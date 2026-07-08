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

    // Equipo del jugador 1
    for (int i = 0; i < 6; i++)
    {
        getline(archivo, equipo1[i].nombre);
        getline(archivo, equipo1[i].tipo);

        archivo >> equipo1[i].vidaMax;
        archivo >> equipo1[i].vidaActual;
        archivo >> equipo1[i].ataqueBase;
        archivo.ignore();

        for (int j = 0; j < 4; j++)
        {
            getline(archivo, equipo1[i].ataques[j].nombre);
            getline(archivo, equipo1[i].ataques[j].tipo);

            archivo >> equipo1[i].ataques[j].danoBase;
            archivo >> equipo1[i].ataques[j].ppMax;
            archivo >> equipo1[i].ataques[j].ppActual;
            archivo.ignore();
        }
    }

    // Equipo del jugador 2
    for (int i = 0; i < 6; i++)
    {
        getline(archivo, equipo2[i].nombre);
        getline(archivo, equipo2[i].tipo);

        archivo >> equipo2[i].vidaMax;
        archivo >> equipo2[i].vidaActual;
        archivo >> equipo2[i].ataqueBase;
        archivo.ignore();

        for (int j = 0; j < 4; j++)
        {
            getline(archivo, equipo2[i].ataques[j].nombre);
            getline(archivo, equipo2[i].ataques[j].tipo);

            archivo >> equipo2[i].ataques[j].danoBase;
            archivo >> equipo2[i].ataques[j].ppMax;
            archivo >> equipo2[i].ataques[j].ppActual;
            archivo.ignore();
        }
    }

    archivo.close();

    cout << "Partida cargada correctamente." << endl;

    return true;
}