#include <iostream>
#include <string>

using namespace std;

int main()
{

    int Venusaur_vida = 180;
    int Charizard_vida = 300;
    int Blastoise_vida = 190;
    int player1_vida, player2_vida;
    int player1_opcion, player2_opcion;
    string dato;

    do
    {
     
    cout << "bienvenido a la batalla pokemon porfavor elija una opcion" << endl;
    cout << "====ELIGE TU POKEMON====" << endl;
    cout << "1. Venusaur  HP: " << Venusaur_vida <<endl;
    cout << "2. Charizard HP: " << Charizard_vida <<endl;
    cout << "3. Blastoise HP: " << Blastoise_vida <<endl;
    cout << "4. "
    cout << "Elige a tu pokemon!:"<<endl;
    cin>> dato;

    if (dato== "1")
    {
        player1_vida=Venusaur_vida;
    }
    else if (dato=="2"){
        player1_vida =Charizard_vida;
    }
    else if (dato=="3")
    {
        player1_vida=Blastoise_vida;
    
    }

    else cout <<"opcion no valida, imgresa 1 2 o 3!"<<endl;

 } while (player1_opcion<1 || player1_opcion>3);


    



    return 0;
}