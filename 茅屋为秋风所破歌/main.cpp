#include <iostream>
#include <easy2d/easy2d.h>
#include "GameS.h"
using namespace easy2d;
Scene* scene;
bool Start() {
	auto gs = gcnew GameS();
	SceneManager::enter(gs);
	return true;
}
void EnterScene() {
	scene = gcnew Scene;//新建场景
	auto background = gcnew Sprite(L"pic//cover.png");//新建背景
	background->setPos(Window::getSize() / 2);//生成位置
	background->setScale(1.0f, 1.0f);
	scene->addChild(background);//将背景添加到场景中
	auto fadeIn = gcnew FadeIn(2);//创建渐入动画
	scene->runAction(fadeIn);
	SceneManager::enter(scene);//进入场景
	auto startbutton = gcnew Button;//开始按钮
	startbutton->setNormal(gcnew Sprite(L"pic//button.png"));//常态
	startbutton->setPos(520, 280);//生成位置
	auto Pcallback = []() {
		Start();
	};
	startbutton->setClickFunc(Pcallback);
	scene->addChild(startbutton);
}
int main() {
	Logger::showConsole(false);//隐藏控制台
	if (Game::init(L"GAME", 960, 720)) {
		//std::cout << " Initialize the success!" << std::endl;
		Node::setDefaultAnchor(0.5f, 0.5f);
		EnterScene();
		//以下是游戏代码

		//以上是游戏代码
		Game::start();
	}
	Game::destroy();
	return 0;
}
