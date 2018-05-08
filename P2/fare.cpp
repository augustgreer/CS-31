#include <iostream>
#include<string>

using namespace std;

int main()
{
	const double ADULT = 18;
	const double SENIOR = 65;
	const double STD_INITIAL_FAIR = 1.35;
	const double STD_ZONE_FACTOR = 0.55;
	const double MINOR_STUDENT_LOWDISTANCE_FARE = 0.65;
	const double SENIOR_INITIAL_FARE = 0.55;
	const double SENIOR_ZONE_FACTOR = 0.25;
	const double ZERO_BOUNDARY_SENIOR_FARE = 0.45;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Age of rider: ";
	int age;
	cin >> age;					//collect age of rider
	cin.ignore(100000, '\n');

	cout << "Student? (y/n): ";
	string student;
	getline(cin, student);		//determine student status

	cout << "Destination: ";
	string destination;
	getline(cin, destination);	//determine destination

	cout << "Number of zone boundaries crossed: ";
	int zones;
	cin >> zones;				//detrmine # of zones crossed

	if (age < 0) //error message if age is negative
	{
		cout << "---" << endl << "The age must not be negative" << endl;
		return 1;					//terminate
	}

	else if (student != "y" && student != "n") //error message if student status isn't y or n
	{
		cout << "---" << endl << "You must enter y or n" << endl;
		return 1;				//terminate
	}

	else if (destination == "")	//error message if nothing entered for destination
	{
		cout << "---" << endl << "You must enter a destination" << endl;
		return 1;			//terminate
	}

	else if (zones < 0)		//error message if zones is negative
	{
		cout << "---" << endl << "The number of zone boundaries crossed must not be negative" << endl;
		return 1;					//terminate
	}

	else //beginning of the section that actually outputs the cost when inputs are acceptable
	{
		
		if ((age < ADULT && zones <= 1) || (age >= ADULT && age < SENIOR && student == "y" && zones <= 1) || (age >= SENIOR && student == "y" && zones == 1)) //under 18 low distance discount / student low distance discount / senior 1 zone trick
			cout << "---" << endl << "The fare to " << destination << " is $" << MINOR_STUDENT_LOWDISTANCE_FARE << endl;

		else if (age >= SENIOR && zones == 0) //0 zone senior discount
			cout << "---" << endl << "The fare to " << destination << " is $" << ZERO_BOUNDARY_SENIOR_FARE << endl;

		else if (age >= SENIOR && zones >= 1) //1+ zone senior discount
			cout << "---" << endl << "The fare to " << destination << " is $" << ((SENIOR_ZONE_FACTOR * zones) + SENIOR_INITIAL_FARE) << endl;

		else //this is the "standard" cost of riding if no discounts are applied
			cout << "---" << endl << "The fare to " << destination << " is $" << ((STD_ZONE_FACTOR * zones) + STD_INITIAL_FAIR) << endl;
	}
}