#include <iostream>
#include <string>
#include <vector>
#define MIN 8000
using namespace std;

class delivery { //�⺻Ŭ���� : �⺻ ������
protected:
	char dis[20]; //����
	int total; //��޷� ������ �ݾ�
	int fee; //��޷�
public:
	delivery() {} //������
	int setprice() {
		int price;
		price = fee + total;
		return price;
	}
	virtual int setpay(char dis[20], int total) {
		strcmp(dis, this->dis);
		this->total = total;
		int price = setprice();
		cout << "��� ������ ���� ��޷ᰡ �ٸ��� �ΰ��˴ϴ�. " << endl;
		return price;
	}
};

class A : public delivery { //����
public:
	virtual int setpay(char dis[20], int total) {
		fee = 1000;

		strcmp(dis, this->dis);
		this->total = total;

		int price = setprice();
		cout << "�ش� ����(" << dis << ")�� ��޷ᰡ 1000�� �߰��˴ϴ�." << endl;
		cout << "�� ���� �ݾ� : " << price << endl;
		return price;
	}
};

class B : public delivery { //������
public:
	virtual int setpay(char dis[20], int total) {
		fee = 2000;

		strcmp(dis, this->dis);
		this->total = total;

		int price = setprice();
		cout << "�ش� ����(" << dis << ")�� ��޷ᰡ 2000�� �߰��˴ϴ�." << endl;
		cout << "�� ���� �ݾ� : " << price << endl;
		return price;
	}
};

class C : public delivery { //�õ�
public:
	virtual int setpay(char dis[20], int total) {
		fee = 3000;

		strcmp(dis, this->dis);
		this->total = total;

		int price = setprice();
		cout << "�ش� ����(" << dis << ")�� ��޷ᰡ 3000�� �߰��˴ϴ�." << endl;
		cout << "�� ���� �ݾ� : " << price << endl;
		return price;
	}
};

class others : public delivery { //��� �� ����
public:
	virtual int setpay(char dis[20], int total) {
		strcmp(dis, this->dis);
		this->total = total;
		cout << "������ �ʹ� �־� �ֹ��� �������� �ʾҽ��ϴ�." << endl;
		return 0;
	}
};
void order(void) {
	cout << "*********************************************" << endl;
	cout << "   menu         price   " << endl << endl << "1.����������   3000��" << endl << "2.¥�嶱����   4000��" << endl << "3.ũ��������   4000��";
	cout << endl << "4.����         3000��" << endl << "5.Ƣ��         2000��" << endl << "6.�ݶ�         1000��" << endl << "7.�ֹ��Ϸ�" << endl;
	cout << "*********************************************" << endl;
	cout << endl << "�޴��� �Է��ϼ��� (�ּ��ֹ��ݾ� 8000��):: ";
}

int main()
{
	vector<int> v;
	vector<int> vc;
	int menu, sum1 = 0, sum2 = 0, total = 0, cnt = 0;
	int price[7] = { 0, 3000, 4000, 4000, 3000, 2000, 1000 };

	order();
	while (1) {
		cin >> menu;
		if (menu == 7) break;
		v.push_back(menu);
	}
	for (int i = 0; i < v.size(); i++) {
		for (int t = 0; t < 127; t++) {
			if (t == v[i])
				sum1 += price[t];

		}
	}
	total = sum1;

	while (1) {
		if (sum1 < MIN) {
			cout << endl << "�ּ� �ֹ� �ݾ��� 8000���Դϴ�. �޴��� �߰��� �ּ���. ���� �ֹ� �ݾ��� "
				 << total << "��" << endl << endl;
			order();
			while (1) {
				cin >> menu;
				if (menu == 7) break;
				vc.push_back(menu);
			}
			for (int i = cnt; i < vc.size(); i++) {
				for (int t = 0; t < 127; t++) {
					if (t == vc[i])
						sum2 += price[t];
				}
			}
			total = sum1 + sum2;
			cnt++;
		}
		if (total >= MIN)
			break;
	}
	cout << endl << "���� �ֹ� �ݾ��� " << total << "���Դϴ�." << endl;
	cout << endl << "�ּҸ� �Է��ϼ��� : ";
	string address; 
	cin.ignore(); //ǥ�� �Է� ���ۿ� ���๮��(\n)�� �����ֱ� ������ ���۸� ����ش�.
	getline(cin, address);

	char home[20] = { 0 };
	for (int i = 0; ; i++)
	{
		if (address[i] == ' ')
			break;
		else if (address[i] != ' ')
			home[i] = address[i];
	}

	int money;
	if (!strcmp(home, "����")) {
		delivery* pdelivery = new A();
		money = pdelivery->setpay(home, total);
		delete pdelivery;
	}
	else if (!strcmp(home, "������")) {
		delivery* pdelivery = new B();
		money = pdelivery->setpay(home, total);
		delete pdelivery;
	}
	else if (!strcmp(home, "�õ�")) {
		delivery* pdelivery = new C();
		money = pdelivery->setpay(home, total);
		delete pdelivery;
	}
	else {
		delivery* pdelivery = new others();
		money = pdelivery->setpay(home, total);
		delete pdelivery;
		return 0;
	}

	cout << endl << "------------------------------------------------------------------------" << endl << endl;
	cout << "�ּҴ� " << address << ", �� �ֹ� �ݾ��� " << money << "�� �Դϴ�!" << endl << "�� ������ �����Ͻðڽ��ϱ�?(Y/N)";
	char c;
	cin >> c;
	cout << endl;
	if (c == 'N') {
		cout << "�ֹ��� ����մϴ�. " << endl;
		return 0;
	}
	else if (c == 'Y')
		cout << "���� �������� �Ѿ�ϴ�. ��ø� ��ٷ� �ּ���." << endl << endl;
}