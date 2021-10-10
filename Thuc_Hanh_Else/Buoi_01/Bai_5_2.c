void add_edge(Graph *G, int x, int y){
    if(x>=1 && y>=1 && x<= G->n && y<=G->n){
        G->edges[G->m].x = x;
        G->edges[G->m].y = y;
        G->m++;
    }
}
