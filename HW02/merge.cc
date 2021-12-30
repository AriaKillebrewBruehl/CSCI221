// Aria Killebrew Bruehl, HW02 Exercise 3: Merge
#include <iostream>

void sort(int *A, int n) {
  // sort A using insertion sort
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0 and A[j] < A[j - 1]; j--) {
      if (A[j] < A[j - 1]) {
        int temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
      }
    }
  }
}

void output(int *A, int size) {
  // create bracketted list of A
  std::cout << "[" << A[0];
  if (size > 1) {
    for (int i = 1; i < size; i++) {
      std::cout << ", " << A[i];
    }
  }
  std::cout << "]" << std::endl;
}

int main() {
  // gets input of sequence size and values of two sequences, then return the
  // sorted sequences
  std::cout << "Enter the first sequence size: ";
  int size1;
  std::cin >> size1;
  int *seq1 = new int[size1];

  std::cout << "Enter its values below: " << std::endl;
  int i = 0;
  while (i < size1) {
    std::cin >> seq1[i];
    i += 1;
  }
  std::cout << "Okay. Now enter the second sequence size: ";
  int size2;
  std::cin >> size2;
  int *seq2 = new int[size2];

  std::cout << "Enter its values below: " << std::endl;
  i = 0;
  while (i < size2) {
    std::cin >> seq2[i];
    i += 1;
  }

  sort(seq1, size1);
  sort(seq2, size2);
  std::cout << "Thanks. Those sequences, sorted, are: \n";
  output(seq1, size1);
  output(seq2, size2);

  delete[] seq1;
  delete[] seq2;
  return 0;
}
