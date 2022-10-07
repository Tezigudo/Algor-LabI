
// /*A field of width Rand length C is divided into unit RxC cells of size1x1.
// Each cell is referred to by its row i (1<=i<=R) and its column j (1<=j<=C). N
// trees will be planted in N of these cells. For 1<=k<=N, tree k will be
// planted in the cell at row Ak and column Bk. Trees on the same row and trees
// on the same column look very beautiful together. You want to find a tree that
// maximizes the number of trees on the same row and the same column. Consider
// the following example where R = 5, C = 7, and N = 6. The trees will be
// planted in to the following cells The locations in the field can be shown
// below. The cells contain the tree number. For example, tree 1 will be planted
// at the cell at row A1=1 and column B1=3. You want to find the index k such
// that the number of trees in the same row or same column as tree k (including
// tree k itself) is maximized. If there are many trees, you should answer the
// smallest index. In the example above, there are 4 trees in the same row or
// same column with tree 2. There are also 4 trees in the same row or colum with
// tree 6. But you should answer the smallest index; therefore, the correct
// answer for this case is 2. Input The first line contains three integers R C
// and N. (1 <= R <= 100,000; 1 <= C <= 100,000; 1 <= N <= 100,000) There are
// test cases worth 30% points that R <= 100, C <= 100, and N <= 1,000. The next
// N lines describe the cell locations. More specifically, for 1<=k<=N, line 1+k
// contains two integers Ak and Bk (1<=Ak<=R; 1<=Bk<=C). No pairs of trees will
// be planted on the same cell. Output You program should output two integers:
// the index k of the tree with the maximum number of trees on the same row or
// column and the number of trees on the same row or column of tree k. Example
// Input:
// 5 7 6
// 1 3
// 3 3
// 3 1
// 5 6
// 5 4
// 3 4
// Output
// 2 4
// */

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// typedef pair<int, int> point;

// int main(){
//     int R, C, N;
//     cin >> R >> C >> N;
//     vector<int> row(R, 0);
//     vector<int> col(C, 0);
//     for(int i = 0; i < N; i++){
//         int r, c;
//         cin >> r >> c;
//         row[r-1]++;
//         col[c-1]++;
//     }
//     int max_row = *max_element(row.begin(), row.end());
//     int max_col = *max_element(col.begin(), col.end());
//     int max = max_row > max_col ? max_row : max_col;
//     int index = 0;
//     for(int i = 0; i < R; i++){
//         if(row[i] == max){
//             index = i;
//             break;
//         }
//     }
//     for(int i = 0; i < C; i++){
//         if(col[i] == max){
//             index = i;
//             break;
//         }
//     }
//     cout << index + 1 << " " << max << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

typedef pair<pair<int, int>, int> point;

// struct point{
//     int x, y;
//     int val;
//     point(int _x, int _y, int _val):{
//         x = _x;
//         y = _y;
//         val = _val;
//     }
// };

int main() {
  int r, c, n;
  cin >> r >> c >> n;
  // point a = make_pair(make_pair(0, 0), 0);
  point arr[r][c];

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      arr[i][j] = make_pair(make_pair(i, j), 0);
    }
  }

  for (int m = 0; m < n; m++) {
    int a, b;
    cin >> a >> b;
    for(int i=0;i<c;i++){
        arr[a-1][b-1].second = i;
    }
  }
}