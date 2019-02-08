#include<iostream>
#include<stdlib.h>
using namespace std;
 struct node
  {
   int row,col;
   node *next;
  }*head,*tail;
 static char a[8][8];
 static char b[8][8];
 char ch;
 int dr,dc,sr,sc,pr1,pc1,life=3;
 int hs=0;
 void display();
 void gboard();
 void displayb();
 void push(int z,int b)
  {
   if(a[z][b]=='S')
    {
      node *new1=new node;
      new1->row=z;
      new1->col=b;
      new1->next=NULL;
     if(head==NULL)
      {			
	head=new1;
	tail=new1;
      }
    }			
  else if((a[z][b]==' ')&&a[z][b]!='#')
   {
     a[z][b]='#';
     node *new1=new node;
     new1->row=z;
     new1->col=b;
     new1->next=NULL;
     if(head==NULL)
      {			
	head=new1;
	tail=new1;
      }
    else
     {
      tail->next=new1;
      tail=new1;
     }
   }
}

 void pop()
  {
    if(a[head->row][head->col]=='S')
    int asd=0;
    else a[head->row][head->col]='*';
    head=head->next;
  }
 void path()                                      //Function to generate path at backend
  {
    int pr=sr,pc=sc;
    push(sr,sc);
    while(a[dr][dc]!='$')
     {
      pr=head->row;
      pc=head->col;
      if(a[pr][pc+1]=='D')
       {
	a[pr][pc+1]='$';
	break;	
       }
      if(a[pr][pc+1]==' '&&pc+1<7)
       {
	push(pr,pc+1);
       }
     if(a[pr+1][pc]=='D')
       {
	a[pr][pc]='*';
	a[pr+1][pc]='$';
	break;	
	}
    if(a[pr+1][pc]==' '&&pr+1<7)
     {
      push(pr+1,pc);
     }
   if(a[pr][pc-1]=='D')
    {
     a[pr][pc]='*';
     a[pr][pc-1]='$';
     break;	
    }
   if(a[pr][pc-1]==' '&&pc-1>0)
    {
     push(pr,pc-1);
    }
  if(a[pr-1][pc]=='D')
   {
    a[pr][pc]='*';
    a[pr-1][pc]='$';
    break;	
   }
  if(a[pr-1][pc]==' '&&pr-1>0)
   {
    push(pr-1,pc);
   }		
   pop();
   }
}

 void destination()                //Function to set destination
  {
        dr=6;
        dc=6;
        a[dr][dc]='D';
  }

 void source()                      //Function to set source
   {
        sr=1;
        sc=1;
	a[sr][sc]='S';
   }

 void gboard()                              
  {
	b[2][2]='|';
	b[2][3]='|';
	b[2][4]='|';
	b[3][1]='|';
	b[3][3]='|';
	b[4][1]='|';
	b[4][3]='|';
	b[4][5]='|';
	b[4][6]='|';
	b[5][2]='|';
	b[6][1]='|';
	b[6][3]='|';
	b[6][4]='|';
	b[sr][sc]='S';
	b[dr][dc]='$';
}

void matrix()                                              //Function to create game board matrix
{
	int i,j;
	for(i=0;i<8;i++)
         {
		for(j=0;j<8;j++)
                  {
			if(i==0||i==7||j==0||j==7)
                        {
				a[i][j]='.';
				b[i][j]='.';
			}				
			else
                         {
				a[i][j]=' ';
				b[i][j]=' ';
			 }			
		}			
	}
	a[2][2]='|';
	a[2][3]='|';
	a[2][4]='|';
	a[3][1]='|';
	a[3][3]='|';
	a[4][1]='|';
	a[4][3]='|';
	a[4][5]='|';
	a[4][6]='|';
	a[5][2]='|';
	a[6][1]='|';
	a[6][3]='|';
	a[6][4]='|';
	source();
	destination();
	gboard();
}

 void exitfun()                                         //Game end function
  {
	system("clear");
	b[dr][dc]=='D';
	for(int i=0;i<8;i++)
         {
	 for(int j=0;j<8;j++)
          {
	   cout<<b[i][j]<<" ";
	  }
	 cout<<endl;
	}
	cout<<"YOUR SCORE IS: "<<hs<<endl;
	exit(0);
}

 void movement()                                       //Function to make user movements
  {
   int ppr=pr1,ppc=pc1;
   switch(ch)
    {
                case 'a':	pc1--;
			break;
		case 'w':	pr1--;
			break;
		case 'd':	pc1++;
			break;
		case 's':	pr1++;
			break;		
	}
	if(pr1<7&&pr1>0&&pc1<7&&pc1>0&&b[pr1][pc1]!='|')
	{   
		hs++;
		if(a[pr1][pc1]=='$')
                {
			exitfun();
		}
			
	    if(b[pr1][pc1]=='@')
			return ;
	    if(a[pr1][pc1]=='#')
            {
	        b[pr1][pc1]='@';
	        return ;
	    }
	    if(a[pr1][pc1]=='*')
            {
	        b[pr1][pc1]='@';
	        return ;
	    }
	    return ;
	}
	else
        {
		pc1=ppc;
		pr1=ppr;
		life--;
	}
}
 void displayb()                              //Function to display board
  {
	system("clear");
        cout<<"Use w a s d to move"<<endl;
	cout<<"YOUR LIFE IS: "<<life<<endl;
	cout<<"YOUR SCORE IS: "<<hs<<endl;
	for(int i=0;i<8;i++)
         {
		for(int j=0;j<8;j++)
                 {
			cout<<b[i][j]<<" ";
		 }
		cout<<endl;
	}
	cout<<endl;
	cin>>ch;
	if(b[dr][dc]!='D'&&ch!='0')
         {
		if(life==0)
                {
			exitfun();
		}			
		movement();
		displayb();
	}		
}

void game()
{
	displayb();
}
int main()
{	
	matrix();
	path();
	pr1=sr;
	pc1=sc;
	game();
	return 0;	
}
