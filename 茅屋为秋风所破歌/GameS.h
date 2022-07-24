#pragma once
#include <iostream>
#include "Playerleft.h"
using namespace easy2d;

class GameS : public Scene {
public:
	Sprite* wind;
	Sprite* house;
	GameS();
	void onUpdate() override;
};