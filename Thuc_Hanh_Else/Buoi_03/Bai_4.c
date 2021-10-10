/*Đất nước CyberGraph có n thành phố và m con đường. Mỗi con đường nối 2 thành phố lại với nhau. tất cả các con đường đều là đường 2 chiều, mỗi con đường có một chiều dài nào đó. giữa hai thành phố có nhiều nhất là 1 con đường.

Tổng thổng của nước này dự định sẽ đi từ thành phố s đến thành phố t. Đương nhiên, ông ta sẽ chọn hành trình có tổng chiều dài các con đường đi qua ngắn nhất.

Hãy giúp Ngài tổng thổng tìm hành trình ngắn nhất đi từ s đến t.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số thành phố và số con đường.

- m dòng tiếp theo mỗi dòng chứa 3 số nguyên u v d mô tả con đường nối hai thành phố u và v có chiều dài d.

- Dòng cuối cùng chứa số nguyên s t là thành phố bắt đầu và kết thúc.

Đầu ra (Output):

In ra màn hình tổng chiều dài các con đường của hành trình ngắn nhất..

Xem thêm ví dụ bên dưới.

For example:

Input	Result
4 3	12
1 2 5
2 3 2
3 4 5
1 4

4 3	7
1 2 3
2 4 4
1 4 10
1 4

4 4	8
1 2 2
2 4 4
1 3 6
1 4 10
2 3
*/

#include<stdio.h>
#define MAX_Vertices 100 //dinh
#define MAX_Edges 500 //cung
#define MAX_Length 100
#define No_Edge -1
#define Infinity 9999999

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
void add_edge(Graph *G, int x, int y, int w){// them cung tu dinh x -> dinh y
	G->A[x][y] = w;
	G->A[y][x] = w;
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
	for (it = 1; it <= G->n; it++) {
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
	int n, m, u, v, w, i, s, t;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G,u,v,w);
	}
	scanf("%d%d", &s, &t);
	Dijkstra(&G, s);
	if(pi[n]==Infinity) printf("-1");
	else printf("%d",pi[t]);
	return 0;
}
