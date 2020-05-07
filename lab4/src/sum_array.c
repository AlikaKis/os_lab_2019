#include "sum_array.h"

#include <stdio.h>
#include <stdlib.h>

int Sum(int* array, int begin, int end) {
  int sum = 0;
  int i;
  for(i = begin; i <= end; i++)
  {
      
	sum += array[i];
        
  }
  return sum;
}