#include <iostream>
#include <string>
#include "pokemones.cpp"

using namespace std;
string player1_nombre, player2_nombre;
void pedirnombres()
{
    
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> player1_nombre;
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> player2_nombre;
        
}
void mostrarpokemones()
{

    cout<<"Pokemones disponibles: "<<endl;

    for (int i = 0; i < 30; i++)
{
        cout << i << ". " << pokemonesDisponibles[i].nombre << " (Tipo: " << pokemonesDisponibles[i].tipo << ", Vida: " << pokemonesDisponibles[i].vidaMax << ", Ataque: " << pokemonesDisponibles[i].ataqueBase << ")" << endl;
}

}

void seleccionarEquipo(Pokemon equipo[], string nombreJugador)
{
    int opcion;
    char continuar;

    cout << endl << "Turno de " << nombreJugador << ": selecciona tu equipo." << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << endl << "Turno de " << nombreJugador << endl;

        mostrarpokemones();

        cout << endl << nombreJugador << ", elige el Pokemon #" << i + 1 << ": ";
        cin >> opcion;

        while (cin.fail() || opcion < 1 || opcion > 30)
        {
            cin.clear();
            cin.ignore(100, '\n');

            cout << "Opcion invalida " << nombreJugador
                 << "elige un numero del 1 al 30: ";
            cin >> opcion;
        }

        equipo[i] = pokemonesDisponibles[opcion - 1];

        cout << endl << nombreJugador << " guardo a "
             << equipo[i].nombre << " en su equipo." << endl;

        if (i < 5)
        {
            cout << "Escribe s para continuar: ";
            cin >> continuar;

            while (continuar != 's' && continuar != 'S')
            {
                cout << "Escribe s para continuar: ";
                cin >> continuar;
            }
        }
    }
}





//funcion de prueba para mostrar los pokemones disponibles y sus atributos
int main()
{

    cargarpokemones();

    pedirnombres();

    cout << "Bienvenido " << player1_nombre << " y " << player2_nombre << " a la batalla Pokemon!" << endl;

    mostrarpokemones();

    seleccionarEquipo(equipoJugador1, player1_nombre);

    seleccionarEquipo(equipoJugador2, player2_nombre);

    return 0;
}
