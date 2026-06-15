#include <iostream>
#include <string>

using namespace std;

struct Ataque
{
    string nombre;
    int danoBase;
    int ppMax;
    int ppActual;
    string tipo;
};

struct Pokemon
{
    string nombre;
    int vidaMax;
    int vidaActul;
    int velocidad;
    int ataqueBase;
    string tipo;
    Ataque ataques[4];
};

Pokemon pokemonesDisponibles[30];
Pokemon equipoJugador1[6], equipoJugador2[6];

int player1_vida, player2_vida, dano;
string player1_nombre, player2_nombre;
int opcionMenu, idPokemon, i;

int indiceJ1 = 0, indiceJ2 = 0;
int opcionAtaque;
float multiplicador;

int pokemonVivosJ1 = 6, pokemonVivosJ2 = 6;
bool peleaActiva = true;

void cargarpokemones()
{

    pokemonesDisponibles[0] = {"Bulbasaur", 160, 160, 45, 49, "Planta"};
    pokemonesDisponibles[1] = {"Ivysaur", 180, 180, 60, 62, "Planta"};
    pokemonesDisponibles[2] = {"Venusaur", 210, 210, 80, 82, "Planta"};
    pokemonesDisponibles[3] = {"Chikorita", 155, 155, 45, 49, "Planta"};
    pokemonesDisponibles[4] = {"Bayleef", 175, 175, 60, 62, "Planta"};
    pokemonesDisponibles[5] = {"Meganium", 215, 215, 80, 82, "Planta"};
    pokemonesDisponibles[6] = {"Treecko", 150, 150, 70, 45, "Planta"};
    pokemonesDisponibles[7] = {"Grovyle", 170, 170, 95, 65, "Planta"};
    pokemonesDisponibles[8] = {"Sceptile", 200, 200, 120, 85, "Planta"};
    pokemonesDisponibles[9] = {"Turtwig", 165, 165, 31, 55, "Planta"};

    pokemonesDisponibles[10] = {"Charmander", 149, 149, 65, 52, "Fuego"};
    pokemonesDisponibles[11] = {"Charmeleon", 169, 169, 80, 64, "Fuego"};
    pokemonesDisponibles[12] = {"Charizard", 208, 208, 100, 84, "Fuego"};
    pokemonesDisponibles[13] = {"Cyndaquil", 149, 149, 65, 52, "Fuego"};
    pokemonesDisponibles[14] = {"Quilava", 169, 169, 80, 64, "Fuego"};
    pokemonesDisponibles[15] = {"Typhlosion", 208, 208, 100, 84, "Fuego"};
    pokemonesDisponibles[16] = {"Torchic", 155, 155, 45, 60, "Fuego"};
    pokemonesDisponibles[17] = {"Combusken", 175, 175, 55, 85, "Fuego"};
    pokemonesDisponibles[18] = {"Blaziken", 210, 210, 80, 120, "Fuego"};
    pokemonesDisponibles[19] = {"Vulpix", 148, 148, 65, 41, "Fuego"};

    pokemonesDisponibles[20] = {"Squirtle", 154, 154, 43, 48, "Agua"};
    pokemonesDisponibles[21] = {"Wartortle", 179, 179, 58, 63, "Agua"};
    pokemonesDisponibles[22] = {"Blastoise", 209, 209, 78, 83, "Agua"};
    pokemonesDisponibles[23] = {"Totodile", 160, 160, 43, 65, "Agua"};
    pokemonesDisponibles[24] = {"Croconaw", 185, 185, 58, 80, "Agua"};
    pokemonesDisponibles[25] = {"Feraligatr", 215, 215, 78, 105, "Agua"};
    pokemonesDisponibles[26] = {"Mudkip", 160, 160, 40, 70, "Agua"};
    pokemonesDisponibles[27] = {"Marshtomp", 190, 190, 50, 85, "Agua"};
    pokemonesDisponibles[28] = {"Swampert", 230, 230, 60, 110, "Agua"};
    pokemonesDisponibles[29] = {"Psyduck", 160, 160, 55, 52, "Agua"};


}
