#include <iostream>

char * resize(const char * str, unsigned size, unsigned new_size)
{
	char * new_str = new char[new_size];
	for(unsigned int i = 0; size > i && new_size > i; i++)
    new_str[i] = str[i];
	delete [] str;
	return new_str;
}

char * getline()
{
    unsigned int buffer_size = 4;
    unsigned int buffer_used = 0;
    char * str = new char[buffer_size];
    char buf_char;
    while(std::cin.get(buf_char) && buf_char != '\n')
    {
        if(buffer_used==buffer_size)
        {
            str = resize(str,buffer_size,buffer_size*2);
            buffer_size*=2;
        }

        str[buffer_used++] = buf_char;
    }

    return str;
}

int main(int argc, const char *argv[])
{
    char * str = 0;
    
    str = getline();
    std::cout << str << std::endl;
    delete [] str;

    return 0;
}
