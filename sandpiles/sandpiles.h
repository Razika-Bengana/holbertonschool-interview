#ifndef SANDPILES_H
#define SANDPILES_H

void print_sandpile(int grid[3][3]);
int check_is_stable(int grid1[3][3], int grid2[3][3]);
void sum_grids(int grid1[3][3], int grid2[3][3]);
void toppling_round(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
