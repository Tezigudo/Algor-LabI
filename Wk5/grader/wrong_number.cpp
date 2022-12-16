
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int table[N][N];
    int row_sum[N];
    int col_sum[N];
    int wrong_row, wrong_col;
    int wrong_num;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
            sum += table[i][j];
        }
        row_sum[i] = sum;
        sum = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += table[j][i];
        }
        col_sum[i] = sum;
        sum = 0;
    }
    int true_row_val = row_sum[0] == row_sum[1] || row_sum[0] == row_sum[2]
                           ? row_sum[0]
                           : row_sum[1];
    for (int i = 0; i < N; i++) {
        if (row_sum[i] != true_row_val) {
            wrong_row = i;
            break;
        }
    }
    int true_col_val = col_sum[0] == col_sum[1] || col_sum[0] == col_sum[2]
                           ? col_sum[0]
                           : col_sum[1];
    for (int i = 0; i < N; i++) {
        if (col_sum[i] != true_col_val) {
            wrong_col = i;
            break;
        }
    }
    wrong_num = table[wrong_row][wrong_col];
    cout << wrong_num << endl;
    return 0;
}