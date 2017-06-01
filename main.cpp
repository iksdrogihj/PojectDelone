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
    /* Initialize the library glfw */
    if (!glfwInit())
    {
        fprintf(stderr, "Error, failed to initialize glfwInit");
        return -1;
    }
    Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
    renderer.render();
    
    return 0;
}
