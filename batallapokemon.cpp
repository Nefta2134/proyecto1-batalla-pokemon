#include <iostream>
#include <string>
using namespace std;

#include "pokemones.cpp"
#include "ataques.cpp"

string player1_nombre, player2_nombre;

void pedirnombresBatalla() 
{
    cout << "Ingresa el nombre del jugador numero 1: ";
    cin >> player1_nombre;

    cout << "Ingresa el nombre del jugador numero 2: ";
    cin >> player2_nombre;
}

void mostrarpokemonesBatalla()
{
    cout << endl;
    cout << "-----------------------" << endl;
    cout << "| POKEMONES A ESCOGER |" << endl;
    cout << "-----------------------" << endl;

    for (int i = 0; i < 30; i++)
    {
        cout << i + 1 << ". "
             << pokemonesDisponibles[i].nombre
             << " | Tipo: " << pokemonesDisponibles[i].tipo
             << " | Vida: " << pokemonesDisponibles[i].vidaMax
             << " | Ataque: " << pokemonesDisponibles[i].ataqueBase
             << endl;
    }
}

void seleccionarEquipoBatalla(Pokemon equipo[], string nombreJugador)
{
    int opcion;

    cout << endl;
    cout << "-------------------------------------" << endl;
    cout << "Es turno de: " << nombreJugador << endl;
    cout << "Elige 6 Pokemones para tu equipo" << endl;
    cout << "-------------------------------------" << endl;

     mostrarpokemonesBatalla();
    for (int i = 0; i < 6; i++)
    {
       

        cout << endl;
        cout << nombreJugador << ", elige tu Pokemon numero : " << i + 1 << ": ";
        cin >> opcion;

        while (opcion < 1 || opcion > 30)
        {
            cout << "Opcion invalida. Elige un numero del 1 al 30: ";
            cin >> opcion;
        }

        equipo[i] = pokemonesDisponibles[opcion - 1];

        cout << endl;
        cout << nombreJugador << " agrego a " << equipo[i].nombre << " a su equipo." << endl;
    }
}

void mostrarAtaquesBatalla(Pokemon atacante, Pokemon defensor)
{
    cout << endl;
    cout << "Ataques de " << atacante.nombre << ":" << endl;

    for (int i = 0; i < 4; i++)
    {
        float multiplicador = calcularMultiplicador(atacante.ataques[i].tipo, defensor.tipo);
        int dano = atacante.ataques[i].danoBase * multiplicador;

        cout << i + 1 << ". "
             << atacante.ataques[i].nombre
             << " | Tipo: " << atacante.ataques[i].tipo
             << " | Dano: " << dano
             << " | PP: " << atacante.ataques[i].ppActual
             << "/"
             << atacante.ataques[i].ppMax;

        if (multiplicador == 2.0)
        {
            cout << " | Super efectivo";
        }
        else if (multiplicador == 0.5)
        {
            cout << " | Poco efectivo";
        }
        else
        {
            cout << " | Efecto normal";
        }

        cout << endl;
    }
}

int elegirAtaqueBatalla(Pokemon atacante, Pokemon defensor, string nombreJugador)
{
    int opcionAtaque;

    mostrarAtaquesBatalla(atacante, defensor);

    cout << endl;
    cout << nombreJugador << ", selecciona un ataque: ";
    cin >> opcionAtaque;

    while (opcionAtaque < 1 || opcionAtaque > 4 || atacante.ataques[opcionAtaque - 1].ppActual <= 0)
    {
        if (opcionAtaque < 1 || opcionAtaque > 4)
        {
            cout << "Error: elige una opcion del 1 al 4." << endl;
        }
        else if (atacante.ataques[opcionAtaque - 1].ppActual <= 0)
        {
            cout << "Error: ese ataque ya no tiene PP." << endl;
        }

        cout << "Vuelve a seleccionar un ataque: ";
        cin >> opcionAtaque;
    }

    return opcionAtaque - 1;
}

void realizarAtaqueBatalla(Pokemon &atacante, Pokemon &defensor, int indiceAtaque)
{
    Ataque &ataque = atacante.ataques[indiceAtaque];

    float multiplicador = calcularMultiplicador(ataque.tipo, defensor.tipo);
    int dano = ataque.danoBase * multiplicador;

    ataque.ppActual--;

    defensor.vidaActual -= dano;

    if (defensor.vidaActual < 0)
    {
        defensor.vidaActual = 0;
    }

    cout << endl;
    cout << atacante.nombre << " uso " << ataque.nombre << endl;
    cout << "El ataque causo " << dano << " de dano." << endl;

    if (multiplicador == 2.0)
    {
        cout << "Fue super efectivo." << endl;
    }
    else if (multiplicador == 0.5)
    {
        cout << "No fue muy efectivo." << endl;
    }
    else
    {
        cout << "Fue un ataque normal." << endl;
    }

    cout << defensor.nombre << " queda con " << defensor.vidaActual << " de vida." << endl;
}

void esperarContinuar()
{
    char continuar;

    cout << endl;
    cout << "Escribe s para continuar: ";
    cin >> continuar;

    while (continuar != 's' && continuar != 'S')
    {
        cout << "Escribe s para continuar: ";
        cin >> continuar;
    }
}

void batallaFinal(Pokemon equipo1[], Pokemon equipo2[])
{
    int indiceJ1 = 0;
    int indiceJ2 = 0;

    while (indiceJ1 < 6 && indiceJ2 < 6)
    {
        Pokemon &p1 = equipo1[indiceJ1];
        Pokemon &p2 = equipo2[indiceJ2];

        cout << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << player1_nombre << ": " << p1.nombre << " VS " << player2_nombre << ": " << p2.nombre << endl;
        cout << "------------------------------------------------------------------------------------" << endl;

        while (p1.vidaActual > 0 && p2.vidaActual > 0)
        {
            cout << endl;
            cout << "Vida de " << p1.nombre << ": " << p1.vidaActual << "/" << p1.vidaMax << endl;
            cout << "Vida de " << p2.nombre << ": " << p2.vidaActual << "/" << p2.vidaMax << endl;

            cout << endl;
            cout << "Turno de " << player1_nombre << endl;

            int ataqueJ1 = elegirAtaqueBatalla(p1, p2, player1_nombre);
            realizarAtaqueBatalla(p1, p2, ataqueJ1);

            if (p2.vidaActual <= 0)
            {
                cout << endl;
                cout << p2.nombre << " ha sido derrotado." << endl;
                indiceJ2++;
                break;
            }

            cout << endl;
            cout << "Turno de " << player2_nombre << endl;

            int ataqueJ2 = elegirAtaqueBatalla(p2, p1, player2_nombre);
            realizarAtaqueBatalla(p2, p1, ataqueJ2);

            if (p1.vidaActual <= 0)
            {
                cout << endl;
                cout << p1.nombre << " ha sido derrotado." << endl;
                indiceJ1++;
                break;
            }
        }
    }

    cout << endl;
    cout << "-------------------" << endl;
    cout << "|FIN DE LA BATALLA|" << endl;
    cout << "-------------------" << endl;

    if (indiceJ1 >= 6)
    {
        cout << "Gana " << player2_nombre << "!" << endl;
    }
    else
    {
        cout << "Gana " << player1_nombre << "!" << endl;
    }
}