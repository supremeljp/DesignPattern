class Visitor;

class Element
{
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Element() {}
};

class ElementA :public Element
{
public:
    void accept(Visitor& visitor)
    {
        visitor.visitElementA(*this);
    }
};

class ElementB :public Element
{
public:
    void accept(Visitor& visitor)
    {
        visitor.visitElementB(*this);
    }
};

class Visitor
{
public:
    virtual void visitElementA(Element& element) = 0;
    virtual void visitElementB(Element& element) = 0;
};

class VisitorA: public Visitor
{
public:
    void visitElementA(Element& element) {}
    void visitElementB(Element& element) {}
};