#include"Header.h"
string addition(string num, string num2);
int indicateSign(string num,int& st);
int greaterThan(string n1, string n2);
string subtraction(string num1, string num2);
BigDecimalInt BigDecimalInt ::operator+(BigDecimalInt anotherDec) {
	string num1 = num, num2 = anotherDec.getStr();
	string reslt;
	int st1=0, st2=0;
	//the following 3 steps are for  removing sign
	indicateSign(num1, st1); indicateSign(num2, st2);
	num1 = num1.substr(st1, num1.size());
	num2 = num2.substr(st2, num2.size());

	if (indicateSign(num1,st1)&&indicateSign(anotherDec.getStr(),st2)) {//both positive
		reslt = addition(num1, num2);
	}
	else if ((!indicateSign(num1, st1))&&(!indicateSign(anotherDec.getStr(),st2))) {
		//both negative //  -num1 - num2
		reslt += "-";
		reslt += addition(num1, num2);
	}
	else if ((!indicateSign(anotherDec.getStr(), st2))&& indicateSign(num1, st1)) {
		//num2 is negative  //num1-num2
		if (num1 == num2) {
			reslt = "0";
		}
		else if (greaterThan(num1, num2)) {//num1>num2
			reslt = subtraction(num1, num2);
		}
		else {//num2>num1
			reslt += "-";
			reslt += subtraction(num2, num1);
		}
	}
	else if ((!indicateSign(num1, st1)) && indicateSign(anotherDec.getStr(), st2)) {
		//num1 is negative //num2-num1
		if (num1 == num2) {
			reslt = "0";
		}
		else if (greaterThan(num2, num1)) {//num2>num1
			reslt = subtraction(num2, num1);
		}
		else {//num1>num2
			reslt += "-"; 
			reslt += subtraction(num1, num2);
		}
	}
    BigDecimalInt sum(reslt);
	return sum;
}
//this function deal with two positive numbers
string addition(string num, string num2) {
	string result;
	int sz;
	if (num2.size() < num.size()) {
		result = num;
		sz = (num.size() - num2.size());
		while (sz--)
			num2.insert(num2.begin(), '0');
	}
	else {
		result = num2;
		sz = (num2.size() - num.size());
		while (sz--)
			num.insert(num.begin(), '0');
	}
	int cary = 0;
	for (int i = num.size() - 1; i > -1; i--) {
		int sum = ((num[i] - '0') + (num2[i] - '0'));
		if (sum > 9) {
			if (cary) sum++;
			sum -= 10;
			result[i] = char(sum + '0');
			cary = 1; i--;
			if (i >= 0) sum = ((num[i] - '0') + (num2[i] - '0'));
		}
		if (cary) {
			if (i < 0) {
				result.insert(result.begin(), '1');
			}
			else if ((sum + 1) <= 9) {
				sum++;
				result[i] = char(sum + '0');
				cary = 0;
			}
			else {
				sum -= 9;
				result[i] = char(sum + '0');
			}
		}
		else {
			result[i] = char(sum + '0');
		}
	}
	return result;
}

int indicateSign(string num,int& st) {
	int nNgsingn=0;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == '-') {
			nNgsingn++;
		}
		else if (num[i] == '+')continue;
		else {
			st = i;
			break;
		}
	}
	if (nNgsingn % 2 == 0) {//negative\n";
		return 1;
	}
	return 0;
}
int greaterThan(string n1, string n2) {
	if (n1.size() > n2.size())
		return 1;
	else if (n2.size() > n1.size())
		return 0;
	else {
		return(n1 > n2);
	}
}

string subtraction(string num1, string num2) {
	if (num2.size() < num1.size()) {
		int sz = num1.size() - num2.size();
		while (sz--) {
			num2.insert(num2.begin(), '0');
		}
	}
	string result = num1;
	for (int i = num1.size() - 1; i > -1; i--) {
		int sub = (num1[i] - '0') - (num2[i] - '0');
		if (sub > -1) {
			result[i] = char(sub+'0');
		}
		else if (i > 0 && (num1[i - 1]-'0') > 0) {//100-048  //100-040
			sub += 10;
			result[i] = char(sub+'0');
			num1[i - 1]--;
		}
		else {
			sub += 10;
			result[i] = char(sub + '0');
			num1[i - 1] += 9;
			for (int j = i - 2; j > -1; j--) {
				if ((num1[j]-'0') > 0) {
					num1[j]--;
					break;
				}
				else {
					num1[j] += 9;
				}
			}
		}
	}
	while (*result.begin() == '0')
	{
		result.erase(result.begin());
	}
	return result;
}







