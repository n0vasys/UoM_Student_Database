#pragma once
#include "course.h"

class StudentRecord 
{	
public:
	virtual string GetFirstName() = 0;
	virtual string GetLastName() = 0;
	virtual void AddUnit(CourseUnitRecord *toAdd)  = 0;				// Adds a course
	virtual void AddMark(int unitCode, string cwname, double mark, double cweight) = 0;
	virtual void GetCourseUnits() = 0;							// Lists the courses into the terminal								// List of courses taken
	virtual void GetCourseUnits(ofstream &file) = 0;
	virtual bool HasCourseUnit(int code) = 0;
	virtual bool UnitsHasSize() = 0;
	virtual void SaveCourseUnits(ofstream &file, int id) = 0;
	virtual bool UnitAlreadyAdded(int code) = 0;
	virtual ~StudentRecord(){}
};