// arithmetic.cpp
#include "arithmetic.h"

int sumInt(int *array, int size){
  int sum = 0;
  for(int i=0; i<size; i++){
    sum += array[i];
  }
  return sum;
}

int prodInt(int *array, int size){
  int prod = 1;
  for(int i=0; i<size; i++){
    prod = array[i] * prod;
  }
  return prod;
}

double sumDouble(double *array, int size){
  double sum = 0.0;
  for(int i=0; i<size; i++){
    sum += array[i];
  }
  return sum;
}

int prodDouble(double *array, int size){
  double prod = 1;
  for(int i=0; i<size; i++){
    prod = array[i] * prod;
  }
  return prod;
}
