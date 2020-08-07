#include <iostream>

int ** create(unsigned int a, unsigned int b)
{
    int ** m = new int * [a];
    m[0] = new int [a*b];

    for (size_t i = 1; i != a;  i++)
        m[i] = m[i - 1] + b;

    return m;
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** result = new int * [cols];
    result[0] = new int[cols*rows];
    for (int i = 0; i < cols; ++i) {
    	result[i+1] = result[i] + rows;
    	for (int j = 0; j < rows; ++j)	
    		result[i][j] = m[j][i];
    }
    return result;
}

void print_matrix(int ** matrix,int cols,int rows){
	for (int j = 0; j < rows; ++j)
	{
		for (int i = 0; i < cols; ++i)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}


int main(int argc, char const *argv[])
{
	
	int ** array = create(3,5);

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 5; ++j)
			array[i][j] = j+i;
		

	print_matrix(array,3,5);

	int ** t_array = transpose(array,3,5);
	print_matrix(t_array,5,3);

	return 0;
}