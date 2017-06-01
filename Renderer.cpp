//
//  Renderer.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#include "Renderer.hpp"

Renderer::Renderer(const unsigned short windowWidth, const unsigned short windowHeight)
{
    window.createWindow(windowWidth, windowHeight);
}

Renderer::~Renderer()
{
}

void Renderer::render()
{
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window.getWindow());
        
        /* Poll for and process events */
        glfwPollEvents();
    }
}

ErrCode Renderer::loadVertexShader()
{
    
    return SUCCESS;
}

ErrCode Renderer::loadFragmentShader()
{
    
    return SUCCESS;
}