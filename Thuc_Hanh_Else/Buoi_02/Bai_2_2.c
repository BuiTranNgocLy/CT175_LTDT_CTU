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

//khai bao cau truc cua stack
typedef struct{
	int data[MAX_Element];
	int size; // kich thuoc stack
}Stack; 

//khoi tao stack rong
void make_null_stack(Stack *stack){
	stack->size=0;
}

//them 1 phan tu vao stack
void push_stack(Stack *stack, int x){
	stack->data[stack->size]=x;
	stack->size++;
}


//lay 1 phan tu trong stack
int top(Stack *stack){
	return stack->data[stack->size-1];
}

//xoa 1 phan tu thuoc stack
void pop(Stack *stack){
	stack->size--;
}
//kiem tra stack co rong hay khong
int empty(Stack *stack){
	return stack->size == 0;
}

//DFS
List depth_first_search(Graph *G, int x, int parent[]){
	Stack s;
	make_null_stack(&s);
	push_stack(&s, x);
	parent[x] =0;
	//khoi tao ds luu cac dinh da duyet
	List list_dfs;
	make_null(&list_dfs);
	//khoi tao tat ca cac dinh chua duoc duyet
	int mark[MAX_Vertices];//mang danh dau dinh da duoc duyet chua
	int i;
	for(i=1; i<=G->n; i++){
		mark[i] = 0; //tat ca cac dinh chua duoc duyet
	}
	while(!empty(&s)){
		int u = top(&s);
		pop(&s);
		if(mark[u]==1)
			continue;
		push_back(&list_dfs, u);//dua dinh u da duyet vao ds
		mark[u] = 1;
		List list = neighbors(G, u);//cac dinh e v cua u
		for(i=1; i<=list.size; i++){
			int v = element_at(&list, i);
			if(mark[v]==0){
				push_stack(&s,v);
				parent[v] = u;
			}	
		}
	}
	return list_dfs;	
} 

int main(){
	Graph G;
	//freopen("DFS.txt", "r", stdin);
	int n, m, i, j;// n sl dinh, m sl cung
	scanf("%d%d", &n, &m);
	init_Graph(&G, n); 
	int e,u,v; //ds cung
	for(e=1; e<=m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v); 
	} 
	int parent[MAX_Vertices];
	for(i=1;i<=G.n;i++){
		parent[i] = -1;
	}
	//kiem tra full dothi xem dinh nao chua duyet
	int mark_dfs[MAX_Vertices];
	for(i=1; i<=G.n; i++){
		mark_dfs[i]=0;
	}
	
//	//neu dinh nao chua duoc duyet thi duyet
	for(i=1; i<=G.n; i++){
		if(mark_dfs[i] == 0){
			List dfs = depth_first_search(&G, i, parent);
			for(j=1; j<=dfs.size;j++){
				int k=element_at(&dfs,j);
				//printf("Thu tu duyet:\n%d\n", k);
				mark_dfs[k]=1;
			}
		}		
	}
	//in mang cha
	for(u=1;u<=G.n;u++){
		printf("%d %d\n", u, parent[u]);
	}
	return 0;
}