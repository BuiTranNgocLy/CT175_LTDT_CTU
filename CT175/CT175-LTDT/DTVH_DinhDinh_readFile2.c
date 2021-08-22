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

//tinh bac cua dinh x trong do thi
int degree(Graph *G, int x){
	int deg = 0, i;
	for(i=1; i<=G->n;i++)
		if(G->A[i][x] == 1)// ton tai cung
			deg++;
	return deg;
}

//
int main(){
	Graph G;
	//doc tap tin
	freopen("dothi.txt","r", stdin);
	int n, m; //n sl dinh, m sl cung 
	scanf("%d%d", &n , &m); 
	
	//doc ds dinh 
	init_Graph(&G, n); 
	int u, v, e; //dinh u -> dinh v 
	
	//doc ds cung
	for(e=1; e<=m; e++){
		scanf("%d%d", &u, &v); 
		printf("%d %d\n", u, v); 
		add_adge(&G, u, v);
		
	} 
	
	//in bac cua tat ca cac dinh 
	int i;
	for(i=1; i<=G.n;i++) 
		printf("deg (%d) = %d\n", i, degree(&G, i));

	return 0;
}
