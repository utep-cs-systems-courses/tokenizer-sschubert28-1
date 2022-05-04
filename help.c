#include <stdio.h>

struct student {
  char name[50];
  int age;
  int year;
  float gpa;
};

void printValue(struct student s) {
  printf("\nName: %s", s.name);
  printf("\nAge: %d", s.age);
  printf("\nYear: %d", s.year);
  printf("\nGPA: %f", s.gpa);
}

void printReference(struct student *s) {
  printf("\nName: %s", s->name);
  printf("\nAge: %d", s->age);
  printf("\nYear: %d", s->year);
  printf("\nGPA: %f", s->gpa);
}

int main()
{
  struct student s1;
  struct student s2;
  struct student s3;

  printf("\nEnter name: ");
  scanf("%s", &s1.name);
  printf("\nEnter age: ");
  scanf("%d", &s1.age);
  printf("\nEnter year: ");
  scanf("%d", &s1.year);
  printf("\nEnter gpa: ");
  scanf("%f", &s1.gpa);

  printf("\nEnter name: ");
  scanf("%s", &s2.name);
  printf("\nEnter age: ");
  scanf("%d", &s2.age);
  printf("\nEnter year: ");
  scanf("%d", &s2.year);
  printf("\nEnter gpa: ");
  scanf("%f", &s2.gpa);

  printf("\nEnter name: ");
  scanf("%s", &s3.name);
  printf("\nEnter age: ");
  scanf("%d", &s3.age);
  printf("\nEnter year: ");
  scanf("%d", &s3.year);
  printf("\nEnter gpa: ");
  scanf("%f", &s3.gpa);

  printValue(s1);
  printValue(s2);
  printValue(s3);

  printReference(&s1);
  printReference(&s2);
  printReference(&s3);
  
  return 0;
}
