/*
Cô giáo Trang chuẩn bị kẹo để phát cho các bé mà cô đang giữ. Dĩ nhiên môi bé đều có một tên gọi rất dễ thương ví dụ: Mạnh Phát, Diễm Quỳnh, Đăng Khoa, ... Tuy nhiên, để đơn giản vấn đề ta có thể giả sử các em được đánh số từ 1 đến n.
Cô giáo muốn rằng tất cả các em đều phải có kẹo. Cô lại biết thêm rằng có một số bé có ý muốn hơn bạn mình một chút vì thế các em ấy muốn kẹo của mình nhiều hơn của bạn.
Hãy viết chương trình giúp cô tính xem mỗi em cần được chia ít nhất bao nhiêu kẹo và tổng số kẹo ít nhất mà cô phải chuẩn bị là bao nhiêu.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số bé và số cặp bé mà trong đó có 1 bé muốn có kẹo hơn bạn mình..

- m dòng tiếp theo mỗi dòng chứa 2 số nguyên a, b nói rằng bé a muốn có kẹo nhiều hơn bé b.

Đầu ra (Output):

In ra màn hình số kẹo ít nhất của từng em, mỗi em trên một dòng.

Dòng cuối cùng in tổng số kẹo ít nhất mà cô giáo Trang cần phải chuẩn bị

Chú ý:

Xem thêm các ví dụ để hiểu thêm về đầu vào và đầu ra.

For example:

Input	  Result
3 2     3
1 3     1
3 2     2
        6
        
7 10    1
2 1     2
3 1     4
4 1     2
3 2     3
6 2     3
7 3     3
5 4     5
3 5     20
7 5 
7 6

*/
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
	G->A[y][x] = 1;
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
int k=1; //buoc lap k
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
	int sum=0;
    for(u=1;u<=n;u++){
        printf("%d \n",rank[u]);
        sum = sum + rank[u];
    }
    printf("%d",sum);
	return 0;
}
