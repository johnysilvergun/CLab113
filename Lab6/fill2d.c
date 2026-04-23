#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows or columns: ");
    scanf("%d",&n);
    int **a = (int*)malloc(n * sizeof(int));
    for(i = 1; i <= n; i++) {
        a[i] = i;
    }

    // Assign value to array a
    

    // Print all values in array a
    for( ) {
        for()
            printf("", a);
        printf("\n");
    }
    return 0;
}