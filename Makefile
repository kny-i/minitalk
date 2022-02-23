CC				= cc
CFLAGS			= -Wall -Wextra -Werror
SERVER_NAME     = server
CLIENT_NAME     = client
NAME = minitalk

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

bonus:			client_bonus server_bonus

server:			server.c utils.c
				$(CC) -o server $(CFLAGS) server.c utils.c

server_bonus:	server_bonus.c utils.c
				$(CC) -o server_bonus $(CFLAGS) server_bonus.c utils_bonus.c

client:			client.c utils.c
				$(CC) -o client $(CFLAGS) client.c utils.c

client_bonus:	client_bonus.c utils.c
				$(CC) -o client_bonus $(CFLAGS) client_bonus.c utils_bonus.c

all:			$(NAME)
clean:
				$(RM) server.o client.o utils.o utils_bonus.o client_bonus.o server_bonus.o

fclean:			clean
				$(RM) server client client_bonus server_bonus

re:				fclean all bonus

.PHONY:			all clean fclean re