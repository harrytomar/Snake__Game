#include<iostream>
#include<conio.h >
#include<graphics.h>
#include<time.h>
using namespace std;
bool gameOver;
const int w = 20;
const int h = 20;
int x,y,fruit_x,fruit_y,score;
int tail_X[100],tail_Y[100];   // holds x and y coordinates of tales and we print them in draw function.
int nTail;
enum eDirection { STOP=0,LEFT,RIGHT,UP,DOWN
};
eDirection dir;
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = w/2;   // these two x and y make the sname centre alligned in starting
	y = h/2;
	fruit_x = rand() % w;
	fruit_y = rand() % h;
	score=0;
}
void Draw()
{
	system("cls");
	for(int i=0;i<w+2;i++)
		cout<<"$";
	cout<<endl;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(j==0)
			{
				cout<<"$";
			}
			if(i==y && j==x)
			{
				cout<<"O";
			}
			else
			{
				if(i==fruit_y && j==fruit_x)
				{
					cout<<"F";
				}
				else        // when snake eats fruit at that sleep of time it comes into else part
				{
					bool flag = false;
					for(int k=0;k<nTail;k++)
					{
						
						if(tail_X[k]==j && tail_Y[k] ==i)
						{
							cout<<"o";
							flag = true;
						}
					
					}
						if(!flag)
							cout<<" ";
				}
			}
			
			if(j==w-1)
			{
				cout<<"$";
			}
		}
		cout<<endl;
	}
	for(int i=0;i<w+2;i++)
		cout<<"$";
	cout<<endl;
	cout<<"SCORE:"<<score<<endl;
}
void Input()
{
	if(_kbhit())
	{
		switch(_getch()) // _getch return char what we press
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
		}
	}
}
void Logic()
{
	
	int prev_x = tail_X[0];
	int prev_y = tail_Y[0];
	int prev2x,prev2y;
	tail_X[0]=x;    // follow head
	tail_Y[0] = y;
	for(int i=1;i<nTail;i++)
	{
		prev2x = tail_X[i];
		prev2y = tail_Y[i];
		tail_X[i] = prev_x;
		tail_Y[i] = prev_y;
		prev_x = prev2x;
		prev_y = prev2y;
	}
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}
	if(x>w || x<0 || y>h || y<0)
	{
		gameOver = true;
	}
	if(x == fruit_x && y == fruit_y)
	{
		score = score+10;
		fruit_x = rand()%w;
		fruit_y = rand()%h;
		nTail++;
	}
}
int main()
{
	Setup();
	while(!gameOver)
	{
	Draw();
	Input();
	Logic();
	//Sleep(10);	
	}
	return 0;
}
