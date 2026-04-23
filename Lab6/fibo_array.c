// เขียนฟังก์ชัน unsigned long *fibo_array(unsigned int n, double *golden_ratio); 
// ที่คืนค่า array ของเลขฟิโบนัชชีจำนวน n ตัวแรก และคำนวณอัตราส่วนทองคำของเลขฟิโบนัชชีใน array เก็บไว้ที่ pointer golden_ratio
// เลขฟิโบนัชชี หาได้จาก ผลรวมของตัวเลข 2 ตัวก่อนหน้า หรือ F[i] = F[i - 1] + F[i - 2] เมื่อ F[0] = 0 และ F[1] = 1
// อัตราส่วนทองคำ หาได้จาก อัตราส่วนของเลขฟิโบนัชชีลำดับที่ n + 1 ต่อเลขฟิโบนัชชีลำดับที่ n
// ตัวอย่าง array ของเลขฟิโบนัชชี 10 ตัวแรก คือ {0, 1, 1, 2, 3, 5, 8, 13, 21, 34} ซึ่งมีอัตราส่วนทองคำ คือ F[11] / F[10] = 89 / 55

#include <stdio.h>
#include <stdlib.h>

unsigned long *fibo_array(unsigned int n, double *golden_ratio);

int main() {
    int narr = 10;
    double a = 0;
    double *gold = &a;
    unsigned long *my_arr = fibo_array(narr,gold);
    for (int x = 0 ; x < narr; x++) {
        printf("%d ",my_arr[x]);
    }
    printf("\ngolden ration is : %lf",*gold);
    return 0;
}

// ส่งเฉพาะ implementation ของฟังก์ชัน unsigned long *fibo_array(unsigned int n, double *golden_ratio);
unsigned long *fibo_array(unsigned int n, double *golden_ratio) {
    unsigned long *fib_arr;
    fib_arr = malloc(n+1 * sizeof(*fib_arr));
    // if (fib_arr == NULL) {
    //     printf("failed to allocate memory");
    // }
    fib_arr[0] = 0;
    fib_arr[1] = 1;

    int prev = 0;
    int cur = 1;
    for (int i = 2; i <= n+1; i++) {
        int next = prev + cur;
        prev = cur;
        cur = next;
        fib_arr[i] = cur;
    }
    // printf("in function test : \n");
    // for (int j = 0; j <= n+1; j++) {
    //     printf("%d ",fib_arr[j]);
    // }
    // printf("\n");
    // printf("in function test ended \n");
    *golden_ratio = (double)fib_arr[n+1] / (double)fib_arr[n];
    return fib_arr;

}