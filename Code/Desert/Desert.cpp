//
//  Terrain.cpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 07/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Desert.hpp"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

Desert::Desert() {
    //Set the texture
    terrainTexture = Scene::GetTexture("./desertTexture.bmp");
    
    //Give variables values
    rows = 50;
    cols = 50;
    scale = 70;
    minElevation = -15;
    maxElevation = 25;
    
    //Initialise the cumalative as 0
    cumulativeTime = 0.f;
    
    //Initialise tex coord and interactive speed
    interactiveSpeed = 3.5;
    texCoord = 0;
    
    //Generate the heights
    generatedElevation = generateRandomHeights(minElevation, maxElevation, cols, rows);
}

void Desert::Display()
{
    //Set the castle base colour
    glColor3f(0.5f, 0.5f, 0.5f);
    //glutWireCube(5);

    //Translate down and draw before moving back to center
    DrawTerrainMesh();
}

void Desert::Update(const double& deltaTime)
{
    //Make the seeder
    std::random_device seeder;
    //then make a mersenne twister engine
    std::mt19937 engine(seeder());
    
    //Accumulate time elapsed and cumalative time for sand animation
    timeElapsed += deltaTime;
    cumulativeTime += deltaTime / (interactiveSpeed*5);
    
    //Only move the heights if x amount of time has passed
    if (timeElapsed > interactiveSpeed/100) {
        //Iterativly draw triangles to create mesh
        for (int z = 0; z < rows-1; z++) {
            for (int x = 0; x < cols; x++) {
                //Set a distabution min and max
                std::uniform_int_distribution<int> dist(-1, 1);
                
                //Change the offset to create the animation
                textureCoordsOffsetRows = (float)(cumulativeTime + (double)z);
                
                //Create a random 
                float change = dist(engine)/interactiveSpeed;
                float minMaxCheck = generatedElevation[z][x] + change;
                
                //Change sand heights if the elevation doesnt surpass the max or min
                if (minMaxCheck >= minElevation && minMaxCheck <= maxElevation)  {
                    generatedElevation[z][x] += change;
                }
            }
        }
        //Reset time elapsed
        timeElapsed = 0;
    }
}

void Desert::DrawTerrainMesh(){
    //Save posistion
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    //Enable Texturing and colour material
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_COLOR_MATERIAL);
    
    //Set diffuse material property
    float ambientMaterial[] = { 0.3f, 0.3f, 0.3f, 1.f };
    //Set diffuse material property
    float diffuseMaterial[] = { 0.8f, 0.8f, 0.8f, 1.f };
    //Set specular material property
    float specularMaterial[] = { 0.0f, 0.0f, 0.0f, 1.f };
    //Set shininess material property
    float shininessMaterial[] = { 60.0 };
    
    //Material properties implementing the Phong model
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininessMaterial);
    
    // Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, terrainTexture);

    //Convert to line wire mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //Move base position down and center the mesh
    glTranslatef(-(rows*scale)/2, -200, -(cols*scale)/2);
    
    //Iterativly draw triangles to create mesh
    for (int z = 0; z < rows-1; z++) {
        glBegin(GL_TRIANGLE_STRIP);
        
        for (int x = 0; x < cols; x++) {
            //Set the normal
            glNormal3f(0.0f, 1.0f, 0.0f);
            //Apply texture and draw the deserts vertices with their randomly generated heights
            NextTextureCoord();
            glVertex3f(x*scale, generatedElevation[z][x], z*scale);
            NextTextureCoord();
            glVertex3f(x*scale, generatedElevation[z+1][x], (z+1)*scale);
        }
        texCoord = 0;
        glEnd();
    }
    
    glEnable(GL_COLOR_MATERIAL);
    glPopAttrib();
    glPopMatrix();
}

vector<vector<float>> Desert::generateRandomHeights(int minElevation, int maxElevation, int cols, int rows) {
    //the random device that will seed the generator
    std::random_device seeder;
    //then make a mersenne twister engine
    std::mt19937 engine(seeder());
    //then the easy part... the distribution
    std::uniform_int_distribution<int> dist(minElevation, maxElevation);
    //then just generate the integer like this:

    //Initialise array
    vector<vector<float>> elevationHeights;
    
    //Iterate through row and columns
    for (int z = 0; z < rows; z++) {
        //For each row make a vector
        vector<float> rowHeights;
        for (int x = 0; x < cols; x++) {
            //Generate a random height
            int randomHeight = dist(engine);
            
            //Push back random heights
            rowHeights.push_back(randomHeight);
        }
        //Push vector to umbrella vector
        elevationHeights.push_back(rowHeights);
    }
    
    return elevationHeights;
}

void Desert::NextTextureCoord() {
    //Check where the counter is and return coordinate accordingly
    if(texCoord == 0) {
        glTexCoord2f(0 + textureCoordsOffsetRows, 0);
    } else if(texCoord == 1) {
        glTexCoord2f(1 + textureCoordsOffsetRows, 0);
    } else if(texCoord == 2) {
        glTexCoord2f(0 + textureCoordsOffsetRows, 1);
    } else if(texCoord == 3) {
        glTexCoord2f(1 + textureCoordsOffsetRows, 1);
    }

    //If the counter is less than 3 increment to the next coordinate, else reset the counter
    if(texCoord < 3) {
        texCoord++;
    } else {texCoord = 0;}
}

void Desert::HandleKey(unsigned char key, int state, int x, int y) {
    // Ignore the key release
    if (!state) return;

    switch (key)
    {
    case '8':
        //Normal gametime speed
            interactiveSpeed = 3.5;
        break;
    case '9':
        //Fast gametime speed
            interactiveSpeed = 2;
        break;
    case '0':
        //Faster gametime speed
            interactiveSpeed = 0.5;
        break;
    }
}
