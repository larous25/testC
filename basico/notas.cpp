# include <iostream>
# include <string>
# include <vector>
# include <fstream> // libreria para la manipulacion de ficheros papu
# include <cstdio>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream; // este tipo es el que maneja los archivos

bool existeArchivo(const char *);

int main(void){
    const string NOMBRE_ARCHIVO = "hola.txt";
    const char CARACTER_SEPARADOR = '|';
    bool salida = false;

    do{
        int opcion = 0;

        cout << "\n\t\tBienvenido" << endl;
        cout << "\tPor favor selecion una opcion de las siguientes" << endl;
        cout << "\t 1) ingresa una nota personal" << endl;
        cout << "\t 2) mira todas tus notas" << endl;
        cout << "\t 3) destruille todo en caso de que te encuentren y" << endl;
        cout << "\t luego lanzarse por la ventana" << endl;
        cout << "\t 4) salir" << endl;
        // esta exprecion cin >> opcion
        // si se utiliza en una condicion
        // retorna un apuntador que se sobrecarga con un
        // valor null
        if(!(cin >> opcion)) {
            cout << "la selecion es un numero";
            return 1;
        } else {
            switch(opcion){
                case 1:
                {
                    const size_t longitud = 100;
                    char nota[longitud] = "";
                    fstream archivo;

                    if(existeArchivo(NOMBRE_ARCHIVO.c_str())) { // c_str retorna un array tipo puntero char
                        archivo.open(NOMBRE_ARCHIVO.c_str(), fstream::in | fstream::out | fstream::app);
                    } else {
                        archivo.open(NOMBRE_ARCHIVO.c_str(), fstream::in | fstream::out | fstream::trunc);
                    }

                    cout << "\n\t  Ingrese la nota porfavor" << endl;
                    // ignora lo ingresado en el buffer
                    // en este caso el caracter ingresado en la variable opcion
                    cin.ignore();
                    // lee los caracteres ingresados aun con el espacio en blanco
                    cin.getline(nota, longitud);
                    // utiliza el operador de flujo para pasarle los datos al archivo
                    archivo <<  nota << CARACTER_SEPARADOR;
                    archivo.close();
                    break;
                }
                case 2:
                {
                    if(existeArchivo(NOMBRE_ARCHIVO.c_str())) {
                        fstream archivo;
                        archivo.open(NOMBRE_ARCHIVO.c_str(), fstream::in | fstream::out | fstream::app);
                        cout << "\n\t  Sus notas" << endl;
                        archivo.seekg(0, archivo.beg); //Nos ponemos al inicio del fichero
                        string linea;
                        while(std::getline(archivo, linea))
                        {
                            std::vector<string> secretos;
                            string textosecreto = "";
                            for (char caracter:linea) {
                                if(caracter != CARACTER_SEPARADOR){
                                    textosecreto.push_back(caracter);
                                } else {
                                    secretos.push_back(textosecreto);
                                    textosecreto = "";
                                }
                            }

                            for (unsigned int i = 0; i < secretos.size(); ++i) {
                                cout << i << ")  " << secretos[i] << endl;
                            }
                        }
                    } else {
                        cout << "no existen notas aun";
                    }

                    break;
                }
                case 3:
                {
                    cout << "\n\t  Eliminando todas las notas" << endl;
                    std::remove(NOMBRE_ARCHIVO.c_str());
                    cout << "\n\t  Ahora corre que vienen por ti!!" << endl;
                    break;
                }
                case 4:
                {
                    salida = true;
                    break;
                }
                default:
                {
                    cout << "esa opcion no existe pillin" << endl;
                    break;
                }
            }
        }
        cin.clear(); // borra los estados de cin
    }while(!salida); // seguira corriendo siempre y cuando sea falso

    return 0;
};

// toma un puntero
// y crea un objeto ifstream
// si al archivo le pasa algo
// el retornara falso
bool existeArchivo(const char *nombre){
    std::ifstream archivo(nombre);
    return archivo.good();
};
