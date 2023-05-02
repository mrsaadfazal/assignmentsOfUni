#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <chrono>
#include <thread>


using namespace std;

class Admin {
private:
    string username;
    string password;
public:
    Admin() : username(""), password("") {}
    Admin(const string& username, const string& password) : username(username), password(password) {}
    Admin(const Admin& other) : username(other.username), password(other.password) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    void setUsername(const string& username) { this->username = username; }
    void setPassword(const string& password) { this->password = password; }
};

class Passenger {
private:
    string username;
    string password;
    string name;
    string cnic;
    string passport;

public:
    Passenger() : username(""), password(""), name(""), cnic(""), passport("") {}
    Passenger(const string& username, const string& password, const string& name, const string& cnic, const string& passport) :
        username(username), password(password), name(name), cnic(cnic), passport(passport) {}
    Passenger(const Passenger& other) :
        username(other.username), password(other.password), name(other.name), cnic(other.cnic), passport(other.passport) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getName() const { return name; }
    string getCnic() const { return cnic; }
    string getPassport() const { return passport; }
    void setUsername(const string& username) { this->username = username; }
    void setPassword(const string& password) { this->password = password; }
    void setName(const string& name) { this->name = name; }
    void setCnic(const string& cnic) { this->cnic = cnic; }
    void setPassport(const string& passport) { this->passport = passport; }
};


class Flight {
private:
    int flightNumber;
    string origin;
    string destination;
    time_t departureTime;
    time_t arrivalTime;
    int availableSeats;

public:
    Flight() : flightNumber(0), origin(""), destination(""), departureTime(0), arrivalTime(0), availableSeats(0) {}
    Flight(int flightNumber, const string& origin, const string& destination, time_t departureTime, time_t arrivalTime, int availableSeats) :
        flightNumber(flightNumber), origin(origin), destination(destination), departureTime(departureTime), arrivalTime(arrivalTime), availableSeats(availableSeats) {}
    Flight(const Flight& other) :
        flightNumber(other.flightNumber), origin(other.origin), destination(other.destination), departureTime(other.departureTime), arrivalTime(other.arrivalTime), availableSeats(other.availableSeats) {}

    int getFlightNumber() const { return flightNumber; }
    string getOrigin() const { return origin; }
    string getDestination() const { return destination; }
    time_t getDepartureTime() const { return departureTime; }
    time_t getArrivalTime() const { return arrivalTime; }
    int getAvailableSeats() const { return availableSeats; }
    void setFlightNumber(int flightNumber) { this->flightNumber = flightNumber; }
    void setOrigin(const string& origin) { this->origin = origin; }
    void setDestination(const string& destination) { this->destination = destination; }
    void setDepartureTime(time_t departureTime) { this->departureTime = departureTime; }
    void setArrivalTime(time_t arrivalTime) { this->arrivalTime = arrivalTime; }
    void setAvailableSeats(int availableSeats) { this->availableSeats = availableSeats; }
};

class Booking {
private:
    string bookingId;
    Passenger passenger;
    Flight flight;
    string seatType;
    double cost;

public:
    Booking() {}

    Booking(const string &bookingId, const Passenger &passenger, const Flight &flight, const string &seatType, double cost)
        : bookingId(bookingId), passenger(passenger), flight(flight), seatType(seatType), cost(cost) {}

    Booking(const Booking &other)
        : bookingId(other.bookingId), passenger(other.passenger), flight(other.flight), seatType(other.seatType), cost(other.cost) {}

    string getBookingId() const {
        return bookingId;
    }

    void setBookingId(const string &bookingId) {
        this->bookingId = bookingId;
    }

    Passenger getPassenger() const {
        return passenger;
    }

    void setPassenger(const Passenger &passenger) {
        this->passenger = passenger;
    }

    Flight getFlight() const {
        return flight;
    }

    void setFlight(const Flight &flight) {
        this->flight = flight;
    }

    string getSeatType() const {
        return seatType;
    }

    void setSeatType(const string &seatType) {
        this->seatType = seatType;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        this->cost = cost;
    }
};


class Airport {
private:
    string name;
    string location;
    string city;

public:
    Airport() : name(""), location(""), city("") {}
    Airport(const string& name, const string& location, const string& city) : name(name), location(location), city(city) {}
    Airport(const Airport& other) : name(other.name), location(other.location), city(other.city) {}

    string getName() const { return name; }
    string getLocation() const { return location; }
    string getCity() const { return city; }
    void setName(const string& name) { this->name = name; }
    void setLocation(const string& location) { this->location = location; }
    void setCity(const string& city) { this->city = city; }
};


// Utility function to display the main menu
void displayMainMenu() {
    cout << "Welcome to NUCES Airline Flight System (NAFS)" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Search Flight Schedule" << endl;
    cout << "4. Exit" << endl;
    cout << "Please enter your choice: ";
}


// Utility function to validate user input and handle errors
int getUserInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cout << "Invalid input. Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return input;
}



void loadAdminData(Admin admins[], int &adminCount, const string &filename) {
    ifstream inFile(filename);
    
    if (!inFile) {
        cerr << "Unable to open admin data file." << endl;
        return;
    }
    
    while (!inFile.eof()) {
        string username, password, email, name;
        inFile >> username >> password >> email >> name;

        if (!inFile.fail()) {
            Admin admin(username, password, email, name);
            admins[adminCount++] = admin;
        }
    }
    
    inFile.close();
}


