//
// Created by Joshua Weinstein on 1/20/16.
//

#include "main.h"
#include "stdio.h"

//special functions for changing indices
int increaseindex(int num);
int decreaseindex(int num);

//collapses entire rows or cols to a cell
int sumrow(int arr[]);
int mulrow(int arr[]);
int sumcol(int arr[][3], int c);
int mulcol(int arr[][3], int c);

//summing rows and cols
int sumbelow(int arr[][3], int r, int c);

//swapping positions in the machine
void swapbelow(int arr[][3], int r, int c);
void swapright(int arr[][3], int r, int c);

//convert to alpha char and printf
void tochar(int num);

//sum up to some number for setting to cells
int sumints(int end);

//factorial function for cells in the machine
int factorial(int end);

//sum current row down
void sumrowdown(int arr[][3], int r, int c);

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
            case '>': col = increaseindex(col);
                break;

            case '<': col = decreaseindex(col);
                break;

            case '^': row = decreaseindex(row);
                break;

            case '_': row = increaseindex(row);
                break;

            case '+': machine[row][col] += 1;
                break;

            case '-': machine[row][col] -= 1;
                break;

            case '~': machine[row][col] = 0;
                break;

            case '#': machine[row][col] = sumrow(machine[row]);
                break;

            case '*': machine[row][col] = mulrow(machine[row]);
                break;

            case '$': machine[row][col] = sumcol(machine, col);
                break;

            case '&': machine[row][col] = mulcol(machine, col);
                break;

            case '/': machine[row][col] = sumbelow(machine, row, col);
                break;

            case '@': tochar(machine[row][col]);
                break;

            case '?': swapbelow(machine, row, col);
                break;

            case ',': machine[row][col] = sumints(machine[row][col]);
                break;

            case '!': machine[row][col] = factorial(machine[row][col]);
                break;

            case '%': swapright(machine, row, col);
                break;

            case '|': sumrowdown(machine, row, col);
                break;

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

//multiplies the row in a matrix
int mulrow(int arr[]) {
    return arr[0]*arr[1]*arr[2];
}

//sums a column in the matrix
int sumcol(int arr[][3], int c) {
    return arr[0][c]+ arr[1][c] + arr[2][c];
}

//multiplies a column in the matrix
int mulcol(int arr[][3], int c) {
    return arr[0][c]* arr[1][c] * arr[2][c];
}

//sums the cell below the current to the current cell.
int sumbelow(int arr[][3], int r, int c) {
    return arr[r][c] + arr[increaseindex(r)][c];
}

//swaps the cell below the current with the current cell value
void swapbelow(int arr[][3], int r, int c) {
    int temp = arr[r][c];
    int tempother = arr[increaseindex(r)][c];
    arr[r][c] = tempother;
    arr[decreaseindex(r)][c] = temp;
}

//swamps the cell to the right of the current value with the current cell value
void swapright(int arr[][3], int r, int c) {
    int temp = arr[r][c];
    int tempother = arr[r][increaseindex(c)];
    arr[r][c] = tempother;
    arr[r][increaseindex(c)] = temp;
}

int sumints(int end) {
    int total = 0;
    int i;
    for(i=0;i<end;i++) {
        total += i;
    }
    return total;
}

int factorial(int end) {
    int total = 1;
    int i;
    for(i=1;i<end;i++) {
        total *= i;
    }
    return total;
}
//sums the current row down
void sumrowdown(int arr[][3], int r, int c) {
    int first = arr[r][0];
    int second = arr[r][1];
    int third = arr[r][2];
    arr[increaseindex(r)][0] += first;
    arr[increaseindex(r)][1] += second;
    arr[increaseindex(r)][2] += third;
}

//prints a char corresponding to the int in the cell
void tochar(int num) {
    switch(num) {
        case 0: printf(" ");
            break;
        case 1: printf("a");
            break;
        case 2: printf("b");
            break;
        case 3: printf("c");
            break;
        case 4: printf("d");
            break;
        case 5: printf("e");
            break;
        case 6: printf("f");
            break;
        case 7: printf("g");
            break;
        case 8: printf("h");
            break;
        case 9: printf("i");
            break;
        case 10: printf("j");
            break;
        case 11: printf("k");
            break;
        case 12: printf("l");
            break;
    }
}