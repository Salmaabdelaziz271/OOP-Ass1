#include"Header.h"
string addition(string num, string num2);
int indicateSign(string num, int& st);
int greaterThan(string n1, string n2);
string subtraction(string num1, string num2);
//cases:
//both positive(num1-num2)//num1 negative(-num1-num2)
//both negative(-num1-(-num2))=num2-num1 //num2 negative(num1-(-num2)) = num1 + num2  
BigDecimalInt BigDecimalInt :: operator-(BigDecimalInt anotherDec) {
	string num1 = num,result, num2 = anotherDec.getStr();//num1-num2
	int st1 = 0, st2 = 0;
	//the following 3 steps are for  removing sign
	indicateSign(num1, st1); indicateSign(num2, st2);
	num1 = num1.substr(st1, num1.size());
	num2 = num2.substr(st2, num2.size());

	if (indicateSign(num1, st1) && indicateSign(anotherDec.getStr(), st2)) {
		//both positive  //num1-num2
		if ((num1.size() == num2.size())&&(num1==num2))
			result = "0";
		else if (greaterThan(num1, num2)) { //num1>num2
			result = subtraction(num1, num2);
		}
		else {//num2>num1
			result = "-";
			result += subtraction(num2, num1);
		}
	}
	else if (indicateSign(num1, st1) && (!indicateSign(anotherDec.getStr(), st2))) {
		//num1+num2 //num2 is negative, so subtraction has converted to addition 
		result = addition(num1, num2);
	}
	else if ((!indicateSign(num1, st2))&& indicateSign(anotherDec.getStr(), st1)) {//-num1-num2
        //num1 is negative, so subtraction has converted to addition of two negative numbers
		result = "-";
		result += addition(num1, num2);
	}
	else if ((!indicateSign(num1, st2)) && (!indicateSign(anotherDec.getStr(), st2))) {
		//both negative num2 - num1
		if ((num1.size() == num2.size())&&(num1==num2))
			result = "0";
		else if (greaterThan(num2, num1)) { //num2>num1
			result = subtraction(num2, num1);
		}
		else {//num1>num2
			result = "-";
			result += subtraction(num1, num2);
		}
	}
	BigDecimalInt sub(result);
	return sub;
}

bool BigDecimalInt :: operator< (BigDecimalInt anotherDec) {
	string num2 = anotherDec.getStr(),num1=num;
	int st1 = 0, st2 = 0;
	//if(num < num2) 
	if ((!indicateSign(num, st1)) && indicateSign(num2, st2))
		return 1;
	else if ((!indicateSign(num2, st2)) && indicateSign(num, st1))
		return 0;
	//the following 2 steps are for  removing sign
	num1 = num1.substr(st1, num1.size());
	num2 = num2.substr(st2, num2.size());
	if (indicateSign(num, st1) && indicateSign(anotherDec.getStr(), st2)) {
		if (greaterThan(num2, num1))//num2 > num1
			return 1;
		else
			return 0;
	}
	else if ((!indicateSign(num, st1)) && (!indicateSign(anotherDec.getStr(), st2))) {
		if (greaterThan(num2, num1))//num2 > num1
			return 0;
		else
			return 1;
	}
	return 0;// equal
}





