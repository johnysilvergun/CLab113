// หาค่าสูงสุด โดยให้นิยาม data type ใหม่ เป็นประเภท struct
// สร้าง array ของ struct ขึ้นมาโดยมีขนาด 5 elements
// รับข้อมูลเข้า  โดยจะมีข้อมูล ID student คะแนนสอบมิดเทอม และ ไฟนอล
// รับครบ ให้เรียกฟังก์ชัน findTop ซึ่งจะหา record ที่มีคะแนนมิดเทอมสูงสุด และ record ที่มีคะแนนไฟนอลสูงสุด
// จากนั้นให้พิมพ์ ID และคะแนนของนิสิตที่ได้คะแนนสูงสุดทั้งสอง
// ex : 
// Enter Student ID: 501456784
// Enter Student Midterm: 26
// Enter Student Final: 37
// Enter Student ID: 501769821
// Enter Student Midterm: 40
// Enter Student Final: 37
// Enter Student ID: 501567893
// Enter Student Midterm: 10
// Enter Student Final: 6
// Enter Student ID: 501875947
// Enter Student Midterm: 26
// Enter Student Final: 35
// Enter Student ID: 519838273
// Enter Student Midterm: 30
// Enter Student Final: 25
// Top Score for Midterm:
// Student ID 501769821 with score 40
// Top Score for Final:
// Student ID 501456784 with score 37


#include <stdio.h>

#define ARRAY_SIZE 5
typedef struct Student{
  char id[12];
  int midterm;
  int final;
  char grade;
}StudentRecord;

void findTop(StudentRecord pRec[], int size, StudentRecord **topMid, StudentRecord **topFin) {
    if (pRec == NULL || topMid == NULL || topFin == NULL || size <= 0) {
        return; 
    }
    int x;
    *topMid = &pRec[0];
    *topFin = &pRec[0];

    for (x = 1; x < size; x++) {
        if (pRec[x].midterm > (*topMid)->midterm) {
            *topMid = &pRec[x];
        }
        if (pRec[x].final > (*topFin)->final) {
            *topFin = &pRec[x];
        }
    }
}

int main() {

  StudentRecord students[ARRAY_SIZE], *pTopMid, *pTopFin;
  int gradeCount[5] = {0};
  int i;

  for (i=0; i <  ARRAY_SIZE; i++) {
    printf("Enter Student ID: ");
    scanf("%s", students[i].id);
    printf("Enter Student Midterm: ");
    scanf("%d", &students[i].midterm);
    printf("Enter Student Final: ");
    scanf("%d", &students[i].final);

  }

  findTop(students,ARRAY_SIZE,&pTopMid,&pTopFin);

  //print grade
  printf("Top Score for Midterm:\n");
  printf("Student ID %s with score %d\n",pTopMid->id, pTopMid->midterm);
  printf("Top Score for Final:\n");
  printf("Student ID %s with score %d\n",pTopFin->id, pTopFin->final);


  return 0;
}
