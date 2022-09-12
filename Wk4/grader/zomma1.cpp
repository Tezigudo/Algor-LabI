#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> lst, int target) {
  for (int i = 0; i < lst.size(); i++) {
    if (lst[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n, m;
  int d, p;
  vector<int> c, balls;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int  num;
    cin >> num;
    c.push_back(num);
    balls.push_back(i + 1);
  }
  for (int i = 0; i < m; i++) {
    cin >> d >> p;

    int idx = find(balls, p);
    balls.insert(balls.begin() + idx + 1, i + n + 1);
  }

  for (int i = 0; i < balls.size(); i++) {
    cout << balls[i] << endl;
  }
}
