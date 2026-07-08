void guardarPartida(Pokemon equipo1[], Pokemon equipo2[], int indiceJ1, int indiceJ2)
{
    ofstream archivo("partida.txt");

    if (!archivo)
    {
        cout << "Error al guardar la partida." << endl;
        return;
    }

    archivo << player1_nombre << endl;
    archivo << player2_nombre << endl;

    archivo << indiceJ1 << endl;
    archivo << indiceJ2 << endl;

    // Equipo del jugador 1
    for (int i = 0; i < 6; i++)
    {
        archivo << equipo1[i].nombre << endl;
        archivo << equipo1[i].vidaActual << endl;

        for (int j = 0; j < 4; j++)
            archivo << equipo1[i].ataques[j].ppActual << endl;
    }

    // Equipo del jugador 2
    for (int i = 0; i < 6; i++)
    {
        archivo << equipo2[i].nombre << endl;
        archivo << equipo2[i].vidaActual << endl;

        for (int j = 0; j < 4; j++)
            archivo << equipo2[i].ataques[j].ppActual << endl;
    }

    archivo.close();

    cout << "\nPartida guardada correctamente.\n";
}