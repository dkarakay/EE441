# pragma once
using namespace std;

// Defining the private and public members of the Disc Class
class Discs
{
private:
    int m_diameter;
public:
    Discs(int diameter = 0);
    void Set_Diameter(int new_diameter);
    int Get_Diameter();
};

// Constructor of the Discs class
Discs::Discs(int diameter) {
    m_diameter = diameter;
}
// Function to change the diameter of a Disc object
void Discs::Set_Diameter(int new_diameter){
    m_diameter = new_diameter;
}

// Function that returns the diameter of the regarding Disc object
int Discs::Get_Diameter(){
    return m_diameter;
}
