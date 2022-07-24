#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

class Child : public Sprite {
public:
	int dirction;
	float speed = 7;
	Child();
	void move(int dirction);
};