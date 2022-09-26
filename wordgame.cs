/*
Console word guessing game 
Sept 22, 2022
*/

using System;
using System.Linq;

class Game
{
    public static void Main(string[] args)
    {
        Console.WriteLine("\n*******************************");
        Console.WriteLine("* MEDIOCRE WORD GUESSING GAME *");
        Console.WriteLine("*******************************");
        Console.Write("\nEnter a word: ");
        string HiddenWord = Console.ReadLine();

        //Test if input is a word
        bool WordTest = HiddenWord.All(Char.IsLetter);
        while (WordTest == false || HiddenWord.Length == 0)
        {
            Console.Write("\nThat's not a word...\nTry again: ");
            HiddenWord = Console.ReadLine();
            WordTest = HiddenWord.All(Char.IsLetter);
        }

        HiddenWord = HiddenWord.ToUpper();

        Console.WriteLine("\nPress ENTER to begin guessing");
        Console.ReadLine();
        Console.Clear(); //clear screen to hide given word

        int lives = 5;
        int counter = -1;
        int WordLength = HiddenWord.Length;
        char[] HiddenArray = HiddenWord.ToCharArray();
        char[] PrintArray = new char[WordLength];
        char[] GuessedLetters = new char[26];
        bool victory = false;

        foreach(char letter in PrintArray)
        {
            counter++;
            PrintArray[counter] = '?';
        }

        while(lives > 0)
        {
            counter = -1;
            string PrintAnswered = string.Concat(PrintArray);
            bool letterFound = false;
            int multiples = 0;

            if (PrintAnswered == HiddenWord)
            {
                victory = true;
                break;
            }

            if (lives > 1)
            {
                Console.WriteLine("You have {0} lives left.", lives);
            }
            else
            {
                Console.WriteLine("You have {0} life left.", lives);
            }

            Console.Write("\n");
            Console.WriteLine(PrintAnswered);
            Console.Write("\n");
            Console.Write("Guess a letter: ");
            string guess = Console.ReadLine();

            //Test if input is a letter
            bool GuessTest = guess.All(Char.IsLetter);
            while (GuessTest == false || guess.Length != 1)
            {
                Console.WriteLine("One letter please.");
                Console.Write("Letter: ");
                guess = Console.ReadLine();
                GuessTest = guess.All(Char.IsLetter);
            }

            guess = guess.ToUpper(); 
            char playerchar = Convert.ToChar(guess);

            //Test to avoid repeated guesses
            if (GuessedLetters.Contains(playerchar) == false) 
            {
                foreach(char letter in HiddenArray)
                {
                    counter++;
                    if (letter == playerchar)
                    {
                        PrintArray[counter] = playerchar;
                        letterFound = true;
                        multiples++;
                    }
                }
                if (letterFound)
                {
                    Console.WriteLine("{0} letter {1} found", multiples, playerchar);
                }
                else
                {
                    Console.WriteLine("No letter {0}", playerchar);
                    lives--;
                }               
            }
            else
            {
                Console.WriteLine("You already guessed the letter {0}", playerchar);
            }

        }

        if(victory)
        {
            Console.WriteLine("\nYou guessed adequately\nThe word was {0}\n\n", HiddenWord);
        }
        else
        {
            Console.WriteLine("\nYou are a disgrace. The word was {0}\n\n", HiddenWord);
        }

        Console.WriteLine("Press ENTER to quit");
        Console.ReadLine();
        Console.Clear();
    }

}
