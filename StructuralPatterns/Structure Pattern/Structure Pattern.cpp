#include <iostream>
#include <string>

using namespace std;

/// @brief Интерфейс для напитков
class Beverage
{
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;
};

/// @brief Класс с настройками напитка "Эспрессо"
class Espresso : public Beverage
{
public:
    /**
    * \brief Функция для получения названия напитка
    * \return string - Возвращает название напитка
    */
    string getDescription() override { return "Эспрессо"; }
    /**
    * \brief Функция для получения цены напитка
    * \return double - Возвращает цена напитка
    */
    double cost() override { return 249.99; }
};

/// @brief Класс с настройками напитка "Латте"
class Latte : public Beverage
{
public:
    /**
    * \brief Функция для получения названия напитка
    * \return string - Возвращает название напитка
    */
    string getDescription() override { return "Латте"; }
    /**
    * \brief Функция для получения цены напитка
    * \return double - Возвращает цена напитка
    */
    double cost() override { return 299.99; }
};

/// @brief Класс с настройками напитка "Капучино"
class Capuchino : public Beverage
{
public:
    /**
    * \brief Функция для получения названия напитка
    * \return string - Возвращает название напитка
    */
    string getDescription() override { return "Капучино"; }
    /**
    * \brief Функция для получения цены напитка
    * \return double - Возвращает цена напитка
    */
    double cost() override { return 269.99; }
};

/// @brief Класс с настройками напитка "Чай"
class Tea : public Beverage
{
public:
    /**
    * \brief Функция для получения названия напитка
    * \return string - Возвращает название напитка
    */
    string getDescription() override { return "Чай"; }
    /**
    * \brief Функция для получения цены напитка
    * \return double - Возвращает цена напитка
    */
    double cost() override { return 149.99; }
};

/// @brief Класс для получения информации о напитке или о добавке
class CondimentDecorator : public Beverage
{
protected:
    /**
    * \brief Получение указателя на класс напиток
    */
    Beverage* beverage;
public:
    /**
    * \brief Конструктор для инициализации напитка
    */
    CondimentDecorator(Beverage* b) : beverage(b) {}
    /**
    * \brief Функция для получения названия напитка
    * \return string - Возвращает название напитка
    */
    string getDescription() override { return beverage->getDescription(); }
    /**
    * \brief Функция для получения цену напитка
    * \return double - Возвращает цену напитка
    */
    double cost() override { return beverage->cost(); }
};

/// @brief Класс для добавления "Молока"
class Milk : public CondimentDecorator
{
public:
    /**
    * @brief Конструктор для инициализации добаки к напитку
    */
    Milk(Beverage* b) : CondimentDecorator(b) {}
    /**
    * \brief Функция для получения названия напитка с добавкой
    * \return string - Возвращает название напитка с добавкой
    */
    string getDescription() override { return beverage->getDescription() + " Молоко"; }
    /**
    * \brief Функция для получения цену напитка с добавкой
    * \return double - Возвращает цену напитка с добавкой
    */
    double cost() override { return beverage->cost() + 10; }
};

/// @brief Класс для добавления "Сахара"
class Sugar : public CondimentDecorator
{
public:
    /**
    * @brief Конструктор для инициализации добаки к напитку
    */
    Sugar(Beverage* b) : CondimentDecorator(b) {}
    /**
    * \brief Функция для получения названия напитка с добавкой
    * \return string - Возвращает название напитка с добавкой
    */
    string getDescription() override { return beverage->getDescription() + " Сахар"; }
    /**
    * \brief Функция для получения цену напитка с добавкой
    * \return double - Возвращает цену напитка с добавкой
    */
    double cost() override { return beverage->cost() + 5.99; }
};

/// @brief Класс для добавления "Сиропа"
class Syrup : public CondimentDecorator
{
public:
    /**
    * @brief Конструктор для инициализации добаки к напитку
    */
    Syrup(Beverage* b) : CondimentDecorator(b) {}
    /**
    * \brief Функция для получения названия напитка с добавкой
    * \return string - Возвращает название напитка с добавкой
    */
    string getDescription() override { return beverage->getDescription() + " Сироп"; }
    /**
    * \brief Функция для получения цену напитка с добавкой
    * \return double - Возвращает цену напитка с добавкой
    */
    double cost() override { return beverage->cost() + 6.6; }
};

/// @brief Класс для добавления "Льда"
class Ice : public CondimentDecorator
{
public:
    /**
    * @brief Конструктор для инициализации добаки к напитку
    */
    Ice(Beverage* b) : CondimentDecorator(b) {}
    /**
    * \brief Функция для получения названия напитка с добавкой
    * \return string - Возвращает название напитка с добавкой
    */
    string getDescription() override { return beverage->getDescription() + " Лёд"; }
    /**
    * \brief Функция для получения цену напитка с добавкой
    * \return double - Возвращает цену напитка с добавкой
    */
    double cost() override { return beverage->cost() + 2.5; }
};

/// @brief Класс для добавления "Картинки на кофе"
class PictureOnCoffee : public CondimentDecorator
{
public:
    /**
    * @brief Конструктор для инициализации добаки к напитку
    */
    PictureOnCoffee(Beverage* b) : CondimentDecorator(b) {}
    /**
    * \brief Функция для получения названия напитка с добавкой
    * \return string - Возвращает название напитка с добавкой
    */
    string getDescription() override { return beverage->getDescription() + " Картинка на кофе"; }
    /**
    * \brief Функция для получения цену напитка с добавкой
    * \return double - Возвращает цену напитка с добавкой
    */
    double cost() override { return beverage->cost() + 28.8; }
};

/// @brief Класс для добавления "Шоколада"
class Chocolate : public CondimentDecorator
{
public:
    /**
    * @brief Конструктор для инициализации добаки к напитку
    */
    Chocolate(Beverage* b) : CondimentDecorator(b) {}
    /**
    * \brief Функция для получения названия напитка с добавкой
    * \return string - Возвращает название напитка с добавкой
    */
    string getDescription() override { return beverage->getDescription() + " Шоколад"; }
    /**
    * \brief Функция для получения цену напитка с добавкой
    * \return double - Возвращает цену напитка с добавкой
    */
    double cost() override { return beverage->cost() + 20.4; }
};

/// @brief Функция для запуска конвеера
/// \note Используется для учебного кода
int main()
{
    setlocale(0, "");

    Beverage* drink = new Espresso;
    drink = new Milk(drink);
    drink = new Sugar(drink);
    drink = new Syrup(drink);
    drink = new Chocolate(drink);

    cout << drink->getDescription() << " стоит " << drink->cost() << " Р." << endl;

    Beverage* drink2 = new Latte;
    drink2 = new Milk(drink2);
    drink2 = new Sugar(drink2);

    cout << drink2->getDescription() << " стоит " << drink2->cost() << " Р." << endl;

    Beverage* drink3 = new Capuchino;
    drink3 = new Ice(drink3);
    drink3 = new PictureOnCoffee(drink3);

    cout << drink3->getDescription() << " стоит " << drink3->cost() << " Р." << endl;
    
    Beverage* drink4 = new Tea;
    drink4 = new Milk(drink4);
    drink4 = new Syrup(drink4);

    cout << drink4->getDescription() << " стоит " << drink4->cost() << " Р." << endl;

}
