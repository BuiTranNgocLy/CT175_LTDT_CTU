#include<stdio.h>
#define MAX_Vertices 100  
#define MAX_Length 20
#define MAX_Element 40
#define white 0 
#define black 1
#define gray 2
/*white: chua duyet
gray: dang duyet, chua duyet xong
black: da duyet*/
//khai bao ma tran dinh dinh
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;// so luong dinh
}Graph;
/*Cac ham do thi*/
//khoi tao do thi
void init_Graph (Graph *G, int n){
	int i,j;
	G->n =n;;
	for(i=1; i<=n;i++)//dong cua ma tran
		for(j=1; j<=n;j++)//cot ma tran
			G->A[i][j] = 0;
}

//them cung vao do thi(cap nhat trong so ma tran A)
void add_edge(Graph *G, int x, int y){// them cung tu dinh x -> dinh y
	//don do thi, k da cung  
//	G->A[x][y] = 1;
//	G->A[y][x] = 1;
	//da cung
//	G->A[x][y] +=1;
	//co huong
	G->A[x][y] =1; 
}

//kiem tra dinh x & y co la lang gieng hay khong
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
}

//tinh bac cua dinh x trong do thi
int degree(Graph *G, int x, int y){
	int deg = 0, i;
	for(i=1; i<=G->n;i++)
		if(G->A[i][x] == 1)// ton tai cung//if(adjacent(G, i, x))
			deg++;
	return deg;
}

//tinh bac da cung
//int degree(Graph *G, int x, int y){
//	int deg = 0, i;
//	for(i=1; i<=G->n;i++)
//		deg+=G->A[x][y];
//	return deg;
//}

/*Cac ham List*/
//khai bao cau truc ds list
typedef struct{
	int data[MAX_Length];
	int size;
}List;

//khoi tao ds rong
void make_null(List *list){
	list->size = 0;
}

//them 1 phan tu(dinh) vao cuoi ds
void push_back(List *list, int x){
	list -> data[list->size] = x;
	list -> size++;
}

//lay 1 phan tu(dinh) trong ds tai vi tri i
int element_at(List *list, int i){
	return list->data[i-1]; //do mang data bat dau tu vi tri thu 0
}

////Ex: can tim lang gieng dinh x
List neighbors(Graph *G, int x){
	List L;
	make_null(&L);
	int i;
	for(i=1; i<=G->n; i++){
		if(G->A[i][x] == 1){ //dinh i -> dinh x
			push_back(&L, i);
		}
	}
	return L;
}
int color[MAX_Vertices];
int index;
//mang kiem tra dinh duyet roi hay chua
int mark[MAX_Vertices];
int parent[MAX_Vertices];
/*Duyet DT bat dau tu dinh u*/
//DFS
void dfs(Graph* G, int u) { 
	if(mark[u]==2) return; 
	//print("%d\n",x) 
	mark[u] = 2; 
	List list = neighbors(G, u);
	int i;
	for(i=1;i<=list.size;i++){ 
		int v = element_at(&list, i);
		if(mark[v] == 2){ 
			index = 1; 
			// Ton tai chu trinh return; 
		} dfs(G, v); } mark[u]=1;
	}
//ham check toan bo di thi
int check(Graph* G) { 
	int i,j;
	for(i=1;i<=G->n;i++){ 
		mark[i] = 0; 
	} 
	index = 0; 
	for( j=1;j<=G->n;j++){ 
		dfs(G, j); 
	} 
	return index;
	}
int main(){
	Graph G;
	//freopen("DFS_DeQuy.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m); 
	init_Graph(&G, n); 
	//doc cac cung cua do thi
	int u, v, i;
	for(i=1; i<=m; i++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v); 
	} 
	for(i=1; i<n; i++){
		mark[i]=0;
	}
	dfs(&G, 1);
//	for(i=1;i<=n;i++){
//		printf("%d %d\n", i, parent[i]);
//	}
	if(!check(&G)){
		printf("YES");
	}
	else printf("NO");
	return 0; 
} 
