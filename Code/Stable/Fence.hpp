//
//  Fence.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "DisplayableObject.h"

class Fence {
public:
    Fence();
    ~Fence() {};

    //Declare functions
    void DrawStableFences(float stableScale, float fenceLength);
private:
    //Declare functions
    void DrawFence(float fenceLength);
    
    //Declare variables
    GLint stableFenceTexture;
    float mainStableScale;
    float stableR, stableG, stableB;
};
