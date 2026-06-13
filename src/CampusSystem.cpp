#include "../include/CampusSystem.h"

//==========================================
// 1.User Class Definitions
//==========================================
User::User() : name(" "), username(" "), password(" "), email(" ") {}

User::User(string nam, string uname, string pass, string emai) {
    name = nam;
    username = uname;
    password = pass;
    email = emai;
}

void User::setName(string nam) { name = nam; }
void User::setUserId(string uname) { username = uname; }
void User::setPassword(string pass) { password = pass; }
void User::setEmail(string emai) { email = emai; }

string User::getName() const { return name; }
string User::getUserId() const { return username; }
string User::getPassword() const { return password; }
string User::getEmail() const { return email; }

void User::display() {
    cout << "Name:" << name << endl;
    cout << "User_Name:" << username << endl;
    cout << "Email:" << email << endl;
}

User::~User() {}

//==========================================
// 2.Student Class Definitions
//==========================================
Student::Student() : studentId(" "), degreeProgram(" "), User() {}

Student::Student(string nam, string uid, string pass, string emai, string stdId, string degrProgr)
    : User(nam, uid, pass, emai) {
    studentId = stdId;
    degreeProgram = degrProgr;
}

void Student::setStudentId(string stuId) { studentId = stuId; }
void Student::setDegreeProgram(string degrProgr) { degreeProgram = degrProgr; }

string Student::getStudentId() const { return studentId; }
string Student::getDegreeProgram() const { return degreeProgram; }

void Student::viewMenu() {
    cout << "=========Student Menu" << " (" << getName() << ") " << "==========" << endl;
    cout << "1. View Facilites" << endl;
    cout << "2. Request Booking" << endl;
    cout << "3. View My Bookings" << endl;
    cout << "4. Cancel Booking" << endl;
    cout << "5. LogOut" << endl;
}

void Student::saveFile() {
    ofstream ofile(studentFile, ios::app);
    if (ofile.is_open()) {
        ofile << getName() << endl;
        ofile << getUserId() << endl;
        ofile << getPassword() << endl;
        ofile << getEmail() << endl;
        ofile << studentId << endl;
        ofile << degreeProgram << endl;
        ofile.close();
    }
    else {
        cout << "Error While File Openning" << endl;
    }
}

bool Student::loadFile(ifstream& ifile) {
    string name, userId, password, email, stdId, degrProg;
    if (!getline(ifile, name)) {
        return false;
    }
    else {
        setName(name);
        getline(ifile, userId);
        setUserId(userId);
        getline(ifile, password);
        setPassword(password);
        getline(ifile, email);
        setEmail(email);
        getline(ifile, stdId);
        studentId = stdId;
        getline(ifile, degrProg);
        degreeProgram = degrProg;
        return true;
    }
}

void Student::display() {
    User::display();
    cout << "Student_ID:" << studentId << endl;
    cout << "Degree_Program:" << degreeProgram << endl;
}

//==========================================
// 3.Faculty Class Definitions
//==========================================
Faculty::Faculty() : employeeId(" "), department(" "), User() {}

Faculty::Faculty(string nam, string uid, string pass, string emai, string empId, string dept)
    : User(nam, uid, pass, emai) {
    employeeId = empId;
    department = dept;
}

void Faculty::setEmployeeId(string empId) { employeeId = empId; }
void Faculty::setDepartment(string dept) { department = dept; }

string Faculty::getEmployeeId() const { return employeeId; }
string Faculty::getDepartment() const { return department; }

void Faculty::viewMenu() {
    cout << "=========Faculty Menu" << " (" << getName() << ") " << "==========" << endl;
    cout << "1. View Facilites" << endl;
    cout << "2. Request Booking" << endl;
    cout << "3. View My Bookings" << endl;
    cout << "4. Cancel Booking" << endl;
    cout << "5. LogOut" << endl;
}

void Faculty::saveFile() {
    ofstream ofile(facultyFile, ios::app);
    if (ofile.is_open()) {
        ofile << getName() << endl;
        ofile << getUserId() << endl;
        ofile << getPassword() << endl;
        ofile << getEmail() << endl;
        ofile << employeeId << endl;
        ofile << department << endl;
        ofile.close();
    }
    else {
        cout << "Error While File Openning" << endl;
    }
}

bool Faculty::loadFile(ifstream& ifile) {
    string name, userId, password, email, empId, dept;
    if (!getline(ifile, name)) {
        return false;
    }
    else {
        setName(name);
        getline(ifile, userId);
        setUserId(userId);
        getline(ifile, password);
        setPassword(password);
        getline(ifile, email);
        setEmail(email);
        getline(ifile, empId);
        employeeId = empId;
        getline(ifile, dept);
        department = dept;
        return true;
    }
}

void Faculty::display() {
    User::display();
    cout << "Employee_Id:" << employeeId << endl;
    cout << "Department:" << department << endl;
}

//==========================================
// 4.Admin Class Definitions
//==========================================
Admin::Admin() : adminLevel(0), User() {}

Admin::Admin(string nam, string uid, string pass, string emai, int admLevel)
    : User(nam, uid, pass, emai) {
    adminLevel = admLevel;
}

void Admin::setAdminLevel(int admLevel) { adminLevel = admLevel; }
int Admin::getAdminLevel() const { return adminLevel; }

void Admin::viewMenu() {
    cout << "=========Admin Menu" << " (" << getName() << ") " << "==========" << endl;
    cout << "1. Add Facility" << endl;
    cout << "2. Edit Facility" << endl;
    cout << "3. Remove Facility" << endl;
    cout << "4. View/Approve Booking Requests" << endl;
    cout << "5. Generate Reports" << endl;
    cout << "6. LogOut" << endl;
}

