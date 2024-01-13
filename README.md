# Banking-management-system
A console-based application written in C. It allows users to perform banking operations like creating account & viewing it's details, depositing and withdrawing funds, transferring funds between accounts, and viewing all accounts (for bank employees).

## Functions
- Create Account: Allows users to create a new bank account with account details like account holder name, initial balance, and a password.
- View Account: Enables users to view account details by providing the account number and the associated password.
- Deposit: Allows users to deposit funds into their account, with validation for positive deposit amounts.
- Withdraw: Enables users to withdraw funds from their account, with validation for positive withdrawal amounts and sufficient funds.
- Transfer: Facilitates fund transfers between two accounts, with validation for positive transfer amounts, sufficient funds, and valid destination account.
- View All Account (Bank Employee): For bank employees, it provides a view of all account details, including passwords (requires admin password for access).
- Exit: Exits the program.


## Constraints
- Maximum of 100 bank accounts with account numbers are automatically generated
- Data is stored in RAM and not in a database i.e. non persistent.

## How to use?
- Compile the program
 `gcc -o bank_system bank_system.c`
- Run the compiled program
 `./bank_system`

