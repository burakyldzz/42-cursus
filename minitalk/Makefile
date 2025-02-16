NAME = minitalk
SERVER = server.c
CLIENT = client.c
SERVER_NAME = server
CLIENT_NAME = client
SRCS = utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(SERVER_NAME) $(CLIENT_NAME)

$(NAME) : all

$(SERVER_NAME): 
	$(CC) $(CFLAGS) $(SERVER) $(SRCS) -o $(SERVER_NAME)

$(CLIENT_NAME):
	$(CC) $(CFLAGS) $(CLIENT) $(SRCS) -o $(CLIENT_NAME)

clean:
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean bonus