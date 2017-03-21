# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <algorithm>
# include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::invalid_argument;

class Persona {
private:
    string nombre = "";
public:
    Persona();
    ~Persona();
    string mostrarNombre() const;
    void consegirNombre(string&);
    string validar(string);
};

Persona::Persona():nombre("")
{
};

Persona::~Persona(){
};

string Persona::mostrarNombre () const
{
    return this->nombre;
};

void Persona::consegirNombre (string& nombre)
{
    this->nombre = this->validar(nombre);
};

string Persona::validar (string texto)
{
    std::replace_if(texto.begin(), texto.end(), ::isdigit, ' ');
    std::replace_if(texto.begin(), texto.end(), ::ispunct, ' ');
    return texto;
};

// -------- barra de separacion ---------- //

class Estudiante: public Persona{
    unsigned int id;
    double calificacion;
    string nombre = "";
public:
    Estudiante();
    ~Estudiante();
    int mostrarId() const;
    void consegirId(int);
    double mostarCalificacion() const;
    void consegirCalificacion(double numero);
};

Estudiante::Estudiante():id(0)
{
};

Estudiante::~Estudiante()
{
};

double Estudiante::mostarCalificacion () const
{
    return this->calificacion;
};

void Estudiante::consegirCalificacion (double numero) { // que retorne un mensaje si esta muy bajo?
    this->calificacion = numero;
};

int Estudiante::mostrarId() const
{
    return this->id;
}

void Estudiante::consegirId(int id)
{
    this->id = id;
}

// -------- barra de separacion ---------- //

class clase {
    vector<Estudiante *> estudiantes;
    int cantidad = 0;
public:
    clase();
    ~clase();
    vector<Estudiante *> mostarEstudiantes() const;
    Estudiante* conseguirEstudiante(string&, int&);
    Estudiante* conseguirEstudiante(int&);
    Estudiante* conseguirEstudiante(string&);
    vector<Estudiante *> conseguirEstudiantes(int inicio,const int cantidad);
    vector<Estudiante *> conseguirEstudiantes(int);
    int mostrarCantidad();
    void guardarEstudiante(Estudiante&);
};

clase::clase()
{

};

clase::~clase()
{
};

vector<Estudiante *> clase::mostarEstudiantes() const
{
    return this->estudiantes;
};

Estudiante* clase::conseguirEstudiante(string& nombre, int& id)
{
    for(Estudiante *alumno : this->estudiantes) {
        if((alumno->mostrarNombre() == nombre) && (alumno->mostrarId() == id)) return alumno;
    }

    return nullptr;
};

Estudiante* clase::conseguirEstudiante(int& id)
{
    for(Estudiante *alumno:this->estudiantes) {
        if((alumno->mostrarId() == id)) return alumno;
    }

    return nullptr;
};

Estudiante* clase::conseguirEstudiante(string& nombre)
{
    for(Estudiante *alumno:this->estudiantes) {
        if((alumno->mostrarNombre() == nombre)) return alumno;
    }

    return nullptr;
};

vector<Estudiante *> clase::conseguirEstudiantes(int inicio,const int cantidad)
{
    vector<Estudiante *> seleccionados;
    for (int i = inicio || 0 ; i < cantidad; ++i) {
        seleccionados.push_back(this->estudiantes[i]);
    }

    return seleccionados;
}

vector<Estudiante *> clase::conseguirEstudiantes(int cantidad)
{
    vector<Estudiante *> seleccionados;
    for (int i = 0; i < cantidad; ++i) {
        seleccionados.push_back(this->estudiantes[i]);
    }

    return seleccionados;
}

void clase::guardarEstudiante(Estudiante& nuevo)
{
    const int uno = 1;
    this->cantidad += uno;
    nuevo.consegirId(uno);
    this->estudiantes.push_back(&nuevo);
};

int clase::mostrarCantidad()
{
    this->cantidad;
}


// -------- barra de separacion ---------- //

// es una variable de plantilla clase
template <class T>
class DB {
public:
    // estas funciones se pueden utilizar como 
    // metodos o funciones normales
    friend void imprimir(vector<T *>);
    friend void imprimir(T&);
    friend void imprimir(const char*);
};



void imprimir(const char* cadena)
{
    cout << cadena;
}

template <class T>
void imprimir(vector<T *> estudiantesVector)
{
    for (T *e: estudiantesVector) {
        imprimir(e);
    }
};


template <class T>
void imprimir(T& estudiante)
{
    cout << "estudiante # " << estudiante->mostrarId() << endl;
    cout << "nombre: " << estudiante->mostrarNombre() << endl;
    cout << "calificacion: " << estudiante->mostarCalificacion() << endl;
};


// -------------------------------------

