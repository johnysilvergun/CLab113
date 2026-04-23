// ร้านขายเสื้อผ้าขนาดใหญ่ เขียนโปรแกรมจัดการระบบขายเสื้อ
// โปรแกรมขจะเก็บบันทึกการขายเสื้อผ้าแยกไว้เป็นวันละไฟล์
// รูปแบบของข้อมูลในไฟล์บันทึกการขายเสื้อผ้าของโปรแกรมเป็นดังนี้
// 	บรรทัดที่ 1 เป็นจำนวนประเภทของเสื้อผ้าที่ขายได้ในวันนั้น
// 	บรรทัดที่ 2 เป็นต้นไป เป็นรายละเอียดของเวลาที่ขายเสื้อผ้า ประเภทเสื้อผ้าที่ขาย จำนวนที่ขาย และราคาที่ขาย 
// 	มีรูปแบบคือ ปีเดือนวัน,เวลา,ชื่อประเภทเสื้อผ้า,จำนวนที่ขาย,ราคาขาย
// ข้อมูลในไฟล์ stock-log-20170401.txt

// 4
// 20170401,12:54:00,T Shirt L,1,120.00
// 20170401,12:56:32,Boxer,2,90.00
// 20170401,13:12:34,T Shirt L,2,200.00
// 20170401,13:12:34,Boxer,2,98.00
// 20170401,14:29:17,T Shirt M,4,480.00
// 20170401,16:39:27,Shorts M,1,120.50
// 20170401,17:12:34,T Shirt L,3,350.00

// ตามิต้องการเขียนโปรแกรม เพื่อสรุปข้อมูลให้ได้ดังนี้

//     Product Name    |Amount|     Total
// T Shirt L           |     6|    670.00
// Boxer               |     4|    188.00
// T Shirt M           |     4|    480.00
// Shorts M            |     1|    120.50


// ผลลัพธ์เรียงลำดับประเภทสินค้าจากประเภทสินค้าแรกที่ปรากฏในไฟล์



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _product {
    char name[30];
    int amount;
    double totalCost;
} Product;

void printStock(Product stock[], int nStock)
{
    int i;
    printf("%-20s|%6s|%-10s\n", "    Product Name", "Amount", "     Total");
    for (i = 0; i < nStock; i++) {
        printf("%-20s|%6d|%10.2lf\n",
            stock[i].name, stock[i].amount, stock[i].totalCost);
    }
}

void reportStock(char *filename) {
    FILE *file;
    char line[100];
    char productName[100];
    Product stock[100] = {0};
    int num_product = 0;
    file = fopen(filename,"r");
    int total_product = 0;
    int count = 0;
    int index = 0;
    int i,j,k = 0;
    float price = 0;
    fgets(line, 100, file);
    int num_prod_present = atoi(line);
    while (fgets(line, 100, file) != NULL) {
        char *token = strtok(line,",");
        token = strtok(NULL,",");
        token = strtok(NULL,",");
        strcpy(productName,token);
        token = strtok(NULL,",");
        total_product = atoi(token);
        token = strtok(NULL,",");
        price = atof(token);
        if (count == 0) {
            strcpy(stock[index].name, productName);
            stock[index].amount = total_product;
            stock[index].totalCost = price;
            count++;
        }
        else {
            for (i = 0; i < count; i++) {
                if (strcmp(stock[i].name, productName) == 0) {
                    stock[i].amount += total_product;
                    stock[i].totalCost += price;
                    break;
                }
            }
            if (i == count) {
                strcpy(stock[count].name, productName);
                stock[count].amount = total_product;
                stock[count].totalCost = price;
                count++;
            }
        }
    }
    printStock(stock, num_prod_present);
}

int main()
{
    char filename[20];
    scanf("%s", filename);
    reportStock(filename);
}