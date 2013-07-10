#include <stdio.h>

class ReferenceCount
{
public:
    virtual ~ReferenceCount(){printf("base Ref destructor\n");};
    int Count;
    virtual void func(){printf("base virtual func\n");}
protected:
    ReferenceCount():Count(0){};
};

class Intrusive: public ReferenceCount
{
public:
    Intrusive()
    {
        printf("\nInstrusive Construct\n");
    }
    
    ~Intrusive()
    {
        printf("\nInstrusive Destruct\n");
    }
    void func(){printf("instrusive virtual func\n");}
};


class B: public ReferenceCount
{
public:
    B()
    {
        printf("\nB Construct\n");
    }
    
    ~B()
    {
        printf("\nB Destruct\n");
    }
    virtual void func(){printf("b virtual func\n");}
};

template <typename T>
class SmartPtrIntrusive
{
public:
    SmartPtrIntrusive(T *t)
    {
        Pointee = t;
        ++Pointee->Count;
    }
    
    SmartPtrIntrusive(const SmartPtrIntrusive &sp)
    {
        Pointee = sp.Pointee;
        ++Pointee->Count;
    }
    
    SmartPtrIntrusive& operator = (const SmartPtrIntrusive &sp)
    {
        if(NULL != Pointee)
            --Pointee->Count;
        if(Pointee->Count == 0)
        {
            delete Pointee;
            Pointee = NULL;
        }
        
        Pointee = sp.Pointee;
        ++Pointee->Count;
        
        return *this;
    }
    
    SmartPtrIntrusive& operator = (T *t)
    {
        if(NULL != Pointee)
            --Pointee->Count;
        if(Pointee->Count == 0)
        {
            delete Pointee;
            Pointee = NULL;
        }

        Pointee = t;
        ++Pointee->Count;
        
        return *this;
    }
    
    ~SmartPtrIntrusive()
    {
        if(NULL != Pointee)
            --Pointee->Count;
        if(Pointee->Count == 0)
        {
            delete Pointee;
            Pointee = NULL;
        }
    }
private:
    T *Pointee;
    SmartPtrIntrusive();
};

int main()
{
    Intrusive *obj1 = new Intrusive();
    Intrusive *obj2 = new Intrusive();
    Intrusive *obj3 = new Intrusive();
    B *objB1 = new B();
    B *objB2 = new B();
    B *objB3 = new B();
    
    SmartPtrIntrusive<Intrusive> sPtr1(obj1);
    SmartPtrIntrusive<Intrusive> sPtr2(obj2);
    sPtr1 = sPtr2;
    sPtr1 = obj3;
    sPtr2 = obj3;
    
    SmartPtrIntrusive<B> sPtrB1(objB1);
    SmartPtrIntrusive<B> sPtrB2(objB2);
    sPtrB1 = sPtrB2;
    sPtrB1 = objB3;
    sPtrB2 = objB3;
    
    return 0;
}
