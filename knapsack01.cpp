#include <bits/stdc++.h>
using namespace std;
#define n 4
struct obj{
    int w;
    int p;
}obj[n+1];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int capacity;
    for(int i=1;i<n+1;i++){
        
        cin>>obj[i].w;
        
    }
    for(int i=1;i<n+1;i++){
        
        
        cin>>obj[i].p;
    }
    
    
    cin>>capacity;

    int dp[n+1][capacity+1];
    memset(dp,0,(n+1)*(capacity+1)*sizeof(int));

    for(int i=1; i<n+1;i++){
        //select ith object
        for(int j=1;j<capacity+1;j++){
            //select jth capacity
            if(obj[i].w<=j){
                //can be putted
                dp[i][j]=max(dp[i-1][j],obj[i].p+dp[i-1][j-obj[i].w]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }


        }
    }
    for(auto &it:dp){
        for(auto itt:it){
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    cout<<">>"<<dp[n][capacity]<<endl;
    
}

/*
w=60 100 120
p=10 20 30
capacity=50
*/