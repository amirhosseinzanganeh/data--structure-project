#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

const int Maxsizest = 10;
const int maxtooldata = 40;

struct stack
{
	int top;
	string arr[Maxsizest];
}st;

void createstack()
{
	st.top = -1;
}

void push(string value)
{
	if (st.top >= Maxsizest - 1)
	{
		cout << "stack over flow" << endl;

	}
	else
	{
		st.arr[++st.top] = value;
	}
}
string pop()
{
	string a = "";
	if (st.top < 0)
	{
		cout << "stack is empty" << endl;
		return a;
	}
	else
	{
		return st.arr[st.top--];
	}
}
int isEmpty()
{
	return st.top == -1;
}

int isOperator(char ch)
{
	return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


string PostfixToInfix(string postfix)
{
	createstack();
	string prantezbaz = "(";
	string parantezbaste = ")";
	for (int i = postfix.length() - 1; i >= 0; i--)
	{
		char ch = postfix[i];
		if (isOperator(ch))
		{
			string operand1 = pop();
			string operand2 = pop();
			string infix = "";
			infix = prantezbaz + operand1 + ch + operand2 + parantezbaste;
			push(infix);
		}
		else
		{
			string aa = "";
			aa += ch;
			push(aa);
		}
	}
	return pop();
}

int main() {
	system("cls");
	string postfix = "";
	cout << "Enter a postfix expression: ";
	cin >> postfix;

	string infix = PostfixToInfix(postfix);
	cout << "Infix expression: " << infix << endl;
	_getch();
	return 0;
}