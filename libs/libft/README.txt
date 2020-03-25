============================================================================================================================
Les 5 regles du developere:👍
1)je code avec le Q
2)tu code avec le Q
3)tous le monde code avec le Q
4)tout les informaticien son sur exploiter par rapport a un chinois
5)ON NE CODE JAMAIS MIEUX QU AVEC SON Q
============================================================================================================================
// --- SYSTEM / ERROR PARSING
//
✔️void error_exit(int p_error_num, char *msg); // Print au format "Error [%d] : %s avec le num et le msg voulu

int open_file(char *p_path, int p_mod);
int get_str(int fd, char **line);
int get_strsplit(int fd, char ***tab, char c);
✔️BOOL check_file_exist(char *path);
BOOL copy_file(char *src, char *dest);
void write_on_file(int fd, char *text);

/*
A METTRE DANS UNE GLOBABLE
int fd_log_file;
int line;
*/
void open_log_file(char *path, char *log_name);
void write_in_log(char *msg);
void close_log_file(char *msg);

//
//--- STRING ---
//
✔️char *_strnew(size_t p_len);

✔️char *_strdup(char *p_src);
✔️char *_strdup_c(char p_c);

✔️size_t _strlen(char *p_src);

✔️BOOL strcmp(char *p_src, char *p_target);
✔️BOOL strcmp_c(char *p_src, char p_target);

✔️char *strjoin(char *p_s1, char *p_s2);
✔️void str_add_front(char *p_front, char **back);
✔️void str_add_back(char **front, char *p_back);

✔️char **strsplit(char *p_src, char p_delim);
✔️void strcpy(char *p_src, char *dest);
✔️char *strsub(char *p_src, size_t p_start, size_t p_);//len ou end, au choix

//
//--- CONVERT ---
//
✔️int atoi(char *p_src);

✔️char *itoa_base(long long p_value, char *p_base);
✔️char *itoa(long long p_value); // -> concidere un int
✔️char *itoa_deci(long long p_value); // -> concidere comme un unsigned int
✔️char *itoa_hexa(long long p_value); // -> base 16
✔️char *itoa_octa(long long p_value); // -> base 8

char *ftoa(float p_value, size_t p_precision);
// 1) on recup la valeur de devant via un cast en int
// 2) on retire l'int au float pour avoir juste la virgule
// 3) on multiple par 10 jusqu'a avoir la precision voulue (limitez la precision a 12 par exemple)

float round(float p_value);
✔️float floor(float p_value);
✔️float roof(float p_value);
int round_i(float p_value);
✔️int floor_i(float p_value);
✔️int roof_i(float p_value);
✔️float degree_to_radian(float p_degree);
✔️float radian_to_degree(float p_radian);

//
// --- PART GRAPHIQUE ---
//
// DANGER - IL FAUT PENSER A AVOIR UNE EXTERN DE TYPE T_APPLICATION POUR LE GRAPHISME
✔️void draw_point(t_color p_color, t_vector2i center, int width);
✔️void draw_line(t_color p_color, t_vector2i p1, t_vector2i p2);
✔️void draw_rectangle(t_color p_color, t_vector2i pos, t_vector2i size);
✔️void fill_rectangle(t_color p_color, t_vector2i pos, t_vector2i size);
✔️void  draw_panel(t_panel p_panel);
✔️void  draw_button(t_button p_button);
void draw_centred_rectangle(t_color p_color, t_vector2i pos, t_vector2i size);
void fill_centred_rectangle(t_color p_color, t_vector2i pos, t_vector2i size);
int draw_text(char *text, t_vector2i coord, int size, int color);
int draw_centred_text(char *text, t_vector2i coord, int size, int color);

//
// --- PARTIE MATHEMATIQUE / ALGORYTHMN
//
✔️t_vector2i_list calc_line_2di(t_vector2i p_a, t_vector2i p_b);
✔️t_vector2_list calc_line_2d(t_vector2 p_a, t_vector2 p_b);

