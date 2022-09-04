#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string quote[] = {"``", "''"};
  string line;
  int index = 0;
  while (getline(cin, line)) {
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '"') {
        cout << quote[index];
        index = (index + 1) % 2;

      } else {
        cout << line[i];
      }
    }
    cout << endl;
  }
  return 0;
}