void Admin::saveFile() {
    ofstream ofile(adminFile, ios::app);
    if (ofile.is_open()) {
        ofile << getName() << endl;
        ofile << getUserId() << endl;
        ofile << getPassword() << endl;
        ofile << getEmail() << endl;
        ofile << adminLevel << endl;
        ofile.close();
    }
    else {
        cout << "Error While File Openning" << endl;
    }
}

bool Admin::loadFile(ifstream& ifile) {
    string name, userId, password, email;
    int level;
    if (!getline(ifile, name)) {
        return false;
    }
    else {
        setName(name);
        getline(ifile, userId);
        setUserId(userId);
        getline(ifile, password);
        setPassword(password);
        getline(ifile, email);
        setEmail(email);
        ifile >> level;
        ifile.ignore();
        adminLevel = level;
        return true;
    }
}

void Admin::display() {
    User::display();
    cout << "Admin Level: " << adminLevel << endl;
}

//==========================================
// 5.Facility Class Definitions
//==========================================
Facility::Facility() : facilityId(" "), type(" "), capacity(0), pricePerHour(0) {}

Facility::Facility(string facilId, string typ, int capac, double pricePH) {
    facilityId = facilId;
    type = typ;
    capacity = capac;
    pricePerHour = pricePH;
}

void Facility::setFacilityId(string facilId) { facilityId = facilId; }
void Facility::setType(string typ) { type = typ; }
void Facility::setCapacity(int capac) { capacity = capac; }
void Facility::setPricePerHour(double pricePH) { pricePerHour = pricePH; }

string Facility::getFacilityId() const { return facilityId; }
string Facility::getType() const { return type; }
int Facility::getCapacity() const { return capacity; }
double Facility::getPricePerHour() const { return pricePerHour; }

bool Facility::checkAvailability() { return true; }

void Facility::saveFile() {
    ofstream ofile(facilityFile, ios::app);
    if (ofile.is_open()) {
        ofile << facilityId << endl;
        ofile << type << endl;
        ofile << capacity << endl;
        ofile << pricePerHour << endl;
        ofile.close();
    }
    else {
        cout << "Error While File Openning" << endl;
    }
}

void Facility::saveToStream(ofstream& ofile) {
    ofile << facilityId << endl;
    ofile << type << endl;
    ofile << capacity << endl;
    ofile << pricePerHour << endl;
}

bool Facility::loadFile(ifstream& ifile) {
    string facilId, typ;
    int capac;
    double pricePH;
    if (!getline(ifile, facilId)) {
        return false;
    }
    else {
        facilityId = facilId;
        getline(ifile, typ);
        type = typ;
        ifile >> capac;
        ifile.ignore();
        capacity = capac;
        ifile >> pricePH;
        ifile.ignore();
        pricePerHour = pricePH;
        return true;
    }
}

ostream& operator<<(ostream& out, const Facility& f) {
    out << "ID:" << f.facilityId << endl;
    out << "Type:" << f.type << endl;
    out << "Capacity:" << f.capacity << endl;
    out << "Price_Per_Hour:$ " << f.pricePerHour << endl;
    return out;
}

//==========================================
// 6.Booking Class Definitions
//==========================================
Booking::Booking() : bookingId(" "), date(" "), time(0), duration(0), status("Pending"), userType(""), student(), facility(), faculty() {}

Booking::Booking(string bookId, string dat, int tim, int durat, Student stud, Facility facil)
    : student(stud), facility(facil) {
    bookingId = bookId;
    date = dat;
    time = tim;
    duration = durat;
    status = "Pending";
    userType = "Student";
}

Booking::Booking(string bookId, string dat, int tim, int durat, Faculty fac, Facility facil)
    : faculty(fac), facility(facil) {
    bookingId = bookId;
    date = dat;
    time = tim;
    duration = durat;
    status = "Pending";
    userType = "Faculty";
}

string Booking::getBookerName() {
    if (userType == "Student") {
        return student.getName();
    }
    else {
        return faculty.getName();
    }
}

void Booking::setBookingId(string bookId) { bookingId = bookId; }
void Booking::setDate(string dat) { date = dat; }
void Booking::setTime(int tim) { time = tim; }
void Booking::setDuration(int durat) { duration = durat; }
void Booking::setStatus(string s) { status = s; }

string Booking::getBookingId() const { return bookingId; }
string Booking::getDate() const { return date; }
int Booking::getTime() const { return time; }
int Booking::getDuration() const { return duration; }
string Booking::getStatus() const { return status; }
Student Booking::getStudent() const { return student; }
Facility Booking::getFacility() const { return facility; }
Faculty Booking::getFaculty() const { return faculty; }

double Booking::calculateCost() {
    return duration * facility.getPricePerHour();
}

bool Booking::checkOverlap(string dat, int tim, int dur) {
    if (date == dat) {
        if (tim >= time && tim < (time + duration)) {
            return true;
        }
    }
    return false;
}

void Booking::saveFile() {
    ofstream ofile(bookingFile, ios::app);
    if (ofile.is_open()) {
        ofile << bookingId << endl;
        ofile << date << endl;
        ofile << time << endl;
        ofile << duration << endl;
        ofile << status << endl;
        ofile << userType << endl;

        if (userType == "Student") {
            ofile << student.getName() << endl;
            ofile << student.getStudentId() << endl;
        }
        else {
            ofile << faculty.getName() << endl;
            ofile << faculty.getEmployeeId() << endl;
        }

        ofile << facility.getFacilityId() << endl;
        ofile << facility.getPricePerHour() << endl;
        ofile.close();
    }
}

