// Author: Nusra Ahmed
// Class: Harvard CS50
// Description: Short program that will evaluate a credit card number from a user
// and will either return the name of the provider or INVALID. Also returns the number
// of digits in the user input.

#include <stdio.h>
#include <cs50.h>

//function prototypes
int numDigits(char charArray[]);

int sumOfMultipliedDigits(char charArray[]);

int main(void)
{
    //prompt user for a credit card number
    long int cardNum;
    do
    {
        // get_long function is provided by the cs50 header file
        cardNum = get_long("Number: ");
    }
    while (cardNum <= 0);

    //create a character array from the long integer
    char result[16];
    sprintf(result, "%lu", cardNum);

    //calculate the number of digits in the character array
    int digits = numDigits(result);

    //parse through the character array and split up the digits
    char everyOther[digits / 2];
    char leftovers[digits / 2];
    int len = 0;
    for (int j = digits - 1; j >= 0; j = j - 2)
    {
        leftovers[len] = result[j];
        everyOther[len] = result[j - 1];

        everyOther[len + 1] = '\0';
        leftovers[len + 1] = '\0';
        len = len + 1;
    }

    //Find the sum of the multiplied digits
    int sum = sumOfMultipliedDigits(everyOther);

    //Find the sum of the digits that were not multiplied
    int z = 0;
    int notMultSum = 0;
    for (int n = 0; leftovers[n] != '\0'; n++)
    {

        z = (int)(leftovers[n] - 48);
        notMultSum = notMultSum + z;
    }

    //validate that the 2 sums add up to a multiple of 10
    int validate = (sum + notMultSum) % 10;
    bool isValid = 1;
    if (validate != 0)
    {
        isValid = 0;
        printf("INVALID\n");
    }

    //check which company the card is only if it passes the previous test
    if (isValid == 1)
    {
        if (cardNum >= 4000000000000000 && cardNum <= 4999999999999999)
        {
            printf("VISA\n");
        }
        else if (cardNum >= 4000000000000 && cardNum <= 4999999999999)
        {
            printf("VISA\n");
        }
        else if (cardNum >= 5100000000000000 && cardNum <= 5599999999999999)
        {
            printf("MASTERCARD\n");
        }
        else if (cardNum >= 340000000000000 && cardNum <= 349999999999999)
        {
            printf("AMEX\n");
        }
        else if (cardNum >= 370000000000000 && cardNum <= 379999999999999)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int numDigits(char charArray[])
{
    int i = 0;
    int digits = 0;
    while (charArray[i] != '\0')
    {
        digits++;
        i++;
    }
    printf("Digits: %i\n", digits);
    return digits;
}

int sumOfMultipliedDigits(char charArray[])
{
    int x = 0;
    int y = 0;
    int sum = 0;
    for (int n = 0; charArray[n] != '\0'; n++)
    {
        //Convert ASCII to integer by subtracting 48
        int multiple = (int)(charArray[n] - 48) * 2;
        if (multiple >= 10)
        {
            //Encountered a double digit
            x = (int)(charArray[n] - 48) * 2;
            sum = sum + x / 10;
            sum = sum + x % 10;
        }
        else
        {
            y = (int)(charArray[n] - 48) * 2;
            sum = sum + y;
        }
    }
    return sum;
}