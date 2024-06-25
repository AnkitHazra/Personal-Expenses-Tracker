#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

struct User {
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phNumber;
    std::string emailId;
    std::string password;
};

struct Expense {
    double amount;
    std::string category;
    std::string date;
    std::string notes;
};

void displayMenu();
void signUp();
void logIn();
void addExpense();
void editExpense();
void deleteExpense();
void generateReport();

std::vector<Expense> readExpenses();
void displayExpenses(const std::vector<Expense>& expenses);
int selectExpenseToEdit(const std::vector<Expense>& expenses);
void editExpenseDetails(Expense& expense);
void writeExpenses(const std::vector<Expense>& expenses);
void removeExpense(int index, std::vector<Expense>& expenses);

std::vector<User> users; // Vector to store multiple users
std::vector<Expense> expenses; // Vector to store multiple expenses

int main() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                logIn();
                break;
            case 3:
                addExpense();
                break;
            case 4:
                editExpense();
                break;
            case 5:
                deleteExpense();
                break;
            case 6:
                generateReport();
                break;
            case 7:
                std::cout << "Exiting from the program." << std::endl;
                return 0;
            default:
                std::cerr << "Invalid input!!!" << std::endl;
        }
    }
}

void displayMenu() {
    std::cout << "------Personal Expenses Tracker------" << std::endl;
    std::cout << "1. Sign Up" << std::endl;
    std::cout << "2. Log In" << std::endl;
    std::cout << "3. Add Expense" << std::endl;
    std::cout << "4. Edit Expense" << std::endl;
    std::cout << "5. Delete Expense" << std::endl;
    std::cout << "6. Generate Report" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your choice: ";
}

void signUp() {
    std::cout << "Sign up function called" << std::endl;
    std::cout << std::endl;

    std::string firstName, lastName, nickName, phNumber, emailId, password, confirmPassword;

    std::cout << "Enter your First Name: ";
    std::cin >> firstName;

    std::cout << "Enter your Last Name: ";
    std::cin >> lastName;

    std::cout << "Enter your Nick Name: ";
    std::cin >> nickName;

    std::cout << "Enter your Phone Number: ";
    std::cin >> phNumber;

    std::cout << "Enter your Email Id: ";
    std::cin >> emailId;

    // Checking valid Email ID
    if (emailId.find('@') == std::string::npos || emailId.find('.') == std::string::npos) {
        std::cerr << "Invalid email format!" << std::endl;
        return;
    }

    std::cout << "Enter your Password: ";
    std::cin >> password;

    std::cout << "Confirm your Password: ";
    std::cin >> confirmPassword;

    // Checking if passwords match
    if (password != confirmPassword) {
        std::cerr << "Passwords do not match!" << std::endl;
        return;
    }

    // Create a new User and add it to the users vector
    User newUser = {firstName, lastName, nickName, phNumber, emailId, password};
    users.push_back(newUser);

    std::cout << "User registered successfully!" << std::endl;
}

void logIn() {
    std::cout << "Log In function called." << std::endl;
    std::cout << std::endl;

    std::cout << "Enter any one of these:" << std::endl;
    std::cout << "1. Nick Name" << std::endl;
    std::cout << "2. Email ID" << std::endl;
    std::cout << "3. Phone Number" << std::endl;

    int choice;
    std::cin >> choice;
    bool userFound = false;

    std::string logName, logEmail, logPhone, logPassword;

    if (choice == 1) {
        std::cout << "Enter your Nick Name: ";
        std::cin >> logName;
    } else if (choice == 2) {
        std::cout << "Enter your Email Id: ";
        std::cin >> logEmail;
    } else if (choice == 3) {
        std::cout << "Enter your phone number: ";
        std::cin >> logPhone;
    } else {
        std::cerr << "Invalid choice!" << std::endl;
        return;
    }

    std::cout << "Enter password: ";
    std::cin >> logPassword;

    // Check credentials
    for (const auto& user : users) {
        if ((choice == 1 && user.nickName == logName) || (choice == 2 && user.emailId == logEmail) || (choice == 3 && user.phNumber == logPhone)) {
            if (user.password == logPassword) {
                std::cout << "Login successful. Welcome " << user.firstName << "!" << std::endl;
                userFound = true;
                break;
            } else {
                std::cerr << "Incorrect Password. Try Again!!" << std::endl;
            }
        }
    }
    if (!userFound) {
        std::cerr << "User not found!" << std::endl;
    }
}

