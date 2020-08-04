//
//  Cauldron.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

class Cauldron :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Cauldron();
    ~Cauldron() {};

    //Declare functions
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);
    
private:
    //Declare variables
    GLint cauldronTexture, lavaTexture, stablePoleTexture, stableTowerBaseTexture, stableTopTexture;
    float cauldronScale, textureCoordsOffsetX, textureCoordsOffsetZ, interactiveSpeed, cumulativeTime;
    float cauldronR, cauldronG, cauldronB, cauldronX, cauldronY, cauldronZ;
    
    // reflectance model parameters for LIGHTS
    GLfloat *positionSetting, *diffuseSetting;
    
    //Declare functions
    void DrawCauldron();
    void DrawCauldronContainer(float height);
    void DrawLava();
};
