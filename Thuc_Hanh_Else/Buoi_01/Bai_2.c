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
