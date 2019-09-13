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


TEST_CASE( "Test 09", "[Project01]" ) 
{
  GradeStats test;
  
  REQUIRE(test.N == 0);
  REQUIRE(test.NumA == 0);
  REQUIRE(test.NumB == 0);
  REQUIRE(test.NumC == 0);
  REQUIRE(test.NumD == 0);
  REQUIRE(test.NumF == 0);
  REQUIRE(abs(test.PercentA) <= 0.001);
  REQUIRE(abs(test.PercentB) <= 0.001);
  REQUIRE(abs(test.PercentC) <= 0.001);
  REQUIRE(abs(test.PercentD) <= 0.001);
  REQUIRE(abs(test.PercentF) <= 0.001);
  
  GradeStats test1
  (20,10,4,3,2,1,50.0,20.0,15.0,10.0,5.0);
  REQUIRE(test1.N == 20);
  REQUIRE(test1.NumA == 10);
  REQUIRE(test1.NumB == 4);
  REQUIRE(test1.NumC == 3);
  REQUIRE(test1.NumD == 2);
  REQUIRE(test1.NumF == 1);
  REQUIRE(abs(test1.PercentA - 50.0) <= 0.001);
  REQUIRE(abs(test1.PercentB - 20.0) <= 0.001);
  REQUIRE(abs(test1.PercentC - 15.0) <= 0.001);
  REQUIRE(abs(test1.PercentD - 10.0) <= 0.001);
  REQUIRE(abs(test1.PercentF - 5.0) <= 0.001);


  Course A("Biology", "bio101", 110, 02, "ali", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
  Course B("Biology", "bio102", 110, 02, "ali", 
           /*A-F*/ 10,4,3,2,1, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course C("physics", "phy101", 110, 02, "ali", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 90, 0, 0, 1);
  Course D("History", "his101", 110, 02, "ali", 
           /*A-F*/ 3, 20, 6, 1, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  
  test = GetGradeDistribution(A);
  test1 = GetGradeDistribution(B);
  
  REQUIRE(test.N == 0);
  REQUIRE(test.NumA == 0);
  REQUIRE(test.NumB == 0);
  REQUIRE(test.NumC == 0);
  REQUIRE(test.NumD == 0);
  REQUIRE(test.NumF == 0);
  REQUIRE(abs(test.PercentA) <= 0.001);
  REQUIRE(abs(test.PercentB) <= 0.001);
  REQUIRE(abs(test.PercentC) <= 0.001);
  REQUIRE(abs(test.PercentD) <= 0.001);
  REQUIRE(abs(test.PercentF) <= 0.001);

  REQUIRE(test1.N == 20);
  REQUIRE(test1.NumA == 10);
  REQUIRE(test1.NumB == 4);
  REQUIRE(test1.NumC == 3);
  REQUIRE(test1.NumD == 2);
  REQUIRE(test1.NumF == 1);
  REQUIRE(abs(test1.PercentA - 50.0) <= 0.001);
  REQUIRE(abs(test1.PercentB - 20.0) <= 0.001);
  REQUIRE(abs(test1.PercentC - 15.0) <= 0.001);
  REQUIRE(abs(test1.PercentD - 10.0) <= 0.001);
  REQUIRE(abs(test1.PercentF - 5.0) <= 0.001);
}
