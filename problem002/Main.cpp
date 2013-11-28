/*
 * Author: Alec Johanson 
 * Date: 11/28/13
 *
 ***************************************************************************
 * ProjectEuler Problem 2:
 *
 *  Each new term in the Fibonacci sequence is generated by adding the two
 *  previous terms. By starting with 1 and 2. The first ten terms will be:
 *  1,2,3,5,8,13,21,34,55,89,....
 *
 *  By Considering the terms in the Fibonacci sequence whose values do not
 *  exceed four million, find the sum of the even valued terms.
 *
 ***************************************************************************
 * COMPILE: g++ Main.cpp
 * RUN: ./a.out
 *
 */
#include<stdio.h>
#include<iostream>

const int MAX_NUM = 4000000;

int Fibonacci(int secondToLast, int last);
int total = 0;

int main (int argc, const char** argv)
{
  total = 2; //Added because we are manually choosing 1 and 2 to start
  int secondToLastNum=1;
  int lastNum = 2;
  int temp;
  while (lastNum < MAX_NUM)
  {
    temp = Fibonacci(secondToLastNum, lastNum);
    secondToLastNum = lastNum;
    lastNum = temp;
    //Add if Even
    if (lastNum%2==0) 
    {
      total += lastNum;
    }
  }
  printf("Total - %d\n", total);
}

//Calculates the next number of the Fibonacci sequence
int Fibonacci(int secondToLastNum, int lastNum)
{
  return secondToLastNum + lastNum;
}

