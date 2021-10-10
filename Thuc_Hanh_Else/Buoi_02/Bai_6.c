/*
Thuyền trưởng Haddock (truyện Tintin) là một người luôn say xỉn. Vì thế đôi khi Tintin không biết ông ta đang say hay tỉnh. Một ngày nọ, Tintin hỏi ông ta về cách uống. Haddock nói như thế này: Có nhiều loại thức uống (soda, wine, water, …), tuy nhiên Haddock lại tuân theo quy tắc “để uống một loại thức uống nào đó cần phải uống tất cả các loại thức uống tiên quyết của nó”. Ví dụ: để uống rượu (wine), Haddock cần phải uống soda và nước (water) trước. Vì thế muốn say cũng không phải dễ !
Cho danh sách các thức uống và các thức uống tiên quyết của nó. Hãy xét xem Haddock có thể nào say không ? Để làm cho Haddock say, ông ta phải uống hết tất cả các thức uống.
Ví dụ 1:
soda wine
water wine
Thức uống tiên quyết được cho dưới dạng a b, có nghĩa là để uống b bạn phải uống a trước. Trong ví dụ trên để uống wine, Haddock phải uống soda và water trước. Soda và water không có thức uống tiên quyết nên Haddock sẽ SAY.
Ví dụ 2:
soda wine
water wine
wine water
Để uống wine, cần uống water. Tuy nhiên để uống water lại cần wine. Vì thế Haddock không thể uống hết được các thức uống nên ông ta KHÔNG SAY.
Để đơn giản ta có thể giả sử các thức uống được mã hoá thành các số nguyên từ 1, 2, … và dữ liệu đầu vào được cho có dạng như sau (ví dụ 1):
3 2
1 2
3 2
Có loại thức uống (soda: 1, wine: 2 và water: 3) và có 2 điều kiện tiên quyết
1 -> 2 và 3 -> 2.
Với ví dụ 2, ta có dữ liệu:
3 3
1 2
3 2
2 3
Viết chương trình đọc dữ liệu các thức uống và kiểm tra xem Haddock có thể say không. Nếu có in ra “YES”, ngược lại in ra “NO”.
Đầu vào (Input):
Dữ liệu đầu vào được nhập từ bàn phím (stdin) với định dạng:
Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số thức uống và số điều kiện tiên quyết .
m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng thức uống u là tiên quyết của thức uống v.
Đầu ra (Output):
Nếu Haddock có thể say in ra YES, ngược lại in ra NO.
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
	//don do thi, k da cung  
//	G->A[x][y] = 1;
//	G->A[y][x] = 1;
	//da cung
//	G->A[x][y] +=1;
	//co huong
	G->A[x][y] =1; 
}

//kiem tra dinh x & y co la lang gieng hay khong
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
}

//tinh bac cua dinh x trong do thi
int degree(Graph *G, int x, int y){
	int deg = 0, i;
	for(i=1; i<=G->n;i++)
		if(G->A[i][x] == 1)// ton tai cung//if(adjacent(G, i, x))
			deg++;
	return deg;
}

//tinh bac da cung
//int degree(Graph *G, int x, int y){
//	int deg = 0, i;
//	for(i=1; i<=G->n;i++)
//		deg+=G->A[x][y];
//	return deg;
//}

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
int index;
//mang kiem tra dinh duyet roi hay chua
int mark[MAX_Vertices];
int parent[MAX_Vertices];
/*Duyet DT bat dau tu dinh u*/
//DFS
void dfs(Graph* G, int u) { 
	if(mark[u]==2) return; 
	//print("%d\n",x) 
	mark[u] = 2; 
	List list = neighbors(G, u);
	int i;
	for(i=1;i<=list.size;i++){ 
		int v = element_at(&list, i);
		if(mark[v] == 2){ 
			index = 1; 
			// Ton tai chu trinh return; 
		} dfs(G, v); } mark[u]=1;
	}
//ham check toan bo di thi
int check(Graph* G) { 
	int i,j;
	for(i=1;i<=G->n;i++){ 
		mark[i] = 0; 
	} 
	index = 0; 
	for( j=1;j<=G->n;j++){ 
		dfs(G, j); 
	} 
	return index;
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
	dfs(&G, 1);
//	for(i=1;i<=n;i++){
//		printf("%d %d\n", i, parent[i]);
//	}
	if(!check(&G)){
		printf("YES");
	}
	else printf("NO");
	return 0; 
} 
