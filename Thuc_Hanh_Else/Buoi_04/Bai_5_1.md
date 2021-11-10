Việc thực hiện một dự án phát triển phần mềm được bố trí thành các công việc và thời gian thực hiện như sau:
![image](https://user-images.githubusercontent.com/88178841/141129852-bb305645-3563-46e9-91c2-b981bec115cb.png)
- Anh Tuấn là một thành viên trong nhóm phát triển phần mềm. Anh ta thường hay hỏi mọi thành viên trong nhóm các câu hỏi tương tự như sau: "Nếu công việc E mình bắt đầu làm vào ngày thứ 60 thì tổng thời gian thực hiện dự án có bị ảnh hưởng không?" "Nếu công việc H mình bắt đầu làm vào ngày thứ 50 thì tổng thời gian thực hiện dự án có bị ảnh hưởng không?". Anh ta hỏi mọi người hoài những câu hỏi tương tự như thế làm cho các thành viên trong nhóm bực bội. Biết rằng dựa vào bảng công việc người ta có thể xác định thời điểm sớm nhất và trể nhất để bắt đầu cho mỗi công việc mà không ảnh hưởng đến tiến độ của dự án phần mềm. Hãy viết chương trình để giúp anh Tuấn tự trả lời câu hỏi của mình. 

Để đơn giản trong cài đặt, ta đánh số lại các công việc theo thứ tự 1, 2, 3 thay vì A, B, C và lưu vào tập tin theo định dạng như sau:
![image](https://user-images.githubusercontent.com/88178841/141129991-f05c1165-57c5-47d8-8e8c-77050a564dff.png)
- Đầu vào:

![image](https://user-images.githubusercontent.com/88178841/141130115-4a0e5342-b40b-486a-9a9d-cbb3124f5d7a.png)

Dòng đầu tiên là số công việc (12), các dòng tiếp theo mỗi dòng mô tả một công việc bao gồm d[u]: thời gian hoàn thành công việc u và danh sách các công việc trước đó của u. Danh sách được kết thúc bằng số 0. Ví dụ: công việc 1 (công việc A) có d[1] = 14 và danh sách các công việc trước đó rỗng.
Công việc 2 (công việc B) có d[2] = 12 và danh sách công việc trước đó là {1}.
Dòng cuối cùng: công việc u và thời gian bắt đầu t, hai giá trị u và t tương ứng với câu hỏi của anh Tuấn:  "Nếu công việc u mình bắt đầu làm vào ngày thứ t thì tổng thời gian thực hiện dự án có bị ảnh hưởng không?"

Đầu ra:
Yes: Nếu ngày bắt đầu thực hiên công việc nằm trong thời điểm sớm nhất và trể nhất để bắt đầu công việc tương ứng.
No: Nếu ngày bắt đầu thực hiện công việc KHÔNG nằm trong thời điểm sớm nhất và trể nhất để bắt đầu công việc tương ứng.
Ví dụ: Công việc 5, mình có thể bắt đầu làm vào ngày thứ 60 được hay không? => YES (Vì Thời gian sớm nhất và thời gian trể nhất thực hiện công việc 5 là: 56-71, 60 nằm trong khoảng thời gian cho phép)

Chú ý đọc dữ liệu:

![image](https://user-images.githubusercontent.com/88178841/141130295-b7b74c92-eb3d-43ba-bdfe-c4a928992d35.png)

For example:
```
Input	      Result
12          YES
14 0
12 1 0
30 2 0
9 2 0
14 3 0
18 3 0
15 3 0
19 3 0
10 6 7 8 0
15 5 9 0
12 4 10 0
4 11 0
4 60

12          YES
14 0
12 1 0
30 2 0
9 2 0
14 3 0
18 3 0
15 3 0
19 3 0
10 6 7 8 0
15 5 9 0
12 4 10 0
4 11 0
5 60

12          NO
14 0
12 1 0
30 2 0
9 2 0
14 3 0
18 3 0
15 3 0
19 3 0
10 6 7 8 0
15 5 9 0
12 4 10 0
4 11 0
7 70
```





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
    int a,b; //Với a là công việc và b là thời gian công việc 
   
    scanf("%d%d",&a,&b); 
    
    if(b>= t[a] && b<= T[a]) printf("YES"); //Nếu thời gian b nằm trong khoảng [t;T] -> Dự án phần mềm không bị trễ tiến độ
    else printf("NO"); //Ngược lại 
    return 0;
}
```
