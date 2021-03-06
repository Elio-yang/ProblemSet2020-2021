#include <iostream>

const int max_n= 1e6 + 10;

struct vertex{
        int lc,rc;
};
struct vertex tree[max_n];

int ans;

void dfs(int id,int depth){
        if(id==0){return ;}
        ans=std::max(ans,depth);
        dfs(tree[id].lc,depth+1);
        dfs(tree[id].rc,depth+1);
}

int main()
{
        int n;
        std::cin>>n;
        for(int i=1;i<=n;i++){
                std::cin>>tree[i].lc>>tree[i].rc;
        }
        dfs(1,1);
        std::cout<<ans<<std::endl;
        system("pause");
        return 0;
}


