import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.BufferedReader;
import org.omg.CORBA.*;

public class Client
{
	static int numM = 0;
    public static void main (String args[])
    {
        int[][] a = { {1, 0, 0}, {0, 2, 0}, {0, 0, 3}, {0, 0, 4} };
        int[][] b = { {1, 2, 3}, {1, 2, 3}, {1, 2, 3} };
        int[][] c;
        
        if(args.length != 0)
        {
            System.out.println( "Use: java Client" );
            System.exit( 1);
        }

        try
        {
            ORB orb = ORB.init(args, null);
            FileReader file;
            BufferedReader in;
            String ior;
            
            
            try
            {
				file = new FileReader(iorfile.value);
				in = new BufferedReader(file);
				ior = in.readLine();
				file.close();
				
				org.omg.CORBA.Object obj = orb.string_to_object(ior);
				OpMatrice service= OpMatriceHelper.narrow(obj);
				System.out.println("Matrices qui vont être multiplies enesemble :");
				display_m(a);
				display_m(b);

				c = service.multiplicationMatrice(a, b);
				System.out.println( "Le serveur a calculé\n" );
				display_m(c);
			}
            
            catch (FileNotFoundException fnfe) 
			{ 
				System.err.println(fnfe.getMessage());
			}
			catch (IOException io)
			{ 
				System.err.println(io.getMessage());
			}
        }
        
        catch(org.omg.CORBA.SystemException ex)
        {
            System.err.println( "Error" );
            ex.printStackTrace();
        }
    }

    static void display_m(int[][] matrix)
    {
        System.out.println("Matrice " + (++numM)+" : ");
        
        for(int i=0; i < matrix.length; i++)
        {
			System.out.print("(\t");
            for(int j=0; j < matrix[0].length; j++)
                System.out.print(matrix[i][j]+"\t");
            System.out.println(")");
        }
        System.out.println("\n");
    }
}
