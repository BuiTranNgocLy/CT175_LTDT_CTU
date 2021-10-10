#include<stdio.h>
#define MAX_Element 40
#define MAX_Vertices 20
#define MAX_Length 20

//khai bao cau truc hang doi (Queue)
typedef struct{
	int data[MAX_Element];
	int front;//chi so dau hang doi(lay DL)
	int indx; //chi so cuoi hang doi(them DL)
}Queue;

//khoi toa hang doi rong
void make_null_Queue(Queue *Q){
	Q->front = 0;
	Q->indx = -1;
}

//them 1 phan tu vao hang doi
void push_Queue(Queue *Q, int x){
	Q->indx++;
	Q->data[Q->indx] = x;
}

//kiem tra Queue co rng hay khong
int empty_Queue(Queue *Q){
	return Q->front > Q->indx;
}

//lay 1 phan tu o dau Queue
int top(Queue *Q){
	return Q->data[Q->front];
}

//cap nhat chi so front
void pop(Queue *Q){
	Q->front++;
}

