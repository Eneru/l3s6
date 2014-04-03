import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;
import org.omg.CORBA.*;
import java.io.*;


public class Client 
    extends Applet
    implements ActionListener {

    TextField texte = new TextField("",10);
    Label intitule = new Label("Nom a rechercher : ");
    Button bouton = new Button("Envoie");
    Annuaire annuaire;

   public void init() 
   {
		add(intitule);
        add(texte);
        add(bouton);
        bouton.addActionListener(this);

        try
        {
            ORB orb = ORB.init(this, null);
            FileReader file= new FileReader(iorfile.value);
            BufferedReader in= new BufferedReader(file);
            String ior = in.readLine();
            file.close();
            org.omg.CORBA.Object obj = orb.string_to_object(ior);
            annuaire = AnnuaireHelper.narrow(obj);

        }
        catch(org.omg.CORBA.SystemException ex)
        {
            System.err.println( "Error" );
            ex.printStackTrace();
        }
        catch(FileNotFoundException fnfe)
        {
            System.err.println(fnfe.getMessage());
        }
        catch(IOException io)
        {
            System.err.println(io.getMessage());
        }
        catch(Exception e)
        {
            System.err.println(e.getMessage());
        }

    }

    public void actionPerformed(ActionEvent ae)
    {
            org.omg.CORBA.StringHolder str = new org.omg.CORBA.StringHolder();
            annuaire.chercheNom(texte.getText(), str);
            intitule.setText(str.value);
    }
}
