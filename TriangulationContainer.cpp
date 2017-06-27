//
//  TriangulationContainer.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/10/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#include <new>
#include <math.h>
#include "TriangulationContainer.hpp"


TriangulationContainer::TriangulationContainer()
: head(NULL)
, alpha(0)
, beta (0)
, gamma(0)
{
}



TriangulationContainer::~TriangulationContainer()
{
    deleteTriangulation(head);
}


ErrCode TriangulationContainer::addInitialPoint(const Vertex2D& p)
{
    ErrCode errCode = FAILED;
    _getBarycentricCoords(head->triangle, p);
    
    if(_isInsideTriangle())
    {
        errCode = _initialThreeWaySplit(p);
    }
    
    return errCode;
}


ErrCode TriangulationContainer::addPoint(const Vertex2D& p)
{
    ErrCode errCode = FAILED;
    Node* iterator = head;
    
    while(iterator->next != NULL)
    {
        _getBarycentricCoords(iterator->next->triangle, p);
        
        if(_isInsideTriangle())
        {
            errCode = threeWaySplit(iterator, p);
            break;
        }
        
        if(_liesOnEdge())
        {
            fourWaySplit(iterator, p);
            break;
        }
        
        iterator = iterator->next;
    }
    
    return SUCCESS;
}


ErrCode TriangulationContainer::threeWaySplit(Node* parent, const Vertex2D& p)
{
    
    Node* first = new (std::nothrow) Node;
    Node* second = new(std::nothrow) Node;
    Node* third  = new(std::nothrow) Node;
    
    if(!first || !second || !third)
    {
        fprintf(stderr, "Error, cannot allocate memory for a Node\n");
        return FAILED;
    }
    
    _createNewTriangle(first->triangle, parent->next->triangle.vertex[0], parent->next->triangle.vertex[1], p);
    _createNewTriangle(second->triangle, parent->next->triangle.vertex[1], parent->next->triangle.vertex[2], p);
    _createNewTriangle(third->triangle, parent->next->triangle.vertex[2], parent->next->triangle.vertex[0], p);
    
    Node* toBeDeleted = parent->next;
    
    parent->next = first;
    first->next = second;
    second->next = third;
    third->next = toBeDeleted->next;

    delete toBeDeleted;
    return SUCCESS;
}


ErrCode TriangulationContainer::fourWaySplit(Node* parent, const Vertex2D& p)
{
    _twoWaySplit(parent, p);
    Node* incidentTriangle = NULL;
    
    float eps = 1e-7;
    
    if(fabs(alpha) < eps)
        incidentTriangle = _getIncidentTriangle(parent, parent->next->triangle.vertex[1], parent->next->triangle.vertex[2]);
    
    else if(fabs(beta) < eps)
        incidentTriangle = _getIncidentTriangle(parent, parent->next->triangle.vertex[0], parent->next->triangle.vertex[2]);
    
    else
        incidentTriangle = _getIncidentTriangle(parent, parent->next->triangle.vertex[0], parent->next->triangle.vertex[1]);
    
    if(incidentTriangle != NULL)
        _twoWaySplit(incidentTriangle, p);
    
    return SUCCESS;
}

// Care for stack overflow
void TriangulationContainer::deleteTriangulation(Node* node)
{
    if(node != NULL)
        deleteTriangulation(node->next);
    
    delete node;
}
