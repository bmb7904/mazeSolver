
#ifndef MAZE_H
#define MAZE_H

using namespace std;

class Maze
{
    private:
        char m[1000][1000];

    public:
        Maze();
        void readMaze();
        void printMaze();
        char peek (int x, int y);
        void setSpace(int x, int y, char c);
};

Maze::Maze()
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            m[i][j]= ' ';
        }
    }
}

void Maze::readMaze()
{
    string line;
    ifstream fin ("Maze.txt");
    int y = 0;
    while (getline(fin, line))
    {
        int x = 0;
        istringstream linein(line);
        while (linein >> m[x][y])
        {
            x++;
        }
        y++;
    }
}

void Maze::printMaze()
{
    // 0 = Empty space
    // 1 = Wall
    // 2 = Beginning
    // 3 = Exit
    // 4 = been there
    // 5 = Part of the path out

   for (int y = 0; y < 100; y ++)
    {
        for (int x = 0; x < 100; x++)
        {
            if (m[x][y] == '0')
                cout << ' ';
            if (m[x][y] == '1')
                cout << '|';
            if (m[x][y] == '2')
                cout << 'S';
            if (m[x][y] == '3')
                cout << 'F';
            if (m[x][y] == '4')
                cout << ' ';
            if (m[x][y] == '5')
                cout << '*';

            if ((m[x][y] == ' ') && (x == 0))
                return;
        }
        cout << endl;
    }
}

char Maze::peek (int x, int y)
{
    return m[x][y];
}

void Maze::setSpace(int x, int y, char c)
{
    m[x][y] = c;
}


#endif /* MAZE_H */

