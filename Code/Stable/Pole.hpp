//
//  Pole.hpp
//  G53GRA.Framework
//
//  Created by Ash Sobhani on 20/05/2020.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"

class Pole {
public:
    Pole();
    ~Pole() {};

    //Declare functions
    void DrawStablePole(float stableScale);
private:
    //Declare functions
    void DrawPoleBase();
    
    //Declare variables
    GLint stablePoleTexture;
    float mainStableScale;
    float stableR, stableG, stableB;
};
