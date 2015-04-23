#include "Menu.h"

void onMenu(int num) {
    menu.entry = num;
}

void menuState(int status) {
    if (status == GLUT_MENU_IN_USE)
        menu.visible = true;
}

void createMenu(Menu &menu, int button, std::map<std::string, int> entries, int defaultEntry) {
    menu.visible = false;
    menu.id = glutCreateMenu(onMenu);
    menu.entry = defaultEntry;
    for (std::map<std::string, int>::iterator it = entries.begin();
        it != entries.end(); ++it) {
        glutAddMenuEntry(it->first.c_str(), it->second);
    }
    glutMenuStateFunc(menuState);
    glutAttachMenu(button);
}
