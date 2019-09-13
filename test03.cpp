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


TEST_CASE( "Test 03", "[Project01]" ) 
{
  vector<Course> test;
  College UIC("UIC");
  Dept C("CS");
  REQUIRE(C.Name == "CS");
  
  Dept D;
  Dept G;
  
  REQUIRE(D.Name == "?");
  
  Course empty;
  Course A("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  
  Course B("Biology", "bio101", 110, 02, "george", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course E("CS", "Professional", 501, 02, "gem", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course ee("CS", "Computer", 501, 02, "emgemem", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course aa("CS", "UnProfessional", 501, 01, "geme", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course bb("BIO", "SoProfessional", 499, 02, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course last("BIO", "SoProfessional", 499, 01, "xyz", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
 
  C.addCourse(bb);
  C.addCourse(A);
  C.addCourse(B);
  C.addCourse(E);
  C.addCourse(aa);
  C.addCourse(ee);
  G.addCourse(last);

  UIC.addDepartment(C);
    UIC.addDepartment(G);

  // (dept, courseNumber)
  
  test = FindCourses(D, 211);
  REQUIRE(test.size() == 0);
  test.clear();
  
  test = FindCourses(C, 211);
  REQUIRE(test.size() == 0);
  test.clear();
  
  test = FindCourses(C, 499);
  REQUIRE(test.size() == 2);
  REQUIRE(test[0].Section == 01);
  REQUIRE(test[1].Section == 02);
  test.clear();
  
  // (dept, instructorPrefix)
  
  test = FindCourses(C, "Hu");
  REQUIRE(test.size() == 2);
  REQUIRE(test[0].Title == "Professional Seminar");
  REQUIRE(test[1].Title == "SoProfessional");

  test.clear();
  
  test = FindCourses(C, "ali");
  REQUIRE(test.size() == 0);
  test.clear();
  
  // (college, courseNumber)
  
  test = FindCourses(UIC, 211);
  REQUIRE(test.size() == 0);
  test.clear();
  
  test = FindCourses(UIC, 499);
  REQUIRE(test.size() == 3);
  REQUIRE(test[0].Section == 01);
  REQUIRE(test[1].Section == 02);
  test.clear();
  
  // (college, instructorPrefix)
  
  test = FindCourses(UIC, "ali");
  REQUIRE(test.size() == 0);
  test.clear();
  
  test = FindCourses(UIC, "Hu");
  REQUIRE(test.size() == 2);
  REQUIRE(test[0].Section == 02);
  REQUIRE(test[1].Section == 01);
  test.clear();
  
  test = FindCourses(UIC, "ge");
  REQUIRE(test.size() == 3);
  REQUIRE(test[0].Section == 02);
  REQUIRE(test[0].Title == "bio101");
  REQUIRE(test[1].Section == 01);
  REQUIRE(test[1].Title == "UnProfessional");
  REQUIRE(test[2].Section == 02);
  REQUIRE(test[2].Title == "Professional");
  test.clear();
  
  test = FindCourses(C, "Hu");
  REQUIRE(test.size() == 2);
  REQUIRE(test[0].Section == 01);
  REQUIRE(test[1].Section == 02);
  test.clear();
  
  test = FindCourses(C, "ge");
  REQUIRE(test.size() == 3);
  REQUIRE(test[0].Number == 110);
  REQUIRE(test[1].Section == 01);
  REQUIRE(test[2].Section == 02);

  test.clear();
}
