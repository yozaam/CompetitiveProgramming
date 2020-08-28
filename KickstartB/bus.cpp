//
// Created by Yohaan Vakil on 19/04/20.
//

#include <iostream>
#include <vector>


using namespace std;
int main() {


//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int T;

    cin>>T;



    int N,D;

    vector<int> h;

    int ans;

    for( int i = 1 ; i <= T ; i++){

//        cout<<"\ni is"<<i;
        cin>>N;
        cin>>D;
//        cout<<"\n N is "<<N;

        h.resize(0);

        while(N>0){
//            cout<<"y1";

            int temp;
//            cout<<"y2";
            cin>>temp;
//            cout<<"y3";
            h.push_back(temp);

            N--;
        }

        //now3
        // in h

        //when it goes down
        //if it goes up next it is a peak
//        ans =0;

//        cout<<"h.size()-1"<<h.size()-1;

//        for(int j = 1 ; j < h.size()-1 ; j++){
////            cout<<"in loop : "<<h[j]<<" \n";
//            if(h[j]>h[j-1]){
////                cout<<" go up \n";
//                if(h[j] > h[j+1]){
////                    cout<<"going down; \n";
//                    ans++;
//                }
//            }
//        }

        for( int  j = h.size() -1 ; j>=0 ; j--){
//            cout<<"in loop\n";
            if(D % h[j] == 0){

//                cout<<"perf match";
            }else{
                D--;
                j++;
            }
        }

        cout<<"Case #"<<i<<": "<<D<<"\n";



    }
    return 0;
}