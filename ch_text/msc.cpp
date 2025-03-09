// #include <wx/textctrl.h>
// this is already defined in msc_h

#include"msc.h"

// class MyTextCtrl : public wxTextCtrl
// wxTextCtrl is the class inherited from

MyTextCtrl::MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value,
                const wxPoint &pos, const wxSize &size, int style = 0)
            : wxTextCtrl(parent, id, value, pos, size, style) // wxTextCtrl is the object we inherit from
        {
            m_hasCapture = false; // what is this?
        }

    // already defined in MSC_H
    // private:
    //     wxDECLARE_EVENT_TABLE();
    //     bool m_hasCapture;

// };


void MyTextCtrl::OnTextURL(wxTextUrlEvent& event)
{
    const wxMouseEvent& ev = event.GetMouseEvent();

    // filter out mouse moves, too many of them
    if ( ev.Moving() )
        return;

    long start = event.GetURLStart(),
         end = event.GetURLEnd();

    // wxLogMessage("Mouse event over URL '%s': %s",
    //              GetValue().Mid(start, end - start),
    //              GetMouseEventDesc(ev));
}

// Define event table if needed (leave empty if not used)
wxBEGIN_EVENT_TABLE(MyTextCtrl, wxTextCtrl)
    EVT_TEXT_URL(wxID_ANY, MyTextCtrl::OnTextURL)
wxEND_EVENT_TABLE()