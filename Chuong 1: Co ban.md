# 1. Các khái niệm cơ bản
- `Đồ thị (Graph) G` là một bộ đôi <V, E>, trong đó:
   - Tập các `đỉnh` (vertex set): `V`
   - Tập các `cung` (edge set): `E`, mỗi cung nối 2 đỉnh trong V
 
- Cung e nối 2 đỉnh x và y `e = (x,y)`
  - `x, y` `đầu mút` (endpoints) của cung e
  - x và y `kề nhau` (adjacent) `lân cận` (neighbours)
  - e `liên thuộc` (incident) với x và y
  
  ![image](https://user-images.githubusercontent.com/88178841/141613519-09829433-b79a-4e4f-872b-9868ce02d949.png)
- `Khuyên` (loop): cung có 2 `đầu mút trùng nhau`

![image](https://user-images.githubusercontent.com/88178841/141643913-72189034-416c-4554-b25e-80fb9a3110b5.png)

- `Đa cung` (multi edges): `các cung có cùng đầu mút`

![image](https://user-images.githubusercontent.com/88178841/141643965-c1dab42d-946b-48e8-a3a3-4f2908d1c3f4.png)

# 2. Các loại đồ thị
## a. Đồ thị vô hướng
### Định nghĩa

| ![icons8-typed.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/16-14-52-10-icons8-typed.png) Loại | ![icons8-agree.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/16-14-51-50-icons8-agree.png) Định nghĩa (`G = (V, E)`)                                                                                             | ![icons8-object.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/16-14-51-03-icons8-object.png) Mô hình                   |
| ------------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| **Đơn** đồ thị <br>(`Single Graph`)                                                                                      | Gồm một tập không rỗng `V` và một tập cạnh `E` là các cạnh không sắp thứ tự của các **đỉnh** phân biệt                                                                                                                                    | ![output-onlinepngtools (3).png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-20-02-23-output-onlinepngtools%20(3).png) |
| **Đa** đồ thị <br>(`MultiGraph`)                                                                                         | Gồm một tập các **đỉnh** `V`, một tập các **cạnh** `E` và một hàm `f` từ `E` tới `{{u, v}\|u, v ∈ V, u ≠ v}`<br>Các **cạnh** `e₁`, `e₂`<br>Gọi là **cạnh song song** (`parallel`) *hoặc* **cạnh bội** (`multiple`)<br>Nếu `f(e₁) = f(e₂)` | ![output-onlinepngtools (4).png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-20-03-07-output-onlinepngtools%20(4).png) |
| **Giả** đồ thị <br>(`Pseudo Graph`)                                                                                      | Gồm một tập các **đỉnh** `V` và một tập các **cạnh** `E` và một hàm `f` từ `E` tới `{{u, v}\|u, v ∈ V}`<br>Một **cạnh** là **khuyên** (`loop`) nếu<br>`f(e) = {u,u} = {u}` với đỉnh `u` nào đó                                            | ![output-onlinepngtools (5).png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-20-03-58-output-onlinepngtools%20(5).png) |

### Tính chất

| ![icons8-typed.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/16-14-52-10-icons8-typed.png) Loại | Cạnh có hướng                                                                                                               | Cạnh bội / đa cung                                                                                                                   | Khuyên                                                                                                                      |
| ------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| **Đơn** đồ thị (`Single Graph`)                                                                                          | ![icons8-delete.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-29-icons8-delete.png)       | ![icons8-delete.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-29-icons8-delete.png)       | ![icons8-delete.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-29-icons8-delete.png)       |
| **Đa** đồ thị (`MultiGraph`)                                                                                             | ![icons8-delete.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-29-icons8-delete.png)       | ![icons8-checkmark.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-07-icons8-checkmark.png) | ![icons8-delete.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-29-icons8-delete.png)       |
| **Giả** đồ thị (`Pseudo Graph`)                                                                                          | ![icons8-delete.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-29-icons8-delete.png)       | ![icons8-checkmark.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-07-icons8-checkmark.png) | ![icons8-checkmark.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-07-icons8-checkmark.png) |
---
### Bậc của đồ thị
- Bậc (degree) của đỉnh `deg(x)` số cung liên thuộc với đỉnh x
- `deg = 0` => đỉnh cô lập
- `deg = 1` => đỉnh treo
- Định lý 1 (định lý bắt tay): *Tổng bậc của tất cả các đỉnh = 2 lần số cung*
- Định lý 2: *Số `đỉnh bậc lẻ` của `DTVH` là số chẵn*

## b. Đồ thị có hướng
### Định nghĩa
| ![icons8-typed.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/16-14-52-10-icons8-typed.png) Loại | ![icons8-agree.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/16-14-51-50-icons8-agree.png) Định nghĩa (`G = (V, E)`)                                                                                             | ![icons8-object.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/16-14-51-03-icons8-object.png) Mô hình                   |
| ------------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| **Đồ** thị có hướng<br> (`Directed Graph`)                                                                               | Gồm tập các **đỉnh** `V` và một tập các **cạnh** `E` là các cặp `có thứ tự` của các phần tử **thuộc** `V`<br>Các cạnh ở đây được gọi là **cung** (`arc`)                                                                                  | ![output-onlinepngtools (6).png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-20-05-18-output-onlinepngtools%20(6).png) |
| **Đa** đồ thị có hướng<br> (`Directed MultiGraph`)                                                                       | Gồm một tập các **đỉnh** `V` và một tập các **cạnh** `E` và một hàm `f` từ `E` tới `{u, v \|u,v ∈ V}`<br>Các cạnh `e₁` và `e₂` là các **cạnh bội** nếu `f(e₁) = f(e₂)`                                                                    | ![output-onlinepngtools (7).png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-20-05-22-output-onlinepngtools%20(7).png) |

### Tính chất

| ![icons8-typed.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/16-14-52-10-icons8-typed.png) Loại | Cạnh có hướng                                                                                                               | Cạnh bội / đa cung                                                                                                                   | Khuyên                                                                                                                      |
| ------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| **Đồ** thị có hướng (`Directed Graph`)                                                                                   | ![icons8-checkmark.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-07-icons8-checkmark.png) | ![icons8-delete.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-29-icons8-delete.png)       | ![icons8-checkmark.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-07-icons8-checkmark.png) |
| **Đa** đồ thị có hướng (`Directed MultiGraph`)                                                                           | ![icons8-checkmark.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-07-icons8-checkmark.png) | ![icons8-checkmark.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-07-icons8-checkmark.png) | ![icons8-checkmark.png](https://raw.githubusercontent.com/Zenfection/Image/master/2021/06/15-18-24-07-icons8-checkmark.png) |
---
### Bậc của đồ thị
- `Bậc vào` của đỉnh `deg-(V)` = số cung đi đến V
- `Bậc ra` của đỉnh `deg+(V)` = số cung đi ra từ V
- Tính chất: `deg(V) = deg-(V) + deg+(V)`
- Định lý 3:

![image](https://user-images.githubusercontent.com/88178841/141644877-98930c19-a073-4d5d-8e36-a0d64a3d3074.png)

# 3. Đồ thị đặc biệt
## Đồ thị đầy đủ (complete graph)
- Kí hiệu: `Kn`
- `Đơn đồ thị vô hướng`
- `Mỗi cặp đỉnh` đều có `đúng 1 cung`

![image](https://user-images.githubusercontent.com/88178841/141644951-83adda09-8887-49a2-b437-7a908a382205.png)

## Đồ thị phân đôi (bipartite graph/bigraph)
- Kí hiệu `Kn,m`
- `Tập đỉnh` được chia thành `hai tập không giao nhau`: U và V
- `Mỗi cung` nối `1 đỉnh trong U` và `1 đỉnh trong V`

![image](https://user-images.githubusercontent.com/88178841/141645452-f481c923-25fe-458c-9c0b-2df2f2a8c8ad.png)

### Đồ thị phân đôi đầy đủ - 2 clique (biclique)
- Mỗi đỉnh của phần này nối với tất cả các đỉnh của phần kia

![image](https://user-images.githubusercontent.com/88178841/141645660-6fbfedcc-c2fa-4aea-9cec-e0026bea904c.png)

