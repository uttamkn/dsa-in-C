#include <stdio.h>
#define SIZE 3

typedef struct {
  char name[20];
  char usn[10];
  int age;
  float cgpa;
} student;
student s[SIZE];

int main() {
  for (int i = 0; i < SIZE; i++) {
    printf("enter the details of student %d: \n", i + 1);
    printf("Name: ");
    scanf("%s", s[i].name);
    printf("USN: ");
    scanf("%s", s[i].usn);
    printf("Age: ");
    scanf("%d", &s[i].age);
    printf("CGPA: ");
    scanf("%f", &s[i].cgpa);
  }

  for (int i = 0; i < SIZE; i++) {
    printf("\n========Details of student %d =========\n", i + 1);
    printf("Name: %s\nUSN: %s\nAge: %d\nCGPA: %.2f\n", s[i].name, s[i].usn,
           s[i].age, s[i].cgpa);
  }

  float cgpa;
  printf("Enter the required CGPA: ");
  scanf("%f", &cgpa);
  printf("Students with CGPA above %.2f are: \n", cgpa);
  for (int i = 0; i < SIZE; i++) {
    if (s[i].cgpa >= cgpa) {
      printf("\n===========================\n");
      printf("Name: %s\nUSN: %s\nAge: %d\nCGPA: %.2f\n", s[i].name, s[i].usn,
             s[i].age, s[i].cgpa);
    }
  }
  return 0;
}
