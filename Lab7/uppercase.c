#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char *stoupper (const char s[]){
    char *string_ptr = (char *)malloc(100 * sizeof(char));
    int i = 0;
    while(s[i] != '\0') {
        string_ptr[i] = toupper(s[i]);
        i++;
    }
    return string_ptr;
}

int main(){
	char s[100];
	char* result;

	scanf("%s",s);
	result = stoupper(s);
        if (result == s) printf("ERROR.\n");
	printf("%s\n",result);
}