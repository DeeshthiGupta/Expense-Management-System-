
#include <iostream>
using namespace std;

// Base Class
class Transaction {
private:
    char title[50];
    double amount;
    int month;

public:
    Transaction() {
        title[0] = '\0';
        amount = 0;
        month = 1;
    }

    void setDetails() {
        cout << "Enter description (one word): ";
        cin >> title;

        cout << "Enter amount: ";
        cin >> amount;

        cout << "Enter month (1-12): ";
        cin >> month;
    }

    void setAmount(double a) {
        amount = a;
    }

    void setTitle(const char t[]) {
        int i = 0;
        while (t[i] != '\0' && i < 49) {
            title[i] = t[i];
            i++;
        }
        title[i] = '\0';
    }

    void setMonth(int m) {
        month = m;
    }

    double getAmount() {
        return amount;
    }

    int getMonth() {
        return month;
    }

    void getTitle(char t[]) {
        int i = 0;
        while (title[i] != '\0') {
            t[i] = title[i];
            i++;
        }
        t[i] = '\0';
    }

    virtual void display() {
        cout << "Description: " << title << endl;
        cout << "Amount: Rs. " << amount << endl;
        cout << "Month: " << month << endl;
    }
};

// Derived Class: Income
class Income : public Transaction {
public:
    void display() override {
        cout << "\n--- Income Details ---\n";
        Transaction::display();
    }
};

// Derived Class: Expense
class Expense : public Transaction {
private:
    int category;

public:
    Expense() {
        category = 1;
    }

    void setCategory(int c) {
        category = c;
    }

    int getCategory() {
        return category;
    }

    void display() override {
        cout << "\n--- Expense Details ---\n";
        Transaction::display();

        cout << "Category: ";
        switch (category) {
            case 1: cout << "Food"; break;
            case 2: cout << "Travel"; break;
            case 3: cout << "Education"; break;
            case 4: cout << "Shopping"; break;
            case 5: cout << "Other"; break;
        }
        cout << endl;
    }
};

// Main Management Class
class ExpenseManager {
private:
    Income incomes[100];
    Expense expenses[100];

    double budgets[5];

    int incomeCount;
    int expenseCount;

public:
    ExpenseManager() {
        incomeCount = 0;
        expenseCount = 0;

        for (int i = 0; i < 5; i++) {
            budgets[i] = 0;
        }
    }

    // Add Income
    void addIncome() {
        if (incomeCount >= 100) {
            cout << "Income limit reached!\n";
            return;
        }

        cout << "\nEnter Income Details:\n";
        incomes[incomeCount].setDetails();

        incomeCount++;

        cout << "Income added successfully!\n";
    }

    // Add Expense
    void addExpense() {
        if (expenseCount >= 100) {
            cout << "Expense limit reached!\n";
            return;
        }

        cout << "\nEnter Expense Details:\n";

        expenses[expenseCount].setDetails();

        int c;
        cout << "\nSelect Category:\n";
        cout << "1. Food\n";
        cout << "2. Travel\n";
        cout << "3. Education\n";
        cout << "4. Shopping\n";
        cout << "5. Other\n";
        cout << "Enter choice: ";
        cin >> c;

        if (c < 1 || c > 5) {
            cout << "Invalid category!\n";
            return;
        }

        expenses[expenseCount].setCategory(c);
        expenseCount++;

        cout << "Expense added successfully!\n";
    }

    // Display All Income
    void showIncome() {
        if (incomeCount == 0) {
            cout << "\nNo income records found.\n";
            return;
        }

        cout << "\n===== INCOME RECORDS =====\n";

        for (int i = 0; i < incomeCount; i++) {
            Transaction* t = &incomes[i];
            t->display();
        }
    }

    // Display All Expenses
    void showExpenses() {
        if (expenseCount == 0) {
            cout << "\nNo expense records found.\n";
            return;
        }

        cout << "\n===== EXPENSE RECORDS =====\n";

        for (int i = 0; i < expenseCount; i++) {
            Transaction* t = &expenses[i];
            t->display();
        }
    }

