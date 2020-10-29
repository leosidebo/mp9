#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants, representation of states */
#define ALIVE 'X'
#define DEAD '.'

/* Declaration of data structure */
typedef struct {
  char current;
  char next;
} cell;

/* Declaration of functions */
int check_prog_params(int argc, const char *argv[],
                      FILE **in_file_p, FILE **out_file_p);
void init_field(const int rows, const int cols,
                cell field[rows][cols]);
void print_field(const int rows, const int cols,
                 cell field[rows][cols]);
int count_alive_neighbors(const int rows, const int cols, 
                        int y, int x, cell field[rows][cols]);
void future_generation(const int rows, const int cols,
                    cell field[rows][cols]);
void next_generation(const int rows, const int cols,
                    cell field[rows][cols]);