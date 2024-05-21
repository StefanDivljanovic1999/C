
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Threading.Channels;
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
    public A(int z) { x = z; }
}
public class B : A { int b = 1;

    public B(int z) : base(z)
    {
    }
}*/
/*public class Osoba
{
    string ime; public Osoba(string i) { ime = i; }
}
public class Student : Osoba
{
    string indeks=5; public Student(string b):base(b) { indeks = b; }
}*/
/*public class Osoba
{
    int godine = 20;
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
        object r= new Osoba();
        Console.WriteLine(r);
    }
}
*/
/*public class A
{
    public A()  { Console.WriteLine(3); }
    public A(int i) { Console.WriteLine(i); }
}
public class B : A
{
    public B() { Console.WriteLine(2); }
    public B(int i): base(i) { Console.WriteLine(i); }
}
public class C : B
{
    public C()  { Console.WriteLine(1); }
    public C(int i): base(i){ Console.WriteLine(i); }
}
public class Program
{
    public static void Main()
    {
        C a = new C();
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
    static void Main()
    {
        Del dg = Puta;
        dg += Minus;
        dg = Puta;
        dg += Minus;
        dg += Plus;
        dg += Minus;
        dg -= Plus;
        int x = 0, y = 20;
        dg(x, ref y);
        Console.WriteLine(x + " " + y);
    }
}*/
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
/*public delegate void Obrada(double suma);
public class Racun
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
        r2.promeni(-350);
        Console.WriteLine(bilans);
    }
}*/
/*public delegate void Del(int a, ref int b, int c); public class Program { public static void Plus(int e, ref int f, int g) { e += g; f += g; } public static void Minus(int e, ref int f, int g) { e -= g; f -= g; } public static void Puta(int e, ref int f, int g) { e *= g; f *= g; } static void Main() { Del dg = Minus; dg -= Plus; dg = Puta; dg += Plus; dg += Minus; dg += Plus; dg -= Plus; int x = 5, y = 10, z = 15; dg(x, ref y, z); Console.WriteLine(x + y); } }
 * */
