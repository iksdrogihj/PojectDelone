//
//  main.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/4/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Delaunay.hpp"
using namespace std;

void printArr(float *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generate(int arr[], int size)
{
    // generation
    srand (time(NULL));
    
    for(int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1;
    }
}


int main(int argc, const char * argv[])
{
    Delaunay delone;
    delone.fileInput("RANDOM.DAT");
    puts("Before MERGE");
    delone.printPointArray();
    
    puts("After MERGE");
    delone.bottomUpMergeSort();
    delone.printPointArray();

    return 0;
}
