void batalla(Pokemon equipo1[], Pokemon equipo2[])
{
    int indiceJ1 = 0;
    int indiceJ2 = 0;

    while (indiceJ1 < 6 && indiceJ2 < 6)
    {
        Pokemon &p1 = equipo1[indiceJ1];
        Pokemon &p2 = equipo2[indiceJ2];

        cout << "\n=====================================\n";
        cout << p1.nombre << " VS " << p2.nombre << endl;
        cout << "=====================================\n";

        while (p1.vidaActual > 0 && p2.vidaActual > 0)
        {
            cout << "\nVida de " << p1.nombre << ": " << p1.vidaActual << endl;
            cout << "Vida de " << p2.nombre << ": " << p2.vidaActual << endl;

            cout << "\nAtaques de " << p1.nombre << ":\n";

            for (int i = 0; i < 4; i++)
            {
                cout << i + 1 << ". "
                     << p1.ataques[i].nombre
                     << " | Daño: "
                     << p1.ataques[i].danoBase
                     << endl;
            }

            int opcionAtaque;

            cout << "\nSelecciona un ataque: ";
            cin >> opcionAtaque;

            while (opcionAtaque < 1 || opcionAtaque > 4)
            {
                cout << "Opcion invalida. Intenta de nuevo: ";
                cin >> opcionAtaque;
            }

            int dano = p1.ataques[opcionAtaque - 1].danoBase;

            p2.vidaActual -= dano;

            cout << "\n" << p1.nombre
                 << " uso "
                 << p1.ataques[opcionAtaque - 1].nombre
                 << " y causo "
                 << dano
                 << " de dano.\n";

            if (p2.vidaActual <= 0)
            {
                cout << p2.nombre << " ha sido derrotado.\n";
                indiceJ2++;
                break;
            }

            int danoRival = p2.ataques[0].danoBase;

            p1.vidaActual -= danoRival;

            cout << p2.nombre
                 << " uso "
                 << p2.ataques[0].nombre
                 << " y causo "
                 << danoRival
                 << " de dano.\n";

            if (p1.vidaActual <= 0)
            {
                cout << p1.nombre << " ha sido derrotado.\n";
                indiceJ1++;
                break;
            }
        }
    }

    cout << "\n====================\n";
    cout << "FIN DE LA BATALLA\n";
    cout << "====================\n";

    if (indiceJ1 >= 6)
        cout << "Gana " << player2_nombre << "!\n";
    else
        cout << "Gana " << player1_nombre << "!\n";
}