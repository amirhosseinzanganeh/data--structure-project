#include <iostream.h>
#include <string.h>
#include <conio.h>
const int MAX_SIZE_ST = 10;
const int MAX_TOOL_DATA = 10;
struct Stack {
    int top;
    char arr[MAX_SIZE_ST][MAX_TOOL_DATA];
}st;

//create stack
void createStack() {
    st.top = -1;
}

//
void push( char* value) {
    if (st.top >= MAX_SIZE_ST - 1) {
	cout << "Stack overflow" << endl;
    } else {
	strcpy(st.arr[++st.top], value);
    }
}

//
char* pop() {
    if (st.top < 0) {
	cout << "Stack underflow" << endl;
	return "";
    } else {
	return st.arr[st.top--];
    }
}

//
int isEmpty() {
    return st.top == -1;
}

//
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

//
char* postfixToInfix(char* postfix) {
    createStack();
    char* pbaz="(";
    char* pbaste=")";
    for (int i = 0; i < strlen(postfix); i++) {
	char* ch ="";ch[0]= postfix[i];ch[1]='\0';
	if (isOperator(ch[0])) {
	    char* operand2 = pop();
	    char* operand1 = pop();
	    char* infix ="";strcat(infix, pbaz);strcat(infix, operand1);
	    //infix[srtlen(infix)]= ch;infix[srtlen(infix)+1]= '\0';
	    strcat(infix,ch);
	    strcat(infix, operand2);strcat(infix, pbaste);
	    push( infix);
	} else {
	    push( ch);
	}
    }

    return pop();
}

int main() {
    clrscr();
    char* postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    char* infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
    getch();
    return 0;
}
