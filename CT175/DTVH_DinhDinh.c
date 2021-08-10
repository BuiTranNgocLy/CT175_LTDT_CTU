#include<stdio.h>

#define MAX_Vertices 20

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
			G->A[i][j] = 0;
}

//them cung vao do thi(cap nhat trong so ma tran A)
void add_adge(Graph *G, int x, int y){// them cung tu dinh x -> dinh y
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

//kiem tra dinh x & y co la lang gieng hay khong
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
}

int main(){
	Graph G;
	//khoi tao do thi
	init_Graph(&G, 5); 
	add_adge(&G, 2, 3);
	add_adge(&G, 3, 2);
	add_adge(&G, 2, 4);
	
	
	//printf("%d ", adjacent(&G, 2, 3));
	
	//in do thi	
	int i, j; 	
	//printf("%d\n", G.n);
	for(i=1; i<=G.n;i++){
		for(j=1; j<=G.n;j++)
			printf("%d ", G.A[i][j]);
		printf("\n");
	}
	return 0;
}
