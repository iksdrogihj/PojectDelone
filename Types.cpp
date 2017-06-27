//
//  GraphicTypes.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/17/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include "Types.hpp"

bool Vertex3D::operator<=(const Vertex3D& point2)
{
    if(this->x <= point2.x)
    {
        return true;
    }
    else
        return false;
}


Vertex2D& Vertex2D::operator=(const Vertex3D& point)
{
    this->x = point.x;
    this->y = point.y;
    return *this;
}

Vertex2D& Vertex2D::operator=(const Vertex2D& point)
{
    this->x = point.x;
    this->y = point.y;
    return *this;
}

bool Vertex2D::operator==(const Vertex2D& point)
{
    if(this->x == point.x && this->y == point.y)
        return true;
    
    return false;
}