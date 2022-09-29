/*
Sorts list and finds the median after every input (max of 6 integers)
September 29, 2022
*/

using System;

namespace MedianFinder
{
    class MyList
    {
        static void Main(string[] args)
        {
            int[] n = new int[0];
            int x, j;
            double median;

            for (x = 0; x < 6; x++) //limits the number of input to 6
            {
                Console.Write("Integer #{0}: ", x + 1);
                int y = Convert.ToInt16(Console.ReadLine());
                n = n.Concat(new int[] { y }).ToArray(); //adds input to array
                
                //Display sorted list
                Console.Write("Your sorted list: ");
                Array.Sort(n);
                for (j = 0; j < n.Length - 1; j++)
                {
                    Console.Write("{0}, ", n[j]);
                }
                Console.WriteLine("{0}", n[n.Length - 1]);

                int i = n.Length / 2;
                if (n.Length % 2 == 0)
                {
                    median = (n[i] + n[i - 1]) / 2.0;
                }
                else
                {
                    median = n[i];
                }
                Console.WriteLine("Median: {0}\n", median);
            }
        }
    }
}
