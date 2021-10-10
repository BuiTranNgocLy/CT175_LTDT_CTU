#include<stdio.h>
#define MAX_Vertices 100
/*bieu dien do thi bang ma tran dinh dinh*/
//khai bao cau truc do thi
typedef struct{
    int n; // Voi n la so dinh cua ma tran
    int A[MAX_Vertices][MAX_Vertices];
}Graph;

//khoi tao do thi
void init_graph(Graph *G, int n){
    int i,j;
    G->n=n;
    for ( i=1; i<= n; i++){ 
        for ( j=1; j<= n; j++) G->A[i][j]=0;
    }
}
//them cung vao do thi
void add_edge(Graph *G, int x, int y){
    G->A[x][y]=1;
    G->A[y][x]=1;
}
int main(){
    int e,n,m,u,v,i,j;
    Graph G;
    //freopen("dt1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    init_graph(&G,n);
    for(e=1;e<=n;e++){
        scanf("%d%d",&u,&v);
        add_edge(&G,u,v);
    }
    for (i=1;i<=G.n;i++){
        for (j=1;j<=G.n;j++){
            printf("%d ",G.A[i][j]);
        }
    printf("\n");
    }
    return 0;
}
