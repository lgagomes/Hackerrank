/*
https://www.hackerrank.com/challenges/queens-attack-2/problem

You will be given a square chess board with one queen and a number of obstacles placed on
it. Determine how many squares the queen can attack.

A queen is standing on an n x n chessboard. The chess board's rows are numbered from 1 to 'n',
going from bottom to top. Its columns are numbered from 1 to 'n', going from left to right.
Each square is referenced by a tuple, (r,c), describing the row, 'r', and column, 'c', where
the square is located.

The queen is standing at position (rq,cq). In a single move, she can attack any square in any of
the eight directions (left, right, up, down, and the four diagonals). In the diagram below, the
'O' denote all the cells the queen can attack from (4,4)

8 | | | | | | | |O|
7 |O| | | | | |O| |
6 | |O| | | |O| | |
5 | | |O| |O| | | |
4 | | | |Q| | | | |
3 | | |O| |O| | | |
2 | |O| | | |O| | |
1 |O| | | | | |O| |
   1 2 3 4 5 6 7 8

There are obstacles on the chessboard, each preventing the queen from attacking any square beyond it
on that path. For example, an obstacle at location (3,5) in the diagram above prevents the queen
from attacking cells (3,5), (2,6) and (1,7).

8 | | | | | | | |O|
7 |O| | | | | |O| |
6 | |O| | | |O| | |
5 | | |O| |O| | | |
4 | | | |Q| | | | |
3 | | |O| |X| | | |
2 | |O| | | | | | |
1 |O| | | | | | | |
   1 2 3 4 5 6 7 8

Given the queen's position and the locations of all the obstacles, find and print the number of squares
the queen can attack from her position at (rq,cq).

Input Format
The first line contains two space-separated integers 'n' and 'k', the length of the board's sides and the
number of obstacles.
The next line contains two space-separated integers 'rq' and 'cq', the queen's row and column position.
Each of the next 'k' lines contains two space-separated integers r[i] and c[i], the row and column position of
obstacle[i]

Constraints
0 <= n <= 10^5
0 <= k <= 10^5
A single cell may contain more than one obstacle.
There will never be an obstacle at the position where the queen is located.

Subtasks
For 30% of the maximum score:
0 <= n <= 100
0 <= k <= 100

For 55% of the maximum score:
0 <= n <= 1000
0 <= k <= 10^5

Output Format
Print the number of squares that the queen can attack from position (rq,cq).

Sample Input 0
4 0
4 4

Sample Output 0
9

Explanation 0

The queen is standing at position (4,4) on a 4x4 chessboard with no obstacles:

4 |O|O|O|Q|
3 | | |O|O|
2 | |O| |O|
1 |O| | |O|
   1 2 3 4

Sample Input 1
5 3
4 3
5 5
4 2
2 3

Sample Output 1
10

Explanation 1
The queen is standing at position (4,3) on a 5x5 chessboard with k = 3 obstacles:

5 | | |O| |X|
4 | |X|Q|O|O|
3 | |O|O|O| |
2 |O| |X| |O|
1 | | | | | |
   1 2 3 4 5

The number of squares she can attack from that position is 10

Sample Input 2
1 0
1 1

Sample Output 2
0

Explanation 2
Since there is only one square, and the queen is on it, the queen can move 0 squares.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

typedef struct
{
    int x;
    int y;
} point;

int queensAttack(int n, int Qx, int Qy, std::vector<point> obstacles) {
    // row = y, col = x
    int UpDistance = n - Qy;
    int LeftDistance = Qx - 1;
    int DownDistance = Qy - 1;
    int RightDistance = n - Qx;
    int UpLeftDistance = std::min(n-Qy, abs(1-Qx));
    int UpRightDistance = n - std::max(Qx,Qy);
    int DownLeftDistance = std::min(Qx,Qy) - 1;
    int DownRightDistance = std::min(n - Qx, Qy - 1);

    int Ox, Oy, xDiff, yDiff;
    for(int i=0; i<obstacles.size(); i++)
    {
        Ox = obstacles[i].x;
        Oy = obstacles[i].y;
        xDiff = Qx - Ox;
        yDiff = Qy - Oy;

        if((Oy == Qy && Ox < Qx) && (Qx - Ox < LeftDistance)) //Obstacle found at Left
            LeftDistance = Qx - Ox - 1;

        if((Oy == Qy && Ox > Qx) && (Ox - Qx < RightDistance)) // Obstacle found at Right
            RightDistance = Ox - Qx - 1;

        if((Ox == Qx && Oy < Qy) && (Qy - Oy < DownDistance)) // Obstacle found at Down
            DownDistance = Qy - Oy - 1;

        if((Ox == Qx && Oy > Qy) && (Oy - Qy < UpDistance)) // Obstacle found at Up
            UpDistance = Oy - Qy - 1;

        // row = y, col = x
        else if((Oy < Qy && Ox < Qx) && (Qy - Oy == Qx - Ox) && Qy - Oy < DownLeftDistance) // Obstacle found at Lower Left
            DownLeftDistance = Qy - Oy - 1;

        else if((Oy < Qy && Ox > Qx) && (Qy - Oy == Ox - Qx) && Qy - Oy < DownRightDistance) //Obstacle found at Lower Right
            DownRightDistance = Qy - Oy - 1;

        else if((Oy > Qy && Ox < Qx) && (Oy - Qy == Qx - Ox) && Oy - Qy < UpLeftDistance) // Obstacle found at Upper Left
            UpLeftDistance = Oy - Qy - 1;

        else if((Oy > Qy && Ox > Qx) && (Oy - Qy == Ox - Qx) && Oy - Qy < UpRightDistance) // Obstacle found at Upper Right
            UpRightDistance = Oy - Qy - 1;
    }
    return UpDistance + LeftDistance + DownDistance + RightDistance +
            UpLeftDistance + UpRightDistance + DownLeftDistance + DownRightDistance;
}
int main() {

    int n,k;
    std::cin >> n >> k;

    int Qx, Qy;
    std::cin >> Qy >> Qx;

    std::vector<point> obstacles(k);
    point p;
    for(int i=0; i<k; i++)
    {
        std::cin >> p.y >> p.x;
        obstacles[i] = p;
    }
    std::cout << queensAttack(n, Qx, Qy, obstacles) << "\n";
    return 0;
}
