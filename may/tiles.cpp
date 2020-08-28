//
// Created by yozaam on 28/05/20.
//


/********   All Required Header Files ********/
#include <iostream>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <sstream>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <iterator>
//#include <list>
//#include <stack>
//#include <map>
//#include <set>
//#include <functional>
//#include <numeric>
//#include <utility>
//#include <limits>
//#include <time.h>
//#include <math.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>


using namespace std;

int main() {
    // your code goes here
    long long tc,row,col,sq,vrect,ans,scount,vcount;
    char dot;
    cin>>tc;
    vector< vector <bool> > tiles;
    while(tc--){


        ans = 0 , scount = 0 , vcount = 0;
        cin>>row>>col>>sq>>vrect;

        tiles.resize(row,vector<bool>(col,false));

        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j < col ; j++){
                cin>>dot;
                if(dot == '.'){
                    tiles[i][j] =1;
                    if(j>0 && tiles[i][j-1] == true){
                        vcount++;// count one vertical 1x2 block
                        scount--; // above tile was counted sorry!
                        tiles[i][j-1] = tiles[i][j] = 0;// make it false to not count as rect in below tiles
                    }//he makes a rect!
                    else{
                        scount++;
                    }//nothing special
                }
            }
        }

//        if( vcount && 2*sq <= vrect) // if 2 sq is cheaper than 1 vrect
        ans = vcount*2*sq + scount*sq;


        ans = min(ans,vcount*vrect + scount*sq);


        cout<<ans<<"\n";//: vc sc "<<vcount<<" "<<scount<<"\n";

    }
    return 0;
}
