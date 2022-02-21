#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	res;

	num = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		num = -1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (*str && '0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * num);
}

static void	put_error(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	send_message(pid_t pid, char *word)
{
	int	i;
	int	count_shift;
	int	kill_confirm;

	i = 0;
	while (word [i] != '\0')
	{
		count_shift = 0;
		while (count_shift < 8)
		{
			if (word[i] >> count_shift & 0b00000001)
				kill_confirm = kill(pid, SIGUSER1);
			else
				kill_confirm = kill(pid, SIGUSER2);
			if (kill_confirm == -1)
				put_error("kill error");
			count_shift++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		put_error("invalid argument\n");
	if (ft_strlen(argv[1]) >= 12)
		put_error("argument is too log\n");
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
