#include <easy2d/easy2d.h>
#include "Ground.h"

Ground::Ground() {
	this->open(L"pic/Ground.png");
	this->setAnchor(0, 1);
}
void Ground::move() {
	this->movePos(-6, 0);
}
