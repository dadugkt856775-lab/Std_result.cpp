
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    double marks[3];

    double total() const {
        return marks[0] + marks[1] + marks[2];
    }

    double average() const {
        return total() / 3.0;
    }

    char grade() const {
        double avg = average();

        if (avg >= 90) return 'A';
        if (avg >= 75) return 'B';
        if (avg >= 60) return 'C';
        if (avg >= 40) return 'D';
        return 'F';
    }
};

int main() {
    vector<Student> students;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of students must be positive.\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        Student s;

        cout << "\nEnter Roll Number: ";
        cin >> s.rollNumber;

        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, s.name);

        bool valid = true;

        for (int j = 0; j < 3; j++) {
            cout << "Enter marks for Subject "
                 << j + 1 << ": ";
            cin >> s.marks[j];

            if (s.marks[j] < 0 || s.marks[j] > 100)
                valid = false;
        }

        if (!valid) {
            cout << "Invalid marks! Enter marks between 0 and 100.\n";
            return 0;
        }

        students.push_back(s);
    }

    sort(students.begin(), students.end(),
        [](const Student &a, const Student &b) {
            return a.total() > b.total();
        });

    cout << "\n========== STUDENT RESULT ==========\n";
    cout << fixed << setprecision(2);

    for (size_t i = 0; i < students.size(); i++) {
        const Student &s = students[i];

        cout << "\nRank: " << i + 1
             << "\nRoll Number: " << s.rollNumber
             << "\nName: " << s.name
             << "\nTotal Marks: " << s.total()
             << "/300"
             << "\nAverage: " << s.average()
             << "\nGrade: " << s.grade()
             << "\nResult: "
             << (s.grade() == 'F' ? "Fail" : "Pass")
             << "\n";
    }

    return 0;
}
