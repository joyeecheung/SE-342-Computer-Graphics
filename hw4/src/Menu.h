#ifndef MENU_H
#define MENU_H

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <GL/glut.h>
#include <map>
#include <string>

struct Menu {
    int id;
    int entry;
    bool visible;
};

void createMenu(int button,
            std::map<std::string, int> entries,
            int defaultEntry);
void onMenu(int num);
void menuState(int status);

#endif