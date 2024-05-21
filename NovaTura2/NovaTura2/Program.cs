using System.Linq;
public enum Tip { Otvoreno, Zatvoreno, Dopuna }
public enum Oznaka { A, B, C, D, E, F }
public struct Poeni
{
    public int tacno;
    public double netacno;
}
public struct Odgovor
{
    public Oznaka? oznaka;
    public string tekst;
}
public class Pitanje
{
    public byte rb;
    public string tekst;
    public Tip tip;
    public Poeni poeni;
    public Odgovor resenje;
}

public delegate void Obrada(double suma);
/*public class Racun
{
    string broj; public double stanje;
    public Racun(string b, double s) { broj = b; stanje = s; }
    public static event Obrada Dogadjaj;
    public void promeni(double iznos)
    {
        if (stanje + iznos < 0) return;
        stanje += iznos;
        if (Dogadjaj != null)
        {
            Console.WriteLine("A");
            Dogadjaj(iznos);
        }
    }
}
public class Banka
{
    static double bilans = 1000;
    static void Azuriraj(double i) => bilans += i;
    static void Main()
    {
        Racun r1 = new Racun("111", 0);
        Racun r2 = new Racun("222", 0);
        r1.promeni(100);//ovde je delegat null
        Racun.Dogadjaj += Azuriraj;
        r2.promeni(200);
        r1.promeni(-75);
       // r2.promeni(-350);
        Console.WriteLine(r2.stanje);
    }
}
*/

/*public delegate void Operacija(ref int x); class Skup { public int[] niz = { 2, 3, 4, 5, 6 }; 
    public int this[int pozicija] { get { return niz[1 - pozicija]; } 
    }
}
static class Prosirenja {
    public static void Mapiraj(this Skup s, Operacija op) { 
        for (int i = 1; i < 4; i++) op(ref s.niz[i]); } }
class Program
{
    static void Povecaj(ref int x) { x += 5; }
    static void Smanji(ref int x) { x -= 2; }
    static void Main()
    {
        Skup x = new Skup();
        Operacija o = Smanji;
        o += Povecaj; x.Mapiraj(o);
        try
        {
            for (int i = -3; i <= 0; i++) Console.Write(x[i]);
        }
        catch (Exception) { Console.Write("X"); }
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
        Delegat dg = x.A;
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
    }
}*/

/*public delegate void Del(int a, ref int b, int c);
public class Program { 
    public static void Plus(int e, ref int f, int g) { e += g; f += g; } 
    public static void Minus(int e, ref int f, int g) { e -= g; f -= g; } 
    public static void Puta(int e, ref int f, int g) { e *= g; f *= g; } 
    static void Main() {
        Del dg = Minus; dg -= Plus; dg = Puta; dg += Plus; dg += Minus; dg += Plus; dg -= Plus; int x = 5, y = 10, z = 15; dg(x, ref y, z); Console.WriteLine(x + y); } }

*/
/*public delegate int Delegat(ref int a, int b);
public class Klasa
{
    public int A(out int a, int b) => a = b;
    private protected int B(ref int a, int b) => a + b;
    public static int C(ref int a, short b) => a + b;
}
public class Program : Klasa
{
    public int D(ref int a, short b) => a + b;
    public static int E(in int a, int b) => a + b;
    public int F(short b, ref int a) => a + b;
    public static void Main()
    {
        Program p = new Program();
        Delegat dg = F;
    }
}
*/

/*public delegate void Operacija(ref int x);
class Skup
{
    public int[] niz = { 2, 4, 6, 8, 10 };
    public int this[int pozicija] { get { return niz[^(pozicija - 1)]; } }
}
static class Prosirenja { 
public static void Mapiraj(this Skup s, Operacija op)
{
    for (int i = 1; i < 4; i++)
        op(ref s.niz[i]);

}
}*/

/*class Osoba
{
    public int broj1;
    public static int broj2;

    private Osoba(int broj1, int broj2)
    {
        this.broj1 = broj1;
        Osoba.broj2 = broj2;
    }
}
class Program
{
    
    static void Main()
    {
        Osoba o1 = new Osoba();
        Osoba o2 = new Osoba();
        Console.WriteLine(o1.broj1+" "+Osoba.broj2);
    }
}*/

/*public class Osoba
{
    protected string ime;
    protected string prezime;

    public Osoba(string ime, string prezime)
    {
        this.ime = ime;
        this.prezime = prezime;
    }
}
public class Student : Osoba
{
   // string indeks = "1/2016";
   
}

public class Program
{
    static void Main()
    {
        Student s = new Student();
        Console.WriteLine(s.ime);
    }
}*/

/*public class Osoba
{
    public string ime;
    public Osoba(string ime)
    {
        this.ime = ime;
    }

    public override bool Equals(object obj)
    {
        Osoba o = (Osoba)obj;
        return this.ime==o.ime;
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
}*/

/*class A
{
    public A() : this(6) { Console.WriteLine(3); }
    public A(int i) { Console.WriteLine(i); }
}
class B : A
{
   public B() : this(5) { Console.WriteLine(2); }
 
    public B(int i) { Console.WriteLine(i); }
    public abstract void P();
}
abstract  class C : B
{
    public C() : this(4) { Console.WriteLine(1); }
    public C(int i) { Console.WriteLine(i); }
}
public class Proba
{
    //public abstract void zadatak();
    public static void Main()
    {
    }

    public void zadatak()
    {
        Console.WriteLine(5);
    }
}*/

