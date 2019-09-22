#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum State {FREE,STUCK,ESCAPE};
void moveup(int &curX,int &curY,int maze[][17])
{
    curY++;
    maze[curX][curY] = 1;
}
void movedown(int &curX,int &curY,int maze[][17])
{
    curY--;
    maze[curX][curY] = 1;
}
void moveleft(int &curX,int &curY,int maze[][17])
{
    curX--;
    maze[curX][curY] = 1;
}
void moveright(int &curX,int &curY,int maze[][17])
{
    curX++;
    maze[curX][curY] = 1;
}

State simulate()
{
    int maze[17][17] = {};
    int freespace[4] = {};
    int numfreespace = 0;
    int curX = 8;
    int curY = 8;
    maze[curX][curY] = 1;
    int random;
    State curstate = FREE;
    while(curstate == FREE)
    {
        if((curX==0)||(curY==0)||(curX==16)||(curY==16))
        {
            curstate = ESCAPE;
            break;
        }

        if(maze[curX][curY+1]==0)//up
        {
            numfreespace++;
            freespace[0] = 0;
        }
        else
        {
            freespace[0] = 1;
        }

        if(maze[curX][curY-1]==0)//down
        {
            numfreespace++;
            freespace[1] = 0;
        }
        else
        {
            freespace[1] = 1;
        }

        if(maze[curX-1][curY]==0)//left
        {
            numfreespace++;
            freespace[2] = 0;
        }
        else
        {
            freespace[2] = 1;
        }

        if(maze[curX+1][curY]==0)//right
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

    return curstate;
}

int main()
{
    srand(time(0));
    int stuck = 0;
    int esc = 0;
    for(int i=1;i<=1000;i++)
    {
        if(simulate()==STUCK)
        {
            stuck++;
        }
        else
        {
            esc++;
        }
    }

    cout << "Escapes: " << esc << endl;
    cout << "Stuck: " << stuck;
    return 0;
}
