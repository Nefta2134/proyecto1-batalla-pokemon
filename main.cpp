#include <iostream>
#include <string>
#include<pokemones.cpp>

 
using namespace std;
void cargarpokemones();
int main()
{
    cargarpokemones();

    cout << pokemonesDisponibles[0].nombre << endl;  
    cout << pokemonesDisponibles[0].vidaMax << endl; 
    cout << pokemonesDisponibles[0].tipo << endl;    

    return 0;
}
