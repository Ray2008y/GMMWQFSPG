#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

class Playerleft : public Sprite {
public:
	int dirction;
	float speed = 6;
	Playerleft();
	void move(int dirction);
};