/*public delegate void Operacija(ref int x); 
class Skup { public int[] niz = { 2, 3, 4, 5, 6 }; 
    public int this[int pozicija] { get { return niz[1 - pozicija]; 
        } 
    } 
}
static class Prosirenja{ 
    public static void Mapiraj(this Skup s, Operacija op) { 
        for (int i = 1; i < 4; i++) op(ref s.niz[i]); 
    }
}
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
            for (int i = -3; i <= 0; i++)
                Console.Write(x[i]);
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
    public static int c(int a, short b) => a + b; }
public class Program : Klasa { 
    public short D(int a, short b) => 1; 
    public static int E(int a, short b) => a + b;
    public int F(short b, int a) => a + b; 
    public static void Main() { 
        Program p = new Program(); Delegat dg = p.F; 
            } 
}*/
/*public delegate int Delegat(); public class Klasa { int k = 5; public int A() { Console.Write(++k); return 1; } public int B() { Console.Write(k); return 2; } public int C() { Console.Write(--k); return 3; } }
public class Program { static void Main() { Klasa x = new Klasa(); Klasa y = new Klasa(); Delegat dg = x.A; for (int i = 6; i >= 1; i--) { if (i % 6 == 0) dg += x.B; if (i % 5 == 0) dg = y.B; if (i % 4 == 0) dg += y.C; if (i % 3 == 0) dg -= x.C; if (i % 2 == 0) dg += x.A; } int s = dg(); Console.WriteLine(s); } }*/
/*public delegate int Delegat(string a, bool b);
public class Klasa
{
    public int A(ref string a, bool b) { return 10; }
    public short B(string a, bool b) { return 0; }
    public static int C(string a, bool b) { return 0; }
     int D(string a, bool b) { return 10; }
}
public class Program : Klasa
{
    public static int E(bool b, string a) { return 10; }
    public int F(bool a, string b) { return 0; }
    static void Main()
    {
        Program p = new Program();
        Delegat dg = F;
    }
}*/
/*class Osoba { }
class Student : Osoba { }
class Program { 
    static int M(int x, int y) => x + y;
    static int Primeni(int v, Func<int, int> f) => f(v); 
    static Func<int, int> F1(int z) => x => M(z, x); 
    static Func<int, int> F2() => x => M(3, x);
    static Func<int, int> Odredi(Osoba o) => (o is Osoba) ? F2() : F1(5); 
    static void Main() { 
        Osoba a = new Student(); 
        var b = Odredi(a); 
        var c = Primeni(6, b); 
        Console.WriteLine(c); 
    }
}*/
/*class Osoba { }
class Student : Osoba { }
class Program { static int M(int x, int y) => x + y; static int Primeni(int v, Func<int, int> f) => f(v); static Func<int, int> F1(int z) => x => M(z, x); static Func<int, int> F2() => x => M(12, x); static Func<int, int> Odredi(Osoba o) => (o is Student) ? F1(5) : F2(); static void Main() { Osoba a = new Student(); var b = Odredi(a); var c = Primeni(6, b); Console.WriteLine(c); } }*/
/*class Lambda
{
    public void ispisi(int[] niz)
    {
        for (int i = 0; i < 7; i++)
        {
            Console.WriteLine(niz[i]);
        }
    }
    public void ispisi_listu(LinkedList<int> lista)
    {
       foreach(int broj in lista)
        {
            Console.WriteLine(broj);
        }
    }
    public static void Main(string[] args)
    {
        int[] niz = { 92, 48, 101, 37, 210, 58 };
        var a = niz.Select((x, i) => new { P = i / 3, O = x / 5 }).First(x => x.P < 0.5) ;
        Console.Write($"{ a.O}:{ a.P}");
    }
}*/
/*class Osoba
{
    public string ime;
    public virtual void Metoda() => Console.WriteLine("A");
}
class Student : Osoba
{
    public string indeks;
    public override void Metoda() => Console.WriteLine("B");
}*/
/*class Sakrivanje
{
    public class A
    {
        public virtual void Prva(List<int> l) { l.Add(5); }
        public void Druga(List<int> l) { l.Add(4); }
    }
    public class B : A
    { public  void Prva(List<int> l) { l.Add(3); } }
    public class C : B { public  void Druga(List<int> l) { l.Add(2); } }
    public class D : C { public  void Prva(List<int> l) { l.Add(1); } } 
 

    public static void Main(string[] args)
    {
        List<int> lista = new List<int>();
        A x = new B(); x.Prva(lista); x.Druga(lista);
        C y = new C(); y.Prva(lista); y.Druga(lista);
        C z = new D(); z.Prva(lista); z.Druga(lista);
        foreach (int broj in lista) Console.Write(broj);
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
    public  int Druga()
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
        broj += x.Druga();
        D y = new D();
        broj += y.Prva();
        broj += y.Druga();
        Console.WriteLine(broj);
    }
}*/
/*partial class K
{
    public int vrednost;
    public virtual int M() { return vrednost; }
}
partial class K
{
   public K(int i) : base() { }
    void M() { return 0; }
}*/
/*public partial class Podatak
{
    public int broj = 10;
}
partial class Podatak
{
    public void Promeni() { broj += 5; }
}
public class Proba
{
    public static void Main()
    {
        Podatak k = new Podatak();
        k.Promeni();
        Console.WriteLine((k.broj != 10) ? "X" : "Y");
    }
}*/
/*class K
{
   public int broj;
   public K(int b) {broj = b; }
   public virtual int M() { return broj; }

}
partial class K1 { public K1() : base() { } }*/
/*class X { int x; public X(int i) { x = i; } }
 class A : X { int a;

    public A(int a): base(4)
    {
        this.a = a;
    }
}
 class B:X { public int b; public B(int i) : base(i) => b = 5; }
 class C : A { public static int c; public C(int x):base(5) { } }
class D : A { int d; public D(int y): base(5) { d = y; } }
 class E : B { int e; public E(int z) : base(z) { e = z; } }
class Proba
{
    public static void Main()
    {
      
    }
}
*/
/*interface I { void Metoda(); }
 abstract class A : I { public abstract int M { get; } public void Metoda() { } }
 abstract class B : A { public int x => 1; }
 abstract class C : B, I { public void Metoda() { } }
 class D : C { public override int M { get => 1; } }
 sealed class E : D { public override int M => 0; }
// class F : E { public int f; }*/
/*interface A { void M(); }
abstract class B : A { public void M() { } }
class C : B { }
class D : C { }*/
/*public class A
{
    public int x = 10;
    public virtual int Prva() { x += 2; return 1; }
    public int Druga() { return 3; }
}
public class B : A { }
public class C : B
{
    public new int Druga() { return 5; }
}
public class D : C
{
    public override int Prva() { x += 6; return 9; }
}*/
/*public class A
{
    public List<int> lista = new List<int>();
    public A() : this(7) { lista.Add(1); }
    public A(int i): base() { lista.Add(i+2); }
}
public class B : A { }
public class C : B
{
    public C() { lista.Add(3); }
    public C(int i) : this() { lista.Add(i + 4); }
}
public class D : C
{
    public D(int i): base(4) { lista.Add(i + 5); }
    public D() : this(1) { lista.Add(6); }
}

class Proba
{
    public static void Main()
    {
        D d = new D(2);
        foreach (int broj in d.lista) { Console.Write(broj); }

    }
}*/
/*public delegate void Del(int a, ref int b, int c);
public class Program
{
    public static void Plus(int e, ref int f, int g)
    { e += g; f += g; }
    public static void Minus(int e, ref int f, int g)
    { e -= g; f -= g; }
    public static void Puta(int e, ref int f, int g)
    { e *= g; f *= g; }
    static void Main()
    {
        Del dg = Minus;
        dg += Puta;
        dg = Plus;
        dg += Plus;
        dg += Minus;
        dg += Plus;
        dg -= Plus;
        int x = 8, y = 4, z = 5;
        dg(x, ref y, z);
        Console.WriteLine(x - y);
    }
}*/
/*public delegate void Operacija(ref int x);
class Skup
{
    public int[] niz = { 2, 4, 6, 8, 10 };
    public int this[int pozicija] { get { return niz[^(pozicija - 2)]; } }
}
static class Prosirenja
{
    public static void Mapiraj(this Skup s, Operacija op)
    {
        for (int i = 1; i < 4; i++)
            op(ref s.niz[i]);

    }
}

class Program
{
    public static int M(int x)
    {
        int y;
        F();
        return ++y;
        void F() { (var a = new ( P = 2, 0 = x + 2 ); y = a.0 - a.P)};
}

    static void Main()
    {
     
    }
}*/
/*public delegate int Delegat(ref int a, int b);
public class Klasa
{
    public int A(out int a, int b) => a = b;
    protected int B(ref int a, int b) => a + b;
    public static int C(ref int a, int b) => a + b;
}
public class Program : Klasa
{
    public int D(ref int a, short b) => a + b;
    public static int E(in int a, int b) => a + b;
    public int F(ref int a, int b) => a + b;
    public static void Main()
    {
       List<int> lista = new List<int>();
        lista.Add(1);
        lista.Add(2);
        lista.Add(3);
        lista.Add(4);
        lista.Add(5);
        lista.Add(6);
        int a= lista.Any(x=> x % 2==0).Count();
        Console.WriteLine(a);

    }
}*/
/*public class A
{
    public A(): this(6){ Console.WriteLine(3); }
    public A(int i): base() { Console.WriteLine(i); }
}

public class B:A
{
    public B() : this(5) { Console.WriteLine(2); }
    public B(int i){ Console.WriteLine(i); }
}

public class C : B
{
    public C() : this(4) { Console.WriteLine(1); }
    public C(int i): base(i) { Console.WriteLine(i); }
}*/
/*public class A
{
    public int[] niz = new int[7];
    public A() : this(7) { niz[5] = 1; }
    public A(int i)  { niz[4] = i; }
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
/*public class A {

    public int[] niz = new int[6];
    public A() : this(7) { niz[5] = 1; }
    public A(int i){ niz[4] = 1; }
}
public class B : A { }
public class C : B
{
    public C() : this(8){ niz[3] = 2;}
    public C (int i){ niz[2] = i;}
}
public class D : C
{
    public D(int i) : this(){niz[2] = i;}
    public D(){niz[0] = 3;}

}
*/
/*class Skup<NekiTip> where NekiTip : struct { List<NekiTip> elementi = new 
 * List<NekiTip>(); }*/
