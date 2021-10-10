#include<stdio.h>
#define MAX_Vertices 20
#define MAX_Length 20
#define MAX_Element 40
//khai bao ma tran dinh dinh
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;// so luong dinh
}Graph;

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
		if(G->A[i][x] == 1)// ton tai cung//if(adjacent(G, i, x))
			deg++;
	return deg;
}

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
//mang kiem tra dinh duyet roi hay chua
int mark[MAX_Vertices];

int parent[MAX_Vertices];
//DFS De Quy
void DFS_DeQuy(Graph *G, int u){
	if(mark[u] == 1)
		return;
	//printf("%d\n", u);
	mark[u] = 1;
	List list = neighbors(G, u);
	int i;
	for(i=1;i<=list.size;i++){
		int v = element_at(&list, i);
		DFS_DeQuy(G, v);
	} 
}
//ham check
int check(Graph *G){
	int i;
	DFS_DeQuy(G, 1);
	for(i=1;i<=G->n;i++){
		if(!mark[i]){
			return 0;
			break;
		}
	}
	return 1;
}
int main(){
	Graph G;
	int n, m;
	scanf("%d%d", &n, &m); 
	init_Graph(&G, n); 
	//doc cac cung cua do thi
	int u, v, i;
	for(i=1; i<=m; i++){
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v); 
	} 
	
	for(i=1; i<n; i++){
		mark[i]=0;
	}
	
	//DFS_DeQuy(&G, 1);
	if(check(&G)){
		printf("YES");
	}
	else printf("NO");
	return 0;
}
