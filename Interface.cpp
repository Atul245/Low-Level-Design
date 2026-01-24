#include <bits/stdc++.h>
using namespace std;

/* 1. Abstraction */
class PaymentGateway {
public:
    virtual void initiatePayment(double amount) = 0;
    virtual ~PaymentGateway() {}
};

/* 2. Concrete implementation */
class StripeGateway : public PaymentGateway {
public:
    void initiatePayment(double amount) override {
        cout << "Payment of ₹" << amount << " processed via Stripe\n";
    }
};

class PaypalGateway : public PaymentGateway {
public:
    void initiatePayment(double amount) override {
        cout << "Payment of ₹" << amount << " processed via Paypal\n";
    }
};

/* 3. Loosely coupled service */
class CheckOutService {
private:
    PaymentGateway* paymentGateway;

public:
    CheckOutService(PaymentGateway* gateway) : paymentGateway(gateway) {}

    void setPaymentGateway(PaymentGateway* gateway) {
        paymentGateway = gateway;
    }

    void checkout(double amount) {
        if (paymentGateway != nullptr) {
            paymentGateway->initiatePayment(amount);
        }
    }
};

int main() {
    StripeGateway stripeGateway;
    CheckOutService service(&stripeGateway);
    service.checkout(100.50);
    
    PaypalGateway paypalGateway;
    service.setPaymentGateway(&paypalGateway);
    service.checkout(98.50);
    return 0;
}
