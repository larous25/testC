#include <iostream>
#include <string>

using namespace std;
// constante tipo int
const int NUMERO_DE_PALABRAS = 5;

int main (void){
    // asignación de cinco palabras
    string palabra[NUMERO_DE_PALABRAS] = {"hola", "mundo", "y", "cruel", "adios"};
    char letra;

    cout << "cual letra quieres buscar?" << endl;
    cin >> letra;
    cout <<"esta es su letra\t" << letra << endl;

    // el tipo string es un objeto con un vector tipo char
    for (unsigned i = 0; i < NUMERO_DE_PALABRAS; ++i)
    {
        bool comprobante = false;
        cout << "buscando en la palabra\t" << palabra[i] << endl;
        for (unsigned y = 0; y <= palabra[i].length(); ++y)
        {
            if(palabra[i][y] == letra) {
                cout << "\tencontrada" << endl;
                comprobante = true;
            }
        }

        if(!comprobante){
            cout << "\tal parecer no esta" << endl;
        }

        // en teroria buscaria el caracter
        if(palabra[i].find(letra) != string::npos) {
            cout << "este metodo tambien funciona" << endl;
        }
    }

    return 0;
}