/*public class A
{
    private int a=14;
}
public class B:A
{
   public int b;
    public static void Main()
    {
        B b = new B();
        b.a = 14;

    }
}*/
/*class X { public int x=4; }
class Y : X { }
class Z : Y { }*/
/*class X { int x; public X(int i) { x = i; } }
 class A : X { int a; public A(int k):base(4){k = a;}
}
 class B { internal int b; public B() : base() => b = 5; }
 class C : B { public static int c; public C(int x) { } }
 class D : A { int d; public D(int y): base(2) { d = y; } }
 class E : C { int e; public E(int z) { e = z; } }*/
/*interface I {abstract void Metoda(); }
 //abstract class A : I { public int x => 1; }
 abstract class B { public abstract int M { get; } }
 abstract class C : B, I { public abstract void Metoda(); }
 class D : C { public override int M { get => 1; } }
 sealed class E : D {  }
 //class F : E { public int f; }*/
/*interface A { void M(); }
abstract class B : A { public void M() { } }
class C : B { }
sealed class D : C { }*/
/*partial class K
{
    public int broj;
    public K(int b) {broj = b; }
    public virtual int M() { return broj; }
}
partial class K { public K() : base() { } }
// partial class K { string broj; }
 //partial class K { static int M() => 0; }
 //partial class K { byte M() { return -1; } }
 public partial class K{ public int M(int x = 0) { broj = x; return 0; } }
//partial class K { abstract void M1(int broj); }*/
/*public delegate int Delegat(ref int a, int b);
public class Klasa
{
    public int A(out int a, int b) => a = b;
    private protected int B(ref int a, int b) => a + b;
    public static int C(ref int a, short b) => a + b;
}*/
/*public class Program 
{
    

    public static void Main()
    {
        int[] niz = { 92, 48, 101, 37, 210, 58 };
        var a = niz.Select((x, i) =>( new { P=i/3, O=x/5})).Last(x=>x.P<0.5);
        Console.Write($"{ a.O}:{ a.P}");

    }
}*/
/*public class A { }
class B : A { }
class C : A { }*/
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
}
class Program
{

