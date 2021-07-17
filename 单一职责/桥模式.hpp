class Message
{
public:
    Message(MessaageImp* p) :pMessageImp(p) {}
    virtual void Login() = 0;
    virtual void SendMessage() = 0;
    virtual void SendPicture() = 0;
    virtual ~Message() {}
protected:
    MessaageImp* pMessageImp;
};

class MessaageImp
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
};

class PCMessageImp :public MessaageImp
{
public:
    virtual void PlaySound() {}
    virtual void DrawShape() {}
    virtual void WriteText() {}
    virtual void Connect() {}
};

class MesssageLite :public Message
{
public:
    MesssageLite(MessaageImp* p) :Message(p) {}
    virtual void Login()
    {
        pMessageImp->Connect();
    }
    virtual void SendMessage()
    {
        pMessageImp->PlaySound();
    }
    virtual void SendPicture()
    {
        pMessageImp->DrawShape();
    }
};