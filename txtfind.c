#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30

int getline1(char s[]);
int getword(char w[]);
int subs(char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);

int subs( char str1[], char str2[])
{
    int size1 = strlen(str1); // length of str1
    int size2 = strlen(str2); // length of str2

    for (int i = 0; i < size2 - size1+ 1; i++)
    {
        if (strncmp(str1, str2 + i, size1) == 0) return 1;
    }
    return 0; 
}


int similar (char s[], char t[] , int n)
{
    int i, j;
    int lens = strlen(s); 
    int lent = strlen(t); 
    if (lens < lent || lent + n < lens) return 0; 
    for (i = 0, j = 0; i < lens && j < lent;i++)
    {
        if (s[i] == t[j]) 
        {
            j++; 
        }

    }
      
    return j == lent; 
}

int getline1(char s[])
{
    int counter = 0,ch = 0;
    for (counter = 0; counter < LINE - 1 && ch != '\n' && ch!='\r'; ++counter){
        if((ch = getchar()) != EOF)
            if(ch != '\r')
                s[counter] = ch;
            else
                s[counter] = '\n';
        else
            return 0;
    }

    if (counter==0) 
    {
        return 1;
    }
    s[counter] = '\0';
    return counter;
}


void print_lines(char *str)
{
    char line[LINE]; 
    while (getline1(line) > 0)
    {
        if (subs(str, line)){
            printf("%s", line); 
        }
    }
}

void print_similar_words(char *str) {
    char word[WORD]; 
    while (getword(word) > 0) { 
        if (similar(word, str, 1)) {  
            printf("%s\n", word);  
        }   
    }
}

int getword(char w[])
{
    int ch, counter; // c is the current character, counter is the number of characters in the word

    for (counter = 0; counter < WORD - 1 && (ch = getchar()) != EOF && ch != ' ' && ch != '\t' && ch != '\n'; ++counter)
        w[counter] = ch;
    
    if (ch == '\n' && counter==0) 
        w[counter++] = ch;

    w[counter] = '\0'; 
    return counter;
}

int main()
{

    char word[WORD];
    char u,b;
    scanf("%s %c%c",word,&u,&b);
    if (u == 'a')
    {
        print_lines(word);
    }

    else if (u== 'b')
    {
        print_similar_words(word);
    }    
    return 0;
   
   
}