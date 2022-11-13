#include <bits/stdc++.h>
using namespace std;
#define n 20
bool cb[n][n];
bool safe(int r,int c){
    
    for(int i=0;i<n;i++){       
        if(cb[r][i]==1){
            return 0;
        }
    }
    for(int i=0;i<n;i++){     
        if(cb[i][c]==1){
            return 0;
        }
    }
    int j=c,i=r;
    for(int k=0; k<n;k++){
        cout<<i<<" "<<j<<endl;
        if(cb[i][j]==1){
            return 0;
        }
        
        i = (i+1)%n;
        j = (j+1)%n;
    }
    return 1;
}
bool isSafe(int r, int c)
{
    int i, j;
  
    /* Check this row on left side */
    for (i = 0; i < r; i++)
        if (cb[i][c])
            return false;
  
    /* Check upper diagonal on left side */
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (cb[i][j])
            return false;
  
    /* Check lower diagonal on left side */
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