#include <iostream>
#include <string>

using namespace std;

#include "batallapokemon.cpp" 

int main()
{
    cargarpokemones();
    pedirnombresBatalla();

    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << "|          BATALLA POKEMON            |" << endl;
    cout << "---------------------------------------" << endl;

    seleccionarEquipoBatalla(equipoJugador1, player1_nombre);
    seleccionarEquipoBatalla(equipoJugador2, player2_nombre);

    batallaFinal(equipoJugador1, equipoJugador2);

    return 0;
}