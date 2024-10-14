#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Структура для зберігання інформації про курс
struct Course {
    string title;
    string instructor;
    int duration; 
    double rating;

    // Функція для виведення інформації про курс
    void print() const {
        cout << "Course Title: " << title << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Rating: " << rating << endl;
    }
};

// Функція для додавання нового курсу
void addCourse(vector<Course>& courses) {
    Course course;
    cout << "Enter course title: ";
    getline(cin >> ws, course.title);  
    cout << "Enter instructor's name: ";
    getline(cin, course.instructor);
    cout << "Enter course duration (in hours): ";
    cin >> course.duration;
    cout << "Enter course rating: ";
    cin >> course.rating;
    courses.push_back(course);  
}

// Функція для пошуку курсу за назвою або викладачем
void searchCourse(const vector<Course>& courses, const string& query) {
    for (const auto& course : courses) {
        if (course.title == query || course.instructor == query) {
            course.print();
            return;
        }
    }
    cout << "Course not found." << endl;
}

// Функція для виведення всіх курсів
void displayCourses(const vector<Course>& courses) {
    for (const auto& course : courses) {
        course.print();
        cout << "---------------------" << endl;
    }
}

// Функція для збереження курсів у файл
void saveCourses(const vector<Course>& courses, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& course : courses) {
            file << course.title << endl;
            file << course.instructor << endl;
            file << course.duration << endl;
            file << course.rating << endl;
        }
        file.close();
        cout << "Courses saved to file." << endl;
    }
    else {
        cout << "Unable to open file for saving." << endl;
    }
}

// Функція для завантаження курсів з файлу
void loadCourses(vector<Course>& courses, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        Course course;
        while (getline(file, course.title)) {
            getline(file, course.instructor);
            file >> course.duration;
            file >> course.rating;
            file.ignore();
            courses.push_back(course);
        }
        file.close();
        cout << "Courses loaded from file." << endl;
    }
    else {
        cout << "Unable to open file for loading." << endl;
    }
}

int main() {
    vector<Course> courses;
    int choice;
    string query, filename;

    do {
        cout << "1. Add Course" << endl;
        cout << "2. Search Course" << endl;
        cout << "3. Display Courses" << endl;
        cout << "4. Save Courses to File" << endl;
        cout << "5. Load Courses from File" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCourse(courses);
            break;
        case 2:
            cout << "Enter course title or instructor to search: ";
            cin.ignore();
            getline(cin, query);
            searchCourse(courses, query);
            break;
        case 3:
            displayCourses(courses);
            break;
        case 4:
            cout << "Enter filename to save courses: ";
            cin >> filename;
            saveCourses(courses, filename);
            break;
        case 5:
            cout << "Enter filename to load courses: ";
            cin >> filename;
            loadCourses(courses, filename);
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
