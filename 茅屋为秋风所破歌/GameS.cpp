#include <easy2d/easy2d.h>
#include "GameS.h"
#include "GameScene.h"

GameS::GameS() {
	auto gameBackGround = gcnew Sprite(L"Pic//GameB.png");
	gameBackGround->setPos(Window::getSize() / 2);
	gameBackGround->setScale(1.0f, 1.0f);
	this->addChild(gameBackGround);
	auto Ground = gcnew Sprite(L"Pic//Ground.png");
	Ground->setAnchor(0, 1);
	Ground->setPos(0, Window::getHeight());
	Ground->setScale(1.0f, 1.0f);
	this->addChild(Ground);
	wind = gcnew Sprite(L"Pic//wind.png");
	wind->setPos(Window::getWidth() - 50, 280);
	wind->setScale(0.5f, 0.5f);
	this->addChild(wind);
	auto player = gcnew Playerleft();
	this->addChild(player);
	house = gcnew Sprite(L"Pic//house.png");
	house->setPos(300, Window::getHeight() - 220);
	house->setScale(0.2f, 0.2f);
	this->addChild(house);
}
void GameS::onUpdate() {
	if (Input::isDown(MouseCode::Left)) {
		SceneManager::enter(gcnew GameScene());
	}
	if (house->containsPoint(Point(wind->getPos()))) {
		wind->setVisible(false);
		auto rotateBy = gcnew RotateBy(0.5f, 20.f);
		auto alwaysRB = gcnew Loop(rotateBy);
		if (house->getPosX() <= 50) {
			house->setVisible(false);
			SceneManager::enter(gcnew GameScene());
		}
		else {
			house->runAction(alwaysRB);
			house->movePosX(-3);
			house->movePosY(-1);
		}
	}
	else {
		wind->movePosX(-5);
		wind->movePosY(2);
	}
}
