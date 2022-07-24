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
	scene = gcnew Scene;//�½�����
	auto background = gcnew Sprite(L"pic//cover.png");//�½�����
	background->setPos(Window::getSize() / 2);//����λ��
	background->setScale(1.0f, 1.0f);
	scene->addChild(background);//��������ӵ�������
	auto fadeIn = gcnew FadeIn(2);//�������붯��
	scene->runAction(fadeIn);
	SceneManager::enter(scene);//���볡��
	auto startbutton = gcnew Button;//��ʼ��ť
	startbutton->setNormal(gcnew Sprite(L"pic//button.png"));//��̬
	startbutton->setPos(520, 280);//����λ��
	auto Pcallback = []() {
		Start();
	};
	startbutton->setClickFunc(Pcallback);
	scene->addChild(startbutton);
}
int main() {
	Logger::showConsole(false);//���ؿ���̨
	if (Game::init(L"GAME", 960, 720)) {
		//std::cout << " Initialize the success!" << std::endl;
		Node::setDefaultAnchor(0.5f, 0.5f);
		EnterScene();
		//��������Ϸ����

		//��������Ϸ����
		Game::start();
	}
	Game::destroy();
	return 0;
}
