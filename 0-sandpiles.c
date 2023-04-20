#include <stdio.h>

void topple(int grid[3][3])
{
	int temp[3][3];
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			temp[i][j] = grid[i][j];
		}
	}

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				for(int k=0; k<4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if(x >= 0 && x < 3 && y >= 0 && y < 3)
					{
						temp[x][y]++;
					}
				}
			}
		}
	}

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			grid[i][j] = temp[i][j];
		}
	}
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

    while(1)
    {
	    int unstable = 0;
	    for(int i=0; i<3; i++)
	    {
		    for(int j=0; j<3; j++)
		    {
			    if(grid1[i][j] > 3)
			    {
				    unstable = 1;
				    break;
			    }
		    }
		    if(unstable) break;
	    }
	    if(unstable)
	    {
		    printf("=\n");
		    for(int i=0; i<3; i++)
		    {
			    for(int j=0; j<3; j++)
			    {
				    printf("%d ", grid1[i][j]);
			    }
			    printf("\n");
		    }
		    topple(grid1);
	    }

	    else
	    {
		    break;
	    }
    }
}
