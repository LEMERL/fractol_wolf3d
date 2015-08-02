#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
typedef enum        e_status
{
    BASIC,
    START,
    END,
}                   t_status;

typedef struct      s_salle
{
	char			*name;
	int				x;
	int				y;
	int             indice;
    t_status        status;
	t_list      	*link;
}				    t_salle;

#endif