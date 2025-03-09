// #ifndef WX_PRECOMP
#include<wx/app.h>
#include<wx/frame.h>

// #include <wx/textctrl.h>
#include "msc.h" // textCtrl will be used in Panel

#include <wx/panel.h>
#include <wx/string.h>
#include <wx/menu.h>
// pull down (list of items) , one of which may be selected before the 
// menu goes away


// g++ -std=c++17 text_2.cpp -o text_2.exe `../../wx-config --cxxflags --libs`


// g++ -std=c++17 -c text_2.cpp msc.cpp `../../wx-config --cxxflags --libs`  
// the "libs" has compiler and linker flags i guess
// this will generate msc.o and text_2.o

// this was actually outputting warnings 
// so now we recommend this
/*  
g++ -std=c++17 -c text_2.cpp msc.cpp `../../wx-config --cxxflags`
g++ -std=c++17 -o text.exe text_2.o msc.o `../../wx-config --cxxflags --libs` 
*/

// every application is derived from here
class MyApp: public wxApp
{
public:
    bool OnInit() override;
};

// moved to msc.cpp and msc.h
// class MyTextCtrl : public wxTextCtrl
// {
//     public:
//         MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value,
//                 const wxPoint &pos, const wxSize &size, int style = 0)
//             : wxTextCtrl(parent, id, value, pos, size, style)
//         {
//             m_hasCapture = false; // what is this?
//         }

//     private:
//         wxDECLARE_EVENT_TABLE();
//         bool m_hasCapture;

// };

// container for other controls
// group and manage related controls within a window
// 
class MyPanel:public wxPanel{
    public:
        MyPanel(wxFrame *frame, int x, int y, int w, int h);
        virtual ~MyPanel();

    private:
        MyPanel *m_panel;
        wxDECLARE_EVENT_TABLE();
};

// provides basic structure for a window
// title bar, bordersm and optional menu bar
class MyFrame: public wxFrame
{
    public:
        MyFrame(const wxString& title, int x, int y);
        // MyFrame();
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnFileSave(wxCommandEvent& event);


    private: // why should the event table be private?
        // MyPanel *m_panel; // panel is used here
        wxDECLARE_EVENT_TABLE();
};

void MyFrame::OnQuit (wxCommandEvent& WXUNUSED(event) )
{
    std::cout<< "Quit called\n";
    Close(true);
}

void MyFrame::OnAbout( wxCommandEvent& WXUNUSED(event) ){
    wxBeginBusyCursor();
}

enum
{
    TEXT_QUIT = wxID_EXIT,
    TEXT_ABOUT = wxID_ABOUT,
    TEXT_SAVE // we dont need to declare this b/c 
    // it continues the values from above
};

bool MyApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    // Create the main frame window
    MyFrame *frame = new MyFrame("Text wxWidgets sample", 50, 50);
    std::cout<< "Frame constructed\n";

    // the below could have been in the constructor of the frame
    // im not sure why file_menu is not working as expected
    wxMenu *file_menu = new wxMenu;
    // this is not creating the menu bar 

    std::cout<< "file_menu constructed\n";


    // this is not showing up
    // text save has to be in the event table
    file_menu->Append(TEXT_SAVE, "&Save file\tCtrl-S",
                    "Save the text control contents to file");
    
    std::cout<< "File appended\n";

    // file_menu->AppendSeparator();

    // file_menu->Append(TEXT_ABOUT, "&About\tAlt-A");
    // file_menu->Append(TEXT_QUIT, "E&xit\tAlt-X", "Quit this sample");

    // what is the menu_bar?
    // 
    wxMenuBar *menu_bar = new wxMenuBar( wxMB_DOCKABLE) ; // menu bar is de-attached
    menu_bar->Append(file_menu, "&File");
// end of what could have been in the frame constructor

    // MyFrame *frame()= new MyFrame();
    frame->SetMenuBar(menu_bar);
    frame->Show(true);
    return true;

}

// main is impplement here
// this creates an application instance of the specified class, and starts running
// the gui event loop
// create a MyApp object
wxIMPLEMENT_APP(MyApp);


// does the table need to be declared in a specific order?


// the constructor should be before the object is declared?
MyFrame::MyFrame(const wxString& title, int x, int y)
       : wxFrame(nullptr, wxID_ANY, title, wxPoint(x, y))
{
    // SetIcon(wxICON(sample));

    // m_panel = new MyPanel( this, 10, 10, 300, 100 );
    // m_panel->GetSizer()->Fit(this);
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
// what makese these appear?
    EVT_MENU(TEXT_QUIT,   MyFrame::OnQuit)
    EVT_MENU(TEXT_ABOUT,  MyFrame::OnAbout)
    EVT_MENU(TEXT_SAVE,   MyFrame::OnFileSave) // we defined the onFileSave
wxEND_EVENT_TABLE()

// member function
void MyFrame::OnFileSave(wxCommandEvent& WXUNUSED(event)){

}