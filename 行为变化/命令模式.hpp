#include <list>

class Command
{
public:
    virtual void execute() = 0;
};

class Command1 :public Command
{
public:
    Command1() {}
    void execute() {}
};

class Command2 :public Command
{
public:
    Command2() {}
    void execute() {}
};

class macro
{
public:
    macro() {}
    void add(Command* p) {list.push_back(p);};
    void execute()
    {
        for(auto& command : list)
        {
            command->execute();
        }
    }
private:
    std::list<Command*> list;
};