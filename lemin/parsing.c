#include "lemin.h"

static void ft_error(void)
{
    ft_putstr("ERROR\n");
    exit(1);
}

int     lin_parse_comm(char *str, t_status *status)
{
    if (str == NULL || str[0] == '\0' || str[0] == '#')
    {
        if (str != NULL && str[0] && str[1] == '#' && ft_strequ(str + 2, "start"))
        {
            if (*status != BASIC)
                ft_error();
            else
                *status = START;
        }
        else if (str != NULL && str[0] && str[1] == '#' && ft_strequ(str + 2, "end"))
        {
            if (*status != BASIC)
                ft_error();
            else
                *status = END;
        }
        return (1);
    }
    return (0);
}

static lin_parse_fill(t_status *status, char **split, t_list *list)
{
    static int  n = 0;
    t_salle     salle;

    ft_bzero((void*)&salle, sizeof(t_salle));
    salle.name = ft_strdup(split[0]);
    salle.status = *status;
    salle.x = ft_atoi(split[1]);
    salle.y = ft_atoi(split[2]);
    salle.indice = n;
    n++;
    printf("%s\t(%d/%d)\t%d\t%d\n", salle.name, salle.x, salle.y, salle.indice, *status);
    ft_lstaddnew(&list, (void*)&salle, sizeof(t_salle));
    *status = BASIC;
}

char    *lin_parse_first(t_list *list)
{
    char        *str;
    t_status    status;
    char        **split;

    status = BASIC;
    while ((split = NULL) || get_next_line(0, &str) > 0)
    {
        if (!lin_parse_comm(str, &status) && (split = ft_strsplit(str, ' ')) &&
            split[0])
        {
            if ((split[1] && (split[2] == NULL || split[3] != NULL))
                || !ft_isnumber(split[1]) || !ft_isnumber(split[2]))
                ft_error();
            if (split[1] == NULL)
            {
                if (status != BASIC)
                    ft_error();
                return (str);
            }
            lin_parse_fill(&status, split, list);
        }
        free_tab(split);
        ft_strdel(&str);
    }
}

int main(void)
{
    t_list  *list;
    
    list = NULL;
    lin_parse_first(list);
    return (0);   
}