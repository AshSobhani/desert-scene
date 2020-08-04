//
//  Tower.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Tower.hpp"

Tower::Tower() {
    //Set the textures
    castleTowerTexture = Scene::GetTexture("./castleTowerTexture.bmp");
    castleTowerBaseTexture = Scene::GetTexture("./castleFloorTexture.bmp");
    castleTopTexture = Scene::GetTexture("./castleTopTexture.bmp");
    
    //Initialise class
    topSquare = new TopSquare();
}

void Tower::DrawCastleTower(float castleScale, float towerScale) {
    mainCastleScale = castleScale;
    float modelScale = mainCastleScale * towerScale;
    
    //Draw the tower base
    glPushMatrix();
    glTranslatef(0, -modelScale, 0);
    DrawTowerBase(towerScale);
    glPopMatrix();
    
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
    glBindTexture(GL_TEXTURE_2D, castleTowerTexture);
    
    glBegin(GL_QUADS);
    //FRONT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale, modelScale); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, 4*modelScale, modelScale); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, 4*modelScale, modelScale); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale, modelScale); //Bottom left

    //BACK SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale, -modelScale); // Bottom Left
    glTexCoord2f(0, 2);
    glVertex3f(-modelScale, 4*modelScale, -modelScale); // Top Left
    glTexCoord2f(2, 2);
    glVertex3f(modelScale, 4*modelScale, -modelScale); // Top Right
    glTexCoord2f(2, 0);
    glVertex3f(modelScale, -modelScale, -modelScale); // Bottom Right

    //LEFT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(2, 0);
    glVertex3f(-modelScale, -modelScale, modelScale);
    glTexCoord2f(2, 2);
    glVertex3f(-modelScale, 4*modelScale, modelScale);
    glTexCoord2f(0, 2);
    glVertex3f(-modelScale, 4*modelScale, -modelScale);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale, -modelScale);

    //RIGHT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(modelScale, -modelScale, -modelScale);
    glTexCoord2f(0, 2);
    glVertex3f(modelScale, 4*modelScale, -modelScale);
    glTexCoord2f(2, 2);
    glVertex3f(modelScale, 4*modelScale, modelScale);
    glTexCoord2f(2, 0);
    glVertex3f(modelScale, -modelScale, modelScale);
    
    glEnd();
    
    //Restore attribute state
    glPopAttrib();
    
    //Add the tower top
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glTranslatef(0, 4*modelScale, 0);
    DrawTowerTop(towerScale);
    glPopAttrib();
    glPopMatrix();
}

void Tower::DrawTowerBase(float towerScale) {
    //Save current attribute state
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    //Set diffuse material property
    float ambientMaterial[] = { 0.4f, 0.4f, 0.4f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 0.8f, 0.8f, 0.8f, 1.f };
    //Set specular material property
    float specularMaterial[] = { 0.9f, 0.9f, 0.9f, 1.f };
    //Set shininess material property
    float shininessMaterial[] = { 90.0 };
    
    //Material properties implementing the Phong model
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininessMaterial);
    
    //Change texture binding
    glBindTexture(GL_TEXTURE_2D, castleTowerBaseTexture);
    
    glBegin(GL_QUADS);
    
    //Towertop size
    float modelScale = mainCastleScale * towerScale * 1.25;

    //FRONT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale*2, modelScale); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale/2, modelScale); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale/2, modelScale); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale*2, modelScale); //Bottom left

    //BACK SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale*2, -modelScale); // Bottom Left
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale/2, -modelScale); // Top Left
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale/2, -modelScale); // Top Right
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale*2, -modelScale); // Bottom Right

    //TOP SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale/2, modelScale);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, modelScale/2, -modelScale);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, modelScale/2, -modelScale);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale/2, modelScale);

    //LEFT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 0);
    glVertex3f(-modelScale, -modelScale*2, modelScale);
    glTexCoord2f(1, 1);
    glVertex3f(-modelScale, modelScale/2, modelScale);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale/2, -modelScale);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale*2, -modelScale);

    //RIGHT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(modelScale, -modelScale*2, -modelScale);
    glTexCoord2f(0, 1);
    glVertex3f(modelScale, modelScale/2, -modelScale);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale/2, modelScale);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale*2, modelScale);

    glEnd();
    
    //Restore attribute state
    glPopAttrib();
}

