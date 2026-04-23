// จำลองการไต่ขั้นบันได โดยเริ่มแรก โปรแกรมจะถามจำนวนขั้นบันได (บรรทัดที 1)
// จากนั้น ในแต่ละรอบ โปรแกรมจะแสดงตำแหน่งปัจจุบันของคนบนขั้นบันได และโปรแกรมจะถาม step command

// step command สำหรับโปรแกรมนี้ คือ

//     ถ้าเป็นจำนวนเต็มบวก x หมายถึง ให้ไต่บันไดขึ้นไป x ขั้น
//     ถ้าเป็นจำนวนเต็มลบ -x หมายถึง ให้ไต่บันไดลงมา x ขั้น
//     ถ้าเป็นจำนวนเต็มศูนย์ หมายถึง จบโปรแกรม

// เงื่อนไขเพิ่มเติมของโปรแกรมนี้ คือ

//     คน ประกอบด้วย 2 ส่วน คือ ส่วนหัว (O) และส่วนขา (^)
//     รอบที่หนึ่ง ขาของคนจะอยู่ที่ขั้นบันไดล่างสุด
//     ขาของคนจะไม่อยู่ต่ำกว่าบันไดขั้นล่างสุด และหัวของคนจะไม่อยู่สูงกว่าบันไดขั้นบนสุด

// Sample Output 1

// Input number of stairs: 4
// ---- round 1 ----
// |---|
// |---|
// |-O-|
// |-^-|
// Input step command: 1
// ---- round 2 ----
// |---|
// |-O-|
// |-^-|
// |---|
// Input step command: 0

// Sample Output 2

// Input number of stairs: 4
// ---- round 1 ----
// |---|
// |---|
// |-O-|
// |-^-|
// Input step command: 2
// ---- round 2 ----
// |-O-|
// |-^-|
// |---|
// |---|
// Input step command: 2
// ---- round 3 ----
// |-O-|
// |-^-|
// |---|
// |---|
// Input step command: 0


#include <stdio.h>
#include <stdlib.h>

int main() {
    char in_stair[10];
    printf("Input number of stairs: ");
    fgets(in_stair,10,stdin);

    int stairs = atoi(in_stair);
    int head_pos = stairs - 1;
    int foot_pos = stairs;
    int round = 1;
    int steps_num = stairs;
    int i,j,k;

    while (1) {
        printf("---- round %d ----\n",round++);

        for (i = 1; i <= stairs; i++) {
            if (i == head_pos) {
                printf("|-O-|\n");
            }
            else if (i == foot_pos) {
                printf("|-^-|\n");
            }
            else {
                printf("|---|\n");
            }
        }
        //step control
    
        char in_steps[10];
        printf("Input step command: ");
        fgets(in_steps,10,stdin);
        int step = atoi(in_steps);

        if (step == 0) {
            break;
        }
        head_pos -= step;
        foot_pos -= step;
        if (head_pos < 1) {
            head_pos = 1;
            foot_pos = 2;
        }
        else if (foot_pos > stairs) {
            head_pos = stairs - 1;
            foot_pos = stairs;
        }
    }

    return 0;
}