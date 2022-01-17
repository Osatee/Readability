#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int compute_index(int word, int letter, int sentence);

int main(void)
{
    //declare variable
    int letter = 0;
    int word = 1;
    int sentence = 0;
    
    char text[256];
    printf("Text: ");
	scanf( "%s" , text);
    
    //Calculate letter, word, and sentence
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //change to lowercase
        if (isupper(text[i]))
        {
            char allLow = tolower(text[i]);
            
            if (allLow >= 'a' && allLow <= 'z')
            {
                letter++;
            }
        }
        
        //Count number
        else if (islower(text[i]))
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                letter++;
            }
        }
        
        //Count word
        else if (text[i] == ' ')
        {
            word++;
        }
        
        //Count sentence
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    
    int level = compute_index(word, letter, sentence);
    
    //Check level
    if (level <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", level);
    }
}

//Caculate index
int compute_index(int word, int letter, int sentence)
{
    float L = letter * 100 / (float)word;
    float S = sentence * 100 / (float)word;
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    
    return index;
}
