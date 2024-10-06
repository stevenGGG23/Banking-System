#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolderName;
    double balance;

public:
    // Constructor to initialize account holder name and balance
    BankAccount(const std::string& name) : accountHolderName(name), balance(0.0) {}

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Deposit amount must be positive!" << std::endl;
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient funds!" << std::endl;
        } else {
            std::cout << "Withdrawal amount must be positive!" << std::endl;
        }
    }

    // Method to check the account balance
    void checkBalance() const {
        std::cout << "Current balance: $" << balance << std::endl;
    }
};

int main() {
    std::string name;
    std::cout << "Enter account holder name: ";
    std::getline(std::cin, name);

    BankAccount account(name);
    int choice;
    
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            }
            case 2: {
                double amount;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            }
            case 3:
                account.checkBalance();
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid option! Please try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
