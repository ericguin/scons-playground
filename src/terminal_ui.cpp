#include "terminal_ui.h"

namespace tui
{
    static tui_getch fgetch = nullptr;
    static tui_putch fputch = nullptr;

    void set_getch(tui_getch f) { fgetch = f; }
    void set_putch(tui_putch f) { fputch = f; }
    
    void read(char* dest, int size)
    {
        for (int i = 0; i < size; i++)
        {
            *(dest++) = fgetch();
        }
    }
}