#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& name, double price) : name(name), price(price) {}

    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }

    virtual double getFinalPrice() const = 0; 
    virtual ~Product() = default;            
};

class Discountable {
public:
    virtual double applyDiscount(double price) const = 0; 
    virtual ~Discountable() = default;
};

class Book : public Product, public Discountable {
public:
    Book(const string& name, double price) : Product(name, price) {}

    double applyDiscount(double price) const override {
        return price * 0.9;
    }

    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};

class Pen : public Product, public Discountable {
public:
    Pen(const string& name, double price) : Product(name, price) {}

    double applyDiscount(double price) const override {
        return (price > 5) ? price - 5 : price; 
    }

    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Book book1("Книга \"Убивства за абеткою\"", 180);
    Book book2("Книга \"Не озирайся і мовчи\"", 290);
    Pen pen1("Синя ручка", 10);
    Pen pen2("Чорна ручка", 4);

    cout << "Товар: " << book1.getName() << ", Ціна: " << book1.getPrice()
        << ", Ціна зі знижкою: " << book1.getFinalPrice() << endl;

    cout << "Товар: " << book2.getName() << ", Ціна: " << book2.getPrice()
        << ", Ціна зі знижкою: " << book2.getFinalPrice() << endl;

    cout << "Товар: " << pen1.getName() << ", Ціна: " << pen1.getPrice()
        << ", Ціна зі знижкою: " << pen1.getFinalPrice() << endl;

    cout << "Товар: " << pen2.getName() << ", Ціна: " << pen2.getPrice()
        << ", Ціна зі знижкою: " << pen2.getFinalPrice() << endl;

    return 0;
}
