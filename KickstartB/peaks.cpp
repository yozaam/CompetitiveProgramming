#include <iostream>
#include <vector>


using namespace std;
int main() {


//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int T;

    cin>>T;



    int N;

    vector<int> h;

    int ans;

    for( int i = 1 ; i <= T ; i++){

//        cout<<"\ni is"<<i;
        cin>>N;

//        cout<<"\n N is "<<N;

        h.resize(0);

        while(N>0){
//            cout<<"y";

            int temp;
            cin>>temp;
//            cout<<"ok ok ";
            h.push_back(temp);

            N--;
        }

        //now3
        // in h

        //when it goes down
        //if it goes up next it is a peak
        ans =0;

//        cout<<"h.size()-1"<<h.size()-1;
        for(int j = 1 ; j < h.size()-1 ; j++){
//            cout<<"in loop : "<<h[j]<<" \n";
            if(h[j]>h[j-1]){
//                cout<<" go up \n";
                if(h[j] > h[j+1]){
//                    cout<<"going down; \n";
                    ans++;
                }
            }
        }

        cout<<"Case #"<<i<<": "<<ans<<"\n";



    }
    return 0;
}