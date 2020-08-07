#include <iostream>
#include <random>
#include "time.h"
int ** create_with_random_array2d(unsigned int a, unsigned int b)
{
    int ** m = new int * [a];
    m[0] = new int [a*b];

    for (size_t i = 1; i != a;  i++){
        m[i] = m[i - 1] + b;
    }

	for (int i = 0; i < a*b; ++i)
		*(m[0] + i) = rand() % 8 + 1;

    return m;
}

void print_matrix(int ** matrix,int cols,int rows){
	for (int j = 0; j < rows; ++j)
	{
		for (int i = 0; i < cols; ++i)
			std::cout << matrix[j][i] << " ";
		std::cout << std::endl;
	}
}


void swap_lines(int *m[], unsigned row1, unsigned row2)
{
	
	// int * row1ptr = m[row1];
	// int ** row2ptr = &m[row2];
	// int ** templateRow = row1ptr;

 // 	std::cout << row1ptr << " " << m[row1] << std::endl;

 // 	*(row2ptr) = row1ptr;
}


void swap_min(int *m[], unsigned rows, unsigned cols)
{
	int minimumValue = m[0][0];
 	int minimumValueRowIndex = 0;
 	
 	for (int i = 0; i < rows; ++i)
 	   {
 	   	int * currentRow = m[i];
 	   	for (int j = 0; j < cols; ++j)
 	   	{
 	   		if(currentRow[j] < minimumValue){
 	   			minimumValue = currentRow[j];
 	   			minimumValueRowIndex = i;
 	   		} 
 	   	}
 	}   
 	
 	if(minimumValueRowIndex!=0){
 	int * templateRow = m[0];
 	m[0] = m[minimumValueRowIndex];
 	m[minimumValueRowIndex] = templateRow;
 }
}

int main(int argc, char const *argv[])
{
	srand(time(0));
	int ** array = create_with_random_array2d(5,5);
	print_matrix(array,5,5);
	// swap_lines(array,0,1);
	swap_min(array,5,5);
	std::cout << "----------" << std::endl;
	print_matrix(array,5,5);
	return 0;
}