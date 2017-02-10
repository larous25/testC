#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int CERO = 0;

//la structura deportes es similar a un diccionario
//de datos o una columna en un db
//son similares a las clases (solo que todo es de tipo publico)
//tienen propiedades, constructores
struct deportes{
    string nombre;
    string descripcion;
    int nivel;
    deportes():nivel{CERO}{
    }
};

// crea una función para que cualquier 
// tipo en la variable pueda ser leida por el cout
template <typename TIPO> // esto es un template para cualquier tipo de variable (no objetos)
void imprima(const TIPO valor) {
    cout<< valor << endl;
}

// sobre escribe la funcion imprima y resive como parametro un  argumento
// constante tipo puntero deportes (realmente es la direccion de memoria)
void imprima(const deportes &valor) {
    imprima("esta es la informacion del su deporte:");
    imprima("nombre:");
    imprima(valor.nombre);
    imprima("descripcion:");
    imprima(valor.descripcion);
    imprima("nivel");
    imprima(valor.nivel);
}


int main(void) {
    int tamano = CERO;

    imprima("favor ingrese cuantos deportes va guardar");
    cin>> tamano;
    // vector tipo deportes
    vector<deportes> d (tamano);    

    for (unsigned i = CERO; i < d.size(); ++i) {
        imprima("ingrese el nombre del deporte");
        cin>> d[i].nombre;  
        imprima("ingrese la descripcion del deporte");  
        cin>> d[i].descripcion; 
        imprima("ingrese el nivel del deporte");    
        cin>> d[i].nivel;   
    }

    for (unsigned i = CERO; i < d.size(); ++i) {
        imprima(d[i]);
    }
}