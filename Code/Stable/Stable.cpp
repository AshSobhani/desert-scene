//
//  Stable.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 13/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Stable.hpp"
#include <iostream>
#include <random>
#include <ctime>

Stable::Stable() :
spaceKeyPressed(false), iKeyPressed(false), oKeyPressed(false), lKeyPressed(false), kKeyPressed(false)
{
    //Set the textures
    stableFloorTexture = Scene::GetTexture("./stableFloorTexture.bmp");
    stableRoofTexture = Scene::GetTexture("./stableRoofTexture.bmp");
    
    //Set the scale and interactive size
    stableScale = 12.5;
    stableInteractiveSize = 1;
    stableLengthInteractiveSize = 1;
    
    //Initialise classes
    pole = new Pole();
    fence = new Fence();
}

void Stable::Display() {
    //Save matrix and attribute
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    // Function to draw stable
    glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0, -190, -550.0f);
    DrawStable();
    
    //Revert back to matrix and attribute
    glPopAttrib();
    glPopMatrix();
}

void Stable::DrawStable() {
    //Enable Texturing
    glEnable(GL_TEXTURE_2D);
    
    //Disable colour material
    glDisable(GL_COLOR_MATERIAL);
    
    //Set the initial stable land
    float stableLength = 150 + stableLengthInteractiveSize;
    
    //Set the stable wall colours
    stableR = 0.5f;
    stableG = 0.5f;
    stableB = 0.5f;
    
    //BUILD THE STABLE
    //FLOOR
    glPushMatrix();
    glTranslatef(0, 0, 0);
    DrawStableFloor(stableLength);
    glPopMatrix();
    
    //POLES
    //Front Left Pole
    glPushMatrix();
    glTranslatef(-stableLength/1.1, 0, stableScale*3);
    pole->DrawStablePole(stableScale);
    glPopMatrix();
    
    //Front Right Pole
    glPushMatrix();
    glTranslatef(stableLength/1.1, 0, stableScale*3);
    pole->DrawStablePole(stableScale);
    glPopMatrix();
    
    //Back Left Pole
    glPushMatrix();
    glTranslatef(-stableLength/1.1, 0, -stableScale*3);
    pole->DrawStablePole(stableScale);
    glPopMatrix();
    
    //Back Right Pole
    glPushMatrix();
    glTranslatef(stableLength/1.1, 0, -stableScale*3);
    pole->DrawStablePole(stableScale);
    glPopMatrix();
    
    //FENCES
    //Left Side
    glPushMatrix();
    glTranslatef(-stableLength/1.1, stableScale*3.5, 0);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    fence->DrawStableFences(stableScale, stableScale*3);
    glPopMatrix();
    
    //Center
    glPushMatrix();
    glTranslatef(0, stableScale*3.5, -stableScale*3);
    fence->DrawStableFences(stableScale, stableLength/1.1);
    glPopMatrix();
    
    //Right Side
    glPushMatrix();
    glTranslatef(stableLength/1.1, stableScale*3.5, 0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    fence->DrawStableFences(stableScale, stableScale*3);
    glPopMatrix();
    
    //ROOF
    //Front Side
    glPushMatrix();
    glTranslatef(0, stableScale*9.5, 0);
    DrawStableRoof(stableLength, 1);
    glPopMatrix();
    
    //Back Side
    glPushMatrix();
    glTranslatef(0, stableScale*9.5, 0);
    glRotatef(180.f, 0.0f, 1.0f, 0.0f);
    DrawStableRoof(stableLength, 1);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable(GL_TEXTURE_2D);
    //Enable colour material
    glEnable(GL_COLOR_MATERIAL);
}

void Stable::DrawStableFloor(float stableLength) {
    //Push attibutes
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    //Set diffuse material property
    float ambientMaterial[] = { 0.5f, 0.5f, 0.5f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 0.4f, 0.4f, 0.4f, 1.f };
    //Set specular material property
    float specularMaterial[] = { 0.6f, 0.6f, 0.6f, 1.f };
    //Set shininess material property
    float shininessMaterial[] = { 100.0 };
    
    //Material properties implementing the Phong model
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininessMaterial);
    
    //Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, stableFloorTexture);
    
    float modelScale = stableScale;
    
    glBegin(GL_QUADS);
    //TOP SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(stableLength, modelScale, modelScale*4);
    glTexCoord2f(1, 0);
    glVertex3f(stableLength, modelScale, -modelScale*4);
    glTexCoord2f(0, 0);
    glVertex3f(-stableLength, modelScale, -modelScale*4);
    glTexCoord2f(0, 1);
    glVertex3f(-stableLength, modelScale, modelScale*4);
    
    //FRONT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(stableLength, -modelScale*2, modelScale*4); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(stableLength, modelScale, modelScale*4); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-stableLength, modelScale, modelScale*4); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-stableLength, -modelScale*2, modelScale*4); //Bottom left
    
    //BACK SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-stableLength, -modelScale*2, -modelScale*4); // Bottom Left
    glTexCoord2f(0, 2);
    glVertex3f(-stableLength, modelScale, -modelScale*4); // Top Left
    glTexCoord2f(2, 2);
    glVertex3f(stableLength, modelScale, -modelScale*4); // Top Right
    glTexCoord2f(2, 0);
    glVertex3f(stableLength, -modelScale*2, -modelScale*4); // Bottom Right
    
    //LEFT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 0);
    glVertex3f(-stableLength, -modelScale*2, modelScale*4);
    glTexCoord2f(1, 1);
    glVertex3f(-stableLength, modelScale, modelScale*4);
    glTexCoord2f(0, 1);
    glVertex3f(-stableLength, modelScale, -modelScale*4);
    glTexCoord2f(0, 0);
    glVertex3f(-stableLength, -modelScale*2, -modelScale*4);

    //RIGHT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(stableLength, -modelScale*2, -modelScale*4);
    glTexCoord2f(0, 1);
    glVertex3f(stableLength, modelScale, -modelScale*4);
    glTexCoord2f(1, 1);
    glVertex3f(stableLength, modelScale, modelScale*4);
    glTexCoord2f(1, 0);
    glVertex3f(stableLength, -modelScale*2, modelScale*4);
    glEnd();
    
    //Pop attributes
    glPopAttrib();
}

