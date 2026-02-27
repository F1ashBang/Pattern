#include <iostream>
#include <string>

using namespace std;

/// @breaf Интрерфейс для персонажей

class Character
{
public:
    virtual string getType() = 0;
    virtual void attak() = 0;
    virtual int getHealth() = 0;
};

/// @breaf Класс с настройками для персонажа "Воин"
class Warrior : public Character
{
public:
    /**
    * \brief Функция для получения типа персонажа
    * \return string - название персонажа
    * \remark Получаем только имя персонажа, т.к. это учебный код
    */
    string getType() override { return "Воин"; }
    /**
    * \breaf Функция для выполнения действий персонажа
    * \note Не влияет ни на что, это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого напали
    */
    void attak() override { cout << "Воин аттакует мечом!" << endl; }
    /**
    * \breaf Функция для получения HP(Hit Points) персонажа
    * \return int - HP(Hit Points) персонажа
    */
    int getHealth() override { return 100; }
};

/// @breaf Класс с настройками для персонажа "Рыцарь"
class Knight : public Character
{
public:
    /**
    * \brief Функция для получения типа персонажа
    * \return string - название персонажа
    * \remark Получаем только имя персонажа, т.к. это учебный код
    */
    string getType() override { return "Рыцарь"; }
    /**
    * \breaf Функция для выполнения действий персонажа
    * \note Не влияет ни на что, это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого напали
    */
    void attak() override { cout << "Рыцарь атакует копьём!" << endl; }
    /**
    * \breaf Функция для получения HP(Hit Points) персонажа
    * \return int - HP(Hit Points) персонажа
    */
    int getHealth() override { return 80; }
};

/// @breaf Класс с настройками для персонажа "Маг"
class Mage : public Character
{
public:
    string getType() override { return "Маг"; }
    /**
    * \breaf Функция для выполнения действий персонажа
    * \note Не влияет ни на что, это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого напали
    */
    void attak() override { cout << "Маг кастует заклинание!" << endl; }
    /**
    * \breaf Функция для получения HP(Hit Points) персонажа
    * \return int - HP(Hit Points) персонажа
    */
    int getHealth() override { return 50; }
};

/// @breaf Класс с настройками для персонажа "Лучник"
class Archer : public Character
{
public:
    /**
    * \brief Функция для получения типа персонажа
    * \return string - название персонажа
    * \remark Получаем только имя персонажа, т.к. это учебный код
    */
    string getType() override { return "Лучник"; }
    /**
    * \breaf Функция для выполнения действий персонажа
    * \note Не влияет ни на что, это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого напали
    */
    void attak() override { cout << "Лучник стреляет из лука!" << endl; }
    /**
    * \breaf Функция для получения HP(Hit Points) персонажа
    * \return int - HP(Hit Points) персонажа
    */
    int getHealth() override { return 70; }
};

/**
* \brief Абстрактная фабрика для генерации персонажей
* \note Используется для примера работы паттерна порождающего Creational
*/
class CharacterFactory 
{
public:
    virtual Character* createHero() = 0;
    /**
    * \brief Функция для создания персонажей и выполнения его базовых действий
    * \note После создания объекта выполняет действие персонажа и уничтожает объект
    * \warning Нельзя будет использовать созданных персонажей в других частях кода
    */
    void spawnAndAttak()
    {
        Character* charact = createHero();
        cout << "Создан " << charact->getType() << " со здоровьем " << charact->getHealth() << ". ";
        charact->attak();
        delete charact;
    }
};

/// @brief класс для создания "Война"
class WarriorFactory : public CharacterFactory
{
public:
    /**
    * \brief Функция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа 
    */
    Character* createHero() override { return new Warrior(); }
};

/// @brief класс для создания "Рыцаря"
class KnightFactory : public CharacterFactory
{
public:
    /**
    * \brief Функция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createHero() override { return new Knight(); }
};

/// @brief класс для создания "Мага"
class MageFactory : public CharacterFactory
{
public:
    /**
    * \brief Функция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createHero() override { return new Mage(); }
};

/// @brief класс для создания "Лучника"
class ArcherFactory : public CharacterFactory
{
public:
    /**
    * \brief Функция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createHero() override { return new Archer(); }
};

/// @brief Функция для запуска конвеера
/// \note Используется для учебного кода
int main()
{
    setlocale(0, "");

    CharacterFactory* factory = new WarriorFactory();
    factory->spawnAndAttak();

    factory = new MageFactory();
    factory->spawnAndAttak();

    factory = new ArcherFactory();
    factory->spawnAndAttak();

    factory = new KnightFactory();
    factory->spawnAndAttak();
}
