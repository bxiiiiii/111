#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr
{
public:
        //typedef std::vector<Screen>::size_type ScreenIndex;
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
        ScreenIndex addScreen(const Screen&);

private:
        std::vector<Screen> screens;
};

class Screen
{
        friend void Window_mgr::clear(ScreenIndex);
public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(const pos &h, const pos &w) :
                                height(h), width(w), str(h*w, ' ') { }
        Screen(const pos &h, const pos &w, const char &c) :
                                height(h), width(w), str(h*w, c) { }
        Screen &move(pos r, pos c)
        {
            pos row = r * width;
            location = r + c;
            return *this;
        }
        Screen &set(char c)
        {
            str[location] = c;
            return *this;
        }
        Screen &set(pos r, pos col, char ch)
        {
            str[r*width + col] = ch;
            return *this;
        }

private:
        std::string str;
        pos location = 0;
        pos height = 0, width = 0;
};

void Window_mgr::clear(ScreenIndex i)
{
        Screen &s = screens[i];
        s.str = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
        screens.push_back(s);
        return screens.size() - 1;
}

int main()
{
    return 0;
}