#include <stdio.h>

struct complex {
    float a;
    float b;
};

struct complex add_complex (struct complex C, struct complex D)
{
    struct complex result;
    result.a = C.a + D.a;
    result.b = C.b + D.b;
    return result;
};

struct complex multiply_complex(struct complex C, struct complex D)
{
    struct complex result;
    result.a = C.a * D.a - C.b * D.b;
    result.b = C.a * D.b + C.b * D.a;
    return result;
};

void print_complex(char str[], struct complex result)
{
    // printf("%s", str);
    // if (result.a > 0 && result.b > 0){
    //     printf("%.1f + %.1fi\n", result.a, result.b);
    // }
    // else if (result.a < 0 && result.b > 0){
    //     printf("%.1f + %.1fi\n", result.a, result.b);
    // }
    // else if (result.a == 0 && result.b > 0){
    //     printf("%.1fi\n",result.b);
    // }
    // else if (result.a < 0 && result.b == 0){
    //     printf("%.1f\n",result.a);
    // }
    // else if (result.a > 0 && result.b < 0){
    //     printf("%.1f - %.1fi\n", result.a, result.b * (-1.0));
    // }
    // else if (result.a == 0 && result.b == 0){
    //     printf("0.0\n");
    // }
    // else if (result.a < 0 && result.b < 0){
    //     printf("%.1f - %.1fi\n", result.a, result.b * (-1.0));
    // }
    printf("%s", str);
    // Case 1: Both are zero
    if (result.a == 0 && result.b == 0) {
        printf("0.0\n");
    } 
    // Case 2: Purely imaginary
    else if (result.a == 0) {
        printf("%.1fi\n", result.b);
    } 
    // Case 3: Purely real
    else if (result.b == 0) {
        printf("%.1f\n", result.a);
    } 
    // Case 4: Combined number
    else {
        // Use %+.1f to automatically include the + or - sign for the imaginary part
        printf("%.1f + %.1fi\n", result.a, result.b);
    }
};

int main()
{
    struct complex C,D,E,F;
    printf("Enter C: ");
    scanf("%f %f", &C.a, &C.b);
    printf("Enter D: ");
    scanf("%f %f", &D.a, &D.b);    

    E = add_complex(C, D);
    F = multiply_complex(C, D);

    print_complex("C + D = ", E);
    print_complex("C x D = ", F);

    return 0;
}