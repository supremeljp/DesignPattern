class IDBConnection
{

};

class IDBCommand
{

};

class IDBExecution
{

};

class IDBFactory
{
public:
    virtual IDBConnection* CreateConnect() = 0;
    virtual IDBCommand* CreateCommand() = 0;
    virtual IDBExecution* CreateExecution() = 0;
    virtual ~IDBFactory() {}
};