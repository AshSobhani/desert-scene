//
//  Wall.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"
#include "TopSquare.hpp"

class Wall {
public:
    Wall();
    ~Wall() {};

    //Declare functions
    void DrawCastleWall(float castleScale, float towerSpacing, float iH);
private:
    //Declare functions
    void DrawWallTop(float towerSpacing);
    
    //Declare variables
    GLint castleWallTexture, castleTopTexture;
    float mainCastleScale;
    float castleR, castleG, castleB;
    TopSquare *topSquare;
};
