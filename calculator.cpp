#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
using namespace std;

int main() {
	stack<int> MyStack;
	cout << "Please enter an expression: " << endl;
	int c = getchar();
	string number = "";
	while (c != '=') {
		switch (c) {
		case'+': {
			MyStack.push(stoi(number));
			number = "";
			int fst = MyStack.top();
			MyStack.pop();
			int snd = MyStack.top();
			MyStack.pop();
			MyStack.push(fst + snd);
			break;
		}
		case'-': {
			MyStack.push(stoi(number));
			number = "";
			int fst = MyStack.top();
			MyStack.pop();
			int snd = MyStack.top();
			MyStack.pop();
			MyStack.push(snd - fst);
			break;
		}
		case'/': {
			MyStack.push(stoi(number));
			number = "";
			int fst = MyStack.top();
			MyStack.pop();
			int snd = MyStack.top();
			MyStack.pop();
			MyStack.push(snd / fst);
			break;
		}
		case '*': {
			MyStack.push(stoi(number));
			number = "";
			int fst = MyStack.top();
			MyStack.pop();
			int snd = MyStack.top();
			MyStack.pop();
			MyStack.push(snd * fst);
			break;
		}
		case ' ': {
			MyStack.push(stoi(number));
			number = "";
			break;
		}
		default: {
			number += c;
			break;
		}
		}
		c = getchar();

	}
	cout << MyStack.top() << endl;

};
