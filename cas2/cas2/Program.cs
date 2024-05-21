using System;
using System.Collections.Generic;
using System.Net.Mail;
using System.Runtime.CompilerServices;

namespace Cas2;

class Klasa
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
        Program l = new Program();
        l.metoda3(ref p, out z);
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
        //p.x = 3 // p.y=12 fwwd
        Klasa k = new Klasa();
        //5 10
        k.metoda1(k.broj1, k.broj2);
        //k1.broj1 = 5, k1.broj2=10
        Klasa.metoda3(out k.broj1, ref k.broj2);
        //k1.broj1 = 2, k1.broj2=3
        Console.WriteLine("Program vrednosti:" + p.x + " " + p.y); Console.WriteLine("Klasa vrednosti:" + k.broj2 + " " + k.broj1);
    }
}
