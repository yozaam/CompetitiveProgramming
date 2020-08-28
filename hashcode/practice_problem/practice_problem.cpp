//
// Created by Yohaan Vakil on 15/02/20.
//
//
//#include <iostream>
//
//using namespace std;
//
//int ordered(int maxSlices, int noOfTypes ,vector<int> types ){
//
//
//
//
//    int sum= 0;
//
//    for(int i : types){
//        sum+=i;
//    }
//
//    int dif = sum - maxSlices;
//
//
//    if((maxSlices == 0) || ( dif > 0 )){
//        return noOfTypes;
//    }
//
//
//    for(int x = 0 ; x<noOfTypes;  x++){
//        return ordered(maxSlices-types[x], noOfTypes-1 , types.erase(types.begin() + x));
//    }

//
// Created by Yohaan Vakil on 15/02/20.
//

#include <iostream>
#include<vector>

    using namespace std;

//    int ordered(int maxSlices, int noOfTypes ,vector<int> types ){
//
//
//
//
//        int sum= 0;
//
//        for(int i : types){
//            sum+=i;
//        }
//
//        int dif = sum - maxSlices;
//
//
//        if((maxSlices == 0) || ( dif > 0 )){
//            return noOfTypes;
//        }
//
//
//        for(int x = 0 ; x<noOfTypes;  x++){
//            return ordered(maxSlices-types[x], noOfTypes-1 , types.erase(types.begin() + x));
//        }
//
//
//
//    }



    int main(){

//        freopen("d_quite_big.in","r",stdin);


        long long  count =0 ;
        int maxSlices , noOfTypes;

        cin>>maxSlices>>noOfTypes;

        vector<int> types(noOfTypes);


        for(int i = 0 ; i < noOfTypes ; i++){
            cin>>types[i];

            // copyOfTypes[i] = types[i];
        }

//        int x =ordered(maxSlices, noOfTypes, types);
//        sort(types.begin(),types.end());

//        cout<<x

        vector<int> ans;
        int sum= 0;

        for(int tt: types){
            sum += tt;
        }

        int dif = sum - maxSlices;


        while(dif>= types[noOfTypes-1]){


            dif-=types[noOfTypes-1];
//            cout<<dif<<"is dif \n";
            noOfTypes--;
            types.pop_back();
        }



        auto rm = find(types.begin(),types.end(),dif);





        if( rm  == types.end() ){
//                cout<<"not finding";
               rm = upper_bound(types.begin(),types.end(),dif);

        }
        {
            for(int x =0 ; x <noOfTypes ;x++){
                if(*rm == types[x]){
//                    cout<<"not found ";
                }else{
                    ans.push_back(x);
                    count++;
//                    cout<<"\n";
//                    ans.push_back();
                }
            }
        }
        cout<<count<<endl;

        for(int a : ans){
            cout<<a<<" ";
        }

    }

//
//
//
//int main(){
//
//
//    int maxSlices , noOfTypes;
//
//    cin>>maxSlices>>noOfTypes;
//
//    vector<int> types(noOfTypes);
//
//
//    for(int i = 0 ; i < noOfTypes ; i++){
//        cin>>types[i];
//
//       // copyOfTypes[i] = types[i];
//    }
//
//    int x =ordered(maxSlices, noOfTypes, types);
//    //sort(copyOfTypes)
//
//    cout<<x;
//
//    return 0;
//}