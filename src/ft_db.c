#include "ft_db.h"

void    all_puts(t_ent *ent, FILE *fp)
{
        fputs(ent->key, fp);
        fputc('\n', fp);
        while (*(ent->data))
		{
			fputs(*(ent->data), fp);
			fputc(30, fp);
			ent->data++;
		}
        fputc('\n', fp);
}

void    db_2file(t_db *db)
{
    FILE    *fp;
    t_ent   *t;

    fp = fopen("derpbase.db", "w+");
    t = db->ents;
    while (t)
    {
        all_puts(t, fp);
        t = t->next;
    }
    fclose(fp);
}

void    print_ent(t_db *db, char *key)
{
    t_ent   *t;

    t = db->ents;
	t = t->next;
    while (t && ft_strcmp(t->key, key) != 0)
        t = t->next;
    if (t)
	{
		printf("For key: %s\nData is:\n", t->key);
		while (t->data)
		{
			printf("%s\n", *(t->data));
			t->data++;
		}
	}
    else
        printf("There was no entry for %s\n", key);
}

void    print_all(t_db *db)
{
    t_ent   *t;

    t = db->ents;
    while (t)
    {
        printf("For key: %s\nData is: %s\n", t->key, *t->data);
        t = t->next;
    }
}

void    add_ent(t_db *db, char *key, char *data)
{
    t_ent   *t;

    t = db->ents;
    while (t->next)
		if (strcmp(t->key, key) == 0)
		{
			ft_putendl("Key already exists, not adding");
			return ;
		}
        t = t->next;
    t->next = init_ent(key, data);
}

void	edit_ent(t_db db, char *key, char *data)
{
	t_ent *t = DE;

	while (strcmp(t->key, key) != 0)
		t = t->next;
	if (t)
		*t->data = data  //but the last thing in array or first?
	else
		print_f("You tried to edit an entry that wasn't there Bill..../n");
}

t_db	*init_db(FILE *fp)
{
	t_db	*db;
	char	*tmp;
	char	*tmpk;
	char	**tmpd;
	int		k = 1;

	if (!(db = ft_memalloc(sizeof(t_db))))
		return (NULL);
	if (!(DE = ft_memalloc(sizeof(t_ent))))
		return (NULL);
	if (fp)
	{
		while (get_next_line(fileno(fp), &tmp) > 0)
		{
//			ft_putnbr(k);
			if (k == 1)
			{
				k = 0;
				tmpk = ft_strdup(tmp);
			}
			else
			{
				DE->dlen = ft_count_words(tmp, 30);
				tmpd = ft_strsplit(ft_strdup(tmp), 30);
				add_ent(db, tmpk, tmpd);
				k = 1;
			}
		}
	}
	return (db);
}

t_ent   *init_ent(char *key, char *data)
{
    t_ent   *ent;

    if(!(ent = (t_ent*)malloc(sizeof(t_ent))))
        return (NULL);
    if(ent)
    {
        ent->key = key;
        ent->data = data;
        ent->next = NULL;
    }
    return (ent);
}

int    check_query(int ac, char **av, t_db *db)
{
    int i = 1;
	int c = 0;
	int	k = 0;
// fix so doesnt seg fault when increments past AV b/c of i++
    while (i < ac)
    {
        if (strcmp(av[i], "help") == 0 && i++)
		{
			printf("help");
//			print_help();
        }
		else if (strcmp(av[i], "print_all") == 0 && i++)
		{
			printf("print all");
			print_all(db);
		}
		else if (strcmp(av[i], "print") == 0 && i++)
            print_ent(db, av[i++]);
	//	else if (strcmp(av[i], "add_to" == 0 && i++)
	//		{

        else if (strcmp(av[i], "add") == 0 && i++)
        {
			printf("adding\n");
			DE->dlen += ft_atoi(av[i++]);
			k = i;
			while (c--)
				add_ent(db, av[k], av[i++]);
        }
        else if (strcmp(av[i], "edit") == 0 && i++)
        {
			printf("edIt");
           // edit_ent(db, av[i], av[i + 1]);
           // i += 2;
        }
        else if (strcmp(av[i], "delete") == 0 && i++)
            printf("delete");//delete_ent(db, av[i++]);
        else if (strcmp(av[i], "delete_all") == 0 && i++)
            printf("delete all");//delete_all(db);
        else
		{
         	i++;
		 	printf("error");//print_err();
			return (1);
    	}
	}
	return (0);
}




int main(int ac, char** av)
{
    t_db    *db;

    FILE *fp = fopen("derpbase.db", "r+");
	db = init_db(fp);
	fclose(fp);
	if (ac == 1)
        printf("%s\n", "use -help for help");
    else
    {
 //		print_all(db);
     if(check_query(ac, av, db) == 0)
		printf("done");   
       // db = init_db(fp);
      //  ft_putendl("get here?");
        db_2file(db);

    }
    return(0);
}


