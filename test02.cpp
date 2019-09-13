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


TEST_CASE( "Test 02", "[Project01]" ) 
{
  Course A;
  Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
  Course B("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 1, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
  Course D("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 1, 2, 3, 4, 0, 
           /*I,S,U,W,NR*/ 1, 2, 3, 4, 0);
  Course E("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
  Course F("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 1, 1, 0, 0);
  Course G("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 1, 0, 0, 0, 1);

  REQUIRE(A.getNumStudents() == 0);
  REQUIRE(A.getGradingType() == Course::Unknown);
  
  REQUIRE(B.getNumStudents() == 1);
  
  REQUIRE(C.Dept == "CS");
  REQUIRE(C.Title == "Professional Seminar");
  REQUIRE(C.Number == 499);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Hummel");
  
  REQUIRE(C.NumA == 0);
  REQUIRE(C.NumB == 0);           
  REQUIRE(C.NumC == 0);
  REQUIRE(C.NumD == 0);
  REQUIRE(C.NumF == 0);
  
  REQUIRE(C.NumI == 2);
  REQUIRE(C.NumS == 88);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);
  REQUIRE(C.NumNR == 1);  
  
  REQUIRE(C.getNumStudents() == (88+0+2+1));
  C.NumF = 1;
  REQUIRE(C.getNumStudents() == (1+2+1));
  C.NumF = C.NumS = C.NumU = 0;
  REQUIRE(C.getNumStudents() == (1+2));
  
  REQUIRE(D.getNumStudents() == 11);
  REQUIRE(E.getNumStudents() == 0);
  REQUIRE(F.getNumStudents() == 2);
  REQUIRE(G.getNumStudents() == 2);



}