void Booking::saveToStream(ofstream& ofile) {
    ofile << bookingId << endl;
    ofile << date << endl;
    ofile << time << endl;
    ofile << duration << endl;
    ofile << status << endl;
    ofile << userType << endl;

    if (userType == "Student") {
        ofile << student.getName() << endl;
        ofile << student.getStudentId() << endl;
    }
    else {
        ofile << faculty.getName() << endl;
        ofile << faculty.getEmployeeId() << endl;
    }
    ofile << facility.getFacilityId() << endl;
    ofile << facility.getPricePerHour() << endl;
}

bool Booking::loadFile(ifstream& ifile) {
    string booId, dat, stat, uType, name, id, fID;
    int tim, dur;
    double price;

    if (!getline(ifile, booId)) {
        return false;
    }
    else {
        bookingId = booId;
        getline(ifile, dat);
        date = dat;

        ifile >> tim;
        ifile.ignore();
        time = tim;

        ifile >> dur;
        ifile.ignore();
        duration = dur;

        getline(ifile, stat);
        status = stat;
        getline(ifile, uType);
        userType = uType;

        getline(ifile, name);
        getline(ifile, id);

        if (userType == "Student") {
            student.setName(name);
            student.setStudentId(id);
        }
        else {
            faculty.setName(name);
            faculty.setEmployeeId(id);
        }
        getline(ifile, fID);
        facility.setFacilityId(fID);
        ifile >> price;
        ifile.ignore();
        facility.setPricePerHour(price);

        return true;
    }
}

void Booking::display() {
    cout << "Booking_ID:" << bookingId << endl;
    cout << "Date:" << date << endl;
    cout << "Time:" << time << ":00" << endl;
    cout << "Booked By (" << userType << "): " << getBookerName() << endl;
    cout << "Facility_Id:" << facility.getFacilityId() << endl;
    cout << "Price_Per_Hour:$" << facility.getPricePerHour() << "/hr" << endl;
    cout << "Status:" << status << endl;
    cout << "Est. Cost: $" << calculateCost() << endl;
}

//==========================================
// 7.Invoice Class Definitions
//==========================================
Invoice::Invoice() : invoiceId(" "), baseAmount(0), penaltyFee(0), isPaid(false), booking() {}

Invoice::Invoice(string invoice, Booking b) : booking(b) {
    invoiceId = invoice;
    baseAmount = booking.calculateCost();
    penaltyFee = 0;
    isPaid = false;
}

void Invoice::setInvoiceID(string id) { invoiceId = id; }
void Invoice::setPenaltyFee(double fee) { penaltyFee = fee; }
void Invoice::setIsPaid(bool status) { isPaid = status; }

string Invoice::getInvoiceID() const { return invoiceId; }
double Invoice::getTotalAmount() const { return baseAmount + penaltyFee; }
bool Invoice::getIsPaid() const { return isPaid; }

void Invoice::applyPenalty() {
    penaltyFee = baseAmount * 0.10;
    cout << "Penalty of $" << penaltyFee << " applied to Invoice " << invoiceId << endl;
}

string Invoice::check_Status() {
    if (isPaid == true) {
        return "Paid";
    }
    else {
        return"Unpaid";
    }
}

void Invoice::genrateInvoice() {
    cout << "======================================" << endl;
    cout << "           INVOICE RECEIPT            " << endl;
    cout << "======================================" << endl;
    cout << "Invoice ID:" << invoiceId << endl;
    cout << "booking ID:" << booking.getBookingId() << endl;
    cout << "Student:" << booking.getStudent().getName() << endl;
    cout << "Facility:" << booking.getFacility().getFacilityId() << endl;
    cout << "--------------------------------------" << endl;
    cout << "Base Amount: $" << baseAmount << endl;
    cout << "Penalty Fee: $" << penaltyFee << endl;
    cout << "--------------------------------------" << endl;
    cout << "Total:       $" << getTotalAmount() << endl;
    cout << "Status:" << check_Status() << endl;
    cout << "======================================" << endl;
}

void Invoice::saveFile() {
    ofstream ofile(invoiceFile, ios::app);
    if (ofile.is_open()) {
        ofile << invoiceId << endl;
        ofile << baseAmount << endl;
        ofile << penaltyFee << endl;
        ofile << isPaid << endl;
        ofile << booking.getBookingId() << endl;
        ofile.close();
    }
    else {
        cout << "Error While Opening The File." << endl;
    }
}

bool Invoice::loadFile(ifstream& ifile) {
    string invID, bID;
    double base, pen;
    bool paid;

    if (!getline(ifile, invID)) {
        return false;
    }
    else {
        invoiceId = invID;
        ifile >> base;
        ifile.ignore();
        baseAmount = base;
        ifile >> pen;
        ifile.ignore();
        penaltyFee = pen;
        ifile >> paid;
        ifile.ignore();
        isPaid = paid;
        getline(ifile, bID);
        booking.setBookingId(bID);
        return true;
    }
}

//==========================================
// CampusSystem Class Definitions
//==========================================
CampusSystem::CampusSystem() {
    studentCount = 0;
    facultyCount = 0;
    adminCount = 0;
    facilityCount = 0;
    bookingCount = 0;
    loadAllData();
}

