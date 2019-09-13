/*gradeutil.cpp*/

//
// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #02: GradeUtil API
// 

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gradeutil.h"

using namespace std;

void Dept::addCourse(Course course)
{
	// Add course to Courses.
  this->Courses.push_back(course);
}

void College::addDepartment(Dept department)
{
	// Add department to Depts.
  this->Depts.push_back(department);
}



//
// API:
//

// 
// ParseCourse:
//
// Parses a CSV (comma-separated values) line into a Course
// object, which is then returned.  The given line must have
// the following format:
//
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//
Course ParseCourse(string csvline)
{
  string  Dept;
	string  Title;
	string  Number;
	string  Section;
	string  Instructor;
	string  NumA, NumB, NumC, NumD, NumF, NumI, NumS, NumU, NumW, NumNR;
  
  stringstream ss(csvline);
  getline(ss, Dept, ',');
  getline(ss, Number, ',');
  getline(ss, Section, ',');
  getline(ss, Title, ',');
  getline(ss, NumA, ',');
  getline(ss, NumB, ',');
  getline(ss, NumC, ',');
  getline(ss, NumD, ',');
  getline(ss, NumF, ',');
  getline(ss, NumI, ',');
  getline(ss, NumNR, ',');
  getline(ss, NumS, ',');
  getline(ss, NumU, ',');
  getline(ss, NumW, ',');
  getline(ss, Instructor, ',');

  return Course( Dept,  Title, stoi(Number), stoi(Section), Instructor,
		 stoi(NumA),  stoi(NumB),  stoi(NumC),  stoi(NumD),  stoi(NumF), stoi(NumI),  stoi(NumS),  stoi(NumU),  stoi(NumW), stoi(NumNR));
}


//
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
double GetDFWRate(const Course& c, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  if (c.getGradingType() == Course::Letter)
  {
    DFW =  c.NumD + c.NumF + c.NumW;
    N = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW; 
    return (DFW*100.0/N);
  }
  return 0.0;
}

double GetDFWRate(const Dept& dept, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  
  for( Course c : dept.Courses)
  {
    if (c.getGradingType() == Course::Letter)
    {
      DFW +=  c.NumD + c.NumF + c.NumW;
      N += c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW; 
    }
  }
  if (N)
  {
    return (DFW*100.0/N);
  }  
  return 0.0;
}

double GetDFWRate(const College& college, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
 
  for (Dept x : college.Depts)
  {
    for( Course c : x.Courses)
    {
      if (c.getGradingType() == Course::Letter)
      {
        DFW +=  c.NumD + c.NumF + c.NumW;
        N += c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW; 
      }
    }
  }
   if (N)
  {
    return (DFW*100.0/N);
  }  
  return 0.0;
}  


//
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
GradeStats GetGradeDistribution(const Course& c)
{
  int    N;  // total # of grades assigned:
	int    NumA, NumB, NumC, NumD, NumF;  // number of A's, B's, etc.
	double PercentA, PercentB, PercentC, PercentD, PercentF;  // percentage of A's, B's, etc.
  
  if (c.getGradingType() == Course::Letter)
  {
      
    NumA = c.NumA;
    NumB = c.NumB;
    NumC = c.NumC;
    NumD = c.NumD; 
    NumF = c.NumF;
    N = NumA + NumB + NumC + NumD + NumF;
    PercentA = (NumA * 100.0/ N);
    PercentB = (NumB * 100.0/ N);
    PercentC = (NumC * 100.0/ N);
    PercentD = (NumD * 100.0/ N);
    PercentF = (NumF * 100.0/ N);

    return GradeStats(N, NumA, NumB, NumC, NumD, NumF,
                      PercentA, PercentB, PercentC, PercentD, PercentF);
  }
  return GradeStats();  
}

GradeStats GetGradeDistribution(const Dept& dept)
{
  int    N = 0;  // total # of grades assigned:
	int    NumA, NumB, NumC, NumD, NumF;  // number of A's, B's, etc.
  NumA = NumB = NumC = NumD = NumF = 0;
  double PercentA, PercentB, PercentC, PercentD, PercentF;  // percentage of A's, B's, etc.

  for( Course x : dept.Courses)
  {
    if (x.getGradingType() == Course::Letter)
    {
      N += x.NumA + x.NumB + x.NumC + x.NumD + x.NumF;
      NumA += x.NumA;
      NumB += x.NumB;
      NumC += x.NumC;
      NumD += x.NumD; 
      NumF += x.NumF;
    }
  }
  // are there any Course with grading type letter
  if (N)
  {
    PercentA = (NumA * 100.0/ N);
    PercentB = (NumB * 100.0/ N);
    PercentC = (NumC * 100.0/ N);
    PercentD = (NumD * 100.0/ N);
    PercentF = (NumF * 100.0/ N);

    return GradeStats(N, NumA, NumB, NumC, NumD, NumF,
                      PercentA, PercentB, PercentC, PercentD, PercentF);
  }
  
  return GradeStats();
}

