#ifndef MSC_H
#define MSC_H

#include <wx/textctrl.h>

class MyTextCtrl : public wxTextCtrl
{
    public:
        MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value,
                const wxPoint &pos, const wxSize &size, int style );
            // : wxTextCtrl(parent, id, value, pos, size, style);

        // void OnKeyDown(wxKeyEvent& event);
        void OnTextURL(wxTextUrlEvent& event); // Declare the function


    private:
        wxDECLARE_EVENT_TABLE();
        bool m_hasCapture;

};

#endif