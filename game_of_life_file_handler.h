#include "game_of_life.h"

int load_config_from_file(const int rows, const int cols,
                          cell field[rows][cols], FILE *fp);             
int save_config_to_file(const int rows, const int cols,
                        const cell field[rows][cols],FILE *fp);