GradeStats GetGradeDistribution(const College& college)
{
  int    N = 0;  // total # of grades assigned:
	int    NumA, NumB, NumC, NumD, NumF;  // number of A's, B's, etc.
  NumA = NumB = NumC = NumD = NumF = 0;
  double PercentA, PercentB, PercentC, PercentD, PercentF;  // percentage of A's, B's, etc.

  for (Dept c : college.Depts)
  {
    for( Course x : c.Courses)
    {
      if (x.getGradingType() == Course::Letter)
      {
        N += x.NumA + x.NumB + x.NumC + x.NumD + x.NumF;
        NumA += x.NumA;
        NumB += x.NumB;
        NumC += x.NumC;
        NumD += x.NumD; 
        NumF += x.NumF;
      }
    }
  }
  if (N)
  {
    PercentA = (NumA * 100.0/ N);
    PercentB = (NumB * 100.0/ N);
    PercentC = (NumC * 100.0/ N);
    PercentD = (NumD * 100.0/ N);
    PercentF = (NumF * 100.0/ N);
    return GradeStats(N, NumA, NumB, NumC, NumD, NumF,
                      PercentA, PercentB, PercentC, PercentD, PercentF);
  }
  
  return GradeStats();
}


//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.
//
// helper function
bool comp(const Course& a, const Course& b)
{
  return (a.Section < b.Section);
}

vector<Course> FindCourses(const Dept& dept, int courseNumber)
{
  vector<Course>  courses;
  for( Course c : dept.Courses)
  {
    if (c.Number == courseNumber)
    {
      courses.push_back(c);
    }
    sort(courses.begin(), courses.end(), comp);
  }
    
  return courses;
}


//
// FindCourses(dept, instructorPrefix)
//
// Searches the courses in the department for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".
//
// If none are found, then the returned vector is empty.  If 
// one or more courses are found, copies of the course objects
// are returned in a vector, with the courses appearing in 
// ascending order by course number.  If two courses have the 
// same course number, they are given in ascending order by 
// section number.  Note that courses are NOT sorted by instructor
// name.
//
// helper function
bool comp1(const Course& a, const Course& b)
{
  if (a.Number == b.Number)
  {
    return a.Section < b.Section;
  }
  else
  {
    return (a.Number < b.Number);
  }
}
vector<Course> FindCourses(const Dept& dept, string instructorPrefix)
{
  vector<Course>  courses;
    size_t pos;
    for( Course x : dept.Courses)
    {
      pos = x.Instructor.find(instructorPrefix);
      if (pos == 0)
      {
        courses.push_back(x);
      } 
    }
    sort(courses.begin(), courses.end(),comp1);

  return courses;
}


//
// FindCourses(college, courseNumber)
//
// Searches for all courses in the college for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department, then course number,
// and then section number.
//
// helper function
bool compDept(const Course& a, const Course& b)
{
  if (a.Dept == b.Dept)
  {
    if (a.Number == b.Number)
    {
      return (a.Section < b.Section);
    }
    else
    {
      return (a.Number < b.Number);
    } 
  }
  else
  {
    return (a.Dept < b.Dept);
  }
}

vector<Course> FindCourses(const College& college, int courseNumber)
{
  vector<Course>  courses;
  
  for (Dept c : college.Depts)
  {
    for( Course x : c.Courses)
    {
      if (x.Number == courseNumber)
      {
        courses.push_back(x);
      }
    }
  }
  sort(courses.begin(), courses.end(), compDept);
  return courses;
}

//
// FindCourses(college, instructorPrefix)
//
// Searches all the courses in the college for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by instructor, then course number,
// and then section number.
//
bool compPref(const Course& a, const Course& b)
{
  if (a.Dept == b.Dept)
  {
    if (a.Number == b.Number)
    {
      return (a.Section < b.Section); 
    }
    else
    {
      return (a.Number < b.Number);
    }
  }
  else
  {
    return (a.Dept < b.Dept);
  }
}
vector<Course> FindCourses(const College& college, string instructorPrefix)
{
  vector<Course>  courses;
  size_t pos;
  
  for (Dept c : college.Depts)
  {
    for( Course x : c.Courses)
    {
      pos = x.Instructor.find(instructorPrefix);
      if (!pos)
      {
        courses.push_back(x);
      }
    }
  }
  sort(courses.begin(), courses.end(),compPref);
  return courses;
}
