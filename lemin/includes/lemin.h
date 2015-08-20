#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef enum		e_status
{
	BASIC,
	START,
	END,
}					t_status;

typedef struct		s_salle
{
	char			*name;
	int				x;
	int				y;
	int				indice;
	t_status		status;
	int				used;
	t_list			*link;
	int				way_value;
	int				simple;
}					t_salle;

typedef struct		s_ant
{
	int				which_one;
	int				which_room;
	int				bol_end;
	struct s_ant	*next;
}					t_ant;

void				resolve(t_list *list, int ant);
int					get_ant(void);
int					set_ant(int modif);

#endif
