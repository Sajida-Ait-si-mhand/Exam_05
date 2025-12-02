#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
** Count how many of the 8 surrounding cells (neighbors)
** around (x, y) are alive.
*/
static int count_neighbors(char *b, int w, int h, int x, int y)
{
	int c = 0;

	for (int dy = -1; dy <= 1; dy++)         // look at rows above, same, below
		for (int dx = -1; dx <= 1; dx++)     // look at columns left, same, right
		{
			if (dx == 0 && dy == 0)
				continue;                    // skip the cell itself

			int nx = x + dx;                 // neighbor X position
			int ny = y + dy;                 // neighbor Y position

			// only count if inside the grid
			if (nx >= 0 && nx < w && ny >= 0 && ny < h)
				if (b[ny * w + nx])          // if that cell is alive
					c++;
		}
	return c;
}

/*
** Run the Game of Life simulation for 'iter' generations.
** Each generation creates a new temporary board, applies the rules,
** then replaces the old one.
*/
static void simulate(char *b, int w, int h, int iter)
{
	while (iter--)  // repeat for the number of iterations
	{
		char *n = calloc(w * h, 1); // new empty board

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
			{
				int nb = count_neighbors(b, w, h, x, y);
				int alive = b[y * w + x]; // is the cell currently alive?

				// Apply Conway's Game of Life rules:
				if (alive && (nb == 2 || nb == 3))
					n[y * w + x] = 1;     // stays alive
				else if (!alive && nb == 3)
					n[y * w + x] = 1;     // dead cell becomes alive
				else
					n[y * w + x] = 0;     // otherwise stays or becomes dead
			}

		// Copy new board into old one
		for (int i = 0; i < w * h; i++)
			b[i] = n[i];
		free(n); // free temporary board
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;

	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int iter = atoi(av[3]);

	char *b = calloc(w * h, 1); // board, all cells dead initially
	int x = 0, y = 0;           // pen position
	int draw = 0;               // pen up/down
	char c;

	// read one character at a time from stdin
	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			draw = !draw; // toggle drawing mode
		else if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < h - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < w - 1)
			x++;

		if (draw)
			b[y * w + x] = 1; // mark current cell alive
	}

	// run the life simulation
	simulate(b, w, h, iter);

	// print final board
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
			putchar(b[y * w + x] ? 'O' : ' ');
		putchar('\n');
	}

	free(b);
	return 0;
}
