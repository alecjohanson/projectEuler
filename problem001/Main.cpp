/*
 * Author: Alec Johanson 
 * Date: 11/28/13
 *
 ***************************************************************************
 * ProjectEuler Problem 1:
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3,5,6, and 9.
 * The sum of these is 23
 *
 * Find the sum of all multiples of 3 and 5 below 1000
 ***************************************************************************
 * COMPILE: g++ Main.cpp
 * RUN: ./a.out
 *
 */

#include <stdio.h>

int const MAX_NUMBER = 1000;

int main (int argc, const char** argv)
{
  int sum=0;
  for (int i=0;i<MAX_NUMBER;i++)
  {
    if (i%3==0 || i%5==0)
      sum+=i;
  }
  printf("%d\n", sum);
  return 0;
}

