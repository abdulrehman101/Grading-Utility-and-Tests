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


TEST_CASE( "Test 10", "[Project01]" ) 
{
  GradeStats test, test1;
  Dept CS("CS");
  Dept Bio("Biology");
  
  Course A("Biology", "bio101", 110, 02, "ali", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 1, 1);
  Course B("Biology", "bio102", 110, 02, "ali", 
           /*A-F*/ 10,4,3,9,1, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course C("physics", "phy101", 110, 02, "ali", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 90, 0, 1, 1);
  Course D("History", "his101", 110, 02, "ali", 
           /*A-F*/ 3, 20, 6, 1, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  
  CS.addCourse(A);
  CS.addCourse(B);
  CS.addCourse(C);
  CS.addCourse(D);
  
  Bio.addCourse(A);
  Bio.addCourse(C);


  test = GetGradeDistribution(CS);
  test1 = GetGradeDistribution(Bio);

  REQUIRE(test.N == 57);
  REQUIRE(test.NumA == 13);
  REQUIRE(test.NumB == 24);
  REQUIRE(test.NumC == 9);
  REQUIRE(test.NumD == 10);
  REQUIRE(test.NumF == 1);
  REQUIRE(abs(test.PercentA - 22.81) <= 0.01);
  REQUIRE(abs(test.PercentB - 42.11) <= 0.01);
  REQUIRE(abs(test.PercentC - 15.79) <= 0.01);
  REQUIRE(abs(test.PercentD - 17.54) <= 0.01);
  REQUIRE(abs(test.PercentF - 1.75) <= 0.01);
  
  REQUIRE(test1.N == 0);
  REQUIRE(test1.NumA == 0);
  REQUIRE(test1.NumB == 0);
  REQUIRE(test1.NumC == 0);
  REQUIRE(test1.NumD == 0);
  REQUIRE(test1.NumF == 0);
  REQUIRE(abs(test1.PercentA) <= 0.001);
  REQUIRE(abs(test1.PercentB) <= 0.001);
  REQUIRE(abs(test1.PercentC) <= 0.001);
  REQUIRE(abs(test1.PercentD) <= 0.001);
  REQUIRE(abs(test1.PercentF) <= 0.001);
}
