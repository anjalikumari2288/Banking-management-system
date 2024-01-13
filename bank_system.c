#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struc def
struct BankAccount {
    int accountNumber;
    char accountHolder[100];
    double balance;
    char password[20];
};

// Function prototypes
void createAccount();
void viewAccount();
void deposit();
void withdraw();
void transfer();
void viewAllAccountsAdmin();
bool verifyPassword(int accountNumber, const char *password);

struct BankAccount accounts[100];
int accountCount = 0;

int main() {
    int choice;

    do {
        // Display
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Transfer\n");
        printf("6. View All Account(Bank Employee)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                transfer();
                break;
            case 6:
                viewAllAccountsAdmin();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

// Creates new bank acc
void createAccount() {
    printf("\nEnter account details:\n");
    accounts[accountCount].accountNumber = accountCount + 1; // Auto-gen acc no
    printf("Account Holder: ");
    scanf("%s", accounts[accountCount].accountHolder);
    printf("Initial Balance: ");
    scanf("%lf", &accounts[accountCount].balance);
    printf("Set Password: ");
    scanf("%s", accounts[accountCount].password);

    printf("Account created successfully!\n");
    accountCount++;
}

void viewAccount() {
    int accountNumber;
    char password[20];

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    printf("Enter password: ");
    scanf("%s", password);

    if (verifyPassword(accountNumber, password)) {
        printf("\nAccount Details:\n");
        printf("Account Number: %d\n", accounts[accountNumber - 1].accountNumber);
        printf("Account Holder: %s\n", accounts[accountNumber - 1].accountHolder);
        printf("Balance: $%.2lf\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number or password. Please try again.\n");
    }
}

void deposit() {
    int accountNumber;
    char password[20];
    double amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    printf("Enter password: ");
    scanf("%s", password);

    if (verifyPassword(accountNumber, password)) {
        printf("Enter deposit amount: $");
        scanf("%lf", &amount);

        if (amount > 0) {
            accounts[accountNumber - 1].balance += amount;
            printf("Deposit successful. New balance: $%.2lf\n", accounts[accountNumber - 1].balance);
        } else {
            printf("Invalid deposit amount. Please enter a positive value.\n");
        }
    } else {
        printf("Invalid account number or password. Please try again.\n");
    }
}

void withdraw() {
    int accountNumber;
    char password[20];
    double amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    printf("Enter password: ");
    scanf("%s", password);

    if (verifyPassword(accountNumber, password)) {
        printf("Enter withdrawal amount: $");
        scanf("%lf", &amount);

        if (amount > 0 && amount <= accounts[accountNumber - 1].balance) {
            accounts[accountNumber - 1].balance -= amount;
            printf("Withdrawal successful. New balance: $%.2lf\n", accounts[accountNumber - 1].balance);
        } else if (amount <= 0) {
            printf("Invalid withdrawal amount. Please enter a positive value.\n");
        } else {
            printf("Insufficient funds for withdrawal.\n");
        }
    } else {
        printf("Invalid account number or password. Please try again.\n");
    }
}

void transfer() {
    int sourceAccount, destinationAccount;
    char password[20];
    double amount;

    printf("\nEnter source account number: ");
    scanf("%d", &sourceAccount);

    printf("Enter password: ");
    scanf("%s", password);

    if (verifyPassword(sourceAccount, password)) {
        printf("Enter destination account number: ");
        scanf("%d", &destinationAccount);

        printf("Enter transfer amount: $");
        scanf("%lf", &amount);

        if (destinationAccount >= 1 && destinationAccount <= accountCount) {
            if (amount > 0 && amount <= accounts[sourceAccount - 1].balance) {
                accounts[sourceAccount - 1].balance -= amount;
                accounts[destinationAccount - 1].balance += amount;
                printf("Transfer successful. New balance for source account (%d): $%.2lf\n",
                       sourceAccount, accounts[sourceAccount - 1].balance);
                printf("New balance for destination account (%d): $%.2lf\n",
                       destinationAccount, accounts[destinationAccount - 1].balance);
            } else if (amount <= 0) {
                printf("Invalid transfer amount. Please enter a positive value.\n");
            } else {
                printf("Insufficient funds for transfer.\n");
            }
        } else {
            printf("Invalid destination account number. Please try again.\n");
        }
    } else {
        printf("Invalid account number or password. Please try again.\n");
    }
}

void viewAllAccountsAdmin() {
    char adminPassword[20];

    printf("\nEnter admin password: ");
    scanf("%s", adminPassword);

    if (strcmp(adminPassword, "admin") == 0) {
        printf("\nAll Account Details (including passwords):\n");
        for (int i = 0; i < accountCount; ++i) {
            printf("\nAccount Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].accountHolder);
            printf("Balance: $%.2lf\n", accounts[i].balance);
        }
    } else {
        printf("Invalid admin password. Access denied.\n");
    }
}

bool verifyPassword(int accountNumber, const char *password) {
    if (accountNumber >= 1 && accountNumber <= accountCount) {
        return strcmp(accounts[accountNumber - 1].password, password) == 0;
    }
    return false;
}

// gcc -o bank_system bank_system.c
// ./bank_system