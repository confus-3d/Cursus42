#include <mlx.h>

#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//keycodes de cada tecla especifica, https://eastmanreference.com/complete-list-of-applescript-key-codes
int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
/*
int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}
*/
int	main(void)
{
	t_vars	vars;
	t_data	img;
	int		x;
	int		y;

	x = 0;
	y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (y < 500)
	{
		while (x < 500)
		{
			my_mlx_pixel_put(&img, x + 5, y + 5, 0x00FF0000);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
//	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);



}

