#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+10,M=2*N;
bool st[N];
int h[N],e[M],ne[M],w[M],dist[N];
int n,m,idx;
typedef pair<int,int> PII;
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    priority_queue< PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});  //first表示权重，second表示点
    while(!heap.empty()){
        auto k=heap.top();   //找到权重最小的待遍历点
        heap.pop();
        int ver=k.second; int val=k.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];    //借助ver点为跳板松弛j点的最短路径
            if(dist[j]>val+w[i]){
                dist[j]=val+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}

int main(){
    memset(h,-1,sizeof h);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dijkstra()<<endl;
}