CC = g++

MFLAGS = `wx-config --libs --gl-libs`
IFLAGS = -Iinclude `wx-config --cxxflags`

OPATH = obj/
BPATH = bin/

vpath %.cpp src/
vpath %.h include/
vpath %.o obj/

drawtri : main.o mainframe.o dialogs.o triangle.o openglcanvas.o | bin
	$(CC) -o $(BPATH)drawtri $(OPATH)main.o $(OPATH)mainframe.o $(OPATH)dialogs.o $(OPATH)triangle.o $(OPATH)openglcanvas.o $(MFLAGS)

triangle.o : triangle.cpp triangle.h
openglcanvas.o : openglcanvas.cpp openglcanvas.h mainframe.h
dialogs.o : dialogs.cpp dialogs.h triangle.h mainframe.h
mainframe.o : mainframe.cpp mainframe.h dialogs.h openglcanvas.h
main.o : main.cpp mainframe.h

%.o : %.cpp | obj
	$(CC) -o $(OPATH)$@ -c $< $(IFLAGS)

obj :
	@mkdir -p $(OPATH)

bin :
	@mkdir -p $(BPATH)

clean :
	@rm -f $(OPATH)* $(BPATH)*
	@rmdir $(OPATH) $(BPATH)
	@echo "Nettoye."
	
