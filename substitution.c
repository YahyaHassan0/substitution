#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{


    if (argc < 2 || argc > 2)   //since the characters stored all in index 1
    {
        printf("Usage: ./substitution key\n");  //if command line argument more than 1 error
        return 1;
    }
    string k = argv[1];  //transfering argv array idex 1 to another arry with multiple indeces for each char
    int x = strlen(k);  //defining the size of the array k


    if (x != 26)  //if the key doesnt equal 26 char error
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < x; i++)  //checking if the user typed alphabatic chars or not (KEY)
    {
        if (!isalpha(k[i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    for (int q = 0; q < x; q++)  //check the uniqueness for each char by nested for loop
    {
        for (int w = q + 1; w < x; w++)
        {
            if (tolower(k[q]) == tolower(k[w]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    string inp = get_string("plaintext: ");  //taking input from the user
    printf("ciphertext: ");

    for (int j = 0; j < strlen(inp); j++)
    {
        if (islower(inp[j]))
        {
            int l = inp[j] - 97;
            printf("%c", tolower(k[l]));
        }
        else if (isupper(inp[j]))
        {
            int l = inp[j] - 65;
            printf("%c", toupper(k[l]));
        }
        else
        {
            printf("%c", inp[j]);
        }
    }
    printf("\n");




}