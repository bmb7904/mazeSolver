
#ifndef POSITION_H
#define POSITION_H

class Position
{
    private:
        int firstx, firsty;

    public:
        Position();
        Position(Maze m);
        bool moveTo(Maze &m, int x, int y);
        void solveMaze(Maze &m);
};

Position::Position()
{
    firstx = 0;
    firsty = 0;
}

Position::Position(Maze m)
{
    firstx = 0;
    firsty = 0;
    for (int x = 0; x < 1000; x++)
    {
        for (int y = 0; y < 1000; y++)
        {
            if (m.peek(x,y) == '2')
            {
                firstx = x;
                firsty = y;
                return;
            }
        }
    }
}

bool Position::moveTo(Maze &m, int x, int y)
{
    // 0 = Empty space
    // 1 = Wall
    // 2 = Beginning
    // 3 = Exit
    // 4 = been there
    // 5 = Part of the path out

    //cout << x << "," << y << endl;

    bool thisIsThePath = false;
    // make sure your on grid
    if ((x < 0) | (x > 999) | (y < 0) | (y > 999))
        return false;
    // Places you can not go
    if((m.peek(x,y) == '1') | (m.peek(x,y) == '2') | (m.peek(x,y) == '4'))
        return false;
    // check if you are out
    if((m.peek(x,y) == '3'))
        return true;
    // Mark this spot
    m.setSpace(x,y,'4');
    // Go in all four directions
    if (moveTo(m,x+1,y))
        thisIsThePath = true;
    if (moveTo(m,x-1,y))
        thisIsThePath = true;
    if (moveTo(m,x,y+1))
        thisIsThePath = true;
    if (moveTo(m,x,y-1))
        thisIsThePath = true;
    // If needed, mark that this is part of the solution
    if (thisIsThePath)
        m.setSpace(x,y,'5');
    return thisIsThePath;
}

void Position::solveMaze(Maze &m)
{
    moveTo (m, firstx+1, firsty);
    moveTo (m, firstx-1, firsty);
    moveTo (m, firstx, firsty+1);
    moveTo (m, firstx, firsty-1);
}


#endif /* POSITION_H */

