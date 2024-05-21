
/*public class Osoba
{
    public string ime="Stefan";
    private string prezime="Divljanovic";
    protected int godiste=1999;

    public void ispisi()
    {
        Console.WriteLine(ime);
        Console.WriteLine(prezime);
        Console.WriteLine(godiste);
    }
}*/

/*public delegate void Del(int a, ref int b);
public class Program
{
    public static void Plus(int e, ref int f)
    {
        e = f + 5;
        f = e + 5;
    }
    public static void Minus(int e, ref int f)
    {
        e = f - 5;
        f = e - 5;
    }
    public static void Puta(int e, ref int f)
    {
        e = f * 5;
        f = e * 5;
    }
    public int A()
    {
        Console.WriteLine(4);
        return 1;
    }
    static void Main()
    {
      Program p= new Program();
        int x=p.A();
        Console.WriteLine(x);
    }
}
*/

/*public delegate int Delegat();
public class Klasa
{
    public int A() { Console.Write(4); return 1; }
    public int B() { Console.Write(5); return 2; }
    public int C() { Console.Write(6); return 3; }
}
public class Program
{
    public static void Main()
    {
        Klasa x = new Klasa();
        Klasa y = new Klasa();
        Delegat dg = x.A;
        for (int i = 6; i >= 1; i--)
        {
            if (i % 6 == 0) dg += x.B;
            if (i % 5 == 0) dg = y.B;
            if (i % 4 == 0) dg += y.C;
            if (i % 3 == 0) dg -= x.C;
            if (i % 2 == 0) dg += x.A;
        }
        int rezultat = dg();
        Console.Write(rezultat);
       
    }
}*/

/*public delegate int Delegat(ref int n);
public class Klasa
{
    public int p;
    public int A(ref int k) { k++; p += k; return 9; }
    public int B(ref int k) { k++; p += k; return 8; }
    public int C(ref int k) { k++; p += k; return 7; }
}
public class Program
{
    public static void Main()
    {
        Klasa x = new Klasa();
        Klasa y = new Klasa();
        Delegat dg=x.A;
        for (int i = 0; i <= 6; i++)
        {
            if (i % 6 == 0) dg += x.B;
            if (i % 5 == 0) dg = y.B;
            if (i % 4 == 0) dg += x.A;
            if (i % 3 == 0) dg -= y.C;
            if (i % 2 == 0) dg += x.A;
        }
       
        int j = 1;
        int rezultat = dg(ref j);
        
        Console.WriteLine($"{rezultat}{x.p}{y.p}");
        Console.WriteLine(j);
    }
}*/

/*public delegate void Del(int a, ref int b, int c);
public class Program {
    public static void Plus(int e, ref int f, int g) { e += g; f += g; }
    public static void Minus(int e, ref int f, int g) { e -= g; f -= g; } 
    public static void Puta(int e, ref int f, int g) { e *= g; f *= g; } 
    static void Main() {
        Del dg = Minus;
        dg -= Plus;
        dg = Puta;
        dg += Plus;
        dg += Minus;
        dg += Plus;
        dg -= Plus;
        int x = 5, y = 10, z = 15;
        dg(x, ref y, z); 
        Console.WriteLine(x +" "+y); 
    } 
}*/

/*public delegate void Operacija(ref int x);
class Skup { 
    public int[] niz = { 2, 3, 4, 5, 6 };
    public int this[int pozicija] { get { return niz[1 - pozicija]; } 
    }
}
static class Prosirenja{
    public static void Mapiraj(this Skup s, Operacija op) {
        for (int i = 1; i < 4; i++)
            op(ref s.niz[i]); 
    } 
}
class Program
{
    static void Povecaj(ref int x) { x += 5; }
    static void Smanji(ref int x) { x -= 2; }
    static void Main()
    {
        Skup X = new Skup();
        Operacija o = Smanji;
        o += Povecaj;
        X.Mapiraj(o);
        try
        {
            //for (int i = -3; i <= 0; i++) Console.Write(X[i]);
            for (int i = 0; i <= 4; i++)
            {
                Console.WriteLine(X.niz[i]);
            }
        }
        catch (Exception)
        {
            Console.Write("X");
        }
    }
}*/

/*public delegate int Delegat(int a, short b); 
public class Klasa { 
    public int A(ref int a, short b) => a + b; 
    int B(int a, short b) => a + b;
    public static int C(int a, short b) => a + b; 
}
public class Program : Klasa {
    public short D(int a, short b) => 1;
    public static int E(int a, short b) => a + b; 
    public int F(short b, int a) => a + b;
    public static void Main() { 
        Program p = new Program();
        Delegat dg;
        dg = E;
        dg = p.F;
            }
}*/

