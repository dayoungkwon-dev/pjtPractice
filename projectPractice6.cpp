#include <iostream>

// ������Ʈ6. Ŭ���� ����(���� �����)

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
		cout << "��� : " << result << endl;
	}
};

//���� Ŭ����
class Addition : public Calculator {

public:
	void getResult() {
		result = firstNum + nextNum;
		cout << "��� : " << result << endl;
	}
};

//���� Ŭ����
class Subtraction : public Calculator {

public:
	void getResult() {
		result = firstNum - nextNum;
		cout << "��� : " << result << endl;
	}
};

// ���� Ŭ����
class Multiplication : public Calculator {

public:
	void getResult() {
		result = firstNum * nextNum;
		cout << "��� : " << result << endl;
	}
};

// ������ Ŭ����
class Division : public Calculator {

public:
	void getResult() {
		result = firstNum / nextNum;
		cout << "��� : " << result << endl;
	}
};

double Calculator::result = 0;
double Calculator::firstNum = 0;
double Calculator::nextNum = 0;
void calculate(double n1, double n2, string ope);


int main() {
	string action, ope;
	double num1, num2;

	cout << "���ڸ� �Է����ּ��� : ";
	cin >> num1;
	cout << "�����ڸ� �Է����ּ��� : ";
	cin >> ope;
	cout << "���ڸ� �Է����ּ��� : ";
	cin >> num2;
	calculate(num1, num2, ope);

	while (1) {
		num1 = 0;
		num2 = 0;

		cout << "������ ��� �����Ͻðڽ��ϱ�? (Y:���, AC:�ʱ�ȭ, EXIT:����)";
		cin >> action;

		if (action == "Y") {
			// ����� ����� �̿��� �ļ� ���
			num1 = Calculator::result;
			cout << "�����ڸ� �Է����ּ��� : ";
			cin >> ope;
			cout << "���ڸ� �Է����ּ��� : ";
			cin >> num2;
		}
		else if (action == "AC") {
			// ���� ��� �ʱ�ȭ
			cout << "���ڸ� �Է����ּ��� : ";
			cin >> num1;
			cout << "�����ڸ� �Է����ּ��� : ";
			cin >> ope;
			cout << "���ڸ� �Է����ּ��� : ";
			cin >> num2;
		}
		else if (action == "EXIT") {
			// ����
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