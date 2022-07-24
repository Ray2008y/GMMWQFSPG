#include <easy2d/easy2d.h>
#include <corecrt_math.h>
#include "Stone.h"

Stone::Stone() : Sprite(L"pic/stone.png") {
	this->setScale(0.3f, 0.3f);
	this->setAnchor(0.05f, 0.05f);
	auto rotateBy = gcnew RotateBy(0.25f, 15.f);
	auto LoopRB = gcnew Loop(rotateBy);
	this->runAction(LoopRB);
}
void Stone::move() {
	this->setPosX(getPosX() + speed);
}