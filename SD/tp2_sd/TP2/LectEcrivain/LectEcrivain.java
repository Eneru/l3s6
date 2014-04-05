class ZonePartage extends Thread 
{
    int nLecteurs;
    int nEcrivainsEnAttente;
    Object accesslock;
    boolean lock;

    ZonePartage() 
    {
		nLecteurs = 0;
		nEcrivainsEnAttente = 0;
		lock = false;
        accesslock = new Object();
    }

    public synchronized void accesPartage() 
    {
		synchronized(accesslock)
		{
			nLecteurs++;
			while(nEcrivainsEnAttente>0 && lock) // On attend la disponibilité de la ressource
				try 
				{
					wait();
				}
				catch(InterruptedException e) {}; 
		}
    }
    
    public synchronized void retourPartage() 
    {
		synchronized(accesslock)
		{
			nLecteurs--;
		}
    }
    
    public synchronized void accesExclusif() 
    {
		synchronized(accesslock) 
		{
			nEcrivainsEnAttente++;
			if (lock==true) // bloque si quelqu'un écrit déjà
			{
				try 
				{
					wait();
				} 
				catch(InterruptedException e) {}; 
			}
		}
    }
    
    public synchronized void retourExclusif() 
    {
		synchronized(accesslock) 
		{
			nEcrivainsEnAttente--;
			lock=false; // On débloque la ressource
			
			notifyAll();
		}
    }
}    

class Reader extends Thread 
{
    ZonePartage z;
    int nbLu = 0;
    
    Reader (ZonePartage z, String name) 
	{
		super(name);
		this.z = z;
    }
    public void run() 
    {
        while (true)
			lecture();
    }
    
    public void lecture() 
    {
		z.accesPartage();
		nbLu++;
		System.out.println("Lecture " +nbLu);
		z.retourPartage();
    }
    
}

class Writer extends Thread {
    ZonePartage z;
    int nbEcrit=0;
    
    Writer (ZonePartage z, String name) 
    {
		super(name);
		this.z = z;
    }
    
    public void run() 
    {
        while (true)
			ecriture();
    }
    
    public void ecriture()
    {
		z.accesExclusif();
		nbEcrit++;
		System.out.println("Ecriture "+nbEcrit);
		z.retourExclusif();
    }
}

public class LectEcrivain {
    public static void main(String args[]) {
	ZonePartage z = new ZonePartage();
	Thread r1 = new Reader(z,"r1");
	Thread r2 = new Reader(z,"r2");
	Thread r3 = new Reader(z,"r3");
	Thread r4 = new Reader(z,"r4");
	Thread w1 = new Writer(z,"w1");
	Thread w2 = new Writer(z,"w2");
	r1.start();
	r2.start();
	r3.start();
	r4.start();
	w1.start();
	w2.start();
    }
}
