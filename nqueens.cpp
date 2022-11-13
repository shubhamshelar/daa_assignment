#include <bits/stdc++.h>
using namespace std;
#define n 20
bool cb[n][n];

bool isSafe(int r, int c)
{
    int i, j;
  
    for (i = 0; i < r; i++)
        if (cb[i][c])
            return false;
  
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (cb[i][j])
            return false;
  
    for (i = r, j = c; i >= 0 && j < n; i--, j++)
        if (cb[i][j])
            return false;
  
    return true;
}
bool place(int r){
    if(r>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(r,i)){
            cb[r][i]=1;
            
            if(place(r+1)){
                return 1;
            }
            cb[r][i]=0;
        }
    }
    return 0;

}
int main(){
    memset(cb,0,n*n*sizeof(bool));
    place(0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cb[i][j]<<" ";

        }
        cout<<endl;

    }
    //safe(1,2);
    
}