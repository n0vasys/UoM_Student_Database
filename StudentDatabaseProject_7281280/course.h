#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//Class to handle degree modules (course  unit)
class CourseUnitInfo
{
protected:
	int unitCode;
	string unitName;
	int unitWeight;
public:
	~CourseUnitInfo();

	CourseUnitInfo(int code, string name, int weight)
	{
		unitCode = code;
		unitName = name;
		unitWeight = weight;
	}

	int GetUnitCode(){return unitCode;}
	string GetUnitName(){return unitName;}
	int GetUnitWeight(){return unitWeight;}
};
//Class to handle courseworks (i.e assignments and exams) being added to a Unit
class Coursework
{
protected:
	string courseworkName;	// e.g. CW1, CW2
	double courseworkMark;  // e.g. 89, 23 stored as a %
	double courseworkWeight; // e.g. % of overall unit credit
public:

	~Coursework(){};

	Coursework(string cwname, double mark, double cweight)
	{
		courseworkName = cwname;
		courseworkMark = mark;
		courseworkWeight = cweight;

	}
	string GetCourseworkName(){return courseworkName;}
	double GetCourseworkMark(){return courseworkMark;}
	double GetCourseworkWeight(){return courseworkWeight;}
};
//Base class for course units
class CourseUnitRecord
{
protected:
	int unitCode;
	string unitName;
	int unitWeight;
	vector<Coursework*> courseworks;		// This holds coursework and mark and weight
public:

	~CourseUnitRecord(){}

	void AddMark(string cwname, double mark, double cweight)
	{
		courseworks.push_back(new Coursework(cwname, mark, cweight));
	}
	virtual void PrintMarks() = 0;
	virtual void PrintMarks(ofstream &file) = 0;
	virtual void SaveMarks(ofstream &file) = 0;
	int GetUnitCode(){return unitCode;}
	string GetUnitName(){return unitName;}
	int GetUnitWeight(){return unitWeight;}
	void SetUnitCode(int code){unitCode = code;}
	void SetUnitName(string name){unitName = name;}
	void SetUnitWeight(int weight){unitWeight = weight;}
};

class PhysicsUnitRecord : public CourseUnitRecord
{
public:
	~PhysicsUnitRecord(){}
	PhysicsUnitRecord(){}
	PhysicsUnitRecord(int code, string name, int weight)
	{
		unitCode = code;
		unitName = name;
		unitWeight = weight;
	}

	void PrintMarks()
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
			cout << "\n\tCoursework Name: " << (*it)->GetCourseworkName() << "\tMark: " << (*it)->GetCourseworkMark() << "%" 
			<<"\tUnit Percentage: "<< (*it)->GetCourseworkWeight() << "%"<< endl;
	}

	void PrintMarks(ofstream &file)
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
			file << "\n\tCoursework Name: " << (*it)->GetCourseworkName() << "\tMark: " << (*it)->GetCourseworkMark() << "%" 
			<<"\tUnit Percentage: "<< (*it)->GetCourseworkWeight()<< "%"<< endl;
	}

	void SaveMarks(ofstream &file)
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
		{
			file << (*it)->GetCourseworkName() << endl;
			file << (*it)->GetCourseworkMark() << endl;
			file << (*it)->GetCourseworkWeight() << endl;
		}
	}
};

class ChemistryUnitRecord : public CourseUnitRecord
{
public:
	~ChemistryUnitRecord(){}
	ChemistryUnitRecord(){}
	ChemistryUnitRecord(int code, string name, int weight)
	{
		unitCode = code;
		unitName = name;
		unitWeight = weight;
	}

	void PrintMarks()
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
			cout << "\n\tCoursework Name: " << (*it)->GetCourseworkName() << "\tMark: " << (*it)->GetCourseworkMark() << "%" 
			<<"\tUnit Percentage: "<< (*it)->GetCourseworkWeight()<< "%"<<endl;
	}

	void PrintMarks(ofstream &file)
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
			file << "\n\tCoursework Name: " << (*it)->GetCourseworkName() << "\tMark: " << (*it)->GetCourseworkMark() << "%" 
			<<"\tUnit Percentage: "<< (*it)->GetCourseworkWeight()<< "%"<<endl;
	}

	void SaveMarks(ofstream &file)
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
		{
			file << (*it)->GetCourseworkName() << endl;
			file << (*it)->GetCourseworkMark() << endl;
			file << (*it)->GetCourseworkWeight() << endl;
		}
	}
};

class ComputerUnitRecord : public CourseUnitRecord
{
public:
	~ComputerUnitRecord(){}
	ComputerUnitRecord(){}
	ComputerUnitRecord(int code, string name, int weight)
	{
		unitCode = code;
		unitName = name;
		unitWeight = weight;
	}

	void PrintMarks()
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
			cout << "\n\tCoursework Name: " << (*it)->GetCourseworkName() << "\tMark: " << (*it)->GetCourseworkMark() << "%" 
			<<"\tUnit Percentage: "<< (*it)->GetCourseworkWeight()<< "%"<< endl;
	}

	void PrintMarks(ofstream &file)
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
			file << "\n\tCoursework Name: " << (*it)->GetCourseworkName() << "\tMark: " << (*it)->GetCourseworkMark() << "%" 
			<<"\tUnit Percentage: "<< (*it)->GetCourseworkWeight()<< "%"<< endl;
	}

	void SaveMarks(ofstream &file)
	{
		for (vector<Coursework*>::iterator it = courseworks.begin() ; it != courseworks.end(); ++it)
		{
			file << (*it)->GetCourseworkName() << endl;
			file << (*it)->GetCourseworkMark() << endl;
			file << (*it)->GetCourseworkWeight() << endl;
		}
	}
};