#include<stdio.h>
#define MAX_Vertices 100 //dinh
#define MAX_Edges 500 //cung
#define MAX_Length 100
#define No_Edge -1
#define Infinity 9999999

//khai bao ma tran dinh dinh
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;// so luong dinh
}Graph;

//khoi tao do thi
void init_Graph (Graph *G, int n){
	int i,j;
	G->n =n;;
	for(i=1; i<=n;i++)
		for(j=1; j<=n;j++)
			G->A[i][j] = No_Edge;
}

//them cung vao do thi(cap nhat trong so ma tran A)
void add_edge(Graph *G, int x, int y, int w){// them cung tu dinh x -> dinh y
	G->A[x][y] = w;
	G->A[y][x] = w;
}

/*Giai thuat Moore-Djisktra*/

int mark[MAX_Vertices];
int pi[MAX_Vertices];
int p[MAX_Vertices];
void Dijkstra(Graph* G, int s) {
	int i, j, it;
	for (i = 1; i <= G->n; i++) {
		pi[i] = Infinity;
		mark[i] = 0;
}
	pi[s] = 0;
	p[s] = -1;
	for (it = 1; it <= G->n; it++) {
		int min_pi = Infinity;
		for (j = 1; j <= G->n; j++){
			if (mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				i = j;
			}
		}
		mark[i] = 1;
		for (j = 1; j <= G->n; j++){
			if (G->A[i][j] != No_Edge && mark[j] == 0) {
				if (pi[i] + G->A[i][j] < pi[j]) {
					pi[j] = pi[i] + G->A[i][j];
					p[j] = i;
				}
			}
		}
	}	
}

int main(){
	Graph G;
	int n, m, u, v, w, i, s, t;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G,u,v,w);
	}
	Dijkstra(&G, 1);
	if(pi[n]==Infinity) printf("-1");
	else printf("%d",pi[n]);
	return 0;
}
