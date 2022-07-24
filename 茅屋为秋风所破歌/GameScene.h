#pragma once
#include "Playerleft.h"
#include "Sky.h"
#include "Ground.h"
#include "Gold.h"
#include "Child.h"
#include "Stone.h"
#include <ctime>
using namespace easy2d;

class GameScene : public Scene {
public:
	Sky* sky;
	Playerleft* player;
	std::vector<Ground*> grounds;
	std::vector<Gold*> golds;
	int score = 0;
	Text* scoreText;
	time_t t;
	Text* timeText;
	Sprite* ending;
	bool judge = false, exist = false;
	int dir = 2;
	Child* child;
	std::vector<Stone*> stones;
	GameScene();
	void onUpdate() override;
};