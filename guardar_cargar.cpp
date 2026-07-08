// guardar_cargar.cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const string ARCHIVO_PARTIDA = "partida_guardada.txt";

void guardarPokemon(ofstream &archivo, Pokemon p)
{
    archivo << p.nombre << endl;
    archivo << p.tipo << endl;
    archivo << p.vidaMax << endl;
    archivo << p.vidaActual << endl;
    archivo << p.ataqueBase << endl;

    for (int i = 0; i < 4; i++)
    {
        archivo << p.ataques[i].nombre << endl;
        archivo << p.ataques[i].tipo << endl;
        archivo << p.ataques[i].danoBase << endl;
        archivo << p.ataques[i].ppActual << endl;
        archivo << p.ataques[i].ppMax << endl;
    }
}

void cargarPokemon(ifstream &archivo, Pokemon &p)
{
    getline(archivo, p.nombre);
    getline(archivo, p.tipo);

    archivo >> p.vidaMax;
    archivo >> p.vidaActual;
    archivo >> p.ataqueBase;
    archivo.ignore(10000, '\n');

    for (int i = 0; i < 4; i++)
    {
        getline(archivo, p.ataques[i].nombre);
        getline(archivo, p.ataques[i].tipo);

        archivo >> p.ataques[i].danoBase;
        archivo >> p.ataques[i].ppActual;
        archivo >> p.ataques[i].ppMax;
        archivo.ignore(10000, '\n');
    }
}

void guardarPartida(string jugador1, string jugador2, Pokemon equipo1[], Pokemon equipo2[], int indiceJ1, int indiceJ2)
{
    ofstream archivo(ARCHIVO_PARTIDA);

    if (!archivo.is_open())
    {
        cout << "Error: no se pudo guardar la partida." << endl;
        return;
    }

    archivo << jugador1 << endl;
    archivo << jugador2 << endl;
    archivo << indiceJ1 << endl;
    archivo << indiceJ2 << endl;

    for (int i = 0; i < 6; i++)
    {
        guardarPokemon(archivo, equipo1[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        guardarPokemon(archivo, equipo2[i]);
    }

    archivo.close();

    cout << "Partida guardada correctamente." << endl;
}

bool cargarPartida(string &jugador1, string &jugador2, Pokemon equipo1[], Pokemon equipo2[], int &indiceJ1, int &indiceJ2)
{
    ifstream archivo(ARCHIVO_PARTIDA);

    if (!archivo.is_open())
    {
        cout << "No hay partida guardada." << endl;
        return false;
    }

    getline(archivo, jugador1);
    getline(archivo, jugador2);

    archivo >> indiceJ1;
    archivo >> indiceJ2;
    archivo.ignore(10000, '\n');

    for (int i = 0; i < 6; i++)
    {
        cargarPokemon(archivo, equipo1[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        cargarPokemon(archivo, equipo2[i]);
    }

    archivo.close();

    cout << "Partida cargada correctamente." << endl;
    return true;
}