#include <iostream>

using namespace std;

int main()
{
    int width;
    int height;
    cout << "Please enter width: ";#include <iostream>

using namespace std;

int main()
{
    int width;
    int height;
    cout << "Please enter width: ";
    cin >> width;
    cout << "Please enter height: ";
    cin >> height;

    string chamber[width][height] = {};
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            chamber[i][j] = '.';
        }
    }

    string mirror;
    int x;
    int y;

    cout << "Please enter mirror orientation (/ or \\), followed by coordinates." << endl;
    cout << "Type 'done' when you're done" << endl << endl;

    while(1)
    {
        for(int j=height-1;j>=0;j--)
        {
            if(j<10)
            {
                cout << ' ';
            }
            cout << j << ' ';

            for(int i=0;i<width;i++)
            {
                cout << ' ' << chamber[i][j] << ' ';
            }
            cout << endl;
        }

        cout << "   ";
        for(int i=0;i<width;i++)
        {
            if(i<10)
            {
                cout << " ";
            }
            cout << i << " ";
        }
        cout << " " << endl << endl;


        cin >> mirror;
        if(mirror == "done")
        {
            break;
        }

        cin >> x >> y;
        cout << endl << endl;

        chamber[x][y] = mirror;
    }

    cout << endl << endl;
    cout << "   ";
    for(int i=2*width+height-1;i>=width+height;i--)
    {
        if(i<10)
        {
            cout << " ";
        }
        cout << i << " ";
    }
    cout << " " << endl;

    int offset;
    int entranceNum;
    for(int j=height-1;j>=0;j--)
    {
        offset = height-j;
        entranceNum = 2*width+height-1 + offset;
        if(entranceNum < 10)
        {
            cout << ' ';
        }
        cout << entranceNum << " ";

        for(int i=0;i<width;i++)
        {
            cout << ' ' << chamber[i][j] << ' ';
        }

        entranceNum = width+height - offset;
        if(entranceNum < 10)
        {
            cout << ' ';
        }
        cout << entranceNum << endl;
    }

    cout << "   ";
    for(int i=0;i<width;i++)
    {
        if(i<10)
        {
            cout << " ";
        }
        cout << i << " ";
    }
    cout << " " << endl;

    char currentDirection;
    int currentX;
    int currentY;
    bool hasExited = false;
    int exit;

    for(int i=0;i<2*(width+height);i++)
    {
        if(i<width)
        {
            currentDirection = 'u';
            currentX = i;
            currentY = 0;
        }
        else if(i<width+height)
        {
            currentDirection = 'l';
            currentX = width-1;
            currentY = i-width;
        }
        else if(i<2*width+height)
        {
            currentDirection = 'd';
            currentX = 2*width+height-i-1;
            currentY = height-1;
        }
        else
        {
            currentDirection = 'r';
            currentX = 0;
            currentY = 2*(width+height)-i-1;
        }




        while(!hasExited)
        {
            if(chamber[currentX][currentY]==".")
            {
                switch(currentDirection)
                {
                    case 'u':
                        currentY++;
                        break;
                    case 'd':
                        currentY--;
                        break;
                    case 'l':
                        currentX--;
                        break;
                    case 'r':
                        currentX++;
                        break;
                }
            }

            if(chamber[currentX][currentY]=="/")
            {
                switch(currentDirection)
                {
                    case 'u':
                        currentDirection = 'r';
                        currentX++;
                        break;
                    case 'd':
                        currentDirection = 'l';
                        currentX--;
                        break;
                    case 'l':
                        currentDirection = 'd';
                        currentY--;
                        break;
                    case 'r':
                        currentDirection = 'u';
                        currentY++;
                        break;
                }
            }

            if(chamber[currentX][currentY]=="\\")
            {
                switch(currentDirection)
                {
                    case 'd':
                        currentDirection = 'r';
                        currentX++;
                        break;
                    case 'u':
                        currentDirection = 'l';
                        currentX--;
                        break;
                    case 'r':
                        currentDirection = 'd';
                        currentY--;
                        break;
                    case 'l':
                        currentDirection = 'u';
                        currentY++;
                        break;
                }
            }

            if((currentDirection=='u' && currentY>=height-1) || (currentDirection=='d' && currentY<=0) || (currentDirection=='l' && currentX<=0) || (currentDirection=='r' && currentX>=width-1))
            {
                hasExited = true;
            }


        }

        switch(currentDirection)
        {
            case 'd':
                exit = currentX;
                break;
            case 'u':
                exit = 2*width+height-1-currentX;
                break;
            case 'r':
                exit = width+currentY;
                break;
            case 'l':
                exit = 2*(width+height)-1-currentY;
                break;
        }
        cout << i << "->" << exit << endl;
        hasExited = false;
    }
    return 0;
}

    cin >> width;
    cout << "Please enter height: ";
    cin >> height;
    return 0;
}
