#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    string subject[n];
    float grade[n], credit[n];

    float totalCredits = 0, totalGradePoints = 0;

    
    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << ":\n";

        cout << "Enter subject name: ";
        cin >> subject[i];

        cout << "Enter grade (e.g., 10, 9, 8): ";
        cin >> grade[i];

        cout << "Enter credit hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

   
    float cgpa = totalGradePoints / totalCredits;

    
    cout << "\n----- Result -----\n";
    for (int i = 0; i < n; i++) {
        cout << subject[i] << " -> Grade: " << grade[i]
             << ", Credits: " << credit[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}