/*class X { }
class Y : X {  }
class Z : Y { }

public class Program
{
    public static void Main()
    {
        X d1 = new X();
        Y d2 = (Y)d1;
    }
}*/

/*public class X { public void Metoda1() { Console.Write("X"); } public static void Metoda2() { Console.Write("X"); } }
public class Y : X { public void Metoda3() { Console.Write("Y"); } }
public class Z : X { public  void Metoda4() { Metoda1(); } }

public class Program
{
    static void Main()
    {
        Z z = new Z();
        z.Metoda4();
    }
}
*/

/*interface I { void Metoda(); }
abstract class A { public abstract int M { get; } }
//class B : A { int b; } 
abstract class C : A, I
{
    public void Metoda()
    {
        throw new NotImplementedException();
    }
} */
/*class D : C { public override int M { set; } } 
sealed class E : D { public int X => 1; } 
class F: E {public int f; }*/

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
abstract class Asistent : Nastavnik
{
    public string grupa;
}
*/

/*interface A { void M() { Console.WriteLine(5); } }
 class B : A { public void M() { int x=5; } }
sealed class C : B { }
class D { }
class Program
{
    static void Main()
    {
        //Program p = new D(); 
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
}*/

/*public class A
{
    int x;
    int y;
    public A(int i) { x = y; }
}
public class B : A { int b = 1; }
class Program
{
    static void Main()
    {
        D d = new D();
        foreach (int broj in d.lista) Console.Write(broj);
    }
}*/

/*public class Osoba
{
    string ime; public Osoba(string i) { ime = i; }
}
public class Student : Osoba
{
    string indeks; public Student() { indeks = b; }
}*/

/*public class Osoba
{
   public int godine = 20;
    public int Godine => godine; //geter za godine
}
public class Student : Osoba
{
    public void Prikazi() { Console.WriteLine(Godine); }
}

class Program
{
    static void Main()
    {
        Osoba r = new Osoba();
        Console.WriteLine(r.Godine);
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
    public B(int i):base(i) { Console.WriteLine(i); }
}*/

/*interface I { void Metoda(); }
//abstract class A : I { public int x => 1; }
abstract class B { public abstract int M { get; } }
abstract class C:B,I { public void Metoda() { } }
class D : B { public override int M { get => 1; } }
interface L : D {}*/

/*interface A { void M(); }
abstract class B : A { public void M() {  } }
class C { }
sealed class D : C { }*/
/*public class A
{
    public int[] niz = new int[7];
    public A() : this(7) { niz[5] = 1; }
    public A(int i) : base() { niz[4] = i; }
}
public class B : A { }
public class C : B
{
    public C() { niz[3] = 2; }
    public C(int i) : this() { niz[2] = i; }
}
public class D : C
{
    public D(int i) : this() { niz[1] = i; }
    public D() { niz[0] = 4; }
}*/

/*public class A { public static int a = 1; public int M1() => a + 6; }
    public class B:A { public static int a = 4; public int M1() => a + 6;  }*/

/*class A { public static int a = -1; public int M1() => a += 6; public virtual int M2() => a += 1; }
class B : A { public override int M2() => a += 3; }
class C : B { }*/

/*public class A
{
    public virtual void Prva(List<int> l) { l.Add(5); }
    public void Druga(List<int> l) { l.Add(4); }
}
public class B : A
{ public override void Prva(List<int> l) { l.Add(3); } }
public class C : B { public new void Druga(List<int> l) { l.Add(2); } }
public class D : C { public override void Prva(List<int> l) { l.Add(1); } }
public class Program
{
    public static void Main()
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
        List<A> l = new List<A>(); l.Add(new B()); l.Add(new C()); l.Add(new A());
        foreach (A x in l) { x.M1(); x.M2(); Console.Write(A.a); }
    }
}
*/

/*public class A
{
    public virtual int Prva() { return 10; }
    public  int Druga() { return 8; }
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
    public new int Druga()
    {
        return 5;
    }
}
public class D : C
{
    public new int Druga()
    {
        return 2;
    }
}
/*public class A
{
    public int x = 10;
    public virtual int Prva() { x += 2; return 1; }
    public int Druga() { return 3; }
}
public class B : A { }
public class C : B
{
    public override int Prva() { x += 4; return 7; }
    public new int Druga() { return 5; }
}
public class D : C
{
    public override int Prva()
    {
        x += 6; return 9;
    }
}*/
/*lass K
{
   public static int broj = 5;
   int p = 5;
   public  void S(int bro = 0) { bro = p; broj++; }
}*/

/*public partial class Podatak { public int broj = 10; }
partial class Podatak { public void Promeni() { broj += 5; } }*/
/*public partial class K
{
    public int vrednost;
    public virtual int M() { return vrednost; }
}

partial class K { public override int M() { return 4; } }*/

partial class K
{
    public int broj;
    public K(int b) { broj = b; }
    public virtual int M() { return broj; }
}


// partial class K { abstract void M1(); }
public class Program
{
    public static void Main()
    {
        int[] niz = { 92, 48, 101, 37, 210, 58 };
        var a = niz.Select((x, i) => new{P = i / 3, O = x / 5}).Last(x => x.P < 0.5);
        Console.Write($"{ a.O}:{ a.P}");

    }
}