/*public delegate int Delegat();
public class Klasa { 
   public  int k = 5; 
    public int A() { Console.Write(++k); return 1; }
    public int B() { Console.Write(k); return 2; }
    public int C() { Console.Write(--k); return 3; } 
}
public class Program {
    static void Main() {
        Klasa x = new Klasa();
        Klasa y = new Klasa();
        Delegat dg = x.A; 
        for (int i = 6; i >= 1; i--) {
            if (i % 6 == 0) dg += x.B;
            if (i % 5 == 0) dg = y.B;
            if (i % 4 == 0) dg += y.C;
            if (i % 3 == 0) dg -= x.C;
            if (i % 2 == 0) dg += x.A; 
        } 
        int s = dg();
        // Console.WriteLine(s);
        Console.WriteLine(y.k);
    }
}*/

/*public delegate int Delegat(string a, bool b);
public class Klasa
{
    public int A(ref string a, bool b) { return 10; }
    public short B(string a, bool b) { return 0; }
    public static int C(string a, bool b) { return 0; }
    protected int D(string a, bool b) { return 10; }
}
public class Program : Klasa
{
    public static int E(bool b, string a) { return 10; }
    public int F(bool a, string b) { return 0; }
    static void Main()
    {
        Program p = new Program();
        Delegat dg = C;
    }
}*/

/*class Osoba { }
class Student : Osoba { }
class Program { static int M(int x, int y) => x + y;
    static int Primeni(int v, Func<int, int> f) => f(v);
    static Func<int, int> F1(int z) => x => M(z, x);
    static Func<int, int> F2() => x => M(5, x);
    static Func<int, int> Odredi(Osoba o) => (o is Student) ? F2() : F1(5);
    static void Main() {
        Osoba a = new Student();
        var b = Odredi(a);
        var c = Primeni(7, b);
        Console.WriteLine(c);
    }
}*/

/*class Osoba { }
class Student : Osoba { }
class Program { static int M(int x, int y) => x + y; static int Primeni(int v, Func<int, int> f) => f(v); static Func<int, int> F1(int z) => x => M(z, x); static Func<int, int> F2() => x => M(12, x); static Func<int, int> Odredi(Osoba o) => (o is Student) ? F1(5) : F2(); static void Main() { Osoba a = new Student(); var b = Odredi(a); var c = Primeni(6, b); Console.WriteLine(c); } }
*/

/*class Osoba
{
  public  string ime;
  public  string prezime;
}

class Student: Osoba
{
 public string brojIndeksa;
}

class Program
{
    public static void Main(string[] args)
    {
        Osoba o = new Osoba();
        o.ime = "Stefan";
        o.prezime = "Divljanovic";
        Console.WriteLine("Ime: "+o.ime+", prezime: "+o.prezime);
        Student s=new Student();
        s.ime = "Pera";
        s.prezime = "Mitic";
        
        Console.WriteLine(s.ime +" "+ s.prezime);

    }
}*/

/*class Osoba
{
    public A() : this(5)
    {
        Console.WriteLine("a");
    }



    public static void Main()
    {
        Osoba o1 = new Osoba();
        Osoba o2 = new Osoba();
        Console.WriteLine("{0} {1}", broj1, o2.broj2);
    }
}*/

/*public class Osoba
{
    protected string ime;
}
public class Student : Osoba
{
    string indeks = "1/2016";
    public Student()
    {
        ime = "Nepoznato";
    }
}*/

/*public class Osoba
{
    public string ime;
    public Osoba(string ime)
    {
        this.ime = ime;

    }
    public override bool Equals(object? obj)
    {
        return base.Equals(obj);
    }

}
public class Program
{
    public static void Main(string[] args)
    {
        Osoba o1 = new Osoba("Milos");
        Osoba o2 = new Osoba("Milos");
        if (o1.Equals(o2))
        {
            Console.WriteLine("Radi se o istoj osobi");
        }
        else
        {
            Console.WriteLine("Ne radi se o istoj osobi");
        }
    }
}

/*class A
{
    public A() : this(6) { Console.WriteLine(3); }
    public A(int i) { Console.WriteLine(i); }
}
class B : A
{
    public B() : this(5) { Console.WriteLine(2); }
    public B(int i) { Console.WriteLine(i); }
}
class C : B
{
    public C() : this(4) { Console.WriteLine(1); }
    public C(int i) { Console.WriteLine(i); }
}
public class Proba
{
    public static void Main()
    {
       A a = new A();
        A a1 = new A(5);
        B b = new B();
        A b1 = new B(5);
        //A c = new C();
       A c1 = new C(5);
    }
}*/

