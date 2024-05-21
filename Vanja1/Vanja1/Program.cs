// See https://aka.ms/new-console-template for more information
class program
{
   public  enum Rok { Januar, Februar, Jun=3, Jul, Septembar, Oktobar }
            //   0         1     2    3       4         5
    enum TVrsta { Kvadrat, Trougao, Romb, Mnogougao }

    public enum TPovez { Korice, Karton, Spirala, Ostalo }

    public enum Vrsta { Kreditna, Debitna }

    public class Knjiga
    {
        public string naziv;
       // public TDimenzija dimenzija; 
        public TPovez povez;
        public short brojStrana;
        public void Visina(double debljinaPapira)
        { //dimenzija.visina = brojStrana * debljinaPapira;
         }
    }
    public struct Index
    {
        public int broj; public int godina;
    }
    public class Ispit
    {
        public string predmet; public Index student; public Rok rok;
        public double brojPoena; public int ocena;
    }
    static void Main()
    {
        /* /* Console.WriteLine("Hello, World!");

          bool b = true;
          int x = Convert.ToInt32(b);
          Console.WriteLine(x);

          int y = Convert.ToInt32("159");
          Console.WriteLine(y);

          float f = Convert.ToSingle("126.199");
          float k = 127 + f;
          Console.WriteLine(k);

          int z;
          int.TryParse("Stef", out z);
          Console.WriteLine(z);

          int a = (int)Rok.Oktobar;
          Console.WriteLine(a);

          Rok r= new Rok();
          Console.WriteLine(r);
         */

        //NULLABLE

        /*int x=15;
        int? y = x;

        Console.WriteLine(x);
        Console.WriteLine(y);
        */

        //VAR i DYNAMIC

        /* var x=5.3;
         x = 7;

         dynamic y = 9;
         y = null;
        */

        //ZADACI

        /* var x = 3.2;
         dynamic y = 2.3f;

         //x = "a";
         //y = "ab";
         //x = 'c';
         //y = 's';
         //x = true; 
         //y = false;
         //x = null; 
         //zy = null;
        */

        /* var x = 3; dynamic y = 2.3f; decimal? z=1.86m;
         // x = z;
         //y = z;
         //y = (int)true;
         //x = (int)z;
         //y = new int[] { };
        // x = (int)y;
        */

        /*var x = 1;
        //short prom1 = x;
        //string prom2 = x;
        //long prom3 = x;
        //double? prom4 = x;
        //var prom5 = x;
        */

        /*var x = 1;
        //char prom1=(char)x;
        //bool prom2 = (bool)x;
        int[] prom4 = { x };
        int? prom3 = x;
        int prom5 = Math.Abs(x);
        */

        /* //float x = 8.7f;
         //bool x=true;
         //string x = "123";
         //char x = '$';
         TVrsta x = TVrsta.Kvadrat;
         long prom = (long)x;
         */

        /* short s = 3;
         int i = (byte)s;
         //byte b = (ushort)s;
         long l = s;
         float f = s;
         //short? b = (int)s;
         short? p = s;
         //char c = s;
        */

        //decimal d = 1.2M; double b = (float)d; Console.WriteLine(b);

        /*double broj1 = 10.3;
        byte broj2 = 3;

        //broj1 = broj2;
        //broj1 = (double)broj2;
        //broj2 = broj1;
        //broj2 = (byte)broj1;
        //int broj3 = broj2;
        //string broj4 = (string)broj2;
        */

        /*char prom1 = 'x';
        char? prom2 = 'y';

        //prom2 = null;
        prom2 = prom1;
        */

        /*// var x = 1.2;
        //string x = '1';
        //long x = 1;
        //TPovez x = TPovez.Ostalo;
        //char x = '#';
        bool x = true;
        int y = (Console.ReadLine() == "Da") ? x : 9;
        Console.WriteLine(y);
        */

        /* var x = 1.2f;
         dynamic y = 3.1m;

         //x = 5.6f;
         //x = y;
         //x = (int)'#';
         //y = x;
         //x = (int)y;
         //y = new Knjiga();
        */

        /*float x = 1;
        //double prom = x;
        //long prom = x;
        //bool prom = x;
        //double? prom = x;
        float? prom = x;
        */

        /* var x = 1.2; //double
         dynamic y = 3.4m;

         //x = 5.6f;
         //x = (int)y;
         //x = (int)'#';
         //x = y;
         //y = x;

         Console.WriteLine(x.GetType());
         Console.WriteLine(y.GetType());
        */

        int i;
        String s;
        Rok r;
        Index x;
        Ispit k = new Ispit();

        //i += x.godina;
        //i += k.student.godina;
        s = k.predmet;
        //x.broj += 2;
        r = k.rok++;
        //k.student.godina = x.godina;
        
    }
}