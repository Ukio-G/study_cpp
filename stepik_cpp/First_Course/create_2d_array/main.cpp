#include <iostream>


int ** create_2d_array(unsigned int size_a, unsigned int size_b)
{
    int ** array = new int * [size_a];
    for(size_t i = 0 ; i < size_a ; i++)
        array[i] = new int [size_b];
    return array;
}
void delete_2d_array(int ** array, unsigned int size_a)
{
    for(size_t i =0 ; i < size_a; i++)
        delete [] array[i];
    delete [] array;
}
int main(int argc, const char *argv[])
{
    
    return 0;
}
