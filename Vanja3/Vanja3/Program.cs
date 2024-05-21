using System.Numerics;
using System.Runtime.Intrinsics.X86;
using System.Security.Cryptography;
using System.Threading.Channels;

public class Osoba
{
    public string ime;
    public int broj;
}

public class Datum
{
    public short mesec; public int godina;
}

public class Broj
{
    public int x; public Broj(int x)
    {
        this.x = x;
    }
}
public class TOblik { public int povrsina; }

public class Razlomak
{
    public int brojilac; public int imenilac;
    public Razlomak(int brojilac, int imenilac)

    {
        this.brojilac = brojilac; 
        this.imenilac = imenilac;
    }
}
public class TIndex { public int broj;
   // public void A(int broj) { broj += this.broj; }
   // public void B(ref int broj) { broj += broj; }
    //public void C(int broj) { this.broj += this.broj; }
    //public void D(out int broj) { this.broj += broj; }
    //public  void E(int broj) { this.broj += broj; }

}

public enum Kurs {Matematika, Programiranje, Baze, Softveri };

public class Klasa
{
    public int x; public int y;
    public Klasa(int x, int y) { this.x = x; this.y = y; }
    public Klasa() { x = 12; y = 5; }
    public class Program
    {
        public static void Dodaj(Razlomak x, int y)
        {
            x.brojilac += y;
        }
        static void Proba(int i)
        { i += 1; }
        static void Proba(TIndex i)
        { i.broj -= 2; }
        static void plus(int i)
        {
            i++;
        }
        public int dodaj(int x, int y)
        {
            return x + y;
        }

        public int zbir(params int[] brojevi)
        {
            int suma = 0;
            for (int i = 0; i < brojevi.Length; i++)
            {
                suma += brojevi[i];
            }
            return suma;
        }
        public enum Rok { Januar, Februar, Jun, Jul, Septembar, Oktobar }
        /* int M(Rok v, ref int i, short s) => 0;
         //int M(Rok v, int i, short s) => 0;
         int M(Rok v, ref int i, int s) => 0;
         //int M(Rok v, out int i, short s) => 0;
         //static int M(Rok v, ref int i, short s) => 0;
         //public int M(Rok v, ref int i, short s) => 0;
         //void M(Rok v, int i, short s) => 0;*/

        float Metoda(long a, ref int b, Rok c = Rok.Jul)
        {
            float f = 2; int d = 2;
            if (a > b) return f; else return d;
        }

        public class Primer
        {
            public char Proba(double d, string b) { return 'a'; }
            //public char Proba(double c, string a) { }
            //public char Proba(string b, double d) { return 'a'; }
            //public char Proba(ref double c, string b) { return 'a'; }
            //public string Proba(double d, string b) { return "aa"; }
            //public char Proba(string d, string b) { return 'a'; }
            //protected char Proba(double d, string b) { return 'a'; }

        }

        public class Razlomak
        {
            public int brojilac; public int imenilac;
            public Razlomak(int a, int b) { imenilac = b; brojilac = a; }
            public Razlomak() { }
            public static Razlomak operator +(Razlomak r1, Razlomak r2)
            {
                Razlomak r = new Razlomak(); r.imenilac = r1.imenilac * r2.imenilac;
                r.brojilac = r1.imenilac * r2.brojilac + r2.brojilac *
                r1.imenilac;
                return r;
            }
        }

        /* public class Broj
         {
             public int broj;
             public Broj(int b) { broj = b; }
             public static Broj operator *(Broj b, int a)
             { b.broj += a; return b; }
         }
         public class Podatak
         {
             public Broj vrednost;
             public Podatak(int v) { vrednost = new Broj(v); }
             public static Podatak operator *(Podatak p, int a)
             { p.vrednost *= a; return p; }
         }*/

        /* public class Broj
         {
             public int broj = 2;
             public static Broj operator *(Broj b, int a)
             { Broj c = new Broj(); c.broj = b.broj * a; return c; }
             public static int operator *(Broj a, Broj b) { return b.broj * a.broj; }
         }*/
        /* public class Broj
         {
             public int broj;
             public static int operator *(Broj b, int a) { return b.broj + a; }
             public static int operator *(int a, Broj b) { return b.broj - a; }
             public static int operator *(Broj a, Broj b) { return b.broj * a.broj; }
         }*/
        /* public class Broj
         {
             public int broj = 3;
             public static int operator *(Broj b, int a)
             { return a + b.broj; }
             public static int operator *(int a, Broj b)
             { return a - b.broj; }
         }
             public static void Main(string[] args)
         {
             Broj broj1 = new Broj(); 
             int broj2 = 5;
             broj2 *= broj1; Console.WriteLine(broj2);
             broj2 *= broj1.broj; Console.WriteLine(broj2);
             Console.WriteLine(broj2);
         }*/
        /* public class Broj
         {
             public int broj = 2;
             public static double operator /(int x, Broj b) { return x / b.broj; }*/

