#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Travel {
	
	//public:
	string destination;
	string ship;
	string captain;
	
	double priceClass1 = 0.0, priceClass2 = 0.0;
	
	int numPassengersClass1, numPassengersClass2;
	
	int day, month, year;
	string dateStart, dateEnd;
	
	
};

bool maxCruisesValidation(vector<Travel> Cruises) {
	if(Cruises.size() == 2)return true;
	return false;
}
void maxCruisesValidation() {
	cout << "Maximum size of cruises reached!!!\n"
		<<"If you want to add cruse, change one\n";
		system("pause");
}

void add(vector<Travel> *Cruises) {
	
	if(maxCruisesValidation(*Cruises))
	{
		maxCruisesValidation();
		return;
	}
	Travel newCruise;
	
	cout << "Destination: ";
	cin >> newCruise.destination;
	cout << "Ship : ";
	cin >> newCruise.ship;
	cout << "Captain name: ";
	getline(cin >> ws, newCruise.captain);
	cout << "Price for class 1: ";
	cin >> newCruise.priceClass1;
	cout << "Price for class 2: ";
	cin >> newCruise.priceClass2;
	cout << "Number of passengers in class 1: ";
	cin >> newCruise.numPassengersClass1;
	cout << "Number of passengers in class 2: ";
	cin >> newCruise.numPassengersClass2;
	cout << "Starting date of cruise: ";
	cin >> newCruise.dateStart;
	cout << "Ending date of cruise: ";
	cin >> newCruise.dateEnd;
	
	Cruises->push_back(newCruise);
}

void printVector(vector<Travel> Cruises) {
	
	system("cls");
	//vector<Travel>::iterator it;
	for(int i = 0; i < Cruises.size(); i++)
	{
		
		cout << "Cruise " << i + 1 << endl 
			<< "destination: " << Cruises.at(i).destination << endl
			<< "ship name: " << Cruises.at(i).ship << endl
			<< "captain: " << Cruises.at(i).captain << endl
			<< "class 1 price: " << Cruises.at(i).priceClass1 << endl
			<< "class 2 price: " << Cruises.at(i).priceClass2 << endl
			<< "class 1 passengers: " << Cruises.at(i).numPassengersClass1 << endl
			<< "class 2 passengers: " << Cruises.at(i).numPassengersClass2 << endl
			<< "Start date: " << Cruises.at(i).dateStart << endl
			<< "End date: " << Cruises.at(i).dateEnd << endl
			
			
			;
		cout << "\n\n\n";
	}
	system("pause");
}

void ODIT() {
	
	cout << "1.Cruises sorted by ship nVme\n"
		<< "2.Cruises for a period sorted by date\n"
		<< "3.Cruises to destinations and month sorted by month\n"
		<< "4.Back\n"
		;
	int input = 1;
	while(input > 0 && input < 3)
	cin >> input;
	switch(input)
	{
		
		case 4: return;
	}
}

void functions() {
	
	cout << "1.add\n"
		<< "2.Show all cruises\n"
		<< "3.Change a cruise\n"
		<< "4.Cruise with lowest price\n"
		<< "5.Cruise with the most passengers\n"
		<< "6.Ship with the most cruises\n"
		<< "7.Show cruises sorted by...\n"
		<< "8.Exit\n"
		;
}

int main() {
	
	vector<Travel> Cruises;
	Travel A;// = new Travel;
	ofstream fout("memory.txt",ofstream::out);
	ifstream fin("memory.txt");
	
	string line="13";
	if (fin.is_open())
	{
		while (getline(fin,line))
		{
			cout << line <<'\n';
		}
		fin.close();
	}
	
	else 
	{
		cout << "Unable to open file\n";
		system("pause");
		return 0;
	}
	string a;
	fin >> a;
	cout << a;
	A.ship = "red";
	A.captain = "Ivan Zarev";
	A.destination = "Atlantida";
	Cruises.push_back(A);
	int input = 0;
	
	while(input != 8)
	{
		system("cls");
		functions();
		
		cout << "\noption: ";
		cin >> input;
		switch(input)
		{
			case 1: add(&Cruises); break;
			case 2 : printVector(Cruises); break;
			
			case 7: ODIT(); break;
		}
	}
}