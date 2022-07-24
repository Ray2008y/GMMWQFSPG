#include "Sky.h"

Sky::Sky() {
	sky1 = gcnew Sprite(L"pic/GameB.png");
	sky1->setAnchor(0, 1);
	sky1->setPos(0, Window::getHeight());
	this->addChild(sky1);
	sky2 = gcnew Sprite(L"pic/GameB.png");
	sky2->setAnchor(0, 1);
	sky2->setPos(sky1->getWidth(), Window::getHeight());
	this->addChild(sky2);
}
void Sky::move() {
	sky1->movePos(-6, 0);
	sky2->movePos(-6, 0);
	if (sky1->getPosX() <= -sky1->getWidth()) {
		sky1->setPosX(sky1->getWidth() - 1);
	}
	if (sky2->getPosX() <= -sky2->getWidth()) {
		sky2->setPosX(sky2->getWidth() - 1);
	}
}
