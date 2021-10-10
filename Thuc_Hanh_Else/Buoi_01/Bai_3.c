/* Cho cấu trúc dữ liệu đồ thị được khai báo sử dụng ma trận đỉnh - đỉnh như sau:

typedef struct {
    int A[100][100];
    int n;
} Graph;
Giả sử đồ thị vô hướng, không chứa khuyên, không chứa đa cung

Viết hàm int deg(Graph* G, int x) để tính bậc của đỉnh x.

int deg(Graph* G, int x) {
}*/
int deg(Graph *G, int x){
    int deg=0, i;
    for(i=0; i<=G->n;i++){
        if(G->A[x][i]==1){
            deg++;
        }
    }
    return deg;
}
