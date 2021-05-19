namespace tui
{
    // Read function
    using tui_getch = char (*)(void);
    
    // Write function
    using tui_putch = bool (*)(const char &);


    void set_getch(tui_getch);
    void set_putch(tui_putch);

    void read(char *, int);
}
