//
//  DayNightLighting.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 09/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "DayNightLighting.hpp"
#include <iostream>
#include <cmath>

DayNightLighting::DayNightLighting() : gameTime(0.0), radius(1750.0), sun(true), moon(true) {
    //Set max colour for the skyblue finish
    maxRed = 0.62;
    maxGreen = 0.847;
    maxBlue = 0.937;
    
    //Initialise interactive gametime speed
    interactiveSpeed = 10;
    
    //Setting the position properties
    static GLfloat position[] = {
        // Sunlight position
        static_cast<GLfloat>(radius), 0.0f, 0.0f, 1.0f,
        // Moonlight position
        static_cast<GLfloat>(radius), 0.0f, 0.0f, 1.0f
    };
    positionSetting = position;
    
    //Setting the ambient properties
    static GLfloat ambient[] = {
        //Sunlight
        0.15f, 0.15f, 0.1f, 1.0f,
        //Moonlight
        0.05f, 0.055f, 0.055f, 1.0f
    };
    ambientSetting = ambient;
    
    //Setting the diffuse properties
    static GLfloat diffuse[] = {
        //Sunlight
        1.0f, 1.0f, 1.0f, 1.0f,
        //Moonlight
        0.5f, 0.52f, 0.52f, 1.0f
    };
    diffuseSetting = diffuse;
    
    //Setting the specular properties
    static GLfloat specular[] = {
        //Sunlight
        0.95f, 0.95f, 0.9f, 1.0f,
        //Moonlight
        0.7f, 0.7f, 0.75f, 1.0f
    };
    specularSetting = specular;
}


DayNightLighting::~DayNightLighting() {

}

void DayNightLighting::Display() {
    //Push the attributes and disable the lighting
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_LIGHTING);
    
    //Move rotation axis down to ground level
    glTranslatef(0, -200, 0);

    //If the sun is set to true
    if (sun) {
        // Draw Sun
        glPushMatrix();
        glColor4fv(&diffuseSetting[SUN]);
        glTranslatef(positionSetting[SUN + 0], positionSetting[SUN + 1], positionSetting[SUN + 2]);
        glutSolidSphere(75.0, 10, 10);
        glPopMatrix();
    }

    if (moon) {
        // Draw Moon
        glPushMatrix();
        
        glColor4fv(&diffuseSetting[MOON]);
        glTranslatef(positionSetting[MOON + 0], positionSetting[MOON + 1], positionSetting[MOON + 2]);
        glutSolidSphere(75.0, 10, 10);
        
        glPopMatrix();
    }
    
    //Enable the lighting
    glEnable(GL_LIGHTING);
    glPopAttrib();
    glPopMatrix();
}

void DayNightLighting::Update(const double& deltaTime) {
    //Change the sky colour as time passes to make night and day
    glClearColor(maxRed * sin(gameTime - 3.1),
                 maxGreen * sin(gameTime - 3.1),
                 maxBlue * sin(gameTime - 3.1), 1.0f);
    
    //Gametime speed
    gameTime += deltaTime/interactiveSpeed;
    
    //Change the suns position
    positionSetting[SUN + 0] = -radius*cos(gameTime);
    positionSetting[SUN + 1] = -radius*sin(gameTime);
    
    //Remove the sun once it's below the surface
    if (positionSetting[SUN + 1] <= -30) {
        sun = false;
    } else {
        sun = true;
    }

    //Change the moons position
    positionSetting[MOON + 0] = radius*cos(gameTime);
    positionSetting[MOON + 1] = radius*sin(gameTime);
    
    //Remove the moon once it's below the surface
    if (positionSetting[MOON + 1] <= -30) {
        moon = false;
    } else {
        moon = true;
    }

    //Enable lighting to display effects of these lights by default
    glEnable(GL_LIGHTING);

    //SUNLIGHT SETTINGS
    glLightfv(SUN_LIGHT, GL_POSITION, &positionSetting[SUN]);
    glLightfv(SUN_LIGHT, GL_AMBIENT, &ambientSetting[SUN]);
    glLightfv(SUN_LIGHT, GL_DIFFUSE, &diffuseSetting[SUN]);
    glLightfv(SUN_LIGHT, GL_SPECULAR, &specularSetting[SUN]);
    
    //Set the light attenuation
    glLightf(SUN_LIGHT, GL_LINEAR_ATTENUATION, 0.0003f);
    //If showLight, enable GL_LIGHT, else disable it
    sun ? glEnable(SUN_LIGHT) : glDisable(SUN_LIGHT);

    //MOONLIGHT SETTINGS
    glLightfv(MOON_LIGHT, GL_POSITION, &positionSetting[MOON]);
    glLightfv(MOON_LIGHT, GL_AMBIENT, &ambientSetting[MOON]);
    glLightfv(MOON_LIGHT, GL_DIFFUSE, &diffuseSetting[MOON]);
    glLightfv(MOON_LIGHT, GL_SPECULAR, &specularSetting[MOON]);
    
    //Set the light attenuation
    glLightf(MOON_LIGHT, GL_LINEAR_ATTENUATION, 0.0005f);
    //If showLight, enable GL_LIGHT, else disable it
    moon ? glEnable(MOON_LIGHT) : glDisable(MOON_LIGHT);
}

void DayNightLighting::HandleKey(unsigned char key, int state, int x, int y) {
    // Ignore callback from key release (state == 0)
    if (!state) return;

    switch (key)
    {
    case '8':
        //Normal gametime speed
        interactiveSpeed = 10;
        break;
    case '9':
        //Fast gametime speed
        interactiveSpeed = 2.5;
        break;
    case '0':
        //Faster gametime speed
        interactiveSpeed = 0.5;
        break;
    }
}
