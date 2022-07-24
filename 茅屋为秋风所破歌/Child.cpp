#include "Child.h"

Child::Child() : dirction(0) {
	this->open(L"pic/child.png");
	this->setScale(0.2f, 0.2f);
	this->setAnchor(0, 1);
}

void Child::move(int dirction) {
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