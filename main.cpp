#include"Header.h"
int main() {
	//bug in minus
	BigDecimalInt num1("123456789012345678901234567890");
	BigDecimalInt num2("+113456789011345678901134567890");
	BigDecimalInt num3("-200000000000000000000000000000");
	BigDecimalInt num4 = num2 - num1;
	cout << "num2 + num1 = " << num4.getStr() << endl;
	//cout << num1;
	BigDecimalInt num5("9"),num6("10");
	//cout << (num6 - num6);
	
}