/*public abstract class A { }
public abstract class B : A { public void S() { Console.WriteLine("a");} }
public class C : B { }
class program
{
    public static void Main()
    {
       
    }
}

/*class X { }
class Y : X { }
class Z : Y { }

class program
{
    public static void Main()
    {
        X f1 = new X();
        Y f2 = f1 as Y;
    }
}*/

/*public class X { public void Metoda1() { Console.Write("X"); } 
    public static void Metoda2() { Console.Write("X"); } }
public class Y : X { public void Metoda3() { Console.Write("Y"); } }
public class Z : X { public void Metoda4() {  } }*/

/*class X { 
    int x;
    public X(int i) { x=i; } 
}

class A
{
    int a; 
    public A()
    {
        a = 5;
    }
}

class C : A
{
    int c;

    public C(int y)
    {
        this.c = y;
    }
}

class D : A
{
    int d;

    public D(int y)
    {
        d = y;
    }
}*/

/*interface I { void Metoda(); }
abstract class A { public abstract int M { get; } }

class B : A { 
    int b;
    public override int M => throw new NotImplementedException();

}

abstract class C : A, I { public abstract void Metoda();}
class D : C { public override int M { get => 1; }
   
}

sealed class E : D {
    public int X => 1;
    public override int M  { get => 1; }

   
}*/

/*class Osoba { }

sealed class Student: Osoba { }

abstract class Nastavnik: Osoba { }

class Program
{
    public static void Main(string[] args)
    {
       Osoba o = new Osoba();
        Student s = o as Student;
        Nastavnik o1= o as Nastavnik;    }
}*/

/*class Osoba { }
sealed class Student : Osoba { }
//class RedovanStudent : Student { }
abstract class Nastavnik : Osoba { }
class Asistent : Nastavnik { }*/

/*abstract class Nastavnik
{
    protected string ime;
    public abstract string Ime
    {
        get;
        internal set;
    }
}
 class Asistent : Nastavnik
{
    public string grupa;

    public override string Ime { get => throw new NotImplementedException(); internal set => throw new NotImplementedException(); }
}*/

/*interface A { void M(); }
abstract class B : A { public void M() { } }
sealed class C : B {  }
class D : B { }

public class Program
{
    public static void Main(string[] args)
    {
      
        
}
}*/

/*public class A
{
    public List<int> lista = new List<int>();
    public A() : this(7) { lista.Add(1); }
    public A(int i) : base() { lista.Add(i + 2); }
}
public class B : A { }
public class C : B
{
    public C() : this(8) { lista.Add(3); }
    public C(int i) { lista.Add(i + 4); }
}
public class D : C
{
    public D(int i) { lista.Add(i + 5); }
    public D() : this(9) { lista.Add(6); }
}
class Program
{
    void ispisi(List<int> lista)
    {
        foreach(object o in lista)
        {
            Console.WriteLine(o);
        }
    }
    static void Main()
    {
        D d = new D();
        foreach (int broj in d.lista) Console.Write(broj);
    }
}*/

/*public class A
{
    int x;
    int y;
    public A(int z) { x = z; }
}
public class B: A {
    int b = 1; 
   /* public B()
    {
        Console.WriteLine("eeee");
    }
   public B(int i):base(9)
    {
        i += 7;
        Console.WriteLine("ee");
    }

}*/

/*public class Osoba
{
    string ime; public Osoba(string i) { ime = i; }
}
public class Student : Osoba
{
    string indeks; public Student(string b):base(" { indeks = b; }
}
*/

/*public class Osoba
{
    int godine = 20;
    public int Godine => godine; //geter za godine
}

public class Program
{
    public static void Main(string[] args)
    {
        Object r = new Osoba();
        r = Osoba as object;
        Console.WriteLine();
    }
}*/

/*public class A
{
    public A() : this(6) { Console.WriteLine(3); }
    public A(int i) { Console.WriteLine(i); }
}
public class B : A
{
    public B() : this(5) { Console.WriteLine(2); }
    public B(int i) { Console.WriteLine(i); }
}
public class C : B
{
    public C() : this(4) { Console.WriteLine(1); }
    public C(int i):base(i)  { Console.WriteLine(i); }
}
public class Program
{
    public static void Main()
    {
        A a = new C(0);
    }
}
9*/

/*public class Osoba
{
    public int broj;
    protected string ime;

    public Osoba(int broj, string ime)
    {
        this.broj = broj;
        this.ime = ime;
    }
}
public class Student : Osoba
{
   public Student(int i, string s):base(i, s) 
    {

        Console.WriteLine("a");
    }
}
*/

/*class Student
{
    public int ocena;
}

class Program
{
    static void Main(string[] args)
    {
        Student s = new Student();
        int ocena = s.ocena;
        Console.WriteLine(ocena);
    }
}*/

