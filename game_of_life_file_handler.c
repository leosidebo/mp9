#include "game_of_life_file_handler.h"

/*
 * Description: Load a configuration to the field array from a file.
 * Input:       The field array, its size and a file pointer to the
 *              file with the initial configuration.
 * Output:      Returns 0 on success, the field array is updated with
 *              the configuration from the file.
 *              Returns a non-zero value on failure. 
 *              The file pointed to by fp is closed.
*/
int load_config_from_file(const int rows, const int cols,
                          cell field[rows][cols], FILE *fp)
{
    printf("bee");
    int inputRows, inputCols;
    printf("bee");
    fscanf(fp, "%d,%d\n", &inputRows, &inputCols);

    printf("bee");

    if(inputRows > rows || inputCols > cols) {
        return 1;
    }

    char c;
    for(int i = 0; i < inputRows; i++) {
        printf("see");
        for(int j = 0; j < inputCols; j++) {

            c = (char)fgetc(fp);
            if(c == '*') {
                field[i][j].current = 'X';
            } else if(c == '0') {
                field[i][j].current = '.';
            }
        }
    }

    printf("yee");
    fclose(fp);
    return 0;
}
                          
/* 
 * Description: Saves the current configuration of the field array to 
 *              a specified file. 
 * Input:       The field array, its size and a file pointer to the 
 *              file where the final configuration should be saved. 
 * Output:      Returns 0 on success, the current configuration in the 
 *              field array is written to the file. Returns a non-zero
 *              value on failure. The file pointed to by fp is closed.
*/
/* int save_config_to_file(const int rows, const int cols,
                        const cell field[rows][cols],FILE *fp) 
{

}*/