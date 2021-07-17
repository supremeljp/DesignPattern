class Stream
{
public:
    virtual void Read(int number) = 0;
    virtual void Write(int number) = 0;
    virtual void Seek(int number) = 0;
    virtual ~Stream() {}
};

class FileSteam :public Stream
{
public:
    virtual void Read(int number) {}
    virtual void Write(int number) {}
    virtual void Seek(int number) {}
    ~FileSteam() {}
};

class NetStream :public Stream
{
public:
    virtual void Read(int number) {}
    virtual void Write(int number) {}
    virtual void Seek(int number) {}
    ~NetStream() {}
};

// 中间装饰类
class DecoratorClass :public Stream
{
public:
    DecoratorClass(Stream* p) :pStream(p) {}
    virtual ~DecoratorClass() {}
protected:
    Stream* pStream;
};

/*
*加密流:
*加密流可以分文件加密流和网络加密流等等,如果只是僵硬地继承FileStream或NetStream,子类的数目会指数增长
*因此此处既要继承基类的接口规范,又要使用上层接口的具体实现,即在加密文件流中[重用]文件流的接口操作.
*/

class CryFileStream :public DecoratorClass
{
public:
    CryFileStream(Stream* p) :DecoratorClass(p) {}
    ~CryFileStream() {}
    virtual void Read(int number)
    {
        pStream->Read(number);
        //加密操作
    }
    virtual void Write(int number)
    {
        pStream->Write(number);
        // 加密操作
    }
    virtual void Seek(int number)
    {
        pStream->Seek(number);
        // 加密操作
    }
};