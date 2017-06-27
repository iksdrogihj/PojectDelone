//
//  GraphicTypes.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/17/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Types_hpp
#define Types_hpp

enum ErrCode{SUCCESS, FAILED};


struct Vertex3D
{
    float x;
    float y;
    float height;
    bool operator<=(const Vertex3D& point2);
};


struct Vertex2D
{
    float x;
    float y;
    Vertex2D& operator=(const Vertex3D& point);
    Vertex2D& operator=(const Vertex2D& point);
    bool operator==(const Vertex2D& point);
};


struct Triangle
{
    Vertex2D vertex[3];
};
#endif /* Types_hpp */
