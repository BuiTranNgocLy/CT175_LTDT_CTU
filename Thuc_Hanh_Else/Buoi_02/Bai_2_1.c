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

//khai bao cau truc hang doi (Queue)
typedef struct{
	int data[MAX_Element];
	int front;//chi so dau hang doi(lay DL)
	int indx; //chi so cuoi hang doi(them DL)
}Queue;

//khoi toa hang doi rong
void make_null_Queue(Queue *Q){
	Q->front = 0;
	Q->indx = -1;
}

//them 1 phan tu vao hang doi
void push_Queue(Queue *Q, int x){
	Q->indx++;
	Q->data[Q->indx] = x;
}

//kiem tra Queue co rng hay khong
int empty_Queue(Queue *Q){
	return Q->front > Q->indx;
}

//lay 1 phan tu o dau Queue
int top(Queue *Q){
	return Q->data[Q->front];
}

//cap nhat chi so front
void pop(Queue *Q){
	Q->front++;
}

//BFS
List BFS(Graph *G, int x, int parent[]){
	Queue Q;
	make_null_Queue(&Q);
	int mark[MAX_Vertices]; //danh dau dinh da duyet hay chua
	int i;
	for(i=1;i<=G->n;i++){
		mark[i]=0;
	}
	push_Queue(&Q, x);
	parent[x]=0;
	List L_bfs;//da dinh da duyet
	make_null(&L_bfs);
	while(!empty_Queue(&Q)){
		int u=top(&Q);
		pop(&Q);
		if(mark[u]==1)
			continue;
		push_back(&L_bfs, u);//dua u vao ds
		mark[u]=1;//danh dau u da duyet
		List L;//luu neighbors
		make_null(&L);
		L=neighbors(G, u);
		int v;
		for(i=1;i<=L.size;i++){
			v=element_at(&L, i);
			if(mark[v]==0){
				push_Queue(&Q, v);
				if(parent[v]==-1)//v chua co cha
					parent[v]=u;
			}	
		}
	}
	return L_bfs;
}
int main (){
	Graph G;
	//freopen("BFS.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	init_Graph(&G, n);
	//doc ds cung
	int e, x, y;
	for(e=1; e<=m; e++){
		scanf("%d %d", &x, &y);
		add_edge(&G, x, y);
	}
	
	//dinh chua duyet
	int mark_bfs[MAX_Vertices], parent[MAX_Vertices], u;
	for(u=1;u<=G.n;u++){
		mark_bfs[u]=0;
		parent[u]=-1;
	}
	//in
	for(u=1;u<=G.n;u++){
		if(mark_bfs[u]==0){
			List L=BFS(&G, u, parent);
			int i, v;
			for(i=1;i<=L.size;i++){
				v=element_at(&L, i);
				//printf("%d\n", v);
				mark_bfs[v]=1;
			}
		}
	}
	//in cha
	for(u=1;u<=G.n;u++){
		printf("%d %d\n", u, parent[u]);
	}
	return 0;
} 
