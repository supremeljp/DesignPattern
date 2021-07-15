#include <vector>
// 进度通知抽象接口
class IProgress
{
public:
    virtual ~IProgress() {}
    virtual void DoProgress() = 0;
};

// 使用进度通知的具体类
class FileFilter
{
public:
    FileFilter(IProgress* progress) :m_progress(progress)
    {

    }
    void Func()
    {
        if(m_progress != nullptr)
        {
            m_progress->DoProgress();
        }
    }
protected:
    IProgress* m_progress;
};

// MFC框架类
class Form
{
    //...
};
class MainForm :public Form, public IProgress
{
    // 需要定义一个进度通知,如果依赖一个进度控件则违背了依赖倒置原则.
public:
    void Func()
    {
        FileFilter filefilter(this);
        filefilter.Func();
    }
    virtual void DoProgress()
    {
        //...
    }
};