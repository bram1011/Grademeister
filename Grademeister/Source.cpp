/*
----------------------------------------
CS 215 - Spring 18
Project 1
----------------------------------------
Author: Bram Hampton
Section: 003
Description: Gradebook
Assistance: cplusplus.com -- Found the 'internal' command for formatting text
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string studentName;
	string topStudent;
	const int maxStudents = 100;
	string student[maxStudents];
	double average[maxStudents];
	double topAvg = 0, classAvg = 0, classSum = 0;
	int numExams, numProjs, numLabs, numDays, maxExams = 5, maxProjs = 4, maxLabs = 10, maxDays = 30;
	int numStudents = 0;
	double daysAvg = 0, daysSum;
	double overallAvg;
	char letterGrade;
	int gradeA = 90, gradeB = 80, gradeC = 70, gradeD = 60;
	//Header
	cout << "+-------------------------------------+\n";
	cout << "|" << setw(30) << "        GRADEMEISTER 900000          |\n";
	cout << "|" << setw(28) << "          By Bram Hampton            |\n";
	cout << "+-------------------------------------+\n";
	cout << endl;
	//# of grades
	cout << "NUMBER OF GRADED ITEMS THIS SEMESTER\n";
	cout << "--------------------------------------\n\n";

	//Exams
	cout << endl << "Enter number of exams:                           ";
	cin >> numExams;
	if (numExams < 0 || numExams > maxExams) {
		do {
			cout << endl << "ERROR: Must be between 0 and 5";
			cout << endl << "Please enter number of exams:                    ";
			cin >> numExams;
		} while (numExams < 0 || numExams > maxExams);
	}

	//Projects
	cout << endl << "Enter number of projects:                        ";
	cin >> numProjs;
	if (numProjs < 0 || numProjs > maxProjs) {
		do {
			cout << endl << "ERROR: Must be between 0 and 4";
			cout << endl << "Please enter number of projects:                 ";
			cin >> numProjs;
		} while (numProjs < 0 || numProjs > maxProjs);
	}

	//Labs
	cout << endl << "Enter number of labs:                            ";
	cin >> numLabs;
	if (numLabs < 0 || numLabs > maxLabs) {
		do {
			cout << endl << "ERROR: Must be between 0 and 10";
			cout << endl << "Please enter number of labs:                     ";
			cin >> numLabs;
		} while (numLabs < 0 || numLabs > maxLabs);
	}
	
	//Attendance
	cout << endl << "Enter total number of attendance days:           ";
	cin >> numDays;
	if (numDays < 0 || numDays > maxDays) {
		do {
			cout << endl << "ERROR: Must be between 0 and 30";
			cout << endl << "Please enter total number of attendance days:    ";
			cin >> numDays;
		} while (numDays < 0 || numDays > maxDays);
	}
	
	cout << endl << endl;

	//Student Processing
	for (int studentInc = 1; studentInc < maxStudents; studentInc++)
	{
		double exSum = 0;
		double grade = 0, exAvg, labSum = 0, labAvg;
		double projSum = 0, projAvg;
		cout << "STUDENT PROCESSING\n";
		cout << "-------------------\n";
		cout << "Enter student's name (or X to exit):             ";
		if(cin.peek() == '\n') cin.ignore();
		getline(cin, studentName);
		if (studentName == "x" || studentName == "X")
			break;

		//Exam Average
		
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
		cout << "Enter total number of days student attended:     ";
		cin >> daysSum;
		if (daysSum > numDays) {
			do {
				cout << "ERROR: Must be less than or equal to total days:        ";
				cin >> daysSum;
			} while (daysSum > numDays);
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
		overallAvg = (exAvg*0.4) + (projAvg*0.3) + (labAvg*0.2) + (daysAvg*0.1);
		//One number past the decimal
		cout << fixed << setprecision(1);
		//Letter grade
		if (overallAvg >= gradeA) {
			letterGrade = 'A';
		}
		else if (overallAvg >= gradeB && overallAvg < gradeA){
			letterGrade = 'B';
		}
		else if (overallAvg >= gradeC && overallAvg < gradeB) {
			letterGrade = 'C';
		}
		else if (overallAvg >= gradeD && overallAvg < gradeC) {
			letterGrade = 'D';
		}
		else {
			letterGrade = 'E';
		}

		//Present student report
		cout << endl << endl << endl;
		cout << "+--------------------------------------------------------------------------+\n";
		cout << "| Grade Report for: " << left << setw(54) << studentName << " |\n";
		cout << "+--------------------------------------------------------------------------+\n";
		cout << setw(75) << left << "| Exam Average | Proj Average | Lab Average | Attendance | Overall | Grade |\n";
		cout << "|    " << setw(5) << internal << exAvg << "     |    " 
		<< setw(5) << internal << projAvg << "     |    "
		<< setw(5) << internal << labAvg << "    |   " 
		<< setw(5) << internal << daysAvg << "    |  " 
		<< setw(5) << internal << overallAvg << "  |" 
		<< setw(5) << internal << letterGrade << "  |\n";
		cout << "+--------------------------------------------------------------------------+\n\n";

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

	//Find top student
	for (int topStudentInc = 0; topStudentInc < numStudents; topStudentInc++) {
		if (average[topStudentInc] == topAvg) {
			topStudent = student[topStudentInc];
		}
	}

	//Blank Class Report
	if (student[0] == "") {
		cout << endl << endl << endl << "+----------------------------------------------------------------------------------------+\n";
		cout << "|                                    CLASS REPORT                                        |\n";
		cout << "+----------------------------------------------------------------------------------------+\n";
		cout << "|                              ERROR: NO STUDENTS ENTERED                                |\n";
		cout << "+----------------------------------------------------------------------------------------+\n\n";
		system("pause");
		return 0;
	}


	//Class Report
	cout << endl << endl << endl << "+----------------------------------------------------------------------------------------+\n";
	cout << "|                                    CLASS REPORT                                        |\n";
	cout << "+----------------------------------------------------------------------------------------+\n";
	cout << "| Class Average | Top Average | Top Student                                              |\n";
	cout << "+----------------------------------------------------------------------------------------+\n";
	cout << "|     " << setw(5) << internal << classAvg << "     |     " << setw(5) << internal << topAvg << "   |   " << setw(55) << left << topStudent << "|\n";
	cout << "+----------------------------------------------------------------------------------------+\n\n";
	
	system("pause");
	return(0);
}