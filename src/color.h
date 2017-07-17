#ifndef COLOR_H
# define COLOR_H


# define C_WHITE		0xFFFFFF
# define C_WHITE1		0xF2F2F2
# define C_WHITE2		0xF3F3F3

# define C_BLACK		0x000000
# define C_BLACK1		0x0C0C0C
# define C_BLACK2		0x262626

# define C_GREEN		0x008000
# define C_GREEN1		0x001900
# define C_GREEN2		0x004C00
# define C_GREEN3		0x006600
# define C_GREEN4		0x007F00
# define C_GREEN5		0x009900
# define C_GREEN6		0x32AD32

# define C_RED			0xFF0000
# define C_RED1			0x660000
# define C_RED2			0x990000
# define C_RED3			0xB20000
# define C_RED4			0xE50000
# define C_RED5			0xFF1919
# define C_RED6			0xFF4C4C


# define C_YELLOW		0xFFFF00
# define C_YELLOW1		0x7F7F00
# define C_YELLOW2		0xB2B200
# define C_YELLOW3		0xE5E500
# define C_YELLOW4		0xFFFF32
# define C_YELLOW5		0xFFFF66
# define C_YELLOW6		0xFFFF99


# define C_BLUE			0x0000FF
# define C_BLUE1		0x00004C
# define C_BLUE2		0x00007F
# define C_BLUE3		0x0000B2
# define C_BLUE4		0x0000E5
# define C_BLUE5		0x3232FF
# define C_BLUE6		0x6666FF

// Misc colors
# define C_PURPLE		0x693278
# define C_MAGENTA		0xFF0066
# define C_CYAN			0x14BFB2
# define C_BROWN		0x8B3A3A
# define C_ORANGE		0xF37736
# define C_AMBER		0xF37736
# define C_VIOLET		0xEE82EE
# define C_GOLD			0xFFD700
# define C_AZUR			0x007FFF
# define C_BEIGE		0xF5F5DC
# define C_BELGE		0xF5F5DC
# define C_BRONZE		0x88540B
# define C_CAMEL		0xC19A6B
# define C_CANARY		0xFFFF99
# define C_CARDINAL		0xC41E3A
# define C_COLA			0x3C3024
# define C_LYME			0x9EFD38
# define C_FUCHSIA		0xFF00FF
# define C_GRAY			0xBFBFBF




typedef struct	color  // Converts colors
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}				t_color;

t_color		get_color(int r, int g, int b, int a);

#endif
