/*
 * author: Sam Clark
 *
 * e-mail: sclark13@calpoly.edu
 *
 * created: Wednesday, September 14, 2011, 15:45 PDT
 *
 * last edited: Tuesday, September 27, 2011, 20:32 PDT
 *
 */


/* OVERVIEW
 * 
 * 1) main() checks that the there is exaclty one argument (excluding the 
 *    command name) and that the argument is within the range. If either 
 *    condition is not met, it returns an error.
 *
 * 2) If the conditions are satisfied, main() calls algorithm() which is the 
 *    real meat and potatoes of the program. 
 * 
 * 3) algorithm() checks the character count, prints to the screen, and passes
 *    arguments to countEnglishLetters()
 *
 * 4) countEnglishLetters splits the number into a tens' place and a ones' palce. 
 *    From there, the values are passed to switches that assign the character
 *    count. 
 *
 * 5) algorithm() is called recursively until there are two terminal 4's.
 */


#include <stdio.h>

typedef unsigned int uint;         //'unsigned int's evaluate faster than 'int's

uint letterCount;                  //number of letters in the standard English spelling of the number
uint firstFour = 0;                //used such that the number 4 will appear twice and only twice
uint firstNumber = 1;


uint main(uint argc, char *argv[])
{
    uint arg;

    sscanf(argv[1], "%d", &arg);                 //reads the char * from the command line argument as an int

    if(argc == 2 && arg != 0 && arg < 100)       //there must be exactly two arguments (including the function name) and the second one must be between 1 and 99, inclusive
    {
        printf("%i ", arg);                      //print the first number to start the pattern
        algorithm(arg);                          //run the function algorithm() with the command line argument, arg, as the parameter
    }
    else                                         //if the conditions are not meant, print the error message
    {
        printf("error -- usage: %s [NUMBER]\nAll numbers should be between 1 and 99, inclusive\n", argv[0]);
        return;
    };

    return;
};

uint countEnglishLetters(uint number)
{
    uint tensPlace = number / 10;          //evaluates the single number in the tens' place; 0 if less than 10
    uint onesPlace = number % 10;          //evaluates the single number in the ones' place

    if(tensPlace == 1)
    {        
        switch(number)
        {
            case 10: letterCount += 3; break; //  ten
            case 11: letterCount += 6; break; //  eleven
            case 12: letterCount += 6; break; //  twelve
            case 13: letterCount += 8; break; //  thirteen
            case 14: letterCount += 8; break; //  fourteen
            case 15: letterCount += 7; break; //  fifteen
            case 16: letterCount += 7; break; //  sixteen
            case 17: letterCount += 9; break; //  seventeen
            case 18: letterCount += 8; break; //  eighteen
            case 19: letterCount += 8; break; //  nineteen
            default: break;
        }
    }
    else
    {
        switch(onesPlace)
        {
            case 0: letterCount += 0; break; //  -
            case 1: letterCount += 3; break; //  one
            case 2: letterCount += 3; break; //  two
            case 3: letterCount += 5; break; //  three
            case 4: letterCount += 4; break; //  four
            case 5: letterCount += 4; break; //  five
            case 6: letterCount += 3; break; //  six
            case 7: letterCount += 5; break; //  seven
            case 8: letterCount += 5; break; //  eight
            case 9: letterCount += 4; break; //  nine
            default: break;
        }

        switch(tensPlace)
        {
            case 0: letterCount += 0; break; //  -
            case 2: letterCount += 5; break; //  twenty* (if if the tens' place is one then it'll catch in the first switch)
            case 3: letterCount += 6; break; //  thirty*
            case 4: letterCount += 5; break; //  forty*
            case 5: letterCount += 5; break; //  fifty*
            case 6: letterCount += 5; break; //  sixty*
            case 7: letterCount += 7; break; //  seventy*
            case 8: letterCount += 6; break; //  eighty*
            case 9: letterCount += 6; break; //  ninety*
            default: break;
        };
    };        
};

int algorithm(uint input)              //NOTE: algorithm() is declared as 'int'
{	
    if(input == 0) return;             //failsafe if somehow letterCount or arg is set to 0
    if(firstFour != 0) 
    {
        printf("-> 4 -> 4\n");              //if a 4 has been output, then print the last 4 and exit
        return;
    };

    if(firstNumber == 0) printf("-> %i ", input);     //if this input is not the first number, print the "->" before the number
    firstNumber = 0;	                              //'firstNumber' set to FALSE
    letterCount = 0;                                  //'letterCount' reset to 0 to go through the loop again.
    countEnglishLetters(input);                       //run countEnglishLetters() with the last 'letterCount' (now saved as 'input') as the parameter

    if(letterCount == 4) firstFour = 1;               //if a 4 has been output, 'firstFour' is set to TRUE

    algorithm(letterCount);                           //run algorithm() with the new 'letterCount' from countEnglishLetters() in line 111
};