CampusSystem::~CampusSystem() {
    for (int i = 0; i < studentCount; i++) {
        delete student[i];
    }
    for (int i = 0; i < facultyCount; i++) {
        delete faculty[i];
    }
    for (int i = 0; i < adminCount; i++) {
        delete admin[i];
    }
    for (int i = 0; i < facilityCount; i++) {
        delete facility[i];
    }
    for (int i = 0; i < bookingCount; i++) {
        delete booking[i];
    }
}

void CampusSystem::loadAllData() {
    ifstream isfile(studentFile);
    if (isfile.is_open()) {
        while (studentCount < 100) {
            Student* s = new Student();
            if (s->loadFile(isfile)) {
                student[studentCount] = s;
                studentCount++;
            }
            else {
                delete s;
                break;
            }
        }
        isfile.close();
    }

    ifstream iffile(facultyFile);
    if (iffile.is_open()) {
        while (facilityCount < 50) {
            Faculty* f = new Faculty();
            if (f->loadFile(iffile)) {
                faculty[facilityCount] = f;
            }
            else {
                delete f;
                break;
            }
        }
        iffile.close();
    }

    ifstream iafile(adminFile);
    if (iafile.is_open()) {
        while (adminCount < 5) {
            Admin* a = new Admin();
            if (a->loadFile(iafile)) {
                admin[adminCount] = a;
                adminCount++;
            }
            else {
                delete a;
                break;
            }
        }
        iafile.close();
    }

    ifstream ifacilfile(facilityFile);
    if (ifacilfile.is_open()) {
        while (facilityCount < 50) {
            Facility* fac = new Facility();
            if (fac->loadFile(ifacilfile)) {
                facility[facilityCount] = fac;
                facilityCount++;
            }
            else {
                delete fac;
                break;
            }
        }
        ifacilfile.close();
    }

    ifstream ibfile(bookingFile);
    if (ibfile.is_open()) {
        while (bookingCount < 100) {
            Booking* b = new Booking();
            if (b->loadFile(ibfile)) {
                booking[bookingCount] = b;
                bookingCount++;
            }
            else {
                delete b;
                break;
            }
        }
        ibfile.close();
    }
}

void CampusSystem::addStudents(Student* s) {
    if (studentCount < 100) {
        student[studentCount] = s;
        studentCount++;
        s->saveFile();
        cout << "Student" << " " << s->getName() << " " << "Added Successfully." << endl;
    }
    else {
        cout << "Student Limit Reached." << endl;
    }
}

void CampusSystem::addFaculty(Faculty* f) {
    if (facultyCount < 50) {
        faculty[facilityCount] = f;
        facilityCount++;
        f->saveFile();
        cout << "Faculty" << " " << f->getName() << " " << "Added Successfully." << endl;
    }
    else {
        cout << "Faculty Limit Reached." << endl;
    }
}

void CampusSystem::addAdmin(Admin* a) {
    if (adminCount < 5) {
        admin[adminCount] = a;
        adminCount++;
        a->saveFile();
        cout << "Admin" << " " << a->getName() << " " << "Saved Successfully." << endl;
    }
    else {
        cout << "Admin Limit reached." << endl;
    }
}

void CampusSystem::addFacility(Facility* fac) {
    if (facilityCount < 50) {
        facility[facilityCount] = fac;
        facilityCount++;
        fac->saveFile();
        cout << "Facility" << " " << fac->getFacilityId() << " Successfully." << endl;
    }
    else {
        cout << "Facility limit Reached." << endl;
    }
}

void CampusSystem::addBooking(Booking* b) {
    if (bookingCount < 100) {
        booking[bookingCount] = b;
        bookingCount++;
        b->saveFile();
        cout << "Booking Confirmed." << endl;
    }
    else {
        cout << "Booking Limit Reached." << endl;
    }
}

void CampusSystem::viewAllStudents() {
    ifstream ifile(studentFile);
    if (!ifile.is_open()) {
        cout << "Error While Opening the file or Empty File." << endl;
        return;
    }
    Student s;
    int count = 0;
    while (s.loadFile(ifile)) {
        count++;
        cout << "================Students Details=================" << endl;
        s.display();
        cout << "===============================================" << endl;
    }
    if (count == 0) {
        cout << "The File is Empty." << endl;
    }
    ifile.close();
}

void CampusSystem::viewAllFaculty() {
    ifstream ifile(facultyFile);
    if (!ifile.is_open()) {
        cout << "Error While Opening the file or Empty File." << endl;
        return;
    }
    Faculty f;
    int count = 0;
    while (f.loadFile(ifile)) {
        count++;
        cout << "================Faculty Details=================" << endl;
        f.display();
        cout << "===============================================" << endl;
    }
    if (count == 0) {
        cout << "The File is Empty." << endl;
    }
    ifile.close();
}

void CampusSystem::viewAllAdmin() {
    ifstream ifile(adminFile);
    if (!ifile.is_open()) {
        cout << "Error While Opening the file or Empty File." << endl;
        return;
    }
    Admin a;
    int count = 0;
    while (a.loadFile(ifile)) {
        count++;
        cout << "================Admin Details=================" << endl;
        a.display();
        cout << "===============================================" << endl;
    }
    if (count == 0) {
        cout << "The File is Empty." << endl;
    }
    ifile.close();
}

void CampusSystem::viewAllFacility() {
    ifstream ifile(facilityFile);
    if (!ifile.is_open()) {
        cout << "Error While Opening the file or Empty File." << endl;
        return;
    }
    Facility fac;
    int count = 0;
    while (fac.loadFile(ifile)) {
        count++;
        cout << "================Facility Details=================" << endl;
        cout << fac;
        cout << "===============================================" << endl;
    }
    if (count == 0) {
        cout << "The File is Empty." << endl;
    }
    ifile.close();
}