/*class Program
{
    static void Metoda(ref int x)
    {
        x--;
    }
    static void Main(string[] args)
    {
        
        const int b = 45;
        int x = b;


    }
}*/

/*class Broj
{
    public int vred;
}
class Program
{
    static void Main(string[] args)
    {

        string str1 = "AAA";
        string str2 = str1;
        string str3 = str2;
        str2 = "CCC";
        Console.WriteLine(str3);
        Console.WriteLine(str2);
    }
}*/

/*using System.Transactions;

public class TAdresa
{
    public string adresa;
    public int broj;
}
public class Primer
{
    public static void Main(string[] args)
    {
        double d = 3.7;
        int i = Convert.ToInt32(d);
        Console.WriteLine(i);
    }
}*/

/*class A
{
    public A(int i)
    { Console.WriteLine("1"); }

}
class B : A
{
    public B() : this(1)
    { Console.WriteLine("2"); }
    public B(int i)
    { Console.WriteLine("3"); }
}
class Program
{
    static void Main(string[] args)
    {
        B b = new B();
        
    }
}*/

/*public class A { }
public class B : A { }
class Broj
{
    const string id = "123";
    static void Main(string[] args)
    {
        
    }
}*/

/*class Broj {
    public virtual int ispisi(int a, int b)
    {
        Console.WriteLine("Ides za Kanadu!");
        return a+b;
    }

    public  void isp()
    {
        Console.WriteLine(1);
    }
  
}

class B: Broj
{
    public void a()
    {
        Console.WriteLine("znj");
    }
}
class A
{
    static void Main(string[] args)
    {
        B b= new B();
        b.a();
        b.isp();
        b.ispisi
    }
}*/

/*public class A
{
  public  void Prikazi()
    { Console.WriteLine("A"); }
}
public class B : A
{
  new public void Prikazi()
    { Console.WriteLine("B"); }
}

class C
{
    static void Main()
    {
        string tekst = "Naziv je \t FON.";
        Console.WriteLine(tekst);
         tekst = @"Naziv je \t FON.";
        Console.WriteLine(tekst);
    }
}*/

/*public class Osoba
{
    public int godine = 20;
    public int Godine => godine;
}

public class Student: Osoba
{
    public void Prikazi()
    {
        Console.WriteLine(godine);
    }

    public string ime = "Petar";
}

public class C
{
    static void Main()
    {
        Osoba r= new Student();
        
        
    }
}*/

/*public class A
{

    public int ispisi(int x, int y)
    {
        return x * y;
    }   
}

public class B:A
{
  
    
}

class c
{
    static void Main()
    {
        A a= new A();
        B b= new B();
        int x=b.ispisi(5, 4);
        Console.WriteLine(x);
    }
}*/

/*public class A
{
    public virtual void Prva(List<int> l) { l.Add(5); }
    public void Druga(List<int> l) { l.Add(4); }
}
public class B : A
{ public override void Prva(List<int> l) { l.Add(3); } }
public class C : B { public new void Druga(List<int> l) { l.Add(2); } }
public class D : C { public override void Prva(List<int> l) { l.Add(1); } }

public class Proba
{
    static void Main()
    {
        List<int> lista = new List<int>();
        A x = new B(); x.Prva(lista); x.Druga(lista);
        C y = new C(); y.Prva(lista); y.Druga(lista);
        C z = new D(); z.Prva(lista); z.Druga(lista);
        foreach (int broj in lista) Console.Write(broj);
    }
}*/

/*class A
{
    public static int a = -1;
    public int M1() => a += 8;
    public virtual int M2() => a -= 2;
}
class B : A { public override int M2() => a += 9; }
class C : B { }
class Primer
{
    public static void Main()
    {
        List<A> l = new List<A>(); 
        l.Add(new B()); 
        l.Add(new C()); 
        l.Add(new A());
        //l.Add(new A());
        foreach (A x in l) { x.M1(); x.M2(); Console.WriteLine(A.a); }
    }
}

/*class A { public static int a = -1; public int M1() => a += 6; public virtual int M2() => a += 1; }
class B : A { public override int M2() => a += 3; }
class C : B { }

class Proba
{
    static void Main()
    {
        List<A> l = new List<A>();
        l.Add(new C());
        l.Add(new B());
        l.Add(new A());
        foreach (A x in l)
        {
            x.M1(); x.M2(); Console.Write(A.a);
        }
    }
}*/

