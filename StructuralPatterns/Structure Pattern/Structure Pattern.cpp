#include <iostream>
#include <string>

using namespace std;

class Beverage
{
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;
};

class Espresso : public Beverage
{
public:
    string getDescription() override { return "Эспрессо"; }
    double cost() override { return 249.99; }
};

class Latte : public Beverage
{
public:
    string getDescription() override { return "Латте"; }
    double cost() override { return 299.99; }
};

class Capuchino : public Beverage
{
    string getDescription() override { return "Капучино"; }
    double cost() override { return 269.99; }
};

class CondimentDecorator : public Beverage
{
protected:
    Beverage* beverage;
public:
    CondimentDecorator(Beverage* b) : beverage(b) {}
    string getDescription() override { return beverage->getDescription(); }
    double cost() override { return beverage->cost(); }
};

class Milk : public CondimentDecorator
{
public:
    Milk(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + " Молоко"; }
    double cost() override { return beverage->cost() + 10; }
};

class Sugar : public CondimentDecorator
{
public:
    Sugar(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + " Сахар"; }
    double cost() override { return beverage->cost() + 5.99; }
};

class Syrup : public CondimentDecorator
{
public:
    Syrup(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + " Сироп"; }
    double cost() override { return beverage->cost() + 6.6; }
};

class Ice : public CondimentDecorator
{
public:
    Ice(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + " Лёд"; }
    double cost() override { return beverage->cost() + 2.5; }
};

class PictureOnCoffee : public CondimentDecorator
{
public:
    PictureOnCoffee(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + " Картинка на кофе"; }
    double cost() override { return beverage->cost() + 28.8; }
};


int main()
{
    setlocale(0, "");

    Beverage* drink = new Espresso;
    drink = new Milk(drink);
    drink = new Sugar(drink);
    drink = new Syrup(drink);

    cout << drink->getDescription() << " стоит " << drink->cost() << " Р." << endl;

    Beverage* drink2 = new Latte;
    drink2 = new Milk(drink2);
    drink2 = new Sugar(drink2);

    cout << drink2->getDescription() << " стоит " << drink2->cost() << " Р." << endl;

    Beverage* drink3 = new Capuchino;
    drink3 = new Ice(drink3);
    drink3 = new PictureOnCoffee(drink3);

    cout << drink3->getDescription() << " стоит " << drink3->cost() << " Р." << endl;
    
}
