// โครงสร้างข้อมูลแบบ linked list สำหรับข้อมูลประเภทจำนวนเต็ม
// ข้อมูลใน linked list ต้องเรียงลำดับจากน้อยไปมาก
// ฟังก์ชั่นในการจัดการ 3 ฟังก์ชั่น คือ
// insert รับค่าเป็นจำนวนเต็มหนึ่งตัวเพื่อเพิ่มเข้าไปใน linked list
// delete รับค่าเป็นจำนวนเต็มหนึ่งตัวเพื่อลบข้อมูลทุกตัวที่มีค่าเท่ากับจำนวนเต็มนั้น
// print แสดงข้อมูลทั้งหมดใน linked list (แสดงออกทาง stdout หนึ่งบรรทัด)

// โปรแกรมจะรับคำสั่งผ่านทาง stdin โดยคำสั่งมีทั้งหมด 4 คำสั่งคือ

//     i k เป็นคำสั่ง insert: เพิ่มข้อมูล k เข้าไปใน linked list
//     d k เป็นคำสั่ง delete: ลบข้อมูลที่มีค่าเท่ากับ k ทุกตัวออกจาก linked list
//     p เป็นคำสั่ง print: แสดงข้อมูล
//     q เป็นคำสั่ง quit: จบการทำงาน
// ตัวอย่างข้อมูลส่งออก

// input> p
// [ ]
// input> i 5
// input> i 4
// input> i 1
// input> p
// [ 1 4 5 ]
// input> i 10
// input> i 4
// input> d 4
// input> d 2
// input> i 9
// input> d 5
// input> i 6
// input> p
// [ 1 6 9 10 ] 
// input> q
// หากพบตัวเลขซ้ำ เช่น การแทรกเลข 4 เมื่อมีเลข 4 อยู่แล้ว การแสดงผลจะต้องแสดงเพียงเลข 4 ตัวเดียว และการลบจะต้องลบเลข 4 ออกทั้งหมด



#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;



void insert(Node **start, int k){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = k;
    new_node->next = NULL;

    if(*start == NULL || (*start)->data > k) {
        new_node->next = *start;
        *start = new_node;
        return;
    }

    Node *current = *start;
    while(current->next != NULL && current->next->data < k) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}


void delete(Node **start, int k) {
    Node *current = *start;
    Node *previous = NULL;
    while(current != NULL) {
        if(current->data == k) {
            if(previous == NULL) {
                *start = current->next;
            } 
            else {
                previous->next = current->next;
            }
            Node *temp = current;
            current = current->next;
            free(temp);
        } 
        else {
            previous = current;
            current = current->next;
        }
    }
}

void print(Node *start) {
    printf("[ ");
    while(start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("]\n");
}


int main() {
    Node *start = NULL;
    char command[10];
    int num;
    while(1) {
        printf("input> ");
        scanf("%s", command);
        if(strcmp(command, "i") == 0) {
            scanf("%d",&num);
            insert(&start,num);
        }
        else if(strcmp(command, "d") == 0) {
            scanf("%d",&num);
            delete(&start,num);
        }
        else if (strcmp(command, "p") == 0) {
            print(start);
        }
        else if (strcmp(command, "q") == 0) {
            break;
        }
    }
}