#include <stdio.h>
#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, int ar [rows][cols]);
	
int main(void)
{
	int i,j;
	int rs = 3;
	int cs = 10;
	int junk[ROWS][COLS]= {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10 ,8, 6}
	};
	int morejunk[ROWS-1][COLS + 2] = {
		{20, 30, 40, 50, 60, 70},
		{5, 6, 7, 8, 9, 10}
	};

	int varr[rs][cs];

	for(i = 0;i < rs; i++)
		for(j = 0; j < cs; j++)
		{
			varr[i][j] = (i * j + j); 
		}
	printf("3*4 array\n");
	printf("the sum of array is %d\n",sum2d(ROWS,COLS,junk));
	
	printf("2*5 array\n");
	printf("the sum of array is %d\n",sum2d(ROWS - 1,COLS + 2,morejunk));

	printf("rs * cs array\n");
   	printf("the sum of array is %d\n",sum2d(rs, cs, varr));

   	return 0;
}

int sum2d(int rows, int cols, int ar[rows][cols])
{
	int  ans = 0;
	for(int i = 0;i < rows;i++) 
		for(int j = 0;j < cols; j++)
			ans +=ar[i][j];

	return ans; 
}

