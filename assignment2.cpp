#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <cstring>
#include <conio.h>

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

    string getFlightDetails() const {
        return flightNumber + " | " + origin + " | " + destination + " | " + departureTime + " | " + arrivalTime + " | " + to_string(economySeats) + " | " + to_string(businessSeats);
    }
    

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
    string getAirportCode() const { return location; } // Assuming location is the airport code
    // getAirportDetails()is down below
    string getAirportDetails() const {
        return name + " | " + city + " | " + location;
    }

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
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open " << filename << " for reading." << endl;
        return;
    }

    while (inputFile >> admins[adminCount]) {
        adminCount++;
    }

    inputFile.close();
}

void loadPassengerData(Passenger passengers[], int &passengerCount, const string &filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open " << filename << " for reading." << endl;
        return;
    }

    while (inputFile >> passengers[passengerCount]) {
        passengerCount++;
    }

    inputFile.close();
}

void loadFlightData(Flight flights[], int &flightCount, const string &filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open " << filename << " for reading." << endl;
        return;
    }

    while (inputFile >> flights[flightCount]) {
        flightCount++;
    }

    inputFile.close();
}

void loadAirportData(Airport airports[], int &airportCount, const string &filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open " << filename << " for reading." << endl;
        return;
    }

    while (inputFile >> airports[airportCount]) {
        airportCount++;
    }

    inputFile.close();
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


//...............................................................................................
//........AAAAAAAA..................dddddd.............................iiiiii....................
//........AAAAAAAA..................dddddd.............................iiiiii....................
//.......AAAAAAAAA..................dddddd.............................iiiiii....................
//.......AAAAAAAAAA.................dddddd.......................................................
//.......AAAAAAAAAA.................dddddd.......................................................
//......AAAAAAAAAAA.................dddddd.......................................................
//......AAAAAAAAAAAA........dddddddddddddd..mmmmmmmmmmmmm..mmmmmmmm....iiiiii..nnnnnnnnnnnnnn....
//.....AAAAAA.AAAAAA.......ddddddddddddddd..mmmmmmmmmmmmmmmmmmmmmmmm...iiiiii..nnnnnnnnnnnnnnn...
//.....AAAAAA.AAAAAA......dddddddddddddddd..mmmmmmmmmmmmmmmmmmmmmmmm...iiiiii..nnnnnnnnnnnnnnnn..
//.....AAAAAA..AAAAAA.....ddddddd.dddddddd..mmmmmmmmmmmmmmmmmmmmmmmm...iiiiii..nnnnnnnn.nnnnnnn..
//....AAAAAA...AAAAAA....ddddddd...ddddddd..mmmmmm...mmmmmmm..mmmmmm...iiiiii..nnnnnnn...nnnnnn..
//....AAAAAA...AAAAAAA...dddddd.....dddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//....AAAAAA....AAAAAA...dddddd.....dddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//...AAAAAAAAAAAAAAAAA...dddddd.....dddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//...AAAAAAAAAAAAAAAAAA..dddddd.....dddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//...AAAAAAAAAAAAAAAAAA..dddddd.....dddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//..AAAAAAAAAAAAAAAAAAA..dddddd.....dddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//..AAAAAA.......AAAAAAA.ddddddd...ddddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//.AAAAAA.........AAAAAA..ddddddd.dddddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//.AAAAAA.........AAAAAA..dddddddddddddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//.AAAAAA.........AAAAAAA..ddddddddddddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//.AAAAA...........AAAAAA...dddddddddddddd..mmmmmm...mmmmmm....mmmmm...iiiiii..nnnnnn....nnnnnn..
//...............................................................................................

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

// Function declarations
void changeFlightSchedule(Flight flights[], int flightCount);
void addNewFlightRoute(Flight flights[], int &flightCount, Airport airports[], int airportCount);
void updateAirlineInquiryDetails(Flight flights[], int flightCount, Airport airports[], int airportCount);
void updateFlightDetails(Flight flights[], int flightCount);
void updateAirportDetails(Airport airports[], int airportCount);

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
            changeFlightSchedule(flights, flightCount);
            break;
        case 2:
            // Add new flight route
            addNewFlightRoute(flights, flightCount, airports, airportCount);
            break;
        case 3:
            // Update airline inquiry details
            updateAirlineInquiryDetails(flights, flightCount, airports, airportCount);
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

