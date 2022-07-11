#include <iostream>
#include <conio.h>
#include <regex>
#include <string>


using namespace std;

bool isValidSentence(const string& s);

int main()
{
    string s;
    int cont = 0;
    int op;

    do {
        cout << "\t1. Validar Informacion." << endl;
        cout << "\t2. Numero de entradas correctas." << endl;
        cout << "\t3. Salir" << endl << endl;

        cout << "Ingresa una opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                fflush(stdin);
                cout << "Ingresa la linea a verificar: ";
                getline(cin, s);

                if(isValidSentence(s)) {
                    cout << "Estructura valida" << endl;
                    cont++;
                }
                else
                    cout << "Estructura invalida" << endl;

                cout << "\t\tPreciona ENTER para continuar" << endl;
                getch();
                system("CLS");
                break;

            case 2:
                cout << endl << endl << "Entradas validas: " << cont << endl;

                cout << "\t\tPreciona ENTER para continuar" << endl;
                getch();
                system("CLS");
                break;

            case 3:
                cout << "\t\t\tFin de la ejecucion" << endl;
                cout << "\t\tPreciona ENTER para continuar" << endl;
                getch();
                break;

        default:
            system("CLS");
        }

    } while (op != 3);


}


bool isValidSentence(const string& s) {
    const regex expReg("C00000\\d{2}\\x7C(ENG|POR|FRE|GER|RUS|SPA)\\x7C(P|S)\\x7CL\\d{7}\\x7C(PF|VC|VW)\\x7CS\\d{7}\\x7C\\d,(2|4)(\x20|-)\\w*\\x7C(0|3)\\x7C");

    return regex_match(s, expReg);
}
