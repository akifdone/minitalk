NAME_SV = server.c utils.c binary_to.c -o server
NAME_CL = client.c utils.c binary_to.c -o client
all:
	@gcc $(NAME_SV)
	@gcc $(NAME_CL)
	@echo make completed.

clean:
	@rm -rf server client
	@echo make cleaned.

fclean:
	@rm -rf server client
	@echo make cleaned.

re:
	@rm -rf server client
	@gcc $(NAME_SV)
	@gcc $(NAME_CL)
	@echo make re completed.

.PHONY: all clean fclean re