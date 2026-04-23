#include <stdio.h>
#include <math.h>

typedef struct coord {
    double x;
    double y;
}coords;

int main () {
    int n = 0;
    printf("Number of Points: ");
    scanf("%d", &n);
    coords points[n];
    int i,j;
    for (i = 1; i <= n; i++) {
        printf("P%d.X: ", i);
        scanf("\n%lf", &points[i - 1].x);
        printf("P%d.Y: ", i);
        scanf("\n%lf", &points[i - 1].y);
    }
    printf("Length:\n");
    for(j = 0;j < n; j++) {
        if(j != n - 1){
            printf("Length from P%d(%.2lf, %.2lf) to P%d(%.2lf, %.2lf) is ", j + 1,points[j].x, points[j].y, j+2, points[j+1].x, points[j+1].y);
            printf("%.2lf\n",sqrtf(powf(points[j].x - points[j+1].x, 2) + powf(points[j].y - points[j+1].y, 2)));

        }
    }
}