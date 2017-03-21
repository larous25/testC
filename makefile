once:
	g++ -std=c++11 ./basico/${NOMBRE} -o hola.exe
	./hola.exe

two:
	g++ -std=c++11 ./basico/${NOMBRE} -o hola.exe
	./hola.exe ${ARG} ${ARG2}  ${ARG3}

medium:
	g++ -std=c++11 ./intermedio/${NOMBRE} -o hola.exe
	./hola.exe 

