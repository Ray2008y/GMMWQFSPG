#include "Playerleft.h"

Playerleft::Playerleft() : dirction(0) {
	this->open(L"pic/player-left.png");
	this->setScale(0.2f, 0.2f);
	this->setAnchor(0, 1);
	this->setPos(300, Window::getHeight() - 142);
}

void Playerleft::move(int dirction) {
	switch (dirction) {
	case 1: {
		if (this->getPosX() > this->getWidth() / 2) {
			this->movePosX(-speed);
		}
		break;
	}
	case 2: {
		if (this->getPosX() < Window::getWidth() - this->getWidth() / 2) {
			this->movePosX(speed);
		}
		break;
	}
	case 3: {
		auto jumpBy = gcnew JumpBy(1, Point(), -75);
		this->runAction(jumpBy);
		break;
	}
	case 4: {
		if (this->getPosY() < Window::getHeight()) {
			this->movePosY(2);
		}
		break;
	}
	}
}