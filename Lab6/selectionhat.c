
#include <stdio.h>

void removeTarget(int *array, int size, int target);

int main()
{
	int num, count, target, i;

	scanf("%d", &num);
	scanf("%d", &count);

	int numbers[num];
	int *numbersPtr = &numbers[0];

	// initialize array numbers from 1 to num by numbersPtr
	for (i = 1; i <= num; i++ && numbersPtr++) {
	   *numbersPtr = i;
	}
    for (int j = 0; j < num;j++) {
        printf("%d ",numbers[j]);
    }
    printf("\n");
    
	// loop through count
	for (int k = 0; k < count; k++) {
		scanf("%d", &target);
		removeTarget(&numbers[0], num, target);
	}

	numbersPtr = &numbers[0];

	// print elements in numbers using numberPtr
	for (i = 1; i <= num; i++ && numbersPtr++) {
	       printf("%d ", *numbersPtr);
	}
	puts("");
	return 0;
}

// remove target from array by pointer *array and append last position by 0
// 2 3 4 5 6 7 8 9 0 0 
void removeTarget(int *array, int size, int target) {
    int *readPtr = array;
    int *writePtr = array;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (*readPtr != target) {
            *writePtr = *readPtr;
            writePtr++;
        } 
        else {
            count++; 
        }
        readPtr++;
    }

    while (writePtr < array + size) {
        *writePtr = 0;
        writePtr++;
    }
}