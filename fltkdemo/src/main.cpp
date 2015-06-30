#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>

//
// Demonstrate how to use Fl_File_Chooser
// erco 08/04/2005
//

// Callback: when use picks 'File | Open' from main menu
void open_cb(Fl_Widget*, void*) {

    // Create the file chooser, and show it
    Fl_File_Chooser chooser(".",                        // directory
                            "*",                        // filter
                            Fl_File_Chooser::MULTI,     // chooser type
                            "Title Of Chooser");        // title
    chooser.show();

    // Block until user picks something.
    //     (The other way to do this is to use a callback())
    //
    while (chooser.shown()) {
        Fl::wait();
    }

    // User hit cancel?
    if (chooser.value() == NULL) {
        fprintf(stderr, "(User hit 'Cancel')\n"); return;
    }

    // Print what the user picked
    fprintf(stderr, "--------------------\n");
    fprintf(stderr, "DIRECTORY: '%s'\n", chooser.directory());
    fprintf(stderr, "    VALUE: '%s'\n", chooser.value());
    fprintf(stderr, "    COUNT: %d files selected\n", chooser.count());

    // Multiple files? Show all of them
    if (chooser.count() > 1) {
        for (int t = 1; t <= chooser.count(); t++) {
            fprintf(stderr, " VALUE[%d]: '%s'\n", t, chooser.value(t));
        }
    }
}

// Callback: when user picks 'Quit'
void quit_cb(Fl_Widget*, void*) {
    exit(0);
}

int main() {
    Fl_Window win(500, 300, "Simple Example of Fl_File_Chooser");
    Fl_Menu_Bar menubar(0, 0, 500, 25);
    menubar.add("File/Open", 0, open_cb);
    menubar.add("File/Quit", 0, quit_cb);
    Fl_Box box(0, 0, 260, 260, "Hey, I mean,\nHello, World!");
    win.show();
    return(Fl::run());
}