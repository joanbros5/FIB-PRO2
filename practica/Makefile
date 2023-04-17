OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Espera.o Area_Emmagatzematge.o Cjt_Contenedores.o Cjt_Huecos.o Contenedor.o Segmento.o Ubicacion.o
	g++ -o program.exe *.o
	
Area_Emmagatzematge.o: Area_Emmagatzematge.cc Area_Emmagatzematge.hh Cjt_Contenedores.hh Contenedor.hh Ubicacion.hh Cjt_Huecos.hh Segmento.hh
	g++ -c Area_Emmagatzematge.cc $(OPCIONS)
	
Espera.o: Espera.cc Espera.hh Contenedor.hh Ubicacion.hh
	g++ -c Espera.cc $(OPCIONS)
	
Contenedor.o: Contenedor.cc Contenedor.hh
	g++ -c Contenedor.cc $(OPCIONS)

Ubicacion.o: Ubicacion.cc Ubicacion.hh
	g++ -c Ubicacion.cc $(OPCIONS)
	
Segmento.o: Segmento.cc Segmento.hh Ubicacion.hh
	g++ -c Segmento.cc $(OPCIONS)
	
Cjt_Contenedores.o: Cjt_Contenedores.cc Cjt_Contenedores.hh Contenedor.hh Ubicacion.hh
	g++ -c Cjt_Contenedores.cc $(OPCIONS)
	
Cjt_Huecos.o: Cjt_Huecos.cc Cjt_Huecos.hh Segmento.hh Ubicacion.hh
	g++ -c Cjt_Huecos.cc $(OPCIONS)

program.o: program.cc Espera.hh Area_Emmagatzematge.hh Cjt_Contenedores.hh Cjt_Huecos.hh Contenedor.hh Segmento.hh Ubicacion.hh
	g++ -c program.cc $(OPCIONS)

practica.tar:
	tar -cvf practica.tar program.cc Area_Emmagatzematge.* Cjt_Contenedores.* Cjt_Huecos.* Contenedor.* Espera.* Segmento.* Ubicacion.* html.zip Makefile

clean:
	rm -f *.o
	rm -f *.exe
