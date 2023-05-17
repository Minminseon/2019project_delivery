#include <iostream>
#include <string>
#include <vector>
#define MIN 8000
using namespace std;

class delivery { //기본클래스 : 기본 설정값
protected:
	char dis[20]; //동네
	int total; //배달료 미포함 금액
	int fee; //배달료
public:
	delivery() {} //생성자
	int setprice() {
		int price;
		price = fee + total;
		return price;
	}
	virtual int setpay(char dis[20], int total) {
		strcmp(dis, this->dis);
		this->total = total;
		int price = setprice();
		cout << "배달 지역에 따라 배달료가 다르게 부과됩니다. " << endl;
		return price;
	}
};

class A : public delivery { //덕명동
public:
	virtual int setpay(char dis[20], int total) {
		fee = 1000;

		strcmp(dis, this->dis);
		this->total = total;

		int price = setprice();
		cout << "해당 지역(" << dis << ")은 배달료가 1000원 추가됩니다." << endl;
		cout << "총 결제 금액 : " << price << endl;
		return price;
	}
};

class B : public delivery { //노은동
public:
	virtual int setpay(char dis[20], int total) {
		fee = 2000;

		strcmp(dis, this->dis);
		this->total = total;

		int price = setprice();
		cout << "해당 지역(" << dis << ")은 배달료가 2000원 추가됩니다." << endl;
		cout << "총 결제 금액 : " << price << endl;
		return price;
	}
};

class C : public delivery { //궁동
public:
	virtual int setpay(char dis[20], int total) {
		fee = 3000;

		strcmp(dis, this->dis);
		this->total = total;

		int price = setprice();
		cout << "해당 지역(" << dis << ")은 배달료가 3000원 추가됩니다." << endl;
		cout << "총 결제 금액 : " << price << endl;
		return price;
	}
};

class others : public delivery { //배달 외 지역
public:
	virtual int setpay(char dis[20], int total) {
		strcmp(dis, this->dis);
		this->total = total;
		cout << "지역이 너무 멀어 주문이 접수되지 않았습니다." << endl;
		return 0;
	}
};
void order(void) {
	cout << "*********************************************" << endl;
	cout << "   menu         price   " << endl << endl << "1.빨간떡볶이   3000원" << endl << "2.짜장떡볶이   4000원" << endl << "3.크림떡볶이   4000원";
	cout << endl << "4.순대         3000원" << endl << "5.튀김         2000원" << endl << "6.콜라         1000원" << endl << "7.주문완료" << endl;
	cout << "*********************************************" << endl;
	cout << endl << "메뉴를 입력하세요 (최소주문금액 8000원):: ";
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
			cout << endl << "최소 주문 금액은 8000원입니다. 메뉴를 추가해 주세요. 현재 주문 금액은 "
				 << total << "원" << endl << endl;
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
	cout << endl << "현재 주문 금액은 " << total << "원입니다." << endl;
	cout << endl << "주소를 입력하세요 : ";
	string address; 
	cin.ignore(); //표준 입력 버퍼에 개행문자(\n)이 남아있기 때문에 버퍼를 비워준다.
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
	if (!strcmp(home, "덕명동")) {
		delivery* pdelivery = new A();
		money = pdelivery->setpay(home, total);
		delete pdelivery;
	}
	else if (!strcmp(home, "노은동")) {
		delivery* pdelivery = new B();
		money = pdelivery->setpay(home, total);
		delete pdelivery;
	}
	else if (!strcmp(home, "궁동")) {
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
	cout << "주소는 " << address << ", 총 주문 금액은 " << money << "원 입니다!" << endl << "★ 결제를 진행하시겠습니까?(Y/N)";
	char c;
	cin >> c;
	cout << endl;
	if (c == 'N') {
		cout << "주문을 취소합니다. " << endl;
		return 0;
	}
	else if (c == 'Y')
		cout << "결제 페이지로 넘어갑니다. 잠시만 기다려 주세요." << endl << endl;
}