/*public class A
{
    public virtual int Prva() { return 10; }
    public int Druga() { return 8; }
}
public class B : A
{
    public override int Prva()
    {
        return 6;
    }
}
public class C : B
{
    public override int Prva()
    {
        return 4;
    }
}
public class D : C
{
    public new int Druga()
    {
        return 2;
    }
}
public class Program
{
    public static void Main()
    {
        int broj = 150;
        A x = new B();
        broj += x.Prva();
        Console.WriteLine(broj);
        broj += x.Druga();
        Console.WriteLine(broj);
        D y = new D();
        broj += y.Prva();
        Console.WriteLine(broj);
        broj += y.Druga();
        Console.WriteLine(broj);
    }
}*/

/*public partial class K
{
    public int vrednost;
    public virtual int M() { return vrednost; }
}

 partial class K { override int M() { return 0; } }*/


/*class Student
{
   public int brojIndeksa = 112;
}

class Broj
{ public int vred; }*/

/*class Broj
{
    public int vrednost; private int a; public Broj(int a)
    {
        this.a = a;
    }
}
class Program
{
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
        Console.WriteLine(b.vrednost);
        Console.WriteLine(a);
    }
    static void Main(string[] args)
    {
        int a = 50;
        Broj b = new Broj(0); 
        m1(a, b);
        Console.WriteLine("a: " + a + "\tb.vrednost: " + b.vrednost);
        m2(a, b);
        Console.WriteLine("a: " + a + "\tb.vrednost: " + b.vrednost); m1(ref a, b);
        /*Console.WriteLine("a: " + a + "\tb.vrednost: " + b.vrednost); m2(ref a, b);
        Console.WriteLine("a: " + a + "\tb.vrednost: " + b.vrednost);*/

/*public class Klasa
{
    public int broj1 = 5; public int broj2 = 10;
    public void metoda1(int x, int y)
    {
        x = 10;
        y = 20;
        metoda2(x, y);
    }
    public static void metoda2(int broj1, int broj2)
    {
        broj1 = broj1;
        broj2 = broj1;
    }
    public static void metoda3(out int x, ref int y)
    {
        x = 1;
        int a = x++; 
        y = x + a;
        Console.WriteLine(x+" "+y);
    }
}
public class Program
{
    public int x = 1; public int y = 2;
    public void metoda3(ref int x, out int y)
    {
        x = x + x + x;
        y = x - 3;
    }
    public static void metoda2(int p, ref int z)
    {
        p = p + 2;
        z = z + p;
        Program l = new Program();
        Console.WriteLine(l.x + " " +l.y) ;
        l.metoda3(ref p, out z);
        Console.WriteLine(l.x + " " + l.y);

    }
    public static void metoda1(ref int x, ref int y)
    {
        x = x + y;
        y = y + x; Program.metoda2(x, ref y);
    }
    public static void Main(string[] args)
    {
        Program p = new Program();
        //p 1 2
        metoda1(ref p.x, ref p.y);
        //p.x = 3 // p.y=12
        Klasa k = new Klasa();
        //5 10
        k.metoda1(k.broj1, k.broj2);
        //k1.broj1 = 5, k1.broj2=10
        Klasa.metoda3(out k.broj1, ref k.broj2);
        //k1.broj1 = 2, k1.broj2=3
        Console.WriteLine("Program vrednosti:" + p.x + " " + p.y); Console.WriteLine("Klasa vrednosti:" + k.broj2 + " " + k.broj1);
    }
}
*/

/*public struct Struktura
{
    public int x, y;
    public Struktura(int x, int y)
    {
        this.x = x; this.y = y;
    }
}
public class Program
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
        x = x++;
        y += x;
        Console.WriteLine("Vrednosti promenjivih x: "+x+", a y: "+y);
    }
    public static void Main(string[] args)
    {
        Struktura s = new Struktura(5, 3); 
        Dodaj(ref s.x, s.y);
        Console.WriteLine(s.x + " " + s.y);

        Oduzmi(s.x, ref s.y);
        Console.WriteLine(s.x + " " + s.y);

        Pomnozi(s.x, ref s.y);
        Console.WriteLine(s.x + " " + s.y);

        Console.WriteLine(s.x + " " + s.y);
    }
}*/

/*public class Podatak
{
    public int broj;
    public void M(int broj) { broj = this.broj; }
    public void M(ref int broj) { broj += broj; }
}
public static class Program
{
    public static void Main(string[] args)
    {
        Podatak x = new Podatak(); x.M(ref x.broj);
        x.M(x.broj);
        Console.WriteLine((x.broj != 10) ? "X" : "Y");
    }
}*/

/*public class Klasa
{
    public int x; public int y;
    public Klasa(int x, int y) { this.x = x; this.y = y; }
    public Klasa() { x = 12; y = 5; }
    public class Program
    {
        public static void Main(string[] args)
        {
            Klasa k1 = new Klasa(5, 7);
            Console.WriteLine(k1.x + " " + k1.y);
            Klasa k2 = new Klasa();//12,5
            Console.WriteLine(k2.x + " " + k2.y);


        }
    }
}*/

