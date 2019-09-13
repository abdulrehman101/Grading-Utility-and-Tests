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


TEST_CASE( "Test 05", "[Project01]" ) 
{
  Course test = ParseCourse("BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington");
  
  
  REQUIRE (test.Dept == "BIOE");
  REQUIRE (test.Title == "Intro to Bioengineering");
  REQUIRE (test.Section == 01);


  REQUIRE (test.NumA == 22);
  REQUIRE (test.NumB == 8);
  REQUIRE (test.NumC == 2);
  REQUIRE (test.NumD == 1);
  REQUIRE (test.NumF == 0);
  REQUIRE (test.NumI == 1);
  REQUIRE (test.NumNR == 0);
  REQUIRE (test.NumS == 0);
  REQUIRE (test.NumU == 0);
  REQUIRE (test.NumW == 5);
  
 
  
}
