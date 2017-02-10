#include <iostream>
#include <iomanip> 
#include <array> 

using namespace std;

template <class Iterador>
void pintar(Iterador init, Iterador end);

int main(void) {
	const size_t longitud = 5;

	// un vector tipo entero de
	// cinco espacios en memoria
	int arregloNormal[longitud] = {5,4,3,2,1};

	// por defecto apunta a la direcion donde
	// se encuentra el primer elemento del array
	// int *puntero = &arregloNormal[0]; 
 	int *puntero = arregloNormal;

	// si utilizamos el operador prefijo apunta a la siguiente direción en memoria
	// y si queremos aumentar el valor de la posicion actual con el operador prefijo 
	// tenemos, lo utilizamos asi (*puntero)++;
	puntero++;
	cout<<"el valor normal\t"<<puntero<<endl;

	// ..................................................

	// matriz de dos dimenciones
 	int matriz[2][3] = {{1,2,3},{3,4,4}};


	// ..................................................
	// declara un array de tipo entero de la miama longitud de l anterior
	array< unsigned int, longitud > arreglo = { 4, 3, 2, 1, 0 };

 	pintar(arreglo.begin(), arreglo.end());

 	// instrucion basada en rango
 	// al no utilizar contador se evita salirce del arreglo
 	// funciona tanto para los contenedores array como vector
 	// for ( declaracionVariableRango : expresion) 
 	for (int elemento:arreglo)
 	{
 		cout << elemento << '\t';
 		cout << &elemento << '\n';
 	}
}


/**
 * resive dos iteradores (son como punteros pero de una coleccion) 
 * el primero va recoriendo la misma pocision hasta que se encuentra 
 * en la misma que el segundo y al ser iguales finaliza el ciclo 
 */
template <class Iterador>
void pintar(Iterador init, Iterador end) {
	cout << "los valores de su array y su puesto en memoria" << endl;
	for (; init != end; ++init)
	{
		cout << *init << '\t';
		cout << init << '\n';
	}


};