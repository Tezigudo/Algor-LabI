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


int main() {
  int testcase;
  cin >> testcase;
  for (int time = 0; time < testcase; time++) {
    string blankline;
    getline(cin, blankline);
    if(time>0){
      cout << endl;
    }

    int n, m;
    cin >> n >> m;
    string word_arr[m];
    for (int i = 0; i < m; i++) {
      string word;
      cin >> word;
      word_arr[i] = word;
    }

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
      cout << word_arr[i] << ": " << word_sort[i] << endl;
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

// #include <iostream>

// using namespace std;

// typedef struct node
// {
//     string dna_line;
//     int sum_dna;
//     struct node *next;
// } node;

// int main()
// {
//     int many;
//     cin >> many;

//     for (int a = 0; a < many; a++)
//     {
//         cout << endl;
//         int long_dna, num_dna;
//         cin >> long_dna >> num_dna;
//         node *head_node = NULL;
//         node *keep_node = NULL;
//         for (int i = 0; i < num_dna; i++)
//         {
//             string dna;
//             cin >> dna;
//             node *new_node = (node *)malloc(sizeof(node));
//             int sum_num = 0;
//             for (int j = 0; j < long_dna; j++)
//             {
//                 for (int m = j; m < long_dna; m++)
//                 {
//                     if (dna[m] < dna[j])
//                     {
//                         sum_num += 1;
//                     }
//                 }
//             }
//             new_node->sum_dna = sum_num;
//             new_node->dna_line = dna;
//             if (i == 0)
//             {
//                 head_node = new_node;
//                 keep_node = new_node;
//             }
//             else if (sum_num < head_node->sum_dna)
//             {
//                 new_node->next = head_node;
//                 head_node = new_node;
//                 keep_node = new_node;
//             }
//             else
//             {
//                 while ((head_node->next != NULL) && (head_node->next->sum_dna < sum_num))
//                 {
//                     head_node = head_node->next;
//                 }
//                 new_node->next = head_node->next;
//                 head_node->next = new_node;
//             }

//             head_node = keep_node;
//         }
//         while (head_node->next != NULL)
//         {
//         cout << head_node->dna_line << ": " << head_node->sum_dna << endl;
//             head_node = head_node->next;
//         }
//         cout << head_node->dna_line << ": " << head_node->sum_dna << endl;
//     }
// }