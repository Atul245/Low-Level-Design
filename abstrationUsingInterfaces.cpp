#include <bits/stdc++.h>
using namespace std;

// Abstract base class
class Document {
protected:
    string content;

public:
    // Constructor
    Document(string content) : content(content) {}

    string getContent() const {
        return content;
    }

    virtual ~Document() {}
};

// Pure abstract class (Interface)
class printable {
public:
    virtual void print(const Document& doc) = 0;
    virtual ~printable() {}
};

// Derived class: PDF Printer
class pdfPrinter : public printable {
public:
    void print(const Document& doc) override {
        cout << "Printing PDF: " << doc.getContent() << endl;
    }
};

// Derived class: Inkjet Printer
class inkjetPrinter : public printable {
public:
    void print(const Document& doc) override {
        cout << "Printing via Inkjet: " << doc.getContent() << endl;
    }
};

int main() {
    // Create document
    Document doc1("Hello PDF World");
    Document doc2("Hello Inkjet World");

    // Interface pointers
    printable* p1 = new pdfPrinter();
    printable* p2 = new inkjetPrinter();

    p1->print(doc1);
    p2->print(doc2);

    delete p1;
    delete p2;

    return 0;
}
