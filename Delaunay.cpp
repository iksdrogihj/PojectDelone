//
//  Delaunay.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/22/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include <iostream>
#include <stdlib.h> // this is retarded if ur running on xcode
#include "Delaunay.hpp"

Delaunay::Delaunay()
{
    points = NULL;
    numOfPoints = 0;
}

Delaunay::~Delaunay()
{
    free(points);
}

int Delaunay::fileInput(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if(!file)
    {
        fprintf(stderr, "Error, cannot open file %s\n", fileName);
        fclose(file);
        return FAILED;
    }
    
    fscanf(file, "%u", &numOfPoints);
    
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

static void bottomUpMerge(Vertex3D A[], Vertex3D B[], const unsigned left, const unsigned mid, const unsigned right)
{
    unsigned l = left, r = mid;
    
    for(unsigned k = left; k < right; ++k)
    {
        if(l < mid && (r >= right || A[l] <= A[r]))
        {
            B[k] = A[l++];
        }
        else
        {
            B[k] = A[r++];
        }
    }
}

ErrCode Delaunay::bottomUpMergeSort()
{
    Vertex3D* helperArr = (Vertex3D*) malloc(sizeof(Vertex3D) * numOfPoints);
    if(!helperArr)
    {
        fprintf(stderr, "Error, cannot allocate enough memory for merge sort\n");
        return FAILED;
    }
    
    for(unsigned runWidth = 1; runWidth < numOfPoints; runWidth *= 2)
    {
        for(unsigned i = 0; i < numOfPoints; i += 2 * runWidth)
        {
            bottomUpMerge(points, helperArr, i, std::min(i + runWidth, numOfPoints), std::min(i + 2 * runWidth, numOfPoints));
        }
        memcpy(points, helperArr, sizeof(float) * numOfPoints);
    }
    
    free(helperArr);
    return SUCCESS;
}

void Delaunay::printPointArray()
{
    for(int i = 0; i < numOfPoints; ++i)
    {
        printf("%d: ", i + 1);
        printf("%f\n", points[i].x);
    }
}
