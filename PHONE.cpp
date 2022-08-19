/*
	Name: PHONEBOOK
	Copyright: @BHARGAV
	Author: BHARGAV
	Date: 17-06-22 18:01
	Description: DONt EDIT 
*/

#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<dos.h>

using namespace std;

class phonebook
{
	//private:
	//	char pass[20];
	public:
			char name[20];
			char rno[10];
			char mno[12];
			
};

int main()
{
	phonebook p;
	int c;
	system("color 7C");
	
	do
	{
		c=0;
		system("cls");
		cout<<"\n\t\t\tPHONEBOOK\n";
		cout<<"\n\n"<<setw(100)<<setiosflags(ios::right)<<" FROM :: GHosT X ASK";
		
		cout<<"\n 1. Add record";
		cout<<"\n 2. Search record";
		cout<<"\n 3. EDIT record";
		cout<<"\n 4. Display all records";
		cout<<"\n 5. DELETE ALL RECORDS";
		cout<<"\n 6. EXIT !!";
		cout<<"\n\n ENTER your choice::  ";
		cin>>c;
		
		switch(c)
		{
			case 1:
				{
				
					ofstream fout("phone.dat",ios::binary | ios::app);
					cout<<"\n    Enter name:: ";
					cin.ignore();
					cin.getline(p.name,20);
					cout<<"\n    Enter roll number:: ";
					cin.getline(p.rno,10);
					cout<<"\n    Enter mobile number:: ";
					cin.getline(p.mno,12);
					
					fout.write( (char*)&p,sizeof(p));
					fout.close();
					cout<<"\n\t ADDED SUCCESFULLY";
					getch();
					break;
				}
			case 2:
				{
				
					cout<<"\n\n\t SEARCH OPTION:: 1. by NAME\n\t 2. by ROLL NO\n\t:: ";
					int k;
					cin>>k;
					if(k==1)
					{
						char sname[20];
						int count=0;
						//settextcolor(1,2,4);
						cout<<"\n ENTER name:: ";
						cin.ignore();
						cin.getline(sname,20);
						ifstream fin("phone.dat",ios::binary|ios::in);
						
						while(fin.read( (char*)&p,sizeof(p)) )
						{
							if(strcmpi( sname,p.name)==0)	
							{
								cout<<"\n\n\t"<<p.name<<"	"<<p.rno<<"		"<<p.mno;
								cout<<endl;
								count++;
								
							}
							
						}
						if(count==0)
						{
							cout<<"\n\t Record NOT found";
							
						}	
						
					}
					else if(k==2)
					{
						char srno[10];
						int count=0;
						cout<<"\n ENTER roll no:: ";
						cin.ignore();
						cin.getline(srno,10) ;
						ifstream fin("phone.dat",ios::binary|ios::in);
						
						while(fin.read( (char*)&p,sizeof(p)) )
						{
							if(strcmpi( srno,p.rno)==0)	
							{
								cout<<"\n\n\t"<<p.name<<"	"<<p.rno<<"		"<<p.mno;
								cout<<endl;
								count++;
								
							}
							
						}
						fin.close();
						if(count==0)
						{
							cout<<"\n\t Record NOT found";
							
						}	
						
					}
					else
					{
						cout<<"inVALID INput";
						
					}
					
					
					getch();
					break;
			    }
			case 3:
				{	
					cout<<"\n This feature is currently unavailable :: Under developement";
				/*	char id[20];
					
					phonebook n;
					int f=0,rec=0;
				
					cout<<"\n\n\t Enter record identity NAME::";
					cin.ignore();
					cin.getline(n.name,20);
					fstream file;
					file.open("phone.dat",ios::binary|ios::in|ios::out);
					while( file.read( (char*)&p,sizeof(p)) )
					{
						rec++;
						if( strcmpi(n.name,p.name)==0)
						{
							cout<<"\n RECORD found ::\t\t";
							cout<<p.name<<" "<<p.rno<<" "<<p.mno;
							cout<<"\n\t Enter new name::";
							cin.ignore();
							cin.getline(n.name,20);
							cout<<"\n\tEnter new roll no::";
							cin.getline(n.rno,10);
							cout<<"\n\tEnter new mno::";
							cin.getline(n.mno,12);
							file.seekg( (-1)*sizeof(p),ios::cur);
							file.write( (char*)&n,sizeof(n) );
							f=1;
							
						}
						else
						{
							file.write( (char*)&p,sizeof(p) );  
						}
					}
					if(!f)
					{
						cout<<"\n\n Record doesnt exist";
					}
					cout<<"\n\t TOTAL RECORDs scanned::"<<rec;
					
				*/
					getch();
					break;
				}
			case 4:
				{
					system("cls");
					int m=0;
					ifstream fin("phone.dat",ios::binary|ios::in );
					while(fin.read( (char*)&p,sizeof(p)))
					{
							cout<<"\n\n"<<p.name<<"	"<<p.rno<<"		"<<p.mno;
							m++;
					}
					if(m==0)
					{
						cout<<"\n\n\t\t PHONEBOOK is EMPTY";
					}
					else
					{	
						cout<<"\n\nTOTAL RECORDS::"<<m;
					}
					fin.close();
					getch();
					break;
				}
		
			case 5:
				{
						ofstream fout("phone.dat",ios::binary | ios::out);
						fout.close();
						
						cout<<endl<<setw(60)<<setiosflags(ios::right)<<" Content DESTOYED  succesfully";
						getch();
						break;
						
				}
			case 6:
				{
					system("cls");
					cout<<"\n\n\t\t\t PHONEBOOK CLOSED";
					break;
				}
			default:
				{
				
					cout<<"\n\t\t INVALID INPUT";
					cout<<" \nPress any key to continue";
					getch();
				}
					
		}
		
	}while(c!=6);
	
	
	
	getch();
	return 0;
}