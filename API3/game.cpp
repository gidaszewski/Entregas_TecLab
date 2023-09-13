#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    // init random sem
    srand(time(0));

    // var
    int lim_inf, lim_sup, int_max;
    int user_number;
    int play_again;

    // input
    cout << "Ingrese el limite inferior: ";
    cin >> lim_inf;

    cout << "Ingrese el limite superior: ";
    cin >> lim_sup;

    cout << "Ingrese la cantidad de intentos máximos: ";
    cin >> int_max;

    // random num
    int secret_num = rand() % (lim_sup - lim_inf + 1) + lim_inf;

    // setup
    int rounds = 0;
    int int_left = int_max;
    int number_entered[int_max];

    while (rounds < int_max)
    {
        // input
        cout << "Intento " << (rounds + 1) << " - Te quedan " << int_left << " intentos. \nIngresa un número: ";
        cin >> user_number;

        if (user_number == secret_num)
        {
            cout << "Felicidades! Adivinaste el número." << endl;
            break;
        }
        else
        {
            int indice = -1;
            for (int i = 0; i < sizeof(number_entered) / sizeof(number_entered[0]); i++)
            {
                int numActual = number_entered[i];
                if (numActual == user_number)
                {
                    indice = i;
                    break;
                }
            }
            if (indice == -1)
            {
                number_entered[rounds] = user_number;
                cout << "Numero incorrecto. \nIngresaste el numero:" << number_entered[rounds] << endl;

                rounds++;
                int_left--;
            }
            else
            {
                cout << "Ya has ingresado ese número. \n";
                cout << "Intento " << (rounds + 1) << " - Te quedan " << int_left << " intentos. \nIngresa un número: ";
                cin >> user_number;
            }
        }
    }
    if (rounds == int_max)
    {
        cout << "Te has quedado sin intentos :( \nEl numero correcto era: " << secret_num << endl;
        cout << "Si desea volver a jugar ingrese el numero 1 \no ingrese cualquier otro digito para terminar: ";
        cin >> play_again;

        if (play_again == 1)
        {
            main();
        }
        else
        {
            cout << "Nos vemos pronto, gracias por jugar :)";
        }
    }

    return 0;
}