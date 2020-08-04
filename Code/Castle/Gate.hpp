//
//  Gate.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"

class Gate {
public:
    Gate();
    ~Gate() {};

    //Declare functions
    void DrawCastleGate(float castleScale, float towerSpacing, float iH);
private:
    //Declare functions
    void DrawGatePlank(float towerSpacing, float iH);

    //Declare variables
    GLint castleTopTexture;
    float mainCastleScale;
    float castleR, castleG, castleB;
};
