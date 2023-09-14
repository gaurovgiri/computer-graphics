#include "transformations.h"
#include <vector>

std::vector<std::vector<int>> translation(int tx, int ty)
{
    return std::vector<std::vector<int>>{{1,0,tx},{0,1,ty},{0,0,1}}; 
}
