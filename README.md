# Personal Expenses Tracker

## Description

Personal Expenses Tracker is a C++ application designed to help users manage their personal finances. Users can sign up, log in, add expenses, edit or delete them, and generate expense reports. The application saves expenses to a CSV file and supports multiple users.

## Features

- **Sign Up**: Register a new user with details including first name, last name, nickname, phone number, email ID, and password.
- **Log In**: Authenticate users using their nickname, email ID, or phone number along with their password.
- **Add Expense**: Add a new expense with details such as amount, category, date, and optional notes.
- **Edit Expense**: Modify the details of an existing expense.
- **Delete Expense**: Remove an expense from the list.
- **Generate Report**: Generate a report of expenses, showing total amount spent and categorized spending.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- Standard C++ library

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/personal-expenses-tracker.git
    cd personal-expenses-tracker
    ```

2. Compile the code:
    ```bash
    g++ -o expenses_tracker main.cpp
    ```

3. Run the application:
    ```bash
    ./expenses_tracker
    ```

## Usage

Upon running the application, you will be presented with a menu offering the following options:

1. **Sign Up**: Register as a new user.
2. **Log In**: Log in with your credentials.
3. **Add Expense**: Add a new expense.
4. **Edit Expense**: Edit an existing expense.
5. **Delete Expense**: Delete an existing expense.
6. **Generate Report**: Generate a report of your expenses.
7. **Exit**: Exit the application.

Follow the prompts for each option to manage your expenses.

## Code Overview

- **User Struct**: Stores user details.
- **Expense Struct**: Stores expense details.
- **Functions**:
  - `displayMenu()`: Displays the main menu.
  - `signUp()`: Handles user registration.
  - `logIn()`: Handles user authentication.
  - `addExpense()`: Adds a new expense and saves it to `expenses.csv`.
  - `editExpense()`: Edits an existing expense.
  - `deleteExpense()`: Deletes an existing expense.
  - `generateReport()`: Generates a report of expenses.
  - `readExpenses()`: Reads expenses from `expenses.csv`.
  - `displayExpenses()`: Displays a list of expenses.
  - `selectExpenseToEdit()`: Selects an expense to edit or delete.
  - `editExpenseDetails()`: Edits the details of an expense.
  - `writeExpenses()`: Writes expenses to `expenses.csv`.
  - `removeExpense()`: Removes an expense from the list.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for review.



## Contact

If you have any questions, feel free to contact me at hazraankit668@gmail.com.


