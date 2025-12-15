#include <stdio.h>

using namespace std;

int main() {

  int a, b;
  scanf("%d %d", &a, &b);

  printf("%.10lf\n", (double)a / b);
  
  return 0;
}