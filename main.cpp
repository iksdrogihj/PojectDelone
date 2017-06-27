//
//  main.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/4/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

//  NOTE:   <GL/glew.h> MUST BE INCLUDED FIRST!!!
//          glew overrides some includes(ex gl.h) from glfw
//          and must be included first otherwise it throws an error.
#include <GL/glew.h>
#include "Renderer.hpp"
#include "Delaunay.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int main(int argc, char * argv[])
{
//    /* Initialize the library glfw */
//    if (!glfwInit())
//    {
//        fprintf(stderr, "Error, failed to initialize glfwInit");
//        return FAILED;
//    }
//    
//    const char * sht="\
//#    ";
//    Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
//    renderer.render();

//    const char* name = "../../../ProjectDelone/Shaders/VertexShader.vs";
//    FILE* file = fopen(name, "r");
//    if(!file)
//    {
//        fprintf(stderr, "Error, cannot open file %s\n", name);
//        fclose(file);
//        return FAILED;
//    }
//    char tempArr[512];
    Delaunay delone;
    delone.triangulate("../../../ProjectDelone/SamplePointFiles/RANDOM.DAT");
    return 0;
}
