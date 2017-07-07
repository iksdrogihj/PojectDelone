//
//  Delaunay.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/22/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include <new>
#include <stdlib.h>
#include "Sorting.hpp"
#include "Delaunay.hpp"

Delaunay::Delaunay()
: points(NULL)
, heights(NULL)
, coords(NULL)
, numOfPoints(0)
{
}


Delaunay::~Delaunay()
{
    free(heights);
    free(coords);
    
    heights = NULL;
    coords = NULL;
}


ErrCode Delaunay::triangulate(const char* file)
{
    if(fileInput(file))
        return FAILED;
    
    if(bottomUpMergeSort(points, numOfPoints))
        return FAILED;
    
    //  NOTE:   after splitPointsArray() executes, points is no longer a valid
    //          pointer and if you try and use it bad things will happen.
    if(splitPointsArray())
        return FAILED;
    
    initializeMainTriangle();
    triangulation.addInitialPoint(coords[0]);
    
    for(unsigned i = 1; i < numOfPoints - 1; ++i)
    {
        triangulation.addPoint(coords[i]);
    }

    legalizeEdge();
    
    return SUCCESS;
}


ErrCode Delaunay::legalizeEdge()
{
    
    return SUCCESS;
}


ErrCode Delaunay::initializeMainTriangle()
{
    float upperMostPoint = coords[0].y;
    float lowerMostPoint = coords[0].y;
    
    for(size_t i = 1; i < numOfPoints; ++i)
    {
        if(upperMostPoint < coords[i].y)
            upperMostPoint = coords[i].y;
        
        if(lowerMostPoint > coords[i].y)
            lowerMostPoint = coords[i].y;
    }
    
    float dy = upperMostPoint - lowerMostPoint;
    float dx = coords[numOfPoints - 1].x - coords[0].x;
    
    //  Main triangles vertices are in order from the leftmost vertex and traveling
    //  counter clockwise.
    //  @NOTE Do we need this? If not remove it and directly assign to triangulation.head->triangle
    coords[numOfPoints].x = coords[0].x - dy;
    coords[numOfPoints].y = lowerMostPoint;
    
    coords[numOfPoints + 1].x = coords[numOfPoints - 1].x + dy;
    coords[numOfPoints + 1].y = lowerMostPoint;
    
    coords[numOfPoints + 2].x = coords[0].x + dx/2;
    coords[numOfPoints + 2].y = upperMostPoint + dx/2;
    
    triangulation.head  = new(std::nothrow) Node;
    if(!triangulation.head)
    {
        fprintf(stderr, "Error, cannot allocate memory for a Node\n");
        return FAILED;
    }

    
    triangulation.head->triangle.vertex[0] = coords[numOfPoints];
    triangulation.head->triangle.vertex[1] = coords[numOfPoints + 1];
    triangulation.head->triangle.vertex[2] = coords[numOfPoints + 2];
    
    triangulation.head->next = NULL;
    
    return SUCCESS;
}