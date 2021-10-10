#include<stdio.h>
#define MAX_Vertices 20
#define MAX_Element 40

//khai bao cau truc cua stack
typedef struct{
	int data[MAX_Element];
	int size; // kich thuoc stack
}Stack; 

//khoi tao stack rong
void make_null_stack(Stack *stack){
	stack->size=0;
}

//them 1 phan tu vao stack
void push_stack(Stack *stack, int x){
	stack->data[stack->size]=x;
	stack->size++;
}


//lay 1 phan tu trong stack
int top(Stack *stack){
	return stack->data[stack->size-1];
}

//xoa 1 phan tu thuoc stack
void pop(Stack *stack){
	stack->size--;
}
//kiem tra stack co rong hay khong
int empty(Stack *stack){
	return stack->size == 0;
}

//DFS
void depth_first_search(Graph *G, int x){
	Stack s;
	make_null_stack(&s);
	push_stack(&s, x);
	//khoi tao ds luu cac dinh da duyet
	List list_dfs;
	make_null(&list_dfs);
	//khoi tao tat ca cac dinh chua duoc duyet
	int mark[MAX_Vertices];//mang danh dau dinh da duoc duyet chua
	int i,j;
	for(i=1; i<=G->n; i++){
		mark[i] = 0; //tat ca cac dinh chua duoc duyet
	}
	while(!empty(&s)){
		int u = top(&s);
		pop(&s);
		if(mark[u]==1)
			continue;
		push_back(&list_dfs, u);//dua dinh u da duyet vao ds
		mark[u] = 1;
		List list = neighbors(G, u);//cac dinh e v cua u
		for(i=1; i<=list.size; i++){
			int v = element_at(&list, i);
			if(mark[v]==0)
				push_stack(&s,v);
		}
	}
	return list_dfs;	
} 

