//
//  GraphicTypes.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/17/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include "GraphicTypes.hpp"

bool Vertex3D::operator<=(const Vertex3D& point2)
{
    if(this->x <= point2.x)
    {
        return true;
    }
    else
        return false;
}