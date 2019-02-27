#include "studentRecord.h"

class ComputerRecord : public StudentRecord
{
protected:
	string firstName;										// First name
	string lastName;										// Last name
	vector<ComputerUnitRecord*> units;						// Vector to hold courses taken
	
public:

	~ComputerRecord(){}

	ComputerRecord(string first, string second)
	{
		firstName = first;
		lastName = second;
	}

	string GetFirstName(){return firstName;}
	string GetLastName() {return lastName;}

	void AddUnit(CourseUnitRecord *toAdd)
	{
		ComputerUnitRecord *newrecord = new ComputerUnitRecord();
		newrecord->SetUnitCode(toAdd->GetUnitCode());
		newrecord->SetUnitName(toAdd->GetUnitName());
		newrecord->SetUnitWeight(toAdd->GetUnitWeight());

		units.push_back(newrecord);
	}
	
	void AddMark(int unitCode, string cwname, double mark, double cweight)
	{
		for (vector<ComputerUnitRecord*>::iterator it = units.begin() ; it != units.end(); ++it)
		{
			if ((*it)->GetUnitCode() == unitCode)
			{
				(*it)->AddMark(cwname, mark, cweight);
				break;
			}
		}
	}

	void GetCourseUnits()
	{
		for (vector<ComputerUnitRecord*>::iterator it = units.begin() ; it != units.end(); ++it)
		{
			cout << "\n\tUnit: " << (*it)->GetUnitCode() << " " << (*it)->GetUnitName() << "\t\tCredits: " << (*it)->GetUnitWeight() << endl;
			(*it)->PrintMarks();		
		}
		cout << endl;
	}

	void GetCourseUnits(ofstream &file)
	{
		for (vector<ComputerUnitRecord*>::iterator it = units.begin() ; it != units.end(); ++it)
		{
			file << "\n\tUnit: " << (*it)->GetUnitCode() << " " << (*it)->GetUnitName() << "\t\tCredits: " << (*it)->GetUnitWeight() << endl;
			(*it)->PrintMarks(file);		
		}
		file << endl;
	}

	bool HasCourseUnit(int code)
	{
		for(vector<ComputerUnitRecord*>::iterator it = units.begin(); it !=units.end(); ++it)
		{
			if((*it)->GetUnitCode() == code) {return true;}
		}
		return false;
	}

	bool UnitsHasSize()
	{
		if(units.size() > 0) return true;
		else return false;
	}

	void SaveCourseUnits(ofstream &file, int id)
	{
		ofstream marks;
		stringstream ss;
		string markFile;
		for (vector<ComputerUnitRecord*>::iterator it = units.begin() ; it != units.end(); ++it)
		{
			ss <<  id << (*it)->GetUnitCode() << "_marks.txt";
			markFile = ss.str();
			ss.str(string());
			file << markFile << endl;
			file <<  (*it)->GetUnitCode() << endl;
			file << (*it)->GetUnitName() << endl;
			file << (*it)->GetUnitWeight() << endl;

			marks.open(markFile);
			(*it)->SaveMarks(marks);
			marks.close();
		}
	}

	bool UnitAlreadyAdded(int code)
	{
		for (vector<ComputerUnitRecord*>::iterator it = units.begin() ; it != units.end(); ++it)
		{
			if (code == (*it)->GetUnitCode()) return true;
		}
		return false;
	}
};
