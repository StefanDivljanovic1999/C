// See https://aka.ms/new-console-template for more information
using System.Diagnostics.CodeAnalysis;
using System.Security.Cryptography.X509Certificates;

enum Enumeracija
{
    Prolece = 0, Leto,
    Jesen = 4,
    Zima = 3
}
class Broj
{
    public int vrednost; private int a; public Broj(int a)
    {
        this.a = a;
    }
}
public class Program
{
    void zadatak1()
    {
        Console.WriteLine("Hello, World!");

        int i = 0, j = 2, suma = 10;
        do
        {
            suma--;
            while (j < i + 2)
            {
                j++;
                if (j % 2 == 0)
                {
                    continue;


                }
                suma--;
            }
            i++;
        } while (i < 3);
        Console.WriteLine(--suma);
        Console.WriteLine(i);
        Console.WriteLine(j);
    }
    void zadatak2()
    {
        //public static void Main(string[] args)
        {
            Enumeracija e = new Enumeracija();
            switch (e++)
            {
                case Enumeracija.Prolece: Console.WriteLine("Prolece"); break;
                case Enumeracija.Leto: Console.WriteLine("Leto"); break;
                case Enumeracija.Jesen: Console.WriteLine("Jesen"); break;
                case Enumeracija.Zima: Console.WriteLine("Zima"); break;
            }





        }
    }
    public enum Operacija { Kvadrat, Plus = 2, Puta, Minus = 1, Podeljeno = 4 }

    enum Enumeracija
    {
        Prolece = 2, Leto,
        Jesen = 4,
        Zima = 1
    }

    // public enum Smer { UK = 2, ISIT, OM = 4, MN = 1 }

    /* public enum Smer
     {
  OM = 3, ME = 1, UK, ISIT = 4
     }*/
    public enum Smer { UK = 2, ISIT, OM = 4, ME = 1 }

    public static void povecaj(out int a)
    {
        a = 30;
        a += 5;
    }

    public class Student { public int ocena; }

    public static void promeniOcenu(Student s)
    {
        s.ocena = 10;
    }

    static void m1(ref int a, Broj b)
    {
        b.vrednost = a; a += 100;
    }
    static void m2(ref int a, Broj b)
    {
        b = new Broj(a); a += 100;
    }
    static void m1(int a, Broj b)
    {
        b.vrednost = a; a += 100;
    }
    static void m2(int a, Broj b)
    {
        b = new Broj(a); a += 100;
    }
    /* public class Klasa
     {
         public int x; public int y;
         public Klasa(int x, int y) { this.x = x; this.y = y; }
         public Klasa() { x = 12; y = 5; }
         public class Program
         {
             public static void Main(string[] args)
             {
                 Klasa k1 = new Klasa(5, 7);
                 Klasa k2 = new Klasa();//12,5
                 Klasa k3 = k1;
                 k3.x = k2.y + 10; Klasa k4 = k2;
                 k3 = k4;
                 k3.y = 4 + k4.x; k2.x = 11 + k1.y; k4.x = 2;
                 Console.WriteLine("X i Y za k1:" + k1.x + " " + k1.y); Console.WriteLine("X i Y za k3:" + k3.x + " " + k3.y);
             }
         }
     }*/

    public class Podatak
    {
        public int broj = 10;
        public void M(int broj) { broj = this.broj; }
        public void M(ref int broj) { broj += broj; }
    }
    /* class Program1
     {
         static void Main(string[] args)
         {
             Podatak x = new Podatak(); 
             x.M(ref x.broj);
             x.M(x.broj);
             Console.WriteLine(x.broj != 10 ? "x" : "y");
             Console.WriteLine(x.broj);
         }
     }*/
    public struct Struktura
    {
        public int x, y;
        public Struktura(int x, int y)
        {
            this.x = x; this.y = y;
        }
    }
    /* public class Program1
     {
         public static void Dodaj(ref int x, int y)
         {
             x = x - 3; y = y + 20;
         }
         public static void Oduzmi(int x, ref int y)
         {
             x = ++x; y += x;
         }
         public static void Pomnozi(int x, ref int y)
         {
             x = x++; y += x;
         }
         public class A
         {
             private int broj = 5;
         }
         public static void Main(string[] args)
         {

         }
     }*/
    public class A
    {
        private int x = 3;
        public void X(int i) { x += i; i = x + 3; }
        public void X(ref int i) { x += i; i = x + 2; }
        public void Y(out int i) { i = x + 1; x += i; }
        public void Z() { Console.Write(x); }
    }
    public class Klasa
    {
        public int x = 4; public int y = 2;
        public Klasa(int x, int y)
        {
            x = 1;
            y = 5;
        }
        public Klasa()
        {
            x = 7;
            y = 5;
        }
    }
    public class Razlomak
    {
        public int brojilac; public int imenilac;
        public Razlomak(int brojilac, int imenilac) { this.brojilac = brojilac; this.imenilac = imenilac; }
    }


    public class Program1
    {
        public static void Dodaj(Razlomak x, int y)
        {
            x.brojilac += y;
        }
        public class TIndex { public int broj; }
        public class Primer
        {
            static void Proba(int i)
            { i += 1; }
            static void Proba(TIndex i)
            { i.broj -= 2; }




            public class Klasa
            {
                public int x = 4; public int y = 2;
                public Klasa(int x, int y)
                {
                    x = 1;
                    y = 5;
                }
                public Klasa()
                {
                    x = 1;
                    y = 5;
                }
            }
            public class Program1
            {
                public static void Main(string[] args)
                {
                    Klasa k1 = new Klasa(5, 2); Console.WriteLine(k1.x); Console.WriteLine(k1.y);
                    //k1,k3 4//5 2
                    Klasa k2 = new Klasa();
                    //k2 1 5
                    Klasa k3 = k1;
                    //Console.WriteLine(k3);
                    //Console.WriteLine(k1); if (k1 == k2 )
                    Console.WriteLine("k1 i k2 su ISTI"); //N if (k1.x == k2.x)
                    Console.WriteLine("k1 i k2 su ISTI"); //N if (k3 == k1)
                    Console.WriteLine("k1 i k3 su isti"); //T Console.WriteLine(k1.x);//4
                    k3.y = 5;
                    if (k1.y == k2.y)
                        Console.WriteLine("k1.y = " + k1.y + " k2.y = " + k2.y);
                }
            }
        }

    }
}