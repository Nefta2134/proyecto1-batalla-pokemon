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
    int vidaActual;
    int velocidad;
    int ataqueBase;
    string tipo;
    Ataque ataques[4];
};

Pokemon pokemonesDisponibles[30];
Pokemon equipoJugador1[6], equipoJugador2[6];

void cargarpokemones()
{
    pokemonesDisponibles[0] = {"Bulbasaur", 160, 160, 45, 49, "Planta"};
    pokemonesDisponibles[0].ataques[0] = {"Placaje", 40, 35, 35, "Normal"};
    pokemonesDisponibles[0].ataques[1] = {"Latigo Cepa", 45, 25, 25, "Planta"};
    pokemonesDisponibles[0].ataques[2] = {"Hoja Afilada", 55, 15, 15, "Planta"};
    pokemonesDisponibles[0].ataques[3] = {"Rayo Solar", 90, 5, 5, "Planta"};

    pokemonesDisponibles[1] = {"Ivysaur", 180, 180, 60, 62, "Planta"};
    pokemonesDisponibles[1].ataques[0] = {"Placaje", 40, 35, 35, "Planta"};
    pokemonesDisponibles[1].ataques[1] = {"Latigo Cepa", 45, 25, 25, "Planta"};
    pokemonesDisponibles[1].ataques[2] = {"Hoja Afilada", 55, 25, 25, "Planta"};
    pokemonesDisponibles[1].ataques[3] = {"Rayo Solar", 120, 5, 5, "Planta"};

    pokemonesDisponibles[2] = {"Venusaur", 210, 210, 80, 82, "Planta"};
    pokemonesDisponibles[2].ataques[0] = {"Placaje", 40, 35, 35, "Planta"};
    pokemonesDisponibles[2].ataques[1] = {"Bomba Germen", 80, 15, 15, "Planta"};
    pokemonesDisponibles[2].ataques[2] = {"Rayo Solar", 120, 5, 5, "Planta"};
    pokemonesDisponibles[2].ataques[3] = {"Planta Feroz", 150, 5, 5, "Planta"};

    pokemonesDisponibles[3] = {"Chikorita", 155, 155, 45, 49, "Planta"};
    pokemonesDisponibles[3].ataques[0] = {"Placaje", 40, 35, 35, "Planta"};
    pokemonesDisponibles[3].ataques[1] = {"Hoja Afilada", 55, 25, 25, "Planta"};
    pokemonesDisponibles[3].ataques[2] = {"Hoja Magica", 60, 20, 20, "Planta"};
    pokemonesDisponibles[3].ataques[3] = {"Gigadrenado", 75, 5, 5, "Planta"};

    pokemonesDisponibles[4] = {"Bayleef", 175, 175, 60, 62, "Planta"};
    pokemonesDisponibles[4].ataques[0] = {"Placaje", 40, 35, 35, "Planta"};
    pokemonesDisponibles[4].ataques[1] = {"Hoja Afilada", 55, 25, 25, "Planta"};
    pokemonesDisponibles[4].ataques[2] = {"Hoja Magica", 60, 20, 20, "Planta"};
    pokemonesDisponibles[4].ataques[3] = {"Golpe Cuerpo", 85, 5, 5, "Planta"};

    pokemonesDisponibles[5] = {"Meganium", 215, 215, 80, 82, "Planta"};
    pokemonesDisponibles[5].ataques[0] = {"Hoja Afilada", 55, 25, 25, "Planta"};
    pokemonesDisponibles[5].ataques[1] = {"Golpe Cuerpo", 85, 5, 5, "Planta"};
    pokemonesDisponibles[5].ataques[2] = {"Tormenta Floral", 90, 5, 5, "Planta"};
    pokemonesDisponibles[5].ataques[3] = {"Planta Feroz", 150, 5, 5, "Planta"};

    pokemonesDisponibles[6] = {"Treecko", 150, 150, 70, 45, "Planta"};
    pokemonesDisponibles[6].ataques[0] = {"Destructor", 40, 35, 35, "Planta"};
    pokemonesDisponibles[6].ataques[1] = {"Absorber", 20, 25, 25, "Planta"};
    pokemonesDisponibles[6].ataques[2] = {"Ataque Rapido", 40, 30, 30, "Planta"};
    pokemonesDisponibles[6].ataques[3] = {"Gigadrenado", 75, 5, 5, "Planta"};

    pokemonesDisponibles[7] = {"Grovyle", 170, 170, 95, 65, "Planta"};
    pokemonesDisponibles[7].ataques[0] = {"Ataque Rapido", 40, 30, 30, "Planta"};
    pokemonesDisponibles[7].ataques[1] = {"Megaagotar", 40, 15, 15, "Planta"};
    pokemonesDisponibles[7].ataques[2] = {"Gigadrenado", 75, 5, 5, "Planta"};
    pokemonesDisponibles[7].ataques[3] = {"Portazo", 80, 5, 5, "Planta"};

    pokemonesDisponibles[8] = {"Sceptile", 200, 200, 120, 85, "Planta"};
    pokemonesDisponibles[8].ataques[0] = {"Ataque Rapido", 40, 30, 30, "Planta"};
    pokemonesDisponibles[8].ataques[1] = {"Hoja Aguda", 90, 15, 15, "Planta"};
    pokemonesDisponibles[8].ataques[2] = {"Gigadrenado", 75, 5, 5, "Planta"};
    pokemonesDisponibles[8].ataques[3] = {"Planta Feroz", 150, 5, 5, "Planta"};

    pokemonesDisponibles[9] = {"Turtwig", 165, 165, 31, 55, "Planta"};
    pokemonesDisponibles[9].ataques[0] = {"Placaje", 40, 35, 35, "Planta"};
    pokemonesDisponibles[9].ataques[1] = {"Absorber", 20, 25, 25, "Planta"};
    pokemonesDisponibles[9].ataques[2] = {"Hoja Afilada", 55, 25, 25, "Planta"};
    pokemonesDisponibles[9].ataques[3] = {"Mordisco", 60, 25, 25, "Planta"};

    pokemonesDisponibles[10] = {"Charmander", 149, 149, 65, 52, "Fuego"};
    pokemonesDisponibles[10].ataques[0] = {"Aranazo", 40, 35, 35, "Fuego"};
    pokemonesDisponibles[10].ataques[1] = {"Ascuas", 40, 25, 25, "Fuego"};
    pokemonesDisponibles[10].ataques[2] = {"Colmillo Igneo", 65, 15, 15, "Fuego"};
    pokemonesDisponibles[10].ataques[3] = {"Lanzallamas", 90, 15, 15, "Fuego"};

    pokemonesDisponibles[11] = {"Charmeleon", 169, 169, 80, 64, "Fuego"};
    pokemonesDisponibles[11].ataques[0] = {"Aranazo", 40, 35, 35, "Fuego"};
    pokemonesDisponibles[11].ataques[1] = {"Ascuas", 40, 25, 25, "Fuego"};
    pokemonesDisponibles[11].ataques[2] = {"Cuchillada", 70, 20, 20, "Fuego"};
    pokemonesDisponibles[11].ataques[3] = {"Lanzallamas", 90, 15, 15, "Fuego"};

    pokemonesDisponibles[12] = {"Charizard", 208, 208, 100, 84, "Fuego"};
    pokemonesDisponibles[12].ataques[0] = {"Cuchillada", 70, 20, 20, "Fuego"};
    pokemonesDisponibles[12].ataques[1] = {"Giro Fuego", 35, 15, 15, "Fuego"};
    pokemonesDisponibles[12].ataques[2] = {"Lanzallamas", 90, 15, 15, "Fuego"};
    pokemonesDisponibles[12].ataques[3] = {"Anillo Igneo", 110, 5, 5, "Fuego"};

    pokemonesDisponibles[13] = {"Cyndaquil", 149, 149, 65, 52, "Fuego"};
    pokemonesDisponibles[13].ataques[0] = {"Placaje", 40, 35, 35, "Fuego"};
    pokemonesDisponibles[13].ataques[1] = {"Ascuas", 40, 25, 25, "Fuego"};
    pokemonesDisponibles[13].ataques[2] = {"Ataque Rapido", 40, 30, 30, "Fuego"};
    pokemonesDisponibles[13].ataques[3] = {"Rueda Fuego", 60, 25, 25, "Fuego"};

    pokemonesDisponibles[14] = {"Quilava", 169, 169, 80, 64, "Fuego"};
    pokemonesDisponibles[14].ataques[0] = {"Ataque Rapido", 40, 30, 30, "Fuego"};
    pokemonesDisponibles[14].ataques[1] = {"Ascuas", 40, 25, 25, "Fuego"};
    pokemonesDisponibles[14].ataques[2] = {"Rueda Fuego", 60, 25, 25, "Fuego"};
    pokemonesDisponibles[14].ataques[3] = {"Lanzallamas", 90, 15, 15, "Fuego"};

    pokemonesDisponibles[15] = {"Typhlosion", 208, 208, 100, 84, "Fuego"};
    pokemonesDisponibles[15].ataques[0] = {"Ataque Rapido", 40, 30, 30, "Fuego"};
    pokemonesDisponibles[15].ataques[1] = {"Rueda Fuego", 60, 25, 25, "Fuego"};
    pokemonesDisponibles[15].ataques[2] = {"Lanzallamas", 90, 15, 15, "Fuego"};
    pokemonesDisponibles[15].ataques[3] = {"Anillo Igneo", 100, 5, 5, "Fuego"};

    pokemonesDisponibles[16] = {"Torchic", 155, 155, 45, 60, "Fuego"};
    pokemonesDisponibles[16].ataques[0] = {"Aranazo", 40, 35, 35, "Fuego"};
    pokemonesDisponibles[16].ataques[1] = {"Ascuas", 40, 25, 25, "Fuego"};
    pokemonesDisponibles[16].ataques[2] = {"Picotazo", 35, 35, 35, "Fuego"};
    pokemonesDisponibles[16].ataques[3] = {"Doble Patada", 30, 30, 30, "Fuego"};

    pokemonesDisponibles[17] = {"Combusken", 175, 175, 55, 85, "Fuego"};
    pokemonesDisponibles[17].ataques[0] = {"Doble Patada", 30, 30, 30, "Fuego"};
    pokemonesDisponibles[17].ataques[1] = {"Ascuas", 40, 25, 25, "Fuego"};
    pokemonesDisponibles[17].ataques[2] = {"Nitrocarga", 50, 20, 20, "Fuego"};
    pokemonesDisponibles[17].ataques[3] = {"Gancho Alto", 85, 15, 15, "Fuego"};

    pokemonesDisponibles[18] = {"Blaziken", 210, 210, 80, 120, "Fuego"};
    pokemonesDisponibles[18].ataques[0] = {"Doble Patada", 30, 30, 30, "Fuego"};
    pokemonesDisponibles[18].ataques[1] = {"Patada Ignea", 85, 10, 10, "Fuego"};
    pokemonesDisponibles[18].ataques[2] = {"Lanzallamas", 90, 15, 15, "Fuego"};
    pokemonesDisponibles[18].ataques[3] = {"Anillo Igneo", 100, 5, 5, "Fuego"};

    pokemonesDisponibles[19] = {"Vulpix", 148, 148, 65, 41, "Fuego"};
    pokemonesDisponibles[19].ataques[0] = {"Ataque Rapido", 40, 30, 30, "Fuego"};
    pokemonesDisponibles[19].ataques[1] = {"Ascuas", 40, 25, 25, "Fuego"};
    pokemonesDisponibles[19].ataques[2] = {"Nitrocarga", 50, 20, 20, "Fuego"};
    pokemonesDisponibles[19].ataques[3] = {"Lanzallamas", 90, 15, 15, "Fuego"};

    pokemonesDisponibles[20] = {"Squirtle", 154, 154, 43, 48, "Agua"};
    pokemonesDisponibles[20].ataques[0] = {"Placaje", 40, 35, 35, "Agua"};
    pokemonesDisponibles[20].ataques[1] = {"Pistola Agua", 40, 25, 25, "Agua"};
    pokemonesDisponibles[20].ataques[2] = {"Mordisco", 60, 25, 25, "Agua"};
    pokemonesDisponibles[20].ataques[3] = {"Hidrobomba", 100, 5, 5, "Agua"};

    pokemonesDisponibles[21] = {"Wartortle", 179, 179, 58, 63, "Agua"};
    pokemonesDisponibles[21].ataques[0] = {"Placaje", 40, 35, 35, "Agua"};
    pokemonesDisponibles[21].ataques[1] = {"Pistola Agua", 40, 25, 25, "Agua"};
    pokemonesDisponibles[21].ataques[2] = {"Mordisco", 60, 25, 25, "Agua"};
    pokemonesDisponibles[21].ataques[3] = {"Hidropulso", 60, 20, 20, "Agua"};

    pokemonesDisponibles[22] = {"Blastoise", 209, 209, 78, 83, "Agua"};
    pokemonesDisponibles[22].ataques[0] = {"Pistola Agua", 40, 25, 25, "Agua"};
    pokemonesDisponibles[22].ataques[1] = {"Hidropulso", 60, 20, 20, "Agua"};
    pokemonesDisponibles[22].ataques[2] = {"Cabezazo", 130, 10, 10, "Agua"};
    pokemonesDisponibles[22].ataques[3] = {"Hidrocanon", 100, 5, 5, "Agua"};

    pokemonesDisponibles[23] = {"Totodile", 160, 160, 43, 65, "Agua"};
    pokemonesDisponibles[23].ataques[0] = {"Aranazo", 40, 35, 35, "Agua"};
    pokemonesDisponibles[23].ataques[1] = {"Pistola Agua", 40, 25, 25, "Agua"};
    pokemonesDisponibles[23].ataques[2] = {"Mordisco", 60, 25, 25, "Agua"};
    pokemonesDisponibles[23].ataques[3] = {"Acua Cola", 90, 10, 10, "Agua"};

    pokemonesDisponibles[24] = {"Croconaw", 185, 185, 58, 80, "Agua"};
    pokemonesDisponibles[24].ataques[0] = {"Aranazo", 40, 35, 35, "Agua"};
    pokemonesDisponibles[24].ataques[1] = {"Pistola Agua", 40, 25, 25, "Agua"};
    pokemonesDisponibles[24].ataques[2] = {"Mordisco", 60, 25, 25, "Agua"};
    pokemonesDisponibles[24].ataques[3] = {"Acua Cola", 90, 10, 10, "Agua"};

    pokemonesDisponibles[25] = {"Feraligatr", 215, 215, 78, 105, "Agua"};
    pokemonesDisponibles[25].ataques[0] = {"Cuchillada", 70, 20, 20, "Agua"};
    pokemonesDisponibles[25].ataques[1] = {"Triturar", 80, 15, 15, "Agua"};
    pokemonesDisponibles[25].ataques[2] = {"Acua Cola", 90, 10, 10, "Agua"};
    pokemonesDisponibles[25].ataques[3] = {"Hidrocanon", 100, 5, 5, "Agua"};

    pokemonesDisponibles[26] = {"Mudkip", 160, 160, 40, 70, "Agua"};
    pokemonesDisponibles[26].ataques[0] = {"Placaje", 40, 35, 35, "Agua"};
    pokemonesDisponibles[26].ataques[1] = {"Pistola Agua", 40, 25, 25, "Agua"};
    pokemonesDisponibles[26].ataques[2] = {"Disparo Lodo", 55, 15, 15, "Agua"};
    pokemonesDisponibles[26].ataques[3] = {"Hidropulso", 60, 20, 20, "Agua"};

    pokemonesDisponibles[27] = {"Marshtomp", 190, 190, 50, 85, "Agua"};
    pokemonesDisponibles[27].ataques[0] = {"Placaje", 40, 35, 35, "Agua"};
    pokemonesDisponibles[27].ataques[1] = {"Pistola Agua", 40, 25, 25, "Agua"};
    pokemonesDisponibles[27].ataques[2] = {"Disparo Lodo", 55, 15, 15, "Agua"};
    pokemonesDisponibles[27].ataques[3] = {"Agua Lodosa", 90, 10, 10, "Agua"};

    pokemonesDisponibles[28] = {"Swampert", 230, 230, 60, 110, "Agua"};
    pokemonesDisponibles[28].ataques[0] = {"Agua Lodosa", 90, 10, 10, "Agua"};
    pokemonesDisponibles[28].ataques[1] = {"Surf", 90, 15, 15, "Agua"};
    pokemonesDisponibles[28].ataques[2] = {"Terremoto", 100, 10, 10, "Agua"};
    pokemonesDisponibles[28].ataques[3] = {"Hidrocanon", 100, 5, 5, "Agua"};

    pokemonesDisponibles[29] = {"Psyduck", 160, 160, 55, 52, "Agua"};
    pokemonesDisponibles[29].ataques[0] = {"Aranazo", 40, 35, 35, "Agua"};
    pokemonesDisponibles[29].ataques[1] = {"Pistola Agua", 40, 25, 25, "Agua"};
    pokemonesDisponibles[29].ataques[2] = {"Confusion", 50, 25, 25, "Agua"};
    pokemonesDisponibles[29].ataques[3] = {"Hidrobomba", 110, 5, 5, "Agua"};
}