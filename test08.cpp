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


TEST_CASE( "Test 08", "[Project01]" ) 
{
  double test, compare;
  int DFW, N, dfw, n;
  Course A("Biology", "bio101", 110, 02, "ali", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course B("Biology", "bio102", 110, 02, "ali", 
           /*A-F*/ 5, 10, 0, 1, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course C("physics", "phy101", 110, 02, "ali", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 90, 0, 0, 1);
  Course D("History", "his101", 110, 02, "ali", 
           /*A-F*/ 3, 20, 6, 1, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  
  College UIC("UIC");
  Dept CS("CS");
  dfw = n = 0;
  compare = 0.0;
  test = GetDFWRate(UIC, DFW, N);
  REQUIRE(DFW == dfw);
  REQUIRE(N == n);
  REQUIRE(abs(test - compare) <= 0.001);

  CS.addCourse(A);
  CS.addCourse(B);
  CS.addCourse(C);
  CS.addCourse(D);
  UIC.addDepartment(CS);
  
  dfw = 2;
  n = 16 + 30;
  
  test = GetDFWRate(UIC, DFW, N);
  compare = (dfw*100.0)/n;
  REQUIRE(DFW == dfw);
  REQUIRE(N == n);
  REQUIRE(abs(test - compare) <= 0.001);
}
