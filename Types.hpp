//
//  GraphicTypes.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/17/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Types_hpp
#define Types_hpp

enum ErrCode{SUCCESS, FAILED};

struct Triangle;
struct Node;


struct Vertex3D
{
    float x;
    float y;
    float height;
    bool operator<=(const Vertex3D& point2);
};


struct Vertex2D
{
    float x;
    float y;
    Vertex2D& operator=(const Vertex3D& point);
    Vertex2D& operator=(const Vertex2D& point);
    bool operator==(const Vertex2D& point);
};


struct Edge
{
    Vertex2D point1;
    Vertex2D point2;
    Node* incidentTriangle1;
    Node* incidentTriangle2;
    bool operator==(Edge& edge);
};

struct Triangle
{
    Vertex2D vertex[3];
    
    //goes: left, bottom, right; (counterclockwise order)
    Edge edge[3];
};


struct Node
{
    Triangle triangle;
    Node* next;
    //Node* prev;
};

#endif /* Types_hpp */
