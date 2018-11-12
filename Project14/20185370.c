#include <stdio.h>

void indexAddmat(int Mat[3][3]);
void ptrProdMat(int *p);
void prtMatrix(int Mat[3][3]);
int Matrix[3][3];

int main()
{
	int i, j;
	printf("9개의 정수를 입력하시오\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d행 %d열 입력 : ",i+1,j+1);
			scanf_s("%d", &Matrix[i][j]);
		}
	}

	int *p = Matrix;

	prtMatrix(Matrix);
	
	printf("\n");

	indexAddmat(Matrix);

	printf("\n");

	ptrProdMat(Matrix);



	system("pause");
	return 0;
}

void indexAddmat(int Mat[3][3])
{
	int result[3][3];
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			result[i][j] = Matrix[i][j] + Matrix[i][j];
		}
	}

	printf("합: \n");
	prtMatrix(result);
	
}
void ptrProdMat(int *p)
{
	int result[3][3];
	int cal = 0;;
	int i, j,row,column;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (row = 0, column = 0; column < 3; row++, column++)
			{
				cal += *(*(Matrix + i) + column)**(*(Matrix + row) + j);
			}
			*(*(result + i) + j) = cal;
			cal = 0;
		}
	}

	printf("곱: \n");
	prtMatrix(result);
}

void prtMatrix(int Mat[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\t", Mat[i][j]);
		}
		printf("\n");
	}
}