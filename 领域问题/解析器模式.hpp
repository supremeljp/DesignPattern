#include <map>
#include <list>
#include <stack>
#include <string>

class Expression
{
public:
    virtual int interpreter(std::map<char, int> var) = 0;
};

class VarExpression :public Expression
{
public:
    VarExpression(const char& key)
    {
        this->key = key;
    }
    int interpreter(std::map<char, int> var)
    {
        return var[key];
    }
private:
    char key;
};

class SymbolExpression :public Expression
{
public:
    SymbolExpression(Expression* left, Expression* right) :left(left), right(right) {}
protected:
    Expression* left = nullptr;
    Expression* right = nullptr;
};

class AddExpression :public SymbolExpression
{
public:
    AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right) {}
    int interpreter(std::map<char, int> var)
    {
        return left->interpreter(var) + right->interpreter(var);
    }
};

class SubExpression :public SymbolExpression
{
public:
    SubExpression(Expression* left, Expression* right) :SymbolExpression(left, right) {}
    int interpreter(std::map<char, int> var)
    {
        return left->interpreter(var) - right->interpreter(var);
    }
};

Expression* analyse(std::string expr)
{
    std::stack<Expression*> expstack;
    Expression* left = nullptr;
    Expression* right = nullptr;
    for(int i = 0; i < expr.size(); i++)
    {
        switch(expr[i])
        {
            case '+':
            {
                left = expstack.top();
                right = new VarExpression(expr[++i]);
                expstack.push(new AddExpression(left, right));
                break;
            }
            case '-':
            {
                left = expstack.top();
                right = new VarExpression(expr[++i]);
                expstack.push(new SubExpression(left, right));
                break;
            }
            default:
            {
                expstack.push(new VarExpression(expr[i]));
                break;
            }
        }
    }
    return expstack.top();
}

void release(Expression* expression)
{
    //...
}

int main()
{
    std::string expr = "a+b-c+d";
    std::map<char, int> var;
    var.insert(std::make_pair('a', 5));
    var.insert(std::make_pair('b', 2));
    var.insert(std::make_pair('c', 1));
    var.insert(std::make_pair('d', 6));
    Expression* expression = analyse(expr);
    int result = expression->interpreter(var);
    release(expression);
}