#include "../cube3d.h"

void	compt_map(char *args, t_scene *scene)
{
	char	*tmp;
	int		fd;
	int		haut;
	int		j;

	haut = 0;
	j = 0;

	fd = open(args, O_RDONLY);
	if (init_asset(args, scene) != 1)
		return ;
	printf("asset = %s\n", scene->asset.asset_NSWE[0]);
	asset_is_valid(&scene->asset);
	while (j < scene->asset.cmpt_asset_tab)
	{
		get_next_line(fd);
		j++;
	}
	tmp = get_next_line(fd);
	haut++;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		haut++;
	}
	close(fd);
	callocmap(scene, haut);
	init_tab_map(args, scene, haut);
}

void	init_tab_map(char *args, t_scene *scene, int haut)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(args, O_RDONLY);
	while (j < scene->asset.cmpt_asset_tab)
	{
		get_next_line(fd);
		j++;
	}
	scene->map.tab_map[i] = get_next_line(fd);
	i++;
	while (i < haut)
	{
		scene->map.tab_map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	map_is_close(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	while (scene->map.tab_map[i])
	{
		j = 0;
		while (scene->map.tab_map[i][j])
		{
			check_wall(scene, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_wall(t_scene *scene, int i, int j)
{
	//printf("i = %d, j = %d\n", i, j);
	if (scene->map.tab_map[0][j] == '0' || scene->map.tab_map[ft_tablen(scene->map.tab_map) - 1][j] == '0')
		printf("error map '0' !\n");
	else if (scene->map.tab_map[i][0] == '0' || scene->map.tab_map[i][(int)ft_strlen(scene->map.tab_map[i] - 1)] == '0')
	{
		printf("error map '0' !\n");
	}
	else if (scene->map.tab_map[i][j] == '0')
	{
		if (scene->map.tab_map[i - 1][j] == ' ' || scene->map.tab_map[i + 1][j] == ' ' || scene->map.tab_map[i][j - 1] == ' ' || scene->map.tab_map[i][j + 1] == ' ')
			printf("error map, i = %d, j = %d ' ' \n", i, j);
	}

	return (0);
}