#include <bits/stdc++.h>
using namespace std;

struct edge_ds{
    char src,dest;
    int w;
};

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int nodes,edges;
    char st,end;
    cin>>nodes>>edges>>st>>end;
    edge_ds edge[edges];
    for(int i=0;i<edges;i++){
        cin>>edge[i].src;
        //cout<<edge[i].src<<endl;
        cin>>edge[i].dest;
        cin>>edge[i].w;
    }
    map<char,int> cost;
    for(int i=0;i<nodes;i++){
        cost[char('a'+i)]=INT_MAX;
        //cout<<char('a'+i)<<endl;
    }
    cost[st]=0;
    for(int i=0;i<nodes+1;i++){
        for(int j=0;j<edges;j++){
            int src=edge[j].src;
            int dest=edge[j].dest;
            int w=edge[j].w;
            cost[dest]=min(cost[dest],cost[src]+w);
        }
    }
    for(int j=0;j<edges;j++){
        int src=edge[j].src;
        int dest=edge[j].dest;
        int w=edge[j].w;
        if(cost[dest]!=cost[src]+w){
            cout<<"Negative Cycle Present\n";
            break;
        }
    }
    for(int i=0;i<nodes;i++){
        cout<<char('a'+i)<<" cost: "<<cost[char('a'+i)]<<endl;
        //cout<<char('a'+i)<<endl;
    }


}