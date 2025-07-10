#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
void printPuzzle (int puzzle [3][3]) {  
    for (int i = 0; i < 3; i++) {         
        for (int j = 0; j < 3; j++) {             
            if (puzzle[i][j] == 0) {                 
                printf("  ");             
            } else {                 
                printf("%d ", puzzle[i][j]);  
            }  
        }  
        printf("\n");  
    }  
}  
  
int isPuzzleSolved(int puzzle [3][3]) {     
    int count = 1;  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 3; j++) {             
            if (puzzle[i][j] != count % 9) {                 
                return 0;   
            }  
            count++;  
        }  
    }  
    return 1;   
}  

void moveTile(int puzzle[3][3], int move) {  
    int i, j;  
    for (i = 0; i < 3; i++) {         
        for (j = 0; j < 3; j++) {             
            if (puzzle[i][j] == 0) {                 
                break;  
            }  
        } 
        if (puzzle[i][j] == 0) {             
            break;  
        }  
    }  
      
    switch (move) {  
        case 1:              
            if (i > 0) {                 
                puzzle[i][j] = puzzle[i - 1][j];                 
                puzzle[i - 1][j] = 0;  
            }  
            break;         
        case 2:              
            if (i < 2) {                
                puzzle[i][j] = puzzle[i + 1][j];                
                puzzle[i + 1][j] = 0;  
            }  
            break;         
        case 3:              
            if (j > 0) {                 
                puzzle[i][j] = puzzle[i][j - 1];                 
                puzzle[i][j - 1] = 0;  
            }  
            break;         
        case 4:              
            if (j < 2) {                 
                puzzle[i][j] = puzzle[i][j + 1];                
                puzzle[i][j + 1] = 0;  
            } 
            break;         
        default:  
            printf("Invalid move!\n");  
    }  
}  

int main() {     
    int puzzle[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}; // Initial state of the puzzle     
    int move;    
    srand(time(NULL));  

    for (int i = 0; i < 100; i++) {         
        move = rand() % 4 + 1;          
        moveTile(puzzle, move);  
    }  
    printf("Welcome to the 3x3 Puzzle Game!\n");  
    do {         
        printPuzzle(puzzle);  
        printf("Enter move (1: Up, 2: Down, 3: Left, 4: Right, 0: Quit): ");         
        scanf("%d", &move);  
        if (move == 0) {             
            printf("Thanks for playing!\n");  
            break;  
        } 
        moveTile(puzzle, move);  
        if (isPuzzleSolved(puzzle)) {             
            printPuzzle(puzzle);    
            printf("Congratulations! You solved the puzzle!\n");  
            break;  
        }  
    } while (1);  
    return 0;  
} 
