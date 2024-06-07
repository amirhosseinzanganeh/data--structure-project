#include <iostream.h>
#include <conio.h>
struct mylink{
 int id;
 struct mylink *node;
}*startlink,*endlink=NULL;
int st[10],top=-1;
int q[10],f=-1,r=-1;
void inputdata(struct mylink *a){
 cout<<"\nplease enter data *****";
 cin>>a->id;
}
void addnode(struct mylink *a){
  if(endlink==NULL){
    endlink->node=a;
    endlink=a;
  }
  else{
   a->node=endlink->node;
   endlink->node=a;
  }
}
void printlist(){
  clrscr();
  cout<<" *****the list is*****\n";
  struct mylink *a;
  a=startlink->node;
  if(endlink==NULL){cout<<"No Data..";return;}else{
    do{
      cout<<a->id<<endl;
      a=a->node;
    }while(a!=startlink->node);
  }
  getch();
}
int checkaval(int a){
 int i=0,st=1;
 for(i=2;i<a;i++) if(a%i==0)st=0;
 return st;
}
void delaval(){
  clrscr();
  cout<<" *****Delete Aval*****\n";
  struct mylink *a,*bk;
  a=bk=startlink->node;
  if(endlink==NULL){cout<<"No Data..";return;}else{
    do{
      if(checkaval(a->id)){
	cout<<a->id<<" Has Been Deleted..";
	getch();
	if(bk==startlink->node)
	{startlink->node=a->node;}
	else
	 bk->node=a->node;
	 delete(a);
	 a=bk->node;
      }
      bk=a;
      a=a->node;
    }while(a!=startlink->node);
  }
}
int menu(){
  clrscr();
  cout<<"\n 1-create link list";
  cout<<"\n 2-print list";
  cout<<"\n 3-check aval";
  cout<<"\n 4-delete aval";
  cout<<"\n 5-push stack";
  cout<<"\n 6-pop stack";
  cout<<"\n 8-add Queue";
  cout<<"\n 9-dell Queue";
  cout<<"\n 10-exit";
  cout<<"\n please choose:";int i=0;cin>>i;
  return i;
}
void createlist(){
  struct mylink *a;
  endlink=startlink=NULL;
  startlink=new(struct mylink);
  a=new(struct mylink);
  startlink->id=-1;
  startlink->node=a;
  inputdata(a);
  addnode(a);
  a=new(struct mylink);
  inputdata(a);
  addnode(a);
  a=new(struct mylink);
  inputdata(a);
  addnode(a);

}
int pop(){
    if(top==-1)cout<<"\n stack is empty";
    else return st[top--];
}
void push(int a){
 if(top==9) cout<<"\nstack is full..";
  else st[++top]=a;
}
int del(){
  if(f==r) cout<<"\n Q is empty..";
  else {f=(f+1)%9;return q[f];}
}
void add(int a){
if(f==(r+1)%9) cout<<"\n Q is full...";
 else {r=(r+1)%9;q[r]=a;}
}
void main(){
 while(1){
  switch(menu()){
  case 1:createlist();break;
  case 2:printlist();break;
  case 3:delaval();break;
  case 4:delaval();break;
  case 10:return;
  }
 }
  getch();
}
