/*
https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

7
100 100 50 40 40 20 10
4
5 25 50 120


index  rank  score
  0	    1	  100
  1	    2	  50
  2	    3	  40
  3	    4	  20
  4	    5	  10
------------------
  0	    1	  100
  1	    1	  100
  2	    2	  50
  3	    3	  40
  4	    3	  40
  5	    4	  20
  6	    5	  10
  -     6      5    <--

  0	    1	  100
  1	    1	  100
  2	    2	  50
  3	    3	  40
  4	    3	  40
  -     4     25    <--
  5	    5	  20
  6	    6	  10

  0	    1	  100
  1	    1	  100
  2	    2	  50
  -     2     50    <--
  3	    3	  40
  4	    3	  40
  5	    4	  20
  6	    5	  10

  -     1     120   <--
  0	    2	  100
  1	    2	  100
  2	    3	  50
  3	    4	  40
  4	    4	  40
  5	    5	  20
  6	    6	  10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

void printArray(std::vector<int> arr) {
    for (int i=0; i<arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> climbingLeaderboard(std::vector<int> scores, std::vector<int> alice) {

    std::vector<int> leaderboard = scores;
    std::vector<int> results;

    int ranking = scores.size(),
        aliceLastPosition;

    // remove duplicates from the original 'scores' vector
    leaderboard.erase(std::unique(leaderboard.begin(), leaderboard.end()), leaderboard.end());
    std::cout << std::endl;
    aliceLastPosition = leaderboard.size()-1;

    for(int i=0; i<alice.size(); i++)
    {
        for(int j=aliceLastPosition; j>=0; j--)
        {
            //std::cout <<"Comparing " << alice[i] << " and " << leaderboard[j] << ":\n";

            if (alice[i] >= leaderboard[j])
            {
                ranking = j+1;
                //results.push_back(j+1);
            }
            else //if (alice[i] < leaderboard[j])
            {
                aliceLastPosition = j;
                ranking = j+2;
                //results.push_back(j+2);
                break;
            }
        }
        //std::cout << " Rank = " << ranking << "\n";
        results.push_back(ranking);
    }
    return results;
}

int main()
{
    int scores_count;
    std::cin >> scores_count;
    std::vector<int> scores(scores_count);

    for(int i=0; i<scores_count; i++)
        std::cin >> scores[i];

    int alice_count;
    std::cin >> alice_count;
    std::vector<int> alice(alice_count);

    for(int j=0; j<alice_count; j++)
        std::cin >> alice[j];

    /*
    std::cout << "Scores\n";
    printArray(scores);

    std::cout << "Alice\n";
    printArray(alice);
    */
    std::vector<int> results = climbingLeaderboard(scores, alice);
    printArray(results);

    return 0;
}
