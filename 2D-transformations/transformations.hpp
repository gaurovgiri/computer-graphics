#ifndef __TRANSFORMATIONS__
#define __TRANSFORMATIONS__

#include <vector>

std::vector<std::vector<int>> translation(int tx, int ty);
std::vector<std::vector<int>> rotation(int deg);
std::vector<std::vector<int>> reflection(int x, int m);

std::vector<std::vector<int>> scaling(int sx, int sy);
std::vector<std::vector<int>> shearing(int shx, int shy);


#endif // __TRANSFORMATIONS__