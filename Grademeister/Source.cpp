/*
----------------------------------------
CS 215 - Spring 18
Project 1
----------------------------------------
Author: Bram Hampton
Section: 003
Description:
Assistance:
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Header
	cout << "+-------------------------------------+\n";
	cout << "|" << setw(30) << "        GRADEMEISTER 900000          |\n";
	cout << "|" << setw(28) << "          By Bram Hampton            |\n";
	cout << "+-------------------------------------+\n";
	cout << endl;
	//# of grades
	int numExams, numProjs, numLabs, numDays;
	cout << "NUMBER OF GRADED ITEMS THIS SEMESTER\n";
	cout << endl << "Enter number of exams:                           ";
	cin >> numExams;
	while (numExams < 0 || numExams > 5)
	{
		cout << endl << "ERROR: Must be between 0 and 5";
		cout << endl << "Please enter number of exams:                    ";
		cin >> numExams;
	}
	cout << endl << "Enter number of projects:                        ";
	cin >> numProjs;
	while (numProjs < 0 || numProjs > 4)
	{
		cout << endl << "ERROR: Must be between 0 and 4";
		cout << endl << "Please enter number of projects:                 ";
		cin >> numProjs;
	}
	cout << endl << "Enter number of labs:                            ";
	cin >> numLabs;
	while (numLabs < 0 || numLabs > 10)
	{
		cout << endl << "ERROR: Must be between 0 and 10";
		cout << endl << "Please enter number of labs:                     ";
		cin >> numLabs;
	}
	cout << endl << "Enter total number of attendance days:           ";
	cin >> numDays;
	while (numDays < 0 || numDays > 30)
	{
		cout << endl << "ERROR: Must be between 0 and 30";
		cout << endl << "Please enter total number of attendance days:    ";
		cin >> numDays;
	}
	cout << endl;

	//Student Processing
	string studentName;
	while (studentName != "X" && studentName != "x")
	{
		cout << "Enter student's name (or X to exit):  ";
		if(cin.peek() == '\n') cin.ignore();
		getline(cin, studentName);
		if (studentName == "x" || studentName == "X")
			break;

		//Exam Average
		double exSum = 0;
		double grade = 0, exAvg;
		for (int exInc = 1; exInc <= numExams; exInc++)
		{
			cout << "Enter grade for Exam " << exInc << ":   ";
			cin >> grade;
			exSum += grade;
		}
		exAvg = exSum / numExams;

		//Project average
		double projSum = 0, projAvg;
		for (int projInc = 1; projInc <= numProjs; projInc++)
		{
			cout << "Enter grade for project " << projInc << ":   ";
			cin >> grade;
			projSum += grade;
		}
		projAvg = projSum / numProjs;

		//Lab average
		double labSum = 0, labAvg;
		for (int labInc = 1; labInc <= numLabs; labInc++)
		{
			cout << "Enter grade for lab " << labInc << ":   ";
			cin >> grade;
			labSum += grade;
		}
		labAvg = labSum / numLabs;

		//Attendance grade
		double daysAvg = 0, daysSum;
		cout << "Enter total number of days student attended:    ";
		cin >> daysSum;
		daysAvg = (daysSum / numDays) * 100;
	}
	
	system("pause");
	return(0);
}