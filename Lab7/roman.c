#include <stdio.h>

void roman2arabic(char input[],char output[])
{
    int count = 0, res = 0;
    char *in_ptr, *out;
    in_ptr = &input[0];
    out = &output[0];
    for (;*in_ptr != '\0'; in_ptr++){
        count++;
    }
    in_ptr = &input[0];
    for (int i = 0; i < count; i++){
        if (*in_ptr == 'I' && *(in_ptr + 1) == 'I' && *(in_ptr + 2) == 'I'){
            *out = '3';
            in_ptr += 2;
        }
        else if(*in_ptr == 'I' && *(in_ptr + 1) == 'I'){
            *out = '2';
            in_ptr += 1;
        }
        else if (*in_ptr == 'I' && *(in_ptr + 1) == 'V'){
            *out = '4';
            in_ptr += 1;
        }
        else if(*in_ptr == 'I' && *(in_ptr + 1) == 'X'){
            *out = '9';
            in_ptr += 1;
        }
        else if(*in_ptr == 'I'){
            *out = '1';
        }
        else if (*in_ptr == 'V' && *(in_ptr + 1) == 'I' && *(in_ptr + 2) == 'I' && *(in_ptr + 3) == 'I'){
            *out = '8';
            in_ptr += 3;
        }
        else if (*in_ptr == 'V' && *(in_ptr + 1) == 'I' && *(in_ptr + 2) == 'I'){
            *out = '7';
            in_ptr += 2;
        }
        else if (*in_ptr == 'V' && *(in_ptr + 1) == 'I'){
            *out = '6';
            in_ptr += 1;
        }
        else if (*in_ptr == 'V'){
            *out = '5';
        }
        else{
            *out = *in_ptr;
        }
        out++;
        in_ptr++;
    }
}



int main()
{  char input[80],output[80];

   printf(" Input: ");
   fgets(input, 80, stdin);
   char *ch = input;
   while (*ch++ != '\n' || (*(--ch) = 0));

   roman2arabic(input,output);
   printf("Output: %s\n",output);

   return 0;
}