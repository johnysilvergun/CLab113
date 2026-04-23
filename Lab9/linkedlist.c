// โปรแกรมเพื่อสร้างลิสต์อย่างง่ายใช้เองโดยไม่ใช้ array 
// แต่ละ element ในลิสต์จะเป็น node (struct) ที่มีตัวแปร value (int) เป็นค่าที่เก็บไว้ใน node และตัวแปร next ซึ่งจะชี้ไปยัง node ต่อไป
// ค่า next ของ node สุดท้ายจะเป็น NULL ราสามารถเรียกใช้ลิสต์ผ่าน pointer ซึ่งชี้ไปยังโหนดแรกของลิสต์นั้น
// ฟังก์ชันที่ใช้กับลิสต์มีสองฟังก์ชันคือ insertNode() 
// insertNode() ซึ่งจะเพิ่ม node เข้าไปในลิสต์ โดยจะรับค่าที่จะเพิ่มและ pointer ซึ่งชี้ไปที่โหนดแรกของลิสต์
// แล้วจะทำการสร้างโหนดใหม่ที่เก็บค่านั้นและเพิ่มเข้าไปในลิสต์
// การเพิ่มโหนดนั้นจะเรียงลำดับค่าของโหนดจากน้อยไปมากให้ด้วย (ดังนั้นลิสต์จะเรียงลำดับค่าอยู่เสมอ)
//  ฟังก์ชันที่สองคือ printList() ซึ่งจะพิมพ์ค่าของโหนดในลิสต์ออกมาทีละค่าโดยเว้นช่องว่างระหว่างค่าและขึ้นบรรทัดใหม่เมื่อพิมพ์ค่าสุดท้าย
// การเพิ่มโหนดนั้นอาจเพิ่มได้ทั้งท้ายลิสต์ หน้าลิสต์ และระหว่างกลาง
// กรณีพิเศษคือเมื่อลิสต์ยังว่างอยู่ตอนใส่โหนดครั้งแรก
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
}node;

void printList(node *pList) {
    node *current = pList;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

}

void insertNode(node **pList,int value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    if (*pList == NULL || (*pList)->value >= value) {
        newNode->next = *pList;
        *pList = newNode;
    } else {
        node *current = *pList;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


int main() {
  int i, value;
  node *pList=NULL;

  for (i = 0; i < 10; i++) {
    scanf(" %d", &value);
    insertNode(&pList, value);
    
  }

  printList(pList);
}