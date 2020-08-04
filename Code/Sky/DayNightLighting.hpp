//
//  DayNightLighting.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 09/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#define SUN 0
#define MOON 4
#define SUN_LIGHT                         0x4002
#define MOON_LIGHT                        0x4003

class DayNightLighting :
    public DisplayableObject, public Animation, public Input
{
public:
    DayNightLighting();
    ~DayNightLighting();

    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

private:
    //Initialise variables
    double gameTime, radius;
    
    //Initialise max colours for rgb
    float maxRed, maxGreen, maxBlue, interactiveSpeed;

    // reflectance model parameters for LIGHTS
    GLfloat *positionSetting, *ambientSetting, *diffuseSetting, *specularSetting;

    // flag for showing lights 0-3
    GLboolean sun, moon;
};
