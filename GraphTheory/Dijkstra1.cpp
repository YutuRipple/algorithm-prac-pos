#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 510;
bool st[N];
int g[N][N],dist[N];
int n, m;
void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n;i++){
        int t = -1;
        for (int j = 1; j <= n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t = j;
        }
        if(t==-1) break;
        st[t] = true;
        for (int j = 1; j <= n;j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
}
int main(){
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b]= min(g[a][b], c);
    }
    dijkstra();
    if(dist[n]==0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
    return 0;
}