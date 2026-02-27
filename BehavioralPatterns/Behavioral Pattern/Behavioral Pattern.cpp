#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// @brief Класс компьютерной системы (получатель команд)
/// \details Содержит методы, которые будут вызываться командами
/// \note Является "получателем" (Receiver) в паттерне Команда
class ComputerSystem
{
public:
    void openFile(const string& path) { cout << "Открываем файл по пути: " << path << endl; }
    void reload() { cout << "Перезагружаем компьютер" << endl; }
    void launchBrowser() { cout << "Запускаем Браузер" << endl; }
    void launchPaint() { cout << "Запускаем пейнт" << endl; }
};

/// @brief Абстрактный класс команды
/// \details Определяет интерфейс для всех конкретных команд
/// \note Является "Командой" (Command) в паттерне Команда
class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

/// @brief Команда открытия файла
/// \details Конкретная команда, инкапсулирующая запрос на открытие файла
/// \note Является "Конкретной командой" (ConcreteCommand) в паттерне Команда
class OpenFileCommand : public Command
{
private:
    ComputerSystem* system;  
    string path;             
public:
    /**
    * @brief Конструктор команды открытия файла
    * @param s Указатель на компьютерную систему
    * @param fn Путь к файлу
    */
    OpenFileCommand(ComputerSystem* s, const string& fn) : system(s), path(fn) {}

    /**
    * @brief Выполнение команды открытия файла
    */
    void execute() override { system->openFile(path); }

    /**
    * @brief Отмена команды открытия файла
    * \details В данном случае просто выводит сообщение о закрытии файла
    */
    void undo() override { cout << "Закрываем файл по пути: " << path << endl; }
};

/// @brief Команда перезагрузки компьютера
/// \details Конкретная команда, инкапсулирующая запрос на перезагрузку
class ReloadCommand : public Command
{
private:
    ComputerSystem* system;  
    string fileName;         
public:
    /**
    * @brief Конструктор команды перезагрузки
    * @param s Указатель на компьютерную систему
    */
    ReloadCommand(ComputerSystem* s) : system(s) {}

    /**
    * @brief Выполнение команды перезагрузки
    */
    void execute() override { system->reload(); }

    /**
    * @brief Отмена команды перезагрузки
    * \details Показывает, что отмена перезагрузки может быть невозможна из-за запущенных файлов
    */
    void undo() override { cout << "Отмена. Есть запущенные файлы, которые не дают перезапуститься" << endl; }
};

/// @brief Команда запуска браузера
/// \details Конкретная команда, инкапсулирующая запрос на запуск браузера
class LaunchBrowserCommand : public Command
{
private:
    ComputerSystem* system; 
    string fileName;         
public:
    /**
    * @brief Конструктор команды запуска браузера
    * @param s Указатель на компьютерную систему
    */
    LaunchBrowserCommand(ComputerSystem* s) : system(s) {}

    /**
    * @brief Выполнение команды запуска браузера
    */
    void execute() override { system->launchBrowser(); }

    /**
    * @brief Отмена команды запуска браузера
    */
    void undo() override { cout << "Закрываем браузер" << endl; }
};

/// @brief Команда запуска Paint
/// \details Конкретная команда, инкапсулирующая запрос на запуск графического редактора
class LaunchPaintCommand : public Command
{
private:
    ComputerSystem* system;  
    string fileName;         
public:
    /**
    * @brief Конструктор команды запуска Paint
    * @param s Указатель на компьютерную систему
    */
    LaunchPaintCommand(ComputerSystem* s) : system(s) {}

    /**
    * @brief Выполнение команды запуска Paint
    */
    void execute() override { system->launchPaint(); }

    /**
    * @brief Отмена команды запуска Paint
    */
    void undo() override { cout << "Закрываем пейнт" << endl; }
};

/// @brief Класс пульта управления (инициатор команд)
/// \details Хранит и выполняет команды, поддерживает отмену последней команды
/// \note Является "Инициатором" в паттерне Команда
class RemoteControl
{
private:
    vector<Command*> commands;
public:
    /**
    * @brief Добавление команды в список
    * @param cmd Указатель на команду для добавления
    */
    void addCommand(Command* cmd) { commands.push_back(cmd); }

    /**
    * @brief Выполнение всех добавленных команд
    * \details Последовательно выполняет все команды из списка
    */
    void pressButton()
    {
        for (auto cmd : commands)
        {
            cmd->execute();
        }
    }

    /**
    * @brief Отмена последней выполненной команды
    * \details Вызывает метод undo у последней команды и удаляет её из списка
    */
    void undoLast()
    {
        if (!commands.empty())
        {
            commands.back()->undo();
            commands.pop_back();
        }
    }
};

/// @brief Точка входа в программу
/// \details Демонстрирует работу паттерна "Команда" на примере управления компьютером
/// \note Используется для учебного кода
int main()
{
    setlocale(0, "");  
    ComputerSystem system; 

    Command* openCmd = new OpenFileCommand(&system, "C:/User/source/repos/code.cpp");
    Command* reloadCmd = new ReloadCommand(&system);
    Command* browserCmd = new LaunchBrowserCommand(&system);
    Command* paintCmd = new LaunchPaintCommand(&system);

    RemoteControl remote;
    remote.addCommand(openCmd);
    remote.addCommand(browserCmd);
    remote.addCommand(paintCmd);
    remote.addCommand(reloadCmd);

    remote.pressButton();

    remote.undoLast();

    delete openCmd;
    delete browserCmd;
    delete reloadCmd;
    delete paintCmd;
}
