//Global Functions
bool courseInputCheck(string s)
{
	stringstream ss(s);
    int i;
	if (ss >> i && !(ss >> s) && (i>=0) && (i < 3)){return true;} //Test to see if integer conversion is possible, and if so, pass.
	else
	{
	cin.clear();
	return false;
	}
}

bool selectInputCheck(string s)
{
	stringstream ss(s);
    int i;
	if (ss >> i && !(ss >> s) && (i>=0)){return true;} //Test to see if integer conversion is possible, and if so, pass.
	else
	{
	cin.clear();
	return false;
	}
}

bool doubleInputCheck(string s)
{
	stringstream ss(s);
    double i;
	if (ss >> i && !(ss >> s) && (i>=0.0)){return true;} //Test to see if double conversion is possible, and if so, pass.
	else
	{
	cin.clear();
	return false;
	}
}