void changeFlightSchedule(Flight flights[], int flightCount) {
    string flightNumber;
    cout << "Enter the flight number you want to change the schedule for: ";
    cin >> flightNumber;

    for (int i = 0; i < flightCount; ++i) {
        if (flights[i].getFlightNumber() == flightNumber) {
            string newDepartureTime;
            cout << "Enter the new departure time: ";
            cin >> newDepartureTime;
            flights[i].setDepartureTime(newDepartureTime);
            cout << "Flight schedule updated successfully." << endl;
            return;
        }
    }

    cerr << "Flight not found. Please try again." << endl;
}

void displayFlights(const Flight flights[], int flightCount) {
    cout << "Flight details:" << endl;
    for (int i = 0; i < flightCount; ++i) {
        // Assuming you have a method to display flight details in your Flight class
        cout << flights[i].getFlightDetails() << endl;
    }
}

void displayAirports(const Airport airports[], int airportCount) {
    cout << "Airport details:" << endl;
    for (int i = 0; i < airportCount; ++i) {
        // Assuming you have a method to display airport details in your Airport class
        cout << airports[i].getAirportDetails() << endl;
    }
}

void addNewFlightRoute(Flight flights[], int &flightCount, Airport airports[], int airportCount) {
    Flight newFlight;

    // Set flight details (e.g., flight number, departure time, arrival time, origin, and destination)
    // Assuming you have setter methods like setFlightNumber, setDepartureTime, etc., in your Flight class

    // Example:
    string flightNumber;
    cout << "Enter the flight number: ";
    cin >> flightNumber;
    newFlight.setFlightNumber(flightNumber);
    // Set other details similarly

    flights[flightCount++] = newFlight;
    cout << "New flight route added successfully." << endl;
}

void updateAirlineInquiryDetails(Flight flights[], int flightCount, Airport airports[], int airportCount) {
    int option;

    while (true) {
        cout << "Update Airline Inquiry Details" << endl;
        cout << "1. Update flight details" << endl;
        cout << "2. Update airport details" << endl;
        cout << "3. Return to the main menu" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                updateFlightDetails(flights, flightCount);
                break;
            case 2:
                updateAirportDetails(airports, airportCount);
                break;
            case 3:
                return;
            default:
                cerr << "Invalid option. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(10));
                break;
        }
    }
}

void updateFlightDetails(Flight flights[], int flightCount) {
    string flightNumber;
    cout << "Enter the flight number you want to update: ";
    cin >> flightNumber;

    for (int i = 0; i < flightCount; ++i) {
        if (flights[i].getFlightNumber() == flightNumber) {
            string newDepartureTime;
            cout << "Enter the new departure time: ";
            cin >> newDepartureTime;
            flights[i].setDepartureTime(newDepartureTime);

            // Update other details similarly

            cout << "Flight details updated successfully." << endl;
            return;
        }
    }

    cerr << "Flight not found. Please try again." << endl;
}

void updateAirportDetails(Airport airports[], int airportCount) {
    string airportCode;
    cout << "Enter the airport code you want to update: ";
    cin >> airportCode;

    for (int i = 0; i < airportCount; ++i) {
        if (airports[i].getLocation() == airportCode) { // Assuming the location is used as the airport code
            string newAirportName;
            cout << "Enter the new airport name: ";
            cin >> newAirportName;
            airports[i].setName(newAirportName); // Use setName instead of setAirportName

            // Update other details similarly

            cout << "Airport details updated successfully." << endl;
            return;
        }
    }

    cerr << "Airport not found. Please try again." << endl;
}


