/*Cho cấu trúc dữ liệu đồ thị được khai báo sử dụng ma trận đỉnh - cung như sau:

typedef struct {
    int A[100][500];
    int n, m;
} Graph;
Giả sử đồ thị không chứa khuyên.

Viết hàm List neighbors(Graph* G, int x) trả về danh sách các đỉnh kề của x.

Chú ý: các đỉnh kề của x được sắp xếp theo thứ tự tăng dần và không trùng nhau. Ví dụ: nếu các đỉnh kề của 1 là 4 và 2 thì danh sách trả về chứa: 2 và 4.

Cấu trúc dữ liệu List được định nghĩa như bên dưới:

#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
ElementType data[MAX_ELEMENTS];
int size;
} List;

//Tao danh sach rong
void make_null(List* L) {
L->size = 0;
}
// Them mot phan tu vao cuoi danh sach
void push_back(List* L, ElementType x) {
L->data[L->size] = x;
L->size++;
}
// Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 
ElementType element_at(List* L, int i) {
return L->data[i-1];
}
// Tra ve so phan tu cua danh sach
int count_list(List* L) {
return L->size;
}*/

List neighbors(Graph *G, int x){
	int i,j; 
	List L;
	make_null(&L);
	for(i=1; i<=G->n; i++){
		if(i!=x){
			for(j=1;j<=G->m; j++){
				if((G->A[i][j]==1) && (G->A[j][i]==1)){
					push_back(&L, i);
					break;	
				}
			}
		}
	}
	return L;
}
