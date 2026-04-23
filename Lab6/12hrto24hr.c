#include <stdio.h>
#include <stdlib.h>

int main(){
    int hr,min;
    char ampm;
    printf("Enter a 12-hour time [eg. 12:34 am]: ");
    scanf("%d:%d %c",&hr,&min,&ampm);

    if(ampm =='a' || ampm =='A'){
        if(hr == 12) {
            hr = 0;
        }
    }
    else if(ampm =='p' || ampm =='P'){
        if(hr != 12){
            hr += 12;
        }
    }
    
    printf("Equivalent 24-hour time: %02d:%02d",hr,min);

}