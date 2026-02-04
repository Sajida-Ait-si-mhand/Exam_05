#include <stdio.h>
#include <stdlib.h>

typedef struct s_map 
{
    int rows;
    int columns;
    int height;
    int width;
    char empty;
    char obst;
    char full;
    char **map;
} t_map;

size_t my_strlen(char *str)
{
    int i = 0;
    while(str && str[i])
        i++;
    return i;
}

int my_atoi(char *str)
{
    int m = 0;
    int i = 0;
    while (str && str[i])
    {
        m *= 10;
        m += str[i] - '0';
        i++;
    }
    return m;
}
int parse_map(t_map *map, char *header)
{
    size_t len = my_strlen(header);
    if (len < 4)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }
    if (header[len - 1] == '\n')
        header[--len] = '\0';

    map->full = header[len - 1];
    map->obst = header[len - 2];
    map->empty= header[len - 3];
    len -= 3;
    header[len] = '\0';
    map->rows = my_atoi(header);
    
    if (map->rows <= 0 || map->empty == map->full || map->empty == map->obst || map->full == map->obst)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }
    return 0;
}

void free_map(t_map *map, char *line)
{
    for (int i = 0; i < map->height; i++)
        free(map->map[i]);
    free(map->map);
    if (line)
        free(line);
}

void free_da(int **arr, int size)
{
    if (!arr)
        return ;
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);
}
int read_map(t_map *map, FILE *file)
{
    map->width = 0;
    map->map = calloc(map->rows, sizeof(char *));
    char *line = NULL;
    size_t size = 0;
    for (int i = 0; i < map->rows; i++)
    {
        size_t br = getline(&line, &size, file);
        if (br <= 0)
        {
            free_map(map, line);
            return 1;
        }

        if (line[br - 1] == '\n')
            line[--br] = '\0';
        
        if (i == 0)
            map->width = br;
        else
        {
            if ((int) br != map->width)
            {
                free_map(map, line);
                return 1;
            }
        }
        map->map[i] = malloc(map->width + 1);
        if (!map->map[i])
        {
            free_map(map, line);
            return 1;
        }
        map->height++;
        for (int j = 0; j < map->width; j++)
        {
            if (line[j] != map->empty && line[j] != map->obst)
            {
                free_map(map, line);
                return 1;
            }
            map->map[i][j] = line[j];
        }
        map->map[i][map->width] = '\0';

    }
    free(line);
    return 0;
}

void fill_array(t_map *map)
{
    int **clone = calloc(map->rows, sizeof(int *));
    if (!clone) return ;
    int s = 0;
    for (int i = 0; i < map->height; i++)
    {
        clone[i] = malloc(map->width * sizeof(int));
        if (clone[i] == NULL)
            free_da(clone, i);
        s = i;
    }

    int best = 0;
    int best_y = 0;
    int best_x = 0;
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == map->obst)
                clone[y][x] = 0;
            else
            {
                if (x == 0 || y == 0)
                    clone[y][x] = 1;
                else
                {
                    int m = clone[y - 1][x];
                    if (m > clone[y - 1][x - 1]) m = clone[y - 1][x - 1];
                    if (m > clone[y][x - 1]) m = clone[y][x - 1];
                    clone[y][x] = 1 + m;
                }
            }
            if (clone[y][x] > best)
            {
                best = clone[y][x];
                best_y = y;
                best_x = x;
            }
        }
    }
    for (int y = best_y; y > best_y - best; y--)
    {
        for (int x = best_x; x > best_x - best; x--)
        {
            map->map[y][x] = map->full;
        }
    }
    free_da(clone, s);

}
int solve_file(FILE *file)
{
    t_map map = {0};
    char *header = NULL;
    size_t len = 0;
    size_t bytes_read;

    bytes_read = getline(&header, &len, file);
    if (bytes_read <= 0)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }
    if (parse_map(&map, header))
    {
        fprintf(stderr, "map error\n");
        free(header);
        return 1;
    }
    free(header);

    if (read_map(&map, file))
    {
        fprintf(stderr, "map error\n");
        return 1;
    }
    fill_array(&map);
    for (int i = 0; i < map.height; i ++)
    {
        fputs(map.map[i], stdout);
        fprintf(stdout, "\n");
    }
    free_map(&map, NULL);
    return 0;
}


int main(int ac, char **av)
{
    if (ac == 1)
        solve_file(stdin);
    else 
    {
        for (int i = 1; i < ac; i++)
        {
            FILE *f = fopen(av[i], "r");
            if (f == NULL)
                fprintf(stderr, "map error\n");
            else
            {
                solve_file(f);
                fclose(f);
            }
            if (i < ac - 1)
                fprintf(stdout, "\n");
        }
    }
    return 0;
}