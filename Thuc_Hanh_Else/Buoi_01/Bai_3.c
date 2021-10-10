int deg(Graph *G, int x){
    int deg=0, i;
    for(i=0; i<=G->n;i++){
        if(G->A[x][i]==1){
            deg++;
        }
    }
    return deg;
}
