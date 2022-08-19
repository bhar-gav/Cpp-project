#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <dos.h>
//#include<graphics.h>
#include<windows.h>

using namespace std;
char a[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
char k[2]={'O','X'};
int c[9]={1,2,3,4,5,6,7,8,9};
int i=1,b=1;
char x,mark=' ';
int t1=80,t2=14;



//glutSpecialFunc(SpecialKeys);
int gotoxy(	short x,short y)
{
		HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos={x,y};
		SetConsoleCursorPosition( hConsole, pos);
		return 0;
}

struct rec				
{
	char p1[10];
	char p2[10];
	int s1=0;
	int s2=0;
}r;				//palyers record


int head()		//game title
{
	system("cls");
	cout<<"\n\t\t\t\t\t\t ---TIC TAC TOE---";
	cout<<"\n\t\t\t\t\t\t                     _GHOST X ASK_";
	return 0;
	
}
int reset()		//reset table parameters
{	
	system("cls");
	a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=a[7]=a[8]=' ';
	for( int l=0;l<=9;l++)
	{
		c[l]=l;
	}
	b=1;
	return 0;
	
}
int cursor()
{
			
			int key=1;
			while(key!=13 &&i!=10)			//ASCII FOR ENTER
			{	
				gotoxy(t1,t2);
				key=getch();
				//cout<<key;
				switch(key)
				{	
					case 13:
					{
						break;
					}
					case 72:		//ASCII FOR UP
					{	
						//cout<<"up";
						if(!(t2<14))
						{
							t2=t2-5;
						}
						break;
					}
					case 80:		//ASCII FOR DOWN
					{	
						//cout<<"down";
						if(!(t2>14))
						{
							t2=t2+5;
						}
						break;
						
					}
					case 77:		//ASCII FOR RIGHT
					{		
						//cout<<"right";
						if(!(t1>80))
						{
							t1=t1+10;
						}
						break;
						
					}
					case 75:		//ASCII FOR LEFT
					{	
						//cout<<"left";
						if(!(t1<80))
						{
							t1=t1-10;
						}
						break;
						
						
					}
				}
			}
							
							
		return 0;			
}


char wincheck()		//check if any player has won 
{
	if( a[0]==a[1]&&a[1]==a[2]&&a[0]!=' ' ) 
	{
		return a[0];
	}
	if( a[3]==a[4]&&a[4]==a[5]&&a[3]!=' ') 
	{
		return a[3];
	}
	if( a[6]==a[7]&&a[7]==a[8]&&a[6]!=' ')
	{
		return a[6];
	}
	if( a[0]==a[3]&&a[3]==a[6]&&a[0]!=' ')
	{
		return a[0];
	}
	if( a[1]==a[4]&&a[4]==a[7]&&a[1]!=' ')
	{
		return a[1];
	}
	if (a[2]==a[5]&&a[5]==a[8]&&a[5]!=' ')
	{
		return a[2];
	}
	if( a[0]==a[4]&&a[4]==a[8]&&a[0]!=' ') 
	{
		return a[0];
	} 
	if( a[6]==a[4]&&a[4]==a[2]&&a[6]!=' ')
	{
		return a[6];
	}
	else
	{
		return 'n';
	}
}

int playerinfo()
{	
	gotoxy(0,5);
	cout<<"\n\n		NAME    	SCORE";
	cout<<"\n		"<<r.p1<<"	  	"<<r.s1;
	cout<<"\n		"<<r.p2<<"		"<<r.s2;
	return 0;
	
}

int gamelayout()
{
	cout<<"\n \n \n \n \n ";
				cout<<"\t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t     "<<a[0]  <<"    |\t"<<a[1]<<"    |     "<<a[2];
				cout<<"\n \t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t _________|__________|_________\n";
				cout<<"\t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t     "<<a[3]  <<"    |\t"<<a[4]<<"    |     "<<a[5];
				cout<<"\n \t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t _________|__________|_________\n";
				cout<<"\t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t     "<<a[6]  <<"    |\t"<<a[7]<<"    |     "<<a[8];
				cout<<"\n \t \t \t \t \t \t \t \t          |          |         \n";
				cout<<"\t \t \t \t \t \t \t \t          |          |         \n";
				return 0;
}
int rungame()		//run game
{  	int turn;
	
	/*ofstream recfile("rec.dat",ios::binary|ios::out);
	recfile.close();
	*/
	for( i=1;i<=9;i++)
	{			
				
				if(0)
				{
					e:
					gotoxy(80,30);
					cout<<"SPACE ALREADY FILLED ";
					sleep(1);
						gotoxy(t1,t2);
				}	
				
				head();				
				
				gamelayout();
				playerinfo();
				
			
				
				gotoxy(0,12);
				if(turn==1||i==1)
				{	
					cout<<" \n\t 	TURN :: "<<r.p1;
				}
				else if(turn==2)
				{	
					cout<<" \n\t 	TURN :: "<<r.p2;
				}	
				
				//cout<<"\n Choose location 1-9 ::\t";
			
				cursor();
					if(i==1)				//deciding turn of player
					turn=1;
				if(i>=1)
				{		
					if(i%2==0)
					{
						mark='O';
						turn=2;
					}
					else
					{
						mark='X';
						turn=1;
					}	
				}
				
				gotoxy(t1,t2);
				{
					cout<<mark;
				}
				for(int q=0;q<3;q++)				//allocating values 0 x
				{
					for(int w=0;w<3;w++)
					{
						if(t1==(10*w+70) && t2==(5*q+9) )		//relating one dimension array with double coordinates
						{	
							if(!( a[3*q+w]=='X' || a[3*q+w]=='O'))	
							{
								a[2*q+q+w]=mark;
							}
							else
							{	
								goto e;
							}
						}
					}
				}
				x=wincheck();
				if(x!='n')
				{
					break;
				}	
			
	}
		
					
						/*	switch(key)
							{
								case GLUT_KEY_LEFT:			//glut.h   graphics.h needed add to bin
									{
										cout<<"left key";
									}
								case GLUT_KEY_RIGHT:
									{
										cout<<"left RIGHT";
									}
								case GLUT_KEY_UP:
									{
										cout<<"left UP";
									}
								case GLUT_KEY_DOWN:
									{
										cout<<"left DOWN";
									}
		
							}
							*/
			
		
	if(x!='n')				//check for which player wins the game
	{	
		gotoxy(50,15);
		if(x=='X')
		{	
			cout<<"\n\n\tCONGRATS : "<<r.p1<<" ::WINS";
			r.s1++;
			Beep(800,2000);
		}
		else
		{
			cout<<"\n\n\tCONGRATS : "<<r.p2<<" ::WINS";
			r.s2++;
			Beep(800,2000);
	    }
	}
	else
	{
		cout<<"\n\n\tDRAW \a.";
	}
	sleep(2);
	char ag[4];
	cout<<" \n\n\tDo you want to play again (type : yes) :: ";
	
	//cin.ignore();
	cin.getline(ag,4);
	if(strcmpi( ag,"yes")==0)
	{	
		reset();
		rungame();
	}
	else
	{
		cout<<"\n\n\t THANKS FOR PLAYING..";
	}
	getch();

	
	return 0;

}



int main ()		//loader function
{
		
	system("color 7C");
	head();
	
	cout<<"\nWelcome to the game \n";
	cout<<"Press enter : " ;
	getch();
	cout<<"\n\n Enter player names\n";
	cout<<" \tPLAYER 1:: ";
	//gotoxy(880,234);
	cin.getline(r.p1,10);
	cout<<" \tPLAYER 2:: ";
	cin.getline(r.p2,10);
	
	cout<<"\n\n\t\t\t PRECAUTION :: DONT ENTER ANY NON NUMERIC CHARACTER IN CHOICE .";
	sleep(2);
	r.s1=r.s2=0;
	/*ofstream recfile("rec.dat",ios::binary | ios::out );
	recfile.close();
	*/
	rungame();
	return 0; 
}