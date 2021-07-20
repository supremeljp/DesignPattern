class NetWorkState
{
public:
    NetWorkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;
    virtual ~NetWorkState() {}
};

class OpenState :public NetWorkState
{
public:
    static NetWorkState* GetInstance()
    {
        if(m_instance == nullptr)
        {
            m_instance = new OpenState();
        }
        return m_instance;
    }
    virtual void Operation1()
    {
        pNext = CloseState::GetInstance();
    }
    virtual void Operation2() {}
    virtual void Operation3() {}

private:
    static NetWorkState* m_instance;
};

class CloseState :public NetWorkState
{
public:
    static NetWorkState* GetInstance()
    {
        if(m_instance == nullptr)
        {
            m_instance = new CloseState();
        }
        return m_instance;
    }
    virtual void Operation1()
    {
        pNext = OpenState::GetInstance();
    }
    virtual void Operation2() {}
    virtual void Operation3() {}

private:
    static NetWorkState* m_instance;
};

class NetWorkProcessor
{
public:
    NetWorkProcessor(NetWorkState* pState)
    {
        this->pState = pState;
    }
    void Operation1()
    {
        pState->Operation1();
        pState = pState->pNext;
    }
private:
    NetWorkState* pState;
};