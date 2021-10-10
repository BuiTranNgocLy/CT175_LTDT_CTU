/*Cho một đồ thị vô hướng đơn. Hãy dựng (các) cây DUYỆT ĐỒ THỊ khi duyệt đồ thị theo chiều rộng bắt đầu từ đỉnh 1.

Nếu đồ thị không liên thông, sau khi duyệt xong lần 1, tìm đỉnh có chỉ số nhỏ nhất chưa duyệt mà duyệt nó, và cứ tiếp tục như thế cho đến khi tất cả các đỉnh đều được duyệt.

Quy ước:

Các đỉnh kề của 1 đỉnh được liệt kê theo thứ tự tăng dần


Đầu vào (Input):
Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

- m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng mô tả cung (u, v).

Đầu ra (Output):

In ra cây duyệt đồ thị theo định dạng:

1 <đỉnh cha của 1>
2 <đỉnh cha của 2>
....
i <đỉnh cha của i>
...
n <đỉnh cha của n>

Quy ước: Nếu 1 đỉnh không có đỉnh cha (nó là đỉnh gốc của cây) thì đỉnh cha của nó là 0.

Xem thêm các ví dụ bên dưới.



Gợi ý:

Sử dụng mảng parent[u] để lưu đỉnh cha của đỉnh u.
Trong quá trình duyệt, thay vì in các đỉnh ra màn hình, ghi nhận lại đỉnh cha của các đỉnh.
Khi duyệt xong lần lượt in ra u và parent[u] (u chạy từ 1 đến n).


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
Input
4 3
2 1
1 3
2 4
Result
1 0
2 1
3 1
4 2*/


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