int main(void) {
    bool salir = false;
    clase matematicas;

    do{
        unsigned int opcion;
        imprimir("\n Bienvenido a la base de dator impostora \n");
        imprimir("\t porfavor ingresa el numero de la instrucion que deseas\n");
        imprimir("\t 1) ingresar estudiante");
        imprimir("\t 2) buscar estudiante");
        imprimir("\t 3) lista estudiantes");
        imprimir("\t 10) salir\n");
        cin>>opcion;
        switch(opcion) {
            case 1: {
                string nombre = "";
                double calificacion = 0;
                Estudiante alumno;

                imprimir("\n\t\t Ingrese nombre porfavor \n");
                cin >> nombre;
                alumno.consegirNombre(nombre);
                imprimir("\n\t\t Ingrese calificacion \n");
                cin >> calificacion;
                alumno.consegirCalificacion(calificacion);

                matematicas.guardarEstudiante(alumno);

                break;
            }
            case 2: {
                bool salir2 = false;
                unsigned int opcion2 = 0 ;
                string nombre = "";
                int id = 0;
                Estudiante* incognito = nullptr;

                do {

                    imprimir("\n\t porfavor ingresa el numero de la instrucion que deseas \n");
                    imprimir("\n\t\t 1) busquerda por nombre y id \n");
                    imprimir("\n\t\t 2) busqueda por id\n");
                    imprimir("\n\t\t 3) busqueda por nombre\n");
                    imprimir("\n\t\t 4) salir submenu 2 \n");

                    cin >> opcion2;

                    switch(opcion2){
                        case 1:
                        {
                            imprimir("\n\t\t Ingrese nombre porfavor \n");
                            cin >> nombre;
                            imprimir("\n\t\t Ingrese id porfavor \n");
                            cin >> id;
                            incognito = matematicas.conseguirEstudiante(nombre, id);
                            if(incognito != nullptr) {
                                imprimir(incognito);
                            } else {
                                imprimir("\nNo existe ningun reguistro\n");
                            }
                            break;
                        }
                        case 2:
                        {
                            imprimir("\n\t\t Ingrese id porfavor \n");
                            cin >> id;
                            incognito = matematicas.conseguirEstudiante(id);
                            if(incognito != nullptr) {
                                imprimir(incognito);
                            } else {
                                imprimir("\nNo existe ningun reguistro\n");
                            }
                            break;
                        }
                        case 3:
                        {
                            imprimir("\n\t\t Ingrese nombre porfavor \n");
                            cin >> nombre;
                            incognito = matematicas.conseguirEstudiante(nombre);
                            if(incognito != nullptr) {
                                imprimir(incognito);
                            } else {
                                imprimir("\nNo existe ningun reguistro\n");
                            }
                            break;
                        }
                        case 4:
                        {
                            imprimir("\n\t\t esta saliendo del submenu 2 \n");
                            salir2 = true;
                            break;
                        }
                        default:
                        {
                            imprimir("\n opcion no valida \n");
                            break;
                        }

                    }

                } while(!salir2);


                break;
            }
            case 3:
            {

                bool salir2 = false;
                unsigned int opcion2 = 0 ;

                imprimir("\n\t porfavor ingresa el numero de la instrucion que deseas \n");
                imprimir("\n\t\t 1) traer los una cantidad 'X' de estudiantes \n");
                imprimir("\n\t\t 2) recorer de a CINCO estudiantes \n");
                imprimir("\n\t\t 3) traer todos los estudiantes \n");
                imprimir("\n\t\t 4) salir submenu 3 \n");

                cin >> opcion2;

                do {
                    switch(opcion2) {
                        case 1: {
                            int cantidad;
                            imprimir("\n\t\t ingrese cantidad porfavor \n");
                            cin >> cantidad;

                            if((matematicas.mostrarCantidad() > cantidad) || (cantidad == 0))
                                throw invalid_argument("no se puede ver mas de lo que hay");
                            else
                                imprimir(matematicas.conseguirEstudiantes(NULL, cantidad));
                            break;
                        }
                        case 2: {
                            const int CINCO = 5;
                            int cantidad = CINCO;
                            do
                            {
                                imprimir(matematicas.conseguirEstudiantes(cantidad, CINCO));
                                cantidad += CINCO;
                                char opcion3;
                                imprimir("continuar con los siquientes cinco/n S o N /n");
                                cin >> opcion3;
                                if(opcion3 == 'n' || opcion3 == 'N')
                                    break;

                            } while(cantidad < matematicas.mostrarCantidad());
                            break;
                        }
                        case 3: {
                            imprimir("Los Estudiantes de su clase\n");
                            imprimir(matematicas.mostarEstudiantes());
                            break;
                        }
                        case 4: {
                            salir2 = true;
                            break;
                        }
                        default:
                        {
                            imprimir("\n opcion no valida \n");
                            break;
                        }
                    }
                } while(!salir2);
                break;
            }
            case 10:
            {
                imprimir("\n\t hasta luego y gracias \n");
                salir = true;
                break;
            }
        };

    }while(!salir);

    return 0;
}
