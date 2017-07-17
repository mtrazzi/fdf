#ifndef GENERAL_H
# define GENERAL_H

# if defined(__linux__)
	#include "../lib/minilibx_linux/mlx.h"
# endif
# if defined(__APPLE__) && defined(__MACH__)
	#include "../lib/minilibx_mac/mlx.h"
# endif
#endif
