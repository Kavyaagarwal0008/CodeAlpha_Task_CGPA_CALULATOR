#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Make structure for your particular course

struct Subject
{
    string name;
    string grade;
    float gradePoint;
    int credit;
};

// Grade and particular point for that grade combined using mapping
map<string, float> gradeToPoint = {
    {"A+", 10.0}, {"A", 9.0}, {"B+", 8.0}, {"B", 7.0}, {"C", 6.0}, {"D", 5.0}, {"E", 4.0}, {"F", 0.0}};

float getGradepoint(string &grade)
{

    if (gradeToPoint.find(grade) != gradeToPoint.end())
    {
        return gradeToPoint[grade];
    }
    else
    {
        return -1; // for giving invalid grade
    }
}

int main()
{

    int total_subject;
    vector<Subject> subject;
    cout << "enter the number of Subject including both theory and practical: ";
    cin >> total_subject;
    float totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < total_subject; i++)
    {

        Subject s;
        cout << "\nSubject " << i + 1 << " details:\n";
        cout << "Enter subject name: ";
        cin.ignore();         // remove \n
        getline(cin, s.name); // to read until newline i.e \n

        cout << "Enter letter grade (A+, A, B+, B, C, D, E, F): ";
        cin >> s.grade;

        s.gradePoint = getGradepoint(s.grade);
        while (s.gradePoint == -1)
        {
            cout << "Invalid Grade. Please enter valid one: ";
            cin >> s.grade;
            ;
            s.gradePoint = getGradepoint(s.grade);
        }

        cout << "Enter credit : ";
        cin >> s.credit;
        totalGradePoints += (s.gradePoint * s.credit);
        totalCredits += s.credit;
        subject.push_back(s);
    }
    float cgpa = totalGradePoints / totalCredits;
    // display subject wise information
    cout << "\n---- Individual Subject Details ----\n";
    cout << left << setw(15) << "Course"
         << setw(10) << "Grade"
         << setw(15) << "Grade Point"
         << setw(10) << "Credits" << endl;

    for (const auto &s : subject)
    {
        cout << left << setw(15) << s.name
             << setw(10) << s.grade
             << setw(15) << s.gradePoint
             << setw(10) << s.credit << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}