/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class IObject
{
    public:
    virtual ~IObject();
    virtual void stamp() = 0;
};

IObject::~IObject(){}

class IntObject : public IObject
{
    int intero;
    public:
    IntObject(int a) {intero = a;}
    ~IntObject(){}
    void stamp();
};
void IntObject::stamp(){cout<<"l'intero e': "<<intero<<endl;}

class CharObject : public IObject
{
    char carattere;
    public:
    CharObject(char a) {carattere = a;}
    ~CharObject(){}
    void stamp();
};

void CharObject::stamp(){cout<<"il carattere e': "<<carattere<<endl;}

class CharIntObject : public IObject
{
    int intero;
    char carattere;
    public:
    CharIntObject(int a, char b) {intero = a; carattere = b;}
    ~CharIntObject(){}
    void stamp();
};

void CharIntObject::stamp(){cout<<"l'intero e': "<<intero<<"  il carattere e': "<<carattere<<endl;}

IObject* createObject()
{
  return nullptr;
}

IObject* createObject(int a)
{
    return new IntObject(a);
}

IObject* createObject(char a)
{
    return new CharObject(a);
}

IObject* createObject(int a, char b)
{
    return new CharIntObject(a,b);
}

template<typename T>
IObject* createObject()
{
    return new T();
}

template<>
IObject* createObject<IntObject>()
{
    return new IntObject(2);
}


int main()
{
    cout<<"Hello World"<<endl;

    IObject* intero = createObject(1);
    IObject* carattere = createObject('a');
    IObject* interocarattere = createObject(1,'a');

    intero->stamp();
    carattere->stamp();
    interocarattere->stamp();

    IObject* temp1 = createObject<IntObject>();
    temp1->stamp();

    return 0;
}
