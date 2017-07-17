#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "mlx.h"

typedef struct  s_env
{
    void    *mlx;
    void    *win;
}               t_env;

void    draw(void *mlx, void *win)
{
    int     x;
    int     y;

    y = 0;
    while (y < 800)
    {
        x = 0;
        while (x < 800)
        {
            if ((x % 100) < 5)
                mlx_pixel_put(mlx, win, x, y, ((y % 50) < 5 ? 0xFF0000 : 0x00FF00));
            else
                mlx_pixel_put(mlx, win, x, y, ((y % 40) < 5 ? 0x0000FF : 0xFF00FF));
            x++;
        }
        y++;
    }

}

int     expose_hook(t_env *e)
{
    draw(e->mlx, e->win);
    return (0);
}

int     key_hook(int keycode, t_env *e)
{
    printf("keycode %d\n", keycode);
    if (keycode == 65307)
        exit(EXIT_FAILURE);
    return (0);
}

int     mouse_hook(int button, int x, int y, t_env *s)
{
    printf("mouse : %d (%d:%d)\n", button, x, y);
    return (0);
}

int main(int ac, char **av)
{
    t_env   e;

    
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, 800, 800, "this is my window");
    mlx_key_hook(e.win, key_hook, &e);
    mlx_expose_hook(e.win, expose_hook, &e);
    mlx_mouse_hook(e.win, mouse_hook, &e);
    mlx_loop(e.mlx);
}
