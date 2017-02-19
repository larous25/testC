# include <iostream>
// # include <exception>

// using std::exeption;
using std::cout;


int main(void)
{
	try{
		throw "hola soy un error";
	}catch(char* e){ 
		cout << "tienes un error" << e;
	}
	return 0;
};