void loadPassengerData(Passenger passengers[], int &passengerCount) {
    ifstream inFile("passengers.txt");
    if (inFile.is_open()) {
        while (inFile >> passengers[passengerCount]) {
            passengerCount++;
        }
        inFile.close();
    }
}

void loadFlightData(Flight flights[], int &flightCount) {
    ifstream inFile("flights.txt");
    if (inFile.is_open()) {
        while (inFile >> flights[flightCount]) {
            flightCount++;
        }
        inFile.close();
    }
}

void loadAirportData(Airport airports[], int &airportCount) {
    ifstream inFile("airports.txt");
    if (inFile.is_open()) {
        while (inFile >> airports[airportCount]) {
            airportCount++;
        }
        inFile.close();
    }
}

void saveAdminData(Admin admins[], int adminCount) {
    ofstream outFile("admins.txt");
    for (int i = 0; i < adminCount; i++) {
        outFile << admins[i] << endl;
    }
    outFile.close();
}

void savePassengerData(Passenger passengers[], int passengerCount) {
    ofstream outFile("passengers.txt");
    for (int i = 0; i < passengerCount; i++) {
        outFile << passengers[i] << endl;
    }
    outFile.close();
}

void saveFlightData(Flight flights[], int flightCount) {
    ofstream outFile("flights.txt");
    for (int i = 0; i < flightCount; i++) {
        outFile << flights[i] << endl;
    }
    outFile.close();
}

void saveAirportData(Airport airports[], int airportCount) {
    ofstream outFile("airports.txt");
    for (int i = 0; i < airportCount; i++) {
        outFile << airports[i] << endl;
    }
    outFile.close();
}

int adminLogin(Admin admins[], int adminCount) {
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    for (int i = 0; i < adminCount; i++) {
        if (admins[i].getUsername() == username && admins[i].getPassword() == password) {
            return i;
        }
    }

    cerr << "Invalid username or password." << endl;
    this_thread::sleep_for(chrono::seconds(10));
    return -1;
}

void adminMenu(Admin &admin, Passenger passengers[], int &passengerCount, Flight flights[], int &flightCount, Airport airports[], int &airportCount) {
    // Implement the Admin menu options, such as managing flights, airports, etc.
}

int passengerLogin(Passenger passengers[], int passengerCount) {
    string username, password;
    cout << "Enter passenger username: ";
    cin >> username;
    cout << "Enter passenger password: ";
    cin >> password;

    for (int i = 0; i < passengerCount; i++) {
        if (passengers[i].getUsername() == username && passengers[i].getPassword() == password) {
            return i;
        }
    }

    cerr << "Invalid username or password." << endl;
this_thread::sleep_for(chrono::seconds(10));
return -1;
}

void passengerMenu(Passenger &passenger, Flight flights[], int flightCount, Airport airports[], int airportCount) {
// Implement the Passenger menu options, such as booking flights, viewing flight schedules, etc.
}

void registerPassenger(Passenger passengers[], int &passengerCount) {
// You may need to modify this function depending on the constructor and member variables of the Passenger class.
string name, username, password, email;
cout << "Enter your name: ";
cin >> name;
cout << "Enter your desired username: ";
cin >> username;
cout << "Enter your desired password: ";
cin >> password;
cout << "Enter your email address: ";
cin >> email;


Passenger newPassenger(name, username, password, email);
passengers[passengerCount++] = newPassenger;

cout << "Registration successful! You can now log in as a passenger." << endl;
}



int main() {
    // Initialize arrays to store Admins, Passengers, Flights, and Airports.
    // You can adjust the array size based on the desired maximum capacity.
    Admin admins[100];
    Passenger passengers[50000];
    Flight flights[1000];
    Airport airports[10];
    
    // Initialize necessary variables and indexes for arrays.
    int adminCount = 0;
    int passengerCount = 0;
    int flightCount = 0;
    int airportCount = 0;
    
    // Load data from files.
    loadAdminData(admins, adminCount);
    loadPassengerData(passengers, passengerCount);
    loadFlightData(flights, flightCount);
    loadAirportData(airports, airportCount);
    
    // Main menu loop
    while (true) {
        int option;
        cout << "Welcome to NUCES Airline Flight System (NAFS)\n";
        cout << "1. Admin Login\n";
        cout << "2. Passenger Login\n";
        cout << "3. Register as Passenger\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1: {
                // Admin Login
                int adminIndex = adminLogin(admins, adminCount);
                if (adminIndex != -1) {
                    adminMenu(admins[adminIndex], passengers, passengerCount, flights, flightCount, airports, airportCount);
                }
                break;
            }
            case 2: {
                // Passenger Login
                int passengerIndex = passengerLogin(passengers, passengerCount);
                if (passengerIndex != -1) {
                    passengerMenu(passengers[passengerIndex], flights, flightCount, airports, airportCount);
                }
                break;
            }
            case 3:
                // Register as Passenger
                registerPassenger(passengers, passengerCount);
                break;
            case 4:
                // Save data to files.
                saveAdminData(admins, adminCount);
                savePassengerData(passengers, passengerCount);
                saveFlightData(flights, flightCount);
                saveAirportData(airports, airportCount);
                cout << "Thank you for using NUCES Airline Flight System (NAFS)!" << endl;
                return 0;
            default:
                cerr << "Invalid option. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(10));
                break;
        }
    }

    return 0;
}
