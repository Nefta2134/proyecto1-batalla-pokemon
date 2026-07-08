bool cargarPartida(Pokemon equipo1[], Pokemon equipo2[], int &indiceJ1, int &indiceJ2)
{
    ifstream archivo("partida.txt");

    if (!archivo)
    {
        cout << "No existe una partida guardada." << endl;
        return false;
    }

    getline(archivo, player1_nombre);
    getline(archivo, player2_nombre);

    archivo >> indiceJ1;
    archivo >> indiceJ2;
    archivo.ignore();

    string nombre;

    // Equipo jugador 1
    for (int i = 0; i < 6; i++)
    {
        getline(archivo, nombre);

        for (int j = 0; j < 30; j++)
        {
            if (pokemonesDisponibles[j].nombre == nombre)
            {
                equipo1[i] = pokemonesDisponibles[j];
                break;
            }
        }

        archivo >> equipo1[i].vidaActual;

        for (int j = 0; j < 4; j++)
            archivo >> equipo1[i].ataques[j].ppActual;

        archivo.ignore();
    }

    // Equipo jugador 2
    for (int i = 0; i < 6; i++)
    {
        getline(archivo, nombre);

        for (int j = 0; j < 30; j++)
        {
            if (pokemonesDisponibles[j].nombre == nombre)
            {
                equipo2[i] = pokemonesDisponibles[j];
                break;
            }
        }

        archivo >> equipo2[i].vidaActual;

        for (int j = 0; j < 4; j++)
            archivo >> equipo2[i].ataques[j].ppActual;

        archivo.ignore();
    }

    archivo.close();

    cout << "\nPartida cargada correctamente.\n";

    return true;
}