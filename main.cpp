#include <iostream>
#include <string>

using namespace std;

#include "batallapokemon.cpp"

int main()
{
    int opcion;
    int indiceJ1 = 0;
    int indiceJ2 = 0;

    cargarpokemones();

    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << "|          BATALLA POKEMON            |" << endl;
    cout << "---------------------------------------" << endl;

    cout << endl;
    cout << "1. Nueva partida" << endl;
    cout << "2. Cargar partida" << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 2)
    {
        cout << "Opcion invalida. Elige 1 o 2: ";
        cin >> opcion;
    }

    if (opcion == 2)
    {
        if (cargarPartida(player1_nombre, player2_nombre, equipoJugador1, equipoJugador2, indiceJ1, indiceJ2))
        {
            batallaFinal(equipoJugador1, equipoJugador2, indiceJ1, indiceJ2);
        }
        else
        {
            cout << endl;
            cout << "Se iniciara una nueva partida." << endl;

            pedirnombresBatalla();

            seleccionarEquipoBatalla(equipoJugador1, player1_nombre);
            seleccionarEquipoBatalla(equipoJugador2, player2_nombre);

            batallaFinal(equipoJugador1, equipoJugador2);
        }
    }
    else
    {
        pedirnombresBatalla();

        seleccionarEquipoBatalla(equipoJugador1, player1_nombre);
        seleccionarEquipoBatalla(equipoJugador2, player2_nombre);

        batallaFinal(equipoJugador1, equipoJugador2);
    }

    return 0;
}