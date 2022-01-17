#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<ctime>

using namespace std;
int main()
{

using std::cout;
using std::cin;
using std::endl;
system("CLS"); //clears the screen
int a,red; // variable a takes the difficulty choice and red defines number of moves
char name;

//  Instructions 
cout<<"\t\t\t THE BORING GAME \n\n"<<"\n Instructions :\n1. You are Assigned with a * as your movable charachter ,Your goal is to make contact with percentage sign \n";
cout<<"2. You have Limited Number of Moves, if you Succeed in reaching % within the moves you WIN \n";
cout<<"3. Use W,A,S,D  keys to move your character \n"<<"4.Dont touch the -- or || bars you will loose the game"<<"\n5. BEWARE OF THE @ SIGNS THAT POP UP RANDOMLY IF YOU TOUCH THEM YOU LOOSE"<<endl;
cout<<"\n Ok ";
cout<<" Select your Difficulty Level \n"<<"\n1.EASY \n"<<"2.MEDIUM \n"<<"3.HARD \n"<<"4.IMPOSSIBLE \n\nENTER YOUR CHOICE : ";

cin>>a; 

if( a==1)
red = 5; //if easy is chosen reduces total moves by 5
else if(a==2)
red = 10; //if hard is chosen reduces total moves by 10
else if(a==3)
{
  red = 30; //if impossible is chosen reduces total moves by 30
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

char input; //variable to read moves from keyboard

system("CLS");


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

// the border of the game looks like the above array


brdr[7][35] = '%'; //target location where the charater to be reached


for(int t =0; t>=0;t++)
{
	for(int i =0; i<=14;i++) //prints the borders and the location characher and target
     cout<<brdr[i]<<endl;

 cout<<" \n \n MOVES LEFT ="<<count; //print the number of moves left
 m = rand() % 10;
 n = rand() % 50;  //randomises position for obstacles
 if(brdr[m][n] != brdr[7][35] && m >0 && n> 0)
    brdr[m][n] = '@';  //obstacle placing at different positions
   
      
	  input =tolower(getche()); //gets input from keyboard


	  if(input == 'd')   //if input is d the charachter moves left
  		{
		  brdr[x][y] = ' '; 
          if(brdr[x][y+1] == '|'||brdr[x][y+1] == '@') // if that shifted positition = @ then exit
           exit(0);
          else
         {
			 if(brdr[x][y-1] ==brdr[7][35]) //if the postion of * is at target location then user wins the match
              {
				  system("CLS"); 
                  goto lose;
               }
            brdr[x][y+1] ='*'; //basically puts a space before and shifts the * to y+1 postion 
            y=y+1;
		 }
        }
 else if(input =='a')//if input is a the charachter moves left
  {
	  brdr[x][y] =' ';
      if(brdr[x][y-1] == '|'||brdr[x][y-1] == '@')
       exit(0);
    else
      {
		  if(brdr[x][y-1] ==brdr[7][35])//if the postion of * is at target location then user wins the match
           {
			   system("CLS");
               goto lose;
               exit(0);
			}
          brdr[x][y-1] ='*';//basically puts a space before and shifts the * to y-1 postion 
          y=y-1;
	   }
   }
 else if(input =='s')//if input is a the charachter moves down
  {
	  brdr[x][y] =' ';
      if(brdr[x+1][y] =='-'|| brdr[x+1][y] =='@')//if the postion of * is at target location then user wins the match
       exit(0);
      else
       {
		  if(brdr[x+1][y] ==brdr[7][35]) //if the postion of * is at target location then user wins the match
          {
            system("CLS");
            goto lose;
          }
          
		  brdr[x+1][y] ='*';//basically puts a space before and shifts the * to x+1 postion 
          x=x+1;
        }
   }
  else if(input =='w')//if input is w the charachter moves up
   {
	   brdr[x][y] =' ';
 
       if(brdr[x-1][y] =='-'||brdr[x-1][y] =='@')//if the postion of * is at target location then user wins the match
        exit(0);
       else
        {
           if(brdr[x-1][y] ==brdr[7][35]) //if the postion of * is at target location then user wins the match
            {
				system("CLS");
                goto lose;
            }
         }

       brdr[x-1][y] ='*';//basically puts a space before and shifts the * to x-1 postion 
       x=x-1;

 
    }



count = count - 1;
  if(input=='b')
    exit(0);
  if(count == -1)
   {
	system("CLS");
    exit(0);
    }
system("CLS");

}


lose:
  {
    system("CLS");
    cout<<"WINNER";
   }


return 0;
getch();
 
 
}