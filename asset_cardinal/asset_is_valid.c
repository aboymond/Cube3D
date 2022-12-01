#include "../cub3D.h"

int	asset_is_valid(t_asset *asset)
{
	if (asset_p_cardinal(asset) == -1 || asset_color(asset) == -1)
	{
		ft_printf("error: asset invalid\n");
		return (-1);
	}
	return (0);
}

int	asset_p_cardinal(t_asset *asset)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (i <= 3)
	{
		tmp = ft_strdup("");
		while (asset->asset_NSWE[i][j] != ' ')
		{
			tmp[j] = asset->asset_NSWE[i][j];
			printf("asset_p_cardinal: tmp[%d] = %c\n", j, tmp[j]);
			j++;
		}
		if (valid_p_cardinal_name(tmp, i) == -1)
			return (-1);
		j = 0;
		i++;
	}
	return (0);
}

int	valid_p_cardinal_name(char *str, int i)
{
	if (i == 0)
	{
		if (ft_strcmp(str, "NO") != 0)
		{
			free(str);
			return (-1);
		}
	}
	if (i == 1)
	{
		if (ft_strcmp(str, "SD") != 0)
		{
			free(str);
			return (-1);
		}
	}
	if (i == 2)
	{
		if (ft_strcmp(str, "WE") != 0)
		{
			free(str);
			return (-1);
		}
	}
	if (i == 3)
	{
		if (ft_strcmp(str, "EA") != 0)
		{
			free(str);
			return (-1);
		}
	}
	free(str);
	return (0);
}
