//
//  Wall.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Wall.hpp"

Wall::Wall(){
    castleWallTexture = Scene::GetTexture("./castleWallTexture.bmp");
    castleTopTexture = Scene::GetTexture("./castleTopTexture.bmp");
    
    //Initialise class
    topSquare = new TopSquare();
}

void Wall::DrawCastleWall(float castleScale, float towerSpacing, float iH) {
    mainCastleScale = castleScale;
    
    //Save attributes and change Texture
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
    
    //Change the texture binding
    glBindTexture(GL_TEXTURE_2D, castleWallTexture);
    
    //Assign scale
    float modelScale = mainCastleScale;
    
    glBegin(GL_QUADS);
    //FRONT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(towerSpacing, -modelScale*3, modelScale/2); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(towerSpacing, iH*2.5*modelScale, modelScale/2); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-towerSpacing, iH*2.5*modelScale, modelScale/2); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-towerSpacing, -modelScale*3, modelScale/2); //Bottom left

    //BACK SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-towerSpacing, -modelScale*3, -modelScale/2); // Bottom Left
    glTexCoord2f(0, 1);
    glVertex3f(-towerSpacing, iH*2.5*modelScale, -modelScale/2); // Top Left
    glTexCoord2f(1, 1);
    glVertex3f(towerSpacing, iH*2.5*modelScale, -modelScale/2); // Top Right
    glTexCoord2f(1, 0);
    glVertex3f(towerSpacing, -modelScale*3, -modelScale/2); // Bottom Right

    glEnd();
    
    //Restore attribute state
    glPopAttrib();
    
    //Draw the wall top
    glPushMatrix();
    glTranslatef(0, iH*2.5*modelScale, 0);
    DrawWallTop(towerSpacing);
    glPopMatrix();
}


void Wall::DrawWallTop(float towerSpacing) {
    //Save current attribute state
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    //Set diffuse material property
    float ambientMaterial[] = { 0.2f, 0.2f, 0.2f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 0.7f, 0.7f, 0.7f, 1.f };
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
    
    //WALL TOP BASE
    glBegin(GL_QUADS);
    //Towertop size
    float modelScale = mainCastleScale * 0.75;

    //FRONT SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 0);
    glVertex3f(towerSpacing, -modelScale/2, modelScale); //Bottom Right
    glTexCoord2f(1, 1);
    glVertex3f(towerSpacing, modelScale/5, modelScale); //Top Right
    glTexCoord2f(0, 1);
    glVertex3f(-towerSpacing, modelScale/5, modelScale); //Top left
    glTexCoord2f(0, 0);
    glVertex3f(-towerSpacing, -modelScale/2, modelScale); //Bottom left

    //BACK SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-towerSpacing, -modelScale/2, -modelScale); // Bottom Left
    glTexCoord2f(0, 1);
    glVertex3f(-towerSpacing, modelScale/5, -modelScale); // Top Left
    glTexCoord2f(1, 1);
    glVertex3f(towerSpacing, modelScale/5, -modelScale); // Top Right
    glTexCoord2f(1, 0);
    glVertex3f(towerSpacing, -modelScale/2, -modelScale); // Bottom Right

    //TOP SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1);
    glVertex3f(towerSpacing, modelScale/5, modelScale);
    glTexCoord2f(1, 0);
    glVertex3f(towerSpacing, modelScale/5, -modelScale);
    glTexCoord2f(0, 0);
    glVertex3f(-towerSpacing, modelScale/5, -modelScale);
    glTexCoord2f(0, 1);
    glVertex3f(-towerSpacing, modelScale/5, modelScale);

    //BOTTOM SIDE
    glColor4f(castleR, castleG, castleB, 1);
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-towerSpacing, -modelScale/2, modelScale);
    glTexCoord2f(0, 0);
    glVertex3f(-towerSpacing, -modelScale/2, -modelScale);
    glTexCoord2f(1, 0);
    glVertex3f(towerSpacing, -modelScale/2, -modelScale);
    glTexCoord2f(1, 1);
    glVertex3f(towerSpacing, -modelScale/2, modelScale);

    glEnd();
    
    //Restore attribute state
    glPopAttrib();
    
    //WALL SQUARES
    //FRONT SIDE
    for(int i=1; i<= towerSpacing/10; i++){
        glPushMatrix();
        //Top sqaures
        glTranslatef((i * modelScale) - (towerSpacing - (towerSpacing/16)), modelScale/8, modelScale);
        topSquare->DrawTopSquare(mainCastleScale, 1);
        glPopMatrix();
    }
    
    //BACK SIDE
    for(int i=1; i<= towerSpacing/10; i++){
        glPushMatrix();
        //Top squares
        glTranslatef((i * modelScale) - (towerSpacing - (towerSpacing/16)), modelScale/8, -modelScale);
        topSquare->DrawTopSquare(mainCastleScale, 1);
        glPopMatrix();
    }
}
