#include <easy2d/easy2d.h>
#include <corecrt_math.h>
#include "Gold.h"

Gold::Gold() : Sprite(L"pic/gold.png") {
	this->setScale(0.2f, 0.2f);
	this->setAnchor(0, 1);
}
void Gold::move() {
	this->movePosX(-6);
}