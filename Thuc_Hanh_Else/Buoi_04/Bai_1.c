#include <stdio.h>
#define MAX_Vertices 100
#define MAX_Length 20

//khai bao ma tran dinh dinh
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;// so luong dinh
}Graph;

//khoi tao do thi
void init_Graph (Graph *G, int n){
	int i,j;
	G->n =n;;
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
	return G->A[x][y] != 0;
}

//tinh bac cua dinh x trong do thi
	//da cung
int degree(Graph *G, int x){
	int count=0,y;
	for(y=1;y<=G->n;y++){
		if(G->A[y][x]==1){
			count++;
		}
	}
	return count; 
} 

//khai bao cau truc ds list
typedef struct{
	int data[MAX_Length];
	int size;
}List;

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

////Ex: can tim lang gieng dinh x
List neighbors(Graph *G, int x){
	List L;
	make_null_list(&L);
	int i;
	for(i=1; i<=G->n; i++){
		if(G->A[i][x] == 1){ //dinh i -> dinh x
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
int k=0; //buoc lap k
int rank[MAX_Vertices]; // mang luu tru hang dinh u
int d[MAX_Vertices]; // mang luu bac vao cua dinh u
List S1, S2; //ds s1 luu dinh goc cu, s2 luu cac din goc moi

void ranking(Graph* G){
	int u,v,i;
	
	for(u=1;u<=G->n;u++){
		//d[u] = 0; //khoi tao bac vao cua ta ca cac dinh = 0
		rank[u]=0;
	}
	
	//tinh bac vao cua tat ca cac dinh trong do thi
	for(u=1;u<=G->n;u++){
		d[u] = degree(G,u);
	}
	
	//khoi tao ds chua dinh goc o buoc lap k
	make_null_list(&S1);
	
	for(u=1;u<=G->n;u++){
		if(d[u]==0){ // chon dinh goc co bac vao bang 0 da tinh o tren
			push_back_list(&S1, u); //dua dinh do vao ds S1
		}
	}
	
	while(S1.size>0){ //lap khi S1 chua rong
		make_null_list(&S2); //khoi tao ds S2 luu cac dinh ke v cua u co bac vao = 0
		for(i=1;i<=S1.size;i++){
			u=element_at_list(&S1, i); //lay dinh u trong ds s1 tai vi tri i
			rank[u]=k; //tinh rank[u] = buoc lap k
			for(v=1;v<=G->n;v++){ //tim cac dinh v ke u
				if(G->A[u][v]!=0){ // neu v la dinh ke u
					d[v]--; //giam bac cua v
					if(d[v]==0) //sau khi giam bac cua v = 0(nut goc) => dua vao ds S2
						push_back_list(&S2, v); // dua v vao S2
				}
			}
		}
		copy_list(&S1, &S2);//lay cac dinh trong S2 vao S1 de tiep tuc xet
		k++; //tang buoc lap k tiep tuc thuat toan
	}
}
int main(){
	Graph G;
	//doc tap tin
	//freopen("dothi.txt","r", stdin);
	int n, m; //n sl dinh, m sl cung 
	scanf("%d%d", &n , &m); 
	
	//doc ds dinh 
	init_Graph(&G, n); 
	int u, v, e; //dinh u -> dinh v 
	
	//doc ds cung
	for(e=1; e<=m; e++){
		scanf("%d%d", &u, &v); 
		add_edge(&G, u, v);	
	} 
	ranking(&G);
	for(u=1;u<=n;u++){
		printf("%d \n",rank[u]);
	}
	return 0;
}
