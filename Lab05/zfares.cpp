#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      cout << arr[i][j] << ";";
    }
    cout << endl;
  }
}

int findM(int arr[], int n) {
  int m = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > m)
      m = arr[i];
  return m;
}

void countingSort(vector<int> arr[], int x, int index) {
  int max = 4;
  vector<int> *outputArr = new vector<int>[x];
  int lim[10] = {0};
  for (int i = 0; i < x; i++) {
    lim[arr[i][index]]++;
  }
  for (int i = 1; i < 10; i++) {
    lim[i] = lim[i] + lim[i - 1];
  }
  for (int i = x - 1; i >= 0; i--) {
    outputArr[lim[arr[i][index]] - 1] = arr[i];
    lim[(arr[i][index])]--;
  }
  for (int i = 0; i < x; i++) {
    arr[i] = outputArr[i];
  }
}

void radixSort(vector<int> arr[], int x) {
  // int m = getMax(arr,x);
  for (int i = 10; i > 0; i--) {
    countingSort(arr, x, i - 1);
  }
}

int main() {
  int n = 1;
  cin >> n;

  vector<int> *arr = new vector<int>[n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      int hold;
      cin >> hold;
      arr[i].push_back(hold);
    }
  }

  radixSort(arr, n);
  for (int i = 0; i < n; i++) {
    vector<int>::iterator v = arr[i].begin();

    while (v != arr[i].end()) {
      cout << *v << ";";
      v++;
    }

    cout << endl;
    // print
  }
}