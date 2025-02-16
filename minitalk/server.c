#include "minitalk.h"

static void signal_handler(int signal)
{
    static char chr;
    static int  i;

    i++;
    if (signal == SIGUSR1)
        chr = chr | 1;
    if (i == 8)
    {
        write(1, &chr, 1);
        i = 0;
        chr = 0;
    }
    chr = chr << 1;
}

int main()
{
	int	pid;

	pid = getpid();
    ft_putstr("PID Number: ");
    ft_putnbr(pid);
    ft_putstr("\n");
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while(1)
    {
        pause();
    }
    return (0);
}