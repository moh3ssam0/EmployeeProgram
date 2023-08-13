//============================================================================
// Name        : EmployeeProgram.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
const int Max = 1000;
string names[Max];
int ages[Max];
float salaries[Max];
char genders[Max];
int empNum= 0;  //number of employees

int menu(){
	int choice = -1;
	while(choice == -1){
		cout << "Enter your choice \n";
		cout << "1. Add new employee.\n";
		cout << "2. Print all employees.\n";
		cout << "3. Delete employee by name.\n";
		cout << "4. Update employee by age.\n";
		cout << "5. Exit.\n";

		cin >> choice;

		//for invalid values
		if(!(choice >= 1 && choice <=5)){
			cout << "Invalid choice, Try again\n";
			choice = -1;  //to keep looping
		}

	}
	return choice;
}

void addEmployee(){
	cout << "Enter name : ";
	cin >> names[empNum];
	cout << "Enter age : ";
	cin >> ages[empNum];
	cout << "Enter salary : ";
	cin >> salaries[empNum];
	cout << "Enter gender (M/F) : ";
	cin >> genders[empNum];
	empNum++;
}

void printEmployees(){
	cout << "***********************************\n";
	for(int i = 0;i<empNum;++i){
		if(ages[i]==0)
			continue;
		cout << names[i] << " " << ages[i] << " " << salaries[i] << " " <<genders[i] << "\n";

	}
}

void deleteEmployeeByAge(){
	cout << "Enter the range of ages (start & end) : ";
	int strt,end;cin >> strt >> end;
	for(int i =0;i<empNum;++i){
		if(ages[i]== strt || ages[end] == end)
			ages[i] = 0;
	}

}

void updateSalaryByName(){
	cout << "Enter the name & new salary : ";
	string name;float newSalary;
	cin >> name >> newSalary;
	bool nameFound = false;
	for (int i = 0; i < empNum; ++i) {
		if(ages != 0 && names[i]==name){
			salaries[i] = newSalary;
			nameFound = true;
			break;
		}
	}
	if(!nameFound)
		cout << "No data found.\n";

}

void employeeInterface(){
	while(true){
		int choice = menu();
		if(choice == 1)
			addEmployee();
		else if(choice == 2)
			printEmployees();
		else if(choice == 3)
			deleteEmployeeByAge();
		else if(choice == 4)
			updateSalaryByName();
		else{
			cout << "Have a good day:)\n";
			break;}
	}
}


int main() {

	employeeInterface();

	return 0;
}
