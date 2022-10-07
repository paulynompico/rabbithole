/*
Simple input string reversal code
October 7, 2022
*/

using System;

namespace reversestring
{
    class word
    {
        static void Main()
        {
            Console.Write("Input a word: ");
            string theword = Console.ReadLine();
            Console.WriteLine(reverse(theword));
        }
        
        public static string reverse(string x)
        {
            string newword = "";
            for (int i = x.Length; i > 0; i--)
            {
                newword = newword + x.Substring(i - 1, 1);
            }
            return newword;
        }
    }
}
