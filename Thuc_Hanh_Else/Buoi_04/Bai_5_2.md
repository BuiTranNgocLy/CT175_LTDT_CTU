Việc thực hiện một dự án phát triển phần mềm được bố trí thành các công việc và thời gian thực hiện như sau:
![image](https://user-images.githubusercontent.com/88178841/141130992-9d7a3c7e-c5e4-4344-b1d7-5cf75a019b9b.png)

- Biết rằng dựa vào bảng công việc người ta có thể xác định thời điểm sớm nhất và trể nhất để bắt đầu cho mỗi công việc mà không ảnh hưởng đến tiến độ của dự án phần mềm. Trong danh sách các công việc thì Trưởng dự án cực kỳ quan tâm đến các công việc then chốt. Công việc then chốt là những công việc có thời gian sớm nhất và thời gian trể nhất bắt đầu công việc bằng nhau. Hãy viết chương trình cho trưởng dự án biết những công việc nào là công việc then chốt?

Để đơn giản trong cài đặt, ta đánh số lại các công việc theo thứ tự 1, 2, 3 thay vì A, B, C và lưu vào tập tin theo định dạng như sau:
![image](https://user-images.githubusercontent.com/88178841/141131119-f384695a-aec4-4ef9-a45f-b84f7f5abc46.png)

Đầu vào:

![image](https://user-images.githubusercontent.com/88178841/141131224-3cb6f81e-9fe6-4bcc-b470-cc85f2ce1a22.png)

Dòng đầu tiên là số công việc (12), các dòng tiếp theo mỗi dòng mô tả một công việc bao gồm d[u]: thời gian hoàn thành công việc u và danh sách các công việc trước đó của u. Danh sách được kết thúc bằng số 0. Ví dụ: công việc 1 (công việc A) có d[1] = 14 và danh sách các công việc trước đó rỗng.
Công việc 2 (công việc B) có d[2] = 12 và danh sách công việc trước đó là {1}.

Đầu ra:
Danh sách các công việc then chốt. Mỗi công việc trên một dòng.

Chú ý đọc dữ liệu:

![image](https://user-images.githubusercontent.com/88178841/141131455-80e9dd5a-1d1a-4f5b-a670-3b44effd6bd3.png)

![image](https://user-images.githubusercontent.com/88178841/141131554-62a1c303-4e89-4a5b-91ce-76632f383d0d.png)


CODE
````
#include <stdio.h>
#include <stdbool.h>
#define MAX_Vertices 100
#define MAX_Length 100
#define oo 9999999

//khai báo ma trận đỉnh đỉnh

typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n; //số lượng đỉnh
}Graph;

//khai báo cấu  ds list
typedef struct{
	int data[MAX_Length];
	int size;
}List;

//khởi tạo đồ thị
void init_Graph (Graph *G, int n){
	int i,j;
	G->n =n;
	for(i=1; i<=n;i++){
		for(j=1; j<=n;j++)
			G->A[i][j] = 0;
	}
}

//thêm cung vào đồ thị(cập nhật trọng số ma trận A)
void add_edge(Graph *G, int x, int y){// thêm cung từ đỉnh x -> đỉnh y
	G->A[x][y] = 1;
}

//kiểm tra đỉnh x & y có là láng giềng hay không
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] ==1;
}

//Tính số bậc vào của 1 đỉnh - bậc vào là bậc có mũi tên đi vào
int degreeInput(Graph *G, int x){
    int count=0,i;
    for(i=1;i<=G->n;i++){
        if(adjacent(G,i,x)){
            count++;
        }
    }
    return count;
}

//Tính số bậc ra của đồ thị - Bậc ra là số mũi tên đi ra của đỉnh đang xét đến 1 đỉnh khác
int degreeOutput(Graph *g, int x){
    int i,count=0;
    for(i=1;i<=g->n;i++){
        if(adjacent(g,x,i)){
            count++;
        }
    }
    return count;
}

//khởi tạo ds rỗng
void make_null_list(List *list){
	list->size = 0;
}

//thêm 1 phần tử(đỉnh) vào cuối ds
void push_back_list(List *list, int x){
	list -> data[list->size] = x;
	list -> size++;
}

//lấy 1 phần tử(đỉnh) trong ds tại vị trí i
int element_at_list(List *list, int i){
	return list->data[i-1]; //do mảng data bắt đầu từ vị trí thứ 0
}

//hàm kiểm tra  list rỗng
bool empty_list(List* list){
	return (list->size == 0);
}
////Ex: cần tìm láng giềng đỉnh x
List neighbors(Graph *G, int x){
	List L;
	make_null_list(&L);
	int i;
	for(i=1; i<=G->n; i++){
		if(adjacent(G, x, i)){ //đỉnh i -> đỉnh x
			push_back_list(&L, i);
		}
	}
	return L;
}
 
//hàm copy ds 
void copy_list(List* S1, List* S2){
	int i, x;
	make_null_list(S1);
	for(i=1;i<=S2->size;i++){
		x=element_at_list(S2, i);
		push_back_list(S1, x);
	}
}

//biến hỗ trợ
int k=0; //bước lặp k, hạng của đồ thị được gán cho bước lặp sau khi xếp hạng 1 đỉnh trong đồ thị xong
int rank[MAX_Vertices]; // Mảng rank[] để lưu hạng của tất cả các đỉnh trong đồ thị
int d[MAX_Vertices]; // Mảng d-Degree  để lưu số bậc vào của tất cả các đỉnh trong đồ thị
List S1, S2; //Danh sách L1 lưu những đỉnh có bậc vào bằng 0(gốc cũ), danh sách L2 lưu những đỉnh kề v của u có bậc vào bằng 0(gốc mới)

//Dựa trên giải thuật ranking để tìm thứ tự topo
List topoSort(Graph *G){
    List toposort;
    make_null_list(&toposort);
    int u,n=G->n;
    
    for(u=1;u<=n;u++){
    	d[u]=0; //Khởi tạo các đỉnh có bậc vào điều bằng 0
	}
    for(u=1;u<=n;u++){
    	d[u] = degreeInput(G,u); //Tính bậc vào cho các đỉnh rồi lưu vào mảng d[]
	}
    make_null_list(&S1); //Khởi tạo danh sách S1 lưu những đỉnh gốc(đỉnh có bậc vào bằng 0)
    for(u=1;u<=n;u++) 
      if(d[u]==0) push_back_list(&S1,u);//Những đỉnh nào là đỉnh gốc sẽ được cho vào danh sách 1(Gốc cũ) 
    while(!empty_list(&S1)){ //Duyệt trong khi S1 chưa rỗng 
        make_null_list(&S2);//Khởi tạo danh sách S2 để chứa các đỉnh kề v của u có bậc vào bằng 0(Gốcmới)
		    int i, j; 
        for(i=1;i<=S1.size;i++){ //Duyệt các đỉnh gốc vừa được thêm trong danh sách S1
            int u = element_at_list(&S1,i); //Lấy đỉnh gốc ra
            rank[u] = k; //Xếp hạng cho đỉnh gốc bằng bước lặp k
            push_back_list(&toposort,u); //Đưa đỉnh đó vào danh sách topo sau khi đã xếp hạng xong
            List L = neighbors(G,u); //Tìm đỉnh kề của đỉnh vừa được xếp hạng
            for(j=1;j<=L.size;j++){ //Duyệt các đỉnh kề
                int v = element_at_list(&L,j); //Lấy đỉnh kề
                d[v]--;//Giảm bậc đỉnh kề đi 1 tương đương với việc xóa đỉnh gốc u(gốc mới) ra khỏi đồthị
                if(d[v]==0){ //Nếu đỉnh kề v là đỉnh gốc(gốc mới)
                    push_back_list(&S2,v);  //Đưa đỉnh gốc mới vào danh sách S2
                }
            }
        }
        copy_list(&S1,&S2); //Sao chép các đỉnh gốc mới trong S2 sang 1
        k++;//Tăng bước lặp lên để xếp hạng cho các đỉnh tiếp theo trong danh sách S1
         //Khi nào danh sách S2 rỗng tức đỉnh gốc cũ không có đỉnh kề thì hiển nhiên -> Giải thuật kết thúc -> vì lúc này 1 đã rỗng
    }
    return toposort;
}
//Ham tim min
int min(int a, int b){
    return (a<b)?a:b;
}

//Ham tim max
int max(int a, int b){
    return (a>b)?a:b;
}
int main(){
    Graph G;
    int n, u, x, i, j, v;
    scanf("%d", &n);
    init_Graph(&G, n+2); //Đồ thị lúc này sẽ được thêm 2 đỉnh nữa là đỉnh alpha và beta
    int time[100]; //Mảng time lưu thời gian để thực hiện công việc 
    time[n+1] = 0; // d[alpha] = 0
    for (u=1;u<=n;u++) {
        scanf("%d",&time[u]); //Nhập thời gian hoàn thành công việc thứ u (u=1,2,3,...)
        do{
            scanf("%d", &x); //Nhập danh sách công việc trước đó phải làm của công việc u 
            if(x>0){ //Nếu không phải đỉnh alpha và beta
              add_edge(&G, x, u); //Thì thêm công việc trước đó của công việc u - thêm cung vào đồ thị    
            } 
        }while(x>0);//Nếu không có công việc trước đó hoặc nhập hết công việc trước đó thì dừng
    }
    
     //Thêm đỉnh alpha vào đồ thị
    for(i=1;i<=n;i++){
        if(degreeInput(&G,i)==0){
            add_edge(&G,n+1,i);//Nối đỉnh alpha vào đỉnh bắt đầu
    	}
    }
    
    //Thêm đỉnh beta vào đỉnh cuối
    for(i=1;i<=n;i++){
        if(degreeOutput(&G,i)==0){
            add_edge(&G,i,n+2);//Nối đỉnh beta vào đỉnh cuối
        }
    }

    //Muốn tìm thời gian trễ nhất và sớm nhất để bắt đầu công việc thì phải dựa trên thứ tự topo
    List L = topoSort(&G);
    
    int t[100];//Mảng lưu thời gian sớm nhất để bắt đầu công việc
    int T[100];//Mảng lưu thời gian trễ nhất để bắt đầu công việc
    
    t[n+1] = 0; //Khởi tạo t[alpha] = 0
    for (j=2;j<=L.size;j++){ //Bắt đầu từ đỉnh thứ 2 vì đỉnh thứ 1 đã là đỉnh alpha
        int u = element_at_list(&L,j); //Lấy đỉnh trong danh sách topo ra 
        t[u] = -1; //Gán t[u] bằng số nào đó > 0
        for (x=1;x<=G.n;x++){
            if (adjacent(&G,x,u)){ // Nếu u kề x
                t[u] = max(t[u], t[x] + time[x]); //Tính thời gian sớm nhất hoàn thành công việc
            }
        }
    }
    
    //Tìm thời điểm trễ nhất 
    T[n+2] = t[n+2]; //Khởi tạo T[beta] = t[beta]
    for (j=L.size-1;j>=1;j--) { //Bắt đầu bằng đỉnh trước đỉnh cuối vì đỉnh cuối đang là đỉnh beta
        int u = element_at_list(&L, j); //Lấy đỉnh trong danh sách topo ra 
        T[u] = oo; // Gán T[u] bằng vô cực
        for (v = 1; v <= G.n; v++){
            if (adjacent(&G,u,v)){ //Nếu v kể u
                T[u] = min(T[u], T[v] - time[u]); //Tính thời gian trễ nhất hoàn thành công việc
            }
        }
    }
    //Công việc then chốt là công việc bắt buộc phải làm đúng thời gian nên những công việc nào có t[] = T[] là những công việc then chốt
    for(u=1;u<=G.n;u++){
       if(t[u]==T[u]){
           printf("%d\n",u);
       }
   } 
        
    return 0;
}
````