        /*public class Broj
        {
            public int broj;
            public static int operator *(Broj b, int a)
            {
                return a * b.broj;
            }
            public static int operator *(int a, Broj b)
            {
                return a - b.broj;
            }*/
    }
   


}

static class Prosirenja { public static int Ucm(this int m) => m * 100; }
static class Prosirenja1 { public static int uO(this double poena) => Convert.ToInt32(poena / 10); }
public class Tindeks
{
    public int broj;
}
/*class Program
{

     public class Skup
    {
        int[] niz = new int[]{ 1, 2, 3, 4 };
        public int this[int pozicija]
        {
            get => niz[pozicija];
            set => niz[pozicija] = value;
        }
    }
    public static void Main(string[] args) {
        Skup s = new Skup(); 
        s[0] = 5;
        Console.WriteLine(s[1]);

    }           
}*/

/*class SkupBrojeva
{
    int[] brojevi = new int[6]; public int this[int pozicija]
    {
        get { return brojevi[pozicija + 1]; }
        set { brojevi[pozicija - 1] = value; }
    }
}*/
/*public class Program
{
    public static void Main(string[] args)
    {
        SkupBrojeva skup = new SkupBrojeva(); int suma = 0;
        for (int i = 2; i < 5; i++)
        {
            skup[i] = i;
        }
        for (int i = 0; i < 5; i++)
        {
            suma += skup[i];
            Console.WriteLine(skup[i]);
        }
        Console.WriteLine(suma);
    }
}*/

/*public class Brojevi
{
    int[] niz = new int[] { 5, 6, 7, 8 };
    public int this[int indeks]
    {
        set { niz[indeks + 1] = value; }
    }
    public static void Main(string[] args)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i == 4)
            {
                continue;
            }
            Console.WriteLine(i);
        }
    }
}*/
/*public class Program
{
    class Skup
    {
        public int[] niz = { 0, 1, 2, 3, 4 };
        public int this[int pozicija]
        {
            get { return niz[pozicija - 1]; }
            set { niz[pozicija] = value; }
        }
    }*/
class Skup
{
    public int[] niz = { 2, 3, 4, 5, 6 }; public int this[int pozicija]
    { get { return niz[1 - pozicija]; } }


    public static void ispisi_niz(double[] niz)
    {
        for (int i = 0; i < niz.Length; i++)
        {
            Console.WriteLine(niz[i]);
        }
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
    class Osoba
    {
        string ime; string adresa; int godine;
        public Osoba(string a) { adresa = a; }
        public string Ime { get { return ime; } }
        public int Godine { get { return godine; } }

        public class Razlomak
        {
            int brojilac = 0;
            static int imenilac = 1;
            public void Inicijalizuj(int b, int i)
            {
                brojilac = b; imenilac = i;
            }
            public double izracunaj()
            {
                return brojilac / imenilac;
            }
        }

        public class skup
        {
            public static int x=5;
            private static int a = 4;
            int y;
        }

        /*public class Program
        {
            public static void Main(string[] args)
            {
                skup R = new skup();
                Console.WriteLine(skup.x);
                


            }
        }*/
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

        public class K
        {
            public static void P(Ispit i, Rok r)
            {
                if (r == Rok.Jun) i.brojPoena += 5;
                i.ocena = Convert.ToInt32(i.brojPoena) / 10;
            }
            public static void M(ref Ispit i, Ispit i1)
            { K.P(i1, Rok.Jun); i.ocena = i1.ocena; }
        }
        public class A
        {
            private static int x = 4;
            public void M1(int i) { i = 3; x += i; }
            public void M2(out int i) {i = 2; x += i; }
            public void M3(ref int i){i = 1;x += i;}
            public static void M4() { Console.Write(x); }
            /* static void Main()
             {
                 Ispit x = new Ispit(); Ispit y = new Ispit(); x.ocena = 5; x.brojPoena = 76;
                 y.ocena = 5; y.brojPoena = 86;
                 K.M(ref x, y); Console.Write( x.brojPoena);*/
            /*public class Program
            {
                public static int x = 1;
                public void Prikazi1() { Console.Write(x); }
                public static void Prikazi2() { Console.Write(x); }
                public void Saberi2() { x += 2; }
                public static void Saberi3() { x += 3; }
                static void Main()
                {
                    Program p = new Program(); p.Saberi2();
                    p.Prikazi1(); Saberi3(); Prikazi2(); p.Prikazi1();
                }
            }*/
            public class Program
            {
                public static int x; public static int y;
                public static void metoda1(int x, int y = 5)
                {
                    Program.x = x; Program.y = y;
                    int z = Program.x;
                    int g = Program.y;
                    metoda2(z, g); //12, 5 override-uju opcione vrednosti parametara
                }
                public static void metoda2(int x = 2, int y = 1)
                {
                    Program.x = x; //5
                    Program.y = y; //12
                }
                public static void Main(string[] args)
                {
                    int x = 12;
                    int y = 3;
                    metoda2(x);
                    Console.WriteLine(Program.x + " " + Program.y);
                }
            }
        }
    }
}


