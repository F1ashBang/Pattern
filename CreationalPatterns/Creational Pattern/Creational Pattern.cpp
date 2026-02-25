#include <iostream>
#include <string>

using namespace std;

class Character
{
public:
    virtual string getType() = 0;
    virtual void attak() = 0;
    virtual int getHealth() = 0;
};

class Warrior : public Character
{
public:
    string getType() override { return "Воин"; }
    void attak() override { cout << "Воин аттакует мечом!" << endl; }
    int getHealth() override { return 100; }
};

class Knight : public Character
{
public:
    string getType() override { return "Рыцарь"; }
    void attak() override { cout << "Рыцарь атакует копьём!" << endl; }
    int getHealth() override { return 80; }
};

class Mage : public Character
{
public:
    string getType() override { return "Маг"; }
    void attak() override { cout << "Маг кастует заклинание!" << endl; }
    int getHealth() override { return 50; }
};

class Archer : public Character
{
public:
    string getType() override { return "Лучник"; }
    void attak() override { cout << "Лучник стреляет из лука!" << endl; }
    int getHealth() override { return 70; }
};

class CharacterFactory 
{
public:
    virtual Character* createHero() = 0;
    void spawnAndAttak()
    {
        Character* charact = createHero();
        cout << "Создан " << charact->getType() << " со здоровьем " << charact->getHealth() << ". ";
        charact->attak();
        delete charact;
    }
};

class WarriorFactory : public CharacterFactory
{
public:
    Character* createHero() override { return new Warrior(); }
};
class KnightFactory : public CharacterFactory
{
public:
    Character* createHero() override { return new Knight(); }
};

class MageFactory : public CharacterFactory
{
public:
    Character* createHero() override { return new Mage(); }
};

class ArcherFactory : public CharacterFactory
{
public:
    Character* createHero() override { return new Archer(); }
};

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
