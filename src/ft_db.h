#ifndef FT_DB_H
# define FT_DB_H
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>
# include "libft.h"
# define DE db->ents
# define 


typedef struct	s_ent
{
char			*key;
char			**data;
size_t			dlen;
struct s_ent	*next;
}				t_ent;

typedef struct	s_db
{
size_t			entry_count;
t_ent			*ents;
}				t_db;

FILE		*init_db_file(void);
t_db		*init_db(FILE *fp);
t_ent		*init_ent(char *key, char **data);
void		print_help(void);
void		print_err(void);
int		check_query(int ac, char **av, t_db *db);
void		print_all(t_db *db);
void		print_ent(t_db *db, char *key);
void		add_ent(t_db *db, char *key, char **data);
void		edit_ent(t_db *db, char *key, char **data);
void		delete_ent(t_db *db, char *key);
void		delete_all(t_db *db);
void		db_2file(t_db *db);
void		all_puts(t_ent *ent, FILE *fp);
void		*db_memalloc(size_t size);
size_t		db_numlen(intmax_t nb, int bse);
char		*db_itoa(intmax_t nbg);

#endif
