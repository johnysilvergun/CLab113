#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE    8

void setPieceOnTable(int board[][BOARD_SIZE], char piece, int xPos, int yPos);
int main(){
    int numPieces,j,i,x_pos,y_pos;
    char piece;
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    scanf("%d",&numPieces);

    for (i = 0;i < numPieces; i++){
        scanf("\n%c(%d, %d)",&piece,&x_pos,&y_pos);
        setPieceOnTable(board, piece, x_pos, y_pos);
    }
    
    printf("------------------\n");
    printf("  0 1 2 3 4 5 6 7\n");

    for (i = 0; i < BOARD_SIZE; i++){
        printf("%d|",i);
        for (int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] == 0){
                printf(" |");
            }
            else{
                printf("%c|", board[i][j]);
            }
        }
        printf("\n");
    }
}

void setPieceOnTable(int board[][BOARD_SIZE], char piece, int xPos, int yPos){
    board[yPos][xPos] = piece;
}