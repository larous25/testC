#include <iostream>
using namespace std;

int main(void){
	int edad = 0;
	
	do{
			cout << "porfavor ingrecese la edad del cliente\t" << endl;
			cin >> edad;
			if( edad < 18 ){
				cout << "merece descuento de estudiante\t" << edad << endl;
			}else if( edad > 60 ){
				cout << "merece descuento de tercera edad\t" << edad << endl;
			}else{
				cout << "no merece descuento\t" << edad << endl;
			}

	}while (edad != 0);

 cout<< "adios" << endl;
}