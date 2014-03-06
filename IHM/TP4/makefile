CC = g++ -g

drawtri : main.o mainframe.o dialogs.o triangle.o openglcanvas.o
	$(CC) -o drawtri main.o mainframe.o dialogs.o triangle.o openglcanvas.o `wx-config --libs --gl-libs`

main.o : main.cpp 
	$(CC) `wx-config --cxxflags` -c main.cpp -o main.o

mainframe.o : mainframe.cpp
	$(CC) `wx-config --cxxflags` -c mainframe.cpp -o mainframe.o

openglcanvas.o : openglcanvas.cpp
	$(CC) `wx-config --cxxflags` -c openglcanvas.cpp -o openglcanvas.o
	
dialogs.o : dialogs.cpp
	$(CC) `wx-config --cxxflags` -c dialogs.cpp -o dialogs.o
	
triangle.o : triangle.cpp
	$(CC) `wx-config --cxxflags` -c triangle.cpp -o triangle.o






clean : 
	rm -f *.o drawtri 
	
