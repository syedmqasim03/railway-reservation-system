#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Train and seat configurations
int karachi_business_class[50] = {0}, karachi_economy_class[150] = {0};
int faisalabad_business_class[50] = {0}, faisalabad_economy_class[150] = {0};
int lahore_business_class[50] = {0}, lahore_economy_class[150] = {0};
int multan_business_class[50] = {0}, multan_economy_class[150] = {0};
int islamabad_business_class[50] = {0}, islamabad_economy_class[150] = {0};
float business_price = 5000.00, economy_price = 2500.00;
float price;

// Predefined train information (only 5 trains for 5 destinations)
string train_Destination_Time[5][4] = {
    {"  Lahore  ", "RQM 01", "10:00 AM", "200seats"},
    {"Faisalabad", "RQM 02", "11:00 AM", "200seats"},
    {"  Multan  ", "RQM 03", "12:00 AM", "200seats"},
    {" Karachi  ", "RQM 04", "7:00 PM", "200seats"},
    {"Islamabad ", "RQM 05", "1:00 PM", "200seats"}
};

// Function declarations
void showTrainSchedule();
void bookTicket(int trainIndex);
int reserveSeat(int business_class[], int economy_class[], int business, int economy);
void printTicket(const string& destination, int seat_no);
void cancelTicket();
void viewBookedTickets();

int main() {
    int choice;
    while (true) {
        // Main Menu
        cout << "\n\t***** Welcome to RGM Railway Station *****" << endl;
        cout << "1. View Train Schedule" << endl;
        cout << "2. Book a Ticket" << endl;
        cout << "3. Cancel a Ticket" << endl;
        cout << "4. View Booked Tickets" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            showTrainSchedule();
        } else if (choice == 2) {
            int destination;
            cout << "\nSelect Destination:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << train_Destination_Time[i][0] << endl;
            }
            cout << "Enter choice (1-5): ";
            cin >> destination;

            if (destination >= 1 && destination <= 5) {
                bookTicket(destination - 1);
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        } else if (choice == 3) {
            cancelTicket();
        } else if (choice == 4) {
            viewBookedTickets();
        } else if (choice == 5) {
            cout << "Thank you for using RGM Railway Station. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
        
    }

    return 0;
}

