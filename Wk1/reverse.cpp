#include <iostream>

using namespace std;

int main()
{
  int n;
  int x[1000];

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> x[i];
  }
  for(int i=1;i<=n;i++){
    cout << x[n-i] << endl;
  }
}