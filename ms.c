#include<iostream>
using namespace std;
struct node{
	int row,col;
	node *next;
}*head,*tail;
static char a[8][8];
int dr,dc;
void display();
void push(int aa,int b){
	if(a[aa][b]=='#'){
		int c=0;
	}		
	else if(a[aa][b]==' '||a[aa][b]=='S'){
		a[aa][b]='#';
		node *new1=new node;
		new1->row=aa;
		new1->col=b;
		new1->next=head;
		head=new1;
		cout<<aa<<" "<<b<<endl;
	}
}
void pop(){
	a[head->row][head->col]='*';
	head=head->next;
}
void functionstack(){
	int sr=1,sc=1r=sr,pc=sc;
	push(sr,sc);
	while(a[dr][dc]!='$'){
		pr=head->row;
		pc=head->col;
		if(a[pr][pc+1]=='D'){
			a[pr][pc+1]='$';
			break;	
		}
		if(a[pr][pc+1]==' '&&pc+1<7){
			push(pr,pc+1);
		}
		if(a[pr+1][pc]=='D'){
			a[pr+1][pc]='$';
			break;	
		}
		if(a[pr+1][pc]==' '&&pr+1<7){
			push(pr+1,pc);
		}
		if(a[pr][pc-1]=='D'){
			a[pr][pc-1]='$';
			break;	
		}
		if(a[pr][pc-1]==' '&&pc-1>0){
			push(pr,pc-1);
		}
		if(a[pr-1][pc]=='D'){
			a[pr-1][pc]='$';
			break;	
		}
		if(a[pr-1][pc]==' '&&pr-1>0){
			push(pr-1,pc);
		}		
		pop();
		display();
	}
	display();	
}
void dest(){
	cout<<"Enter destination Coordinates"<<endl;
	cin>>dr>>dc;
	if(dr<=7&&dc<=7&&dr>0&&dc>0)	
		a[dr][dc]='D';
	else dest();
}
void fun(){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(i==0||i==7||j==0||j==7)
				a[i][j]='|';
			else a[i][j]=' ';			
		}			
	}
	a[2][2]='1';
	a[2][3]='1';
	a[2][4]='1';
	a[3][1]='1';
	a[3][3]='1';
	a[4][1]='1';
	a[4][3]='1';
	a[4][5]='1';
	a[4][6]='1';
	a[5][2]='1';
	a[6][1]='1';
	a[6][3]='1';
	a[6][4]='1';
	a[1][1]='S';
	dest();
}
void display(){
	//system("CLS");
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	fun();
	display();
	functionstack();
	return 0;	
}
