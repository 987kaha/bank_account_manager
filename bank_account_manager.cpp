#include <iostream>
using namespace std;

// BankAccount class definition
class BankAccount {
private:
    string owner;
    double balance;

public:
    // Constructor to initialize a new account
    BankAccount(string owner, double initialBalance) {
        this->owner = owner;
        if (initialBalance >= 0) {
            this->balance = initialBalance;
        } else {
            this->balance = 0;
            cout << "Initial balance cannot be negative. Setting balance to 0." << endl;
        }
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    // Function to check the account balance
    double checkBalance() {
        return balance;
    }
};

int main() {
    // Create a new bank account with an initial balance
    BankAccount myAccount("John Doe", 1000.00);

    // Display initial balance
    cout << "Initial balance: $" << myAccount.checkBalance() << endl;

    // Perform some deposits and withdrawals
    myAccount.deposit(500.00);
    cout << "Current balance: $" << myAccount.checkBalance() << endl;

    myAccount.withdraw(200.00);
    cout << "Current balance: $" << myAccount.checkBalance() << endl;

    myAccount.withdraw(1500.00); // Attempt to withdraw more than the balance

    return 0;
}
