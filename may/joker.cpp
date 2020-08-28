//
// Created by yozaam on 28/05/20.
//


/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


using namespace std;

int main() {
    // your code goes here
    long long tc,total,jokers,players,hand,ans,second;
    cin>>tc;
    while(tc--){


        ans = 0;
        cin>>total>>jokers>>players;

        if(jokers == 0) {   cout<<ans<<"\n";  continue;  };

        hand = total/players;


        long long first = min(jokers,hand);
        // if five cards per person max is either 5 or no of jokers in the game

        jokers -= first;

        //now find second

        players--;
        if(jokers == 0)
            second = 0; // absolute best case
        else if(jokers<=players) //there is max of one in best case
            second = 1;
        else{
            second = jokers/players;//gives me how many are distributed evenly
            if(jokers%players)//if remainder then each guy gets one more card
                second ++;
        }

        ans = first - second;

        cout<<ans<<"\n";

    }
    return 0;
}
