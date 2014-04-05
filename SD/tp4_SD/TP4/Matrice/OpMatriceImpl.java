import org.omg.CORBA.*;

public class OpMatriceImpl extends OpMatricePOA
{
    public int[][] multiplicationMatrice( int[][] a, int[][] b)
    {
        if(a[0].length == b.length)
        {
            int[][] c= new int[a.length][b[0].length];
            for(int i=0; i < a.length; i++)
                for(int j=0; j < b[0].length; j++)
                {
                    c[i][j]=0;
                    for(int k=0; k < a[0].length; k++)
                        c[i][j]+=a[i][k]*b[k][j];
                }
            return c;
        }
        
        else
        {
            int[][] err=new int[1][1];
            err[0][0]=0;
            return err;
        }
    }
}
