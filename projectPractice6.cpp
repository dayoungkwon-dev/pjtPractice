#include <iostream>

// 프로젝트6. 클래스 복습(계산기 만들기)

using namespace std;

class Calculator {
public:
	static double firstNum, nextNum;
	string ope;
	static double result;
public:
	Calculator() {}

	// getter, setter
	static void setFirstNum(double num) {
		firstNum = num;
	}
	static double getFirstNum() {
		return firstNum;
	}
	static void setNextNum(double num) {
		nextNum = num;
	}
	static double getNextNum() {
		return nextNum;
	}

	virtual void getResult() {
		cout << "결과 : " << result << endl;
	}
};

//덧셈 클래스
class Addition : public Calculator {

public:
	void getResult() {
		result = firstNum + nextNum;
		cout << "결과 : " << result << endl;
	}
};

//뺄셈 클래스
class Subtraction : public Calculator {

public:
	void getResult() {
		result = firstNum - nextNum;
		cout << "결과 : " << result << endl;
	}
};

// 곱셈 클래스
class Multiplication : public Calculator {

public:
	void getResult() {
		result = firstNum * nextNum;
		cout << "결과 : " << result << endl;
	}
};

// 나눗셈 클래스
class Division : public Calculator {

public:
	void getResult() {
		result = firstNum / nextNum;
		cout << "결과 : " << result << endl;
	}
};

double Calculator::result = 0;
double Calculator::firstNum = 0;
double Calculator::nextNum = 0;
void calculate(double n1, double n2, string ope);


int main() {
	string action, ope;
	double num1, num2;

	cout << "숫자를 입력해주세요 : ";
	cin >> num1;
	cout << "연산자를 입력해주세요 : ";
	cin >> ope;
	cout << "숫자를 입력해주세요 : ";
	cin >> num2;
	calculate(num1, num2, ope);

	while (1) {
		num1 = 0;
		num2 = 0;

		cout << "연산을 계속 진행하시겠습니까? (Y:계속, AC:초기화, EXIT:종료)";
		cin >> action;

		if (action == "Y") {
			// 도출된 결과를 이용한 후속 계산
			num1 = Calculator::result;
			cout << "연산자를 입력해주세요 : ";
			cin >> ope;
			cout << "숫자를 입력해주세요 : ";
			cin >> num2;
		}
		else if (action == "AC") {
			// 이전 기록 초기화
			cout << "숫자를 입력해주세요 : ";
			cin >> num1;
			cout << "연산자를 입력해주세요 : ";
			cin >> ope;
			cout << "숫자를 입력해주세요 : ";
			cin >> num2;
		}
		else if (action == "EXIT") {
			// 종료
			break;
		}
		calculate(num1, num2, ope);
	}
}


void calculate(double n1, double n2, string ope) {
	Calculator* a = new Addition();
	Calculator* s = new Subtraction();
	Calculator* m = new Multiplication();
	Calculator* d = new Division();

	Calculator::setFirstNum(n1);
	Calculator::setNextNum(n2);

	cout << "--------------------------------------------" << endl;
	if (ope == "+") {
		a->getResult();
	}
	else if (ope == "-") {
		s->getResult();
	}
	else if (ope == "*") {
		m->getResult();
	}
	else if (ope == "/") {
		d->getResult();
	}
	cout << "--------------------------------------------" << endl;

	delete a, s, m, d;
}