/*public class Klasa
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
public class Program
{
    public static void Main(string[] args)
    {
        Klasa k1 = new Klasa(5, 2); Console.WriteLine(k1.x); Console.WriteLine(k1.y);
        //k1,k3 4//5 2
        Klasa k2 = new Klasa();
        //k2 1 5
        Klasa k3 = k1;
        //Console.WriteLine(k3);
        //Console.WriteLine(k1);
        if (k1 == k2 )
        Console.WriteLine("k1 i k2 su ISTI"); //N if
        if(k1.x == k2.x)
        Console.WriteLine("k1 i k2 su ISTI"); //N
        if (k3 == k1)
        Console.WriteLine("k1 i k3 su isti"); //T
        Console.WriteLine(k1.x);//4
        k3.y = 5;
        if (k1.y == k2.y)
            Console.WriteLine("k1.y = " + k1.y + " k2.y = " + k2.y);
    }
}*/

/*public class Razlomak
{
    public int brojilac; public int imenilac;
    public Razlomak(int brojilac, int imenilac)
    {
        this.brojilac = brojilac;
        this.imenilac = imenilac;
    }
}
public class Program
{
    public static void Dodaj(Razlomak x, int y)
    {
        x.brojilac += y;
    }
    public static void Main(string[] args)
    {
        Razlomak r1 = new Razlomak(5, 5); Razlomak r2 = new Razlomak(10, 2); Razlomak r3 = r1;
        Dodaj(r1, r2.brojilac); Dodaj(r3, r2.brojilac); Console.WriteLine(r3.brojilac);
    }
}*/


using System.Collections;
using System.ComponentModel.Design;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.Intrinsics.Arm;

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
    public static int broj; public int godina;
}
public class Ispit
{
    public string predmet; public Index student; public Rok rok;
    public double brojPoena; public int ocena;
}
public enum TPovez { Korice, Karton, Spirala, Ostalo }
public struct TDimenzija
{
    public short sirina; public int duzina; public double visina;
}
public class Knjiga
{
    public string naziv;
    public TDimenzija dimenzija; public TPovez povez;
    public short brojStrana;
    public void Visina(double debljinaPapira)
    { dimenzija.visina = brojStrana * debljinaPapira; }
}
/*public struct Tindeks { public int broj; }

/*public class Program
{
    public static void Main(string[] args)
    {
       
    }
}*/

/*public class Razlomak
{
    int brojilac = 0;
   public static int imenilac = 1;
    public void Inicijalizuj(int b, int i)
    {
        brojilac = b; imenilac = i;
    }
    public void izracunaj()
    {
        Console.WriteLine( $"{ brojilac}/{ imenilac}");
    }
}
public class Program
{
    public static void Main(string[] args)
    {
        Razlomak r = new Razlomak();
        r.Inicijalizuj(20, 2);
        Razlomak r1 = new Razlomak();
        //r1.Inicijalizuj(10, 5);
        Console.WriteLine( Razlomak.imenilac);
    }
}

/*public class A
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
    public static void M4() { Console.Write(x+" "); }
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
        Console.WriteLine(a);
    }
}*/

/*public class K
{
    public static void P(Ispit i, Rok r)
    {
        if (r == Rok.Jun) i.brojPoena += 5;
        i.ocena = Convert.ToInt32(i.brojPoena) / 10;
    }
    public static void M(ref Ispit i, Ispit i1)
    { K.P(i1, Rok.Jun); i.ocena = i1.ocena; }
}

public class Proba
{
    static void Main()
    {
        Ispit x = new Ispit(); Ispit y = new Ispit(); x.ocena = 5; x.brojPoena = 76;
        y.ocena = 5; y.brojPoena = 86;
        K.M(ref x, y); //Console.Write($"{ ++y.ocena}");

        
        Console.WriteLine(x.ocena);
        Console.WriteLine(x.brojPoena);

        Console.WriteLine(y.ocena);
        Console.WriteLine(y.brojPoena);
    }
}*/

/*public class Program
{
    public static int x=3;
    public static int y=6;
    public static void metoda1( int x, int y)
    {
        Program.x += y;
        Program.y += x;
    }

    public static void Main()
    {
        int x = 12;
        int y = 6;
        metoda1( x,  y);
        Console.WriteLine(Program.x+" "+Program.y);
    }
}*/

/*public class Test
{
    public static int x ; 
    public void D()
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
    
}

public class Proba
{
    public static void Main(string[] args)
    {
        Test.A1();
        Test.D1();
        /*Test t1 = new Test();
        t1.A();
        t1.D();
        Test t2 = new Test();
        t2.A();
        t2.D();
        Test.D1();
    }
}*/

