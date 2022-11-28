#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"

# if defined(__APPLE__) && defined(__MACH__)
#  include "./src_mlx/mlx/mlx.h"
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  include "./src_mlx/mlx-linux/mlx.h"
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}		t_mlx;
typedef struct s_player
{
	int		pos_x;
	int		pos_y;
}		t_player;

typedef struct s_asset
{
	char		**asset_NSWE;
	char		**asset_color;
	int			cmpt_asset;
	int			cmpt_asset_tab;
	int			int_NSWE;
	int			int_color;
}		t_asset;
typedef struct s_map
{
	void		*img;
	char		**tab_map;
}		t_map;

typedef	struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
} t_img;

typedef struct s_scene
{
	t_map		map;
	t_asset		asset;
	t_player	player;
	t_img		img;
	t_mlx		mlx;
} t_scene;

/*
manage_assets(t_struct *asset)
{
	asset.int_color = 0;
}
t_map *map;
map.asset.int_color = 1;
manage_assets(&map->assets)
//int_color == 0


typedef struct	s_map
{
	char **data;
	int	height;
	int widht;
} t_map;
*/

/////////// INIT ///////////
void	init(t_scene *scene);
void	init_struct_map(t_scene *scene);
void	init_player(t_scene *scene);
void	init_asset_var(t_scene *scene);
int		init_asset_tab(t_scene *scene, char *line);
int		init_asset(char *args, t_scene *scene);
int		check_asset(t_scene *scene, char *line);
void	callocmap(t_scene *scene, int haut);

////////// ERROR //////////
int		erreur_args(int argc, char **argv);
int		check_arg(char *c);
int		p_error(char *error);

////////// INIT MAP //////////
void	compt_map_haut(char *args, t_scene *scene);
void	compt_map(char *args, t_scene *scene, int haut);
void	init_tab_map(char *args, t_scene *scene, int *larg, int haut);
int		map_is_close(t_scene *scene);
int		check_wall(t_scene *scene, int i, int j);

////////// FREE //////////
int		free_main(t_scene *scene);

#endif
