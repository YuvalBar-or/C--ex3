#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define ARRAY_SIZE LINE*250


int substring( char str1[], char str2[])
{
    if(strstr(str1,str2))
    return 1;
    else return 0;
}

void removeChar(char str[], int i){
    int len = strlen(str);
    for(int j=i; j<len; j++)
    { 
        str[j] = str[j+1];
    }
}

int similar (char s[], char t[])
{
    for (size_t i = 0; i < strlen(s); i++)
    {
        if (s[i]!=t[i])
        {
          removeChar(s,i);
          i=strlen(s);
        }
    }
    if(strcmp(s,t)==0)
    return 1;
    else return 0;
}

void print(char text[])
{
    for (size_t i = 0; i < LINE; i++)
    {
        printf("%c",text[i]);
    }
}

int main()
{
    char text[ARRAY_SIZE];
    fgets(text,ARRAY_SIZE,stdin);
    char searchWord[WORD];
    char line[LINE];
    char word[WORD];
    int i=0,j=0;
   
    while (text[i+1] !=' ')
    {
        searchWord[i] = text[i];
        i++;
    }
    i++;
    if (text[i]=='a')
    {
        for (;i < ARRAY_SIZE-LINE;)
        {
            while (text[i]!='\n')
            {
                line[j]=text[i];
                j++;
                i++;
            }
            j=0;
            if(substring(line,searchWord))
            {
                print(line);
            }
        }      
    }
    if (text[i]=='b')
    {
        for (;i < ARRAY_SIZE-LINE;)
        {
            while (text[i]!='\n'||text[i]!='\t'||text[i]!=' ')
            {
                word[j]=text[i];
                j++;
                i++;
            }
            j=0;
            if(similar(word,searchWord))
            {
                print(word);
            }
        }      
    }
    return 0;
}
