#include <iostream>
#include <string>
using namespace std;

const char WALL = 'X';
const char OPEN = '.';
const char SEEN = 'o';
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

/*
 ------------------------PSEUDOCODE-----------------------
 If the start location is equal to the ending location, then we've
     solved the maze, so return true.
 Mark the start location as visited.
 For each of the four directions,
     If the location one step in that direction (from the start location)
             has no wall and is unvisited,
         then if calling pathExists starting from that location (and
                      ending at the same ending location as in the current
                      call) returns true,
                  then return true.
 Return false.
 */
class Coord;

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    if (sr == er && sc == ec)
        return true;
    
    // mark the start location as visited.
    maze[sr][sc] = SEEN;
    
    for (int i = 0; i < 4; i++) {
        int r = 0;
        int c = 0;
        if (i == NORTH)
            r--;
        else if (i == EAST)
            c++;
        else if (i == SOUTH)
            r++;
        else if (i == WEST)
            c--;
        
        if (maze[sr+r][sc+c] == OPEN) {
            if (pathExists(maze, nRows, nCols, sr+r, sc+c, er, ec))
                return true;
        }
    }
    
    return false;
}

class Coord {
  public:
    Coord(int r, int c) : m_r(r), m_c(c) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};
