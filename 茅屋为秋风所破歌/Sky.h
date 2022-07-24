#pragma once
#include <easy2d/easy2d.h>
using namespace easy2d;

class Sky : public Sprite {
public:
	Sprite* sky1;
	Sprite* sky2;
	Sky();
	void move();
};
