// โปรแกรมที่ใช้ในการเก็บชื่อของสินค้าความยาวไม่เกิน 20 อักขระ 
// โปรแกรมสามารถเก็บข้อมูลสินค้า โดยใช้โครงสร้างข้อมูลแบบ Linkedlist
// ผู้ใช้งานสามารถพิมพ์รายชื่อสินค้าได้โดยไม่จำกัดจำนวน
// ให้พิมพ์คำสั่ง done เพื่อทำการจบการทำงานของโปรแกรม
// ฟังก์ชัน print_all_goods() จะทำการพิมพ์ข้อมูลสินค้าทั้งหมดที่เก็บอยู่ใน Linkedlist
// ฟังก์ชัน print_all_goods() return ค่าออกมาเป็นจำนวนรายชื่อสินค้าทั้งหมดใน Linkedlist

// ตัวอย่าง 1
// Name: Good1
// Name: Good2
// Name: done
// Good1
// Good2
// Total = 2

// ตัวอย่าง 2
// Name: Lay
// Name: Pepsi
// Name: Fanta
// Name: Taro
// Name: Pocky
// Name: done
// Lay
// Pepsi
// Fanta
// Taro
// Pocky
// Total = 5


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct good {
        char name[20];
        struct good *next;
}Good;

Good *start = NULL;

void add_good(Good *new_good){
        Good *current_good = start;
        Good *previous_good = NULL;
        while(current_good){
                previous_good = current_good;
                current_good = current_good->next;
        }
        if(previous_good != NULL){
                previous_good->next = new_good;
        }else{
                start = new_good;
        }
}
int print_all_goods(){
    Good *current_good = start;
    int c = 0;
    while(current_good) {
        printf("%s\n", current_good->name);
        current_good = current_good->next;
        c++;
    }
    return c;
        
}
int main(){
        char name[20];
        int price;
        Good *new_node;
        printf("Name: ");
        scanf("%20s",name);

        while(strcmp(name,"done")){
                new_node = (Good *)malloc(sizeof(Good));
                strcpy(new_node->name,name);
                new_node->next = NULL;
                add_good(new_node);

                printf("Name: ");
                scanf("%20s",name);
        }

        printf("total = %d\n",print_all_goods());
}