/*public class Test
{
    public int y = 0;
    public void D(int x) { Console.WriteLine(x + " " + y); }
    public  void D1(int x) {y++; Console.WriteLine(y + " " + x); }
    public void A() { y = y + 2; }
    public  void A1() { y = y + 1; }
    public static void Main(string[] args)
    {
        Test t1 = new Test();
        t1.A();
        Console.WriteLine(t1.y);
        Test t2 = new Test();
        t2.A();
        Console.WriteLine(t2.y);

    }
    
}*/

/*public class Tindex { public int broj; }
public class Primer
{
    static void Proba(int i) { i += 1; }
    static void Proba(Tindex i) { i.broj -= 2; }
    public static void Main()
    {
        Tindex index = new Tindex(); Proba(index.broj); Proba(index); Console.WriteLine(index.broj);
    }
}*/

/*public class Tindex { public int broj; }
public class Primer
{
    static void Proba(ref int i) { i += 1; }
    static void Proba(ref Tindex i) { i.broj -= 2; }
    public static void Main()
    {
        Tindex index = new Tindex(); Proba(ref index.broj); Proba(ref index); Console.WriteLine(index.broj);
    }
}*/

/*public class G
{
    public static void Promeni(ref Datum d)
    { d.mesec--; d.godina++; }
    public static void M(ref Kartica k, Kartica k1)
    { k.stanje += 1; k1.stanje += 1; k = k1; }
    public static void M(Kartica k, ref Kartica k1)
    { k.stanje += 2; k1.stanje += 2; k = k1; }
}

public class Proba
{
    static void Main()
    {
        Datum x = new Datum(); 
        x.mesec = 9;
        x.godina = 2021;
        Kartica y = new Kartica();
        Kartica z = new Kartica();
        y.vaziDo = x; 
        G.Promeni(ref x);
        Console.WriteLine(x.mesec+" "+ x.godina);
         z.vaziDo = x;
         y.stanje = 5; 
         G.M(y, ref z);
        G.M(ref y, z);
        ;
        Console.Write("{0} {1}", z.stanje, z.vaziDo.mesec);
    }
}*/

/*class Broj
{
    public int vrednost; private int a; public Broj(int a)
    {
        this.a = a;
    }
}
class Program
{
    static void m1(ref int a, Broj b)
    {
        b.vrednost = a; a += 100;
    }
    static void m2(ref int a, Broj b)
    {
        b.vrednost=450; a += 100;
    }
    static void m1(int a, Broj b)
    {
        b.vrednost = a; a += 100;
    }
    static void m2(int a, Broj b)
    {
        b = new Broj(a); a += 100;
    }
    static void Main(string[] args)
    {
        int a = 50;
        Broj b = new Broj(0);
        m1(a, b);
        Console.WriteLine("a: " + a + "\tb.vrednost: " + b.vrednost);
         m2(a, b);
         Console.WriteLine("a: " + a + "\tb.vrednost: " + b.vrednost); 
         m1(ref a, b);
         Console.WriteLine("a: " + a + "\tb.vrednost: " + b.vrednost);
         m2(ref a, b);
         Console.WriteLine("a: " + a + "\tb.vrednost: " + b.vrednost);
    }
}*/

/*public class Klasa
{
    public int broj1 = 5; public int broj2 = 10;
    public void metoda1(int x, int y)
    {
        x = 10;
        y = 20;
        metoda2(x, y);
    }
    public static void metoda2(int broj1, int broj2)
    {
        broj1 = broj1;
        broj2 = broj1;
    }
    public static void metoda3(out int x, ref int y)
    {
        x = 1;
        int a = x++; y = x + a;
    }
}
public class Program
{
    public int x = 1; public int y = 2;
    public void metoda3(ref int x, out int y)
    {
        x = x + x + x;
        y = x - 3;
    }
    public static void metoda2(int p, ref int z)
    {
        p = p + 2;
        z = z + p;
        Console.WriteLine(p+" "+z);
        Program l = new Program();
        l.metoda3(ref p, out z);
        Console.WriteLine(p + " " + z);//ok 15 i 12


    }
    public static void metoda1(ref int x, ref int y)
    {
        x = x + y;
        y = y + x; 
        Program.metoda2(x, ref y);
    }
    public static void Main(string[] args)
    {
        int x = 7;
        x = x++;
        int a = x++;
        Console.WriteLine(x);
    }
}*/

/*public struct Struktura
{
    public int x, y;
    public Struktura(int x, int y)
    {
        this.x = x; this.y = y;
    }
}
public class Program
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
    public enum TPovez { Kartica, Karton, Spirala,Ostalo}
    public static void Main(string[] args)
    {

       




    }
}
*/

