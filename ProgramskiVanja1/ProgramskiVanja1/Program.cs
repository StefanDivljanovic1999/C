using System.Globalization;

class zadatak1
{
    int sabiranje(int a, int b)
    {
        return a + b;
    }

    enum dani
    {
        pon,
        uto,
        sre,
        cet,
        pet,
        sub,
        ned
    }

    public enum rok {januar=10,februar=2,jun,jul,septembar=4,oktobar}
   

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
    public static void Main()
    {
        /* Console.WriteLine("ides za kanadu,sivi audi rolam po Beogradu :)");
         int x = Convert.ToInt32(false);
         Console.WriteLine(x);
         float f = Convert.ToSingle("1229,64");
         Console.WriteLine(f);
         float p = f / 3;
         Console.WriteLine("Vrednost varijable p je:" +p);


         float s;
         float.TryParse("123,457",out s);
         Console.WriteLine(s);


         int rok1 = Convert.ToInt32(rok.oktobar);
         Console.WriteLine(rok1);

         rok r = (rok)10;
         Console.WriteLine(r);

         rok r1 = new rok();
         Console.WriteLine(r1);

          int? x=5;
           //Nullable<int> x= 5;

           Console.WriteLine(x.HasValue);

           int? y = x;
           Console.WriteLine(y);

           int z = 8;
           int? c = z;
           Console.WriteLine(c); */

        /* var x = 3.2;
         dynamic y = 2.3f;

         //x = 18.56;
         //y=x;
         //x = "a";
         // y = "a";
         //x = 'c';
         //y = 's';
         // x = true;
         // y = true;
         //x = null;
         //y = null;

         */

        /* var x = 3;
         dynamic y = 2.3f;
         decimal? z = 1.86m;

         //x = z;
         //y = z;
         //y = (int)true;
         //x=(int)y;
         //x = (int)z;
         //y = new int[] { };
        */

        /* var x = 1;
         //short prom1 = x;
         //string prom2 = x;
         //long prom3 = x;
         //double? prom4 = x;
         //var prom5 = x;
        */

        /*  var x = -1;
          char prom5 = (char)x;
          bool prom1 = Convert.ToBoolean(x);
          int[] prom4 = { x };
          int? prom3 = x;
          int prom2= Math.Abs(x);

          */

        /*float x = 1f;
        double a = x;
        //long b = x;
        //bool c = x;
        double? d = x;
        float? f= x;
        */

        /*  //float x = 8.7f;
          //bool x = true;
          //string x = "123";
          //char x = '$';
          rok x = rok.januar;

           long prom = (long)x;
         // long prom;
          //long.TryParse(x, out prom);
         */

        /*float x = 1;
        //long prom = x;
        //char prom = x;
        //double? Prom = x;
        float? Prom = x;
        */

        /*   short s = 3;
           //byte i = (byte)s;
           //ushort b = (ushort)s;
           //long l = s;
           //float f = s;
           //short? b = (int)s;
           //short? p = s;
           //char c = s;
          */

        /* decimal d = 1.28M;
         double b=(float)d;
         Console.WriteLine(b);
        */

        /*double broj1 = 10.3;
        byte broj2 = 3;

        //broj1 = broj2;
        //broj1 = (double)broj2;
        //broj2 = broj1;
        //broj2 = (byte)broj1;
        //int broj3 = broj2;
        //string broj4 = (string)broj2;
        */

        /* char prom1 = 'x';
         char? prom2 = 'y';
         //int x = 9;
         //prom1 = null;
         //prom2 = null;
         //prom1 = prom2;
         // prom2 = prom1;

         //bool x = true;
         //string x = "1";
        */

        /*
        //int x = 23;
        //bool x = true;
        //char x = '#';
        //long x = 1;

        //TPovez x = TPovez.Ostalo;
        
       // int y = (Console.ReadLine() == "Da") ?x: 94;
  */

        /*
        var x = 1.2f;
        dynamic y = 3.1m;

        //x = 5.6f;
        //x = y;
        //x = (int)'#';
        //y = x;
        //x = (int)y;
        //y = new Knjiga();
        */
        /* var x = 1;
         //char prom=x;
         //var prom = x;
         //bool prom = x;
        // Vrsta prom = x;
        */

        /* //bool x = true;
         //var x = 3.5m;
         //char x = 'Г';
         // string x = "1";
         Vrsta x = Vrsta.Kreditna;
         long prom = (long)x;
        */

        /* int i; string s; Rok r; Index x;
         Ispit k = new Ispit();

         x.godina = 2018;
         x.broj = 247;

         k.brojPoena = 62;
         k.rok = Rok.Septembar;
         k.predmet = "Programski jezici";
         k.ocena = 7;
         k.student = x;

         s = k.predmet;
         x.broj += 2;
         r = k.rok++;
         k.student.godina = x.godina;
        */

        /*char prom1 = 'x';
        char? prom2 = 'y';

        // prom1 = prom2;
        // prom2 = prom1;
        //prom1 = null;
        prom2 = null;
        */

        double broj1 = 10.3;
        byte broj2 = 3;

        //broj2 = (byte)broj1;
        //broj1 = broj2;
        //broj1 = (double)broj2;
        //broj2 = broj1;
        //int broj3 = broj2;
        //string broj4 = (string)broj2;
        Console.WriteLine("Vrednost promenjive x iznosi: "+broj1);
        Console.WriteLine("Vrednost promenjive y iznosi: " +broj2);

        int x = 10;
        x--;
        Console.WriteLine(--x);
    }
}