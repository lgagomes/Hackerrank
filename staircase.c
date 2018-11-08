/*
ex: N=6

     #
    ##
   ###
  ####
 #####
######

*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,
        j,
        count,
        value=10;

    for(i=0; i<value; i++)
    {
        count=1;
        for(j=0; j<value; j++)
        {
            if(count < (value-i))
                printf(" ");
            else
                printf("#");
            count++;
        }
        printf("\n");
    }
    return 0;
}
