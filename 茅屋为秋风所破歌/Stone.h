#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

class Stone : public Sprite {
public:
	float speed = 4 * Random::range(-1.f, 1.f);
	Stone();
	void move();
};