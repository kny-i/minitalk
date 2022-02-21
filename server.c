#include "minitalk.h"

t_signal	g_signal;

static void	put_pid(void)
{
	ft_putstr_fd("pid:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_signal.ans += (0b100000000 >> g_signal.count_shift);
	if (g_signal.count_shift == 1)
	{
		ft_putchar_fd(g_signal.ans, STDOUT_FILENO);
		g_signal.ans = 0;
		g_signal.count_shift = 8;
		return ;
	}
	g_signal.count_shift--;
}

int	main(void)
{
	g_signal.ans = 0;
	g_signal.count_shift = 8;
	put_pid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
