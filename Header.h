#include <iostream>
#include<iomanip>
#include <sstream>
#include<vector>
using namespace std;
class BigDecimalInt {
	string num;
public:
	BigDecimalInt(string decStr = "") {
		num = decStr;
	}
	BigDecimalInt(int decInt) {
		num = to_string(decInt);
	}
	BigDecimalInt operator+(BigDecimalInt anotherDec);
	BigDecimalInt operator-(BigDecimalInt anotherDec);
	bool operator< (BigDecimalInt anotherDec);
	bool operator> (BigDecimalInt anotherDec);
	bool operator==(BigDecimalInt anotherDec);
	BigDecimalInt operator= (BigDecimalInt anotherDec);
	friend ostream& operator << (ostream& out, BigDecimalInt b);
	string getStr() { return num; }
};





