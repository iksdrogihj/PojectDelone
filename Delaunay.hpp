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
#include <vector>
#include "GraphicTypes.hpp"

enum ErrCode{SUCCESS, FAILED};

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
    /// @fn  fileInput
    /// @brief  Opens the file argument takes it`s input and places it in
    ///         points array
    ///
    /// @param  file - Name of the input file
    //=========================================================================
    int fileInput(const char* file);
    
    //=========================================================================
    /// @fn bottomUpMergeSort
    /// @brief  Sorts the points array using merge sort after it`s been filled
    ///         from fileInput.
    ///
    /// @ret    ErrCode for state of completion
    //=========================================================================
    ErrCode bottomUpMergeSort();
    
    //=========================================================================
    /// @fn printPointArray
    /// @brief  prints the values stored in the points array.
    ///
    //=========================================================================
    void printPointArray();
private:
    // Dissable cpy ctor & assignment operator
    Delaunay(const Delaunay&);
    void operator=(const Delaunay&);
    
    //=========================================================================
    /// @var points
    /// @brief  A pointer to a Vertex3D struct. Will be used to allocate a
    ///         dinamyc array which will store our points.
    ///
    //=========================================================================
    Vertex3D* points;
    
    //=========================================================================
    /// @var numOfPoints
    /// @brief  The number of sample points. This is also the size of the points
    ///         array.
    ///
    //=========================================================================
    unsigned numOfPoints;
    
    //=========================================================================
    /// @var triangulation
    /// @brief  A vector of triangle objects. This is the entire finished
    ///         triangulation that will be passed for drawing.
    ///
    //=========================================================================
    std::vector<Triangle> triangulation;
};

#endif /* Delaunay_hpp */
