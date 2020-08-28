// main.cpp
#include <iostream>

#include "arithmetic.h"
#include "statistics.h"

int main(int argc, char **argv){
  int arrayInt[] = {5, 3, 7, 8, 4};
  double arrayDouble[] = {2.5, 4.7, 3.7, 3.3, 9.3};

  std::cout << "Arithmetic Operations" << std::endl;

  std::cout << "  sum of arrayInt = " << sumInt(arrayInt, 5) << std::endl;
  std::cout << "  prod of arrayInt = " << prodInt(arrayInt, 5) << std::endl;

  std::cout << "  sum of arrayDouble = " << sumDouble(arrayDouble, 5) << std::endl;
  std::cout << "  prod of arrayDouble = " << prodDouble(arrayDouble, 5) << std::endl;

  std::cout << "Statistics Operations" << std::endl;

  std::cout << "  mean of arrayDouble = " << calcMean(arrayDouble, 5) << std::endl;
  std::cout << "  std of arrayDouble = " << calcStandardDeviation(arrayDouble, 5) << std::endl;

  return 0;
}
