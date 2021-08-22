#include <stdio.h>
int main(){
    int h, i, j  ;
    scanf("%d",&h);
    for(i = 1; i <= h; i++) {
        for(j = 1; j <= h; j++) {
            if(j<=h-i){
            	printf(" "); 
			}
			else printf("*"); 
	   }
		printf("\n");
   }
   return 0; 
}