    // Edit Expense
    void editExpense() {
        int id;

        showExpenses();

        if (expenseCount == 0)
            return;

        cout << "\nEnter Expense ID (1-" << expenseCount << "): ";
        cin >> id;

        if (id < 1 || id > expenseCount) {
            cout << "Invalid ID!\n";
            return;
        }

        cout << "\nEnter Updated Details:\n";
        expenses[id - 1].setDetails();

        int c;
        cout << "Enter New Category (1-5): ";
        cin >> c;

        if (c < 1 || c > 5) {
            cout << "Invalid category!\n";
            return;
        }

        expenses[id - 1].setCategory(c);

        cout << "Expense updated successfully!\n";
    }

    // Delete Expense
    void deleteExpense() {
        int id;

        showExpenses();

        if (expenseCount == 0)
            return;

        cout << "\nEnter Expense ID to delete: ";
        cin >> id;

        if (id < 1 || id > expenseCount) {
            cout << "Invalid ID!\n";
            return;
        }

        for (int i = id - 1; i < expenseCount - 1; i++) {
            expenses[i] = expenses[i + 1];
        }

        expenseCount--;

        cout << "Expense deleted successfully!\n";
    }

    // Set Budget
    void setBudget() {
        int c;

        cout << "\nSelect Category:\n";
        cout << "1. Food\n";
        cout << "2. Travel\n";
        cout << "3. Education\n";
        cout << "4. Shopping\n";
        cout << "5. Other\n";

        cout << "Enter category: ";
        cin >> c;

        if (c < 1 || c > 5) {
            cout << "Invalid category!\n";
            return;
        }

        cout << "Enter monthly budget: ";
        cin >> budgets[c - 1];

        cout << "Budget set successfully!\n";
    }

    // Monthly Report
    void monthlyReport() {
        int m;

        cout << "\nEnter Month (1-12): ";
        cin >> m;

        if (m < 1 || m > 12) {
            cout << "Invalid month!\n";
            return;
        }

        double totalIncome = 0;
        double totalExpense = 0;

        for (int i = 0; i < incomeCount; i++) {
            if (incomes[i].getMonth() == m) {
                totalIncome += incomes[i].getAmount();
            }
        }

        for (int i = 0; i < expenseCount; i++) {
            if (expenses[i].getMonth() == m) {
                totalExpense += expenses[i].getAmount();
            }
        }

        cout << "\n===== MONTHLY REPORT =====\n";
        cout << "Month: " << m << endl;
        cout << "Total Income: Rs. " << totalIncome << endl;
        cout << "Total Expense: Rs. " << totalExpense << endl;
        cout << "Total Savings: Rs. "
             << totalIncome - totalExpense << endl;
    }

    // Category-wise Budget Report
    void budgetReport() {
        const char* names[5] = {
            "Food", "Travel", "Education", "Shopping", "Other"
        };

        cout << "\n===== BUDGET REPORT =====\n";

        for (int c = 0; c < 5; c++) {
            double spent = 0;

            for (int i = 0; i < expenseCount; i++) {
                if (expenses[i].getCategory() == c + 1) {
                    spent += expenses[i].getAmount();
                }
            }

            cout << "\nCategory: " << names[c] << endl;
            cout << "Budget: Rs. " << budgets[c] << endl;
            cout << "Spent: Rs. " << spent << endl;

            if (budgets[c] > 0) {
                cout << "Remaining: Rs. "
                     << budgets[c] - spent << endl;

                if (spent > budgets[c]) {
                    cout << "Warning: Budget exceeded!\n";
                }
            } else {
                cout << "No budget set.\n";
            }
        }
    }
};

// Main Function
int main() {
    ExpenseManager manager;
    int choice;

    do {
        cout << "\n\n";
        cout << "====================================\n";
        cout << " PERSONAL EXPENSE MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Income\n";
        cout << "2. View Income\n";
        cout << "3. Add Expense\n";
        cout << "4. View Expenses\n";
        cout << "5. Edit Expense\n";
        cout << "6. Delete Expense\n";
        cout << "7. Set Monthly Budget\n";
        cout << "8. Monthly Report\n";
        cout << "9. Budget Report\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addIncome();
                break;

            case 2:
                manager.showIncome();
                break;

            case 3:
                manager.addExpense();
                break;

            case 4:
                manager.showExpenses();
                break;

            case 5:
                manager.editExpense();
                break;

            case 6:
                manager.deleteExpense();
                break;

            case 7:
                manager.setBudget();
                break;

            case 8:
                manager.monthlyReport();
                break;

            case 9:
                manager.budgetReport();
                break;

            case 0:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
