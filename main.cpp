//
//  main.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/4/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include "Delaunay.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    Delaunay delone;
    delone.triangulate("RANDOM.DAT");
    delone.printPointArray();

    return 0;
}