// Function to display train schedule
void showTrainSchedule() {
    cout << "\n***** Train Schedule *****" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cout << train_Destination_Time[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to handle ticket booking
void bookTicket(int trainIndex) {
    cout << "\nBooking ticket for destination: " << train_Destination_Time[trainIndex][0] << endl;
    const string f = "Faisalabad", l = "  Lahore  ", m = "  Multan  ", i = "Islamabad ", k = " Karachi  ";
    int seat_no;
    if (train_Destination_Time[trainIndex][0] == f) {
        seat_no = reserveSeat(faisalabad_business_class, faisalabad_economy_class, 50, 150);
    }
    if (train_Destination_Time[trainIndex][0] == l) {
        seat_no = reserveSeat(lahore_business_class, lahore_economy_class, 50, 150);
    }
    if (train_Destination_Time[trainIndex][0] == m) {
        seat_no = reserveSeat(multan_business_class, multan_economy_class, 50, 150);
    }
    if (train_Destination_Time[trainIndex][0] == i) {
        seat_no = reserveSeat(islamabad_business_class, islamabad_economy_class, 50, 150);
    }
    if (train_Destination_Time[trainIndex][0] == k) {
        seat_no = reserveSeat(karachi_business_class, karachi_economy_class, 50, 150);
    }

    printTicket(train_Destination_Time[trainIndex][0], seat_no);
}

// Function to reserve a seat
int reserveSeat(int business_class[], int economy_class[], int business, int economy) {
    int seat_no, class_type;
    cout << "Select Class: " << endl;
    cout << "1. Business Class (50 seats)" << endl;
    cout << "2. Economy Class (150 seats)" << endl;
    cout << "Enter choice: ";
    cin >> class_type;

    if (class_type == 1) {
        cout << "Enter seat number (1-50): ";
        cin >> seat_no;
        if (seat_no >= 1 && seat_no <= business && business_class[seat_no - 1] == 0) {
            business_class[seat_no - 1] = 1;
            price = business_price;
            return seat_no;
        } else {
            cout << "Invalid or already booked. Try again." << endl;
            return reserveSeat(business_class, economy_class, business, economy);
        }
    } else if (class_type == 2) {
        cout << "Enter seat number (1-150): ";
        cin >> seat_no;
        if (seat_no >= 1 && seat_no <= economy && economy_class[seat_no - 1] == 0) {
            economy_class[seat_no - 1] = 1;
            price = economy_price;
            return seat_no;
        } else {
            cout << "Invalid or already booked. Try again." << endl;
            return reserveSeat(business_class, economy_class, business, economy);
        }
    } else {
        cout << "Invalid class type. Try again." << endl;
        return reserveSeat(business_class, economy_class, business, economy);
    }
}

// Function to print the ticket
void printTicket(const string& destination, int seat_no) {
    string name, phone_no;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your phone number: ";
    cin >> phone_no;

    // Printing ticket
    cout << "\n********** Ticket **********" << endl;
    cout << "* RGM Railway Reservation System *" << endl;
    cout << "* Destination: " << destination << endl;
    cout << "* Name: " << name << endl;
    cout << "* Phone No: " << phone_no << endl;
    cout << "* Seat No: " << seat_no << endl;
    cout << "* Price: " << price << endl;
    cout << "*****************************" << endl;
}

// Function to cancel a ticket
void cancelTicket() {
    int destination, seat_no, class_type;
    cout << "\nSelect Destination for ticket cancellation:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << train_Destination_Time[i][0] << endl;
    }
    cout << "Enter choice (1-5): ";
    cin >> destination;

    if (destination >= 1 && destination <= 5) {
        cout << "Enter Class (1 for Business, 2 for Economy): ";
        cin >> class_type;

        cout << "Enter Seat Number: ";
        cin >> seat_no;

        // Handle cancellation for Business and Economy classes for each destination
        if (class_type == 1) {
            if (destination == 1 && lahore_business_class[seat_no - 1] == 1) {
                lahore_business_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else if (destination == 2 && faisalabad_business_class[seat_no - 1] == 1) {
                faisalabad_business_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else if (destination == 3 && multan_business_class[seat_no - 1] == 1) {
                multan_business_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else if (destination == 4 && karachi_business_class[seat_no - 1] == 1) {
                karachi_business_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else if (destination == 5 && islamabad_business_class[seat_no - 1] == 1) {
                islamabad_business_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else {
                cout << "Seat not found or not booked in business class." << endl;
            }
        } else if (class_type == 2) {
            if (destination == 1 && lahore_economy_class[seat_no - 1] == 1) {
                lahore_economy_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else if (destination == 2 && faisalabad_economy_class[seat_no - 1] == 1) {
                faisalabad_economy_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else if (destination == 3 && multan_economy_class[seat_no - 1] == 1) {
                multan_economy_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else if (destination == 4 && karachi_economy_class[seat_no - 1] == 1) {
                karachi_economy_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else if (destination == 5 && islamabad_economy_class[seat_no - 1] == 1) {
                islamabad_economy_class[seat_no - 1] = 0;
                cout << "Ticket cancelled successfully!" << endl;
            } else {
                cout << "Seat not found or not booked in economy class." << endl;
            }
        } else {
            cout << "Invalid class type. Try again." << endl;
        }
    } else {
        cout << "Invalid destination choice. Try again." << endl;
    }
}

// Function to view booked tickets (for testing)
void viewBookedTickets() {
    cout << "\n***** Booked Tickets *****" << endl;
    // Business class
    cout << "Business Class Bookings:" << endl;
    // Add checks for all destinations
    cout << "Lahore: ";
    for (int i = 0; i < 50; i++) {
        if (lahore_business_class[i] == 1) cout << i + 1 << " ";
    }
    cout << endl;
    // Repeat for other destinations and classes as needed
    // You can display other destinations similarly
}

