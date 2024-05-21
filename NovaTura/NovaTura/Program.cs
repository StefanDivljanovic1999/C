using System.Numerics;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;

public enum Tip { Biznis, Privatni}
public enum Oznaka { A,B,C,D,E,F}
public struct Odgovor
{
    public Oznaka? oznaka;
    public string tekst;
}
public struct Poeni
{
    public int tacno;
    public double netacno;

    
}
public class Pitanje
{
    public byte rb;
    public string tekst;
    public Tip tip;
    public Poeni poeni;
    public Odgovor resenje;

    public  void A(in Tip tip) => this.tip++;
}

public enum Vrsta { Kreditna, Debitna }
public interface IPrikaz { string Prikazi(); }
public struct Datum
{
    public short mesec; public int godina;
}
public class Kartica
{
    public string vlasnik; public Datum vaziDo; public Vrsta vrsta; public double stanje;
}
public enum Rok { Januar, Februar, Jun, Jul, Septembar, Oktobar }
public struct Index
{
    public int broj; public int godina;
}
public class Ispit
{
    public string predmet; public Index student; public Rok rok;
    public double brojPoena; public int ocena;
}
//public enum Tip { Biznis, Privatni }
public struct Paket
{
    public string naziv;
    public int poruka;
    public byte minuta;
    public int kB;

   

}
public class Ugovor
{
    public string broj;
    public Paket paket;
    public Tip tip;
    public double cena;

    
}









/*public class Proba
{
static void A(Odgovor a, ref Odgovor b)
{
    b = a; b.oznaka += 2;
}
static void B(Pitanje x, Pitanje y)
{
    x.resenje.oznaka = Oznaka.C;
    y = x;
    A(b: ref x.resenje, a: y.resenje);
}
public static void Main()
{
    Pitanje p1 = new Pitanje();
    Pitanje p2 = new Pitanje();
    Pitanje p3 = (p1 == p2) ? p1 : p2;
    Poeni x1 = new Poeni(); x1.tacno = 5;
    Poeni x2 = new Poeni(); x2.tacno = 5;
    Poeni x3 = x1;
    p1.poeni = x1; p2.poeni = x2; p3.poeni = x3;
    p1.tip++; x1.tacno += 10; x3.tacno++;
    Pitanje p4 = (p1.tip == p3.tip) ? p3 : p2;
    p4.poeni.tacno += x1.tacno;
    Console.Write($"{x3.tacno}/{p4.poeni.tacno}");
}
}*/

/*public class Count
{
    private static int k = 0;
    public int counter() { return ++k; }
    public static void Main()
    {
        Count c1 = new Count(); Count c2 = new Count();
        Console.WriteLine("counter = " + c1.counter());
        Console.WriteLine("counter = " + c2.counter());
        Console.WriteLine("counter = " + c1.counter());
    }
}*/
public class Count
{
    private static int k = 0;
    public void counter() { ++k; }
    public int getCounter() { return k; }
}
/*public class Test
{
    public static void Main()
    {
        try
        {
            Pitanje p = new Pitanje(); Odgovor o = new Odgovor();
            try
            {
                byte z = (byte)Convert.ToInt32("5");
                o.oznaka = (Oznaka)z; Console.Write(o.oznaka);
                p.resenje = o;
            }
            catch (Exception e) { Console.WriteLine(1); }
            finally { Console.Write(2); }
           // checked { p.rb--; }
            Console.Write(o.tekst);
        }
        catch (NullReferenceException) { Console.Write(3); }
        catch (ArithmeticException) { Console.Write(4); }
        catch (Exception) { Console.WriteLine(5); }
        finally { Console.Write(6); }

    }
}*/

class PassByVal
{
    static void Izmena(int[] pniz)
    {
        pniz[0] = 100;
        pniz = new int[3] { -40, -10, 35 };
        Console.WriteLine("U metodi Izmena: {0}", pniz[0]);
    }
    static void Main()
    {
        Pitanje[] c = new Pitanje[3];
        Console.WriteLine(c[2].rb);
    }
}





