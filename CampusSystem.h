#ifndef CAMPUS_SYSTEM_H
#define CAMPUS_SYSTEM_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const string studentFile("Students.txt");
const string facultyFile("Faculty.txt");
const string adminFile("Admins.txt");
const string facilityFile("Facilities.txt");
const string bookingFile("Bookings.txt");
const string invoiceFile("Invoices.txt");
const string authFile("auth.txt");

//==========================================
// 1.User Class
// Abstract class
//=========================================

class User {
    //Encapsulation : Data is Private
    string name;
    string username;
    string password;
    string email;
public:
    //Default Constructor
    User();
    //Parameterized Constructor
    User(string nam, string uname, string pass, string emai);

    //Setters
    void setName(string nam);
    void setUserId(string uname);
    void setPassword(string pass);
    void setEmail(string emai);

    //Getters
    string getName() const;
    string getUserId() const;
    string getPassword() const;
    string getEmail() const;

    //Pure Virtual Function
    virtual void viewMenu() = 0;
    virtual void display();
    virtual ~User();
};

//==========================================
// 2.Student Class
// Inherit From User
//=========================================

class Student : public User {
    //Encapsulation : Data is Private
    string studentId;
    string degreeProgram;
public:
    //Default Constructor
    Student();
    //Parameterized Constructor
    Student(string nam, string uid, string pass, string emai, string stdId, string degrProgr);

    //Setters
    void setStudentId(string stuId);
    void setDegreeProgram(string degrProgr);

    //Getters
    string getStudentId() const;
    string getDegreeProgram() const;

    //Override menu Function of User
    void viewMenu() override;
    void saveFile();
    bool loadFile(ifstream& ifile);
    void display() override;
};

//==========================================
// 3.Faculty Class
// Inherit From User
//=========================================

class Faculty : public User {
    //Encapsulation : Data is Private
    string employeeId;
    string department;
public:
    //Default Constructor
    Faculty();
    //parameterized Constructor
    Faculty(string nam, string uid, string pass, string emai, string empId, string dept);

    //setters
    void setEmployeeId(string empId);
    void setDepartment(string dept);

    //Getters
    string getEmployeeId() const;
    string getDepartment() const;

    //Override menu Function of User
    void viewMenu() override;
    void saveFile();
    bool loadFile(ifstream& ifile);
    void display() override;
};

//==========================================
// 4.Admin Class
// Inherit From User
//=========================================

class Admin : public User {
    //Encapsulation : Data is Private
    int adminLevel;
public:
    //Default Constructor
    Admin();
    //Parameterized Constructor
    Admin(string nam, string uid, string pass, string emai, int admLevel);

    //Setters
    void setAdminLevel(int admLevel);

    //Getters
    int getAdminLevel() const;

    //Override menu Function of User
    void viewMenu() override;
    void saveFile();
    bool loadFile(ifstream& ifile);
    void display() override;
};

//==========================================
// 5.Facility Class
// Standlone
//=========================================

class Facility {
    //Encapsulation : Data is Private
    string facilityId;
    string type; //e.g (Lab/Hall/Ground)
    int capacity;
    double pricePerHour;
public:
    //Default Constructor
    Facility();
    //Parameterized Constructor
    Facility(string facilId, string typ, int capac, double pricePH);

    //Setters
    void setFacilityId(string facilId);
    void setType(string typ);
    void setCapacity(int capac);
    void setPricePerHour(double pricePH);

    //Getters
    string getFacilityId() const;
    string getType() const;
    int getCapacity() const;
    double getPricePerHour() const;

    bool checkAvailability();
    void saveFile();
    void saveToStream(ofstream& ofile);
    bool loadFile(ifstream& ifile);

    friend ostream& operator<<(ostream& out, const Facility& f);
};

//==========================================
// 6.Booking Class
// Composition(Links Student and Facility)
//=========================================

class Booking {
    //Encapsulation : Data is Private
    string bookingId;
    string date;
    int time; //24 hours fomrat
    int duration;
    string status;
    Student student;
    Facility facility;
    Faculty faculty;
    string userType;
public:
    //Default Constructor
    Booking();
    //Parameterized Constructor For Student
    Booking(string bookId, string dat, int tim, int durat, Student stud, Facility facil);
    //Constructor for FACULTY
    Booking(string bookId, string dat, int tim, int durat, Faculty fac, Facility facil);

    string getBookerName();

    //Setters
    void setBookingId(string bookId);
    void setDate(string dat);
    void setTime(int tim);
    void setDuration(int durat);
    void setStatus(string s);

    //Getters
    string getBookingId() const;
    string getDate() const;
    int getTime() const;
    int getDuration() const;
    string getStatus() const;
    Student getStudent() const;
    Facility getFacility() const;
    Faculty getFaculty() const;

    double calculateCost();
    bool checkOverlap(string dat, int tim, int dur);
    void saveFile();
    void saveToStream(ofstream& ofile);
    bool loadFile(ifstream& ifile);
    void display();
};

//==========================================
// 7.Invoice Class
// Composition(Links to Booking)
//=========================================

class Invoice {
    string invoiceId;
    double baseAmount;
    double penaltyFee;
    bool isPaid;
    Booking booking;
public:
    //Default Constructor
    Invoice();
    //Parameterized Constructor
    Invoice(string invoice, Booking b);

    //Setters
    void setInvoiceID(string id);
    void setPenaltyFee(double fee);
    void setIsPaid(bool status);

    //Getters
    string getInvoiceID() const;
    double getTotalAmount() const;
    bool getIsPaid() const;

    void applyPenalty();
    string check_Status();
    void genrateInvoice();
    void saveFile();
    bool loadFile(ifstream& ifile);
};

//==========================================
// CampusSystem Class
// Main Controller
//=========================================

class CampusSystem {
    Student* student[100];
    int studentCount;
    Faculty* faculty[50];
    int facultyCount;
    Admin* admin[5];
    int adminCount;
    Facility* facility[50];
    int facilityCount;
    Booking* booking[100];
    int bookingCount;
    
public:
    CampusSystem();
    ~CampusSystem();

    void loadAllData();
    void addStudents(Student* s);
    void addFaculty(Faculty* f);
    void addAdmin(Admin* a);
    void addFacility(Facility* fac);
    void addBooking(Booking* b);

    void viewAllStudents();
    void viewAllFaculty();
    void viewAllAdmin();
    void viewAllFacility();
    void viewAllbookings();

    void removefacility();
    void removeStudent();
    void removeFaculty();

    void bookNewBooking(string userType, string userName, string userID);
    void viewMyBooking(string name);
    void cancelMyBooking(string name);
    void approveRejectBooking();
    void generateReports();
    void editFacility();
};

//===========================================
// 9. Authentication Class
//===========================================

class Authentication {
    // Encapsulation: Data is private
    string username;
    string password;
    string userrole;
public:
    // Default Constructor
    Authentication();
    // Parameterized Constructor
    Authentication(string user, string pass, string role);

    //Setters
    void setUserName(string user);
    void setPassword(string pass);
    void setUserRole(string rol);

    //Getters
    string getUsername();
    string getPassword();
    string getUserRole();

    void registerUser(string user, string pass, string rol);
    bool verifyRole(string requiredRole);
    bool login(string user, string pass);
    void logout();
};

#endif // CAMPUS_SYSTEM_H