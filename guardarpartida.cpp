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
        archivo << equipo1[i].tipo << endl;
        archivo << equipo1[i].vidaMax << endl;
        archivo << equipo1[i].vidaActual << endl;
        archivo << equipo1[i].ataqueBase << endl;

        for (int j = 0; j < 4; j++)
        {
            archivo << equipo1[i].ataques[j].nombre << endl;
            archivo << equipo1[i].ataques[j].tipo << endl;
            archivo << equipo1[i].ataques[j].danoBase << endl;
            archivo << equipo1[i].ataques[j].ppMax << endl;
            archivo << equipo1[i].ataques[j].ppActual << endl;
        }
    }

    // Equipo del jugador 2
    for (int i = 0; i < 6; i++)
    {
        archivo << equipo2[i].nombre << endl;
        archivo << equipo2[i].tipo << endl;
        archivo << equipo2[i].vidaMax << endl;
        archivo << equipo2[i].vidaActual << endl;
        archivo << equipo2[i].ataqueBase << endl;

        for (int j = 0; j < 4; j++)
        {
            archivo << equipo2[i].ataques[j].nombre << endl;
            archivo << equipo2[i].ataques[j].tipo << endl;
            archivo << equipo2[i].ataques[j].danoBase << endl;
            archivo << equipo2[i].ataques[j].ppMax << endl;
            archivo << equipo2[i].ataques[j].ppActual << endl;
        }
    }

    archivo.close();

    cout << "Partida guardada correctamente." << endl;
}