//.........................................................................................................................................................
//.PPPPPPPPPPPPPPP.........................................................................................................................................
//.PPPPPPPPPPPPPPPPP.......................................................................................................................................
//.PPPPPPPPPPPPPPPPP.......................................................................................................................................
//.PPPPPPPPPPPPPPPPPP......................................................................................................................................
//.PPPPPP....PPPPPPPP......................................................................................................................................
//.PPPPPP......PPPPPP......................................................................................................................................
//.PPPPPP......PPPPPP....aaaaaaaaaa......sssssssssss......sssssssssss.......eeeeeeeee.....nnnnn.nnnnnnnn.......ggggggggggggg.....eeeeeeeee.....errrrrrrrr..
//.PPPPPP......PPPPPP...aaaaaaaaaaaaa...sssssssssssss....sssssssssssss....eeeeeeeeeeee....nnnnnnnnnnnnnnn....ggggggggggggggg....eeeeeeeeeeee...errrrrrrrr..
//.PPPPPP......PPPPPP..Paaaaaaaaaaaaa...ssssssssssssss..ssssssssssssss....eeeeeeeeeeeee...nnnnnnnnnnnnnnn....ggggggggggggggg...eeeeeeeeeeeeee..errrrrrrrr..
//.PPPPPP...PPPPPPPPP..Paaaaaaaaaaaaa..assssss.sssssss..sssssss.sssssss..seeeeeeeeeeeeee..nnnnnnnnnnnnnnnn..nggggggggggggggg...eeeeeeeeeeeeee..errrrrrr....
//.PPPPPPPPPPPPPPPPPP..Paaaa...aaaaaa..asssss...ssssss..sssss....ssssss..seeeee...eeeeee..nnnnnnn...nnnnnn..nggggg...ggggggg..geeeee....eeeee..errrrrr.....
//.PPPPPPPPPPPPPPPPP............aaaaa..asssssss.........ssssssss........sseeee.....eeeee..nnnnnn....nnnnnn.nngggg.....gggggg..geeeee....eeeeee.errrrr......
//.PPPPPPPPPPPPPPPP.........aaaaaaaaa..asssssssssss.....sssssssssss.....sseeeeeeeeeeeeee..nnnnnn....nnnnnn.nngggg.....gggggg..geeeeeeeeeeeeeee.errrrr......
//.PPPPPPPPPPPPPPP......aaaaaaaaaaaaa...sssssssssssss....sssssssssssss..sseeeeeeeeeeeeee..nnnnnn....nnnnnn.nngggg.....gggggg..geeeeeeeeeeeeeee.errrrr......
//.PPPPPP..............Paaaaaaaaaaaaa....sssssssssssss....sssssssssssss.sseeeeeeeeeeeeee..nnnnnn....nnnnnn.nngggg.....gggggg..geeeeeeeeeeeeeee.errrrr......
//.PPPPPP..............Paaaaaaaaaaaaa......ssssssssssss.....sssssssssss.sseeee............nnnnnn....nnnnnn.nngggg.....gggggg..geeee............errrrr......
//.PPPPPP.............PPaaaaa...aaaaa..........ssssssss.........sssssss.sseeee............nnnnnn....nnnnnn.nngggg.....gggggg..geeeee...........errrrr......
//.PPPPPP.............PPaaaa...aaaaaa..asssss....ssssss.sssss.....sssss..seeeee...........nnnnnn....nnnnnn..nggggg...ggggggg..geeeee...........errrrr......
//.PPPPPP.............PPaaaaaaaaaaaaa..assssss.ssssssssssssssss.sssssss..seeeeee.eeeeeee..nnnnnn....nnnnnn..nggggggggggggggg..geeeeeeeeeeeeee..errrrr......
//.PPPPPP.............PPaaaaaaaaaaaaaa.assssssssssssss..sssssssssssssss...eeeeeeeeeeeeee..nnnnnn....nnnnnn...ggggggggggggggg...eeeeeeeeeeeeeee.errrrr......
//.PPPPPP..............Paaaaaaaaaaaaaa..ssssssssssssss...sssssssssssss....eeeeeeeeeeeee...nnnnnn....nnnnnn...ggggggggggggggg....eeeeeeeeeeeee..errrrr......
//.PPPPPP...............aaaaaaaaaaaaaa...sssssssssss......sssssssssss.......eeeeeeeeee....nnnnnn....nnnnnn....gggggggggggggg.....eeeeeeeeee....errrrr......
//....................................................................................................................gggggg...............................
//..........................................................................................................nggggg....gggggg...............................
//..........................................................................................................ngggggg.gggggggg...............................
//..........................................................................................................ngggggggggggggg................................
//...........................................................................................................gggggggggggggg................................
//............................................................................................................ggggggggggg..................................
//.........................................................................................................................................................



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
    Passenger passengers[50];
    Flight flights[100];
    Airport airports[10];

    // // Initialize necessary variables and indexes for arrays.
    int adminCount = 0;
    int passengerCount = 0;
    int flightCount = 0;
    int airportCount = 0;

    // // Load data from files.
    loadAdminData(admins, adminCount, "admins.txt");
    loadPassengerData(passengers, passengerCount, "passengers.txt");
    loadFlightData(flights, flightCount, "flights.txt");
    loadAirportData(airports, airportCount, "airports.txt");



    // Main menu loop
    while (true) {
         // Add this before the return statement in your main() function
        // std::cout << "Press any key to exit..." << std::endl;
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // std::cin.get();
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
                cout << "Press any key to exit..." << endl;
                _getch(); // Wait for a key press before exiting
                return 0;
            default:
                cerr << "Invalid option. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(10));
                break;
        }
    }
    
}
