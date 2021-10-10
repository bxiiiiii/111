#include <iostream>
#include <iterator>
#include <functional>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

template <typename T>
int compare(const T &i1, const T &i2)
{
    if(i1 < i2) return -1;
    if(i1 > i2) return 1;

    return 0;
}

template <typename Iterator, typename Value>
Iterator find(Iterator first, Iterator end, const Value &v)
{
    for(auto i = first; i != end; i++){
        if(*i == v)
            return i;
    }
    return end;

    /*
    for( ; first != end && *first != value; first++);
    return first;
    */
}

template <typename T>
void print(const T& arr)
{
    for(auto &i : arr)
        std::cout << i << std::endl;
}

template <typename T, unsigned t>
T* begin(const T (&arr)[t])
{
    return arr;
}

template <typename T, unsigned t>
T* end(const T (&arr)[t])
{
    return arr + t;
}

template <typename T, unsigned t>
unsigned size(const T (&arr)[t])
{
    return t;
}

template <unsigned w, unsigned h>
class Screen{
public:
    typedef std::string::size_type pos;
    Screen() = default;
private:
    pos cursor = 0;
    pos height = h, width = w;
    std::string contents;
};

template <typename Container>
void print1(const Container& c)
{
    for(typename Container::size_type i = 0; i != c.size(); i++)
        cout << c[i] << " ";
}

template <typename T>
void print2(const T &c)
{
    for(auto i = c.begin(); i != c.end(); i++)
        cout << *i << " ";
}

class DebugDelete{
public:
    DebugDelete(ostream &s = cerr) : os(s) {}
    template<typename T> void operator() (T *p) const
        { os << "deleting unique_ptr" << endl; delete p; }

private:
    ostream &os;
};
/*
namespace cp
{
    template<typename T>
    class SharedPointer;

    template<typename T>
    auto swap(SharedPointer<T> &lhs, SharedPointer<T> &rhs){
        using std::swap;
        swap(lhs.ptr, rhs.ptr);
        swap(lhs.ref_count, rhs.ref_count);
        swap(lhs.deleter, rhs.deleter);

   }

    template<typename T>
    class SharedPointer
    {
    public:
            SharedPointer() 
                    : ptr(nullptr), ref_count(new std::size_t(1)), deleter{ cp::Delete{} }
            {}

            explicit SharedPointer(T* raw_ptr)
                    : ptr{ raw_ptr }, ref_count(new std::size_t(1)), deleter{ cp::Delete{} }
            {}
            
            SharedPointer(SharedPointer const& other)
                    : ptr{ other.ptr }, ref_count{ other.ref_count }, deleter{ other.deleter}
            {}

            SharedPointer(SharedPointer&& other) noexcept
                    : ptr(other.ptr), ref_count(other.ref_count), deleter(std::move(other.deleter))
            {
                other.ptr = nullptr;
                other.ref_count = nullptr;
            }

            SharedPointer& operator= (SharedPointer const& rhs)
            {
                ++*rhs.ref_count;
                decrement_and_destroy();
                ptr = rhs.ptr;
                ref_count = rhs.ref_count;
                deleter = rhs.deleter;
                return *this;
            }

            SharedPointer& operator=(SharedPointer&& rhs) noexcept
            {
                cp::swap(*this, rhs);
                rhs.decrement_and_destroy();
                return *this;
            }

            operator bool() const
            {
                return ptr ? true : false;
            }

            T& operator*() const
            {
                return *ptr;
            }

            T* operator->() const
            {
                return &*ptr;
            }

            auto use_count() const
            {
                return *ref_count;
            }

            auto get() const
            {
                return ptr;
            }

            auto unique() const
            {
                return 1 == *ref_count;
            }

            auto swap(SharedPointer& rhs)
            {
                cp::swap(*this, rhs);
            }

            auto reset()
            {
                decrement_and_destroy();
            }

            auto reset(T* pointer)
            {
                if(ptr != pointer){
                    decrement_and_destroy();
                    ptr = pointer;
                    ref_count = new std::size_t(1);
                }
            }

            auto reset(T* pointer, const std::function<void(T*)>& d)
            {
                reset(pointer);
                deleter = d;
            }

            ~SharedPointer()
            {
                decrement_and_destroy();
            }

    private:
            T* ptr;
            std::size_t* ref_count;
            std::function<void(T*)> deleter;

            void decrement_and_destroy()
            {
                if(ptr && 0 == --*ref_count){
                    delete ref_count;
                    deleter(ptr);
                }else if(!ptr)
                    delete ref_count;
                ref_count = nullptr;
                ptr = nullptr;
            }
    };
}*/




template <typename T>
int f(vector<T> vec, T tag)
{
    int count = 0;
    for(auto i : vec)
        if(tag == i)
            count++;
    return count;
}

template <> int f(vector<const char*> vec, const char* value)
{
    auto count = 0;
    for(auto i : vec)
        if(strcmp(value, i) == 0)
            count++;
    return count;
}

template <typename T> string debug_rep(T* t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <> string debug_rep (const char* str)
{
    string ret(str);
    return ret;
}

template <> string debug_rep(char* str)
{
    string ret(str);
    return ret;
}

int main()
{
    int x = 123;
    string str = debug_rep(&x);
    cout << str << endl;

    return 0;
}