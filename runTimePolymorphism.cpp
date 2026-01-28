#include <bits/stdc++.h>
using namespace std;

// Interface (Abstract class)
class notificationSender {
public:
    virtual void sendNotification(const string& message) = 0;
    virtual ~notificationSender() {}
};

// Email sender
class emailSender : public notificationSender {
public:
    void sendNotification(const string& message) override {
        cout << "Email sent: " << message << endl;
    }
};

// SMS sender
class smsSender : public notificationSender {
public:
    void sendNotification(const string& message) override {
        cout << "SMS sent: " << message << endl;
    }
};

int main() {
    // Base class pointers (runtime polymorphism)
    notificationSender* n1 = new emailSender();
    notificationSender* n2 = new smsSender();

    n1->sendNotification("Welcome to the system!");
    n2->sendNotification("Your OTP is 123456");

    delete n1;
    delete n2;

    return 0;
}
