#include <iostream>
#include <string>

using namespace std;


class Product{

    public:
    virtual ~Product(){};
    virtual string Operation() const = 0;

};

class ConcreteProduct1 : public Product{};

class ConcreteProduct2 : public Product{};

class Creator{};

class ConcreteCreator1 : public Creator{};

class ConcreteCreator2 : public Creator{};

