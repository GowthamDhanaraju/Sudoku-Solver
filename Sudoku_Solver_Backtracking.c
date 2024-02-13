#include <stdio.h>

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9



/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
int SolveSudoku(int grid[N][N])
{
    int row, col;

    // If there is no unassigned location , solving is over.
    if (!FindUnassignedLocation(grid, &row, &col))
        // success!
        return 1;

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {

        // Check if looks promising
        if (isSafe(grid, row, col, num))
        {

            // Make tentative assignment
            grid[row][col] = num;

            // Return, if success
            if (SolveSudoku(grid))
                return 1;

            grid[row][col] = UNASSIGNED;
        }
    }

    // This triggers backtracking
    return 0;
}
int FindUnassignedLocation(int grid[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == UNASSIGNED)
                return 1;
    return 0;
}

int UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

int UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

int UsedInBox(int grid[N][N], int boxStartRow,
              int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] ==
                num)
                return 1;
    return 0;
}

int isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3,
                      col - col % 3, num) &&
           grid[row][col] == UNASSIGNED;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        if (row%3==0)
            printf("  === === ===  === === ===  === === === \n");
        else
            printf("  --- --- ---  --- --- ---  --- --- --- \n");
        for (int col = 0; col < N; col++)
            {
            if (col%3==0)
                printf("|| %d ", grid[row][col]);
            else
                printf("| %d ", grid[row][col]);
            }
        printf("||");
        printf("\n");
    }
    printf("  === === ===  === === ===  === === === \n");
}

int main()
{
    int grid[N][N] = {{0,0,0,2,6,0,7,0,1},{6,8,0,0,7,0,0,9,0},{1,9,0,0,0,4,5,0,0}
,{8,2,0,1,0,0,0,4,0},{0,0,4,6,0,2,9,0,0},{0,5,0,0,0,3,0,2,8}
,{0,0,9,3,0,0,0,7,4}, {0,4,0,0,5,0,0,3,6},{7,0,3,0,1,8,0,0,0}};
    printf("YOUR INTIAL QUESTION :\n");
    printGrid(grid);
    SolveSudoku(grid);
    printf("SOLUTION EXISTS : \n");
    printGrid(grid);
    return 0;
}
