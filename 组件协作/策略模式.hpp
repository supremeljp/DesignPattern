class TaxStrategy
{
public:
    virtual double Calculate(const double&) = 0;
    virtual ~TaxStrategy() {}
};

class CNTax :public TaxStrategy
{
public:
    double Calculate(const double&) {}
    ~CNTax() {}
};