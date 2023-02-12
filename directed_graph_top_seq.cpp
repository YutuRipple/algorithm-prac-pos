#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int h[N], d[N], e[M], ne[M];
int n, m, idx;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void topseq()
{
    int q[N];
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){
        if(d[i]==0)
            q[++tt] = i;
    }
    while (hh<=tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1;i=ne[i]){
            int j = e[i];
            if(--d[j]==0)
                q[++tt] = j;
        }
    }
    if(tt==n-1)
        for (int i = 0; i < n;i++)
            cout << q[i] << " ";
    else
        cout << -1;
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    topseq();
    return 0;
}