void Tower::DrawTowerTop(float towerScale) {
    //Save current attribute state
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    //Set diffuse material property
    float ambientMaterial[] = { 0.3f, 0.3f, 0.3f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 0.8f, 0.8f, 0.8f, 1.f };
    //Set specular material property
    float specularMaterial[] = { 0.5f, 0.5f, 0.5f, 1.f };
    //Set shininess material property
    float shininessMaterial[] = { 10.0 };
    
    //Material properties implementing the Phong model
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininessMaterial);
    
    //Change texture binding
    glBindTexture(GL_TEXTURE_2D, castleTopTexture);
    
    //Towertop size
    float modelScale = mainCastleScale * towerScale * 1.15;
    
    //TOWER TOP BASE
    glBegin(GL_QUADS);

    //FRONT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale/5, modelScale); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale/5, modelScale); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale/5, modelScale); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale/5, modelScale); //Bottom left

    //BACK SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale/5, -modelScale); // Bottom Left
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale/5, -modelScale); // Top Left
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale/5, -modelScale); // Top Right
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale/5, -modelScale); // Bottom Right

    //TOP SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale/5, modelScale);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, modelScale/5, -modelScale);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, modelScale/5, -modelScale);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, modelScale/5, modelScale);

    //BOTTOM SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, -modelScale/5, modelScale);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale/5, -modelScale);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, -modelScale/5, -modelScale);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, -modelScale/5, modelScale);

    //LEFT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-modelScale, -modelScale/5, modelScale);
    glTexCoord2f(1, 1);
    glVertex3f(-modelScale, modelScale/5, modelScale);
    glTexCoord2f(1, 0);
    glVertex3f(-modelScale, modelScale/5, -modelScale);
    glTexCoord2f(0, 0);
    glVertex3f(-modelScale, -modelScale/5, -modelScale);

    //RIGHT
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(modelScale, -modelScale/5, -modelScale);
    glTexCoord2f(1, 0);
    glVertex3f(modelScale, modelScale/5, -modelScale);
    glTexCoord2f(1, 1);
    glVertex3f(modelScale, modelScale/5, modelScale);
    glTexCoord2f(0, 1);
    glVertex3f(modelScale, -modelScale/5, modelScale);
    glEnd();
    
    //Restore attribute state
    glPopAttrib();
     
    //TOWER TOP SQUARES
    // FRONT SIDE
    glPushMatrix();
    //Center square
    glTranslatef(0, modelScale/5, modelScale);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    //Left square
    glPushMatrix();
    glTranslatef(-modelScale/1.12, 0, 0);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    glPopMatrix();
    //Right square
    glPushMatrix();
    glTranslatef(modelScale/1.12, 0, 0);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    glPopMatrix();
    glPopMatrix();

    //RIGHT SIDE
    glPushMatrix();
    //Center square
    glRotatef(90.0f, 0, 1, 0);
    glTranslatef(0, modelScale/5, modelScale);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    //Left square
    glPushMatrix();
    glTranslatef(-modelScale/1.12, 0, 0);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    glPopMatrix();
    //Right square
    glPushMatrix();
    glTranslatef(modelScale/1.12, 0, 0);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    glPopMatrix();
    glPopMatrix();

    //LEFT SIDE
    glPushMatrix();
    //Center square
    glRotatef(-90.0f, 0, 1, 0);
    glTranslatef(0, modelScale/5, modelScale);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    //Left square
    glPushMatrix();
    glTranslatef(-modelScale/1.12, 0, 0);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    glPopMatrix();
    //Right square
    glPushMatrix();
    glTranslatef(modelScale/1.12, 0, 0);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    glPopMatrix();
    glPopMatrix();

    //BACK SIDE
    glPushMatrix();
    //Center square
    glRotatef(-180.0f, 0, 1, 0);
    glTranslatef(0, modelScale/5, modelScale);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    //Left square
    glPushMatrix();
    glTranslatef(-modelScale/1.12, 0, 0);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    glPopMatrix();
    //Right square
    glPushMatrix();
    glTranslatef(modelScale/1.12, 0, 0);
    topSquare->DrawTopSquare(mainCastleScale, towerScale);
    glPopMatrix();
    glPopMatrix();
}

