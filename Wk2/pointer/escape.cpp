#include <iostream>
using namespace std;

char* write_chars(char* dest, const char* st) { return dest; }


void escape(char* src, char* dest) {
  int size = 0;
  while (*(src + size) != 0) {
    size++;
  }
  int total_count = 0;
  char less[] = "&lt;";
  char more[] = "&gt;";
  char quote[] = "&quot;";

  for (int i = 0; i < size; i++) {
    if (src[i] == '<') {
      for (int j = 0; j < 4; j++) {
        *dest = less[j];
        dest++;
        total_count++;
      }
    } else if (src[i] == '>') {
      for (int j = 0; j < 4; j++) {
        *dest = more[j];
        dest++;
        total_count++;
      }
    } else if (src[i] == '"') {
      for (int j = 0; j < 6; j++) {
        *dest = quote[j];
        dest++;
        total_count++;
      }
    } else {
        *dest = src[i];
        dest++;
        total_count++;
    }
  }
  dest-=total_count;
  *(dest+total_count) = '\0';
}


int main() {
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st, 1000);
  escape(st, out);

  cout << out << endl;
}