float calcularMultiplicador(string tipoAtaque, string tipoPokemon)
{
    // Ataques de Fuego
    if (tipoAtaque == "Fuego" && tipoPokemon == "Planta")
        return 2.0;

    if (tipoAtaque == "Fuego" && tipoPokemon == "Agua")
        return 0.5;

    // Ataques de Agua
    if (tipoAtaque == "Agua" && tipoPokemon == "Fuego")
        return 2.0;

    if (tipoAtaque == "Agua" && tipoPokemon == "Planta")
        return 0.5;

    // Ataques de Planta
    if (tipoAtaque == "Planta" && tipoPokemon == "Agua")
        return 2.0;

    if (tipoAtaque == "Planta" && tipoPokemon == "Fuego")
        return 0.5;

    // Si los tipos son iguales o no hay ventaja
    return 1.0;
}