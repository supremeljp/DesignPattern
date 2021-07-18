class ISplitter
{
public:
    virtual void Splitter() = 0;
    virtual ~ISplitter() {}
};

class BinaryFileSplitter :public ISplitter
{
    public:
    virtual void Splitter() {}
};

class PictureSplitter :public ISplitter
{
public:
    virtual void Splitter() {}
};

class Factory
{
public:
    virtual ISplitter* GetSpliiter() = 0;
};

class BinaryFactory :public Factory
{
public:
    virtual ISplitter* GetSpliiter()
    {
        return new BinaryFileSplitter();
    }
};

class MainForm
{
public:
    MainForm(Factory* factory)
    {
        this->factory = factory;
    }

    void Func()
    {
        auto splitter = factory->GetSpliiter();
    }
private:
    Factory* factory;
};