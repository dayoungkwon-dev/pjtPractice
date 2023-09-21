﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <windows.h>

// color상수 지정 
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 


// 프로젝트7. 클래스 종합 - 게임 만들기
using namespace std;


void textcolor(int foreground, int background);

class Character {
public:
	static int hp;
	static int level;
	//static vector<Weapon*> weapons;
	static vector<string> weapons;
public:
	Character() {}

	//getter,setter
	static void setHp(int chgHp) {
		hp = chgHp;
	}
	static int getHp() {
		return hp;
	}
	static void setLevel(int chgLevel) {
		level = chgLevel;
	}
	static int getLevel() {
		return level;
	}
	
	void pickWeapon(string newWeapon) {
		// 무기추가
		weapons.push_back(newWeapon);
	}

	void attack(){
		// 보유 무기들로만 공격 가능.
	}

	void getDamage(int power) {
		hp = hp - power;
	}
};

class Weapon {
protected:
	int offensePower{ 0 };	// 공격력
	int attackCnt{ 0 };		// 공격 가능 횟수

public:
	virtual void attack() {
		cout << "공격하기" << endl;
	}
};

class Gun : public Weapon {
public:
	int offensePower;
	int attackCnt;

public:
	Gun() {
		this->offensePower = 10;
		this->attackCnt = 1;
	}
	int getPower() {
		return offensePower;
	}
	int getAttackCnt() {
		return attackCnt;
	}
	void attack() {
		textcolor(YELLOW, RED);
		cout << "\n      ------ 총쏘기 -------     ( -10 HP ) " << endl;
		textcolor(LIGHTGRAY, BLACK);
	}
};

class Knife : public Weapon {
public:
	int offensePower;
	int attackCnt;

public:
	Knife() {
		this->offensePower = 5;
		this->attackCnt = 3;
	}
	int getPower() {
		return offensePower;
	}
	int getAttackCnt() {
		return attackCnt;
	}
	void attack() {
		textcolor(YELLOW, RED);
		cout << "\n      ------ 찌르기 -------     ( -5 HP ) " << endl;
		textcolor(LIGHTGRAY,BLACK);
	}
};

class Monster {
public:
	static int mstHp;
	static string mstName;

public:
	Monster(){}

	void setMstHp(int chaLevel) {
		mstHp = chaLevel * 5 * 10;
	}
	int getMstHp() {
		return mstHp;
	}
	void setMstName(int chaLevel) {
		mstName = "Monster" + to_string(chaLevel);
	}
	string getMstName() {
		return mstName;
	}
	void getAttack(int power) {
		mstHp = mstHp - power;
	}
};


int Character::hp = 100;
int Character::level = 1;
vector<string> Character::weapons = {};
int Monster::mstHp = 0;
string Monster::mstName = "Monster";

void levelUp(int level, int hp);
void attackGun();
void attackKnife();
void showMonster();
void youDie();
void showPotential();
void myHp(int hp);
//void textcolor(int foreground, int background);


