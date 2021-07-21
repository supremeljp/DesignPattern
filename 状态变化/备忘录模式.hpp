#include <string>

class Memento
{
public:
    Memento(const std::string& str) :state(str) {}
    std::string GetState() const {return state;}
    void SetState(const std::string& str) {state = str;}
private:
    std::string state;
};

class Originator
{
public:
    Originator() {}
    Memento CreateMemento()
    {
        return Memento(state);
    }
    void SetState(const Memento& m)
    {
        state = m.GetState();
    }
private:
    std::string state;
};

int main()
{
    Originator o;
    Memento m = o.CreateMemento();
    //...
    o.SetState(m);
}