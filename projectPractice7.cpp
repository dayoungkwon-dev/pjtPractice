#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

// 프로젝트7. 클래스 종합 - 게임 만들기
using namespace std;

class Character {
public:
	static int hp;
	static int level;
	//static vector<Weapon*> weapons;
	static vector<string> weapons;
public:
	Character() {}

	//getter,setter
	void setHp(int chgHp) {
		hp = chgHp;
	}
	int getHp() {
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
		cout << "\n      ------ 총쏘기 -------     ( -10 HP )" << endl;
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
		cout << "\n      ------ 찌르기 -------     ( -5 HP )" << endl;
	}
};

class Monster {
public:
	static int mstHp;
	static string mstName;

public:
	Monster(){}

	void setMstHp(int chaLevel) {
		mstHp = chaLevel * 2 * 10;
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
void levelUp(int level);
void attackM();

int main() {
	Character c1;
	bool attacked = false;
	int action, weaponAcction;
	vector<Weapon*> weaponBasket;

	cout << "-------------------- 게임 시작 -------------------- " << endl;
	cout << "현재 hp : " << c1.hp << ", level : " << c1.level << endl;
	Monster m = Monster();
	m.setMstHp(c1.level);
	m.setMstName(c1.level);
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
		cout << "\n/////// 도전 몬스터 : " << Monster::mstName << " , hp : " << Monster::mstHp << " ////////" << endl;
		
		// 몬스터 만난지 10초 지나면 데미지.
		clock_t endTime = clock();
		if ((endTime - startTime) / CLOCKS_PER_SEC >= 10) {
			cout << "\n ----------- 몬스터 공격 ◐ㅁ◑ -----------" << endl;
			cout << "               피해량 : -" << 10 * c1.level << endl;
			c1.getDamage(10 * c1.level);
			cout << "               현재 나의 HP : " << c1.hp << endl;
			cout << endl;
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
						attackM();
						gPower = pg->offensePower;
						m.getAttack(gPower);
						attacked = true;
					}
				}
				else if(pn) {
					int nPower = 0;
					if (action == 2) {
						pn->attack();
						attackM();
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
			cout << "----------------- 몬스터 처치 완료 !! --------------------" << endl;
			levelUp(c1.level);
			break;
		}
	}

	for (Weapon* weapon : weaponBasket) {
		delete weapon;
	}
}

// 레벨업 함수
void levelUp(int level) {
	level++;
	cout << "☆☆☆☆☆ LEVEL UP !!! ☆☆☆☆☆ " << endl;
	cout << "레벨 : " << level << endl;
	Character::setLevel(level);
}

// 몬스터 공격 효과 함수
void attackM() {
	cout << "C ▶▶▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▶▶▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▶▶▷▷▷▷▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▶▶▷▷▷▷▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▶▶▷▷▷▷ M" << endl;
	cout << "C ▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▷▶▶ M" << endl;
}