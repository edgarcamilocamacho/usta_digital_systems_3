// statistics.cpp
#include "statistics.h"

double calcMean(double *array, int size){
  double sum = sumDouble(array, size);
  return sum/size;
}

double calcStandardDeviation(double *array, int size){
  double mean = calcMean(array, size);
  double std = 0.0;
  for(int i=0; i<size; i++){
    std += pow(array[i] - mean, 2);
  }
  return sqrt(std/size);
}
