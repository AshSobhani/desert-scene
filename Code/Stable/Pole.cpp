//
//  Pole.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Pole.hpp"

Pole::Pole() {
    //Assign textures
    stablePoleTexture = Scene::GetTexture("./castleTopTexture.bmp");
}

void Pole::DrawStablePole(float stableScale) {
    mainStableScale = stableScale;
    float modelScale = mainStableScale;
    
    //Draw the base first
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glTranslatef(0, modelScale, 0);
    DrawPoleBase();
    glPopAttrib();
    glPopMatrix();
    
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
    glBindTexture(GL_TEXTURE_2D, stablePoleTexture);
    
    glBegin(GL_QUADS);
    //FRONT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/5, -modelScale, modelScale/5); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/5, modelScale*10, modelScale/5); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/5, modelScale*10, modelScale/5); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale, modelScale/5); //Bottom left

    //BACK SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale, -modelScale/5); // Bottom Left
    glTexCoord2f(0, 2);
    glVertex3f(-modelScale/5, modelScale*10, -modelScale/5); // Top Left
    glTexCoord2f(2, 2);
    glVertex3f(modelScale/5, modelScale*10, -modelScale/5); // Top Right
    glTexCoord2f(2, 0);
    glVertex3f(modelScale/5, -modelScale, -modelScale/5); // Bottom Right

    //LEFT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(2, 0);
    glVertex3f(-modelScale/5, -modelScale, modelScale/5);
    glTexCoord2f(2, 2);
    glVertex3f(-modelScale/5, modelScale*10, modelScale/5);
    glTexCoord2f(0, 2);
    glVertex3f(-modelScale/5, modelScale*10, -modelScale/5);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale, -modelScale/5);

    //RIGHT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(modelScale/5, -modelScale, -modelScale/5);
    glTexCoord2f(0, 2);
    glVertex3f(modelScale/5, modelScale*10, -modelScale/5);
    glTexCoord2f(2, 2);
    glVertex3f(modelScale/5, modelScale*10, modelScale/5);
    glTexCoord2f(2, 0);
    glVertex3f(modelScale/5, -modelScale, modelScale/5);

    glEnd();
    glPopAttrib();
}

void Pole::DrawPoleBase() {
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
    
    //Change Texture
    glBindTexture(GL_TEXTURE_2D, stablePoleTexture);
    
    glBegin(GL_QUADS);
    
    //Towertop size
    float modelScale = mainStableScale*1.25;
    
    //TOP SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/2, modelScale/3, modelScale/2);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/2, modelScale/3, -modelScale/2);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/2, modelScale/3, -modelScale/2);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/2, modelScale/3, modelScale/2);

    //FRONT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/2, -modelScale/2, modelScale/2); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/2, modelScale/3, modelScale/2); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/2, modelScale/3, modelScale/2); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/2, -modelScale/2, modelScale/2); //Bottom left

    //BACK SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/2, -modelScale/2, -modelScale/2); // Bottom Left
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/2, modelScale/3, -modelScale/2); // Top Left
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/2, modelScale/3, -modelScale/2); // Top Right
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/2, -modelScale/2, -modelScale/2); // Bottom Right

    //LEFT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 0);
    glVertex3f(-modelScale/2, -modelScale/2, modelScale/2);
    glTexCoord2f(1, 1);
    glVertex3f(-modelScale/2, modelScale/3, modelScale/2);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/2, modelScale/3, -modelScale/2);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/2, -modelScale/2, -modelScale/2);

    //RIGHT SIDE
    glColor4f(stableR, stableG, stableB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(modelScale/2, -modelScale/2, -modelScale/2);
    glTexCoord2f(0, 1);
    glVertex3f(modelScale/2, modelScale/3, -modelScale/2);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/2, modelScale/3, modelScale/2);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/2, -modelScale/2, modelScale/2);

    glEnd();
    glPopAttrib();
}
