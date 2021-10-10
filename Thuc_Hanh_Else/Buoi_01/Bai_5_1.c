void add_edge(Graph *G, int x, int y){
    G->edges[G->m].x = x;
    G->edges[G->m].y = y;
    G->m++;
}
