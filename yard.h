#pragma once
#include <iostream>
#include <vector>
using namespace std;


void swap(string& stack) {
	for (int i = 0; i < stack.size() / 2; i++) {
		char temp = stack[i];
		stack[i] = stack[stack.size() - i - 1];
		stack[stack.size() - i - 1] = temp;
	}
}


bool isSymbol(char symbol) {
	if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '(' || symbol == ')') return true;
	return false;
}

int getValue(char symbol) {

	switch (symbol) {
		case '+': return 0; break;
		case '-': return 0; break;
		case '*': return 1; break;
		case '/': return 1; break;
		case '(': return 3; break;
		case ')': return 3; break;

	}
}

void resetStack(string& stack) {
	string temp = stack;
	stack.clear();

	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == '&') continue;
		stack += temp[i];
	}

}


void pushStack(char symbol, string& stack, string& output) {
	int stackSize = stack.size();
	int symbolValue = getValue(symbol);

	if (stack.size() == 0) {
		stack += symbol;
	}


	/*else if (stack[stackSize - 1]) {
		stack += symbol;
	}*/

	else {

		for (int i = 0; i < stack.size(); i++) {
			int indexValue = getValue(stack[stack.size() - i - 1]);
			if (symbolValue <= indexValue) {

				output += stack[stack.size() - i - 1];
				stack[stack.size() - i - 1] = '&';
			}
		}
		resetStack(stack);
		stack += symbol;
	}
}


string shunt_yard(string expr) {

	string output;
	string stack;

	for (int i = 0; i < expr.size(); i++) {
		char iter = expr[i];
		if (isSymbol(iter)) {
			output += '&';
			pushStack(iter, stack, output);

		}
		else {
			output += iter;
		}
	}

	swap(stack);
	output += stack;
	return output;
}


//https://en.wikipedia.org/wiki/Shunting-yard_algorithm