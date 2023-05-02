#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <cstring>

using namespace std;

class Admin {
public:

    // Default constructor
    Admin() : username(""), password("") {}
    // Constructor
    Admin(const string &username, const string &password) : username(username), password(password) {}

    // Getters
    string getUsername() const { return username; }
    string getPassword() const { return password; }

    // Setters
    void setUsername(const string &newUsername) { username = newUsername; }
    void setPassword(const string &newPassword) { password = newPassword; }

    // Overloaded stream operators
    friend ostream& operator<<(ostream &out, const Admin &admin);
    friend istream& operator>>(istream &in, Admin &admin);

private:
    string username;
    string password;
};

ostream& operator<<(ostream &out, const Admin &admin) {
    out << admin.username << " " << admin.password;
    return out;
}

istream& operator>>(istream &in, Admin &admin) {
    in >> admin.username >> admin.password;
    return in;
}


class Passenger {
public:
    // Default constructor
    Passenger() : name(""), cnic(""), passport(""), username(""), password(""), age(0), isForeign(false) {}

    // Constructor
    Passenger(const string &name, const string &cnic, int age, const string &passport, bool isForeign, const string &username, const string &password)
        : name(name), cnic(cnic), age(age), passport(passport), isForeign(isForeign), username(username), password(password) {}

    // Getters
    string getName() const { return name; }
    string getCnic() const { return cnic; }
    string getPassport() const { return passport; }
    string getUsername() const { return username; }
    string getPassword() const { return password; }

    int getAge() const { return age; }
    bool getIsForeign() const { return isForeign; }

    // Setters
    void setName(const string &newName) { name = newName; }
    void setCnic(const string &newCnic) { cnic = newCnic; }
    void setPassport(const string &newPassport) { passport = newPassport; }
    void setUsername(const string &newUsername) { username = newUsername; }
    void setPassword(const string &newPassword) { password = newPassword; }

    void setAge(int newAge) { age = newAge; }
    void setIsForeign(bool newIsForeign) { isForeign = newIsForeign; }

    // Overloaded stream operators
    friend ostream& operator<<(ostream &out, const Passenger &passenger);
    friend istream& operator>>(istream &in, Passenger &passenger);

private:
    string name;
    string cnic;
    int age;
    string passport;
    bool isForeign;
    string username;
    string password;
};

ostream& operator<<(ostream &out, const Passenger &passenger) {
    out << passenger.name << " " << passenger.cnic << " " << passenger.passport << " " << passenger.username << " " << passenger.password;
    return out;
}

istream& operator>>(istream &in, Passenger &passenger) {
    in >> passenger.name >> passenger.cnic >> passenger.passport >> passenger.username >> passenger.password;
    return in;
}


class Flight {
public:
    // Default constructor
    Flight() : flightNumber(""), origin(""), destination(""), departureTime(""), arrivalTime(""), economySeats(0), businessSeats(0) {}
    // Constructor
    Flight(const string &flightNumber, const string &origin, const string &destination, const string &departureTime, const string &arrivalTime, int economySeats, int businessSeats)
        : flightNumber(flightNumber), origin(origin), destination(destination), departureTime(departureTime), arrivalTime(arrivalTime), economySeats(economySeats), businessSeats(businessSeats) {}

    // Getters
    string getFlightNumber() const { return flightNumber; }
    string getOrigin() const { return origin; }
    string getDestination() const { return destination; }
    string getDepartureTime() const { return departureTime; }
    string getArrivalTime() const { return arrivalTime; }
    int getEconomySeats() const { return economySeats; }
    int getBusinessSeats() const { return businessSeats; }

