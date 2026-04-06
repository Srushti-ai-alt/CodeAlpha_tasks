#include <iostream>
#include <vector>
using namespace std;


class Transaction {
public:
    string type;
    float amount;

    Transaction(string t, float a) {
        type = t;
        amount = a;
    }
};

// Account Class
class Account {
public:
    int accNo;
    float balance;
    vector<Transaction> history;

    Account(int no) {
        accNo = no;
        balance = 0;
    }

    void deposit(float amt) {
        balance += amt;
        history.push_back(Transaction("Deposit", amt));
        cout << "✅ Deposited successfully!\n";
    }

    void withdraw(float amt) {
        if (amt > balance) {
            cout << "❌ Insufficient balance!\n";
        } else {
            balance -= amt;
            history.push_back(Transaction("Withdraw", amt));
            cout << "✅ Withdrawal successful!\n";
        }
    }

    void transfer(Account &to, float amt) {
        if (amt > balance) {
            cout << "❌ Insufficient balance!\n";
        } else {
            balance -= amt;
            to.balance += amt;

            history.push_back(Transaction("Transfer Sent", amt));
            to.history.push_back(Transaction("Transfer Received", amt));

            cout << "✅ Transfer successful!\n";
        }
    }

    void showTransactions() {
        cout << "\n--- Transaction History ---\n";
        for (auto &t : history) {
            cout << t.type << " : " << t.amount << endl;
        }
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

// Customer Class
class Customer {
public:
    string name;
    Account account;

    Customer(string n, int accNo) : account(accNo) {
        name = n;
    }

    void showDetails() {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Account No: " << account.accNo << endl;
        account.showBalance();
    }
};

// Main Program
int main() {
    Customer c1("Kusum", 101);
    Customer c2("Amit", 102);

    int choice;
    float amount;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Show Balance\n";
        cout << "5. Show Transactions\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                c1.account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                c1.account.withdraw(amount);
                break;

            case 3:
                cout << "Enter amount: ";
                cin >> amount;
                c1.account.transfer(c2.account, amount);
                break;

            case 4:
                c1.showDetails();
                break;

            case 5:
                c1.account.showTransactions();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "❌ Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}