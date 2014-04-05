import org.omg.CORBA.*;
import java.io.*;


public class Ajoute 
{
    public static void main(String [] args) 
    {
		if (args.length != 2)
            System.out.println("Usage : java Ajoute <nom> <numero>");
        else 
        {
            try
            {
                ORB orb = ORB.init(args , null);
                FileReader file= new FileReader(iorfile.value);
                BufferedReader in= new BufferedReader(file);
                String ior = in.readLine();
                file.close();
                
                org.omg.CORBA.Object obj = orb.string_to_object(ior);
                Annuaire annuaire = AnnuaireHelper.narrow(obj);
                annuaire.ajouterNoms( args[0], args[1] );
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
                System.err.println("De la merde ouech");
            }
        }
    }
}