    // Setters
    void setFlightNumber(const string &newFlightNumber) { flightNumber = newFlightNumber; }
    void setOrigin(const string &newOrigin) { origin = newOrigin; }
    void setDestination(const string &newDestination) { destination = newDestination; }
    void setDepartureTime(const string &newDepartureTime) { departureTime = newDepartureTime; }
    void setArrivalTime(const string &newArrivalTime) { arrivalTime = newArrivalTime; }
    void setEconomySeats(int newEconomySeats) { economySeats = newEconomySeats; }
    void setBusinessSeats(int newBusinessSeats) { businessSeats = newBusinessSeats; }

    // Overloaded stream operators
    friend ostream& operator<<(ostream &out, const Flight &flight);
    friend istream& operator>>(istream &in, Flight &flight);

private:
    string flightNumber;
    string origin;
    string destination;
    string departureTime;
    string arrivalTime;
    int economySeats;
    int businessSeats;
};

ostream& operator<<(ostream &out, const Flight &flight) {
    out << flight.flightNumber << " " << flight.origin << " " << flight.destination << " " << flight.departureTime << " " << flight.arrivalTime << " " << flight.economySeats << " " << flight.businessSeats;
    return out;
}

istream& operator>>(istream &in, Flight &flight) {
    in >> flight.flightNumber >> flight.origin >> flight.destination >> flight.departureTime >> flight.arrivalTime >> flight.economySeats >> flight.businessSeats;
    return in;
}


class Airport {
public:
    // Default constructor
    Airport() : name(""), city(""), location("") {}
    // Constructor
    Airport(const string &name, const string &city, const string &location) : name(name), city(city), location(location) {}

    // Getters
    string getName() const { return name; }
    string getCity() const { return city; }
    string getLocation() const { return location; }

    // Setters
    void setName(const string &newName) { name = newName; }
    void setCity(const string &newCity) { city = newCity; }
    void setLocation(const string &newLocation) { location = newLocation; }

    // Overloaded stream operators
    friend ostream& operator<<(ostream &out, const Airport &airport);
    friend istream& operator>>(istream &in, Airport &airport);

private:
    string name;
    string city;
    string location;
};

ostream& operator<<(ostream &out, const Airport &airport) {
    out << airport.name << " " << airport.city << " " << airport.location;
    return out;
}

istream& operator>>(istream &in, Airport &airport) {
    in >> airport.name >> airport.city >> airport.location;
    return in;
}

void loadAdminData(Admin admins[], int &adminCount, const string &filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (inFile >> admins[adminCount]) {
        adminCount++;
    }

    inFile.close();
}

void loadPassengerData(Passenger passengers[], int &passengerCount, const string &filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (inFile >> passengers[passengerCount]) {
        passengerCount++;
    }

    inFile.close();
}

void loadFlightData(Flight flights[], int &flightCount, const string &filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (inFile >> flights[flightCount]) {
        flightCount++;
    }

    inFile.close();
}

void loadAirportData(Airport airports[], int &airportCount, const string &filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (inFile >> airports[airportCount]) {
        airportCount++;
    }

    inFile.close();
}

void saveAdminData(Admin admins[], int adminCount, const string &filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < adminCount; i++) {
        outFile << admins[i] << endl;
    }

    outFile.close();
}

void savePassengerData(Passenger passengers[], int passengerCount, const string &filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < passengerCount; i++) {
        outFile << passengers[i] << endl;
    }

    outFile.close();
}

void saveFlightData(Flight flights[], int flightCount, const string &filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < flightCount; i++) {
        outFile << flights[i] << endl;
    }

    outFile.close();
}

void saveAirportData(Airport airports[], int airportCount, const string &filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < airportCount; i++) {
        outFile << airports[i] << endl;
    }

    outFile.close();
}




int adminLogin(const Admin admins[], int adminCount) {
    string username, password;

    cout << "Admin Login" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < adminCount; ++i) {
        if (admins[i].getUsername() == username && admins[i].getPassword() == password) {
            return i;
        }
    }
    return -1;
}