void Stable::DrawStableRoof(float stableLength, float side) {
    //Save current attribute state
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    //Set diffuse material property
    float ambientMaterial[] = { 0.3f, 0.3f, 0.3f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 0.4f, 0.4f, 0.4f, 1.f };
    //Set specular material property
    float specularMaterial[] = { 1.0f, 1.0f, 1.0f, 1.f };
    //Set shininess material property
    float shininessMaterial[] = { 100.0 };
    
    //Material properties implementing the Phong model
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininessMaterial);
    
    //Change texture binding
    glBindTexture(GL_TEXTURE_2D, stableRoofTexture);
    
    //Assign scale
    float modelScale = stableScale;
    
    glBegin(GL_QUADS);
    //FRONT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(stableLength, -modelScale/5, side*modelScale*4); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(stableLength, modelScale/5, side*modelScale*4); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-stableLength, modelScale/5, side*modelScale*4); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-stableLength, -modelScale/5, side*modelScale*4); //Bottom left

    //TOP SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 1, 0.5);
    glTexCoord2f(1, 1);
    glVertex3f(stableLength, modelScale/5, modelScale*4);
    glTexCoord2f(1, 0);
    glVertex3f(stableLength, (modelScale/5)*10, 0);
    glTexCoord2f(0, 0);
    glVertex3f(-stableLength, (modelScale/5)*10, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-stableLength, modelScale/5, modelScale*4);

    //BOTTOM SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-stableLength, (modelScale/5) - modelScale/2.5, modelScale*4);
    glTexCoord2f(0, 0);
    glVertex3f(-stableLength, ((modelScale/5)*10) - modelScale/2.5, 0);
    glTexCoord2f(1, 0);
    glVertex3f(stableLength, ((modelScale/5)*10) - modelScale/2.5, 0);
    glTexCoord2f(1, 1);
    glVertex3f(stableLength, (modelScale/5) - modelScale/2.5, modelScale*4);
    
    //LEFT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 0);
    glVertex3f(-stableLength, (modelScale/5) - modelScale/2.5, modelScale*4);
    glTexCoord2f(1, 1);
    glVertex3f(-stableLength, modelScale/5, modelScale*4);
    glTexCoord2f(0, 1);
    glVertex3f(-stableLength, (modelScale/5)*10, 0);
    glTexCoord2f(0, 0);
    glVertex3f(-stableLength, ((modelScale/5)*10) - modelScale/2.5, 0);

    //RIGHT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(stableLength, ((modelScale/5)*10) - modelScale/2.5, 0);
    glTexCoord2f(0, 1);
    glVertex3f(stableLength, (modelScale/5)*10, 0);
    glTexCoord2f(1, 1);
    glVertex3f(stableLength, modelScale/5, modelScale*4);
    glTexCoord2f(1, 0);
    glVertex3f(stableLength, (modelScale/5) - modelScale/2.5, modelScale*4);
    glEnd();
    
    //Remove attributes
    glPopAttrib();
}

void Stable::Update(const double& deltaTime) {
    //Decrease the stables length (k)
    if (kKeyPressed) {
        if (!(stableLengthInteractiveSize <= 0)) {
            stableLengthInteractiveSize -= 10;
            //std::cout << stableLengthInteractiveSize << std::endl;
        }
    }
    //Increase the stables lenght (l)
    if (lKeyPressed) {
        if (!(stableLengthInteractiveSize >= 150)) {
            stableLengthInteractiveSize += 10;
            //std::cout << stableLengthInteractiveSize << std::endl;
        }
    }
}

void Stable::HandleKey(unsigned char key, int state, int x, int y) {
    //Handle a key press to create a smooth animation when a user holds down the increase or decrease buttons
    switch (key) {
    case 'l':
        lKeyPressed = static_cast<GLboolean>(state);
        break;
    case 'k':
        kKeyPressed = static_cast<GLboolean>(state);
        break;
    }
}
