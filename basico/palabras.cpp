#include <iostream>
#include <string>

using namespace std;
// constante tipo int
const int NUMERO_DEPALABRAS = 5;

int main (void){
	// asignación de cinco palabras
	string palabra[NUMERO_DEPALABRAS] = {"hola", "mundo", "y", "cruel", "adios"};
	char letra;

	cout<<"cual letra quieres buscar?"<<endl;
	cin>>letra;
	cout<<"esta es su letra\t"<<letra<<endl;

	// el tipo string es un objeto con un vector tipo char 
	for (unsigned i = 0; i < NUMERO_DEPALABRAS; ++i)
	{
		bool comprobante = false;
		cout<<"buscando en la palabra\t"<<palabra[i]<<endl;
		for (unsigned y = 0; y <= palabra[i].size(); ++y)
		{
			if(palabra[i][y] == letra){
				cout<<"\tencontrada"<<endl;
				comprobante = true;
			}
		}

		if(!comprobante){
			cout<<"\tal parecer no esta aqui"<<endl;
		}

	}
}