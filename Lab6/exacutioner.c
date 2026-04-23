
// เลือกนักโทษมา numPrisoners คน
// แต่ละคนมีหมายเลข 1 ถึง numPrisoners
// รับเลข m ซึ่งมีค่าตั้งแต่ 2 ถึง 5
// การประหารชีวิตนักโทษ เยียงเข้าแถวเป็นวงกลม
// เริ่มจากคนที่ได้รับหมายเลข 1 ไล่ไปจนถึง numPrisoners
// ให้นับเลข 1, 2, ..., m ไปตามลำดับ หากใครนับเลขตรงกับเลข m จะถูกนำตัวไปประหารทันที
// EX :
// 10
// 3
// 3 6 9 2 7 1 8 5 10 4
// เริ่มนับจาก 1 ถึง 3
// จากนั้นนับจาก 3 ถึง 6
// จาก 6 ถึง 9
// แล้วย้อนกลับมานับจาก 9 ถึง 1 2 ไม่ต้องนับ 3 เพราะ 3 หายไปแล้ว
// จากนั้นนับจาก 2 ถึง 4 5 7
// จากนั้นนับจาก 7 และต่อไปเรื่อยๆ

#include <stdio.h>

void removeKilled(int *array, int size, int killedPrisoner);

int main()
{
	int numPrisoners, m, i;

	scanf("%d", &numPrisoners);
	scanf("%d", &m);

	int prisoners[numPrisoners];
	int killed[numPrisoners];

	// generate array 1 to numPrisoners
	for (i = 0; i < numPrisoners; i++) {
		prisoners[i] = i + 1;
	}

	int *killerPtr = &prisoners[0];

	// printf("@@ &prisoners[0] %d\n", (int) &prisoners[0]);
	// printf("@@ &prisoners[%d] %d\n", numPrisoners - 1, (int) &prisoners[numPrisoners - 1]);

	// Select prisoner to be killed
	for (i = 0; i < numPrisoners; i++) {
        for (int j = 0; j < m-1; j++) {
            int MOVED = 0;
            if (*killerPtr != prisoners[numPrisoners - (i+1) ] && *killerPtr != 0) {
                *killerPtr++;
            }
            else {
                if (*killerPtr == 0){
                    MOVED++;
                }
                if (killerPtr == &prisoners[1] && MOVED == 1) {
                    MOVED--;
                }
            killerPtr = &prisoners[0+MOVED];
            }
            
        }

		killed[i] = *killerPtr;
		removeKilled(&prisoners[0], numPrisoners, *killerPtr);

	}

	for (i = 0; i < numPrisoners; i++) {
		printf("%d ", killed[i]);
	}
	return 0;
}

void removeKilled(int *array, int size, int killedPrisoner)
{
    int *last = array + size - 1;
    int *start = array;
    for (int i = 0; i < size; i++ , array++){
        if(*array == killedPrisoner){
			for(int j = i; j < size; j++, array++){
				*array = *(array+1);
			}
			break;
        }
    }
    *last = 0;    
}