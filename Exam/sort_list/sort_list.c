typedef struct s_list t_list;

struct s_list {
    int data;
    t_list *next;
};

int ascending(int a, int b)
{
        return (a <= b);
}
t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *list = lst;
    int swap = 0;
    while (lst->next != 0)
    {
        if((cmp)(lst->data, lst->next->data) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = list;
        }
        else
            lst = lst->next;
    }
    
    return list;
}