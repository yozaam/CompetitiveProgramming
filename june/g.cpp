//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 04/06/20.
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
#include <unordered_set>

typedef long long ll;

using namespace std;

int help(int a,int b,int c,int p, int q, int r){
    vector<int> og({p,q,r});

    vector<int> target({a,b,c});

    vector<int> diff({a-p,b-q,c-r});

    vector<int> factor({a/p,b/q,c/r});

    vector<int> remainder({a%p,b%q,c%r});

    int correct = count(diff.begin() , diff.end(), 0);

    if(  correct == 3){
        //well well well there are not too many numbers left
        return 0;
        //base case all done
    }else if(correct == 2){
        return 1;
    }else if(correct == 1){
        //only 1 zero then what the fuck to do
        // can i do it in one move?
        //either two factors are same or else two diff are same
        unordered_set<int> sameIndex(diff.begin,diff.end());

        if(sameIndex.size() == 2){
            // one is zero what is other i dont f care okay now we can just rule the world by saying ans is 1 step away
            return 1;
        }

        sameIndex.clear();

        sameIndex.insert(factor.begin(),factor.end());

        if(sameIndex.size() == 2){
            // one is 1 what is other i dont f care okay now we can just rule the world by saying ans is 1 step away
            return 1;
        }
        //ans has to be two steps away obviously! because cant do it in one step!
        else{
            return 2;
        }
    }

    else if(correct == 0){
        // okay how many steps bastard idk mf i need recurrence relation

        //multiply by smallest factor?
        //add smallest d?

        //if any two are same d then what?
        //consider all diffs after addition what happens?
        //addition is not great if we add all we get a stupid ans

        //add the remainder or add the diff!
        vector<int> poss;

        for(int i = 0 ; i < 3 ; i++){
            if(remainder[i]>0)
            {
                int ta = a, tb = b , tc = c;
                //if there is a remainder we need addition no doubt about that!

                switch(i){
                    case 0:
                        poss.push_back(helper(p,b,c,p,q,r));
                        break;
                    case 1:
                        poss.push_back(helper(a,q,c,p,q,r));
                        break;
                    case 2:
                        poss.push_back(helper(a,b,r,p,q,r));
                        break;
                }
            }
        }

        //otherwise what strategy is a good strategy? i can do a multiplication and make one of my elements zero at the same time if i make another zero that will be great!
        set<int> sames(diff.begin(),diff.end());

        int samescount = sames.size();

        //IF TWO HAVE SAME DIFFERENCE -> ANS CAN BE BROUGHT IN TWO STEPS

        if(samescount==2)//there is a overlap of same diff!
            poss.push_back(1);

        if(samescount == 1)
            poss.push_back(0);

        //if it is three then nothing great.



        return 1+ min_element(poss.begin(),poss.end());
    }
}



int main() {
    // your code goes here
    int tc;
    cin>>tc;
    while(tc--){

        int a,b,c,p,q,r;

        cin>>p>>q>>r>>a>>b>>c;

        //first try addition?

        //if all numbers don't overlap anywhere take smallest addition and do first or else take smallest multiplication and do that




    }
    return 0;
}
