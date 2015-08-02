#include "lemin.h"

int main()
{
    t_salle     salle;
    char        *str;
    t_list      *list;
    t_status    status;
    char        **split;
    int         n;

    n = 0;
    list = NULL;
    status = BASIC;
    while (get_next_line(0, &str) > 0)
    {
        if (str == NULL || str[0] == '\0' || str[0] == '#')
        {
            if (str != NULL && str[0] && str[1] == '#' && ft_strequ(str + 2, "start"))
            {
                if (status != BASIC)
                {
                    ft_putstr("ERROR\n");
                    exit(1);
                }
                else
                    status = START;
            }
            else if (str != NULL && str[0] && str[1] == '#' && ft_strequ(str + 2, "end"))
            {
                if (status != BASIC)
                {
                    ft_putstr("ERROR\n");
                    exit(1);
                }
                else
                    status = END;
            }
            ft_strdel(&str);
            continue;
        }
        split = ft_strsplit(str, ' ');
        if (split != NULL)
        {
            if (split[0] == NULL)
            {
                free_tab(split);
                continue;
            }
            if ((split[1] != NULL && (split[2] == NULL || split[3] != NULL))
                || !ft_isnumber(split[1]) || !ft_isnumber(split[2]))
            {
                ft_putstr("ERROR\n");
                exit(1);
            }
            if (split[1] == NULL)
            {
                if (status != BASIC)
                {
                    ft_putstr("ERROR\n");
                    exit(1);
                }
                break;
            }
            ft_bzero((void*)&salle, sizeof(t_salle));
            salle.name = ft_strdup(split[0]);
            salle.status = status;
            salle.x = ft_atoi(split[1]);
            salle.y = ft_atoi(split[2]);
            salle.indice = n;
            n++;
            printf("%s\t(%d/%d)\t%d\n", salle.name, salle.x, salle.y, salle.indice);
            ft_lstaddnew(&list, (void*)&salle, sizeof(t_salle));
            free_tab(split);
            ft_strdel(&str);
            status = BASIC;
        }
    }
}

/*
    ##start
    1 23 3
    2 16 7
    #commentaire
    3 16 3
    4 16 5
    5 3 9
    6 1 0
    7 4 8
    ##end
*/