void CampusSystem::viewAllbookings() {
    ifstream ifile(bookingFile);
    if (!ifile.is_open()) {
        cout << "Error While Opening the file or Empty File." << endl;
        return;
    }
    Booking b;
    int count = 0;
    while (b.loadFile(ifile)) {
        count++;
        cout << "================Booking Details=================" << endl;
        b.display();
        cout << "===============================================" << endl;
    }
    if (count == 0) {
        cout << "The File is Empty." << endl;
    }
    ifile.close();
}

void CampusSystem::removefacility() {
    string id;
    cout << "Enter Facility Id :";
    getline(cin, id);

    bool ramfound = false;
    for (int i = 0; i < facilityCount; i++) {
        if (facility[i]->getFacilityId() == id) {
            delete facility[i];

            for (int j = i; j < facilityCount - 1; j++) {
                facility[j] = facility[j + 1];
            }
            facilityCount--;
            ramfound = true;
            cout << "Facility removed from active memory." << endl;
            break;
        }
    }
    if (!ramfound) {
        cout << "Facility Id not found" << endl;
        return;
    }

    ifstream ifile(facilityFile);
    ofstream ofile("temp_facility.txt");
    Facility f;
    bool found = false;
    if (!ifile.is_open()) {
        return;
    }
    while (f.loadFile(ifile)) {
        if (f.getFacilityId() == id) {
            found = true;
            cout << "Facility" << " " << id << " " << "Removed." << endl;
            continue;
        }
        ofile << f.getFacilityId() << endl;
        ofile << f.getType() << endl;
        ofile << f.getCapacity() << endl;
        ofile << f.getPricePerHour() << endl;

    }
    ifile.close();
    ofile.close();
    if (found) {
        remove(facilityFile.c_str());
        rename("temp_facility.txt", facilityFile.c_str());
    }
    else {
        cout << "ID Not Found." << endl;
        remove("temp_facility.txt");
    }
}

void CampusSystem::removeStudent() {
    string id;
    cout << "Enter Student Id:";
    getline(cin, id);

    bool ramfound = false;
    for (int i = 0; i < studentCount; i++) {
        if (student[i]->getStudentId() == id) {
            delete student[i];

            for (int j = i; j < studentCount - 1; j++) {
                student[j] = student[j + 1];
            }
            studentCount--;
            ramfound = true;
            cout << "Student removed from active memory." << endl;
            break;
        }
    }
    if (!ramfound) {
        cout << "Student Id not found" << endl;
        return;
    }

    ifstream ifile(studentFile);
    ofstream ofile("temp_Student.txt");
    if (!ifile.is_open()) {
        return;
    }
    Student s;
    bool found = false;
    while (s.loadFile(ifile)) {
        if (s.getStudentId() == id) {
            found = true;
            cout << "Student " << " " << s.getStudentId() << " " << "Removed Successfully." << endl;
            continue;
        }
        ofile << s.getName() << endl;
        ofile << s.getUserId() << endl;
        ofile << s.getPassword() << endl;
        ofile << s.getEmail() << endl;
        ofile << s.getStudentId() << endl;
        ofile << s.getDegreeProgram() << endl;
    }
    ifile.close();
    ofile.close();
    if (found) {
        remove(studentFile.c_str());
        rename("temp_Student.txt", studentFile.c_str());
    }
    else {
        cout << "Id Not Found." << endl;
        remove("temp_Student.txt");
    }
}

void CampusSystem::removeFaculty() {
    string id;
    cout << "Enter Faculty Id:";
    getline(cin, id);

    bool ramfound = false;
    for (int i = 0; i < facultyCount; i++) {
        if (faculty[i]->getEmployeeId() == id) {
            delete faculty[i];

            for (int j = i; j < facultyCount - 1; j++) {
                faculty[j] = faculty[j + 1];
            }
            facultyCount--;
            ramfound = true;
            cout << "Faculty removed from active memory." << endl;
            break;
        }
    }
    if (!ramfound) {
        cout << "Faculty Id not found" << endl;
        return;
    }

    ifstream ifile(facultyFile);
    ofstream ofile("temp_Faculty.txt");
    if (!ifile.is_open()) {
        return;
    }
    Faculty f;
    bool found = false;
    while (f.loadFile(ifile)) {
        if (f.getEmployeeId() == id) {
            found = true;
            cout << "Faculty " << " " << f.getEmployeeId() << " " << "Removed Successfully." << endl;
            continue;
        }
        ofile << f.getName() << endl;
        ofile << f.getUserId() << endl;
        ofile << f.getPassword() << endl;
        ofile << f.getEmail() << endl;
        ofile << f.getEmployeeId() << endl;
        ofile << f.getDepartment() << endl;
    }
    ifile.close();
    ofile.close();
    if (found) {
        remove(facultyFile.c_str());
        rename("temp_Faculty.txt", facultyFile.c_str());
    }
    else {
        cout << "Id Not Found." << endl;
        remove("temp_Faculty.txt");
    }
}

