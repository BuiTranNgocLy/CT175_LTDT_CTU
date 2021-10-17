#include <stdio.h>
#include <stdbool.h>
#define MAX_Vertices 100
#define MAX_Length 100
#define oo 9999999

//khai bao ma tran dinh dinh
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;// so luong dinh
}Graph;

//khai bao cau truc ds list
typedef struct{
	int data[MAX_Length];
	int size;
}List;

//khoi tao do thi
void init_Graph (Graph *G, int n){
	int i,j;
	G->n =n;
	for(i=1; i<=n;i++){
		for(j=1; j<=n;j++)
			G->A[i][j] = 0;
	}
}

//them cung vao do thi(cap nhat trong so ma tran A)
void add_edge(Graph *G, int x, int y){// them cung tu dinh x -> dinh y
	G->A[x][y] = 1;
}

//kiem tra dinh x & y co la lang gieng hay khong
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] ==1;
}

//Tính s? b?c vào c?a 1 d?nh trong d? th? - b?c vào là b?c có mui tên di vào d?nh
int degreeInput(Graph *G, int x){
    int count=0,i;
    for(i=1;i<=G->n;i++){
        if(adjacent(G,i,x)){
            count++;
        }
    }
    return count;
}


//Tính s? b?c ra c?a 1 d?nh trong d? th? - B?c ra là s? mui tên di ra c?a d?nh dang xét d?n m?t d?nh khác
int degreeOutput(Graph *g, int x){
    int i,count=0;
    for(i=1;i<=g->n;i++){
        if(adjacent(g,x,i)){
            count++;
        }
    }
    return count;
}


//khoi tao ds rong
void make_null_list(List *list){
	list->size = 0;
}

//them 1 phan tu(dinh) vao cuoi ds
void push_back_list(List *list, int x){
	list -> data[list->size] = x;
	list -> size++;
}

//lay 1 phan tu(dinh) trong ds tai vi tri i
int element_at_list(List *list, int i){
	return list->data[i-1]; //do mang data bat dau tu vi tri thu 0
}

//ham kiem tra  list rong
bool empty_list(List* list){
	return (list->size == 0);
}
////Ex: can tim lang gieng dinh x
List neighbors(Graph *G, int x){
	List L;
	make_null_list(&L);
	int i;
	for(i=1; i<=G->n; i++){
		if(adjacent(G, x, i)){ //dinh i -> dinh x
			push_back_list(&L, i);
		}
	}
	return L;
}


//ham copy ds 
void copy_list(List* S1, List* S2){
	int i, x;
	make_null_list(S1);
	for(i=1;i<=S2->size;i++){
		x=element_at_list(S2, i);
		push_back_list(S1, x);
	}
}

//bien support
int k=0; //buoc lap k, hang cua do thi duoc gan cho buoc lap sau khi xep hang 1 dinh trong do thi xong
int rank[MAX_Vertices]; // mang luu tru hang tat ca cac dinh trong do thi
int d[MAX_Vertices]; // mang luu bac vao cua tat ca cac dinh trong do thi
List S1, S2; //ds s1 luu dinh bac vao = 0 (goc cu), s2 luu cac dinh ke v cua u co bac vao = 0( goc moi)

//Dua tren giai thuat tim kiem totpo
List topoSort(Graph *G){
    List toposort;
    make_null_list(&toposort);
    int u,n=G->n;
    
    for(u=1;u<=n;u++){
    	d[u]=0; //Khoi tao cac dinh co bac vao bang 0
	}
    for(u=1;u<=n;u++){
    	d[u] = degreeInput(G,u); //Tinh bac vao cho cac dinh luu vao d[]
	}
    make_null_list(&S1); //Khoi tao danh sach rong S1 luu dinh goc ( co bac vao bang 0)
    for(u=1;u<=n;u++) if(d[u]==0) push_back_list(&S1,u); 
    while(!empty_list(&S1)){ 
        make_null_list(&S2);
		int i, j; 
        for(i=1;i<=S1.size;i++){ 
            int u = element_at_list(&S1,i); 
            rank[u] = k; 
            push_back_list(&toposort,u);
            List L = neighbors(G,u);
            for(j=1;j<=L.size;j++){ 
                int v = element_at_list(&L,j); 
                d[v]--; 
                if(d[v]==0){ 
                    push_back_list(&S2,v);
                }
            }
        }
        copy_list(&S1,&S2);
        k++;
    
    }
    return toposort;
}
//Ham tim min
int min(int a, int b){
    return (a<b)?a:b;
}

//Ham tim max
int max(int a, int b){
    return (a>b)?a:b;
}
int main(){
    Graph G;
    int n, u, x, i, j, v;
    scanf("%d", &n);
    init_Graph(&G, n+2); 
    int time[100];
    time[n+1] = 0; // d[alpha] = 0
    for (u=1;u<=n;u++) {
        scanf("%d",&time[u]); 
        do{
            scanf("%d", &x); 
            if(x>0){ 
              add_edge(&G, x, u);   
            } 
        }while(x>0);
    }
    
    
    for(i=1;i<=n;i++){
        if(degreeInput(&G,i)==0){
            add_edge(&G,n+1,i);
    	}
    }
    
    
    for(i=1;i<=n;i++){
        if(degreeOutput(&G,i)==0){
            add_edge(&G,i,n+2);
        }
    }

    
    List L = topoSort(&G);
    
    int t[100];
    int T[100];
    
    t[n+1] = 0; 
    for (j=2;j<=L.size;j++){ 
        int u = element_at_list(&L,j); 
        t[u] = -1; 
        for (x=1;x<=G.n;x++){
            if (adjacent(&G,x,u)){ 
                t[u] = max(t[u], t[x] + time[x]); 
            }
        }
    }
    
    
    T[n+2] = t[n+2]; 
    for (j=L.size-1;j>=1;j--) { 
        int u = element_at_list(&L, j); 
        T[u] = oo; 
        for (v = 1; v <= G.n; v++){
            if (adjacent(&G,u,v)){ 
                T[u] = min(T[u], T[v] - time[u]); 
            }
        }
    }
    
    
    int a,b; 
   
    scanf("%d%d",&a,&b);
    
    if(b>= t[a] && b<= T[a]) printf("YES"); 
    
    else printf("NO"); 
        
    return 0;
}
