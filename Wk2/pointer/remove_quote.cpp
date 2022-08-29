#include <iostream>
using namespace std;

void remove_quotes(char* src, char* dest) {
  int size = 0;
  while (*(src + size) != 0) {
    size++;
  }

  int quote_count = 0;
  for (int i = 0; i <= size; i++) {
    char alp = src[i];
    if (alp == '\'' || alp == '"') {
      quote_count += 1;
    } else {
        *(dest + i - quote_count) = alp;
    }
  }
}

int main() {
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st, 1000);
  remove_quotes(st, out);

  cout << out << endl;
}