//
//  TopSquare.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"

class TopSquare {
public:
    TopSquare();
    ~TopSquare() {};

    //Declare functions
    void DrawTopSquare(float castleScale, float towerScale);
private:

    //Declare variables
    GLint castleTowerBaseTexture;
    float mainCastleScale;
    float castleR, castleG, castleB;
};
