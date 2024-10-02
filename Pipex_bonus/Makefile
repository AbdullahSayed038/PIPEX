CC		:= cc

CFLAGS	:= -Wall -Werror -Wextra -g3 -O3 # -fsanitize=address,undefined

SRCS	:= pipex_bonus.c fork_bonus.c handle_bonus.c utils_bonus.c here_doc.c

OBJS	:= $(SRCS:.c=.o)

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

NAME	:= pipex

all			:	print_art $(NAME)

%.o			:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME)	:	$(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $@


clean		:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean		:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re			:	fclean all

print_art	:
	@echo "                                                      "
	@echo "       ███████████                 ██████████        "
	@echo "    ████          ███            ███         ███     "
	@echo "   ██               ██         ██              ██    "
	@echo "  ██    █████████    ██       ██    ████████    ██   "
	@echo "  ██   ██       ██    ██     ██   ███       ██   ██  "
	@echo " ██   ██          █    ████████   █          █    ██ "
	@echo " ██   ██        ███               ███        █    ██ "
	@echo "  █    ██    ████████                ██     ██    █  "
	@echo "  ██    ████████████████     ████████████████    ██  "
	@echo "   ██     ████   ████  ██  ███   ███   ███      ██   "
	@echo "     ███  ██     ███     ███    ████    ███   ██     "
	@echo "        ████     ███     ███    ████     ████        "
	@echo "        ████    █████    ███    █████    ███         "
	@echo "        ██ ██   █████   ████    █████   ██ █         "
	@echo "        █   ██  ████   ██   ██  ████  ███  ██        "
	@echo "        ██    █████████       █████████    ██        "
	@echo "        ████████████████████████████████████         "
	@echo "         ██  ██ █    ███     ██     █ █   ██         "
	@echo "          ████  █   █  █     ███   █   ██ █          "
	@echo "           ██   ██ ██  ██   █  ██ ██    ██           "
	@echo "            ███  █ █    ██ ██   ████   ██            "
	@echo "              ██ ██      █ █    ███  ██              "
	@echo "                ████     ███     ████                "
	@echo "                    █████████████                    "
	@echo "                                                     "


PHONY: all clean fclean re print_art
