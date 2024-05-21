using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    enum Enumeracija
    {
        Prolece = 5,
        Leto = 1,
        Jesen = 4,
        Zima = 0
    }
    // public enum Operacija { Kvadrat, Plus = 2, Puta, Minus = 1, Podeljeno = 4 }

    class Program
    {
        public enum Operacija { Kvadrat, Plus = 2, Puta, Minus = 1, Podeljeno = 4 }

        public static void Main(string[] args)
        {
            Operacija op = 0; int x = 10; int y = 2; if (x / y > 1) op++; else op--;
            switch (op)
            {
                // default: op += 1;
                case Operacija.Plus: break;
                case Operacija.Minus: op -= 2;
                case Operacija.Puta:
                case Operacija.Podeljeno: op -= 2; break;
            }
        }
    }
}

        

