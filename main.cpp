#include <iostream>

using namespace std;

int solveSudoku(int puzzle[9][9]);
int isValid(int number, int puzzle[9][9], int row, int column);
int sudokuHelper(int puzzle[9][9], int row, int column);
void printSudoku(int puzzle[9][9]);

int main() {
    int puzzle[9][9]= {
    {6,5,0,8,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,0,5,0,0,0,0,0,0},
    {4,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,5,0,3},
    {5,7,8,3,0,1,0,2,6},
    {2,0,0,0,4,8,9,0,0},
    {0,9,0,6,2,5,0,8,1}
/*Example 2:*/
/*

   3, 8, 5, 0, 0, 0, 0, 0, 0,
   9, 2, 1 ,0 ,0 ,0 ,0 ,0 ,0,
   6, 4 ,7, 0, 0, 0, 0 ,0 ,0,
   0 ,0 ,0 ,1 ,2 ,3 ,0 ,0 ,0,
   0 ,0 ,0 ,7 ,8 ,4 ,0 ,0 ,0,
   0, 0 ,0 ,6 ,9 ,5 ,0 ,0 ,0,
   0 ,0 ,0 ,0 ,0 ,0 ,8 ,7, 3,
   0 ,0 ,0 ,0 ,0 ,0 ,9 ,6 ,2,
   0 ,0, 0 ,0 ,0 ,0, 1, 4, 5,
*/
};
    /* Print out the original puzzle, then start solving. */
    cout<<"Original Puzzle:"<<endl;

    printSudoku(puzzle);

    cout<<"Solving:"<<endl;

    /* If successful, print the solution */
    if (solveSudoku(puzzle)) {
        cout<<"Sudoku Solved!"<<endl;
        printSudoku(puzzle);
    }
    else {
        cout<<"Sudoku not solvable"<<endl;
    }

    return 0;
}

/*Solve Function*/
int solveSudoku(int puzzle[9][9]) {
    return sudokuHelper(puzzle, 0, 0);
}

/*Recursive Function used calc.*/
int sudokuHelper(int puzzle[9][9], int row, int column) {

    if (row==9) {
        return 1;
    }
    else if (puzzle[row][column]) {
        if (column == 8) {
            if (sudokuHelper(puzzle, row+1, 0)) return 1;
        }
        else {                                                ///<----------so column is not out of bounds
            if (sudokuHelper(puzzle, row, column+1)) return 1;
        }
        return 0;
    }

    for (int nextNumber = 1; nextNumber<10; nextNumber++) {
        if(isValid(nextNumber, puzzle, row, column)) {      ///<------possible value for cell
            puzzle[row][column] = nextNumber;
            if (column == 8) {
                if (sudokuHelper(puzzle, row+1, 0)) return 1;
            } else {
                if (sudokuHelper(puzzle, row, column+1)) return 1;
            }
            puzzle[row][column] = 0;
        }
    }
    return 0;
}

/*Validity of number*/
int isValid(int number, int puzzle[9][9], int row, int column) {
    int modRow = 3*(row/3); ///<----------starting index of the row
    int modCol = 3*(column/3);  ///<----------starting index of the column

    /* Check for the value in the given row and column */
    for (int i=0; i<9; i++) {
        if (puzzle[i][column] == number) return 0;
        if (puzzle[row][i] == number) return 0;
    }
    /*checking sub matrix*/
    for(int i=modRow;i<modRow+3;i++)
    {
        for(int j=modCol;j<modCol+3;j++)
        {
            if(puzzle[i][j]==number)
                return 0;
        }
    }
    return 1;
};

/*PRINT*/
void printSudoku(int puzzle[9][9]) {
    cout<<"----------------------\n";
    /*Row loop*/
    for (int i = 0; i < 9; i++)
    {
        cout<<"|";
        /*Column loop*/
        for (int j = 0; j < 9; j++)
        {
            cout<<puzzle[i][j]<<" ";

            if (((j + 1) % 3) == 0)
            {
                cout<<"|";
            }
        }
        cout<<"\n";
        if (((i + 1) % 3) == 0)
        {
            cout<<"----------------------\n";
        }
    }
}
