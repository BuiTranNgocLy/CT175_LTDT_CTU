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
	for (it = 1; it < G->n; it++) {
		int min_pi = Infinity;
		for (j = 1; j <= G->n; j++){
			if (mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				i = j;
			}
		}
		mark[i] = 1;
		for (j = 1; j <= G->n; j++){
			if (G->A[i][j] != NO_Edge && mark[j] == 0) {
				if (pi[i] + G->A[i][j] < pi[j]) {
					pi[j] = pi[i] + G->A[i][j];
					p[j] = i;
				}
			}
		}
	}	
}

