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

int main(){
	Graph G;
	int n=7, m=9, v;
	init_graph(&G, n, m);
	
	add_edge(&G, 1, 1, 2);
	add_edge(&G, 2, 1, 3);
	add_edge(&G, 3, 1, 3);
	
	add_edge(&G, 4, 3, 6);
	add_edge(&G, 5, 4, 1);

	add_edge(&G, 6, 4, 3);
	add_edge(&G, 7, 5, 6);
	add_edge(&G, 8, 6, 5);
	add_edge(&G, 9, 4, 5);
	
	for(v=1; v<=n;v++){
		printf("deg: %d = %d\n", v, deg(&G, v));
	}
	return 0;
}
