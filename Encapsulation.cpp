#include <bits/stdc++.h>

using namespace std;

class BankBalance {
private:
    double balance;
public:
    BankBalance() : balance(100.00){};
    
    void deposit (double amount) {
        if(amount <= 0) {
            throw invalid_argument("Amount must be greater than zero");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if(amount > balance) {
            throw invalid_argument("Insufficient Funds.");
        }
        if(amount <= 0) {
            throw invalid_argument("Amount must be greate than zero");
        }
        balance -= amount;
    }
    
    double getBalance() {
        return balance;
    }
};

int main() {
    BankBalance account;  

    cout << "Initial Balance: ₹" << account.getBalance() << endl;

    account.deposit(50.0);
    cout << "After Deposit: ₹" << account.getBalance() << endl;

    account.withdraw(30.0);
    cout << "After Withdrawal: ₹" << account.getBalance() << endl;

    // account.balance = 1000; ❌ NOT allowed (private member)

    return 0;
}
