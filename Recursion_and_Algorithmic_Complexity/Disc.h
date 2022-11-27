#pragma once

using namespace std;

class Disc
{
    private:
        // diameter of the disc
        int diameter;

    public:
        // the constructor for the class
        Disc(int diam = 0);
        // get the diameter of the disc
        int get_diameter();
        // get the number of disc
        void set_diameter(int diam);
};

// set the discs using diameters, constructor for the class
Disc::Disc(int diam){
    diameter = diam;
}

// get the diameter of the disc
int Disc::get_diameter(){
    return diameter;
}

// set the diameter of the disc (if required)
void Disc::set_diameter(int diam){
    diameter = diam;
}


