#include <iostream>
#include <string>

#define MAX_SIZE 5

using namespace std;

class Reservation {
public:
    int bookingId;
    string customerName;
};

class TicketQueue {
private:
    Reservation reservations[MAX_SIZE];
    int front, rear;

public:
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void addReservation(Reservation newBooking) {
        if (isFull()) {
            cout << "\n[Error] Reservation queue is full. Cannot add more bookings." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        reservations[rear] = newBooking;
        cout << "\n[Success] Reservation confirmed for " << newBooking.customerName 
             << " with Booking ID: " << newBooking.bookingId << endl;
    }

    void cancelReservation() {
        if (isEmpty()) {
            cout << "\n[Info] Reservation queue is empty. Nothing to cancel." << endl;
            return;
        }

        Reservation canceledBooking = reservations[front];
        cout << "\n[Success] Canceled reservation for " << canceledBooking.customerName 
             << " (Booking ID: " << canceledBooking.bookingId << ")" << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void displayReservations() {
        if (isEmpty()) {
            cout << "\n[Info] The reservation queue is currently empty." << endl;
            return;
        }

        cout << "\n--- Current Reservations (First-In, First-Out) ---" << endl;
        int i = front;
        while (true) {
            cout << "  Booking ID: " << reservations[i].bookingId 
                 << ", Name: " << reservations[i].customerName << endl;
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        cout << "----------------------------------------------------" << endl;
    }
    
    Reservation peekFront() {
        if (isEmpty()) {
            return {-1, "N/A"};
        }
        return reservations[front];
    }
};

int main() {
    TicketQueue system;
    int choice;
    int bookingCounter = 101;

    do {
        cout << "\n========== Ticket Reservation System ==========" << endl;
        cout << "1. Make a Reservation" << endl;
        cout << "2. Cancel a Reservation (Processes the first in queue)" << endl;
        cout << "3. Modify a Reservation (Processes the first in queue)" << endl;
        cout << "4. Display All Reservations" << endl;
        cout << "5. Exit" << endl;
        cout << "=============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (system.isFull()) {
                    cout << "\n[Error] The queue is full. Cannot make a new reservation right now." << endl;
                } else {
                    Reservation newBooking;
                    newBooking.bookingId = bookingCounter++;
                    cout << "Enter customer name: ";
                    cin.ignore(); 
                    getline(cin, newBooking.customerName);
                    system.addReservation(newBooking);
                }
                break;
            }
            case 2: {
                system.cancelReservation();
                break;
            }
            case 3: {
                if (system.isEmpty()) {
                    cout << "\n[Info] Queue is empty, nothing to modify." << endl;
                    break;
                }
                Reservation currentBooking = system.peekFront();
                cout << "\n--- Modifying Next Reservation in Queue ---" << endl;
                cout << "Current Details -> ID: " << currentBooking.bookingId << ", Name: " << currentBooking.customerName << endl;
                cout << "Modification involves canceling this and adding a new one." << endl;
                
                char confirm;
                cout << "Do you want to proceed? (y/n): ";
                cin >> confirm;
                
                if (confirm == 'y' || confirm == 'Y') {
                    system.cancelReservation(); 
                    
                    Reservation modifiedBooking;
                    modifiedBooking.bookingId = bookingCounter++;
                    cout << "Enter new customer name for the reservation: ";
                    cin.ignore();
                    getline(cin, modifiedBooking.customerName);
                    system.addReservation(modifiedBooking);
                    cout << "[Success] Reservation has been modified." << endl;
                } else {
                    cout << "[Info] Modification cancelled." << endl;
                }
                break;
            }
            case 4: {
                system.displayReservations();
                break;
            }
            case 5: {
                cout << "\nExiting the system. Thank you!" << endl;
                break;
            }
            default:
                cout << "\n[Error] Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
