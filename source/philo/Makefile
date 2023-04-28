# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ NAMES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

NAME		= philo
# NAME_BONUS		= philo_bonus

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

# ▖▖▖▖▖▖▖▖▖▖▖▖▖▖ BONUS ▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖#

# SRC_DIR_BONUS 	= philo_bonus/
# OBJ_DIR_BONUS 	= obj_bonus/
# UTILS_DIR_BONUS	= utils_bonus/

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ SOURCES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#


MAIN_FILES	=	main
UTILS_FILES	= file_utils my_libft 

SRC_MAIN_FILES	+=$(MAIN_FILES)
SRCS_MAIN = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAIN_FILES)))
OBJS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAIN_FILES)))
DEPS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_MAIN_FILES)))

SRC_UTILS_FILES	+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))
SRCS_UTILS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_UTILS_FILES)))
OBJS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_UTILS_FILES)))
DEPS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_UTILS_FILES)))

# ▖▖▖▖▖▖▖▖▖▖▖▖▖▖ BONUS ▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖#

# MAIN_FILES_BONUS	=	main_bonus
# UTILS_FILES_BONUS	= ctrl_bonus init_bonus stack_bonus swap_bonus push_bonus \
#  rotate_bonus reverse_bonus
 
# SRC_MAIN_FILES_BONUS	+=$(MAIN_FILES_BONUS)
# SRC_UTILS_FILES_BONUS	+=$(addprefix $(UTILS_DIR_BONUS),$(UTILS_FILES_BONUS))

# SRCS_MAIN_BONUS = $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_MAIN_FILES_BONUS)))
# OBJS_MAIN_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(addsuffix .o, $(SRC_MAIN_FILES_BONUS)))
# DEPS_MAIN_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(addsuffix .d, $(SRC_MAIN_FILES_BONUS)))
# SRCS_UTILS_BONUS = $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_UTILS_FILES_BONUS)))
# OBJS_UTILS_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(addsuffix .o, $(SRC_UTILS_FILES_BONUS)))
# DEPS_UTILS_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(addsuffix .d, $(SRC_UTILS_FILES_BONUS)))
# DEPS += $(DEPS_MAIN) $(DEPS_UTILS) $(DEPS_ORDER) $(DEPS_UTILS_BONUS)

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ RULES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

$(OBJ_DIR)%.o : $(SRC_DIR)%.c Makefile
			@$(MKDIR) $(dir $@)
			@echo "$(ORANGE) Creado objeto de  ➟  $(BLUE)$< $(WHITE)"
			@$(CC) -MMD -MP $(CFLAGS) -I $(INCLUDES) -c $< -o $@

# $(OBJ_DIR_BONUS)%.o : $(SRC_DIR_BONUS)%.c Makefile
# 			@$(MKDIR) $(dir $@)
# 			@echo "$(ORANGE) Compilando objetos  ➟  $(BLUE)$< $(WHITE)"
# 			@$(CC) -MMD -MP $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME)

# bonus: $(NAME_BONUS)

$(NAME):	$(OBJS_MAIN) $(OBJS_UTILS) 
			@$(CC) $(CFLAGS) $^ -o $@
			@echo "$(ORANGE) Compilando Ejecutable  ➟  $(RED)$@ $(WHITE)"

# $(NAME_BONUS):	$(OBJS_MAIN_BONUS) 
# 			@$(CC) $(CFLAGS)  $(LIBSFT) $^ -o $@
# 			@echo "$(ORANGE) Compilando Ejecutable  ➟  $(RED)$@ $(WHITE)"

clean :
			@$(RM) $(OBJ_DIR) $(NAME)
# @$(RM) $(OBJ_DIR_BONUS)
			@echo "$(RED)\n ✗ Archivos objetos push_swap borrados.‼️\n$(WHITE)";

fclean : clean
			@$(RM) $(NAME)
# @$(RM) $(NAME_BONUS)
			@echo "$(GREEN) Todo Super limpito...✌🏼 $(WHITE)" 

re: fclean all
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

reb: fclean bonus
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

norm:
			@norminette $(SRC_DIR) | grep -v Norme -B1 || true

norm_bonus:
			@norminette $(SRCS_MAIN_BONUS) $(SRCS_UTILS_BONUS) $(INCLUDES) | grep -v Norme -B1 || true

-include $(DEPS)

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ Non-file targets ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

.PHONY: all clean fclean re norm bonus norm_bonus
