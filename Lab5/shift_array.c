// มีหน้าที่เลื่อนตัวอักษรใน array ของตัวอักษร (str) ไปทางซ้ายตามจำนวนครั้งที่กำหนด (n) 
// หากเลื่อนไปจนสุด array แล้วตัวอักษรที่หลุดออกจากซ้ายสุดจะถูกนำกลับมาต่อที่ด้านขวาสุด (ลักษณะการหมุนแบบวงกลม)



// String: Computer Programming
//      n: 4
// Output: >>uter ProgrammingComp<<

#include <stdio.h>
#include <stdlib.h>

void shift_left(char str[], int n);

int main()
{
   char str[80], *c;
   char input[20];
   int n;

   printf("String: ");
   fgets(str, sizeof(str), stdin);
   for (c=str; *c && *c != '\n'; c++)
       ;
   *c = 0;
   printf("     n: ");
   fgets(input, 20, stdin);
   n = atoi(input);
   shift_left(str, n);
   printf("Output: >>%s<<\n",str);
   return 0;
}
void shift_left(char str[], int n) {

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    if (len <= 1 || n <= 0) {
        return;
    } 
    n = n % len; 
    if (n == 0) {
        return;
    } 


    for (int i = 0, j = n - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    for (int i = n, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }


    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
