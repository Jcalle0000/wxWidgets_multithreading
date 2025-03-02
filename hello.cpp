 // function documentation
 // https://docs.wxwidgets.org/3.2/classwx_app_console.html#a99953775a2fd83fa2456e390779afe15 

// wxApp Oveview

// /Users/jasoncalle/Documents/wxWdigets_trail_2/wxWidgets/macBuild

// ls | grep -v '\.o$' 

// this we are going to build using cmake
// https://docs.wxwidgets.org/3.2/overview_helloworld.html
// to compile
//   g++ -std=c++17 hello.cpp -o hello.exe `../wx-config --cxxflags --libs`  
// macBuild % ../wx-config --version

// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    // #include <wx/wx.h> // global include
    #include<wx/frame.h>
    #include<wx/app.h>
    #include<wx/menu.h>
    #include <wx/msgdlg.h>

    #include<wx/button.h> // for button creation
#endif

    // #include "TextEditorApp.h"
// #include "TextFrame.h"
// #include "wx/any.h"

// #endif // TEXTEDITORAPP_H


// (every app should define a new class) derived from wxApp

class MyApp : public wxApp 
{
public:
    virtual bool OnInit();// by overriding this, we can initialize this (open a new main window)
};
// wxApp serves as the entry point for a wxWidgets application, handling initialization 
// and the main event loop

// main window is created by deriving a class from wxFrame
// along with giving it a menu and a status bar in its constructor 
// frame is a top level window that contains other windows
// 
class MyFrame : public wxFrame 
{
public:
    MyFrame();
    // MyFrame(const wxString& title);
private:
    // 3 menu items
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event); // any program should implement this and the latter
    void OnAbout(wxCommandEvent& event);
    void OnButtonOk(wxCommandEvent& event);

    // wxDECLARE_EVENT_TABLE();
    // DECLARE_EVENT_TABLE();
};

// in order to be able to react to a menu command
// it must be given a unique identifier which can be defined as a const variable or an enum
enum
{
    ID_Hello = 1,
    ID_CustomNum=2
};

// main is impplement here
// this creates an application instance of the specified class, and starts running
// the gui event loop
// create a MyApp object
wxIMPLEMENT_APP(MyApp);

// called upon startup
// usually creates at least one window
// will interpret any command-line arguments
// if this returns true it will start the event loop
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();

    // MyFrame *frame = new MyFrame(wxT("Minimal wxWidgets App"));
    // frames are created hidden by default
    frame->Show(true);
    return true;
}

// what is this? object declaration?
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Hello World") // this is the window title?
{
    // This is added under "File" , section is called "Hello..."
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", // this is the option under file with the command shortcut
                     "Help string shown in status bar for this menu item");
    
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);// what are we doing here?

    // We are adding the about section under the executable tab
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    
    // lets create another tab under file?
    // wxMenu *menuSomeTab = new wxMenu;
    // menuSomeTab->Append( ID_CustomNum);

    // here we are adding the sections File, help
    menuBar->Append(menuFile, "&File"); // what is this doing 
    menuBar->Append(menuHelp, "&Help"); // what is this doing

    wxButton* col=new wxButton(this, 101, "&Colour...");

    // menuBar->Append(menuSomeTab, "&SomeTab"); // what is this doing    
    // im not sure why this dosent work
    // menuBar->Append(menuHelp, "&SomeOtherTab"); // what is this doing

    SetMenuBar( menuBar );

    // status bar at the bottom of the window
    CreateStatusBar(); // part of the member function documentation

    SetStatusText("Welcome to wxWidgets!");
    
    // we use the standards ids (stock items)
    // ID values are used here
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnButtonOk, this, wxID_OK);
    // Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    // instead of using functions for event handlers we could use lambdas
    Bind(wxEVT_MENU, 
            [=](wxCommandEvent&) 
            { 
                Close(true); 
            }, 
            wxID_EXIT);
}


// when the user click on the "About/Quit" menu items,
/*
    the event is sent to the frame, and MyFrame's event
    table tells wxWidgets that a menu event with identifier wxID_About
    should be sent to MyFrame::OnAbout
*/ 

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true); // other windows have no veto power
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example", // this is the message
                 "About Hello World", // This is the title in the about  
                 wxOK |  // this is the button
                 wxICON_INFORMATION); // im not sure what the wxICON_INFORMATION is about
}



void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnButtonOk(wxCommandEvent& event ){

}