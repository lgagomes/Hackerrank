/*
https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

Maria plays n games of college basketball in a season. Because she wants to go
pro, she tracks her points scored per game sequentially in an array defined as a
score = [s0, s1, ... sn-1]. After each game i, she checks to see if score si
breaks her record for most or least points scored so far during that season.

Given Maria's array of scores for a season of n games, find and print the number of
times she breaks her record for most and least points scored during the season.

Note: Assume her records for most and least points at the start of the season are
the number of points scored during the first game of the season.

Input Format:
The first line contains an integer denoting n(the number of games).
The second line contains n space-separated integers describing the respective values of
s0, s1,...sn-1.

Constraints:
1 <= n <= 1000
0 <= si <= 10^8

Output Format:
Print two space-seperated integers describing the respective numbers of times her best
(highest) score increased and her worst (lowest) score decreased.

Sample Input 0:
9
10 5 20 20 4 5 2 25 1

Sample Output 0:
2 4

Explanation 0
She broke her best record twice (10 to 20 and 20 to 25) and her worst record four times
(10 to 5, 5 to 4, 4 to 2 and 2 to 1), so we print 2 4 as our answer. Note that she did not
break her record for best score on 20 to 20 sequence, as her score during that game was not
strictly greater than her best record at the time.

Sample Input 1:
10
3 4 21 36 10 28 35 5 24 42

Sample Output 1:
4 0

Explanation 1:
She broke her best record four times (3 to 4, 4 to 21, 21 to 36 and 36 to 42) and her worst
record zero times as no score during the season was lower than the one she earned during her
first game (3), so we print 4 0 as our answer.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define N 10

void breakingRecords(int* score) {

    int max_val = score[0],
        min_val = score[0],
        best_record = 0,
        worst_record = 0,
        i;

    for(i=1; i<N; i++)
    {
        if(score[i] > max_val)
        {
           max_val = score[i];
           best_record++;
        }

        if(score[i] < min_val)
        {
            min_val = score[i];
            worst_record++;
        }
    }
    printf("%d %d\n",best_record, worst_record);
}

int main() {
    int *score = malloc(sizeof(int) * N);

    /*
    score[0] = 10;
    score[1] = 5;
    score[2] = 20;
    score[3] = 20;
    score[4] = 4;
    score[5] = 5;
    score[6] = 2;
    score[7] = 25;
    score[8] = 1;
    */

    score[0] = 3;
    score[1] = 4;
    score[2] = 21;
    score[3] = 36;
    score[4] = 10;
    score[5] = 28;
    score[6] = 35;
    score[7] = 5;
    score[8] = 24;
    score[9] = 42;

    breakingRecords(score);
    free(score);
    return 0;
}
