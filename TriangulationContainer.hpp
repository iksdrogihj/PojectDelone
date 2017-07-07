//
//  TriangulationContainer.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/10/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef TriangulationContainer_hpp
#define TriangulationContainer_hpp

#include <stdio.h>
#include "Types.hpp"

class Iterator
{
    
};


class TriangulationContainer
{
public:
    
    TriangulationContainer();
    ~TriangulationContainer();
    ErrCode addInitialPoint(const Vertex2D& point);
    ErrCode addPoint(const Vertex2D& point);
    Node* head;
    
// Helper Methods
private:
    void _createNewTriangle(Triangle& triangle, const Vertex2D& p1, const Vertex2D& p2, const Vertex2D& p3);
    void _getBarycentricCoords(const Triangle&, const Vertex2D& p);
    bool _isInsideTriangle();
    bool _liesOnEdge();
    ErrCode _initialThreeWaySplit(const Vertex2D& p);
    ErrCode _twoWaySplit(Node* parentNode, const Vertex2D& p);
    void _setIncidentTriangle(Node* first, Node* second, Edge& edge);
    Node* _getIncidentTriangle(const Node* node, Edge& edge);
    
private:
    ErrCode threeWaySplit(Node* node, const Vertex2D& p);
    ErrCode fourWaySplit(Node* node, const Vertex2D& p);
    void deleteTriangulation(Node* node);
    //void setIncidentTriangle(Node* parent, Node* first, Node* second, Node* third) ;
    
    
    float alpha;
    float beta;
    float gamma;
};
#endif /* TriangulationContainer_hpp */
