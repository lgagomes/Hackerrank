/*
https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
*/

#include <iostream>
#include <algorithm>

string catAndMouse(int posCatA, int posCatB, int posMouse) {

    int distCatA = abs(posCatA - posMouse),
        distCatB = abs(posCatB - posMouse);

    if(distCatA < distCatB)
        return "Cat A";
    else if(distCatA > distCatB)
        return "Cat B";
    else
        return "Mouse C";
}

int main() {

    int x,y,z,q;

    std::cin >> q;

    for(int i=0; i<q; i++)
    {
        std::cin >> x >> y >> z;
        std::cout << catAndMouse(x, y, z) << "\n";
    }

    return 0;
}
