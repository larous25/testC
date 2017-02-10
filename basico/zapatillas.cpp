# include <iostream>
# include <string>
# include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;

// definicion de la clase
class Zapatos 
{
	// declaración de variables privadas
	// solo esta clase puede conocer su contenido
	string tipo;
	string marca;
public: // declaración de todas las funciones y variables publicas
	// constructor de la clase
	Zapatos();
	// destructor de la clase 
	~Zapatos();

	// aqui por que solo se declara el prototipo de la funcion
	// que retorna y cuales variables va a utilizar
	void consegirTipo(string);
	string retornarTipo() const;
	void consegirMarca(string);
	string retornarMarca() const; 
};

// aqui se declara la función como tal
Zapatos::Zapatos()
{
	tipo = "";
	marca = "";
};
// este vendria siendo el destructor por defecto
// con un cuerpo vacio
Zapatos::~Zapatos()
{
};

void Zapatos::consegirTipo(string tipo)
{
	this->tipo = tipo;
};

string Zapatos::retornarTipo() const
{
	return tipo;
};

void Zapatos::consegirMarca(string marca)
{
	this->marca = marca;
};

string Zapatos::retornarMarca() const
{
	return marca;
};

// esto es una herencia del tipo publico
class Botas: public Zapatos 
{
	string uso;
public:
	//esto es un constructor con una variable por defecto
	Botas(string="Botas");
	~Botas();
	void consegirUso(string);
};


Botas::Botas(string tipo) 
{
	uso = "";
	this->consegirTipo(tipo);
};

Botas::~Botas()
{
 cout << "eliminando botas"; // esto se ejecuta al momento de eliminar el objeto botas
};

void Botas::consegirUso(string)
{
	this->uso = uso;
};


int main(void) 
{
	cout << "tipos de Zapatos que tengo en el armario" << endl;
	// se instancia un objeto de la clase zapatos
	// en realidad es un puntero que apunta a la direción de un 
	// objeto por eso se utiliza el operador ->
	Zapatos* adidaz = new Zapatos; 
	adidaz->consegirTipo("zapatilla");
	adidaz->consegirMarca("falsificacion");
	cout << "su zapato es del tipo:\t" << adidaz->retornarTipo() << endl;
	cout << "de la marca:\t" << adidaz->retornarMarca() << endl;
	delete adidaz;
	// se instancia un objeto de la clase botas pero 
	// de variable de ambito (solo tendra vida dentro de esta función) 
	Botas punk;
	punk.consegirMarca("rastrojeras");
	punk.consegirUso("para pogo");
	cout << "su bota es del tipo:\t" << punk.retornarTipo() << endl;
	cout << "de la marca:\t" << punk.retornarMarca() << endl;
	return 0;
}