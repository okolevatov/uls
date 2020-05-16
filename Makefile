NAME = uls

LIBAR = ./libmx/libmx.a

DIROBJ = obj

LIB = ./libmx

FILES = main \
	mx_main_uls \
	mx_isfile \
	mx_creating_array \
	mx_output \
	mx_sort_args \
	mx_out_d_f \
	mx_flag_1 \
	mx_flag_m \
	mx_output_m \
	mx_cr_no_kol \
	mx_flag_S \
	mx_flag_r \
	mx_fill_flag \
	mx_printerr_c \
	mx_printerr \
	mx_fill_name \
	mx_flag_l \
	mx_sort_flags \
	mx_flag_t \
	mx_last_out \
	mx_make_path \
	mx_flag_a_f \
	mx_flag_A \
	mx_flag_p \
	mx_flag_d \
	mx_flagR \
	mx_numlen \
	mx_file_perm \
	mx_dec_to_hex \
	mx_file_size \
	mx_find_max_n \
	mx_find_max_z \
	mx_check_dop_l \
	mx_find_max_g \
	mx_find_max_gf \
	mx_find_max_s \
	mx_find_max_se \
	mx_count_arr \
	mx_total \
	mx_find_all \
	mx_mem_my \
	mx_max_all \
	mx_if_file_l \
	mx_num_hard \
	mx_file_owner \
	mx_mod_time \
	mx_file_group \
	mx_file_name \
	mx_creating_array_lena \
	mx_count_of_fil \
	mx_isfileR \
	mx_permcheck \
	mx_iflinkl \
	mx_error_13 \
	mx_helper_wh \
	mx_one_m \
	mx_fd_m \
	mx_helpR \
	mx_pchhelp \
	mx_creating_l \

SRC = $(addprefix src/, $(addsuffix .c,$(FILES)))

OUT = $(addsuffix .o, $(FILES))

INC = inc/pathfinder.h

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install
install:
	@make install -C $(LIB)
	@mkdir -p $(DIROBJ)
	@clang $(FLAGS) $(SRC) -c $(SRC) -I $(INC)
	@mv $(OUT) $(DIROBJ)
	@clang $(FLAGS) $(SRC) $(LIBAR) -o $(NAME) -I $(INC)

uninstall: clean
	@rm -rf $(NAME)
	@make uninstall -C $(LIB)
clean: 	
	@make clean -C $(LIB)
	@rm -rf $(DIROBJ)
	
reinstall: uninstall install 
