#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

void numsEntered(int user_nums[], int rounds);

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
    while (lim_sup < lim_inf)
    {
        cout << "Ingresa un limite superior válido. Debe ser mayor al limite inferior que ingresaste." << endl;
        cout << "Ingrese el limite superior: ";
        cin >> lim_sup;
    }

    cout << "Ingrese la cantidad de intentos máximos: ";
    cin >> int_max;
    while (int_max < 1)
    {
        cout << "La cantidad de intentos máximos debe ser mayor que 1." << endl;
        cout << "Ingrese la cantidad de intentos máximos: ";
        cin >> int_max;
    }

    // random num
    int secret_num = rand() % (lim_sup - lim_inf + 1) + lim_inf;

    // array
    int user_nums[int_max];

    // setup
    int rounds = 0;
    int repetitive = 0;
    int int_left = int_max;

    while (rounds < int_max)
    {
        // input
        cout << "<<<<<<<<<<<<------->>>>>>>>>>>>\nAdivine el numero creado aleatoriamente entre " << lim_inf << " y " << lim_sup << "\nIntento " << (rounds + 1) << " - Te quedan " << int_left << " intentos. \nIngresa un número: ";
        cin >> user_number;

        if (user_number < lim_inf || user_number > lim_sup)
        {
            cout << "El numero ingresado no está dentro del rango especificado.";
            cout << "\nIntento " << (rounds + 1) << " - Te quedan " << int_left << " intentos. \nIngresa un número: ";
            cin >> user_number;
        }
        else
        {
            if (user_number == secret_num)
            {
                cout << "Felicidades! Adivinaste el número. Lo hiciste en " << rounds << " intentos" << endl;
                break;
            }
            else
            {
                for (int i = 0; i < rounds; i++)
                {
                    if (user_nums[i] == user_number)
                    {
                        cout << "--------------------------------\nEl numero " << user_number << " ya ha sido ingresado anteriormente." << endl;
                        repetitive = 1;
                        rounds--;
                        int_left++;
                        break;
                    }
                }

                if (!repetitive)
                {
                    user_nums[rounds] = user_number;
                }
                rounds++;
                int_left--;
                cout << "--------------------------------\nNumero incorrecto. \n--------------------------------" << endl;
            }
        }
    }
    if (rounds == int_max)
    {
        cout << "Te has quedado sin intentos :( \nEl numero correcto era: " << secret_num << endl;
    }

    numsEntered(user_nums, rounds);

    return 0;
}

void numsEntered(int user_nums[], int rounds)
{
    cout << "Los numeros que ingresaste fueron: ";

    // Método de la burbuja
    int i, j, temp;
    for (i = 0; i < rounds - 1; ++i)
    {
        for (j = 0; j < rounds - 1; ++j)
        {
            if (user_nums[j] > user_nums[j + 1])
            {
                temp = user_nums[j];
                user_nums[j] = user_nums[j + 1];
                user_nums[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < rounds; i++)
    {
        cout << user_nums[i] << " ";
    }
    cout << endl;
}