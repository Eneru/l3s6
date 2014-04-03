import org.omg.CORBA.*;
import java.io.*;

public class Supprime 
{
    public static void main(String [] args) 
    {
        if (args.length != 1) 
            System.out.println("Usage : java Supprime <nom>");
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
                annuaire.enleverNoms( args[0] );
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
    }
}
