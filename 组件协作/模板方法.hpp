class Library
{
public:
    Library() {}
    virtual ~Library() {}
    void Run()
    {
        Step1();
        Step2();
        Step3();
        Step4();
        Step5();
    }

protected:
    void Step1() {}
    void Step3() {}
    void Step5() {}

    virtual void Step2() = 0;
    virtual void Step4() = 0;
};

class Application :public Library
{
public:
    Application() {}
    ~Application() {}
protected:
    void Step2() {}
    void Step4() {}
};

int main()
{
    Library* p = new Application();
    p->Run();
    delete p;
    return 0;
}