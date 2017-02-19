# include <iostream>
# include <string>
# include <vector>
# include <iomanip> // esta libreria tiene funciones para la salida en pantalla

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// un programa de consola resive dos argumentos
// uno es la cantidad de argumentos que por defecto
// es uno y el otro es un array en el cual la primera 
// pocicion es el nombre del programa y las demas son argumentos 
// pasados despues del nombre del programa con que se ejecuto
// por estandar se llaman argc (c de count) y argv (v de vector) 
int main(int cantidad, char* matriz[]){
	if(cantidad >= 2){ // si solo existe uno no se ingresaron parametros 
		vector<string> argumentos;
		
		for (int i = 1; i < cantidad; ++i)
		{
			argumentos.push_back(string(matriz[i]));
		}
		
		cout << "te doy una lista con los colores que me gustan segun su valor" << endl;
		setiosflags(ios::left);
		for (int i = 0; i < argumentos.size(); ++i)
		{
			// controla la salida por pantalla
			// setw, setfill son funciones de iomanip
			cout << std::setw(1) << i  << std::setfill('.') << std::setw(20) << argumentos[i] << endl;
			
			if(argumentos[i] == "violeta"){ 
				cout << "su pesimo gusto rompio el ciclo" << endl;
				break; // rompe el ciclo
			}
		}

		return 0; 
	}


	cout << "los argumentos son necesarios para el programa:\t" << matriz[0]; 
	// retornando uno le dice al sistema que se
	// ha ocurrido un problema con el programa
	return 1; 
};
