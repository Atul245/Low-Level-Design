class notificationSender {
public:
    virtual void sendNotification(const string& message) = 0
};

class emailSender : public notificationSender () {
public:
    void sendNotification(const string& message) override {
        cout << "Message sent through Email..." << endl;
    }
};

class  smsSender : public notificationSender () {
public:
    void sendNotification(const string& message) override {
        cout << "Message sent through sms..." << endl;
    }
};

int main() {
    

    return 0;
}
