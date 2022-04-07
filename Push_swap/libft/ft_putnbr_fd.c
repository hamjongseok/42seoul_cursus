#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long long	num;

	num = n;
	if (n < 0)
	{	
		num *= -1;
		write(fd, "-", 1);
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		num %= 10;
	}
	if (num <= 9)
	{
		c = num + '0';
		write(fd, &c, 1);
	}
}
