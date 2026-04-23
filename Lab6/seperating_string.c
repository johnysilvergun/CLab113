#include <stdio.h>
#include <stdlib.h>

void str_extract(char** source, char** vowel);

int main() {
    char* str = malloc(201);
    scanf("%[^\n]s", str);
    char* vowel = NULL;

    str_extract(&str, &vowel);

    printf("Consonants: \"%s\"\n", str);
    printf("    Vowels: \"%s\"\n", vowel);

    free(str);
    free(vowel);
    return 0;
}
void str_extract(char** source, char** vowel) {
    char *src = *source;
    *vowel = (char *)malloc(201 * sizeof(char));
    char *vptr = *vowel; 
    char *cptr = *source; 
    
    while (*src != '\0') {
        if (*src == 'a' || *src == 'e' || *src == 'i' || *src == 'o' || *src == 'u' ||
            *src == 'A' || *src == 'E' || *src == 'I' || *src == 'O' || *src == 'U') {
            
            *vptr = *src;
            vptr++;
        } else {
            *cptr = *src;
            cptr++;
        }
        src++;
    }


    *cptr = '\0';
    *vptr = '\0';
}