int main() {
	Character c1;
	bool attacked = false;
	int action, weaponAcction, next, yHp, nHp;
	vector<Weapon*> weaponBasket;

	cout << "-------------------- 게임 시작 -------------------- " << endl;
	cout << "현재 hp : " << c1.hp << ", level : " << c1.level << endl;

	// 해당 레벨 몬스터 생성.
	Monster m = Monster();
	m.setMstHp(c1.level);
	m.setMstName(c1.level);

	// 무기줍기
	cout << " >>>>>> 총 발견 >>>> (1:무기줍기, 2:지나가기) : ";
	cin >> weaponAcction;
	if (weaponAcction == 1) {
		weaponBasket.push_back(new Gun());
	}
	cout << " >>>>>> 칼 발견 >>>> (1:무기줍기, 2:지나가기) : ";
	cin >> weaponAcction;
	if (weaponAcction == 1) {
		weaponBasket.push_back(new Knife());
	}


	clock_t startTime = clock();
	while (1) {
		showMonster();
		cout << "////// 몬스터 : " << Monster::mstName << " , HP : " << Monster::mstHp << " ///////" << endl;
		cout << endl;

		// 몬스터 만난지 10초 지나면 데미지.
		clock_t endTime = clock();
		if ((endTime - startTime) / CLOCKS_PER_SEC >= 10) {
			textcolor(YELLOW, RED);
			cout << "\n ----------- 몬스터 공격 ◐ㅁ◑ ----------" << endl;
			cout << " ------------ 피해량 : -" << 10 * c1.level << " HP ------------" << endl;
			textcolor(LIGHTGRAY, BLACK);
			c1.getDamage(10 * c1.level);
			myHp(c1.hp);

			// GAME OVER
			if (c1.hp <= 0) {
				youDie();
				break;
			}
		}

		cout << "공격을 선택해주세요. (1:총, 2:칼)";
		cin >> action;
		if (action == 1 || action == 2) {
			if (weaponBasket.empty()) {
				cout << "공격할 수 있는 무기가 없습니다. " << endl;
			}
			for (Weapon* weapon : weaponBasket) {
				attacked = false;
				Gun* pg = dynamic_cast<Gun*>(weapon);
				Knife* pn = dynamic_cast<Knife*>(weapon);
				int gPower = 0;
				if (pg) {
					if (action == 1) {
						pg->attack();
						//attackGun();
						gPower = pg->offensePower;
						m.getAttack(gPower);
						attacked = true;
					}
				}
				else if(pn) {
					int nPower = 0;
					if (action == 2) {
						pn->attack();
						//attackKnife();
						nPower = pn->offensePower;
						m.getAttack(nPower);
						attacked = true;
					}
				}
				else {
					if (!attacked) {
						cout << "해당 무기를 보유하고 있지 않습니다. " << endl;
					}
				}
			}
		}
		else {
			// 1,2 이외의 입력.
			cout << "잘못된 공격입니다." << endl;
		}

		if (Monster::mstHp <= 0) {
			next = 0;
			textcolor(WHITE, GREEN);
			cout << "\n----------------------------------------------------" << endl;
			cout << "--------------- 몬스터 처치 완료 !! ----------------" << endl;
			cout << "----------------------------------------------------" << endl;
			textcolor(LIGHTGRAY, BLACK);
			levelUp(c1.level, c1.hp);
			cout << "\n다음 레벨 게임을 진행하시겠습니까? (1:YES, 2:EXIT) " << endl;
			cin >> next;
			if (next == 1) {
				// 다음레벨 몬스터 update.
				m.setMstHp(c1.level);
				m.setMstName(c1.level);
				textcolor(WHITE, BLUE);
				cout << "                 ☞ NEXT STAGE ☜                  " << endl;
				textcolor(LIGHTGRAY, BLACK);
			}
			else if (next == 2) {
				break;
			}
		}
	}

	for (Weapon* weapon : weaponBasket) {
		delete weapon;
	}
}

// 레벨업 함수 - 레벨업 선물 증정. (물약 랜덤)
void levelUp(int level, int hp) {
	int rNum;
	srand(time(NULL));
	rNum = (rand() % 3 + 1)*10;
	showPotential();
	cout << "레벨업 선물 : 물약(+"<< rNum <<"HP)을 받았습니다 !!" << endl;
	hp = hp + rNum;
	if (hp >= 100) {
		hp = 100;
	}
	Character::setHp(hp);
	myHp(hp);
	level++;
	cout << "\n☆☆☆☆☆ LEVEL UP !!! ☆☆☆☆☆ " << endl;
	cout << "레벨 : " << level << endl;
	Character::setLevel(level);
}

// 몬스터 공격 효과 함수 - 총
void attackGun() {
	cout << "C ▶▶▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▶▶▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▶▶▷▷▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▶▶▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▶▶▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▶▶ M" << endl;
}

// 몬스터 공격 효과 함수 - 칼
void attackKnife() {
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▶▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▷▶▶▶▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▶▶▶▶▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▶▶▶▶▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▶▶▷▷▶▶▶▶▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▶▶▶▶▶▶▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▶▶▶▶▶▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▶▶▶▶▶▶▶▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▶▶▶▶▷▶▶▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▶▶▷▷▷▶▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷ M" << endl;
}

