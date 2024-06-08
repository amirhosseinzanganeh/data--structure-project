#include<iostream>
#include<conio.h>
using namespace std;

struct mylink
{
	int id;
	struct mylink* node;
}*startlink,*endlink = NULL , *back ;

int st[10], top = -1;
int q[10], f = -1, r = -1;

void inputData(struct mylink* a)
{
	cout << "\nplease enter number = ";
	cin >> a->id;
}

void addnode(struct mylink* a)
{

	if (endlink == NULL)//nothing exist in link list
	{
		startlink = endlink = a;
		endlink->node = startlink;
		
	}
	else
	{
		a->node = startlink;  // اشاره کردن ند جدید به شروع لیست
		endlink->node = a;    // لینک دادن انتهای لیست به ند جدید
		endlink = a;
		
	}
}

void printList()
{
	cout << " the list is : \n ";
	struct mylink* a;
	a = startlink->node;
	if (endlink == NULL)
	{
		cout << "No Data ...";
		return;
	}
	else
	{
		do
		{
			cout << a->id << " -> ";
			a = a->node;
		} while (a != startlink->node);
	}
}
bool checkaval(int a)
{
	int i = 0;
	bool st = true;
	for (i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			st = false;
		}
	}
	return st;
}
void deleteaval()
{
	struct mylink* a, * bk;
	a = bk = startlink->node;
	if (endlink == NULL)
	{
		cout << "\ndata is not exist";
		return;
	}
	else
	{
		do 
		{
			if (checkaval(a->id))
			{
				cout << a->id << "has been deleted ...";
				if (bk == startlink->node)
				{
					startlink->node = a->node;
				}
				else
				{
					bk->node = a->node;
					delete(a);
					a = bk->node;// zamani ke yek link bein 2 hast va adad aval ro bekhaim hazf konim
				}
			}
			bk = a;//address bk yeki ghabl a hast
			a = a->node;//a=a.next
		
		
		} while (a != startlink->node);
	}
}

int menu()
{
	cout << "\n 1-create link list";
	cout << "\n 2-print list";
	cout << "\n 3-check and delete aval";
	cout << "\n 4-push stack";
	cout << "\n 5-pop stack";
	cout << "\n 6-add Queue";
	cout << "\n 7-dell Queue";
	cout << "\n 8-print stack";
	cout << "\n 9-print Queue";
	cout << "\n 10-exit";
	cout << "\n please choose:";
	int i = 0; 
	cin >> i;
	return i;
}
void createlist()
{
	struct mylink* a;
	endlink = startlink = NULL;
	startlink = new(struct mylink);
	a = new(struct mylink);
	int i = 0;
	cout << "how many link do you want exist ? ";
	cin >> i;
	for (int s = 0; s < i; s++)
	{
		if (s == 0)
		{
			startlink->id = -1;
			startlink->node = a;
		}
		inputData(a);
		addnode(a);
	}
}
int pop() {
	if (top == -1)cout << "\n stack is empty";
	else return st[top--];
}
void push() {
	int a;
	cout << "what is your number do you want push in stack = ";
	cin >> a;
	if (top == 9) cout << "\nstack is full..";
	else st[++top] = a;
}
int del() {
	if (f == r) cout << "\n Q is empty..";
	else { f = (f + 1) % 9; return q[f]; }
}
void add() {
	int a;
	cout << "what is your number do you want push in stack = ";
	cin >> a;
	if (f == (r + 1) % 9) cout << "\n Q is full...";
	else { r = (r + 1) % 9; q[r] = a; }
}
void printstack()
{
	for (int i = top; i > -1; i--)
	{
		cout << st[i] << endl;
	}
}
void printq()
{
	cout << "Q = ";
	for (int i = f; i <= r; i++)
	{
		cout << q[i] << "-";
	}
}
void main() {
	while (1) {
		switch (menu()) {
		case 1:createlist(); break;
		case 2:printList(); break;
		case 3:deleteaval(); break;
		case 4:push(); break;
		case 5:pop(); break;
		case 6:add(); break;
		case 7:del(); break;
		case 8:printstack(); break;
		case 9:printq(); break;
		case 10:return;
		}
	}

}