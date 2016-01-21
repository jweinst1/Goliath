//
// Created by Joshua Weinstein on 1/20/16.
//

#include "main.h"
#include "stdio.h"

//special functions for changing indices
int increaseindex(int num);
int decreaseindex(int num);
int sumrow(int arr[]);

//matrix machine
//makes a 3 by 3 matrix and takes instructions for it.
int main(void) {
    // Disable stdout buffering
    setvbuf(stdout, NULL, _IONBF, 0);
    int i, j;

    int machine[3][3];
    for(i=0;i<3;i++) for(j=0;j<3;j++) machine[i][j] = 0;

    int row = 0;
    int col = 0;

    char instructions[10000];
    printf("Give the Code:");
    scanf("%s", instructions);
    int r;
    for(r=0;instructions[r]!='\0';r++) {
        switch(instructions[r]) {
            case '>': increaseindex(col);
                break;

            case '<': decreaseindex(col);
                break;

            case '^': decreaseindex(row);
                break;

            case '_': increaseindex(row);
                break;

            case '+': machine[row][col] += 1;
                break;

            case '-': machine[row][col] -= 1;
                break;

            case '#': machine[row][col] = sumrow(machine[row]);

            case '.': printf("%d", machine[row][col]);
                break;

        }
    }
    return 0;
}

//prevents out of bounds on the matrix
int increaseindex(int num) {
    switch(num) {
        case 0: return 1;
            break;

        case 1: return 2;
            break;

        case 2: return 0;
            break;
    }
}

//prevents out of bounds on the matrix
int decreaseindex(int num) {
    switch(num) {
        case 0: return 2;
            break;

        case 1: return 0;
            break;

        case 2: return 1;
            break;
    }
}

//sums a row in the matrix
int sumrow(int arr[]) {
    return arr[0]+arr[1]+arr[2];
}
