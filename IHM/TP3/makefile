CC = g++ -g

drawtri : main.o mainframe.o dialogs.o triangle.o
	$(CC) -o drawtri main.o mainframe.o dialogs.o triangle.o `wx-config --libs`

main.o : main.cpp 
	$(CC) `wx-config --cxxflags` -c main.cpp -o main.o

mainframe.o : mainframe.cpp
	$(CC) `wx-config --cxxflags` -c mainframe.cpp -o mainframe.o
	
dialogs.o : dialogs.cpp
	$(CC) `wx-config --cxxflags` -c dialogs.cpp -o dialogs.o
	
triangle.o : triangle.cpp
	$(CC) `wx-config --cxxflags` -c triangle.cpp -o triangle.o






clean : 
	rm -f *.o drawtri 
	
