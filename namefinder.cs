/*
Checks list of names based on string input
September 29, 2022
*/

using System;

namespace NameFinder
{
    class MyList
    {  
        static void Main(string[] args)
        {
            string letter;
            List<string> names = new List<string> {"HEDI","PAULYN","HELGA","HAROLD"};
            Console.Write("Name/s starting with: ");
            letter = Console.ReadLine().ToUpper();
            Console.WriteLine("\nName/s found:");

            for (int i = 0; i < names.Count; i++)
            {
                if (names[i].StartsWith(letter))
                {
                    Console.WriteLine(names[i]);
                }
            }
        }
    }
}