void CampusSystem::bookNewBooking(string userType, string userName, string userID) {
    string bookID, date, fid;
    int time, duration;

    cout << "Enter Booking ID: ";
    getline(cin, bookID);
    cout << "Enter Date (DD-MM-YYYY): ";
    getline(cin, date);
    cout << "Enter Start Time (e.g. 14): ";
    cin >> time;
    cout << "Enter Duration: ";
    cin >> duration;
    cin.ignore();

    viewAllFacility();
    cout << "Enter Facility ID to Book: ";
    getline(cin, fid);

    Facility foundFac;
    bool facExists = false;

    for (int i = 0; i < facilityCount; i++) {
        if (facility[i]->getFacilityId() == fid) {
            foundFac = *facility[i];
            facExists = true;
            break;
        }
    }

    if (!facExists) {
        cout << "Error: Facility ID not found." << endl;
        return;
    }
    for (int i = 0; i < bookingCount; i++) {
        if (booking[i]->getFacility().getFacilityId() == fid) {
            if (booking[i]->checkOverlap(date, time, duration)) {
                cout << "Error: Time Overlap! Booking rejected." << endl;
                return;
            }
        }
    }
    if (userType == "Student") {
        Student tempStud;
        tempStud.setName(userName);
        tempStud.setStudentId(userID);
        Booking* b = new Booking(bookID, date, time, duration, tempStud, foundFac);
        addBooking(b);
    }
    else if (userType == "Faculty") {
        Faculty tempF;
        tempF.setName(userName);
        tempF.setEmployeeId(userID);
        Booking* b = new Booking(bookID, date, time, duration, tempF, foundFac);
        addBooking(b);
    }
}

void CampusSystem::viewMyBooking(string name) {
    ifstream ifile(bookingFile);
    if (!ifile.is_open()) {
        cout << "No Record Found." << endl;
        return;
    }
    cout << "===============My Bookings================" << endl;
    Booking b;
    bool found = false;
    while (b.loadFile(ifile)) {
        if (b.getBookerName() == name) {
            b.display();
            found = true;
        }
    }
    ifile.close();
    if (!found) {
        cout << "No booking Found For You." << endl;
    }
}

void CampusSystem::cancelMyBooking(string name) {
    string id;
    cout << "Enter Booking ID to Cancel: ";
    getline(cin, id);

    ifstream ifile(bookingFile);
    ofstream ofile("Temp_Book.txt");
    Booking b;
    bool found = false;
    bool idFound = false;

    if (!ifile.is_open()) {
        cout << "Error While opening the File Or Empty File" << endl;
        return;
    }

    while (b.loadFile(ifile)) {
        if (b.getBookingId() == id) {
            idFound = true;

            if (b.getBookerName() == name) {
                b.setStatus("Cancelled");
                found = true;
                cout << "Booking Cancelled." << endl;
            }
            else {
                cout << "Access Denied: Not your booking." << endl;
            }
        }
        b.saveToStream(ofile);
    }
    ifile.close(); ofile.close();

    if (found) {
        remove(bookingFile.c_str());
        rename("Temp_Book.txt", bookingFile.c_str());
    }
    else {
        remove("Temp_Book.txt");
    }
    if (!idFound) {
        cout << "Booking ID Not Found." << endl;
    }
}

void CampusSystem::approveRejectBooking() {
    string id;
    cout << "Enter Booking ID: ";
    getline(cin, id);

    ifstream ifile(bookingFile);
    ofstream ofile("Temp_Book.txt");
    Booking b;
    bool found = false;

    if (!ifile.is_open()) {
        cout << "Error While Opening the File OR Empty File" << endl;
        return;
    }
    while (b.loadFile(ifile)) {
        if (b.getBookingId() == id) {
            found = true;
            cout << "Current Status: " << b.getStatus() << endl;
            cout << "1. Approve" << endl;
            cout << "2. Reject" << endl;
            cout << "Enter choice : ";
            int ch;
            cin >> ch;
            cin.ignore();
            if (ch == 1) {
                b.setStatus("Approved");
            }
            else {
                b.setStatus("Rejected");
            }
            cout << "Status Updated." << endl;
        }
        b.saveToStream(ofile);
    }
    ifile.close();
    ofile.close();

    if (found) {
        remove(bookingFile.c_str());
        rename("Temp_Book.txt", bookingFile.c_str());
    }
    else {
        cout << "Booking ID Not Found." << endl;
        remove("Temp_Book.txt");
    }
}

void CampusSystem::generateReports() {
    ifstream ifile(bookingFile);
    if (!ifile.is_open()) {
        cout << "No records found." << endl;
        return;
    }

    Booking b;
    int count = 0;
    double totalRevenue = 0;

    cout << "\n========= BILL GENERATION =========" << endl;

    while (b.loadFile(ifile)) {
        if (b.getStatus() == "Approved") {
            count++;
            string invID = b.getBookingId();
            Invoice bill(invID, b);
            bill.genrateInvoice();
            totalRevenue = totalRevenue + bill.getTotalAmount();
        }
    }
    ifile.close();

    cout << "\n========= REVENUE SUMMARY =========" << endl;
    cout << "Total Approved Bookings: " << count << endl;
    cout << "Total Revenue:           $" << totalRevenue << endl;
    cout << "===================================" << endl;
}

void CampusSystem::editFacility() {
    string id;
    cout << "Enter Facility Id to Edit: ";
    getline(cin, id);

    ifstream ifile(facilityFile);
    ofstream ofile("Temp_Facility.txt");
    Facility f;
    bool found = false;

    if (!ifile.is_open()) {
        return;
    }

    while (f.loadFile(ifile)) {
        if (f.getFacilityId() == id) {
            found = true;
            cout << "Current Details: " << f << endl;
            string t;
            int c;
            double p;
            cout << "Enter New Type: ";
            getline(cin, t);
            cout << "Enter New Capacity: ";
            cin >> c;
            cout << "Enter New Price/Hr: ";
            cin >> p;
            cin.ignore();

            f.setType(t);
            f.setCapacity(c);
            f.setPricePerHour(p);
            cout << "Details Updated." << endl;
        }
        f.saveToStream(ofile);
    }
    ifile.close();
    ofile.close();

    if (found) {
        remove(facilityFile.c_str());
        rename("Temp_Facility.txt", facilityFile.c_str());
    }
    else {
        cout << "ID Not Found." << endl;
        remove("Temp_Facility.txt");
    }
}

