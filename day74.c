#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include <string.h>
int main(void) {
    struct Candidate { char name[100]; int votes; } arr[] = {{"alice", 5}, {"bob", 5}, {"charlie", 3}};
    int n = 3;
    int max = arr[0].votes;
    char winner[100];
    strcpy(winner, arr[0].name);
    for (int i = 1; i < n; ++i) {
        if (arr[i].votes > max || (arr[i].votes == max && strcmp(arr[i].name, winner) < 0)) {
            max = arr[i].votes;
            strcpy(winner, arr[i].name);
        }
    }
    printf("Winner: %s %d\n", winner, max);
    return 0;
}