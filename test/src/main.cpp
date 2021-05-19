#include <iostream>
#include <cstdio>
#include <functional>
#include "terminal_ui.h"

int main()
{
    tui::tui_getch test_getch = []() { return (char)getchar(); };
    tui::tui_putch test_putch = [](const char& c) { putchar(c); return true; };
    
    tui::set_getch(test_getch);
    tui::set_putch(test_putch);
    
    char in;
    tui::read(&in, 1);
    
    std::cout << "Read character: " << in << std::endl;
}