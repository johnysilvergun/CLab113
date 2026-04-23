#include <stdio.h>
#include <stdlib.h>



int charcount(char *s)
{
    int c = 0;
    for (c = 0 ; *s != '\0';s++) {
        c++;
    }
    return c;
   
}

void charweave(char *s,char *result)
{
    int len = charcount(s);
    char *start ;
    start = &s[0];
    char *end ;
    end = &result[0];
    for (;*start != '\0';start++) {
        *(end) = *(start);
        end += 2;
    }
    end = &result[1];
    start--;
    for (int i =0 ; i < len; i++) {
        *(end) = *(start);
        end += 2;
        start--;
        
    }
    *(result + (len * 2)) = '\0';

}

int main()
{  char str[100],result[200];

   printf("String: ");
   fgets(str, 100, stdin);
   char *ch = str;
   while (*ch++ != '\n' || (*(--ch) = 0));
   charweave(str,result);
   printf("Output: %s\n",result);
   return 0;
}