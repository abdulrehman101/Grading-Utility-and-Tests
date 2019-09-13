 /*test01.cpp*/

//
// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases:
// 
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE( "Test 06", "[Project01]" ) 
{
  double test, compare;
  int DFW, N, dfw, n;
  Course A("Biology", "bio101", 110, 02, "ali", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course B("Biology", "bio101", 110, 02, "ali", 
           /*A-F*/ 5, 10, 0, 1, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course C("history", "his101", 110, 02, "Ahmed", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 1, 1);
  Course D("Biology", "bio101", 110, 02, "ali", 
           /*A-F*/ 5, 10.5, 3, 1, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 2, 1);
  Course empty;
  
  test = GetDFWRate(empty, DFW, N);
  REQUIRE(abs(test - 0.0) <= 0.001);
  REQUIRE(DFW == 0);
  REQUIRE(N == 0);
  
  test = GetDFWRate(A, DFW, N);
  REQUIRE(abs(test - 0.0) <= 0.001);
  REQUIRE(DFW == 0);
  REQUIRE(N == 0);
  
  test = GetDFWRate(C, DFW, N);
  REQUIRE(abs(test - 0.0) <= 0.001);
  REQUIRE(DFW == 0);
  REQUIRE(N == 0);
  
  test = GetDFWRate(B, DFW, N);
  dfw = 1;
  n = 16;
  REQUIRE(DFW == dfw);
  REQUIRE(N == n);
  compare = (dfw*100.0)/n;
  REQUIRE(abs(test - compare)<= .001);

  test = GetDFWRate(D, DFW, N);
  dfw = 3;
  n = 21;
  REQUIRE(DFW == dfw);
  REQUIRE(N == n);
  compare = (dfw*100.0)/n;
  REQUIRE(abs(test - compare) <= .001);
  
}
