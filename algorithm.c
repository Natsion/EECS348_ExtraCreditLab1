// Abinav Krishnan
// Febuary 18, 2023

#include <stdio.h>

int main() {

  int departments[5][5];
  int programmers[5][5];
  
  int department_to_programmer[5];
  int programmer_to_department[5][5];

  printf("Input: \n\n");

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      scanf(" %d", & departments[j][i]);
    }
  }

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      scanf(" %d", & programmers[j][i]);
    }
  }

  for (int i = 0; i < 5; i++) {
    department_to_programmer[i] = -1;
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      programmer_to_department[i][programmers[i][j] - 1] = j;
    }
  }

  for (int count = 0; count < 5; count++) {
    for (int i = 0; i < 5; i++) {
      if (department_to_programmer[i] == -1) {
        int j = 0;
        while (department_to_programmer[i] == -1 && j < 5) {
          int programmer = departments[i][j] - 1;
          if (programmer_to_department[programmer][i] == count) {
            department_to_programmer[i] = programmer;
          }
          j++;
        }
      }
    }
  }

  
  for (int i = 0; i < 5; i++) {
    printf("\nDepartment #%d will get Programmer #%d", i + 1, department_to_programmer[i] + 1);
  }

  return 0;
}