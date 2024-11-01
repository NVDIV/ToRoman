#include <stdio.h> 
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes

void capture();
int get_number();
void arabic_to_roman(int num);
void clear_console();
bool continue_calculation();

// Constant declaration

const int MAX_ROMAN_VALUE = 9999;
const int MIN_ROMAN_VALUE = 1;

// Main function

int main() 
{ 
    // Clear console

    clear_console();
    
    // Author and project title

    capture();

    do
    {
        // Get input

        int numeral;

        do
        {
            numeral = get_number();
        } 
        while (numeral <= 0 && continue_calculation);

        // Print the result

        printf("\nThe Roman numeral equivalent of %d is: ", numeral);

        arabic_to_roman(numeral); 
    } 
    while (continue_calculation());
} 

void clear_console() 
{
    system("cls");
}

void capture()
{
    // Author

    printf("\nNadiia Rybak 2023\n");

    // Title

    printf("\nCONVERTATION OF NUMBERS FROM ARABIC TO ROMAN SYSTEM\n\n");
}

int get_number()
{
    // Get input

    char input[4];

    printf("Enter a number (0-9999]: ");

    scanf("%s", input);

    /* Check if input is valid */
    
    // Check if it is an integer (if there are digits only)

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isdigit(input[i]) == 0)
        {
            printf("\nYour input is invalid.\n");
            return -1;
        }
    }

    int result = atoi(input);

    if (result < MIN_ROMAN_VALUE || result > MAX_ROMAN_VALUE)
    {
        printf("\nYour input is invalid.\n");
        return -1;
    }

    return result;
}

void arabic_to_roman (int num) 
{ 
    // Print the number in roman system

    struct {
        int step;
        char* symbol;
    } roman[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };

    for (int i = 0; i <= 12; i++)
    {
        while (num >= roman[i].step)
        {
            printf("%s", roman[i].symbol);
            num -= roman[i].step;
        }
    }
} 

bool continue_calculation()
{
    printf("\nDo you want to enter all of the sides one more time? (enter/esc) \n");

    while(1)
    {
        char response = getch(); 

        if (response == 13)  
        {
            return true;
        }
        else if (response == 27)  
        {
            return false;
        }
    }
}