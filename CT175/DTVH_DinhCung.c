#include<stdio.h>
#define MAX_Vertices 100 //dinh
#define MAX_Edges 500 //cung

//khai bao ma tran dinh cung
typedef struct{
	int A[MAX_Vertices][MAX_Edges];
	int n,m; //n: sl dinh, m sl cung
}Graph;

//khoi tao DT
void init_graph(Graph *G, int n, int m){
	int i,j;
	G->n=n;
	G->m=m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			G->A[i][j]=0;
		}
	}
}

//them cung e=(x,y) vao DT
void add_edge(Graph *G, int e, int x, int y){
	G->A[x][e] =1;
	G->A[y][e] = 1;
}

//kiem tra dinh y co ke dinh x hay khong
int adjacent(Graph *G, int e, int x, int y){
	for(e=1; e<=G->m; e++){
		if(G->A[x][e]==1 && G->A[y][e]==1){
			return 1;
		}
		return 0;
	}
}

//tinh bac cua 1 dinh
int deg(Graph *G, int x){
	int e, deg =0;
	for(e=1; e<=G->m; e++){
		if(G->A[x][e]==1)
			deg++;
	}
	return deg;
}
