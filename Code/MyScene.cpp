#include <cstdlib>
#include <string>

#include "MyScene.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
    //Create the objects
    Desert *desert = new Desert();
    DayNightLighting *dayNightLighting = new DayNightLighting();
    Castle *castle = new Castle();
    Stable *stable = new Stable();
    Cauldron *cauldron = new Cauldron();
    
    //Add the objects to the scene
    AddObjectToScene(desert);
    AddObjectToScene(dayNightLighting);
    AddObjectToScene(castle);
    AddObjectToScene(stable);
    AddObjectToScene(cauldron);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 100000.0);
}
