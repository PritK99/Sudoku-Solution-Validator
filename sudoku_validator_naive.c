#include <stdio.h>

int main()
{
    int sudoku[9][9] = {
        {7, 9, 2, 1, 5, 4, 3, 8, 6},
        {6, 4, 3, 8, 2, 7, 1, 5, 9},
        {8, 5, 1, 3, 9, 6, 7, 2, 4},
        {2, 6, 5, 9, 7, 3, 8, 4, 1},
        {4, 8, 9, 5, 6, 1, 2, 7, 3},
        {3, 1, 7, 4, 8, 2, 9, 6, 5},
        {1, 3, 6, 7, 4, 8, 5, 9, 2},
        {9, 7, 4, 2, 1, 5, 6, 3, 8},
        {5, 2, 8, 6, 3, 9, 4, 1, 7}};

    int x = 0, y = 0, z = 0; // These will act as flags if any condition is violated

    /*Checking values in a row*/
    for (int i = 0; i < 9; i++)
    {
        int visited[9] = {0};
        for (int j = 0; j < 9; j++)
        {
            if (visited[sudoku[i][j] - 1] == 1) // Number j occurs more than once in a row
            {
                x = 1;
                break;
            }
            else
            {
                visited[sudoku[i][j] - 1] = 1;
            }
        }
        if (x == 1)
        {
            break;
        }
    }

    /*Checking values in a column*/
    for (int j = 0; j < 9; j++)
    {
        int visited[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            if (visited[sudoku[i][j] - 1] == 1) // Number j occurs more than once in a column
            {
                y = 1;
                break;
            }
            else
            {
                visited[sudoku[i][j] - 1] = 1;
            }
        }
        if (y == 1)
        {
            break;
        }
    }

    /*Checking all 3X3 sub-matrices*/
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            int visited[9] = {0};
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    if (visited[sudoku[k][l] - 1] == 1) // Number j occurs more than once in a submatrix
                    {
                        z = 1;
                        break;
                    }
                    else
                    {
                        visited[sudoku[k][l] - 1] = 1;
                    }
                }
                if (z == 1)
                {
                    break;
                }
            }
            if (z == 1)
            {
                break;
            }
        }
        if (z == 1)
        {
            break;
        }
    }

    if (x == 1 || y == 1 || z == 1) // If any of the conditions are violated
    {
        printf("Invalid solution. Please try again.\n");
    }
    else
    {
        printf("The given solution is valid.\n");
    }

    return 0;
}