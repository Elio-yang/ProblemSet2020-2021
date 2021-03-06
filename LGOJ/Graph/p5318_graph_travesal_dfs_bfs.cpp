#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100010;

class Document{
public:
        int n;
        int e;

        vector<int> Adj[maxn];
        Document(int N,int E):n(N),e(E){}
        void dfs(int s);
        void bfs(int s);
};
bool vis[maxn]={false};
void Document::dfs(int s)
{
        /*dfs模板背熟
         进来先操作
         */
        printf("%d ",s);
        vis[s]=true;
        size_t size=Adj[s].size();
        for (int i = 0; i < size; i++) {
                int v=Adj[s][i];
                if (!vis[v]){
                        this->dfs(v);
                }
        }
}

void Document::bfs(int s)
{
        /*bfs模板背熟
         在入队的时候，标记
         在出队的时候，操作
         */
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        vis[s]= true;
        while (!q.empty()){
                int v=q.front();
                q.pop();
                /*全部在出队的时候操作*/
                printf("%d ",v);
                int size=Adj[v].size();
                for (int i = 0; i < size; i++) {
                        int u=Adj[v][i];
                        if (!vis[u]){
                                q.push(u);
                                vis[u]= true;
                                /*以及入队过，标记为已经访问*/
                        }

                }
        }
}

int cmp(const void *a,const void *b){
        return (*(int*)a)-(*(int*)b);
}
int main(){
        int m,n;
        scanf("%d %d",&n,&m);
        Document doc(n,m);
        for (int i = 0; i < m; i++) {
                //u--->v
                int u,v;
                scanf("%d %d",&u,&v);
                doc.Adj[u].push_back(v);
        }
        for (int i = 1; i <=n ; i++) {
                sort(doc.Adj[i].begin(),doc.Adj[i].end());
        }
        doc.dfs(1);
        printf("\n");
        doc.bfs(1);
        return 0;
}
