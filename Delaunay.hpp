//
//  Delaunay.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/22/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Delaunay_hpp
#define Delaunay_hpp

#include <stdio.h>
#include "TriangulationContainer.hpp"
#include "Types.hpp"

//=============================================================================
/// @brief  Main Class that will handle all triangulation functionality
///
//=============================================================================
class Delaunay
{
public:
    
    Delaunay();
    ~Delaunay();
    
    //=========================================================================
    /// @fn triangulate
    /// @brief  Main function that handles the entire triangulation sequence.
    ///
    /// @param  Name of the file with our sample points.
    ///
    /// @ret    ErrCode for the state of completion.
    //=========================================================================
    ErrCode triangulate(const char* file);

private:
    
    // Dissable cpy ctor & assignment operator
    Delaunay(const Delaunay&);
    void operator=(const Delaunay&);
    
    //=========================================================================
    /// @fn  fileInput
    /// @brief  Opens the file argument takes it`s input and places it in
    ///         points array
    ///
    /// @param  file - Name of the input file
    ///
    /// @ret    ErrCode for the state of completion.
    /// @NOTE   Remove the need for points array by dispatching the input
    ///         directly to the coords and height arrays.
    //=========================================================================
    ErrCode fileInput(const char* file);
    
    //=========================================================================
    /// @fn  splitPointsArray
    /// @brief  Splits the points array into 2 arrays. 1 with the 2d Coords x/y
    ///         and one with the height that will be used for rendering.
    ///         We do this so we wont have to carry the extra baggage of an
    ///         unused field(i.e the height)
    ///
    /// @ret    ErrCode for the state of completion.
    /// @NOTE   After this function executes points will no longer be a valid
    ///         pointer.
    //=========================================================================
    ErrCode splitPointsArray();
    
    //=========================================================================
    /// @fn  initializeMainTriangle
    /// @brief  Initializes the main circumscribing triangle. The main triangles
    ///         vertex coords are the last 3 indexes of the coords array.
    ///
    //=========================================================================
    ErrCode initializeMainTriangle();
    
    ErrCode legalizeEdge();
    
    //=========================================================================
    /// @var points
    /// @brief  A pointer to a Vertex3D struct. Will be used to allocate a
    ///         dynamic array which will store our points.
    ///
    //=========================================================================
    Vertex3D* points;
    
    //=========================================================================
    /// @var coords
    /// @brief  A pointer to a Vertex2D struct. Will be used to allocate a
    ///         dynamic array which will store the coords for our 2d triangles.
    ///
    /// @NOTE   we allocate 2 more vertices at the end of the array which will
    ///         serve as the vertices of our main circumscribing triangle.
    //=========================================================================
    Vertex2D* coords;
    
    //=========================================================================
    /// @var coords
    /// @brief  A pointer to a Vertex2D struct. Will be used to allocate a
    ///         dynamic array which will store the coords for our 2d triangles.
    ///
    //=========================================================================
    float* heights;
    
    //=========================================================================
    /// @var numOfPoints
    /// @brief  The number of sample points. This is also the size of the points
    ///         array, the size of the coords and the size of the heights arrays.
    ///
    //=========================================================================
    unsigned numOfPoints;
    
    //=========================================================================
    /// @var triangulation
    /// @brief  A list of triangle objects. This is the entire, finished
    ///         triangulation that will be passed for drawing.
    ///
    //=========================================================================
    TriangulationContainer triangulation;
};

#endif /* Delaunay_hpp */