class ISPlitter
{
public:
    virtual void Split() = 0;
    virtual ISPlitter* clone() = 0;
    virtual ~ISPlitter() {}
};