    static void Main()
    {
        D d = new D(2);
        foreach (int broj in d.niz)
        {
            Console.Write(broj);
        }
    }
}*/
/*public delegate void Obrada(double suma);
public class Racun
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
            Dogadjaj(iznos);
        }
    }
}*/
/*class X { public int x; }
class Y : X { }
class Z : Y { }*/
/*class X { int x; public X(int i) { x = i; } }
class A : X { int a;
public A(int k): base(k){k = a;}
}
class B { internal int b; public B() : base() => b = 5; }
class C : A { public static int c; public C(int x) : base(4)   { } }
class D : A { int d; public D(int y):base(4) { d = y; } }
class E : B { int e; public E() : base() {  } }*/
/*interface I { void Metoda(); }
 abstract class A : I { public abstract int M { get; } public void Metoda() { } }
 abstract class B : A { public int x => 1; }
 abstract class C : B, I {  }
 class D : C { public override int M { get => 1; } }
 sealed class E : D { }
 //class F : E { public int f; }*/
/*interface A { void M(); }
abstract class B : A { public void M() { } }
class C : B { }
class D : C { }*/
/*class K
{
   public void X(int k) { }
   public void X(int i=0) { }
}




public class Banka
{
   public static int M(int x)
   {
       int y;
       F();
       return ++y;
       void F() {
           var a = new { P = 2, O = x + 2 }; y = a.O - a.P;
       }
   }


   static void Main()
   {
       Console.WriteLine(M(2));
   }
}*/
/*public delegate int Delegat(ref int a, int b);
public class Klasa
{
    public int A(out int a, int b) => a = b;
    protected int B(ref int a, int b) => a + b;
    public static int C(ref int a, int b) => a + b;
}*/
/*public class Program {
    public static int M(int x)
    {
        int y = 1;
        Func<int> f = () => { int z = 1; y++; return x + y + z; };
        y = 3;
        return f();
    }
    
    
    public static void Main()
    {
        int[] niz = { 1, 2, 3, 4, 5, 2, 3 };
        var v = niz.Distinct().Select((x, i) => (i % 2 == 0) ? 1 : x * 2).First();
        
            Console.WriteLine(v);
        
    }
}*/
/*public class A
{
    public int x = 10;
    public virtual int Prva() { x += 2; return 1; }
    public int Druga() { return 3; }
}
public class B : A { }
public class C : B
{
    public new int Druga() { return 5; }
}
public class D : C
{
    public override int Prva() { x += 6; return 9; }
}*/
/*public class A
{
    public List<int> lista = new List<int>();
    public A() : this(7) { lista.Add(1); }
    public A(int i) : base(){ lista.Add(i+2); }
}
public class B : A { }
public class C : B
{
    public C(){ lista.Add(3); }
    public C(int i) : base() { lista.Add(i + 4); }
}
public class D : C
{
    public D(int i) : base() { lista.Add(i + 5); }
    public D() : this(1) { lista.Add(6); }
}
class Program
{

    static void Main()
    {
        D d = new D();
        foreach (int broj in d.lista) { Console.Write(broj); }
    }
}*/
/*public delegate void Obrada(double suma);
public class Racun
{
    string broj; double stanje;
    public Racun(string b, double s) { broj = b; stanje = s; }
    public event Obrada Dogadjaj;
    public void promeni(double iznos)
    {
        if (stanje + iznos < 0) return;
        stanje += iznos;
        if (Dogadjaj != null)
        {
            Dogadjaj(iznos);
        }
    }
}

public class Banka
{
   
    static void Main()
    {
        
    }
}*/
/*public delegate void Operacija(ref int x);
class Skup
{
    public int[] niz = { 2, 4, 6, 8, 10 };
    public int this[int pozicija] { get { return niz[^(pozicija - 2)]; } }
}*/
/*class X { int x; public X(int i) { x = i; } }
//class A : X { int a; }
class B { int b; public B():base() { b=5;}}
//class C : B { int c; public C() { b = 5; } }
class D : B {int d; public D(int y) { d = y; } }
class E : D{int e; public E(int z) : base(z) { e = z; }
    */
