#include <list>
#include <string>

class Component
{
public:
    Component() {}
    virtual ~Component() {}
    virtual void process() = 0;
};

class Composite :public Component
{
public:
    Composite(const std::string& name) :name(name) {}
    void add(Component* element)
    {
        elements.push_back(element);
    }
    void remove(Component* element)
    {
        elements.remove(element);
    }
    void process()
    {
        for(auto& e : elements)
        {
            e->process();
        }
    }

private:
    std::string name;
    std::list<Component*> elements;
};

class Leaf :public Component
{
public:
    Leaf(const std::string& name) :name(name) {}
    void process()
    {

    }
private:
    std::string name;
};

void invoke(Component& c)
{
    c.process();
}

int main()
{
    Composite root("root");
    Composite node1("node1");
    Composite node2("node2");
    Leaf leaf1("leaf1");
    Leaf leaf2("leaf2");
    root.add(&node1);
    node1.add(&node2);
    node2.add(&leaf1);
    node2.add(&leaf2);

    invoke(root);

    return 0;
}