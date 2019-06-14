#include<iostream>
#include<vector>

void printBoard(int board[9][9]);


bool check(int board[9][9], int row, int column, int val){
   
    bool r = false;
    bool c = false;
    bool b = false;
    
    for(int col = 0; col < 9; col++) {
        if(board[row][col] == val){
            r = true;
        }
    }
    
    for (int r = 0; r < 9; r++) {
        if(board[r][column] == val) {
            c = true;
        }
    }
    
    for (int r = 0; r < 3; r++) {
        for(int col = 0; col < 3; col++) {
            if(board[r + (row - row%3)][col + (column - column%3)] == val) {
                b = true;
            }
        }
    }
    return (!r && !c && !b);
}

bool nextSpot(int board[9][9], int & r, int & c){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0){
                r = i;
                c = j;
                return false;
            }
        }
    }
    return true;
}

bool solve(int board[9][9], int r, int c){
    if(nextSpot(board, r, c)) {
        return true;
    }
    
    for(int val = 1; val < 10; val++){
        if(check(board, r, c, val)) {
            board[r][c] = val;
            if(solve(board, r, c)) {
                return true;
            }
            board[r][c] = 0;
        }
    }
    return false;
}

void printBoard(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            std::printf("%2d", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int args, char **argv){
    int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
        { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
        { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
        { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
        { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
        { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
        { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
        { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 7, 0, 0, 0, 0, 0, 3, 0 }
    };
    solve(board,0,0);
    printBoard(board);
    
}
