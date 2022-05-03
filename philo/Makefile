NAME			=	philo

LEAKS			=	-fsanitize=address -fno-omit-frame-pointer
CC			=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3
RM			=	rm -rf

HEADER_DIR		=	include
HEADER			=	philo
HEADERS			=	$(addprefix $(HEADER_DIR)/, $(addsuffix .h, $(HEADER)))

SRC_DIR			=	src
SRC			=	philo ph_init ph_action ph_checkvalid ph_starving
SRCS 			=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

OBJ_DIR			=	obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m
SALMON = \033[38;5;174m
HOTPINK = \033[38;5;168m

all:				$(NAME)

$(NAME):			$(OBJ)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c	$(HEADERS)
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -c $< -o $@ 			
					

leaks:				$(NAME)
					@echo "$(GREEN)For Leaks Check:$(NORMAL)"
					$(CC) $(LEAKS) $(SRCS) -o $(NAME)

clean:
					@$(RM) -f $(OBJ) $(OBJ_B) $(OBJ_DIR)
fclean:				clean
					@$(RM) -f $(NAME) $(NAME_B)

re:					fclean all

.PHONY:				all clean fclean re libft leaks

pig:				
					@echo "$(SALMON)                         .....            :!????7!^:\n\
                   .^!J5PGGBGG5::~!77?77~:G&&&&&&&&#GY!.\n\
                 .?G#&&&&&&&&&B^G&&&&&&&B^G&&&&&&&&&&&#^\n\
                 .P&&&&&&&&&&#!?&&&&&&&&&J~B&&&&&&&&#Y^\n\
                  .JB&&&&&&&G!J&&&&&&&&&&&Y!YB###B5J??^\n\
                   ~??5GGG5?7P&&&&&&&&&&&&&#5JJJJJ5G&&#5^\n\
                 .J&&BPYYY5G&&&&&&&&&&&&&&&&&&&#&&&&&&&&#~\n\
                .Y&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&B^\n\
                !&&&&&&&&&&&&BG#&&&&&&&&&BJY#&&&&&&&&&&&&&P.\n\
               .5&&&&&&&&&&&#^ ?&&&&&&&&&5:^B&&&&&&&&&&&&&&Y.\n\
               ^#&&&&&&&&&&&&BPB$(HOTPINK)#BGGGGGGGBB$(SALMON)#&&&&&&&&&&&&&&&&J.\n\
              .5&&&&&&&&&&&&&$(HOTPINK)#BPPPP5PP55PPPPB$(SALMON)&&&&&&&&&&&&&&&&!\n\
              7&&&&&&&&&&&&&&$(HOTPINK)#PPPP?^5P!~PPPPG&$(SALMON)&&&#######&&&&&5.\n\
             .Y&&&&&#######&&&$(HOTPINK)BGPP55PPP5PPGB#$(SALMON)&&&#BBGBGBB##&&&B:\n\
              J&&&##BBBBBB##&&&&$(HOTPINK)#BBBBBB#PB$(SALMON)&&&&&##BGGPPGBB#&&&P.\n\
              :B&&#BBGPPGGB##&&&&#JYPPPJ?B&&&&&&#BBGGGBB##&&#!\n\
               ^G&&#BBGGGBB#&&&&&&#BPPGB&&&&&&&&########BBP!.\n\
                .?G########&&&&&&&&&&&&&&&&&&&&&&&&#G5YJJJYY5PY!.\n\
                   ^7J5GB#&&&&&&&&&&&&&&&&&&&&&&&&#YJPG##&&&&&@P.\n\
               :~!!777777?B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GJ:\n\
             .J#&&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBP5?!^.\n\
             .7B#&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&Y^.\n\
               .^~!777777Y#&&&&&&&&&&&&&&&&&&&&&&&&&&&?\n\
                        ~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&P.\n\
                        ^#&&&&&&&&&&&&&&&&&&&&&&&&&&&&G.\n\
                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~^\n\
				      $(NORMAL)I'm the piglosopher !"