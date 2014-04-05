all:
	idlj -fall OpMatrice.idl
	javac OpMatriceImpl.java
	javac Serveur.java
	javac Client.java

clean:
	rm -f *~ .pok *Operations.java *Helper.java *Holder.java *POA.java *.class _* ior iorfile.java OpMatrice.java
	killall java
