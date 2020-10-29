/*
 * Programmering i C
 * Fall 20
 * Mastery test 8

 * File:         mp8.c
 * Description:  A simple implementation of Conway's Game of Life.
 * Author:       Leo Sidebo
 * CS username:  ens19lso
 * Date:         2020-10-28
 * Input:        Choice of initial configuration and then instruction
                 to step or exit.
 * Output:       Prints the game field in each step.
 * Limitations:  No validation of input.
 */

#include "game_of_life_file_handler.h"

/* Description: Start and run games, interact with the user.
 * Input:       About what initial structure and whether to step or
 *              exit.
 * Output:      Prints information to the user, and the game field in
 *              each step.
 */
int main(int argc, const char *argv[])
{
    const int rows = 20;
    const int cols = 20;
    cell field[rows][cols];
    FILE *input;
    FILE *output;

    if(check_prog_params(argc, argv, &input, &output) != 0) {
        fprintf(stderr, "%s", "Error!\n");
        return 0;
    }

    init_field(rows, cols, field);
    if(load_config_from_file(rows, cols, field, input) != 0) {
        fprintf(stderr, "%s", "Error!\n");
        return 0;
    }
    
    do {
        future_generation(rows, cols, field);
        print_field(rows, cols, field);

        printf("Select one of the following options: \n");
        printf("        (enter) Step\n");
        printf("        (any) Exit\n"); 

        next_generation(rows, cols, field);
    } while(getchar() == '\n');



    return 0;
}



