//
//  Castle.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 10/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Castle.hpp"
#include <string>
#include <iostream>

Castle::Castle() :
spaceKeyPressed(false), iKeyPressed(false), oKeyPressed(false), equalsKeyPressed(false), minusKeyPressed(false), gateRaised(false)
{
    //Set the textures
    castleFloorTexture = Scene::GetTexture("./castleFloorTexture.bmp");

    //Set the scale and interactive size
    castleScale = 25;
    castleTowerInteractiveSize = 1;
    castleWallInteractiveSize = 50;
    adjustGateInteractive = -200;
    
    //Initialise class instances
    tower = new Tower();
    wall = new Wall();
    gate = new Gate();
}

void Castle::Display() {
    //Save the current position then move
    glPushMatrix();
    //glRotatef(30.0f, 0, 1, 0);
    glTranslatef(0, -100, -250);
    //Draw the castle
    DrawCastle();
    glPopMatrix();
}

void Castle::DrawCastle() {
    //Enable Texturing
    glEnable(GL_TEXTURE_2D);

    //Enable colour material
    glDisable(GL_COLOR_MATERIAL);
    
    //Set the initial castle land and pass value to positionComparison
    float towerSpacing = 150 + castleWallInteractiveSize;
    castleGrounds = towerSpacing;
    
    //Set the castle wall colours
    castleR = 0.5f;
    castleG = 0.5f;
    castleB = 0.5f;
    
    //BUILD THE CASTLE
    //FLOOR
    glPushMatrix();
    glTranslatef(0, -185, 0);
    DrawCastleFloor(towerSpacing);
    glPopMatrix();
    
    //GATE
    glPushMatrix();
    glTranslatef(0, -castleScale*2 + adjustGateInteractive, towerSpacing + 15);
    gate->DrawCastleGate(castleScale, towerSpacing, castleTowerInteractiveSize);
    glPopMatrix();

    //TOWERS
    //Front Left Tower
    glPushMatrix();
    glTranslatef(-towerSpacing, -castleScale*2, towerSpacing);
    tower->DrawCastleTower(castleScale, castleTowerInteractiveSize);
    glPopMatrix();

    //Front Right Tower
    glPushMatrix();
    glTranslatef(towerSpacing, -castleScale*2, towerSpacing);
    tower->DrawCastleTower(castleScale, castleTowerInteractiveSize);
    glPopMatrix();

    //Center Tower
    glPushMatrix();
    glTranslatef(0, -castleScale, 0);
    tower->DrawCastleTower(castleScale, castleTowerInteractiveSize*1.75);
    glPopMatrix();

    //Back Right Tower
    glPushMatrix();
    glTranslatef(towerSpacing, -castleScale*2, -towerSpacing);
    tower->DrawCastleTower(castleScale, castleTowerInteractiveSize);
    glPopMatrix();

    //Back Left Tower
    glPushMatrix();
    glTranslatef(-towerSpacing, -castleScale*2, -towerSpacing);
    tower->DrawCastleTower(castleScale, castleTowerInteractiveSize);
    glPopMatrix();

    //WALLS
    //Right Castle Wall
    glPushMatrix();
    glRotatef(90.0f, 0, 1, 0);
    glTranslatef(0, -castleScale*2, towerSpacing);
    wall->DrawCastleWall(castleScale, towerSpacing, castleTowerInteractiveSize);
    glPopMatrix();

    //Left Castle Wall
    glPushMatrix();
    glRotatef(-90.0f, 0, 1, 0);
    glTranslatef(0, -castleScale*2, towerSpacing);
    wall->DrawCastleWall(castleScale, towerSpacing, castleTowerInteractiveSize);
    glPopMatrix();

    //Back Castle Wall
    glPushMatrix();
    glRotatef(180.0f, 0, 1, 0);
    glTranslatef(0, -castleScale*2, towerSpacing);
    wall->DrawCastleWall(castleScale, towerSpacing, castleTowerInteractiveSize);
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
}

