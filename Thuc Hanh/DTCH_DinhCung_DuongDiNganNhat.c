#include<stdio.h>
#define MAX_Vertices 100 //dinh
#define MAX_Edges 500 //cung
#define MAX_Length 100
#define NO_Edge -1
#define Infinity 9999999
/*Cac ham voi ma tran dinh cung*/
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
			G->A[i][j]=NO_Edge;
		}
	}
}

//them cung e=(x,y) vao DT
void add_edge(Graph *G, int x, int y, int w){
	G->A[x][y] =w;
	//G->A[y][x] = w;
}

//kiem tra dinh y co ke dinh x hay khong
int adjacent(Graph *G, int e, int x, int y){
	for(e=1; e<=G->m; e++){
		if(G->A[x][e]==1 && G->A[y][e]==1){
			return 1;
		}
	}
	return 0; 
}

//tinh bac cua 1 dinh
int degree(Graph *G, int x){
	int e, deg =0;
	for(e=1; e<=G->m; e++){
		if(G->A[x][e]==1)
			deg++;
	}
	return deg;
}

/*Cac ham voi list*/
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
//tra ve so phan tu cua danh sach
int count_list(List *L){
	return L->size;
} 
////Ex: can tim lang gieng dinh x
//List neighbors(Graph *G, int x){	
//	int y;
//	List list;
//	make_null(&list);
//	for (y = 1; y <= G->n; y++)
//		if (adjacent(G, x, y) && y != x)
//			push_back(&list, y);
//	return list;
//}
//dinh co bac lon nhat
void count(Graph* G){
    int dinh, i, max = 0;
    for (i = 1; i <= G->n; i++){
        if(degree(G, i) > max){
            max = degree(G, i);
            dinh = i;
        }   
    }
    printf("Dinh %d co bac lon nhat la %d\n", dinh, max);
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
			if (G->A[i][j] != NO_Edge && mark[j] == 0) {
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
	init_graph(&G, n, m);
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
