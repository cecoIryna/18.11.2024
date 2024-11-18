#include <iostream>
#pragma warning(disable : 4996)
#include <cstring>

using namespace std;

class Employer {
protected:
    char* name;

public:
    Employer(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    virtual ~Employer() {
        delete[] name;
    }

    virtual void Print() const = 0;
};

class President : public Employer {
    char* country;

public:
    President(const char* name, const char* country): Employer(name) {
        this->country = new char[strlen(country) + 1];
        strcpy(this->country, country);
    }

    ~President() {
        delete[] country;
    }

    void Print() const override {
        cout << "President: " << name << "\nCountry: " << country << endl;
        cout << endl;
    }
};

class Manager : public Employer {
    char* department;

public:
    Manager(const char* name, const char* department)
        : Employer(name) {
        this->department = new char[strlen(department) + 1];
        strcpy(this->department, department);
    }

    ~Manager() {
        delete[] department;
    }

    void Print() const override {
        cout << "Manager: " << name << "\nDepartment: " << department << endl;
        cout << endl;
    }
};

class Worker : public Employer {
    char* position;

public:
    Worker(const char* name, const char* position)
        : Employer(name) {
        this->position = new char[strlen(position) + 1];
        strcpy(this->position, position);
    }

    ~Worker() {
        delete[] position;
    }

    void Print() const override {
        cout << "Worker: " << name << "\nPosition: " << position << endl;
        cout << endl;
    }
};

int main() {
    President president("John Doe", "USA");
    Manager manager("Ann Smith", "Sales");
    Worker worker("Bob Brown", "Programist");

    Employer* employees[] = { &president, &manager, &worker };

    for (int i = 0; i < 3; ++i) {
        employees[i]->Print();
    }

    return 0;
}