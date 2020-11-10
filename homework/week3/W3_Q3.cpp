#include <cstdlib>
#include <iostream>
struct node{
        int key;
        struct node *lchild;
        struct node *rchild;
};
using namespace std;
struct node* creat();
void path_rec(struct node *node, int *path, int len);


int ans[100][100];
int len_id[100];
int id=0;


int main()
{
        struct node* T;
        T=creat();
        int path[110]={0};
        path_rec(T, path, 0);
        int max=INT32_MIN;
        int id_m=0;
        for(int i=0;i<id;i++){
                int result=0;
                for(int j=0;j<100;j++){
                        result+=ans[i][j];
                }
                if(result>max){
                        max=result;
                        id_m=i;
                }
        }

        cout<<max<<endl;
        for(int i=0;i<len_id[id_m];i++){
                cout<<ans[id_m][i]<<" ";
        }
        cout<<endl;
        return 0;
}

struct node* creat()
{
        int k;
        scanf("%d",&k);
        struct node* T;

        if(k==0){
                T= NULL;
        }else{
                T=(struct node*)malloc(sizeof(struct node));
                T->key=k;
                T->lchild=creat();
                T->rchild=creat();
        }
        return T;
}



void path_rec(struct node *node, int *path, int len)
{
        if (node == NULL) return;
        path[len] = node->key;
        len++;

        if (node->lchild ==NULL && node->rchild == NULL)
        {
                for(int i=0;i<len;i++){
                        ans[id][i]=path[i];
                }
                len_id[id]=len;
                id++;
        } else {
                path_rec(node->lchild, path, len);
                path_rec(node->rchild, path, len);
        }
}
