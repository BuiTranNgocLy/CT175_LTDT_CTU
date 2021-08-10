#include <stdio.h>
int LonHonKhong(int a[100][100], int m, int n){
    int i,j, count;
   for(i = 0; i < m; i++){
   		for(j = 0; j < n; j++){
   			if(a[i][j]>0){
   				count ++;
			   }
			}
	}
	return count;    
}
 
int main(){
    int a[100][100];
    int m,n,i ,j;
   	scanf("%d \n",&m);
    scanf("%d ",&n);
    for(i = 0; i < m; i++){
    	for( j = 0; j < n; j++){
      		scanf("%d", &a[i][j]);
		}
	}
    printf("%d", LonHonKhong(a, m, n));
}
