/*Cho c?u tr�c d? li?u �? th? ��?c khai b�o s? d?ng ma tr?n �?nh - cung nh� sau:

typedef struct {
    int A[100][500];
    int n, m;
} Graph;
Gi? s? �? th? v� h�?ng, kh�ng ch?a khuy�n.

Vi?t h�m add_edge(Graph* G, int e, int x, int y) �? th�m cung e = (x, y) v�o �? th? G.

void add_edge(Graph* G, int e, int x, int y) {
}*/

void add_edge(Graph *G, int e, int x, int y){
    G->A[x][e]=1;
    G->A[y][e]=1;
}
