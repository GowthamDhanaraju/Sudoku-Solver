# Sudoku-Solver
In this project I have coded a backtracking algorithm in C language to solve the code.

Time complexity:
O(9(N * N)), For every unassigned index, there are 9 possible options so the time complexity is O(9^(n*n)). The time complexity remains the same but there will be some early pruning so the time taken will be much less than the naive algorithm but the upper bound time complexity remains the same.

Space Complexity:
O(N * N), To store the output array a matrix is needed.

Like all other Backtracking problems, Sudoku can be solved by assigning numbers one by one to empty cells. Before assigning a number, check whether it is safe to assign.
Check that the same number is not present in the current row, current column and current 3X3 sub-grid. After checking for safety, assign the number, and recursively check whether this assignment leads to a solution or not. If the assignment doesn’t lead to a solution, then try the next number for the current empty cell. And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.
