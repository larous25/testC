
//////////////////////////////////////////////////////////////////////////////////////////////////
// carreras de caballos                                                                         //
// en un hipodromo se registran 6 caballos para                                                 //
// una carrera no mas no menos ya que no se                                                     //
// puede realizar la carrera si no estan completos                                              //
// segun la posicion en la carrera LOS CABALLOS SUMAN PUNTOS en la                              //
// tabla general                                                                                //
// la tabla general se crea apartir de la pocision en cada carrera                              //
// la posicion en cada carrera es dada por el mayor puntage                                     //
// entonces es ordenar de forma mayor a menor (desendete ) y asignar puntos a cada uno de ellos //
//////////////////////////////////////////////////////////////////////////////////////////////////

# include <iostream>
# include <string>
# include <vector>
# include <random> // libreria de generadores aleatorios en c++11
# include <iomanip>

using namespace std;


class jinete {
    string nombre;
    float habilidad;
public:
    jinete(); // los contructores siempre son publicos
    jinete(string, float); // esto se llama sobrecarga
    ~jinete(); // tambien los destructores siempre son publicos

    // esto es un forma de declaracion de los metodos
    // se llama prototipo
    void asignarHabilidad(float);
    float mostrarHabilidad() const;
    void asignarNombre(string);
    string mostrarNombre() const;
};

jinete::jinete()
{
};

// esta es una forma de asignar valores a
// las propiedades del objeto
jinete::jinete(string nombre, float habilidad)
{
    this->nombre = nombre;
    this->habilidad = habilidad;
};

jinete::~jinete()
{
};

// este es el cuerpo del metodo
void jinete::asignarHabilidad(float habilidad)
{
    this->habilidad = habilidad;
};

float jinete::mostrarHabilidad() const
{
    this->habilidad;
};

void jinete::asignarNombre(string nombre)
{
    this->nombre = nombre;
}

string jinete::mostrarNombre() const
{
    return this->nombre;
};


// -------- barra ----- separadora ------- simple

class caballo {
private:
    string nombre;
    float velocidad;
    float desgaste;
public:
    caballo();
    caballo(int);
    caballo(string, float);
    ~caballo();
    void asignarNombre(string);
    string mostrarNombre() const;
    void asignarVelocidad(float);
    float mostrarVelocidad() const;
    int mostarDesgaste();
};


caballo::caballo():desgaste(0)
{
};

//  al tener un solo
// parametro se puede inicializar el objeto de esta forma
// caballo c = 5; o como funcion caballo c(2);
// explicit evita que se pueda realizar conversion
caballo::caballo(int d):desgaste(d)
{
};

// esto se llama iniciacion directa la cual es mas eficas
// que utilizar operadores de asignacion dentro del cuerpo
// del constructor
caballo::caballo(string n, float v):nombre(n), velocidad(v), desgaste(0)
{
};

caballo::~caballo()
{};


void caballo::asignarNombre(string nombre)
{
    this->nombre = nombre;
}

string caballo::mostrarNombre() const
{
    return this->nombre;
};

void caballo::asignarVelocidad(float velocidad)
{
    this->velocidad = velocidad;
}

float caballo::mostrarVelocidad() const
{
    return this->velocidad;
}

int caballo::mostarDesgaste()
{
    random_device rd; // este es un tipo de motor
    mt19937 gen(rd()); // para los numeros aleatorios
    uniform_int_distribution<unsigned int> aleatorio(1,5);
    this->desgaste += aleatorio(gen);
    return this->desgaste;
}

// -------- barra ----- separadora ------- simple

class participante: public jinete
{
    unsigned int puntaje = 0;
    caballo corsel;
    float resultado = 0;
public:
    using jinete::jinete; // esto hereda constructores
    participante();
    ~participante();
    float calcularResultado();
    void asignarCaballo(caballo&);
    void asignarPuntaje(int);
    void darPuntos(int);
    int mostrarPuntos() const;
    float mostrarPosicion() const;
};

participante::participante()
{}

participante::~participante()
{}

float participante::calcularResultado()
{
    this->resultado = (this->corsel.mostrarVelocidad() + this->mostrarHabilidad()) - this->corsel.mostarDesgaste();
    return this->resultado;
}

void participante::asignarCaballo(caballo &c)
{
    this->corsel = c;
};

void participante::asignarPuntaje(int p)
{
    this->puntaje = p;
};

void participante::darPuntos(int p)
{
    this->puntaje += p;
};

int participante::mostrarPuntos() const
{
    return this->puntaje;
};

