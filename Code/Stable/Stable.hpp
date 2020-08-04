//
//  Stable.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 13/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#include "Pole.hpp"
#include "Fence.hpp"

#define _INIT_SIZE 50.0f

class Stable :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Stable();
    ~Stable() {};

    //Declare functions
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);
    
private:
    //Declare variables
    GLint stableFloorTexture, stableRoofTexture, stablePoleTexture, stableTowerBaseTexture, stableTopTexture;
    float stableScale;
    float stableInteractiveSize;
    float stableLengthInteractiveSize;
    float stableR, stableG, stableB;
    Pole *pole;
    Fence *fence;
    
    //Declare functions
    void DrawStable();
    void DrawStableFloor(float towerSpaceing);
    void DrawStableRoof(float towerSpacing, float iH);

    //Declare key press booleans
    GLboolean iKeyPressed, oKeyPressed;
    GLboolean lKeyPressed, kKeyPressed;
    GLboolean spaceKeyPressed;
};
