#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "yard.h"
using namespace std;



int calc(char symbol, string number1, string number2) {
	int num1 = stoi(number1);
	int num2 = stoi(number2);
	
	int result;
	switch (symbol) {
		case '+': 
			result = num1 + num2; 
		break;
		case '-': 
			result = num1 - num2; 
		break;
		case '*': 
			result =  num1 * num2;
		break;
		case '/': 
			result = num2 / num1; 
		break;
	}
	return result;
}

string initNewExpr(string& expr) {
	string temp;

	bool bFlag = false;
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '$') {
			if (bFlag) {
				bFlag = false;
				temp += '&';
			}
			continue;
		}
		temp += expr[i];
		bFlag = true;
	}
	return temp;
}

void getTwoLastNumbers(string& expr, int i, string* tab) {
	int j = 0;
	if (expr[i] == '&') {
		expr[i] = '$';
		i--;
	}
	
	string temp;
	while (i >= 0) {
		if (j==2) break;

		if (expr[i] == '&') {
			expr[i] = '$';
			swap(temp);
			tab[j] = temp;
			temp.clear();
			j++;
		}
		else {
			temp += expr[i];
			expr[i] = '$';
		}
		i--;
	}
	if (temp.size() != 0) {
		swap(temp);
		tab[j] = temp;
	}

}

int getResult(string expr) {

	string temp;
	for (int i = 0; i < expr.size()-1; i++) {
		temp += expr[i];
	}
	return stoi(temp);
}

int compute(string expr) {

	for (int i = 0; i < expr.size(); i++) {
		if (isSymbol(expr[i])) {
			string nums[2];
			getTwoLastNumbers(expr, i - 1, nums);
			string result = to_string(calc(expr[i], nums[0], nums[1]));

			expr[i] = '$';
			expr = result + '&' + initNewExpr(expr);
			i = 0;
		}
	}

	int result = getResult(expr);
	return result;
}


int parseShunt(string expr) {

	vector<string> numbers;
	vector<char> symbols;

	int result;
	result = compute(expr);
	return result;
}





