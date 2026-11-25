# Expense-Management-System-
A Personal Expense Management System to track income, manage expenses, categorize spending, monitor budgets, and generate monthly savings reports.
 Project Overview
Managing personal finances is important for maintaining financial stability. This application provides a simple and interactive way to record income and expenses and monitor monthly spending.

The project is developed using basic C++ concepts and demonstrates the practical implementation of Object-Oriented Programming.

✨ Features
1. Income Management
Add new income records.
View all income records.
Store income descriptions and amounts.
2. Expense Management
Add new expenses.
View all recorded expenses.
Edit existing expenses.
Delete unwanted expense records.
3. Category Management
Expenses can be organized into five categories:

Food
Travel
Education
Shopping
Other
4. Budget Management
Set monthly budgets for different categories.
Track spending against budgets.
Calculate remaining budget.
Get warnings when spending exceeds the budget.
5. Monthly Reports
Calculate total monthly income.
Calculate total monthly expenses.
Calculate monthly savings.
Generate category-wise budget reports.
🛠️ Technologies Used
Technology	Purpose
C++	Core programming language
OOP	Application structure
iostream	Input and output
Arrays	Store income and expense records
Switch Case	Menu-driven operations
🧠 Object-Oriented Programming Concepts
This project demonstrates the following OOP concepts:

Concept	Implementation
Classes & Objects	Transaction, Income, Expense, ExpenseManager
Encapsulation	Private data members and public member functions
Inheritance	Income and Expense inherit from Transaction
Polymorphism	Virtual display() function and function overriding
Abstraction	ExpenseManager provides a simplified interface for operations
Constructor	Initializes transaction and manager objects
📂 Project Structure
expense-management-system/
│
├── main.cpp
└── README.md
⚙️ Installation & Setup
Prerequisites
C++ Compiler (GCC / MinGW)
Visual Studio Code (Recommended)
Step 1: Clone the Repository
git clone YOUR_GITHUB_REPOSITORY_URL
Step 2: Navigate to Project Directory
cd expense-management-system
Step 3: Compile the Program
g++ -std=c++11 main.cpp -o main.exe
Step 4: Run the Application
Windows:

.\main.exe
🖥️ Application Menu
====================================
 PERSONAL EXPENSE MANAGEMENT SYSTEM
====================================

1. Add Income
2. View Income
3. Add Expense
4. View Expenses
5. Edit Expense
6. Delete Expense
7. Set Monthly Budget
8. Monthly Report
9. Budget Report
0. Exit

Enter your choice:
📊 Example Monthly Report
========== MONTHLY REPORT ==========

Month: 11

Total Income: Rs. 15000
Total Expense: Rs. 5000
Total Savings: Rs. 10000

====================================
Example values are for demonstration purposes.

⚠️ Current Limitations
Data is stored in arrays.
