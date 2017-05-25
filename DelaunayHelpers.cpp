//
//  DelaunayHelpers.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/25/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include <stdlib.h>
#include "Delaunay.hpp"
#include "Types.hpp"

ErrCode Delaunay::fileInput(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if(!file)
    {
        fprintf(stderr, "Error, cannot open file %s\n", fileName);
        fclose(file);
        return FAILED;
    }
    
    if(fscanf(file, "%u", &numOfPoints) != 1)
    {
        fprintf(stderr, "Error, fscanf fail.\n");
        return FAILED;
    }
    
    points = (Vertex3D*) malloc (sizeof(Vertex3D) * numOfPoints);
    if(!points)
    {
        fprintf(stderr, "Error, cannot allocate memory\n");
        return FAILED;
    }
    
    for(int i = 0; i < numOfPoints; ++i)
    {
        fscanf(file, "%f %f %f", &points[i].x, &points[i].y, &points[i].height);
    }
    
    fclose(file);
    return SUCCESS;
}

ErrCode Delaunay::splitPointsArray()
{
    heights = (float*) malloc(sizeof(float) * numOfPoints);
    if(!heights)
    {
        fprintf(stderr, "Error, cannot allocate memory.\n");
        return FAILED;
    }
    
    coords = (Vertex2D*) malloc(sizeof(Vertex2D) * (numOfPoints + 2));
    if(!coords)
    {
        fprintf(stderr, "Error, cannot allocate memory.\n");
        return FAILED;
    }
    
    for (size_t i = 0; i < numOfPoints; ++i)
    {
        coords[i] = points[i];
        heights[i] = points[i].height;
    }
    
    free(points);
    points = NULL;
    
    return SUCCESS;
}
