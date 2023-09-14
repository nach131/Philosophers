# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ NAMES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

NAME		= philo

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ COLORS ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

GREEN		=\033[0;32m
BLUE 		=\033[0;34m
ORANGE	=\033[38;5;214m
RED			=\033[0;31m
YELLOW	=\033[0;33m
WHITE		=\033[0;37m

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ SANITIZER ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

# Address sanitizing flags
ASAN := -fsanitize=address -fsanitize-recover=address
ASAN += -fno-omit-frame-pointer -fno-common
# no psoportadas por High Sierra
# ASAN += -fsanitize=pointer-subtract -fsanitize=pointer-compare
# Technicaly UBSan but works with ASan
ASAN += -fsanitize=undefined
# Technicaly LSan but works with ASan
# ASAN += -fsanitize=leak
# Thread sanitizing flags
TSAN := -fsanitize=thread
# Memory sanitizing flags
MSAN := -fsanitize=memory -fsanitize-memory-track-origins

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ COMPILATE ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

CC			= gcc
AR 			= ar -rcs
RM			= rm -rf
MKDIR		= -mkdir -p
CFLAGS	= -Wall -Wextra -Werror -g3
LEAKS		= -fsanitize=address

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ DIRECTORIES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

INCLUDES 	= inc/
SRC_DIR 	= ./
OBJ_DIR 	= obj/
UTILS_DIR	= utils/

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ SOURCES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

MAIN_FILES	=	main
UTILS_FILES	= my_libft init_data my_libft2 processes clock waiting

SRC_MAIN_FILES	+=$(MAIN_FILES)
SRCS_MAIN = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAIN_FILES)))
OBJS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAIN_FILES)))
DEPS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_MAIN_FILES)))

SRC_UTILS_FILES	+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))
SRCS_UTILS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_UTILS_FILES)))
OBJS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_UTILS_FILES)))
DEPS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_UTILS_FILES)))

ALL_OBJS += $(OBJS_MAIN) $(OBJS_UTILS)
DEPS += $(DEPS_MAIN) $(DEPS_UTILS)

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ RULES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

$(OBJ_DIR)%.o : $(SRC_DIR)%.c Makefile
			@$(MKDIR) $(dir $@)
			@echo "$(ORANGE) Creado objeto de  ➟  $(BLUE)$< $(WHITE)"
			@$(CC) -MMD -MP $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME):	$(ALL_OBJS)
			@$(CC) $(CFLAGS) $(TSAN) $^ -o $@
			@echo "$(ORANGE) Compilando Ejecutable  ➟  $(RED)$@ $(WHITE)"

clean :
			@$(RM) $(OBJ_DIR) $(NAME)
			@echo "$(RED)\n ✗ Archivos objetos push_swap borrados.‼️\n$(WHITE)";

fclean : clean
			@$(RM) $(NAME)
			@echo "$(GREEN) Todo Super limpito...✌🏼 $(WHITE)" 

re: fclean all
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

reb: fclean 
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

norm:
			@norminette $(SRC_DIR) | grep -v Norme -B1 || true

-include $(DEPS)

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ Non-file targets ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

.PHONY: all clean fclean re norm