/*public enum Operacija { Kvadrat, Plus = 2, Puta, Minus = 1, Podeljeno = 4 }
public class Program
{
    public static void Main(string[] args)
    {
        int[] niz = new int[5] { 0, 1, 2, 3, 4 };
        //
        int x = 0;
     
for (int i = 2; i > 0; i = i - 1)
        {
            for (int j = i; j < i + 2; j = j + 1)
            {
                x++;
                if (x % 2 == 0)
                    continue;
                x++;
                niz[i] = x;
            }
        }
       for(int i=0;i<niz.Length;i++)
        {
            Console.WriteLine(niz[i]);
        }
    }
}*/

/*class SkupBrojeva
{
    int[] brojevi = new int[6]; public int this[int pozicija]
    {
        get { return brojevi[pozicija + 1]; }
        set { brojevi[pozicija - 1] = value; }
    }
}
public class Program
{
    public static void Main(string[] args)
    {
        SkupBrojeva skup = new SkupBrojeva(); int suma = 0;
        for (int i = 2; i < 5; i++)
        {
            skup[i] = i;
        }
        for (int i = 2; i < 5; i++)
        {
            suma += skup[i];
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
        Brojevi b = new Brojevi();
        b[1] = 4;

        foreach(int broj in b.niz)
        {
            Console.WriteLine(broj);
        }
    }
}*/

/*public class Program
{

    public static void Main(string[] args)
    {
        int i = 0;
        if ((9 / i) > 0) { Console.WriteLine(1); }
    }
}*/

/*class Osoba
{
   void ispisi_mat(int[,] mat, int m, int n)
    {
        for(int i=0; i<m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Console.Write(mat[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    static void Main()
    {
        ArrayList f = new ArrayList();
        f.Add(new Datum());
        Console.Write(f[0]);
    }
}
*/

/*public class Razlomak
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
public class Proba
{
    public static void Main()
    {
        Razlomak r1 = new Razlomak(2, 3); Razlomak r2 = new Razlomak(3, 4); Razlomak r = r1 + r2; Console.WriteLine(r.brojilac); Console.WriteLine(r.imenilac);
    }
}*/

/*public class Broj
{
    public int broj;
    public static int operator *(Broj b, int a) { return b.broj + a; }
    public static int operator *(int a, Broj b) { return b.broj - a; }
    public static int operator *(Broj a, Broj b) { return b.broj * a.broj; }
}
*/

/*public class Broj
{
    public int broj = 2;
    public static Broj operator *(Broj b, int a)
    { Broj c = new Broj(); c.broj = b.broj * a; return c; }
    public static int operator *(Broj a, Broj b) { return b.broj * a.broj; }
}
public class Proba
{
    public static void Main(string[] args)
    {
        int broj1 = 2;
        Broj broj2 = new Broj();
        broj1 = broj2 * broj2; broj2.broj = broj1 * broj1; broj2 *= broj1;
        Console.WriteLine(broj2.broj);
    }
}*/

/*public class Broj
{
    public int broj = 3;
    public static int operator *(Broj b, int a)
    { return a + b.broj; }
    public static int operator *(int a, Broj b)
    { return a - b.broj; }
    static void Main()
    {
        Broj broj1 = new Broj(); int broj2 = 5;
        broj2 *= broj1; broj2 *= broj1.broj;
        Console.WriteLine(broj2);
    }
}*/

/*public class Broj
{
    public int broj = 2;
    public static double operator /(int x, Broj b) { return x / b.broj; }
    public static void Main()
    {
        int x = 5;
        Broj y = new Broj(); double z = x / y; Console.WriteLine(z);
    }
}


public enum Oznaka { A,B,C,D,E,F}

public class Proba
{
   static int metoda(long a, in int b, Oznaka c = Oznaka.A)
    {
        short d = 1;
        int e = 2;
        if (a > b)  return d; else return e; 
    }

   
}*/

public class A
{
    private static int x = 5;
    private int y = 10;

    public void M1(in int i) { x += i;y += i; }
    public void M2(out int i) { i = 1; x += i; y += i; }
    public void M3(ref int i) { x += i; y += i; i += 2; }
    public void M4(int i) { x += i; y += i; i += 3; }
    public string Prikazi() => $"{x}/{y}";

}

public class Proba
{
    public static void Main()
    {
        int a = 0;
        A b= new A();
        A c= new A();
        b.M2(out a); b.M1(in a); b.M3(ref a); b.M4(a);
        c.M3(ref a); c.M1(in a); c.M2(out a); c.M4(a);
        Console.WriteLine($"{b.Prikazi()}+ {c.Prikazi()}.{a}");
    }
}
