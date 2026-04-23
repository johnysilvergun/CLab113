#include <stdio.h>

int main() {
    char word[100];
    int c = 0;
    printf("String (without a space): ");
    scanf("%s",&word);
    for(int i=0; word[i]!=0 ;i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
        {
            printf("%c ",word[i]);
            c++;
        }

    }
    if (c == 0 || c == 1) {
        printf("\nThis string contains %d vowel.",c);
    }
    
    else {
        printf("\nThis string contains %d vowels.",c);
    }
}