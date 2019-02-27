#include <map>
#include <typeinfo>
#include <sstream>

#include "physicsRecord.h"
#include "chemistryRecord.h"
#include "computerRecord.h"
#include "globalFunctions.h"

int main()
{
	// INITIALIZE
	map<int, StudentRecord*> Records;
	
	vector<CourseUnitInfo*> PhysicsCourseUnits;
	vector<CourseUnitInfo*> ChemistryCourseUnits;
	vector<CourseUnitInfo*> ComputerCourseUnits;
	
	// FORMAT FOR THESE FILES:
	//
	// 40101			<- Unit ID
	// Gravitation		<- Unit Name
	// 10				<- Credit weighting
	// 10302
	// Maths I
	// 10
	// etc...
	//Read in avaiable course units
	ifstream units;
	string code, name, weight;
	units.open("phys_units.txt");
	while(getline(units,code))
	{
		getline(units,name);
		getline(units, weight);
		PhysicsCourseUnits.push_back(new CourseUnitInfo(atoi(code.c_str()),name, atoi(weight.c_str())));
	}
	units.close();
	
	units.open("chem_units.txt");
	while(getline(units,code))
	{
		getline(units,name);
		getline(units, weight);
		ChemistryCourseUnits.push_back(new CourseUnitInfo(atoi(code.c_str()),name, atoi(weight.c_str())));
	}
	units.close();

	units.open("cs_units.txt");
	while(getline(units,code))
	{
		getline(units,name);
		getline(units, weight);
		ComputerCourseUnits.push_back(new CourseUnitInfo(atoi(code.c_str()),name, atoi(weight.c_str())));
	}
	units.close();
	
	// START PROGRAM

	cout << "Type 'help' for a list of avaialable commands" << endl;
	cout << "=============================================" << endl;

	string command;
	while (true)
	{	
		cout << "\nStudentDatabase> ";
		cin >> command;

		//LOAD STUDENT
		if (command.compare("load") == 0)
		{
			ifstream student;
			string studentFileName;
			cout << "Enter file name of student information: ";
			
			cin >> studentFileName;

			student.open(studentFileName);
			if (!student.good())
			{
				cerr << "Cannot find " << studentFileName << "." << endl;
			}
			else
			{
				int id;
				string degree, fName, lName, cFileName;
				while(getline(student, cFileName))
				{
					getline(student, degree);
					getline(student, fName);
					getline(student,lName);

					if (degree.compare("Physics") == 0)
					{
						// Generating ID
						id = 0;
						// While taken, increment
						while (Records.find(id) != Records.end())
							id ++;
						Records[id] = new PhysicsRecord(fName, lName);

						ifstream course;
						course.open(cFileName);
						if (!course.good())
						{
							cerr << "Cannot find " << cFileName << "." << endl;
						}
						else
						{
							string uCode, uName, uWeight, mFileName;
							while (getline(course, mFileName))
							{
								getline(course, uCode);
								getline(course, uName);
								getline(course, uWeight);

								Records[id]->AddUnit(new PhysicsUnitRecord(atoi(uCode.c_str()),uName, atoi(uWeight.c_str())));
								
								ifstream marks;
								marks.open(mFileName);
								if (!marks.good())
								{
									cerr << "Cannot find " << mFileName << "." << endl;
								}
								else
								{
									double temp(0.0), tmp(0.0);
									string cMark, cWeight;
									string cName;
									while(getline(marks, cName))
									{
										getline(marks, cMark);
										getline(marks, cWeight);

										temp = atof(cMark.c_str());
										tmp = atof(cWeight.c_str());

										Records[id]->AddMark(atoi(uCode.c_str()), cName, temp, tmp);
										
									}
									marks.close();
								}

							}
							
						}
						course.close();
					}
					else if (degree.compare("Chemistry") ==0)
					{
						id = 0;
						while (Records.find(id) != Records.end())
							id ++;
						Records[id] = new ChemistryRecord(fName, lName);

						ifstream course;
						course.open(cFileName);
						if (!course.good())
						{
							cerr << "Cannot find " << cFileName << "." << endl;
						}
						else
						{
							string uCode, uName, uWeight, mFileName;
							while (getline(course, mFileName))
							{
								getline(course, uCode);
								getline(course, uName);
								getline(course, uWeight);

								Records[id]->AddUnit(new ChemistryUnitRecord(atoi(uCode.c_str()),uName, atoi(uWeight.c_str())));
								
								ifstream marks;
								marks.open(mFileName);
								if (!marks.good())
								{
									cerr << "Cannot find " << mFileName << "." << endl;
								}
								else
								{
									double temp(0.0), tmp(0.0);
									string cMark, cWeight;
									string cName;
									while(getline(marks, cName))
									{
										getline(marks, cMark);
										getline(marks, cWeight);

										temp = atof(cMark.c_str());
										tmp = atof(cWeight.c_str());

										Records[id]->AddMark(atoi(uCode.c_str()), cName, temp, tmp);
										
									}
								}
							}
						}
					}
					else if (degree.compare("Computer") == 0)
					{
						id = 0;
						while (Records.find(id) != Records.end())
							id ++;
						Records[id] = new ComputerRecord(fName, lName);

						ifstream course;
						course.open(cFileName);
						if (!course.good())
						{
							cerr << "Cannot find " << cFileName << "." << endl;
						}
						else
						{
							string uCode, uName, uWeight, mFileName;
							while (getline(course, mFileName))
							{
								getline(course, uCode);
								getline(course, uName);
								getline(course, uWeight);

								Records[id]->AddUnit(new ComputerUnitRecord(atoi(uCode.c_str()),uName, atoi(uWeight.c_str())));
								
								ifstream marks;
								marks.open(mFileName);
								if (!marks.good())
								{
									cerr << "Cannot find " << mFileName << "." << endl;
								}
								else
								{
									double temp(0.0), tmp(0.0);
									string cMark, cWeight;
									string cName;
									while(getline(marks, cName))
									{
										getline(marks, cMark);
										getline(marks, cWeight);

										temp = atof(cMark.c_str());
										tmp = atof(cWeight.c_str());

										Records[id]->AddMark(atoi(uCode.c_str()), cName, temp, tmp);
									}
								}
							}	
						}
					}
					cout << "Student " << fName << " " << lName << " was added with ID " << id << endl;
				}
			}
			student.close();
		}

		//SAVE RECORDS
		else if (command.compare("save") == 0)
		{
			cout << "Saving database... Please Wait..." << endl;
			stringstream ss;
			string dbFile("db.txt"), courseFile;
			ofstream db, courses;

			db.open(dbFile);

			for(map<int,StudentRecord*>::iterator iterator = Records.begin(); iterator != Records.end(); iterator++) 
			{
				//Assigns Filename and prints it to the file for saving
				ss << iterator->first << iterator->second->GetFirstName() << iterator->second->GetLastName() << ".txt";
				courseFile = ss.str();
				ss.str(string());
				db << courseFile << endl;

				//outputs degree course
				if (typeid(*(iterator->second)) == typeid(PhysicsRecord))
					db << "Physics" << endl;
				else if (typeid(*(iterator->second)) == typeid(ChemistryRecord))
					db << "Chemistry" << endl;
				else if (typeid(*(iterator->second)) == typeid(ComputerRecord))
					db << "Computer" << endl;

				db << iterator->second->GetFirstName() << endl;
				db << iterator->second->GetLastName() << endl;
				
				int id = iterator->first;
				courses.open(courseFile);
				iterator->second->SaveCourseUnits(courses, id);
				courses.close();
			}
			db.close();
			cout << "Database saved successfully!" << endl;
		}

		//HELP MENU
		else if (command.compare("help") ==0)
		{
			cout << "Available commands: \n(Please note all commands are case sensistive.)" << endl;
			cout << "\tadd \t-- Adds a new student record to the database" << endl;
			cout << "\tload \t-- Loads student records into the database" << endl;
			cout << "\tsave \t-- Saves the database" << endl;
			cout << "\tselect \t-- Selects a student to add course units and marks etc." << endl;
			cout << "\tdelete \t-- Deletes a student from the database." << endl;
			cout << "\tlist \t-- List the ID's and names of all students in database." <<endl;
			cout << "\treport \t-- Produces a report of entire database to screen or file." << endl;
			cout << "\texit \t-- Close database." << endl;
		}

		// EXIT 
		else if (command.compare("exit") == 0)
		{
			return 0;
		}
		
		// ADDS A STUDENT
		else if (command.compare("add") == 0)
		{
			// Getting input from user
			string firstName, lastName;
			//int course;

			cout<<"== Adding student =="<<endl;
			
			cout<<"First name: ";
			cin.ignore();
			getline(cin, firstName);

			cout<<"Last name: ";
			getline(cin, lastName);
			
			bool valid = false;
			string course;
			int courseSelection;
			
			//Validating input
			while (!valid)
			{
				// Selecting degree
				cout << "Please select a course:"<<endl;
				cout << "   [0] - Physics"<<endl << "   [1] - Chemistry" << endl << "   [2] - Computer Science" << endl;
				cout << "Course: ";
				cin >> course;
				if (courseInputCheck(course))
				{
					courseSelection = atoi(course.c_str());
					valid = true;
				}
				else 
				{
					cout << "Invalid Response." << endl;
				}
			}

			// Adding new info to database
			// Generating ID
			int id = 0;
			// While taken, increment
			while (Records.find(id) != Records.end())
				id ++;

			switch(courseSelection)
			{
				// Create physics record
				case 0: 
					Records[id] = new PhysicsRecord(firstName, lastName);
					break;
				// Create chemistry record
				case 1:
					Records[id] = new ChemistryRecord(firstName, lastName);
					break;

				// Create computer science record
				case 2:
					Records[id] = new ComputerRecord(firstName, lastName);
					break;					
			}
			cout << "Student " << firstName << " " << lastName << " was added with ID " << id << endl;	
		}
		// SELECT A STUDENT
		else if (command.compare("select") == 0)
		{
			int id; 
			string  tmpid;
			bool valid = false;

			//Validating input
			while (!valid)
			{
				cout << "Please enter the Student id of the student you are looking for: ";
				cin >> tmpid;
				
				if (selectInputCheck(tmpid))
				{
					id = atoi(tmpid.c_str());
					valid = true;
				}
				else 
				{
					cout << "Invalid Response." << endl;
				}
			}
			
			// CHECK IF STUDENT EXISTS
			if (Records.count(id) > 0)
			{
			// DISPLAYING AVAILABLE COMMANDS
			cout << "Student " << Records[id]->GetFirstName() << " " << Records[id]->GetLastName() << " was selected" << endl;
			cout << "Available commands: " << endl;
			cout << "\taddcourse \t-- Adds a course unit" << endl; 
			cout << "\taddmark \t-- Adds a mark" << endl;
			cout << "\tview \t\t-- Print student details" << endl; 
			cout << "\tback \t\t-- Back to menu" << endl;
			cout << "\thelp \t\t-- Display this list again" << endl;
			string comm;

			// STUDENT MENU
			while (true)
			{	
				cout << "\nStudentDatabase> "<<  Records[id]->GetFirstName() << " " << Records[id]->GetLastName() << "> ";
				cin >> comm;

				if (comm.compare("help") == 0)
				{
					cout << "Available commands: " << endl;
					cout << "\taddcourse \t-- Adds a course unit" << endl; 
					cout << "\taddmark \t-- Adds a mark" << endl;
					cout << "\tview \t\t-- Print student details" << endl; 
					cout << "\tback \t\t-- Back to menu" << endl;
					cout << "\thelp \t\t-- Display this list again" << endl;
				}
				// COMMAND TO ADD COURSE
				else if (comm.compare("addcourse") == 0)
				{
					// Displaying the course units
					vector<CourseUnitInfo*> courseUnitInfo;

					if (typeid(*Records[id]) == typeid(PhysicsRecord))
						courseUnitInfo = PhysicsCourseUnits;
					else if (typeid(*Records[id]) == typeid(ChemistryRecord))
						courseUnitInfo = ChemistryCourseUnits;
					else if (typeid(*Records[id]) == typeid(ComputerRecord))
						courseUnitInfo = ComputerCourseUnits;

					cout << "== Available couse units ==" << endl;

					 for (vector<CourseUnitInfo*>::iterator it = courseUnitInfo.begin() ; it != courseUnitInfo.end(); ++it)
						 cout << " " << (*it)->GetUnitCode() << " " << (*it)->GetUnitName() << "\tCredits: " << (*it)->GetUnitWeight() << endl;
					
					// Selecting course unit
					int unitcode;
					string tmpunitcode;
					bool valid = false;

					//Validating input
					while (!valid)
					{
						cout << "\nPlease select the course unit (by entering unit code): ";
						cin >> tmpunitcode;
				
						if (selectInputCheck(tmpunitcode))
						{
							unitcode = atoi(tmpunitcode.c_str());
							valid = true;
						}
						else 
						{
							cout << "Invalid Response." << endl;
						}
					}
					
					bool found = false;
					do 
					{
						for (vector<CourseUnitInfo*>::iterator it = courseUnitInfo.begin() ; it != courseUnitInfo.end(); ++it)
							if (unitcode == (*it)->GetUnitCode())
							{
								found = true;
								// Course unit selection is now valid, adding it to the user
								if (!(Records[id]->UnitAlreadyAdded(unitcode)))
								{
								if (typeid(*Records[id]) == typeid(PhysicsRecord))
									Records[id]->AddUnit(new PhysicsUnitRecord((*it)->GetUnitCode(),(*it)->GetUnitName(), (*it)->GetUnitWeight()));
								else if (typeid(*Records[id]) == typeid(ChemistryRecord))
									Records[id]->AddUnit(new ChemistryUnitRecord((*it)->GetUnitCode(),(*it)->GetUnitName(), (*it)->GetUnitWeight()));
								else if (typeid(*Records[id]) == typeid(ComputerRecord))
									Records[id]->AddUnit(new ComputerUnitRecord((*it)->GetUnitCode(),(*it)->GetUnitName(), (*it)->GetUnitWeight()));
							
								cout << "Course unit added" << endl;
								}
								else {cout << "\nUnit already added to student, please add a different unit." << endl;}
							}

						if (!found) 
						{
							cout << "\nInvalid choice." << endl << "Please select the course unit: ";
							cin>>unitcode;
						}
						else 
							break;
					} 
					while (!found);
				}

				// COMMAND TO ADD MARK
				else if (comm.compare("addmark") == 0)
				{
					//Makes sure the student has courses assigned before adding marks
					if (Records[id]->UnitsHasSize())
					{
						cout << "\nPlease select the course unit by typing in the unit no.: " << endl;
						Records[id]->GetCourseUnits(); // Prints out the courses;
						int unitcode;
						string tmpunitcode;
						bool valid = false;

						//Validating input
						while (!valid)
						{
							cout << "\nUnit: ";
							cin >> tmpunitcode;
				
							if (selectInputCheck(tmpunitcode))
							{
								unitcode = atoi(tmpunitcode.c_str());
								//Checks unit selection is valid
								if (Records[id]->HasCourseUnit(unitcode)) valid = true;
								else cout << "Invalid Response." << endl;
							}
							else 
							{
								cout << "Invalid Response." << endl;
							}
						}

						string cwname ="";
						double mark, cweight;
						string tmpmark, tmpcweight;
						cout << "\nCoursework name: ";
						cin.ignore();
						getline(cin,cwname);
 
						valid = false;

						//Validating input
						while (!valid)
						{
							cout << "\nCoursework mark: ";
							cin >> tmpmark;
				
							if (doubleInputCheck(tmpmark))
							{
								mark = atof(tmpmark.c_str());
								valid = true;
							}
							else 
							{
								cout << "Invalid Response." << endl;
							}
						}

						valid = false;

						while (!valid)
						{
							cout << "\nCoursework weight: ";
							cin >> tmpcweight;
				
							if (doubleInputCheck(tmpcweight))
							{
								cweight = atof(tmpcweight.c_str());
								valid = true;
							}
							else 
							{
								cout << "Invalid Response." << endl;
							}
						}

						Records[id]->AddMark(unitcode,cwname,mark, cweight);
						cout << "\nMarks added..." << endl;
					}
					else 
					{
						cout << "\nCurrent student has not been assigned any courses." << endl;
						cout<< "Add courses before adding marks." << endl;
					}
				}

				// COMMAND TO DISPLAY STUDENT
				else if (comm.compare("view") == 0)
				{
					if(typeid(*Records[id]) == typeid(PhysicsRecord)) cout << " --- Physics Student --- " << endl;
					else if(typeid(*Records[id]) == typeid(ChemistryRecord)) cout << " --- Chemistry Student --- " << endl;
					else if(typeid(*Records[id]) == typeid(ComputerRecord)) cout << " --- Computer Science Student" << endl;
					cout << "\tFirst name: " << Records[id]->GetFirstName() << endl;
					cout << "\tLast name: " << Records[id]->GetLastName() << endl;
					cout << "\tCourse units: " << endl;
					Records[id]->GetCourseUnits();
				}

				else if (comm.compare("back") == 0)
					break; // Back to main menu

				else {cout << "Invalid command. Type 'help' for available commands." << endl;}
			}
			}
			else {cout << "Student not found. Returning to main menu...." << endl;}
		}

		// DELETE
		else if (command.compare("delete") == 0)
		{
			if (Records.size() != 0)
			{
			int id;
			string  tmpid;
			bool valid = false;

			//Validating input
			while (!valid)
			{
				cout << "Please enter the Student id of the student you want erased: ";
				cin >> tmpid;
				
				if (selectInputCheck(tmpid))
				{
					id = atoi(tmpid.c_str());
					valid = true;
				}
				else 
				{
					cout << "Invalid Response." << endl;
				}
			}
			
			//CHECK IF STUDENT FOUND
			if (Records.count(id) > 0)
			{//found!
				map<int,StudentRecord*>::iterator it;
				it = Records.find(id);

				cout << "Student is " << Records[id]->GetFirstName() << " " << Records[id]->GetLastName() << endl;
				bool valid = false;
				string answer;
				while(!valid)
				{
					cout << "Are you sure? [y/n]" << endl << ">";
					cin >> answer;

					if (answer.compare("y") == 0)
					{
						Records.erase(it); 
						cout << "Student was erased" << endl;
						valid = true;
					}
					else if (answer.compare("n") ==0) {cout << "Returning to main menu..." << endl; valid = true;}
					else cout << "Invalid Response." << endl;
				}
			}
			else{ cout << "\nStudent not found. Returning to main menu..." << endl;}
			}
			else {cout << "The database is empty. Please add/load students before attempting to delete! Returning to main menu." << endl;}
		}

		// LIST STUDENTS
		else if (command.compare("list") == 0)
		{
			if (Records.size() != 0)
			{
				for(map<int,StudentRecord*>::iterator iterator = Records.begin(); iterator != Records.end(); iterator++) 
				{
					cout << "[" << iterator->first << "] " << iterator->second->GetFirstName() << " " << iterator->second->GetLastName() << endl;
				}
			}
			else {cout << "Database is empty, please add some student records." << endl;}
		}

		// REPORT
		else if (command.compare("report") == 0)
		{
			if(Records.size() !=0)
			{
				cout << "Reporting Menu: " << endl;
				cout << "Available commands: " << endl;
				cout << "\tprintdb \t-- Outputs the contents of the database" << endl; 
				cout << "\tback \t\t-- Back to menu" << endl;
				cout << "\thelp \t\t-- Display this list again" << endl;
				string comm;
				 while (true)
				 {
					cout << "\nStudentDatabase> Reports> ";
					cin >> comm;

					//Back to main menu
					if (comm.compare("back") == 0) break;

					 else if (comm.compare("help") == 0)
					{
						cout << "Available commands: " << endl;
						cout << "\tprintdb \t-- Outputs the contents of the database" << endl; 
						cout << "\tback \t\t-- Back to menu" << endl;
						cout << "\thelp \t\t-- Display this list again" << endl;
					}

					//Produce full report on all records in database
					else if (comm.compare("printdb") ==0)
					{
						for(map<int,StudentRecord*>::iterator iterator = Records.begin(); iterator != Records.end(); iterator++) 
						{
							cout << "\n[" << iterator->first << "] " << iterator->second->GetFirstName() << " " << iterator->second->GetLastName();
				
							if (typeid(*(iterator->second)) == typeid(PhysicsRecord))
								cout << " -- Physics Student" << endl;
							else if (typeid(*(iterator->second)) == typeid(ChemistryRecord))
								cout << " -- Chemistry Student" << endl;
							else if (typeid(*(iterator->second)) == typeid(ComputerRecord))
								cout << " -- Computer Science Student" << endl;
							
							cout << "\nCourse units: " << endl;
							iterator->second->GetCourseUnits();
						}

						string ans;
						bool valid = false;
						while(!valid)
						{
						cout << "Would you like the report printed to a file? [y/n]" << endl << ">";
						cin >> ans;

						if (ans.compare("y") == 0)
						{
							ofstream reportFile;
							reportFile.open ("report.txt");

							for(map<int,StudentRecord*>::iterator iterator = Records.begin(); iterator != Records.end(); iterator++) 
							{
								reportFile << "[" << iterator->first << "] " << iterator->second->GetFirstName() << " " << iterator->second->GetLastName();
				
								if (typeid(*(iterator->second)) == typeid(PhysicsRecord))
									reportFile << " -- Physics Student" << endl;
								else if (typeid(*(iterator->second)) == typeid(ChemistryRecord))
									reportFile << " -- Chemistry Student" << endl;
								else if (typeid(*(iterator->second)) == typeid(ComputerRecord))
									reportFile << " -- Computer Science Student" << endl;
							
								iterator->second->GetCourseUnits(reportFile);
							}
							reportFile.close();
							valid = true;
						}
						else if (ans.compare("n") == 0){ cout << "Returning to report menu..." << endl; valid = true;}
						else {cout << "Invalid Response." << endl;}
						}
					}
					 else {cout << "Invalid command. Type 'help' for available commands." << endl;}
				 }
			}
			else {cout << "Database is empty, please add some student records." << endl;}
		}
		else
		{
			cout << "Invalid command. Type 'help' for available commands." << endl;	
		}	
	}


	//Cleaning up
	for(map<int,StudentRecord*>::iterator it = Records.begin(); it != Records.end(); ++it)
	{
		delete it->second;
	}
	Records.clear();
	return 0;
}