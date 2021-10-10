/*Cho G=<V, E> là một đồ thị vô hướng đơn (không có khuyên, không có đa cung). Hãy viết chương trình kiểm tra xem có chứa chu trình hay không.

Chu trình là một đường đi đơn cung có đỉnh đầu trùng với đỉnh cuối.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

- m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v mô tả cung (u, v).

Đầu ra (Output):

In ra màn hình YES nếu đồ thị có chứa chu trình, ngược lại in ra NO

Xem thêm ví dụ bên dưới.



Hướng dẫn đọc dữ liệu và chạy thử chương trình
Để chạy thử chương trình, bạn nên tạo một tập tin dt.txt chứa đồ thị cần kiểm tra.
Thêm dòng freopen("dt.txt", "r", stdin); vào ngay sau hàm main(). Khi nộp bài, nhớ gỡ bỏ dòng này ra.
Có thể sử dụng đoạn chương trình đọc dữ liệu mẫu sau đây:
	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
*/
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
int cycle;
//mang kiem tra dinh duyet roi hay chua
int mark[MAX_Vertices];
int parent[MAX_Vertices];
/*Duyet DT bat dau tu dinh u*/
//DFS De Quy
void DFS_DeQuy(Graph *G, int u, int p){
	color[u]=gray;
	List list = neighbors(G, u);
	int i;
	for(i=1;i<=list.size;i++){
		int v = element_at(&list, i);
		if(v==p){
			continue;
		}
		if(color[v]==gray){
			cycle=1;//ton tai chu trinh
			return;
		}
		if(color[v]==white){
			DFS_DeQuy(G, v, u);
		}
	}
	color[u]=black;
}
//KT toan bo do thi
int contains_cycle(Graph *G){
	int i;
	for(i=1;i<=G->n;i++){
		color[i] = white;
	}
	cycle = 0;
	for(i=1;i<=G->n;i++){
		if(color[i]==white){
			DFS_DeQuy(G,i,0);
		}
	}
	return cycle;
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
	if(contains_cycle(&G)){
		printf("YES");
	}
	else printf("NO");
	return 0; 
} 