/*interface I { void Metoda(); int Pomnozi(); }
abstract class A
{
    public int x => 1;
    abstract class B { public abstract int M { get; } }
    abstract class C : B, I { public int Pomnozi() { return 0; } public void Metoda() { } }
    class D : C { public override int M { get => 1; } }
    sealed class E : D { public int x => 1; }
}
    */
/*partial class K
{
    public int broj;
    public K(int b) { broj = b; }
    public virtual int M() { return broj; }
}
partial class K { public K() : base() { } }
//partial class K { string broj; }
//partial class K { static int M() => 0 }
//partial class K { byte M() { return 1; } }
public partial class K{ public int M(int x = 0) { broj = x; return 0; } }
 partial class K { void M1(int broj) { broj += broj; } }*/
/*public class Klasa
{
    public int A(ref int a, short b) => a + b;
    int B(int a, short b) => a + b;
    public static int C(int a, short b) => a + b;
}*/
/*class A
{ public virtual void M1() => Console.Write(1); }
class B : A
{ public override void M1() => Console.Write(2); }
class C : B{ }*/
/*class Osoba { }
class Student : Osoba { }*/
public class A{
    public int[] niz = new int[6];
    public A(): this(7){ niz[5] = 1;}
    public A(int i) : base()
    {
        niz[4] = 1;
    }

}
public class B : A { }
public class C : B
{
    public C() : this(8){ niz[3] = 2;}

    public C (int i) { niz[2] = i; }

}
public class D : C
{
    public D(int i) : this() { niz[2] = i; }


    public  D(){niz[0] = 3;}

}
class Program
{
    

    static void Main()
    {
        D d = new D(3);
        foreach (int broj in d.niz) Console.Write(broj);
    }
}
  
