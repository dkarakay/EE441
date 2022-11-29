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
    ifstream input_file; /* input file stream */
    input_file.open ("input_maze.txt");
    input_file >> nrow >> ncol; /* read the size from file */

    state = new char*[nrow];

    for(int i = 0; i < nrow; ++i)
        state[i] = new char[ncol];

    for(int i=0; i<nrow; ++i)
    {
        for(int j=0; j<ncol; ++j)
        {
            input_file >> state[i][j];

            if(state[i][j] != '.' && state[i][j] != '#' && state[i][j] != 'T')
            {
                posRobot[0] = i; // Row posY
                posRobot[1] = j; // Col posX
                dirRobot =  state[i][j]; // Direction
            }


            if(state[i][j] == 'T')
            {
                posTarget[0] = i; // Row posY
                posTarget[1] = j; // Col posX
            }

        }
    }
    //cout << "Row: " <<nrow << endl;
    //cout << "Column: " << ncol << endl;
    input_file.close();

}

Maze::Maze(const Maze& maz)
{
    state = maz.state;
    nrow  = maz.nrow;
    ncol  = maz.ncol;
    dirRobot = maz.dirRobot;
}

void Maze::print_state()
{
    //cout << "Dir Robot: " << dirRobot << endl;
    //cout << "Pos Robot: " << posRobot[0] << " " << posRobot[1] << endl;
    //cout << "Pos Target: " << posTarget[0] << " " << posTarget[1] << endl;
    //cout << endl;
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

// Moving Left based on last direction
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
       // cout << "Moving left"<<endl;;
       // print_state();

    }
    else
    {
       // cout << "Cannot move left"<< endl;;
    }

}

// Moving Right based on last direction
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
        //cout << "Moving right"<< endl;
        //print_state();

    }
    else
    {
        //cout << "Cannot move right"<< endl;
    }

}

// Moving Forward based on last direction
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
        //cout << "Moving forward"<< endl;
        //print_state();

    }
    else
    {
        //cout << "Cannot move forward"<< endl;
    }

}


// Moving Back based on last direction
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
        //cout << "Moving back"<< endl;
        //print_state();
    }
    else
    {
        //cout << "Cannot move back"<< endl;
    }
}

bool Maze::is_solved()
{
    return (posRobot[0] == posTarget[0] && posRobot[1] == posTarget[1]) ? true : false;
}
