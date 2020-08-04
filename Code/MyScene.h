#pragma once

#include "../Framework/Engine/Scene.h"
#include "Desert.hpp"
#include "DayNightLighting.hpp"
#include "Castle.hpp"
#include "Stable.hpp"
#include "Cauldron.hpp"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};

private:
	void Initialise();
	void Projection();

};
