#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
void main()
{clrscr();
int a,red;
char name;
cout<<"\t\t\t THE BORING GAME \n\n"<<"\n Instructions :\n1. You are Assigned with a * as your movable charachter ,Your goal is to make contact with % sign"<<endl;
cout<<"2. You have Limited Number of Moves, if you Succeed in reaching % within the moves you WIN"<<endl;
cout<<"3. Use W,A,S,D  keys to move your character \n"<<"4.Dont touch the -- or || bars you will loose the game"<<"\n5. BEWARE OF THE @ SIGNS THAT POP UP IF YOU TOUCH THEM YOU LOOSE"<<endl;
cout<<"\n Ok ";
cout<<" Select your Difficulty Level \n"<<"\n1. EASY \n"<<"2.MEDIUM \n"<<"3.HARD \n"<<"4.IMPOSSIBLE \n\nENTER YOUR CHOICE : ";
cin>>a;
if( a==1)
red = 5;
else if(a==2)
red = 10;
else if(a==3)
{
red = 30;
cout<<"Are you sure "<<name<<" you can do this, dont chicken out at the end";
}
else if(a==4)
{
red = 40;
cout<<name<<"Its Impossible to solve then why even care";
}
else
cout<<name<<"YOU HAVE MADE A WRONG CHOICE";

cout<<endl<<"\n THE GAME BEGINS ";

int x = 1,y =1,m,n,count=50 - red,j=0;
char input;
clrscr();
char brdr [14][52] = {"--------------------------------------------------",
		      "|*                                                |",
		      "|                                                 |",
		      "|                                                 |",
		      "|                                                 |",
		      "|                                                 |",
		      "|                                                 |",
		      "|                                                 |",
		      "|                                                 |",
		      "|                                                 |",
		      "|                                                 |",
		      "---------------------------------------------------"};
brdr[7][35] = '%';
for(int t =0; t>=0;t++)
{for(int i =0; i<=14;i++)
{
cout<<brdr[i]<<endl;
}
cout<<" \n \n MOVEMENT LEFT ="<<count;
m = random(14-2+1);
n = random(49-4+1);
if(brdr[m][n] != brdr[7][35])
{brdr[m][n] = '@';}
input =getche();
if(input == 'd')
{brdr[x][y] = ' ';
if(brdr[x][y+1] == '|'||brdr[x][y+1] == '@')
{exit(0);}
else
{if(brdr[x][y-1] ==brdr[7][35])
{clrscr();
goto lose;
}
brdr[x][y+1] ='*';
y=y+1;}
}
else if(input =='a')
{brdr[x][y] =' ';
if(brdr[x][y-1] == '|'||brdr[x][y-1] == '@')
{exit(0);}
else
{if(brdr[x][y-1] ==brdr[7][35])
{clrscr();
goto lose;
exit(0);}
brdr[x][y-1] ='*';
y=y-1;}
}
else if(input =='s')
{brdr[x][y] =' ';
if(brdr[x+1][y] =='-'|| brdr[x+1][y] =='@')
{exit(0);}
else
{if(brdr[x+1][y] ==brdr[7][35])
{
clrscr();
goto lose;
}
brdr[x+1][y] ='*';
x=x+1;
}}
else if(input =='w')
{brdr[x][y] =' ';
if(brdr[x-1][y] =='-'||brdr[x-1][y] =='@')
{exit(0);}
else
{
if(brdr[x-1][y] ==brdr[7][35])
{clrscr();
goto lose;
}
}
brdr[x-1][y] ='*';
x=x-1;
}



count = count - 1;
if(input=='b')
exit(0);
if(count == -1)
{clrscr();
exit(0);
}
clrscr();

}


lose:
{
clrscr();
cout<<"WINNER";
}

getch();
}
