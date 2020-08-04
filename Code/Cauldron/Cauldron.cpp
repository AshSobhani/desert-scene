//
//  Cauldron.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Cauldron.hpp"
#include <iostream>
#include <random>
#include <ctime>

Cauldron::Cauldron() {
    //Set the textures
    cauldronTexture = Scene::GetTexture("./metalTexture.bmp");
    lavaTexture = Scene::GetTexture("./lavaTexture.bmp");
    
    //Cauldron position
    cauldronX = -400.0f;
    cauldronY = -160.0f;
    cauldronZ = 350.0f;
    
    //Initialise the cumalative as 0 and speed as 5
    interactiveSpeed = 3.0f;
    cumulativeTime = 0.0f;

    //Set the scale and interactive size
    cauldronScale = 15;
    
    //LIGHT PROPORTIES
    //Setting the position properties
    static GLfloat position[] = {
        cauldronX, cauldronY+50, cauldronZ, 1.0f,
    };
    positionSetting = position;
    
    //Setting the diffuse properties
    static GLfloat diffuse[] = {
        1.0f, 1.0f, 1.0f, 1.0f,
    };
    diffuseSetting = diffuse;
}

void Cauldron::Display() {
    //Save matrix and attribute
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    // Function to draw cauldron
    //glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(cauldronX, cauldronY, cauldronZ);
    DrawCauldron();

    //Revert back to matrix and attribute
    glPopAttrib();
    glPopMatrix();
}

void Cauldron::DrawCauldron() {
    //Enable Texturing
    glEnable(GL_TEXTURE_2D);

    //Disable colour material
    glDisable(GL_COLOR_MATERIAL);

    //Set the cauldron wall colours
    cauldronR = 0.5f;
    cauldronG = 0.5f;
    cauldronB = 0.5f;

    //BUILD THE CAULDRON
    //Cauldron Wall Left
    glPushMatrix();
    glTranslatef(-cauldronScale*4, 0, 0);
    DrawCauldronContainer(1.2);
    glPopMatrix();
    
    //Cauldron Wall Right
    glPushMatrix();
    glTranslatef(cauldronScale*4, 0, 0);
    DrawCauldronContainer(1.2);
    glPopMatrix();
    
    //Cauldron Wall Front
    glPushMatrix();
    glTranslatef(0, 0, cauldronScale*4);
    glRotatef(90.0f, 0, 1, 0);
    DrawCauldronContainer(1);
    glPopMatrix();
    
    //Cauldron Wall Back
    glPushMatrix();
    glTranslatef(0, 0, -cauldronScale*4);
    glRotatef(-90.0f, 0, 1, 0);
    DrawCauldronContainer(1);
    glPopMatrix();
    
    //LAVA
    glPushMatrix();
    glTranslatef(0, -cauldronScale, 0);
    DrawLava();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable(GL_TEXTURE_2D);
    //Enable colour material
    glEnable(GL_COLOR_MATERIAL);
}

void Cauldron::DrawCauldronContainer(float height) {
    //Push attibutes
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    //Set diffuse material property
    float ambientMaterial[] = { 0.5f, 0.5f, 0.5f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 0.7f, 0.7f, 0.7f, 1.f };
    //Set specular material property
    float specularMaterial[] = { 0.9f, 0.9f, 0.9f, 1.f };
    //Set shininess material property
    float shininessMaterial[] = { 10.0 };

    //Material properties implementing the Phong model
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininessMaterial);

    //Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, cauldronTexture);

    float modelScale = cauldronScale;

    glBegin(GL_QUADS);
    //TOP SIDE
    glColor4f(cauldronR, cauldronG, cauldronB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale*height, modelScale*4);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, modelScale*height, -modelScale*4);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, modelScale*height, -modelScale*4);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale*height, modelScale*4);

    //FRONT SIDE
    glColor4f(cauldronR, cauldronG, cauldronB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale*4, modelScale*4); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale*height, modelScale*4); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale*height, modelScale*4); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale*4, modelScale*4); //Bottom left

    //BACK SIDE
    glColor4f(cauldronR, cauldronG, cauldronB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale*4, -modelScale*4); // Bottom Left
    glTexCoord2f(0, 2);
    glVertex3f(-modelScale, modelScale*height, -modelScale*4); // Top Left
    glTexCoord2f(2, 2);
    glVertex3f(modelScale, modelScale*height, -modelScale*4); // Top Right
    glTexCoord2f(2, 0);
    glVertex3f(modelScale, -modelScale*4, -modelScale*4); // Bottom Right

    //LEFT SIDE
    glColor4f(cauldronR, cauldronG, cauldronB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 0);
    glVertex3f(-modelScale, -modelScale*4, modelScale*4);
    glTexCoord2f(1, 1);
    glVertex3f(-modelScale, modelScale*height, modelScale*4);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale*height, -modelScale*4);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale*4, -modelScale*4);

    //RIGHT SIDE
    glColor4f(cauldronR, cauldronG, cauldronB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(modelScale, -modelScale*4, -modelScale*4);
    glTexCoord2f(0, 1);
    glVertex3f(modelScale, modelScale*height, -modelScale*4);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale*height, modelScale*4);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale*4, modelScale*4);
    glEnd();

    //Pop attributes
    glPopAttrib();
}

void Cauldron::DrawLava() {
    //Push attibutes
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    //Set diffuse material property
    float ambientMaterial[] = { 0.5f, 0.5f, 0.5f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 1.0f, 1.0f, 1.0f, 1.f };
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
    glBindTexture(GL_TEXTURE_2D, lavaTexture);

    float modelScale = cauldronScale;

    glBegin(GL_QUADS);
    //TOP SIDE
    glColor4f(cauldronR, cauldronG, cauldronB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1 + textureCoordsOffsetX, 1);
    glVertex3f(modelScale*3, modelScale, modelScale*3);
    glTexCoord2f(1, 0 + textureCoordsOffsetZ);
    glVertex3f(modelScale*3, modelScale, -modelScale*3);
    glTexCoord2f(0, 0 + textureCoordsOffsetZ);
    glVertex3f(-modelScale*3, modelScale, -modelScale*3);
    glTexCoord2f(0 + textureCoordsOffsetX, 1);
    glVertex3f(-modelScale*3, modelScale, modelScale*3);
    glEnd();
    
    glPopAttrib();
}

void Cauldron::Update(const double& deltaTime)
{
    //Accumulate cumalative time for lava animation
    cumulativeTime += deltaTime/interactiveSpeed;
    
//    std::cout << deltaTime << "\n";
//    std::cout << cumulativeTime << "\n";

    //Change the offset to create the animation
    textureCoordsOffsetX = (float)sin(cumulativeTime)/5;
    textureCoordsOffsetZ = (float)cos(cumulativeTime)/5;
    
    //Enable lighting to display effects of these lights by default
    glEnable(GL_LIGHTING);

    //SUNLIGHT SETTINGS
    glLightfv(GL_LIGHT0, GL_POSITION, positionSetting);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseSetting);
    
    //Set the light attenuation
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.004f);
    //Enable GL_LIGHT
    glEnable(GL_LIGHT0);
}

void Cauldron::HandleKey(unsigned char key, int state, int x, int y) {
    // Ignore the key release
    if (!state) return;

    switch (key)
    {
    case '8':
        //Normal gametime speed
            interactiveSpeed = 4;
        break;
    case '9':
        //Fast gametime speed
            interactiveSpeed = 2;
        break;
    case '0':
        //Faster gametime speed
            interactiveSpeed = 1;
        break;
    }
}
