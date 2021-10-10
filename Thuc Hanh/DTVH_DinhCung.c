#include<stdio.h>
#define MAX_Vertices 100 //dinh
#define MAX_Edges 500 //cung
#define MAX_Length 100
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
List neighbors(Graph *G, int x){	
	int y;
	List list;
	make_null(&list);
	for (y = 1; y <= G->n; y++)
		if (adjacent(G, x, y) && y != x)
			push_back(&list, y);
	return list;
}
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
int main(){
	Graph G;
	//doc tap tin
	freopen("dothi.txt","r", stdin);
	int n, m; //n sl dinh, m sl cung 
	scanf("%d%d", &n , &m); 
	
	//doc ds dinh 
	init_graph(&G, n, m); 
	int u, v, e; //dinh u -> dinh v 
	
	//doc ds cung
	printf("Danh sach cac cung la:\n"); 
	for(e=1; e<=m; e++){
		scanf("%d%d", &u, &v); 
		printf("%d %d\n", u, v); 
		add_edge(&G, e, u, v);
		
	}
	
	//in bac cua tat ca cac dinh 
	int i,j;
	for(i=1; i<=G.n;i++) 
		printf("deg (%d) = %d\n", i, degree(&G, i));
	//in dinh co bac lon nhat
	count(&G);
	
	printf("in ra ds lang gieng cua cac dinh trong do thi");
	for(i=1; i<=G.n; i++){
		List list = neighbors(&G, i);
		printf("\nNeigh:[%d] = ", i);
		for(j=1; j<=list.size; j++){
			printf("%d ", element_at(&list, j));
		}
	}

	
	return 0; 
} 

