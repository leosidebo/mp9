#include "game_of_life.h"

/* Description:  Checks the parameters to the program. Checks if the 
 *               call to the program has the right number of
 *               parameters. Open the input and output files.
 *  Input:       The parameters to the program and two pointers to file
 *               pointers.
 *  Output:      Returns 0 when the files are correctly opened.
 *               Returns a non-zero value on failure.
*/
int check_prog_params(int argc, const char *argv[],
                      FILE **in_file_p, FILE **out_file_p)
{
    if(argc == 3) {
        FILE *in_file_p = fopen(argv[1], "r");
        if(in_file_p == NULL) {
            return 1;
        }

        FILE *out_file_p = fopen(argv[2], "w");
        if(out_file_p == NULL) {
            return 1;
        }

        return 0;
    }

    return 1;
}

void init_field(const int rows, const int cols,
                cell field[rows][cols])
{
    for (int r = 0 ; r < rows ; r++) {
        for (int c = 0 ; c < cols ; c++) {
            field[r][c].current = DEAD;
        }
    }
}

/* Description: Initializes the future generation.
 * Input:       The field array and its size.
 * Output:      The field array is updated with the
 *              future generations states.
 */
void future_generation(const int rows, const int cols,
                        cell field[rows][cols]) 
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            field[i][j].next = field[i][j].current;
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int aliveNeighbors = count_alive_neighbors(rows, cols, j, i, field);

            if(field[i][j].current == ALIVE) {
                if(aliveNeighbors < 2) {
                    field[i][j].next = DEAD;
                } else if(aliveNeighbors == 2 && aliveNeighbors == 3) {
                    field[i][j].next = ALIVE;
                } else if (aliveNeighbors > 3) {
                    field[i][j].next = DEAD;
                }
            }
            else {
                if(aliveNeighbors == 3) {
                    field[i][j].next = ALIVE;
                }
            }
        }
    }
}

/* Description: Prints the field.
 * Input:       The field array and its size.
 * Output:      The field array, represented
 *              as 'X' and '.'
 */
void print_field(const int rows, const int cols,
                 cell field[rows][cols]) 
{
    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {
            printf("%c ", field[i][j].current);
        }
        printf("\n");
    }
}

/* Description: Counts the number of alive neighbors
                a certain position in the field has
 * Input:       The field array and its size, along with
 *              a position in the field.
 * Output:      The number of alive neighbors the 
 *              position has.
 */
int count_alive_neighbors(const int rows, const int cols, 
                        int y, int x, cell field[rows][cols]) {
    int totalAliveNeighbors = 0;
  
    /**
     * This part could be pretty hard to understand. Since the 
     * value of the character . is 46 and X is 88 I subtract 46 
     * from the characters value and end up with 0 if it was dead,
     * and 42 if it was alive. At the end I divide the result by 42 
     * leaving me with the amount of neighbors that are alive.
    **/ 

    if(x != 0) {
        if(y != 0) {
            totalAliveNeighbors += field[x - 1][y - 1].current - 46;
        } 

        totalAliveNeighbors += field[x - 1][y].current - 46;

        if (y != rows - 1) {
            totalAliveNeighbors += field[x - 1][y + 1].current - 46;
        }
    }

    if(y != 0) {
        totalAliveNeighbors += field[x][y - 1].current - 46;
    }
    if(y != rows - 1) {
        totalAliveNeighbors += field[x][y + 1].current - 46;
    }
    
    if(x != rows - 1) {
        if(y != 0) {
            totalAliveNeighbors += field[x + 1][y - 1].current - 46;
        } 

        totalAliveNeighbors += field[x + 1][y].current - 46;

        if (y != rows - 1) {
            totalAliveNeighbors += field[x + 1][y + 1].current - 46;
        }
    }

    return totalAliveNeighbors / 42;
}

/* Description: Goes forward in time, making the next 
                generation the current one.
 * Input:       The field array and its size.
 * Output:      The field array is changed.
 */
void next_generation(const int rows, const int cols,
                    cell field[rows][cols])
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            field[i][j].current = field[i][j].next;
        }
    }
}