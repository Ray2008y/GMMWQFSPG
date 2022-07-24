#include <easy2d/easy2d.h>
#include "GameScene.h"
#include "GameS.h"

GameScene::GameScene() {
	t = time(NULL);
	sky = gcnew Sky();
	this->addChild(sky);
	auto ground = gcnew Ground();
	ground->setPos(0, Window::getHeight());
	this->addChild(ground);
	grounds.push_back(ground);
	player = gcnew Playerleft();
	this->addChild(player);
	scoreText = gcnew Text;
	scoreText->setAnchor(0.5f, 0);
	scoreText->setPos(Window::getWidth() - 50, 20);
	scoreText->setText(L"score:0");
	this->addChild(scoreText);
	timeText = gcnew Text;
	timeText->setAnchor(0.5f, 0);
	timeText->setPos(50, 20);
	timeText->setText(L"time:0");
	this->addChild(timeText);
}
void GameScene::onUpdate() {
	if (score >= 50) {
		ending = gcnew Sprite(L"pic/end.png");
		ending->setPos(Window::getSize() / 2);
		this->addChild(ending);
		if (!judge) {
			score = difftime(time(NULL), t);
			judge = true;
		}
		auto TimeText = gcnew Text;
		TimeText->setPos(477, 360);
		TimeText->setColor(Color::Red);
		TimeText->setFont(Font(L"AaÎ´À´ºÚ", 50, Font::Weight::Bold, false));
		TimeText->setText(L"time:" + std::to_wstring(score));
		this->addChild(TimeText);
		if (Input::isDown(KeyCode::Enter)) {
			SceneManager::enter(gcnew GameS());
		}
	}
	else if (player->getPosY() >= Window::getHeight()) {
		player->setVisible(false);
		auto ScoreText = gcnew Text;
		ScoreText->setPos(475, 360);
		ScoreText->setColor(Color::WhiteSmoke);
		ScoreText->setText(L"ÄãÊ§°ÜÁË£¡");
		this->addChild(ScoreText);
		if (Input::isDown(KeyCode::Enter)) {
			SceneManager::enter(gcnew GameS());
		}
	}
	else {
		timeText->setText(L"time:" + std::to_wstring(int(difftime(time(NULL), t))));
		if (Input::isDown(KeyCode::D) || Input::isDown(KeyCode::Right)) {
			sky->move();
			for (int i = 0; i < grounds.size(); i++) {
				auto ground = grounds[i];
				ground->move();
			}
			for (int i = 0; i < golds.size(); i++) {
				auto gold = golds[i];
				gold->move();
			}
			for (int i = 0; i < stones.size(); i++) {
				auto stone = stones[i];
				stone->movePosX(-6);
			}
			if (exist) {
				child->movePosX(-6);
			}
		}
		std::vector<Ground*> del1;
		bool flag = false;
		for (int i = 0; i < grounds.size(); i++) {
			auto ground = grounds[i];
			if (exist) {
				if (child->getPosY() == ground->getPosY() - ground->getHeight()) {
					if (child->getPosX() <= ground->getPosX()) {
						dir = 2;
					}
					if (child->getPosX() >= ground->getPosX() + ground->getWidth()) {
						dir = 1;
					}
					child->move(dir);
					if (child->getPosX() + child->getWidth() <= 0) {
						exist = false;
					}
					if (!stones.empty()) {
						auto stone = stones[stones.size() - 1];
						if (abs(stone->getPosX() - child->getPosX()) >= 400) {
							auto stonenew = gcnew Stone();
							stonenew->setPos(child->getPos());
							this->addChild(stonenew);
							stones.push_back(stonenew);
						}
					}
					else {
						auto stonenew = gcnew Stone();
						stonenew->setPos(child->getPos());
						this->addChild(stonenew);
						stones.push_back(stonenew);
					}
				}
			}
			if (ground->getPosX() + ground->getWidth() <= 0) {
				del1.push_back(ground);
			}
			if (player->getPosX() <= ground->getPosX() + ground->getWidth() && player->getPosX() >= ground->getPosX() - player->getWidth()) {
				flag = true;
				if (player->getPosY() == ground->getPosY() - ground->getHeight()) {
					if (Input::isDown(KeyCode::Space)) {
						player->move(3);
					}
				}
				else if (player->getPosY() > ground->getPosY() - ground->getHeight() && player->getPosY() <= ground->getPosY() - ground->getHeight() + 20) {
					player->setPosY(ground->getPosY() - ground->getHeight());
				}
				else if (player->getPosY() < ground->getPosY() - ground->getHeight()) {
					player->move(4);
				}
				else {
					flag = false;
				}
			}
		}
		if (!flag) {
			player->move(4);
		}
		std::vector<Gold*> del2;
		for (int i = 0; i < golds.size(); i++) {
			auto gold = golds[i];
			if (gold->getPosX() + gold->getWidth() <= 0) {
				del2.push_back(gold);
			}
			if (player->containsPoint(Point(gold->getPos()))) {
				score++;
				scoreText->setText(L"score:" + std::to_wstring(score));
				gold->setVisible(false);
				del2.push_back(gold);
			}
		}
		std::vector<Stone*> del3;
		for (int i = 0; i < stones.size(); i++) {
			auto stone= stones[i];
			stone->move();
			if (stone->getPosX() + stone->getWidth() <= 0) {
				stone->setVisible(false);
				del3.push_back(stone);
			}
			if (player->containsPoint(Point(stone->getPos()))) {
				player->setVisible(false);
				player->setPosY(Window::getHeight());
			}
		}
		for (size_t i = 0; i < del1.size(); i++) {
			auto ground = del1[i];
			auto it = grounds.begin();
			while (it != grounds.end()) {
				if (*it == ground) {
					grounds.erase(it);
					break;
				}
				else {
					it++;
				}
			}
		}
		for (size_t i = 0; i < del2.size(); i++) {
			auto gold = del2[i];
			auto it = golds.begin();
			while (it != golds.end()) {
				if (*it == gold) {
					golds.erase(it);
					break;
				}
				else {
					it++;
				}
			}
		}
		for (size_t i = 0; i < del3.size(); i++) {
			auto stone = del3[i];
			auto it = stones.begin();
			while (it != stones.end()) {
				if (*it == stone) {
					stones.erase(it);
					break;
				}
				else {
					it++;
				}
			}
		}
		auto ground = grounds[grounds.size() - 1];
		if (ground->getPosX() + ground->getWidth() < Window::getWidth()) {
			auto groundnew = gcnew Ground();
			do {
				groundnew->setPos(ground->getPosX() + ground->getWidth() + Random::range(10, 200), ground->getPosY() + Random::range(-20, 20));
			} while (groundnew->getPosY() > Window::getHeight() || groundnew->getPosY() - player->getHeight() < 0);
			groundnew->setScale(Random::range(0.1f, 1.0f), Random::range(0.1f, 1.0f));
			this->addChild(groundnew);
			grounds.push_back(groundnew);
			for (int i = 1; i <= Random::range(0.f, 3.f); i++) {
				auto gold = gcnew Gold();
				gold->setPos(groundnew->getPosX() + Random::range(0, groundnew->getWidth()), groundnew->getPosY() - groundnew->getHeight() - Random::range(20, 200));
				this->addChild(gold);
				golds.push_back(gold);
			}
			if (!exist && Random::range(0.f, 10.f) <= 1) {
				child = gcnew Child();
				child->setPos(groundnew->getPosX(), groundnew->getPosY() - groundnew->getHeight());
				this->addChild(child);
				exist = true;
			}
		}
	}
}