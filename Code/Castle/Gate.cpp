//
//  Gate.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Gate.hpp"

Gate::Gate() {
    //Assign textures
    castleTopTexture = Scene::GetTexture("./castleTopTexture.bmp");
}

void Gate::DrawCastleGate(float castleScale, float towerSpacing, float iH) {
    mainCastleScale = castleScale;
    float modelScale = castleScale;
    
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
    glBindTexture(GL_TEXTURE_2D, castleTopTexture);
    
    //DRAW SPIKES
    for(int i=1; i<= towerSpacing/12 - 2; i++){
        glPushMatrix();
        //Spikes
        glTranslatef((i * modelScale) - (towerSpacing - modelScale/2), modelScale/8, 0);
        DrawGatePlank(towerSpacing, iH);
        glPopMatrix();
    }
    
    //Restore attributes state
    glPopAttrib();
}

void Gate::DrawGatePlank(float towerSpacing, float iH) {
    float modelScale = mainCastleScale;
    
    glBegin(GL_QUADS);
    //TOP SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/5, iH*2.5*modelScale, modelScale/5);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/5, iH*2.5*modelScale, -modelScale/5);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, iH*2.5*modelScale, -modelScale/5);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/5, iH*2.5*modelScale, modelScale/5);
    
    //FRONT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale/5, -modelScale*3, modelScale/5); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(modelScale/5, iH*2.5*modelScale, modelScale/5); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale/5, iH*2.5*modelScale, modelScale/5); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale*3, modelScale/5); //Bottom left

    //BACK SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale*3, -modelScale/5); // Bottom Left
    glTexCoord2f(0, 2);
    glVertex3f(-modelScale/5, iH*2.5*modelScale, -modelScale/5); // Top Left
    glTexCoord2f(2, 2);
    glVertex3f(modelScale/5, iH*2.5*modelScale, -modelScale/5); // Top Right
    glTexCoord2f(2, 0);
    glVertex3f(modelScale/5, -modelScale*3, -modelScale/5); // Bottom Right

    //LEFT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(2, 0);
    glVertex3f(-modelScale/5, -modelScale*3, modelScale/5);
    glTexCoord2f(2, 2);
    glVertex3f(-modelScale/5, iH*2.5*modelScale, modelScale/5);
    glTexCoord2f(0, 2);
    glVertex3f(-modelScale/5, iH*2.5*modelScale, -modelScale/5);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale/5, -modelScale*3, -modelScale/5);

    //RIGHT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(modelScale/5, -modelScale*3, -modelScale/5);
    glTexCoord2f(0, 2);
    glVertex3f(modelScale/5, iH*2.5*modelScale, -modelScale/5);
    glTexCoord2f(2, 2);
    glVertex3f(modelScale/5, iH*2.5*modelScale, modelScale/5);
    glTexCoord2f(2, 0);
    glVertex3f(modelScale/5, -modelScale*3, modelScale/5);

    glEnd();
}
