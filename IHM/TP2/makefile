CC = g++

drawtri : main.o mainframe.o dialogs.o
	$(CC) -o drawtri main.o mainframe.o dialogs.o `wx-config --libs`

main.o : main.cpp 
	$(CC) `wx-config --cxxflags` -c main.cpp -o main.o

mainframe.o : mainframe.cpp
	$(CC) `wx-config --cxxflags` -c mainframe.cpp -o mainframe.o
	
dialogs.o : dialogs.cpp
	$(CC) `wx-config --cxxflags` -c dialogs.cpp -o dialogs.o






clean : 
	rm -f *.o drawtri 
	
