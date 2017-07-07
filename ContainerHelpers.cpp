//
//  ContainerHelpers.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/22/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include <new>
#include <math.h>
#include "TriangulationContainer.hpp"


void TriangulationContainer::_getBarycentricCoords(const Triangle& triangle, const Vertex2D &p)
{
    Vertex2D p1 = triangle.vertex[0];
    Vertex2D p2 = triangle.vertex[1];
    Vertex2D p3 = triangle.vertex[2];
    
    alpha = ((p2.y - p3.y)*(p.x - p3.x) + (p3.x - p2.x)*(p.y - p3.y)) /
    ((p2.y - p3.y)*(p1.x - p3.x) + (p3.x - p2.x)*(p1.y - p3.y));
    
    beta = ((p3.y - p1.y)*(p.x - p3.x) + (p1.x - p3.x)*(p.y - p3.y)) /
    ((p2.y - p3.y)*(p1.x - p3.x) + (p3.x - p2.x)*(p1.y - p3.y));
    
    gamma = 1 - alpha - beta;
}


bool TriangulationContainer::_isInsideTriangle()
{
    if(alpha < 0 || alpha > 1 || beta < 0 || beta > 1 || gamma < 0 || gamma > 1)
        return false;
    
    return true;
}


bool TriangulationContainer::_liesOnEdge()
{
    float eps = 1e-7;
    if(fabs(alpha) < eps || fabs(beta) < eps || fabs(gamma) < eps)
        return true;
    
    return false;
}


void TriangulationContainer::_createNewTriangle(Triangle& triangle, const Vertex2D& p1, const Vertex2D& p2, const Vertex2D& p3)
{
    triangle.vertex[0] = p1;
    triangle.vertex[1] = p2;
    triangle.vertex[2] = p3;
    
    triangle.edge[0].point1 = p1;
    triangle.edge[0].point2 = p3;
    
    triangle.edge[1].point1 = p1;
    triangle.edge[1].point2 = p2;
    
    triangle.edge[2].point1 = p2;
    triangle.edge[2].point2 = p3;
}


ErrCode TriangulationContainer::_initialThreeWaySplit(const Vertex2D& p)
{
    Node* first = new (std::nothrow) Node;
    Node* second = new(std::nothrow) Node;
    Node* third  = new(std::nothrow) Node;
    
    if(!first || !second || !third)
    {
        delete first;
        delete second;
        delete third;
        
        fprintf(stderr, "Error, cannot allocate memory for a Node\n");
        return FAILED;
    }
    
    _createNewTriangle(first->triangle, head->triangle.vertex[0], head->triangle.vertex[1], p);
    _createNewTriangle(second->triangle, head->triangle.vertex[1], head->triangle.vertex[2], p);
    _createNewTriangle(third->triangle, head->triangle.vertex[2], head->triangle.vertex[0], p);
    
    
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;
    
    return SUCCESS;
}


ErrCode TriangulationContainer::_twoWaySplit(Node* parentNode, const Vertex2D& p)
{
    Node* toBeDeleted = parentNode->next;
    
    Node* first = new(std::nothrow) Node;
    Node* second = new(std::nothrow) Node;
    
    if(!first || !second)
    {
        fprintf(stderr, "Error, Not enough memory to allocate a new triangle node\n");
        return FAILED;
    }
    
    float eps = 1e-7;
    
    // starts from the leftMost point and travels counter clockwise
    if(fabs(gamma) < eps)
    {
        first->triangle.vertex[0] = parentNode->next->triangle.vertex[0];
        first->triangle.vertex[1] = p;
        first->triangle.vertex[2] = parentNode->next->triangle.vertex[2];
        
        first->triangle.edge[0].point1 = first->triangle.vertex[0];
        first->triangle.edge[0].point2 = p;
        
        first->triangle.edge[1].point1 = p;
        first->triangle.edge[1].point2 = first->triangle.vertex[1];
        
        first->triangle.edge[2].point1 = first->triangle.vertex[0];
        first->triangle.edge[2].point2 = first->triangle.vertex[2];
        
        
        
        second->triangle.vertex[0] = p;
        second->triangle.vertex[1] = parentNode->next->triangle.vertex[1];
        second->triangle.vertex[2] = parentNode->next->triangle.vertex[2];
        
        second->triangle.edge[0].point1 = p;
        second->triangle.edge[0].point2 = second->triangle.vertex[1];;
        
        second->triangle.edge[1].point1 = second->triangle.vertex[1];;
        second->triangle.edge[1].point2 = second->triangle.vertex[2];
        
        second->triangle.edge[2].point1 = second->triangle.vertex[2];
        second->triangle.edge[2].point2 = p;
        
    }
    else if(fabs(alpha) < eps)
    {
        first->triangle.vertex[0] = parentNode->next->triangle.vertex[0];
        first->triangle.vertex[1] = parentNode->next->triangle.vertex[1];
        first->triangle.vertex[2] = p;
        
        first->triangle.edge[0].point1 = first->triangle.vertex[0];
        first->triangle.edge[0].point2 = p;
        
        first->triangle.edge[1].point1 = p;
        first->triangle.edge[1].point2 = first->triangle.vertex[1];
        
        first->triangle.edge[2].point1 = first->triangle.vertex[0];
        first->triangle.edge[2].point2 = first->triangle.vertex[2];
        
        
        
        
        second->triangle.vertex[0] = p;
        second->triangle.vertex[1] = parentNode->next->triangle.vertex[2];
        second->triangle.vertex[2] = parentNode->next->triangle.vertex[1];
        
        second->triangle.edge[0].point1 = p;
        second->triangle.edge[0].point2 = second->triangle.vertex[1];;
        
        second->triangle.edge[1].point1 = second->triangle.vertex[1];;
        second->triangle.edge[1].point2 = second->triangle.vertex[2];
        
        second->triangle.edge[2].point1 = second->triangle.vertex[2];
        second->triangle.edge[2].point2 = p;
    }
    else
    {
        first->triangle.vertex[0] = parentNode->next->triangle.vertex[0];
        first->triangle.vertex[1] = parentNode->next->triangle.vertex[1];
        first->triangle.vertex[2] = p;
        
        second->triangle.vertex[0] = parentNode->next->triangle.vertex[1];
        second->triangle.vertex[1] = parentNode->next->triangle.vertex[2];
        second->triangle.vertex[2] = p;
    }
    
    parentNode->next = first;
    first->next = second;
    second->next = toBeDeleted->next;
    
    delete toBeDeleted;
    return SUCCESS;
}


void TriangulationContainer::_setIncidentTriangle(Node* first, Node* second, Edge& edge)
{
    edge.incidentTriangle1 = first;
    edge.incidentTriangle2 = second;
}


Node* TriangulationContainer::_getIncidentTriangle(const Node* node, Edge& edge)
{
    if(node == edge.incidentTriangle1)
        return edge.incidentTriangle2;
    else
        return edge.incidentTriangle1;
}


