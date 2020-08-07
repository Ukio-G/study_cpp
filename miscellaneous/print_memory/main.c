#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_printchar(unsigned char c)
{
	ft_putchar((c > 31 && c < 127) ? c : '.');
}

void ft_print_hex(int dword)
{
	int result;
	if (dword >= 16)
		ft_print_hex(dword/16);

	result = dword % 16;

	if (result >= 10)
		result += 'a' - 10;
	else
		result += '0';
	ft_putchar(result);
}

void print_memory(void *data, int i)
{
	int counter_hex_bytes;
	int counter_char_bytes;
	int total_counter;


	unsigned char *d = data;

	while (i > total_counter) {
	    
		// if (d[i] > 0)

		counter_hex_bytes = 0;

		while (counter_hex_bytes < 16)
		{
			if (i > counter_hex_bytes + total_counter)
			{
				if (d[total_counter + counter_hex_bytes] < 16)
					ft_putchar('0');
				ft_print_hex(d[total_counter + counter_hex_bytes]);
			}
			else
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			counter_hex_bytes++;
			if (counter_hex_bytes % 2 == 0)
				ft_putchar(' ');
			
		}

		counter_char_bytes = 0;
		while (counter_char_bytes < 16)
		{
			if (i > counter_char_bytes + total_counter)
				ft_printchar(d[total_counter + counter_char_bytes]);
			counter_char_bytes++;
		}

		total_counter+=counter_char_bytes;
		ft_putchar('\n');
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}