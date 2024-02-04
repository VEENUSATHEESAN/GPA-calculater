#include <iostream>
#include <string>
#include <map>
using namespace std;

double gradeToGPA(string grade) {
    static map<string, double> gradeGPA = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B", 3.0},
        {"B-", 2.7}, {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1.0}, {"E", 0.0}
    };

    return gradeGPA[grade];
}

int main()
{
    string name, sem;
    int sub;

    cout << "YOUR NAME:  " << endl;
    getline(cin, name);

    cout << "YOUR SEMESTER:  " << endl;
    getline(cin, sem);

    cout << "HOW MANY SUBJECTS IN YOUR SEMESTER:  " << endl;
    cin >> sub;

    cin.ignore(); // Ignore the newline character left in the stream

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < sub; i++) {
        string cname;
        string grade;
        double credits;

        cout << "ENTER YOUR SUBJECT NAME " << i + 1 << ":  " << endl;
        getline(cin, cname);

        cout << "ENTER YOUR GRADE:  " << endl;
        cin >> grade;

        cout << "ENTER THE CREDITS OF THE SUBJECT:  " << endl;
        cin >> credits;

        totalCredits += credits;
        totalGradePoints += gradeToGPA(grade) * credits;

        cin.ignore(); // Ignore the newline character left in the stream
    }

    double GPA = totalGradePoints / totalCredits;
    cout<<"-------------------------------------"<<endl;
    cout << "\nName: " << name << endl;
    cout << "Semester: " << sem << endl;
    cout << "-------------Subjects & Results--------------" << endl;
   /* for (int i = 0; i < sub; ++i) {
        string cname;
        string grade;

        cout << "Subject " << i + 1 << ": ";
        getline(cin, cname);

        cout << "Grade: ";
        cin >> grade;

        cout << cname << ": " << grade << endl;*/
    //}
    cout << "GPA: " << GPA << endl;

    if (GPA >= 3.7) {
        cout << "Class: First Class" << endl;
    } else if (GPA >= 3.3) {
        cout << "Class: Upper Second Class" << endl;
    } else if (GPA >= 3.0) {
        cout << "Class: Lower Second Class" << endl;
    } else if (GPA >= 2.0) {
        cout << "Class: Pass" << endl;
    } else {
        cout << "Class: Fail" << endl;
    }

    return 0;
}
