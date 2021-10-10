/*Cho c?u trúc d? li?u ð? th? ðý?c khai báo s? d?ng ma tr?n ð?nh - cung nhý sau:

typedef struct {
    int A[100][500];
    int n, m;
} Graph;
Gi? s? ð? th? vô hý?ng, không ch?a khuyên.

Vi?t hàm add_edge(Graph* G, int e, int x, int y) ð? thêm cung e = (x, y) vào ð? th? G.

void add_edge(Graph* G, int e, int x, int y) {
}*/

void add_edge(Graph *G, int e, int x, int y){
    G->A[x][e]=1;
    G->A[y][e]=1;
}