// 몬스터 등장 효과
void showMonster() {
	cout << endl;
	cout << endl;
	cout << " ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇ " << endl;
	cout << " ◇◇◇◇◇◇◇◇◈◇◇◇◈◇◇◇◇◇◇◇◇ " << endl;
	cout << " ◇◇◇◇◇◇◇◈◈◈◈◈◈◈◇◇◇◇◇◇◇ " << endl;
	cout << " ◇◇◇◇◇◇◈◇◇◇◇◇◇◇◈◇◇◇◇◇◇ " << endl;
	cout << " ◇◇◇◇◇◈◈◇◇◇◇◇◇◇◈◈◇◇◇◇◇ " << endl;
	cout << " ◇◇◇◇◇◈◇◇◐◇◇◇◑◇◇◈◇◇◇◇◇ " << endl;
	cout << " ◇◇◇◇◇◈◇◇◇◇◇◇◇◇◇◈◇◇◇◇◇ " << endl;
	cout << " ◇◇◇◇◈◇◇◇◇▣▣▣◇◇◇◇◈◇◇◇◇ " << endl;
	cout << " ◇◇◇◈◇◇◇◇◇◇◇◇◇◇◇◇◇◈◇◇◇ " << endl;
	cout << " ◇◇◇◈◈◈◈◈◈◈◇◈◈◈◈◈◈◈◇◇◇ " << endl;
	cout << " ◇◇◇◇◇◈◈◈◇◈◈◈◇◈◈◈◇◇◇◇◇ " << endl;
	cout << " ◇◇◈◇◈◈◈◇◇◇◇◇◇◇◈◈◈◇◈◇◇ " << endl;
	cout << " ◇◇◇◈◈◈◇◇◇◇◇◇◇◇◇◈◈◈◇◇◇ " << endl;
	cout << " ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇ " << endl;
}


//콘솔 출력색상 설정.
void textcolor(int foreground, int background){
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void youDie() {
	textcolor(RED, BLACK);
	cout << "○○○○○○○○○○○○○○○○○○○○○○○○○" << endl;
	cout << "○○●○○●○○○●●○○○●○○●○○○○○○○" << endl;
	cout << "○○●○○●○○●○○●○○●○○●○○○○○○○" << endl;
	cout << "○○○●●○○○●○○●○○●○○●○○○○○○○" << endl;
	cout << "○○○●●○○○●○○●○○●○○●○○○○○○○" << endl;
	cout << "○○○●●○○○○●●○○○○●●○○○○○○○○" << endl;
	cout << "○○○○○○○○○○○○○○○○○○○○○○○○○" << endl;
	cout << "○○○○○○●●○○○●●●○●●●○●●○○○○" << endl;
	cout << "○○○○○○●○●○○○●○○●○○○●○●○○○" << endl;
	cout << "○○○○○○●○○●○○●○○●●●○●○○●○○" << endl;
	cout << "○○○○○○●○●○○○●○○●○○○●○●○○○" << endl;
	cout << "○○○○○○●●○○○●●●○●●●○●●○○○○" << endl;
	cout << "○○○○○○○○○○○○○○○○○○○○○○○○○" << endl;
	textcolor(LIGHTGRAY, BLACK);
}


//물약
void showPotential() {
	textcolor(BLUE, BLACK);
	cout << "○○○○○○○○○○○○○○○○○○○○○○" << endl;
	cout << "○○○○○○○●●●●●●●●○○○○○○○" << endl;
	cout << "○○○○○○○●○○○○○○●○○○○○○○" << endl;
	cout << "○○○○○○○●●●●●●●●○○○○○○○" << endl;
	cout << "○○○○○○○○●○○○○●○○○○○○○○" << endl;
	cout << "○○○○○○○○●○○○○●○○○○○○○○" << endl;
	cout << "○○○○○●●●○○○○○○●●●○○○○○" << endl;
	cout << "○○○○●○○○○○○○○○○○○●○○○○" << endl;
	cout << "○○○●●●●●●●●●●●●●●●●○○○" << endl;
	cout << "○○○●●●●●●●●●●●●●●●●○○○" << endl;
	cout << "○○○●●●●●●●●●●●●●●●●○○○" << endl;
	cout << "○○○●●●●●●●●●●●●●●●●○○○" << endl;
	cout << "○○○●●●●●●●●●●●●●●●●○○○" << endl;
	cout << "○○○○●●●●●●●●●●●●●●○○○○" << endl;
	cout << "○○○○○○○○○○○○○○○○○○○○○○" << endl;
	textcolor(LIGHTGRAY, BLACK);
}

void myHp(int hp) {
	int yHp, nHp;
	cout << "  현재 나의 HP :";
	yHp = hp / 10;
	nHp = 10 - yHp;
	for (int i = 0; i < yHp; i++) {
		cout << "■";
	}
	for (int j = 0; j < nHp; j++) {
		cout << "□";
	}
	cout << hp << "%" << endl;
	cout << endl;
}