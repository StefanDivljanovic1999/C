using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Transactions;

/*class proba
{
    public static int x;
    public static int y;
   
    public static void metoda1( int x, int y = 5)
    {
        proba.x = x;
        proba.y = y;
    }
}*/

/* class program
{
    public static int x;
    public static int y;

    public static void metoda1(int x, int y = 5)
    {
        program.x = x;
        program.y = y;
        int z = program.x;
        int g = program.y;
        Console.WriteLine("z: "+z+" g:"+g);
    }
    public static void Main(string[] args)
    {
        int x = 12;
        int y = 3;

        metoda1(x);
        Console.WriteLine(program.x + " " + program.y);


    }


}*/

/*public class Program
{
    public static int x; public static int y;
    public static void metoda1(int x, int y = 5)
    {
        Program.x = x; Program.y = y;
        int z = Program.x;
        int g = Program.y;
        metoda2(z, g); //12, 5 override-uju opcione vrednosti parametara
    }
    public static void metoda2(int y = 1, int x = 2)
    {
        Program.x = x; //5
        Program.y = y; //12
    }
    public static void Main(string[] args)
    {
        int x = 12; int y = 3; metoda1(x);
        Console.WriteLine("x: "+Program.x + "y: " + Program.y);
    }
}*/
/*public class Program
{
    public  int x = 1;
    public void Prikazi1() { Console.Write(x); }
    public static void Prikazi2() { Console.Write(x); }
    public void Saberi2() { x += 2; }
    public static void Saberi3() { x += 3; }
    static void Main()
    {
        Program p = new Program();
        Console.WriteLine("x na pocetku: "+p.x);
        p.Saberi2();
        Console.WriteLine("x posle saberi 2: " +p.x);

        p.Prikazi1(); Saberi3(); Prikazi2(); p.Prikazi1();
    }
}
*/

/*public class Test
{
    public static int x = 0; public void D()
    {
        Console.WriteLine(x + " ");
    }
    public static void D1()
    {
        Console.WriteLine(x + " ");
    }
    public void A()
    {
        x = x + 2;
    }
    public static void A1()
    {
        x = x + 1;
    }
    public static void Main(string[] args)
    {
        Test.A1();
        Console.WriteLine(x);
        Test t1 = new Test();
        Console.WriteLine(x);
        t1.A();
        t1.D(); // sada je x = 3
        Test t2 = new Test(); t2.A(); t2.D(); Test.D1();
    }
}*/
/*public class Test
{
    public static int y = 0;
    public void D(int x) { Console.WriteLine(x + " " + y); }
    public static void D1(int x) { y++; Console.WriteLine(y + " " + x); }
    public void A() { y = y + 2; }
    public static void A1() { y = y + 1; }
    public static void Main(string[] args)
    {
        Test.A1();
        Test t1 = new Test(); t1.A(); t1.D(2);
        Test t2 = new Test(); t2.A(); t2.D(3);

        Test.D1(5);
    }
}*/

/*public class Tindex { public int broj; }
public class Primer
{
    static void Proba(int i) { i += 1; }
    static void Proba(Tindex i) { i.broj -= 2; }
    public static void Main()
    {
        Tindex index = new Tindex();
        Console.WriteLine(index.broj);
        Proba(index.broj);
        Console.WriteLine(index.broj);
        Proba(index);
        //Console.WriteLine(index.broj);
    }
}*/
/*public class Tindex { public int broj; }
public class Primer
{
    static void Proba(ref int i) { i += 1; }
    static void Proba(ref Tindex i) { i.broj -= 2; }
    public static void Main()
    {
        Tindex index = new Tindex(); 
        Proba(ref index.broj);
        Proba(ref index);
        Console.WriteLine(index.broj);
    }
}*/
/*ublic class A
{
    private static int x = 4;
    public void M1(int i) { i = 3; x += i; }
    public void M2(out int i)
    {
        i = 2;
        x += i;
    }
    public void M3(ref int i)
    {
        i = 1;
        x += i;
    }

    public static void M4() { Console.Write(x); }
    static void Main()
    {
        int a = 5;
        A b = new A(); 
        A c = new A();
        b.M3(ref a);
        b.M2(out a);
        b.M1(a);
        c.M3(ref a);
        c.M2(out a);
        c.M1(a);

        A.M4();
    }
}*/
/*public class Tindex { public int broj; }*/
public struct Datum
{
    public short mesec; public int godina;
}
public enum Vrsta { Kreditna, Debitna }
public class Kartica
{
    public string vlasnik; public Datum vaziDo; public Vrsta vrsta; public double stanje;
}
public class G
{
    public static void Promeni(Datum d)
    { d.mesec--; d.godina++; }
    public static void M(ref Kartica k, Kartica k1)
    { k.stanje += 1; k1.stanje += 1; 
        //k = k1;
        }
    public static void M(Kartica k, ref Kartica k1)
    { k.stanje += 2; k1.stanje += 2; //k = k1; 
    }
}



public class Primer
{

    static void setstr1(ref string s)
    {
        s = "dva";
    }
    static void setstr2(out string s)
    {
        s = "tri";
    }
    static void setstr3(string s)
    {
        s = "pet";
    }
    public static void Main(string[] args)
    {
        string s1 = "xyz"; string s2 = "zyx"; string s3 = "xyz"; string s4;
        s4 = (s1 != s3 || s1[1] == s2[1]) ? s3 : "cba"; s2 = s3;
        s3 = "abc";
        if (s2 == s3) Console.WriteLine(s2[1]); else Console.WriteLine(s4[1]);
    }
}