void adminMenu(Admin &admin, Flight flights[], int &flightCount, Airport airports[], int &airportCount) {
    int option;

    while (true) {
        cout << "Admin Menu" << endl;
        cout << "1. Change flight schedule" << endl;
        cout << "2. Add new flight route" << endl;
        cout << "3. Update airline inquiry details" << endl;
        cout << "4. Logout" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                // Change flight schedule
                break;
            case 2:
                // Add new flight route
                break;
            case 3:
                // Update airline inquiry details
                break;
            case 4:
                cout << "Logged out successfully." << endl;
                return;
            default:
                cerr << "Invalid option. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(10));
                break;
        }
    }
}


int passengerLogin(const Passenger passengers[], int passengerCount) {
    string username, password;

    cout << "Passenger Login" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < passengerCount; ++i) {
        if (passengers[i].getUsername() == username && passengers[i].getPassword() == password) {
            return i;
        }
    }
    return -1;
}

void passengerMenu(Passenger &passenger, Flight flights[], int &flightCount, Airport airports[], int &airportCount) {
    int option;

    while (true) {
        cout << "Passenger Menu" << endl;
        cout << "1. View flight schedule" << endl;
        cout << "2. Book a flight" << endl;
        cout << "3. Update personal details" << endl;
        cout << "4. Logout" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                // View flight schedule
                break;
            case 2:
                // Book a flight
                break;
            case 3:
                // Update personal details
                break;
            case 4:
                cout << "Logged out successfully." << endl;
                return;
            default:
                cerr << "Invalid option. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(10));
                break;
        }
    }
}


int registerPassenger(Passenger passengers[], int &passengerCount) {
    string username, password, confirmPassword, cnic, name, passportNumber;
    int age;
    bool isForeign;

    cout << "Passenger Registration" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "CNIC: ";
    cin >> cnic;
    cout << "Age: ";
    cin >> age;
    cout << "Passport Number: ";
    cin >> passportNumber;
    cout << "Is the passport foreign (0 for No, 1 for Yes): ";
    cin >> isForeign;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cerr << "Passwords do not match. Please try again." << endl;
        this_thread::sleep_for(chrono::seconds(10));
        return -1;
    }

    for (int i = 0; i < passengerCount; ++i) {
        if (passengers[i].getCnic() == cnic) {
            cerr << "CNIC already exists. Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(10));
            return -1;
        }
    }

    // Verify financial details with VerifyFinancialDetail()
    // ...

    passengers[passengerCount++] = Passenger(name, cnic, age, passportNumber, isForeign, username, password);
    return passengerCount - 1;
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
    loadAdminData(admins, adminCount, "admins.txt");
    loadPassengerData(passengers, passengerCount, "passengers.txt");
    loadFlightData(flights, flightCount, "flights.txt");
    loadAirportData(airports, airportCount, "airports.txt");


   

    // Main menu loop
    while (true) {
         // Add this before the return statement in your main() function
        std::cout << "Press any key to exit..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
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
                int adminIndex = adminLogin(admins, adminCount);
                if (adminIndex != -1) {
                    adminMenu(admins[adminIndex], flights, flightCount, airports, airportCount);
                }
                break;
            }
            case 2: {
                int passengerIndex = passengerLogin(passengers, passengerCount);
                if (passengerIndex != -1) {
                    passengerMenu(passengers[passengerIndex], flights, flightCount, airports, airportCount);
                }
                break;
            }
            case 3:
                registerPassenger(passengers, passengerCount);
                break;
            case 4:
                // Save data to files.
                saveAdminData(admins, adminCount, "admins.txt");
                savePassengerData(passengers, passengerCount, "passengers.txt");
                saveFlightData(flights, flightCount, "flights.txt");
                saveAirportData(airports, airportCount, "airports.txt");
                cout << "Thank you for using NUCES Airline Flight System (NAFS)!" << endl;
                return 0;
            default:
                cerr << "Invalid option. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(10));
                break;
        }
    }
}