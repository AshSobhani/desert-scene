//
//  Castle.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 10/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#include "Tower.hpp"
#include "Wall.hpp"
#include "Gate.hpp"

#define _INIT_SIZE 50.0f

class Castle :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Castle();
    ~Castle() { };

    //Declare functions
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);
    
private:
    //Declare variables
    GLint castleFloorTexture, castleWallTexture, castleTowerTexture, castleTowerBaseTexture, castleTopTexture;
    float castleScale, castleGrounds;
    float castleTowerInteractiveSize, castleWallInteractiveSize, adjustGateInteractive;
    float castleR, castleG, castleB;
    Tower *tower;
    Wall *wall;
    Gate *gate;
    
    //Declare functions
    void DrawCastle();
    void DrawCastleFloor(float towerSpaceing);
    bool IsUserInCastle();

    //Declare key press booleans
    GLboolean iKeyPressed, oKeyPressed;
    GLboolean equalsKeyPressed, minusKeyPressed;
    bool spaceKeyPressed, gateRaised;
};
