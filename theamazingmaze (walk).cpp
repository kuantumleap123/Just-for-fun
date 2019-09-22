#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum State {FREE,STUCK,ESCAPE};
void moveup(int &curX,int &curY,char maze[][17])
{
    curY++;
    maze[curX][curY] = 'o';
}
void movedown(int &curX,int &curY,char maze[][17])
{
    curY--;
    maze[curX][curY] = 'o';
}
void moveleft(int &curX,int &curY,char maze[][17])
{
    curX--;
    maze[curX][curY] = 'o';
}
void moveright(int &curX,int &curY,char maze[][17])
{
    curX++;
    maze[curX][curY] = 'o';
}

void simulate()
{
    char maze[17][17] = {};
    for(int i=0;i<17;i++)
    {
        for(int j=0;j<17;j++)
        {
            maze[i][j] = '.';
        }
    }
    int freespace[4] = {};
    int numfreespace = 0;
    int curX = 8;
    int curY = 8;
    maze[curX][curY] = 'x';
    int random;
    State curstate = FREE;
    while(curstate == FREE)
    {
        if((curX==0)||(curY==0)||(curX==16)||(curY==16))
        {
            curstate = ESCAPE;
            break;
        }

        if(maze[curX][curY+1]=='.')//up
        {
            numfreespace++;
            freespace[0] = 0;
        }
        else
        {
            freespace[0] = 1;
        }

        if(maze[curX][curY-1]=='.')//down
        {
            numfreespace++;
            freespace[1] = 0;
        }
        else
        {
            freespace[1] = 1;
        }

        if(maze[curX-1][curY]=='.')//left
        {
            numfreespace++;
            freespace[2] = 0;
        }
        else
        {
            freespace[2] = 1;
        }

        if(maze[curX+1][curY]=='.')//right
        {
            numfreespace++;
            freespace[3] = 0;
        }
        else
        {
            freespace[3] = 1;
        }


        if(numfreespace==0)
        {
            curstate = STUCK;
            break;
        }
        else if(numfreespace==1)
        {
            if(freespace[0]==0)//up
            {
                moveup(curX,curY,maze);
            }
            else if(freespace[1]==0)//down
            {
                movedown(curX,curY,maze);
            }
            else if(freespace[2]==0)//left
            {
                moveleft(curX,curY,maze);
            }
            else//right
            {
                moveright(curX,curY,maze);
            }
        }
        else
        {
            while(1)
            {
                random = rand()%4;
                if((random==0)&&(freespace[0]==0))
                {
                    moveup(curX,curY,maze);
                    break;
                }
                else if((random==1)&&(freespace[1]==0))
                {
                    movedown(curX,curY,maze);
                    break;
                }
                else if((random==2)&&(freespace[2]==0))
                {
                    moveleft(curX,curY,maze);
                    break;
                }
                else if((random==3)&&(freespace[3]==0))
                {
                    moveright(curX,curY,maze);
                    break;
                }
            }

        }

        numfreespace = 0;
    }

    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=15;j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    for(int i=1;i<=10;i++)
    {
        simulate();
        cout << endl << endl;
    }

    return 0;
}
