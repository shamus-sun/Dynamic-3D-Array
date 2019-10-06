// Author: Shamus French
// Purpose: Dynamically allocate memory for a 3d array,
//	      display array data in 2d form,
//	      dynamically deallocate the memory for the array
// Creation Date: 20191006
// Last Date Modified: 20191006

#include <iostream>
#include <array>

using namespace std;

//displays the 3d array in a 2d format with each set of numbers 
//representing the 3rd dimension
void display(int **d3Array[], int a, int b, int c) {
  for (int i = 0; i < a; i++) {
    cout << "\n";
    for (int j = 0; j < b; j++) {
      cout << "    ";
      for (int k = 0; k < c; k++) {
        cout << d3Array[i][j][k] << " ";
      }
    }
  }
}

int main() {
    int i, j, k;

    //get array dimensions from user input
    cout << "i = ";
    cin >> i;
    cout << "\nj = ";
    cin >> j;
    cout << "\nk = ";
    cin >> k;

    //dynamically allocate memory
    int ***x = new int**[i];

    for (int a = 0; a < i; a++) {
      x[a] = new int*[j];
      for (int b = 0; b < j; b++) {
        x[a][b] = new int[k];
        for (int c = 0; c < k; c++) {
          x[a][b][c] = i*j*k;
        }
      }
    }

    //display array contents
    display(x, i, j, k);

    //dynamically deallocate memory
    for (int a = 0; a < i; a++) {
      for (int b = 0; b < j; b++) {
        delete[] x[a][b];
      }
      delete[] x[a];
    }
    delete[] x;

    return 0;
}

