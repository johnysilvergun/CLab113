#include <stdio.h>
#include <string.h>

typedef struct{
    char id[11];
    int midterm;
    int final;
    int total;
} studentRecord;

void ScoreCal (studentRecord list[], int size) {
    int i;
    for (i = 0; i < 5; i++) {
        list[i].total = list[i].midterm + list[i].final;
    }
}

void GradeCal (studentRecord list[], int size) {
    int i;
    for (i = 0; i < 5; i++) {
        if (list[i].total >= 80){
            printf("Student ID %s receives grade A.\n", list[i].id);
        }
        else if (list[i].total >= 70 && list[i].total <= 79){
            printf("Student ID %s receives grade B.\n", list[i].id);
        }
        else if (list[i].total >= 60 && list[i].total <= 69){
            printf("Student ID %s receives grade C.\n", list[i].id);
        }
        else if (list[i].total >= 50 && list[i].total <= 59){
            printf("Student ID %s receives grade D.\n", list[i].id);
        }
        else if (list[i].total < 50){
            printf("Student ID %s receives grade F.\n", list[i].id);
        }
    }    
}

int main() {
    studentRecord list[5];
    char id[11];
    int mid_score;
    int final_score;
    int i;
    for (i = 0; i < 5; i++) {
        printf("Enter Student ID: ");
        scanf("%s", id);
        printf("Enter Student Midterm: ");
        scanf("%d", &mid_score);
        printf("Enter Student Final: ");
        scanf("%d", &final_score);
        sprintf(list[i].id, "%s", id);
        list[i].midterm = mid_score;
        list[i].final = final_score;
    }
    ScoreCal(list,5);
    GradeCal(list,5);
    return 0;

}