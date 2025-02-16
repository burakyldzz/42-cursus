#include "minitalk.h"

static void	send_signal(int server_id, char *text)
{
	char	res;
	int		i;
	int		j;

	i = 0;
	while (text[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			res = (text[i] >> j) & 1;
			if (res == 1)
				kill(server_id, SIGUSR1);
			else if (res == 0)
				kill(server_id, SIGUSR2);
			usleep(142);
			j--;
		}
		i++;
	}
	
}

int main(int ac, char *av[])
{
	int	server_id;

	if (ac == 3)
	{
		server_id = ft_atoi(av[1]);
		send_signal(server_id, av[2]);
	}
	else
		write(1, "Eksik arguman sayisi.", 21);
	return (0);
}