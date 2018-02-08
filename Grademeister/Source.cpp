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
	const int maxStudents = 100;
	string student[maxStudents];
	double average[maxStudents];
	double topAvg = 0, classAvg = 0, classSum = 0;
	int numStudents = 0;
	for (int studentInc = 1; studentInc < maxStudents; studentInc++)
	{
		cout << "Enter student's name (or X to exit):             ";
		if(cin.peek() == '\n') cin.ignore();
		getline(cin, studentName);
		if (studentName == "x" || studentName == "X")
			break;

		//Exam Average
		double exSum = 0;
		double grade = 0, exAvg;
		for (int exInc = 1; exInc <= numExams; exInc++)
		{
			cout << "Enter grade for Exam " << exInc << ":                          ";
			cin >> grade;
			exSum += grade;
		}
		if (numExams == 0)
		{
			exAvg = 100;
		}
		else {
			exAvg = exSum / numExams;
		}

		//Project average
		double projSum = 0, projAvg;
		for (int projInc = 1; projInc <= numProjs; projInc++)
		{
			cout << "Enter grade for project " << projInc << ":                       ";
			cin >> grade;
			projSum += grade;
		}
		if (numProjs == 0)
		{
			projAvg = 100;
		}
		else {
			projAvg = projSum / numProjs;
		}

		//Lab average
		double labSum = 0, labAvg;
		for (int labInc = 1; labInc <= numLabs; labInc++)
		{
			cout << "Enter grade for lab " << labInc << ":                           ";
			cin >> grade;
			labSum += grade;
		}
		if (numLabs == 0)
		{
			labAvg = 100;
		}
		else 
		{
			labAvg = labSum / numLabs;
		}

		//Attendance grade
		double daysAvg = 0, daysSum;
		cout << "Enter total number of days student attended:     ";
		cin >> daysSum;
		while (daysSum > numDays)
		{
			cout << "ERROR: Must be less than or equal to total days:        ";
			cin >> daysSum;
		}
		if (numDays == 0)
		{
			daysAvg = 100;
		}
		else
		{
			daysAvg = (daysSum / numDays) * 100;
		}

		//Overall average
		double overallAvg = (exAvg*0.4) + (projAvg*0.3) + (labAvg*0.2) + (daysAvg*0.1);
		//One number past the decimal
		cout << fixed << setprecision(1);
		//Letter grade
		char letterGrade;
		if (overallAvg >= 90) {
			letterGrade = 'A';
		}
		else if (overallAvg >= 80 && overallAvg < 90){
			letterGrade = 'B';
		}
		else if (overallAvg >= 70 && overallAvg < 80) {
			letterGrade = 'C';
		}
		else if (overallAvg >= 60 && overallAvg < 70) {
			letterGrade = 'D';
		}
		else {
			letterGrade = 'E';
		}

		//Present student report
		cout << "+--------------------------------------------------------------------------+\n";
		cout << left << setw(22) << "| Grade Report for: " << studentName << "                                                   |\n";
		cout << "+--------------------------------------------------------------------------+\n";
		cout << setw(75) << left << "| Exam Average | Proj Average | Lab Average | Attendance | Overall | Grade |\n";
		cout << "| " << setw(7.5) << internal << exAvg << setw(8) << internal << " | " << setw(7) << internal << projAvg << setw(8) << internal << " | " << setw(7) << internal << labAvg << setw(7) << internal << " | " << setw(7) << internal << daysAvg << setw(6) << internal << " | " << setw(4) << internal << overallAvg << setw(6) << internal << " | " << setw(3.5) << internal << letterGrade << "   |\n";
		cout << "+-----------------------------------------------------------------------------+\n";

		//Record keeping
		average[studentInc - 1] = overallAvg;
		student[studentInc - 1] = studentName;
		if (overallAvg > topAvg) {
			topAvg = overallAvg;
		}
		classSum += overallAvg;
		numStudents++;
	}
	classAvg = classSum / numStudents;

	
	system("pause");
	return(0);
}