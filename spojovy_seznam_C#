using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace zkouka_Prg
{
    class Program
    {
        public class Seznam
        {

            public int data;
            public Seznam next;
            public Seznam prev;

        }


        static void Zobraz(Seznam s)
        {


            while (s != null)
            {

                Console.Write(s.data + " ");
                s = s.next;


            }

            Console.WriteLine();



        }



        static Seznam Novy(int n)
        {
            Seznam vys = new Seznam();
            vys.data = n;
            vys.next = null;
            vys.prev = null;
            return vys;


        }

        static Seznam PoleSeznam(int[] pole)
        {

            int i;
            Seznam vys, akt, tmp;
            if (pole.Length == 0) return null;
            vys = akt = null;
            for (i = 0; i < pole.Length; i++)
            {
                tmp = Novy(pole[i]);
                tmp.prev = akt;
                if (vys == null) vys = akt = tmp;
                else akt = akt.next = tmp;



            }

            return vys;

        }


        static int[] SeznamPole(Seznam s)
        {

            Seznam akt = s;
            int i = 0;
            while (akt != null)
            {
                i++;
                akt = akt.next;
            }

            int[] pole = new int[i];
            for (int k = 0; k < i; k++)
            {

                pole[k] = s.data;
                s = s.next;


            }






            return pole;
        }


        static Seznam Zacatek(Seznam s, int n)
        {

            Seznam tmp = Novy(n);
            tmp.next = s;
            s.prev = tmp;
            return tmp;



        }


        static Seznam Konec(Seznam s, int n)
        {

            Seznam akt = s, tmp = Novy(n);
            if (akt == null) return tmp;
            while (akt != null)
            {
                if (akt.next == null)
                {

                    tmp.prev = akt;
                    akt.next = tmp;
                    return s;
                }
                akt = akt.next;
            }

            return s;

        }
        static Seznam PridejPo(Seznam s, int kam, int co)
        {

            Seznam tmp = Novy(co);
            Seznam akt = s;
            while (akt != null)
            {

                if (akt.data == kam)
                {


                    tmp.prev = akt;
                    tmp.next = akt.next;
                    akt.next = tmp;

                    return s;
                }

                akt = akt.next;


            }
            return null;

        }

        static Seznam Smaz(Seznam s, int co)
        {

            Seznam akt = s;
            Seznam tmp2 = Novy(co);
            Seznam tmp3;
            tmp2 = new Seznam();
            tmp3 = null;
            while (akt != null)
            {


                if (akt.data == co)
                {



                    tmp2 = akt.next;
                    tmp3.next = tmp2;
                    tmp2.prev = akt.prev;
                    return s;


                }

                tmp3 = akt;
                akt = akt.next;
            }

            return s;

        }




        static Seznam PridejPred(Seznam s, Seznam kam, int n)
        {



            Seznam tmp = Novy(n);
            if ((kam == null) || (kam.prev == null)) return Zacatek(s, n);
            tmp.prev = kam.prev;
            kam.prev.next = tmp;
            kam.prev = tmp;
            tmp.next = kam;
            return s;

        }


        private static void Quick_Sort(int[] arr, int left, int right)
        {
            if (left < right)
            {
                int pivot = Partition(arr, left, right);

                if (pivot > 1)
                {
                    Quick_Sort(arr, left, pivot - 1);
                }
                if (pivot + 1 < right)
                {
                    Quick_Sort(arr, pivot + 1, right);
                }
            }

        }

        private static int Partition(int[] arr, int left, int right)
        {
            int pivot = arr[left];
            while (true)
            {

                while (arr[left] > pivot)
                {
                    left++;
                }

                while (arr[right] < pivot)
                {
                    right--;
                }

                if (left < right)
                {
                    if (arr[left] == arr[right]) return right;

                    int temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;


                }
                else
                {
                    return right;
                }
            }


        }


        static void ZobrazPole(int[] pole)
        {

            for (int i = 0; i > pole.Length; i++)
            {


                Console.WriteLine(pole[i] + " ");



            }

            Console.WriteLine();

        }



       

        static Seznam Cykl(Seznam s)
        {

            Seznam akt = s;
            while (akt != null)
            {
                if (akt.next == null)
                {
                    akt.next = s;
                    s.prev = akt;
                    return s;
                }
                akt = akt.next;
            }
            return s;



        }

        static void ZobrazCykl(Seznam s)
        {
            Seznam akt = s;
            if (akt == null) return;
            {
                while (akt.next != s)
                
                {
                    
                    Console.WriteLine("Cyklický seznam" + akt.data);

                    akt = akt.next;
                }

                Console.WriteLine();
            }

        }

        static void Main(string[] args)
        {


            Console.WriteLine("Kolik chcete zadat čísel do seznamu? Minimální počet je 7");
            int cisla = Convert.ToInt32(Console.ReadLine());
            int[] pole = new int[cisla];
            for (int i = 1; i < cisla && cisla > 7; i++)
            {

                Console.Write("Zadejte {0} cislo: ", i);




                pole[i] = Convert.ToInt32(Console.ReadLine());


            }




            Seznam s1 = PoleSeznam(pole);
            Zobraz(s1);
            Seznam s2 = new Seznam();


            Console.WriteLine("Chcete nějakou hodnotu do seznamu přidat, smazat nebo pokračovat? ");
            Console.WriteLine("1. - Přidej");
            Console.WriteLine("2. - Smaž");
            Console.WriteLine("3. - Nic");
            string menu = Console.ReadLine();

            if (menu == "1")
            {

                Console.WriteLine("Kam chcete vkládat?");
                int kam = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Co chcete vkládat?");
                int co = Convert.ToInt32(Console.ReadLine());



                PridejPo(s1, kam, co);
                Zobraz(s1);
            }


            else if (menu == "2")
            {

                Console.WriteLine("Co chcete mazat?");
                int co = Convert.ToInt32(Console.ReadLine());





                Smaz(s1, co);
                Zobraz(s1);

            }



            else
            {


                Console.WriteLine("Ok, nedělám nic, pokračuji");
                Console.ReadLine();



            }




            Console.WriteLine("Původní pole Quicksort : ");
            foreach (var item in pole)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine();

            Quick_Sort(pole, 0, pole.Length - 1);

            Console.WriteLine();
            Console.WriteLine("Setřídené pole QuickSort : ");

            foreach (var item in pole)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine();




            Seznam s4 = Cykl(s1);
            ZobrazCykl(s4);

            Console.ReadLine();





        }

    }


}
