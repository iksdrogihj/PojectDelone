//
//  Sorting.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/25/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Sorting_hpp
#define Sorting_hpp

#include "Types.hpp"

//=========================================================================
/// @fn bottomUpMergeSort
/// @brief  Sorts the points array using merge sort after it`s been filled
///         from fileInput. Sorts the points array in regard to the x coord.
///
/// @ret    ErrCode for state of completion.
//=========================================================================
ErrCode bottomUpMergeSort(Vertex3D points[], const unsigned  numOfPoints);

#endif /* Sorting_hpp */
