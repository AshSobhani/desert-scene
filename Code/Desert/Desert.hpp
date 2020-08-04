//
//  Terrain.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 07/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

using namespace std;

class Desert :
    public DisplayableObject, public Animation, public Input
{
public:
    Desert();
    ~Desert(){};

    //Declare functions
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

private:
    //Declare variables
    int rows, cols, scale, minElevation, maxElevation, texCoord;
    float interactiveSpeed, radius, cumulativeTime, textureCoordsOffsetRows, textureCoordsOffsetCols;
    GLint terrainTexture;
    vector<vector<float>> generatedElevation;
    double timeElapsed;

    
    //Declare functions
    void DrawTerrainMesh();
    vector<vector<float>> generateRandomHeights(int minElevation, int maxElevation, int cols, int rows);
    void NextTextureCoord();
};
