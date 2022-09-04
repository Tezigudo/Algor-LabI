#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int count_sort(string word, int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (word[i] > word[j]) {
        count++;
      }
    }
  }
  return count;
}
//! must use pointer to do with function
// void sorting(string word_arr[], int word_sort[], int size){
//  // do a bubble sort at here
//   bool changed = false;
//   while(not changed){
//     changed = false;
//     for(int i=0;i<size-1;i++){
//       if (word_sort[i] > word_sort[i+1]){
//         int temp = word_sort[i];
//         word_sort[i] = word_sort[i+1];
//         word_sort[i+1] = temp;

//         string str_temp = word_arr[i];
//         word_arr[i] = word_arr[i+1];
//         word_arr[i+1] = str_temp;

//         changed = true;
//       }
//     }
//   }
// }

int main() {
  int testcase;
  cin >> testcase;
  for (int time = 0; time < testcase; time++) {
    string blankline;
    getline(cin, blankline);
    int n, m;
    cin >> n >> m;
    string word_arr[m];
    for (int i = 0; i < m; i++) {
      string word;
      cin >> word;
      word_arr[i] = word;
    }
    cout << endl;

    int word_sort[m];
    for (int i = 0; i < m; i++) {
      word_sort[i] = count_sort(word_arr[i], n);
    }

    //* sort here
    while (true) {
      bool changed = false;
      for (int i = 0; i < m - 1; i++) {
        if (word_sort[i] > word_sort[i + 1]) {
          int temp = word_sort[i];
          word_sort[i] = word_sort[i + 1];
          word_sort[i + 1] = temp;

          string str_temp = word_arr[i];
          word_arr[i] = word_arr[i + 1];
          word_arr[i + 1] = str_temp;

          changed = true;
        }
      }
      if (!changed) {
        break;
      }
    }

    for (int i = 0; i < m; i++) {
      cout << word_arr[i] << endl;
    }
    if (time != testcase - 1) {
      cout << endl;
    }
  }
}

/*
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
*/
