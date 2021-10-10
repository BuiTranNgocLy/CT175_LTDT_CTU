#include<stdio.h>
#define MAX_Vertices 100 //dinh
#define MAX_Edges 500 //cung
#define MAX_Length 100
#define No_Edge -1
#define Infinity 9999999
/*Cac ham voi ma tran dinh cung*/
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
void add_edge(Graph *G, int w, int x, int y){// them cung tu dinh x -> dinh y
	G->A[x][y] = w;
	//G->A[y][x] = 1;
	//da cung: G->A[x][y]+=1
	//co huong: bo 1 hang
}

//kiem tra dinh x & y co la lang gieng hay khong
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
}

//tinh bac cua dinh x trong do thi
	//don cung
int degree(Graph *G, int x){
	int deg = 0, i;
	for(i=1; i<=G->n;i++)
		if(G->A[i][x] == 1)// ton tai cung
			deg++;
	return deg;
}
	//da cung
//int degree(Graph *G, int x){
//	int deg=0, i;
//	for(i=1;i<=G->n;i++){
//		deg+=G->A[x][y];
//	}
//	return deg; 
//} 

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
//dinh co bac lon nhat
void count(Graph *G, int x){
	int i, max=0;
	for(i=1; i<=G->n; i++){
		if(degree(G, i) > max){
			max = degree (G, i);
			x=i;
		}
	}
	printf("%d %d", x, max);
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
	for (it = 1; it < G->n; it++) {
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
	int n, m, u, v, e, w;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for (e = 1; e <= m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G,u,v,w);
	}
	Dijkstra(&G, 1);
	if(pi[n]>0){
		printf("%d", pi[n]);
	}
	else printf("-1");
	return 0;
}
