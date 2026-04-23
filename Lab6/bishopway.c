#include <stdio.h>
#define BOARD_SIZE 8

void bishopMoves(int xPos, int yPos) {
    int sum = xPos + yPos, i, j, neg = xPos - yPos;
    for (i = 0; i < BOARD_SIZE; i++){
        printf("%d|",i);
        for (int j = 0; j < BOARD_SIZE; j++){
            if (j != sum && j != neg){
                printf(" |");
            }
            else{
                if (i == yPos && j == xPos){
                    printf("B|");
                }
                else{
                    printf("X|");
                }
            }
        }
        sum -= 1;
        neg += 1;
        printf("\n");
        printf("------------------\n");
    }
}

int main() {
    int start_posx, start_posy;
    printf("Enter Bishop's X Y position: ");
    scanf("%d %d", &start_posx, &start_posy);
    printf("  0 1 2 3 4 5 6 7\n");
    printf("------------------\n");
    bishopMoves(start_posx,start_posy);
}