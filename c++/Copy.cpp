#include <iostream>

class HasPtr{
public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { }
        HasPtr(HasPtr &hasptr);
        //HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
        HasPtr& operator=(const HasPtr &hasptr);
        ~HasPtr(){ delete ps; }
private:
        std::string *ps;
        int i;
};

class numbered
{
public:
        numbered() { mysn = unique++; }
        numbered(const numbered& temp) { mysn = unique++; }
        
        void f(numbered s) { std::cout << s.mysn << std::endl; }
        //void f(numbered &s) { std::cout << s.mysn << std::endl; }

private:
        int mysn;
        static int unique ;
};

class Employee
{
public:
        Employee() { id = number++; };
        Employee(const std::string &n) : name(n) { id = number++; }
        Employee(const Employee& em) : name(em.name), id(em.id) { }
private:
        std::string name;
        int id;
        static int number;
};

int Employee::number = 777;

int numbered::unique = 1;

HasPtr::HasPtr(HasPtr &hasptr)
{
        i = hasptr.i;
        ps = new std::string(*hasptr.ps);
}

HasPtr& HasPtr::operator= (const HasPtr &hasptr)
{
        i = hasptr.i;
        std::string *temp_ps = new std::string(*hasptr.ps);
        delete ps;
        ps = temp_ps;

        return *this;
}

void func()
{
        numbered a, b = a, c = b;
        a.f(a);
        b.f(b);
        c.f(c);
}

int main()
{
        func();

        return 0;
}