void Castle::DrawCastleFloor(float towerSpacing) {
    float modelScale = castleScale;
    
    //Save current attribute state
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    //Set diffuse material property
    float ambientMaterial[] = { 0.4f, 0.4f, 0.4f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 0.7f, 0.7f, 0.7f, 1.f };
    //Set specular material property
    float specularMaterial[] = { 0.6f, 0.6f, 0.6f, 1.f };
    //Set shininess material property
    float shininessMaterial[] = { 20.0 };
    
    //Material properties implementing the Phong model
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininessMaterial);
    
    //Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, castleFloorTexture);
    
    glBegin(GL_QUADS);
    //FRONT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(towerSpacing, -modelScale, towerSpacing); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(towerSpacing, 4*modelScale, towerSpacing); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-towerSpacing, 4*modelScale, towerSpacing); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-towerSpacing, -modelScale, towerSpacing); //Bottom left

    //TOP SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(towerSpacing, 4*modelScale, towerSpacing);
    glTexCoord2f(1, 0);
    glVertex3f(towerSpacing, 4*modelScale, -towerSpacing);
    glTexCoord2f(0, 0);
    glVertex3f(-towerSpacing, 4*modelScale, -towerSpacing);
    glTexCoord2f(0, 1);
    glVertex3f(-towerSpacing, 4*modelScale, towerSpacing);
    
    glEnd();
    
    //Restore attibute state
    glPopAttrib();
}

void Castle::Update(const double& deltaTime) {
    //If the gate raised flag is true, raise gate to desired height
    if (gateRaised && adjustGateInteractive < 0) {
        adjustGateInteractive += 5;
    }
    
    //If the gate raised flag is false, lower gate to desired height
    if (!gateRaised && adjustGateInteractive > -200) {
        adjustGateInteractive -= 5;
    }

    //Decrease the tower and wall size (-)
    if (minusKeyPressed) {
        //If the current scale is not smaller or equal to 1
        if (!(castleTowerInteractiveSize <= 1)) {
            castleTowerInteractiveSize -= 0.1;
        }
    }
    //Increase the tower and wall size (=)
    if (equalsKeyPressed) {
        //If the current scale is not larger or equal to 2
        if (!(castleTowerInteractiveSize >= 2)) {
            castleTowerInteractiveSize += 0.1;
        }
    }

    //Decrease the castles land (i)
    if (iKeyPressed) {
        if (!(castleWallInteractiveSize <= 50)) {
            castleWallInteractiveSize -= 10;
            //std::cout << castleWallInteractiveSize << std::endl ;
        }
    }
    //Increase the castles land (o)
    if (oKeyPressed) {
        if (!(castleWallInteractiveSize >= 200)) {
            castleWallInteractiveSize += 10;
            //std::cout << castleWallInteractiveSize << std::endl ;
        }
    }
}

void Castle::HandleKey(unsigned char key, int state, int x, int y) {
    //Handle a key press to create a smooth animation when a user holds down the increase or decrease buttons
    switch (key) {
    case '-':
        minusKeyPressed = static_cast<GLboolean>(state);
        break;
    case '=':
        equalsKeyPressed = static_cast<GLboolean>(state);
        break;
    case 'i':
        iKeyPressed = static_cast<GLboolean>(state);
        break;
    case 'o':
        oKeyPressed = static_cast<GLboolean>(state);
        break;
    case 'g':
        //If the user is in the castle grounds raise gate
        if (IsUserInCastle()) {
            gateRaised = false;
        }
        break;
    case 'h':
        //If the user is in the castle grounds lower gate
        if (IsUserInCastle()) {
            gateRaised = true;
        }
        break;
    }
}

bool Castle::IsUserInCastle() {
    //Create position variables
    float x, y, z;
    
    //Get the users position
    Scene::GetCamera()->GetEyePosition(x, y, z);
    
    //If the user is withing the castle grounds return true, else return false
    if (x <= castleGrounds && x >= -castleGrounds &&
        y <= castleGrounds && y >= -castleGrounds &&
        z <= castleGrounds-200 && z >= -castleGrounds-200) {
        return true;
    } else {
        return false;
    }
}
