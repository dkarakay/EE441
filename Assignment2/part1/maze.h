#include <iostream>
#include <fstream>

using namespace std;


class Maze
{
public:
    char **state;
    int nrow, ncol;
    char dirRobot;

    Maze();
    Maze(const Maze& maz);
    int posTarget[2];
    int posRobot[2];

    void print_state();

    bool can_move_left();
    bool can_move_right();
    bool can_move_forward();
    bool can_move_back();
    bool is_solved();

    void move_left();
    void move_right();
    void move_forward();
    void move_back();

};


Maze::Maze()
{
    // Input from file stream
    ifstream input_file;

    // Open input_maze.txt
    input_file.open ("input_maze.txt");

    // Read from opened file -> nrow and ncol
    input_file >> nrow >> ncol;

    // Create two dimensional char array
    state = new char*[nrow];

    // Allocate memory for all columns for each row
    for(int i = 0; i < nrow; ++i)
        state[i] = new char[ncol];

    // Read from file
    for(int i=0; i<nrow; ++i)
    {
        for(int j=0; j<ncol; ++j)
        {
            input_file >> state[i][j];

            // If next char is not dot or # or T
            if(state[i][j] != '.' && state[i][j] != '#' && state[i][j] != 'T')
            {
                posRobot[0] = i; // Y Position of robot, Row
                posRobot[1] = j; // X Position of robot, Col
                dirRobot =  state[i][j]; // Direction
            }


            if(state[i][j] == 'T')
            {
                posTarget[0] = i; // Y Position of target, Row
                posTarget[1] = j; // X Position of target, Col
            }

        }
    }
    input_file.close();

}

Maze::Maze(const Maze& maz)
{
    // Copy constructor
    state = maz.state;
    nrow  = maz.nrow;
    ncol  = maz.ncol;
    dirRobot = maz.dirRobot;
}

// Print state of maze
void Maze::print_state()
{
    for(int i=0; i<nrow; ++i)
    {
        for(int j=0; j<ncol; ++j)
        {
            cout << state[i][j];
        }
        cout << endl;

    }
    cout << endl;
}

// Determine if robot can move left based on NSWE
bool Maze::can_move_left()
{
    switch(dirRobot)
    {
    case 'N':
    {
        return (state[posRobot[0]][posRobot[1]-1] == '#') ? false : true;
    }
    case 'S':
    {
        return (state[posRobot[0]][posRobot[1]+1] == '#') ? false : true;
    }
    case 'W':
    {
        return (state[posRobot[0]+1][posRobot[1]] == '#') ? false : true;
    }
    case 'E':
    {
        return (state[posRobot[0]-1][posRobot[1]] == '#') ? false : true;
    }
    }
}

// Determine if robot can move right based on NSWE
bool Maze::can_move_right()
{
    switch(dirRobot)
    {
    case 'N':
    {
        return (state[posRobot[0]][posRobot[1]+1] == '#') ? false : true;
    }
    case 'S':
    {
        return (state[posRobot[0]][posRobot[1]-1] == '#') ? false : true;
    }
    case 'W':
    {
        return (state[posRobot[0]-1][posRobot[1]] == '#') ? false : true;
    }
    case 'E':
    {
        return (state[posRobot[0]+1][posRobot[1]] == '#') ? false : true;
    }
    }
}

// Determine if robot can move forward based on NSWE
bool Maze::can_move_forward()
{
    switch(dirRobot)
    {
    case 'N':
    {
        return (state[posRobot[0]-1][posRobot[1]] == '#') ? false : true;
    }
    case 'S':
    {
        return (state[posRobot[0]+1][posRobot[1]] == '#') ? false : true;
    }
    case 'W':
    {
        return (state[posRobot[0]][posRobot[1]-1] == '#') ? false : true;
    }
    case 'E':
    {
        return (state[posRobot[0]][posRobot[1]+1] == '#') ? false : true;
    }
    }
}

// Determine if robot can move back based on NSWE
bool Maze::can_move_back()
{
    switch(dirRobot)
    {
    case 'N':
    {
        return (state[posRobot[0]+1][posRobot[1]] == '#') ? false : true;
    }
    case 'S':
    {
        return (state[posRobot[0]-1][posRobot[1]] == '#') ? false : true;
    }
    case 'W':
    {
        return (state[posRobot[0]][posRobot[1]+1] == '#') ? false : true;
    }
    case 'E':
    {
        return (state[posRobot[0]][posRobot[1]-1] == '#') ? false : true;
    }
    }
}

// Moving Left based on last orientation (NSWE)
void Maze::move_left()
{
    if(can_move_left())
    {
        state[posRobot[0]][posRobot[1]] = '.';
        switch(dirRobot)
        {
        case 'N':
        {
            posRobot[1] -=1;
            dirRobot = 'W';
            break;
        }
        case 'S':
        {
            posRobot[1] +=1;
            dirRobot = 'E';
            break;
        }

        case 'W':
        {
            posRobot[0] +=1;
            dirRobot = 'S';
            break;
        }
        case 'E':
        {
            posRobot[0] -=1;
            dirRobot = 'N';
            break;
        }
        }
        state[posRobot[0]][posRobot[1]] = dirRobot;

    }
    else
    {
    }

}

// Moving Right based on last orientation (NSWE)
void Maze::move_right()
{
    if(can_move_right())
    {
        state[posRobot[0]][posRobot[1]] = '.';
        switch(dirRobot)
        {
        case 'N':
        {
            posRobot[1] +=1;
            dirRobot = 'E';
            break;
        }
        case 'S':
        {
            posRobot[1] -=1;
            dirRobot = 'W';
            break;
        }

        case 'W':
        {
            posRobot[0] -=1;
            dirRobot = 'N';
            break;
        }
        case 'E':
        {
            posRobot[0] +=1;
            dirRobot = 'S';
            break;
        }
        }
        state[posRobot[0]][posRobot[1]] = dirRobot;

    }
    else
    {
    }

}

// Moving Forward based on last orientation (NSWE)
void Maze::move_forward()
{
    if(can_move_forward())
    {
        state[posRobot[0]][posRobot[1]] = '.';
        switch(dirRobot)
        {
        case 'N':
        {
            posRobot[0] -=1;
            dirRobot = 'N';
            break;
        }
        case 'S':
        {
            posRobot[0] +=1;
            dirRobot = 'S';
            break;
        }

        case 'W':
        {
            posRobot[1] -=1;
            dirRobot = 'W';
            break;
        }
        case 'E':
        {
            posRobot[1] +=1;
            dirRobot = 'E';
            break;
        }
        }
        state[posRobot[0]][posRobot[1]] = dirRobot;

    }
    else
    {
    }

}

// Moving Back based on last orientation (NSWE)
void Maze::move_back()
{
    if(can_move_back())
    {
        state[posRobot[0]][posRobot[1]] = '.';
        switch(dirRobot)
        {
        case 'N':
        {
            posRobot[0] +=1;
            dirRobot = 'S';
            break;
        }
        case 'S':
        {
            posRobot[0] -=1;
            dirRobot = 'N';
            break;
        }
        case 'W':
        {
            posRobot[1] +=1;
            dirRobot = 'E';
            break;
        }
        case 'E':
        {
            posRobot[1] -=1;
            dirRobot = 'W';
            break;
        }
        }
        state[posRobot[0]][posRobot[1]] = dirRobot;
    }
    else
    {
    }
}

// Check if the maze is solved by comparing the position of target and robot
bool Maze::is_solved()
{
    return (posRobot[0] == posTarget[0] && posRobot[1] == posTarget[1]) ? true : false;
}
