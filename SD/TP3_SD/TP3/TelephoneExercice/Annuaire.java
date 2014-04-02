import java.awt.*; 

public interface Annuaire extends java.rmi.Remote {
    String chercheNom(String nom) throws java.rmi.RemoteException;
    void ajout(String nom, String num) throws java.rmi.RemoteException;
    void supprime(String nom) throws java.rmi.RemoteException;
    java.awt.List affiche() throws java.rmi.RemoteException;
}
