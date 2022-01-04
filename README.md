![image](https://user-images.githubusercontent.com/88178841/148009642-e64ec225-b74c-4cff-9fbc-3bf33fcf7fa0.png)

# LÝ THUYẾT ĐỒ THỊ-GRAPH THEORY
## Chương 1. Cơ bản
[Slide bài giảng](https://bitly.com.vn/e6c4b7)
### 1.1 Các khái niệm cơ bản
- [Các khái niệm cơ bản](https://bitly.com.vn/2z7zh6)
- [Các loại đồ thị](https://bitly.com.vn/t09d61)
- [Một số dạng đồ thị vô hướng đặc biệt](https://bitly.com.vn/xr4q0f)
- [Đồ thị vô hướng nền](https://bitly.com.vn/v5qpzl)
- [Đồ thị con](https://bitly.com.vn/7f4s3d)
- [Sự đẳng cấu của đồ ](https://bitly.com.vn/5zvjfp)
### 1.2 Biểu diễn đồ thị
- Ma trận kề, ma trận trọng số, Ma trận liên thuộc đỉnh
cạnh
- Danh sách cạnh, Danh sách kề

### 1.3 Duyệt đồ thị
- Tìm kiếm theo chiều sâu - DFS
- Tìm kiếm theo chiều rộng - BFS

## Chương 2: Tính liên thông của đồ thị
[Slide bài giảng](https://bitly.com.vn/wtaxin)
- Tìm đường đi và kiểm tra tính liên thông
- `Thuật toán Tarjan` - tìm bộ phận liên thông mạnh

## Chương 3: TÌm đường đi ngắn nhất
[Slide bài giảng](https://bitly.com.vn/zrpcn4)
- Biểu diễn Đồ thị có trọng số
- Bài toán đường đi ngắn nhất
- Phát biểu bài toán
- Đường đi ngắn nhất xuất phát từ một đỉnh
  - `Thuật toán Moore - Dijkstra`
  - `Thuật toán Bellman - Ford`
- Đường đi ngắn nhất trên đồ thị không có chu trình
- Đường đi ngắn nhất giữa mọi cặp đỉnh (Thuật toán Floyd)

## Chương 4: Xếp hạng đồ thị & Tổ chức thi công
[Slide bài giảng](https://bitly.com.vn/9jbcwc)
- Xếp hạng các đỉnh đồ thị
   - Đồ thị có hướng không chu trình (DAG)
   - Giải thuật xếp hạng đồ thị
- Bài toán tổ chức thi công

## Chương 5. Cây và cây khung của đồ thị
### 5.1 Cây vô hướng
[Slide bài giảng](https://bitly.com.vn/x2sxx4)
- Cây và các tính chất của cây
- Cây khung của đồ thị
- `Thuật toán Kruskal` - cây khung tối thiểu_bài toán xây dựng
- `Thuật toán Prim`
### 5.2 Cây có hướng
[Slide bài giảng](https://bitly.com.vn/g207au)
- Cây và các tính chất của cây
- `Thuật toán Chu-Liu/Edmonds` 

## Chương 6. Bài toán luồng cực đại trong mạng
[SLide bài giảng](https://bitly.com.vn/qt38aw)
- Mạng, luồng và bài toán luồng cực đại
- Định lý Ford-Fulkerson
- `Thuật toán Ford-Fulkerson`

## Thực hành
### Cấu trúc quan trọng khi thực hành
- [Danh sách - List](https://bitly.com.vn/eho8yn)
- [Hàng đợi - Queue](https://bitly.com.vn/5gtar8)
- [Ngăn xếp - Stack](https://bitly.com.vn/ag5d8g)
### Buổi 1
[Tài liệu TH](https://bitly.com.vn/wwn26n)
- [Bài 1 - Ma trận đỉnh cung(add_edge)](https://bitly.com.vn/jmkwoh)
- [Bài 2 - Ma trận đỉnh - cung (neighbors)](https://bitly.com.vn/v9biyb)
- [Bài 3 - Ma trận đỉnh - đỉnh (degree)](https://bitly.com.vn/lf98q3)
- [Bài 4 - Bậc lớn nhất](https://bitly.com.vn/t0p56z)
- [Bài 5 - Danh sách cung](https://bitly.com.vn/wlfu62)
- [Bài 5.2 - Danh sách cung có điều kiện](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_01/Bai_5_2.c)
- [Bài 6 - Đọc đồ thị từ tập tin](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_01/Bai_6.c)
### Buổi 2
[Tài liệu TH](https://github.com/BuiTranNgocLy/CT175_LTDT_code_C/blob/main/Tai_Lieu_TH/Session2_T%C3%ADnh_Li%C3%AAn_Th%C3%B4ng.pdf)
- Bài 1 - Duyệt đồ thị
  - [1.1 Duyệt đồ thị theo chiều rộng (Queue)](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_1_1.c)
  - [1.2 Duyệt đò thị theo chiều sâu (Stack)](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_1_2.c)
  - [1.3 Duyệt đò thị theo chiều sâu (Đệ Quy)](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_1_3.c)  
- Bài 2 - Duyệt đồ thị & Dựng cây duyệt đồ thị
  - [2.1 - Duyệt & dựng đồ thị theo chiều rộng(QUEUE)](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_2_1.c)
  - [2.2 - Duyệt & dựng đồ thị theo chiều sâu(STACK)](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_2_2.c)
  - [2.3 - Duyệt & dựng đồ thị theo chiều sâu(Đệ Quy)](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_2_3.c)
- [Bài 3 - Đồ thị liên thông - Qua đảo](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_3.c)
- [Bài 4 - Tôn Ngộ Không](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_4.c)
- [Bài 5 - Kiểm tra chu trình - đồ thị vô hướng](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_5.c)
- [Bài 6 - Thuyền trưởng Haddock](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_02/Bai_6.c)
- Bài 7- Phân chia đội bóng
- Bài 8 - Kiểm tra tính liên thông mạnh - đếm số BPLT mạnh
  - 8.1 - Kiểm tra tính liên thông mạnh
  - 8.2 - Đếm số bộ phận liên thông mạnh
- Bài 9 - Come and Go
### Buổi 3
[Tài liệu TH](https://github.com/BuiTranNgocLy/CT175_LTDT_code_C/blob/main/Tai_Lieu_TH/Session3_%C4%90%C6%B0%E1%BB%9Dng_%C4%90i_Ng%E1%BA%AFn_Nh%E1%BA%A5t.pdf)
- Bài 1 - Tìm đường đi ngắn nhất
  - [1.1 - Tìm đường đi ngắn nhất - đơn đồ thị có hướng](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_03/Bai_1_1.c)
  - [1.2 - Tìm đường đi ngắn nhất - đơn đồ thị vô hướng](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_03/Bai_1_2.c)
- Bài 2 - Tìm đường đi ngắn nhất (Check được)
  - 2.1 - Kiểm tra chu trình âm - đơn đồ thị có hướng
  - 2.2 - Ứng dụng đường đi ngắn nhất - Ngưu Lang Chức Nữ
- Bài 3 - Kiểm tra chu trình âm và ứng dụng đường đi ngắn nhất
  - [3.1 - Kiểm tra chu trình âm của đồ thị có hướng(không khuyên, không đa cung)]
  - [3.2 - Bài toán Ngưu Lang](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_03/Bai_3_2.c)
- [Bài 4 - Ứng dụng đường đi ngắn nhất - Đất nước CyberGraph](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_03/Bai_3_2.c)
- Bài 5 - Mê cung số (Number Maze)
- Bài 6 - Bellman - Ford pi và pi
- Bài 7 - Bellman - Ford
- Bài 8 - Floyd - Warshall
- Bài 9 - Tìm số đường đi ngắn nhất (nâng cao)
### Buổi 4
[Tài liệu TH](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Tai_Lieu_TH/Session4_X%E1%BA%BFp%20h%E1%BA%A1ng%20%C4%91%C3%B2%20th%E1%BB%8B.pdf)
- [Bài 1- Xếp hạng đồ thị có hướng không chu trình](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_04/Bai_1.c)
- [Bài 2 - Cân đá](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_04/Bai_2_Can_Da.c)
- [Bài 3 - Chia kẹo](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_04/Bai_3_Chia_Keo.c)
- [Bài 4 - Tổ chức thi công - Dự án xây nhà](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_04/Bai_4.md)
- Bài 5 - Tổ chức thi công - Dự án phần mềm
  - [5.1 - Tổ chức thi công - Dự án phần mềm 1](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_04/Bai_5_1.md)
  - [5.2 - Tổ chức thi công - Dự án phần mềm 2](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Thuc_Hanh_Else/Buoi_04/Bai_5_2.md)
### Buổi 5
[Tài liệu TH - Cây khung tối thiểu](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Tai_Lieu_TH/Session5.1_C%C3%A2y%20khung%20t%E1%BB%91i%20thi%E1%BB%83u.pdf)
[Tài liệu TH - Luồng cực đại](https://github.com/BuiTranNgocLy/CT175_LTDT_CTU/blob/main/Tai_Lieu_TH/Session5.2_Lu%E1%BB%93ng%20c%E1%BB%B1c%20%C4%91%E1%BA%A1i.pdf)
- Bài 5.1. Tìm cây khung bằng giải thuật Kruskal
- Bài 5.2. tìm cây khung có trọng lượng nhỏ nhất bằng giải thuật Prim
- Bài 5.3. Tìm luồng cực đại trong mạngTrắc nghiệm
