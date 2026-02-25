#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ComputerSystem
{
public:
    void openFile(const string& path) { cout << "Открываем файл по пути: " << path << endl; }
    void reload() { cout << "Перезагружаем компьютер" << endl; }
    void launchBrowser() { cout << "Запускаем Браузер" << endl; }
    void launchPaint() { cout << "Запускаем пейнт" << endl; }
};

class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class OpenFileCommand : public Command
{
private:
    ComputerSystem* system;
    string path;
public:
    OpenFileCommand(ComputerSystem* s, const string& fn) : system(s), path(fn) {}
    void execute() override { system->openFile(path); }
    void undo() override { cout << "Закрываем файл по пути: " << path << endl; }
};

class ReloadCommand : public Command
{
private:
    ComputerSystem* system;
    string fileName;
public:
    ReloadCommand(ComputerSystem* s) : system(s) {}
    void execute() override { system->reload(); }
    void undo() override { cout << "Отмена. Есть запущенные файлы, которые не дают перезапуститься" << endl; }
};

class LaunchBrowserCommand : public Command
{
private:
    ComputerSystem* system;
    string fileName;
public:
    LaunchBrowserCommand(ComputerSystem* s) : system(s) {}
    void execute() override { system->launchBrowser(); }
    void undo() override { cout << "Закрываем браузер" << endl; }
};

class LaunchPaintCommand : public Command
{
private:
    ComputerSystem* system;
    string fileName;
public:
    LaunchPaintCommand(ComputerSystem* s) : system(s) {}
    void execute() override { system->launchPaint(); }
    void undo() override { cout << "Закрываем пейнт" << endl; }
};


class RemoteControl
{
private:
    vector<Command*> commands;
public:
    void addCommand(Command* cmd) { commands.push_back(cmd); }
    void pressButton()
    {
        for (auto cmd : commands)
        {
            cmd->execute();
        }
    }
    void undoLast()
    {
        if (!commands.empty())
        {
            commands.back()->undo();
            commands.pop_back();
        }
    }
};

int main()
{
    setlocale(0, "");
    ComputerSystem system;

    Command* openCmd = new OpenFileCommand(&system, "C:/User/source/repos/code.cpp");
    Command* reloadCmd = new ReloadCommand(&system);
    Command* browserCmd = new LaunchBrowserCommand(&system);
    Command* PaintCmd = new LaunchPaintCommand(&system);

    RemoteControl remote;
    remote.addCommand(openCmd);
    remote.addCommand(browserCmd);
    remote.addCommand(PaintCmd);
    remote.addCommand(reloadCmd);

    remote.pressButton();
    remote.undoLast();

    delete openCmd;
    delete browserCmd;
    delete reloadCmd;
}