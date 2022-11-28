#include "../cube3d.h"

int	init_asset(char *args, t_scene *scene)
{
	char	*tmp;
	int		fd;

	fd = open(args, O_RDONLY);
	tmp = get_next_line(fd);
	if (check_asset(scene, tmp) == 1)
	{
		close (fd);
		return (1);
	}
	scene->asset.cmpt_asset_tab++;
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(fd);
		if (check_asset(scene, tmp) == 1)
		{
			close (fd);
			return (1);
		}
		scene->asset.cmpt_asset_tab++;
	}
	close (fd);
	return (0);
}

int check_asset(t_scene *scene, char *line)
{
	if (init_asset_tab(scene, line) == 1)
	{
		if (!scene->asset.asset_color || !scene->asset.asset_NSWE || scene->asset.cmpt_asset != 6)
		{
			p_error("Error: \n\tMap asset = NULL !");
		}
		return (1);
	}
	return (0);
}

int	init_asset_tab(t_scene *scene, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("NSWE", line[i]))
		{
			scene->asset.asset_NSWE[scene->asset.int_NSWE] = line;
			scene->asset.int_NSWE++;
			scene->asset.cmpt_asset++;
			return (0);
		}
		else if (ft_strchr("FC", line[i]))
		{
			scene->asset.asset_color[scene->asset.int_color] = line;
			scene->asset.int_color++;
			scene->asset.cmpt_asset++;
			return (0);
		}
		else if (ft_strchr("01", line[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}