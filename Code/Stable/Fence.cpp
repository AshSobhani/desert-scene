//
//  Fence.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Fence.hpp"

Fence::Fence() {
    //Assign textures
    stableFenceTexture = Scene::GetTexture("./castleTowerTexture.bmp");
}

void Fence::DrawStableFences(float stableScale, float fenceLength) {
    mainStableScale = stableScale;
    float modelScale = mainStableScale;
    
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

    glPushMatrix();
    glTranslatef(0, modelScale*2, 0);
    DrawFence(fenceLength);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, modelScale, 0);
    DrawFence(fenceLength);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -modelScale, 0);
    DrawFence(fenceLength);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 0);
    DrawFence(fenceLength);
    glPopMatrix();
    
    //Restore attributes state
    glPopAttrib();
}

void Fence::DrawFence(float fenceLength) {
    //Change Texture
    glBindTexture(GL_TEXTURE_2D, stableFenceTexture);
    
    //WALL TOP BASE
    glBegin(GL_QUADS);
    //Towertop size
    float modelScale = mainStableScale;

    //FRONT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(fenceLength, -modelScale/5, modelScale/12); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(fenceLength, modelScale/5, modelScale/12); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-fenceLength, modelScale/5, modelScale/12); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-fenceLength, -modelScale/5, modelScale/12); //Bottom left

    //BACK SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-fenceLength, -modelScale/5, -modelScale/12); // Bottom Left
    glTexCoord2f(0, 1);
    glVertex3f(-fenceLength, modelScale/5, -modelScale/12); // Top Left
    glTexCoord2f(1, 1);
    glVertex3f(fenceLength, modelScale/5, -modelScale/12); // Top Right
    glTexCoord2f(1, 0);
    glVertex3f(fenceLength, -modelScale/5, -modelScale/12); // Bottom Right

    //TOP SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(fenceLength, modelScale/5, modelScale/12);
    glTexCoord2f(1, 0);
    glVertex3f(fenceLength, modelScale/5, -modelScale/12);
    glTexCoord2f(0, 0);
    glVertex3f(-fenceLength, modelScale/5, -modelScale/12);
    glTexCoord2f(0, 1);
    glVertex3f(-fenceLength, modelScale/5, modelScale/12);

    //BOTTOM SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-fenceLength, -modelScale/5, modelScale/12);
    glTexCoord2f(0, 0);
    glVertex3f(-fenceLength, -modelScale/5, -modelScale/12);
    glTexCoord2f(1, 0);
    glVertex3f(fenceLength, -modelScale/5, -modelScale/12);
    glTexCoord2f(1, 1);
    glVertex3f(fenceLength, -modelScale/5, modelScale/12);
    glEnd();
}