void addExpense() {
    Expense newExpense;

    std::cout << "Enter your Expense amount: ";
    std::cin >> newExpense.amount;

    std::cout << "Enter Category: ";
    std::cin >> newExpense.category;

    std::cout << "Enter Date (DD/MM/YYYY): ";
    std::cin >> newExpense.date;

    std::cout << "Enter note (Optional): "; 
    std::cin.ignore(); // Ignore the newline character from previous input
    std::getline(std::cin, newExpense.notes);

    if (newExpense.amount <= 0) {
        std::cerr << "Expense must be a positive number!!" << std::endl;
        return;
    }

    expenses.push_back(newExpense);

    std::ofstream outFile("expenses.csv", std::ios::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << newExpense.amount << "," << newExpense.category << ","
                << newExpense.date << "," << newExpense.notes << "\n";
        outFile.close();
        std::cout << "Expense added successfully and saved to expenses.csv." << std::endl;
    } else {
        std::cerr << "Error: Unable to open expenses.csv for writing." << std::endl;
    }
}

std::vector<Expense> readExpenses() {
    std::vector<Expense> expenses;
    std::ifstream inFile("expenses.csv");
    std::string line;
    
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string amountStr, category, date, notes;
        
        std::getline(ss, amountStr, ',');
        std::getline(ss, category, ',');
        std::getline(ss, date, ',');
        std::getline(ss, notes, ',');
        
        Expense expense;
        expense.amount = std::stod(amountStr);
        expense.category = category;
        expense.date = date;
        expense.notes = notes;
        
        expenses.push_back(expense);
    }
    
    return expenses;
}

void displayExpenses(const std::vector<Expense>& expenses) {
    for (size_t i = 0; i < expenses.size(); ++i) {
        std::cout << i + 1 << ". " << expenses[i].amount << ", " << expenses[i].category << ", " 
                  << expenses[i].date << ", " << expenses[i].notes << std::endl;
    }
}

int selectExpenseToEdit(const std::vector<Expense>& expenses) {
    int choice;
    displayExpenses(expenses);
    std::cout << "Enter the number of the expense you want to edit/delete: ";
    std::cin >> choice;
    
    return choice - 1; // Convert to zero-based index
}

void editExpenseDetails(Expense& expense) {
    std::cout << "Editing expense: " << expense.amount << ", " << expense.category << ", " 
              << expense.date << ", " << expense.notes << std::endl;
    
    std::cout << "Enter new amount: ";
    std::cin >> expense.amount;
    
    std::cout << "Enter new category: ";
    std::cin.ignore(); // Ignore any leftover newline character in the buffer
    std::getline(std::cin, expense.category);
    
    std::cout << "Enter new date: ";
    std::getline(std::cin, expense.date);
    
    std::cout << "Enter new notes: ";
    std::getline(std::cin, expense.notes);
}

void writeExpenses(const std::vector<Expense>& expenses) {
    std::ofstream outFile("expenses.csv");
    
    for (const auto& expense : expenses) {
        outFile << expense.amount << "," << expense.category << "," 
                << expense.date << "," << expense.notes << "\n";
    }
}

void editExpense() {
    std::vector<Expense> expenses = readExpenses();
    
    if (expenses.empty()) {
        std::cerr << "No expenses to edit!" << std::endl;
        return;
    }
    
    int index = selectExpenseToEdit(expenses);
    
    if (index >= 0 && index < expenses.size()) {
        editExpenseDetails(expenses[index]);
        writeExpenses(expenses);
        std::cout << "Expense edited successfully." << std::endl;
    } else {
        std::cerr << "Invalid selection!" << std::endl;
    }
}

void removeExpense(int index, std::vector<Expense>& expenses) {
    if (index >= 0 && index < expenses.size()) {
        expenses.erase(expenses.begin() + index);
    } else {
        std::cerr << "Invalid index!" << std::endl;
    }
}

void deleteExpense() {
    std::vector<Expense> expenses = readExpenses();
    
    if (expenses.empty()) {
        std::cerr << "No expenses to delete!" << std::endl;
        return;
    }
    
    int index = selectExpenseToEdit(expenses);
    
    if (index >= 0 && index < expenses.size()) {
        removeExpense(index, expenses);
        writeExpenses(expenses);
        std::cout << "Expense deleted successfully." << std::endl;
    } else {
        std::cerr << "Invalid selection!" << std::endl;
    }
}

void generateReport() {
    std::vector<Expense> expenses = readExpenses();

    if (expenses.empty()) {
        std::cerr << "No expenses to generate report!" << std::endl;
        return;
    }

    double totalAmount = 0;
    std::map<std::string, double> categoryTotals;

    for (const auto& expense : expenses) {
        totalAmount += expense.amount;
        categoryTotals[expense.category] += expense.amount;
    }

    std::cout << "------Expenses Report------" << std::endl;
    std::cout << "Total Amount Spent: ₹" << totalAmount << std::endl;
    std::cout << "Expenses by Category:" << std::endl;

    for (const auto& category : categoryTotals) {
        std::cout << category.first << ": ₹" << category.second << std::endl;
    }
}