//==========================================
// 9. Authentication Class Definitions
//==========================================
Authentication::Authentication() {
    username = " ";
    password = " ";
    userrole = " ";
}

Authentication::Authentication(string user, string pass, string role) {
    username = user;
    password = pass;
    userrole = role;
}

void Authentication::setUserName(string user) { username = user; }
void Authentication::setPassword(string pass) { password = pass; }
void Authentication::setUserRole(string rol) { userrole = rol; }

string Authentication::getUsername() { return username; }
string Authentication::getPassword() { return password; }
string Authentication::getUserRole() { return userrole; }

void Authentication::registerUser(string user, string pass, string rol) {
    username = user;
    password = pass;
    userrole = rol;
    ofstream ofile(authFile, ios::app);
    if (ofile.is_open()) {
        ofile << username << endl;
        ofile << password << endl;
        ofile << userrole << endl;
        ofile.close();
        cout << "Credentials saved for " << username << " (" << userrole << ")." << endl;
    }
    else {
        cout << "Error: Could not open Auth file." << endl;
    }
}

bool Authentication::verifyRole(string requiredRole) {
    if (userrole == requiredRole) {
        return true;
    }
    else {
        cout << "Access Denied: Requires " << requiredRole << " role." << endl;
        return false;
    }
}

bool Authentication::login(string user, string pass) {
    ifstream ifile(authFile);

    if (!ifile.is_open()) {
        cout << "No user database found!" << endl;
        return false;
    }

    string fUser, fPass, fRole;
    bool found = false;

    while (getline(ifile, fUser)) {
        getline(ifile, fPass);
        getline(ifile, fRole);

        if (user == fUser && pass == fPass) {
            username = fUser;
            password = fPass;
            userrole = fRole;
            found = true;
            break;
        }
    }
    ifile.close();

    if (found) {
        cout << "Login Successful! Welcome " << username << "." << endl;
        return true;
    }
    else {
        cout << "Error: Invalid Username or Password." << endl;
        return false;
    }
}

void Authentication::logout() {
    cout << "User " << username << " logged out successfully." << endl;
    username = "";
    password = "";
    userrole = "";
}

//==========================================
// Standalone Functions
//==========================================

void AdminMenu(Authentication& auth, CampusSystem& system) {
    int choice;
    do {
        ::system("cls");

        cout << "==" << "================Admin Menu=====================" << endl;
        cout << "||" << "\t 1. Add New Facility                   ||" << endl;
        cout << "||" << "\t 2. Edit Facility                      ||" << endl;
        cout << "||" << "\t 3. Remove Facility                    ||" << endl;
        cout << "||" << "\t 4. View Booking Requests              ||" << endl;
        cout << "||" << "\t 5. Approve/Reject Booking             ||" << endl;
        cout << "||" << "\t 6. Genrate Reports                    ||" << endl;
        cout << "||" << "\t 7. Add Student/Faculty (Registration) ||" << endl;
        cout << "||" << "\t 8. Remove Student/Facult              ||" << endl;
        cout << "||" << "\t 9. Logout                             ||" << endl;
        cout << "==" << "===============================================" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            cout << "========= Add New Facility =========" << endl;
            string id, type;
            int cap;
            double price;
            cout << "Enter ID: ";
            getline(cin, id);
            cout << "Enter Type: ";
            getline(cin, type);
            cout << "Enter Capacity: ";
            cin >> cap;
            cout << "Enter Price/Hr: ";
            cin >> price;

            Facility* f = new Facility(id, type, cap, price);
            system.addFacility(f);

            ::system("pause");
            break;
        }
        case 2: {
            system.editFacility();
            ::system("pause");
            break;
        }
        case 3: {
            system.removefacility();
            ::system("pause");
            break;
        }
        case 4: {
            system.viewAllbookings();
            ::system("pause");
            break;
        }
        case 5: {
            system.approveRejectBooking();
            ::system("pause");
            break;
        }
        case 6: {
            system.generateReports();
            ::system("pause");
            break;
        }
        case 7: {
            cout << "1. Add Student" << endl;
            cout << "2. Add Faculty" << endl;
            cout << "Enter Your Choice : ";
            int c;
            cin >> c;
            cin.ignore();
            if (c == 1) {
                cout << "========= Add New Student =========" << endl;
                string name, user, pass, email, stdId, degrProgr;
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Username: ";
                getline(cin, user);
                cout << "Enter Password: ";
                getline(cin, pass);
                cout << "Enter Email: ";
                getline(cin, email);
                cout << "Enter Student ID: ";
                getline(cin, stdId);
                cout << "Enter Degree: ";
                getline(cin, degrProgr);

                Student* s = new Student(name, user, pass, email, stdId, degrProgr);
                system.addStudents(s);
                auth.registerUser(user, pass, "Student");
            }
            else if (c == 2) {
                cout << "========= Add New Faculty =========" << endl;
                string nam, user, pass, email, empId, dept;
                cout << "Enter Name: ";
                getline(cin, nam);
                cout << "Enter Username: ";
                getline(cin, user);
                cout << "Enter Password: ";
                getline(cin, pass);
                cout << "Enter Email: ";
                getline(cin, email);
                cout << "Enter Faculty ID: ";
                getline(cin, empId);
                cout << "Enter Department: ";
                getline(cin, dept);
                Faculty* f = new Faculty(nam, user, pass, email, empId, dept);
                system.addFaculty(f);
                auth.registerUser(user, pass, "Faculty");
            }
            ::system("pause");
            break;
        }
        case 8: {
            cout << "1. Remove Student" << endl;
            cout << "2. Remove Faculty" << endl;
            cout << "Enter Your Choice : ";
            int c;
            cin >> c;
            cin.ignore();
            if (c == 1) {
                system.removeStudent();
            }
            else if (c == 2) {
                system.removeFaculty();
            }
            ::system("pause");
            break;
        }
        case 9: {
            cout << "Logging Out..." << endl;
            auth.logout();
            return;
        }
        default: {
            cout << "Invalid Choice!" << endl;
            ::system("pause");
        }
        }
    } while (choice != 9);
}

