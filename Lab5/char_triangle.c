// รับจํานวนเต็มบวกมาหนึ่งจํานวน และพิมพ์สามเหลี่ยมตามขนาดที่ผู้ใช้กําหนดดังตัวอย่างด้านล่าง
// ตัวอย่าง Input/Output 1

// Enter n: 1
// -

// ตัวอย่าง Input/Output 2

// Enter n: 2
// -
// -x
// - 

// ตัวอย่าง Input/Output 3

// Enter n: 10
// -
// -x
// -x-
// -x-x
// -x-x-
// -x-x-x
// -x-x-x-
// -x-x-x-x
// -x-x-x-x-
// -x-x-x-x-x
// -x-x-x-x-
// -x-x-x-x
// -x-x-x-
// -x-x-x
// -x-x-
// -x-x
// -x-
// -x
// -

// ตัวอย่าง Input/Output 4

// Enter n: 11
// -
// -x
// -x-
// -x-x
// -x-x-
// -x-x-x
// -x-x-x-
// -x-x-x-x
// -x-x-x-x-
// -x-x-x-x-x
// -x-x-x-x-x-
// -x-x-x-x-x
// -x-x-x-x-
// -x-x-x-x
// -x-x-x-
// -x-x-x
// -x-x-
// -x-x
// -x-
// -x
// -

#include <stdio.h>
#include <stdlib.h>

int main(){
    char high[10];
    printf("Enter n: ");
    fgets(high,10,stdin);
    int h = atoi(high);
    int i,j,k;

    for(i = 1; i<=h; ++i){
        for(j = 1; j<=i ; ++j){
            if(j % 2 == 0 ){
                printf("x");
            }
            else {
                printf("-");
            }
        }
        printf("\n");
    }
    for (i = h - 1; i >0; --i){
        for (k = 1 ; k <= i; ++k){
            if(k % 2 == 0 ){
                printf("x");
            }
            else {
                printf("-");
            }
        }
        if(i != 1) {
            printf("\n");
        }
    }
    return 0;
}