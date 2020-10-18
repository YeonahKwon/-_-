#include <bangtal.h>

using namespace bangtal;

int main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	auto dangg = 0;
	auto coin = 0;

	auto horsefeed = 0;
	auto horsefashion = 0;
	auto horsefeel = 0;

	//1. 장면 생성
	ScenePtr scene0 = Scene::create("제주도 어딘가", "images/말집.png");
	ScenePtr scene1 = Scene::create("집", "images/말집.png");
	ScenePtr scene2 = Scene::create("지도", "images/지도.png");
	ScenePtr scene3 = Scene::create("당근밭", "images/당근밭.png");
	ScenePtr scene4 = Scene::create("바닷길", "images/바다말.png");
	ScenePtr scene5 = Scene::create("상점", "images/상점.png");
	ScenePtr scene6 = Scene::create("당근코인", "images/당근코인배경.png");
	ScenePtr scene7 = Scene::create("말 상태", "images/상태배경.png");

	auto sound = Sound::create("제주도의푸른밤.mp3");
	sound->play();

	//시작 종료 버튼 생성

	auto intro = Object::create("images/인트로.png", scene0, 10, 175);
	auto startButton = Object::create("images/시작버튼.png", scene0, 290, 20);
	startButton->setScale(0.7f);
	auto endButton = Object::create("images/종료버튼.png", scene0, 680, 20);
	endButton->setScale(0.7f);

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		startButton->hide();
		endButton->hide();
		intro->hide();
		scene1->enter();
		//말 만든다
		auto horse = Object::create("images/기본말.png", scene1, 200, 150);
		horse->setScale(1.2f);      //크기조정
		showMessage("힐링프로젝트 [제주 馬]\n당신의 말을 키워라!");



		//당코상태
		/*
		auto dangcoin = Object::create("images/당코상태.png", scene1, 200, 10);
		dangcoin->setScale(0.3f);
		dangcoin->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene6->enter();
			auto car0 = Object::create("images/영.png", scene6, 600, 360,false);
			auto car1 = Object::create("images/일.png", scene6, 600, 360,false);
			auto car2 = Object::create("images/이.png", scene6, 600, 360, false);
			auto car3 = Object::create("images/삼.png", scene6, 600, 360, false);
			auto car4 = Object::create("images/사.png", scene6, 600, 360, false);
			auto car5 = Object::create("images/오.png", scene6, 600, 360, false);

			if (dangg == 0)
			{
				car0->show();
				car1->hide();
				car2->hide();
				car3->hide();
				car4->hide();
				car5->hide();
			}
			if(dangg==1)
			{
				car0->hide();
				car1->show();
				car2->hide();
				car3->hide();
				car4->hide();
				car5->hide();
			}

			return true;
			});
		auto close1 = Object::create("images/닫기.png", scene6, 200, 10);
		close1->setScale(0.3f);
		close1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene1->enter();
			return true;
			});

			*/

			//말상태///////////////////////////////////
		auto now = Object::create("images/말상태.png", scene1, 30, 5);
		now->setScale(0.3f);
		now->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene7->enter();
			if (horsefashion == 100)
			{
				auto fashion = Object::create("images/도장.png", scene7, 650, 460);
				fashion->setScale(0.5f);
			}
			if (horsefeed == 100)
			{
				auto feed = Object::create("images/도장.png", scene7, 650, 280);
				feed->setScale(0.5f);
			}
			if (horsefeel >= 100)
			{
				auto feel = Object::create("images/도장.png", scene7, 650, 100);
				feel->setScale(0.5f);
			}

			return true;
			});
		auto close2 = Object::create("images/닫기.png", scene7, 200, 10);
		close2->setScale(0.3f);
		close2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene1->enter();
			return true;
			});
		////////////////////////////////



		//당근먹이기
		auto feed = Object::create("images/당근먹이기.png", scene1, 210, 10); //370 10
		feed->setScale(0.3f);
		feed->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (dangg == 0)
			{
				showMessage("당근이 없습니당근");
			}
			else
			{
				showMessage("말이 당근을 먹었당근!");
				dangg = dangg - 1;
				horsefeed = horsefeed + 25;
				if (horsefeed >= 100 && horsefashion >= 100 && horsefeel >= 100)
				{
					showMessage("말이 행복해졌당근!\n이제 집으로 돌아가도 좋당근!");
					auto gohome = Object::create("images/육지.png", scene1, 150, 210);
					gohome->setScale(0.7f);
					gohome->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
						endGame();
						return true;
						});
				}
			}
			return true;
			});



		//지도 아이콘
		auto map1 = Object::create("images/지도아이콘.png", scene1, 1150, 610);
		map1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene2->enter();
			return true;
			});

		return true;
		});

	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();

		return true;
		});


	//지도아이콘 

	auto map2 = Object::create("images/지도아이콘.png", scene3, 1150, 610);
	map2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});
	auto map3 = Object::create("images/지도아이콘.png", scene4, 1150, 610);
	map3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});
	auto map4 = Object::create("images/지도아이콘.png", scene5, 1150, 610);
	map4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});


	//팻말생성
	auto h_go = Object::create("images/집팻말.png", scene2, 820, 70);
	h_go->setScale(0.7f);
	h_go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
		});
	auto c_go = Object::create("images/당근밭팻말.png", scene2, 40, 20);
	c_go->setScale(0.7f);
	c_go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene3->enter();
		return true;
		});
	auto s_go = Object::create("images/바닷길팻말.png", scene2, 320, 330);
	s_go->setScale(0.7f);
	s_go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showMessage("제주도의 바다는 참 예쁘당근...\n말의 기분이 좋아졌당근!");
		horsefeel = horsefeel + 25;
		if (horsefeed >= 100 && horsefashion >= 100 && horsefeel >= 100)
		{
			showMessage("말이 행복해졌당근!\n이제 집으로 돌아가도 좋당근!");
			auto gohome = Object::create("images/육지.png", scene2, 150, 210);
			gohome->setScale(0.7f);
			gohome->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				endGame();
				return true;
				});
		}
		scene4->enter();
		return true;
		});
	auto m_go = Object::create("images/상점팻말.png", scene2, 840, 330);
	m_go->setScale(0.7f);
	m_go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene5->enter();
		return true;
		});




	//당근밭게임///////////////////////

	auto carrot = 0;
	auto playButton = Object::create("images/당근버튼.png", scene3, 800, 10, false);
	playButton->setScale(0.7f);
	auto carrotstart = Object::create("images/시작버튼.png", scene3, 500, 20);
	carrotstart->setScale(0.7f);
	auto carrotgame = Object::create("images/당게설명.png", scene3, 210, 300);
	carrotgame->setScale(0.7f);

	auto seed = Object::create("images/씨앗.png", scene3, 570, 230, false);
	seed->setScale(1.2f);
	auto sand = Object::create("images/흙.png", scene3, 450, 200, false);
	auto cloud = Object::create("images/구름.png", scene3, 500, 500, false);
	cloud->setScale(0.7f);
	auto rain = Object::create("images/비.png", scene3, 550, 300, false);
	rain->setScale(0.7f);
	auto dang1 = Object::create("images/당근1.png", scene3, 550, 130, false);
	auto dang2 = Object::create("images/당근2.png", scene3, 550, 160, false);
	auto dang3 = Object::create("images/당근3.png", scene3, 500, 200, false);
	auto dang4 = Object::create("images/당근.png", scene3, 550, 250, false);
	dang4->setScale(1.5f);

	auto timer = Timer::create(10.f);



	carrotstart->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		carrotstart->hide();
		carrotgame->hide();
		playButton->show();
		dang4->hide();

		showTimer(timer);
		timer->setOnTimerCallback([&](TimerPtr)->bool {
			showMessage("당근 키우기 실패");
			carrotstart->show();
			timer->stop();
			playButton->hide();
			seed->hide();
			sand->hide();
			cloud->hide();
			rain->hide();
			dang1->hide();
			dang2->hide();
			dang3->hide();
			return true;
			});

		carrot = 0;
		timer->set(10.f);
		timer->start();
		return true;
		});

	playButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		carrot = carrot + 1;
		if (carrot == 3) {
			seed->show();
		}
		else if (carrot == 6) {
			seed->hide();
			sand->show();
		}
		else if (carrot == 9) {
			sand->hide();
			cloud->show();
		}
		else if (carrot == 12) {
			rain->show();
		}
		else if (carrot == 15) {
			cloud->hide();
			rain->hide();
			dang1->show();
		}
		else if (carrot == 18)
		{
			dang1->hide();
			dang2->show();
		}
		else if (carrot == 21)
		{
			dang2->hide();
			dang3->show();
		}
		else if (carrot == 24) {
			dang3->hide();
			dang4->show();
			showMessage("당근 키우기 성공!");
			if (dangg == 5) showMessage("당근이 너무 많당근...");
			else
			{
				dangg = dangg + 1;
			}
			carrotstart->show();
			timer->stop();
			playButton->hide();
		}


		return true;
		});
	////////////////////////////////


	///상점이용//////////////////
	auto buy = Object::create("images/구매버튼.png", scene5, 330, 350);
	buy->setScale(0.7f);
	auto sale = Object::create("images/판매버튼.png", scene5, 330, 150);
	sale->setScale(0.7f);
	auto flower_buy = Object::create("images/꽃세트.png", scene5, 330, 500, false);
	flower_buy->setScale(0.6f);
	auto latte_buy = Object::create("images/라떼세트.png", scene5, 330, 260, false);
	latte_buy->setScale(0.6f);
	auto child_buy = Object::create("images/멜빵세트.png", scene5, 330, 20, false);
	child_buy->setScale(0.6f);
	auto carrot_sale = Object::create("images/당근판매.png", scene5, 330, 10, false);
	carrot_sale->setScale(0.7f);
	auto carrotcoin = Object::create("images/일당이코.png", scene5, 360, 240, false);
	carrotcoin->setScale(0.7f);
	auto shopmain = Object::create("images/상점정문.png", scene5, 700, 130, false);
	shopmain->setScale(0.4f);

	buy->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		buy->hide();
		sale->hide();
		flower_buy->show();
		latte_buy->show();
		child_buy->show();
		shopmain->show();

		flower_buy->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (coin < 10)
			{
				showMessage("코인이 부족합니당근");
			}
			else
			{
				coin = coin - 10;
				horsefashion = 100;
				showMessage("옷을 구매했당근");
				if (horsefeed >= 100 && horsefashion >= 100 && horsefeel >= 100)
				{
					showMessage("말이 행복해졌당근!\n이제 집으로 돌아가도 좋당근!");
					auto gohome = Object::create("images/육지.png", scene2, 150, 210);
					gohome->setScale(0.7f);
					gohome->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
						endGame();
						return true;
						});
				}
				auto flowerhorse = Object::create("images/꽃말.png", scene1, 200, 150);
				flowerhorse->setScale(1.2f);      //크기조정
			}
			return true;
			});
		latte_buy->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (coin < 10)
			{
				showMessage("코인이 부족합니당근");
			}
			else
			{
				coin = coin - 10;
				horsefashion = 100;
				showMessage("옷을 구매했당근");
				if (horsefeed >= 100 && horsefashion >= 100 && horsefeel >= 100)
				{
					showMessage("말이 행복해졌당근!\n이제 집으로 돌아가도 좋당근!");
					auto gohome = Object::create("images/육지.png", scene2, 150, 210);
					gohome->setScale(0.7f);
					gohome->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
						endGame();
						return true;
						});
				}
				auto lattehorse = Object::create("images/라떼말.png", scene1, 200, 150);
				lattehorse->setScale(1.2f);      //크기조정
			}
			return true;
			});
		child_buy->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (coin < 10)
			{
				showMessage("코인이 부족합니당근");
			}
			else
			{
				horsefashion = 100;
				coin = coin - 10;
				showMessage("옷을 구매했당근");
				if (horsefeed >= 100 && horsefashion >= 100 && horsefeel >= 100)
				{
					showMessage("말이 행복해졌당근!\n이제 집으로 돌아가도 좋당근!");
					auto gohome = Object::create("images/육지.png", scene2, 150, 210);
					gohome->setScale(0.7f);
					gohome->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
						endGame();
						return true;
						});
				}
				auto childhorse = Object::create("images/어린이말.png", scene1, 200, 150);
				childhorse->setScale(1.2f);      //크기조정
			}
			return true;
			});
		shopmain->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			buy->show();
			sale->show();
			flower_buy->hide();
			latte_buy->hide();
			child_buy->hide();
			shopmain->hide();
			carrot_sale->hide();
			carrotcoin->hide();
			return true;
			});

		return true;
		});


	sale->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		buy->hide();
		sale->hide();
		carrot_sale->show();
		carrotcoin->show();
		shopmain->show();

		carrot_sale->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (dangg == 0)
			{
				showMessage("판매할 당근이 없습니당근!");
			}
			else if (coin == 10)
			{
				showMessage("지갑이 너무 무겁당근...");
			}
			else
			{
				showMessage("2코인을 벌었당근!");
				dangg = dangg - 1;
				coin = coin + 2;
			}
			return true;
			});
		shopmain->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			buy->show();
			sale->show();
			flower_buy->hide();
			latte_buy->hide();
			child_buy->hide();
			shopmain->hide();
			carrot_sale->hide();
			carrotcoin->hide();
			return true;
			});

		return true;

		});


	/////////////////////////////////////////////

	//2. 게임 시작
	startGame(scene0);

	return 0;
}