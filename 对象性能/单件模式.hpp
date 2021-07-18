#include <atomic>
#include <mutex>
class Singleton
{
public:
    static Singleton* GetInstance();
    // static Singleton* m_instance;
    static std::atomic<Singleton*> Singleton::m_instance;

private:
    static std::mutex mut;
    Singleton() {}
    Singleton(const Singleton& other) {}
};

// Singleton* Singleton::m_instance = nullptr;

// 非线程安全版本
// Singleton* Singleton::GetInstance()
// {
//     if(m_instance == nullptr)
//     {
//         m_instance = new Singleton();
//     }
//     return m_instance;
// }

// 线程安全版本,但是锁的代价很高
// Singleton* Singleton::GetInstance()
// {
//     std::lock_guard lk(mut);
//     if(m_instance == nullptr)
//     {
//         m_instance = new Singleton();
//     }
//     return m_instance;
// }

// 双检查锁,但由于内存读写reorder不安全
// Singleton* Singleton::GetInstance()
// {
//     if(m_instance == nullptr)
//     {
//         std::lock_guard lk(mut);
//         if(m_instance == nullptr)
//         {
//             m_instance = new Singleton();
//         }        
//     }
//     return m_instance;
// }

// c++11
Singleton* Singleton::GetInstance()
{
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if(tmp == nullptr)
    {
        std::lock_guard<std::mutex> lock(mut);
        tmp = m_instance.load(std::memory_order_relaxed);
        if(tmp == nullptr)
        {
            tmp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release);
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}