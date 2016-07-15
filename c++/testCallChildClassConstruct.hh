#if !defined(TEST_CALL_CONSTRUCT)
#define TEST_CALL_CONSTRUCT

class Parent
{
public:
    Parent();
    virtual ~Parent();
    
    void testCallCheck();

private:
    virtual void testCheck();
    
};

class Child : public Parent
{
public:
    Child();
    virtual ~Child();

private:
    virtual void testCheck();
};

#endif // end TEST_CALL_CONSTRUCT