//
// --- LISTE INFINIE ---
//
✔️t_vector2 **vector2_tab_new(size_t nb);
✔️t_vector2 *vector2_array_new(size_t nb);
✔️void vector2_tab_cpy(t_vector2 **old, t_vector2 **new);
✔️static size_t vector2_list_calc_line(t_vector2_list *list, size_t index);
✔️static size_t vector2_list_calc_elem(t_vector2_list *list, size_t index);
✔️t_vector2_list create_vector2_list(size_t p_push_size);
✔️t_vector2_list *malloc_vector2_list(size_t p_push_size);
✔️void destroy_vector2_list(t_vector2_list to_delete);
✔️void free_vector2_list(t_vector2_list *to_free);
✔️void vector2_list_push_back(t_vector2_list *list, t_vector2 to_add);
✔️t_vector2 vector2_list_at(t_vector2_list *list, size_t index);
✔️void vector2_list_clear(t_vector2_list *list);
✔️void print_vector2_list(t_vector2_list *list);

// DANGER ----- DANGER ----- DANGER : toutes les fonctions de vector2i_list sont exactement les meme que celle des vector2
t_vector2i **vector2i_tab_new(size_t nb);
t_vector2i *vector2i_array_new(size_t nb);
void vector2i_tab_cpy(t_vector2i **old, t_vector2i **new);
static size_t vector2i_list_calc_line(t_vector2i_list *list, size_t index);
static size_t vector2i_list_calc_elem(t_vector2i_list *list, size_t index);
t_vector2i_list create_vector2i_list(size_t p_push_size);
t_vector2i_list *malloc_vector2i_list(size_t p_push_size);
void destroy_vector2i_list(t_vector2i_list to_delete);
void free_vector2i_list(t_vector2i_list *to_free);
void vector2i_list_push_back(t_vector2i_list *list, t_vector2i to_add);
t_vector2i vector2i_list_at(t_vector2i_list *list, size_t index);
void vector2i_list_clear(t_vector2i_list *list);
void print_vector2i_list(t_vector2i_list *list);

t_color **color_tab_new(size_t nb);
t_color *color_array_new(size_t nb);
void color_tab_cpy(t_color **old, t_color **new);
static size_t color_list_calc_line(t_color_list *list, size_t index);
static size_t color_list_calc_elem(t_color_list *list, size_t index);
✔️t_color_list create_color_list(size_t p_push_size);
✔️t_color_list *malloc_color_list(size_t p_push_size);
✔️void destroy_color_list(t_color_list to_delete);
✔️void free_color_list(t_color_list *to_free);
void color_list_push_back(t_color_list *list, t_color to_add);
t_color color_list_at(t_color_list *list, size_t index);
void color_list_clear(t_color_list *list);
void print_color_list(t_color_list *list);

int **int_tab_new(size_t nb);
int *int_array_new(size_t nb);
void int_tab_cpy(int **old, int **new);
static size_t int_list_calc_line(int_list *list, size_t index);
static size_t int_list_calc_elem(int_list *list, size_t index);
int_list create_int_list(size_t p_push_size);
int_list *malloc_int_list(size_t p_push_size);
void destroy_int_list(int_list to_delete);
void free_int_list(int_list *to_free);
void int_list_push_back(int_list *list, int to_add);
int int_list_at(int_list *list, size_t index);
void int_list_clear(int_list *list);
void print_int_list(int_list *list);

float **float_tab_new(size_t nb);
float *float_array_new(size_t nb);
void float_tab_cpy(float **old, float **new);
static size_t float_list_calc_line(float_list *list, size_t index);
static size_t float_list_calc_elem(float_list *list, size_t index);
float_list create_float_list(size_t p_push_size);
float_list *malloc_float_list(size_t p_push_size);
void destroy_float_list(float_list to_delete);
void free_float_list(float_list *to_free);
void float_list_push_back(float_list *list, float to_add);
float float_list_at(float_list *list, size_t index);
void float_list_clear(float_list *list);
void print_float_list(float_list *list);