float participante::mostrarPosicion() const
{
    return this->resultado;
};

// -------- barra ----- separadora ------- simple

class hipodromo {
    const unsigned int CANTIDAD = 6;
    vector<participante> participantes;
    void pintarTabla(vector<participante>&);
    bool temporada = false;
public:
    hipodromo();
    ~hipodromo();
    string nuevoParticipante(participante&);
    void carrera();
    vector<participante> mejoresResultados();
    int conseguirCantidad() const;
    void tablaGeneral();
    vector<participante> asignarPuntos(vector<participante>&);
};


hipodromo::hipodromo()
{
};

hipodromo::~hipodromo()
{
};

string hipodromo::nuevoParticipante(participante &p)
{
    if(this->participantes.size() < this->CANTIDAD) {
        this->participantes.push_back(p);
        return "se ha guardado de forma exitosa";
    }

    return "se ha exidido en el limite de participantes";
};

void hipodromo::carrera()
{
    cout << "comienza carrera" << endl;
    for(participante &p : this->participantes)
    {
        cout << p.mostrarNombre() << " va con " << p.calcularResultado() << endl;
    }

    this->temporada = true;
};

// al retornar o dar parametros siempre se pasa
// el tipo incluso si ese tipo depende de otro tipo
vector<participante> hipodromo::mejoresResultados()
{
    // aqui estoy copiando el vector
    vector<participante> participantesOrdenados(this->participantes);
    if(this->participantes.size() > 0) {
        // aqui lo organiso por el metodo en burbuja
        for (int i = 0; i < participantesOrdenados.size(); ++i) {
            for (int j = 0; j < participantesOrdenados.size() - 1; ++j) {
                if(participantesOrdenados[j].mostrarPosicion() < participantesOrdenados[j + 1].mostrarPosicion()){
                    participante temp = participantesOrdenados[j];
                    participantesOrdenados[j] = participantesOrdenados[j+1];
                    participantesOrdenados[j+1] = temp;
                }
            }
        }
    } else {
        cout << "no existen registros que mostrar";
    }

    return participantesOrdenados;
};

void hipodromo::tablaGeneral()
{
    vector<participante> ordenados =  (this->temporada ? this->mejoresResultados() : this->participantes);
    // esto es parecido a javascript (mas bien javascript se copio)
    if(this->temporada)
        this->asignarPuntos(ordenados);

    this->pintarTabla(ordenados);
};

void hipodromo::pintarTabla(vector<participante> &vp)
{

    cout << endl << "Nompre de participante" << " | " << " posicion" << " | " << "puntacion"<< endl;
    cout << "................................."<< endl;
    for(participante &p : vp)
    {
        cout.width(10);
        cout << p.mostrarNombre() << " | " << p.mostrarPosicion() << " | " << p.mostrarPuntos() << endl;
    }
    cout << "................................."<< endl;
};

vector<participante> hipodromo::asignarPuntos(vector<participante> &participantesOrdenados)
{
    // paresido al metodo en burbuja pero solo es una busqueda
    for (int i = 0; i < participantesOrdenados.size() ; ++i) {
        int puntos = participantesOrdenados.size() - i;
        for (int j = 0; j < participantesOrdenados.size(); ++j) {
            if(participantesOrdenados[i].mostrarNombre() == this->participantes[j].mostrarNombre()) {
                participantesOrdenados[i].darPuntos(puntos);
                this->participantes[j].darPuntos(puntos);
                break; // en teoria esto rompe el ciclo cuando ha encontrado el nombre
            }
        }
    }

    return participantesOrdenados;
};

// -------- barra ----- separadora ------- simple

int main(void) {
    hipodromo zarsuela;
    int cantidadDeCarreras = 5;
    vector<string> nombresCaballos = { "prieto", "pinto", "colorado", "azabache", "mancha", "tostao" };
    vector<string> nombresjinetes = { "ronaldo", "ernesto", "pinpollo", "guns", "riquelme", "raul" };


    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned int> habilidadJinete(1, 5);
    uniform_int_distribution<unsigned int> velocidadCaballo(15, 25);

    for (int i = 0; i < nombresjinetes.size(); ++i) {

        participante p(nombresjinetes[i], habilidadJinete(gen));
        caballo c(nombresCaballos[i], velocidadCaballo(gen));
        p.asignarCaballo(c);
        cout << zarsuela.nuevoParticipante(p) << endl;

    }
    for (int j = 0; j < cantidadDeCarreras; ++j) {
        zarsuela.tablaGeneral();
        zarsuela.carrera();
    }

    return 0;
}
