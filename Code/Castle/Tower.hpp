//
//  Tower.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"
#include "TopSquare.hpp"

class Tower {
public:
    Tower();
    ~Tower() {};

    //Declare functions
    void DrawCastleTower(float castleScale, float towerScale);
private:
    //Declare functions
    void DrawTowerBase(float towerScale);
    void DrawTowerTop(float towerScale);
    
    //Declare variables
    GLint castleTowerTexture, castleTowerBaseTexture, castleTopTexture;
    float mainCastleScale;
    float castleR, castleG, castleB;
    TopSquare *topSquare;
};
