//
//  TopSquare.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "TopSquare.hpp"

TopSquare::TopSquare() {
    castleTowerBaseTexture = Scene::GetTexture("./castleFloorTexture.bmp");
}

void TopSquare::DrawTopSquare(float castleScale, float towerScale) {
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
    
    //Change texture binding
    glBindTexture(GL_TEXTURE_2D, castleTowerBaseTexture);
    
    glBegin(GL_QUADS);
    
    //Towertop size
    float modelScale = castleScale * towerScale * 1.15;

    //FRONT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/5, -modelScale/3, modelScale/10); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/5, modelScale/3, modelScale/10); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/5, modelScale/3, modelScale/10); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale/3, modelScale/10); //Bottom left

    //BACK SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale/3, -modelScale/10); // Bottom Left
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/5, modelScale/3, -modelScale/10); // Top Left
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/5, modelScale/3, -modelScale/10); // Top Right
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/5, -modelScale/3, -modelScale/10); // Bottom Right

    //TOP SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/5, modelScale/3, modelScale/10);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/5, modelScale/3, -modelScale/10);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, modelScale/3, -modelScale/10);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/5, modelScale/3, modelScale/10);

    //BOTTOM SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/5, -modelScale/3, modelScale/10);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale/3, -modelScale/10);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/5, -modelScale/3, -modelScale/10);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/5, -modelScale/3, modelScale/10);

    //LEFT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/5, -modelScale/3, modelScale/10);
    glTexCoord2f(1, 1);
    glVertex3f(-modelScale/5, modelScale/3, modelScale/10);
    glTexCoord2f(1, 0);
    glVertex3f(-modelScale/5, modelScale/3, -modelScale/10);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale/3, -modelScale/10);

    //RIGHT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(modelScale/5, -modelScale/3, -modelScale/10);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/5, modelScale/3, -modelScale/10);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/5, modelScale/3, modelScale/10);
    glTexCoord2f(0, 1);
    glVertex3f(modelScale/5, -modelScale/3, modelScale/10);

    glEnd();
    
    //Restore attributes state
    glPopAttrib();
}
