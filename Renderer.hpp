//
//  Renderer.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/1/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "Window.hpp"

class Renderer
{
public:
    Renderer(const unsigned short windowWidth, const unsigned short windowHeight);
    ~Renderer();
    
    void render();
private:
    ErrCode loadVertexShader();
    ErrCode loadFragmentShader();
    Window window;
};
#endif /* Renderer_hpp */
