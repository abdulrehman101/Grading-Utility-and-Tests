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


TEST_CASE( "Test 04", "[Project01]" ) 
{
  vector<Course> test;
  College one;
  REQUIRE(one.Name == "?");
  College two("UIC");
  REQUIRE(two.Name == "UIC");
  
  Dept CS("computer science");
  
  Course B("Biology", "bio101", 110, 02, "ali", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course C("CS", "Professional Seminar", 499, 01, "aliUmer", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  
  CS.addCourse(B);
  CS.addCourse(C);
  two.addDepartment(CS);
  
  test = FindCourses(two, "ali");
  REQUIRE(test.size() == 2);
  REQUIRE(test[0].Title == "bio101");
  REQUIRE(test[1].Title == "Professional Seminar");
  
}