void FacultyMenu(Authentication& auth, CampusSystem& system) {
    string uName = auth.getUsername();

    int choice;
    do {
        ::system("cls");
        cout << "==" << "================Faculty Menu=====================" << endl;
        cout << "||" << "\t 1. View Facilites                     ||" << endl;
        cout << "||" << "\t 2. Request Booking                    ||" << endl;
        cout << "||" << "\t 3. View My Booking                    ||" << endl;
        cout << "||" << "\t 4. Cancel Booking                     ||" << endl;
        cout << "||" << "\t 5. Logout                             ||" << endl;
        cout << "==" << "=================================================" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            system.viewAllFacility();
            ::system("pause");
            break;
        }
        case 2: {
            system.bookNewBooking("Faculty", uName, "FAC-ID");
            ::system("pause");
            break;
        }
        case 3: {
            system.viewMyBooking(uName);
            ::system("pause");
            break;
        }
        case 4: {
            system.cancelMyBooking(uName);
            ::system("pause");
            break;
        }
        case 5: {
            auth.logout();
            return;
        }
        default: {
            cout << "Invalid Choice!" << endl;
            ::system("pause");
        }
        }
    } while (choice != 5);
}

void StudentMenu(Authentication& auth, CampusSystem& system) {
    string uName = auth.getUsername();

    int choice;
    do {
        ::system("cls");
        cout << "==" << "================Student Menu=====================" << endl;
        cout << "||" << "\t 1. View Facilites                     ||" << endl;
        cout << "||" << "\t 2. Request Booking                    ||" << endl;
        cout << "||" << "\t 3. View My Booking                    ||" << endl;
        cout << "||" << "\t 4. Cancel Booking                     ||" << endl;
        cout << "||" << "\t 5. Logout                             ||" << endl;
        cout << "==" << "=================================================" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            system.viewAllFacility();
            ::system("pause");
            break;
        }
        case 2: {
            system.bookNewBooking("Student", uName, "STD-ID");
            ::system("pause");
            break;
        }
        case 3: {
            system.viewMyBooking(uName);
            ::system("pause");
            break;
        }
        case 4: {
            system.cancelMyBooking(uName);
            ::system("pause");
            break;
        }
        case 5: {
            auth.logout();
            return;
        }
        default: {
            cout << "Invalid Choice!" << endl;
            ::system("pause");
        }
        }
    } while (choice != 5);
}

void all() {
    CampusSystem system;
    Authentication auth;
    int choice;

    ifstream ifile(authFile);
    if (!ifile.is_open()) {
        auth.registerUser("admin", "admin123", "Admin");
    }
    ifile.close();

    cout << "==" << "=============================================" << endl;
    cout << "||" << "            SYSTEM CREDENTIALS             ||" << endl;
    cout << "||" << "===========================================||" << endl;
    cout << "||" << "       Role ||   UserName|| Password       ||" << endl;
    cout << "||" << "===========================================||" << endl;
    cout << "||" << "      Admin ||    admin  || admin123       ||" << endl;
    cout << "==" << "=============================================" << endl;
    ::system("pause");

    do {
        ::system("cls");
        cout << "==" << "=============Campus Facility System============" << endl;
        cout << "||" << "\t 1. Admin Login                        ||" << endl;
        cout << "||" << "\t 2. Faculty Login                      ||" << endl;
        cout << "||" << "\t 3. Student Login                      ||" << endl;
        cout << "||" << "\t 4. Exit                               ||" << endl;
        cout << "==" << "===============================================" << endl;
        cout << "Enter Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string u, p;
            cout << "========= Admin Login =========" << endl;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;
            if (auth.login(u, p) && auth.verifyRole("Admin")) {
                ::system("pause");
                AdminMenu(auth, system);
            }
            ::system("pause");
            break;
        }
        case 2: {
            string u, p;
            cout << "========= Faculty Login =========" << endl;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;
            if (auth.login(u, p) && auth.verifyRole("Faculty")) {
                ::system("pause");
                FacultyMenu(auth, system);
            }
            ::system("pause");
            break;
        }
        case 3: {
            string u, p;
            cout << "========= Student Login =========" << endl;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;
            if (auth.login(u, p) && auth.verifyRole("Student")) {
                ::system("pause");
                StudentMenu(auth, system);
            }
            ::system("pause");
            break;
        }
        case 4: {
            cout << "GOOD BYE!" << endl;
            return;
        }
        default: {
            cout << "Invalid Choice!" << endl;
            ::system("pause");
        }
        }
    } while (choice != 4);
}