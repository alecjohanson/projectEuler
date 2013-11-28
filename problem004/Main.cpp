/*
 * Author: Alec Johanson 
 * Date: 11/28/13
 *
 ***************************************************************************
 * ProjectEuler Problem 4:
 *
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 (91X99)
 *
 * Find the largest palindrome made from the product of two 3 digit numbers
 ***************************************************************************
 * COMPILE: g++ Main.cpp
 * RUN: ./a.out
 *
 */
#include<stdio.h>
#include<iostream>
//Prototypes
bool checkIfPalindrome(int num);
void runTests();

//Variables
bool runTheTests = false;

int main (int argc, const char** argv)
{
  if(runTheTests)
  {
    runTests();
    return 0;
  }

  int maxPalindrome = 0;
  for(int i=100;i<=999;i++)
  {
    for(int j=i;j<=999;j++)
    {
      if(checkIfPalindrome(i*j))
      {
        std::cout<<i << "*" <<j<<"=" << i*j << "\n";
        if(i*j > maxPalindrome)
          maxPalindrome = i*j;
      }
    }
  }
  printf("%d", maxPalindrome);
    return 0;
}

bool checkIfPalindrome(int num)
{
  //First three digits
  int firstThree;
  if (num < 99999) //numbers can only be five or six digits.
    firstThree = num/100;
  else
    firstThree = num/1000;

  //Last three digits
  int lastThree = num%1000;
  int tokens[6];

  /*
   *These could be abstracted to ((num/10^i)%10) I think
   */
  //First Digit
  tokens[0] = firstThree/100; //Integer division
  tokens[3] = lastThree/100;
  //Second Digit
  tokens[1] = (firstThree/10)%10;
  tokens[4] = (lastThree/10)%10;
  //Third Digit
  tokens[2] = firstThree%10;
  tokens[5] = lastThree%10;

//  for(int i=0;i<=5;i++)
//  {
//    std::cout << tokens[i] << "\n";
//  }

  if (tokens[0] + tokens[1] + tokens[2]
      != tokens[3] + tokens[4] + tokens[5])
    return false;
  
  if (tokens[0] == tokens[5]
      && tokens[1] == tokens[4]
      && tokens[2] == tokens[3])
    return true;

  return false;
}

void runTests()
{
  //Check 5 digits non palindrome
  if (!checkIfPalindrome(12345))
    std::cout << "[PASS] - 12345";
  else
    std::cout << "[FAIL] - 12345";
  std::cout << "\n";

  //Check 6 digits non palindrome
  if (!checkIfPalindrome(198520))
    std::cout << "[PASS] - 198520";
  else
    std::cout << "[FAIL] - 198520";
  std::cout << "\n";

  //Check 5 digits palindrome
  if (checkIfPalindrome(12321))
    std::cout << "[PASS] - 12321";
  else
    std::cout << "[FAIL] - 12321";
  std::cout << "\n";

  //Check 6 digits non palindrome
  if (checkIfPalindrome(198891))
    std::cout << "[PASS] - 198891";
  else
    std::cout << "[FAIL] - 198891";
  std::cout << "\n";

  if (!checkIfPalindrome(100*100))
    std::cout << "[PASS] - 100*100";
  else
    std::cout << "[FAIL] - 100*100";
  std::cout << "\n";

  if (checkIfPalindrome(121*121))
    std::cout << "[PASS] - 121*121";
  else
    std::cout << "[FAIL] - 121*121";
  std::cout << "\n";
}
