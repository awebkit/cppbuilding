#ifndef libfoo_h
#define libfoo_h

#define TEST_GLOBAL 1

class libfoo{
public:
    libfoo();
    void increase1A();
    void getA();
    void increase2A();
private:
#if TEST_GLOBAL
    static int m_a;
#else
    int m_a;
#endif
};

#endif
