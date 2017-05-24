//
//  GraphicTypes.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/17/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef GraphicTypes_hpp
#define GraphicTypes_hpp

struct Vertex3D
{
    float x;
    float y;
    float height;
    bool operator<=(const Vertex3D& point2);
};

struct Edge
{
    Vertex3D point1;
    Vertex3D point2;
    
};

struct Triangle
{
    Vertex3D v1;
    Vertex3D v2;
    Vertex3D v3;
};
#endif /* GraphicTypes_hpp */
