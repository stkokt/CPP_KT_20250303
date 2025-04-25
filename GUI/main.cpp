#include <wx/wx.h> // Einbinden der wxWidgets-Bibliothek
#include <wx/combobox.h> // Einbinden der Combobox-Klasse
#include <cmath> // Einbinden der mathematischen Bibliothek für Berechnungen

// Definition der Hauptklasse für das Anwendungsfenster
class CircleCalculatorFrame : public wxFrame
{
public:
    // Konstruktor für das Hauptfenster
    CircleCalculatorFrame() : wxFrame(nullptr, wxID_ANY, wxT("Kreisberechnungen"), wxDefaultPosition, wxSize(400, 400))
    {
        // Erstellen eines Panels, das die Benutzeroberfläche enthält
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        // Erstellen eines vertikalen BoxSizers für das Hauptlayout
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

        // Erstellen eines horizontalen BoxSizers für die Eingabefelder
        wxBoxSizer* inputSizer = new wxBoxSizer(wxHORIZONTAL);

        // Hinzufügen eines statischen Textes "Wert:" zum Eingabesizer
        inputSizer->Add(new wxStaticText(panel, wxID_ANY, wxT("Wert:")), 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        // Erstellen eines Eingabefelds für den Benutzer
        inputField = new wxTextCtrl(panel, wxID_ANY);
        // Hinzufügen des Eingabefelds zum Eingabesizer
        inputSizer->Add(inputField, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        // Erstellen einer Combobox mit Auswahlmöglichkeiten
        wxArrayString choices;
        choices.Add(wxT("Radius"));
        choices.Add(wxT("Durchmesser"));
        choices.Add(wxT("Flächeninhalt"));
        choices.Add(wxT("Umfang"));
        comboBox = new wxComboBox(panel, wxID_ANY, wxT("Radius"), wxDefaultPosition, wxDefaultSize, choices, wxCB_READONLY);
        // Hinzufügen der Combobox zum Eingabesizer
        inputSizer->Add(comboBox, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        // Hinzufügen des Eingabesizers zum Hauptlayout
        mainSizer->Add(inputSizer, 0, wxEXPAND | wxALL, 5);

        // Erstellen eines Buttons zum Auslösen der Berechnungen
        calculateButton = new wxButton(panel, wxID_ANY, wxT("Berechnen"));
        // Hinzufügen des Buttons zum Hauptlayout
        mainSizer->Add(calculateButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

        // Erstellen von schreibgeschützten Textfeldern zur Anzeige der Ergebnisse
        radiusField = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
        diameterField = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
        areaField = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
        circumferenceField = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

        // Hinzufügen der Ergebnisfelder zum Hauptlayout
        mainSizer->Add(new wxStaticText(panel, wxID_ANY, wxT("Radius:")), 0, wxALL, 5);
        mainSizer->Add(radiusField, 0, wxEXPAND | wxALL, 5);

        mainSizer->Add(new wxStaticText(panel, wxID_ANY, wxT("Durchmesser:")), 0, wxALL, 5);
        mainSizer->Add(diameterField, 0, wxEXPAND | wxALL, 5);

        mainSizer->Add(new wxStaticText(panel, wxID_ANY, wxT("Flächeninhalt:")), 0, wxALL, 5);
        mainSizer->Add(areaField, 0, wxEXPAND | wxALL, 5);

        mainSizer->Add(new wxStaticText(panel, wxID_ANY, wxT("Umfang:")), 0, wxALL, 5);
        mainSizer->Add(circumferenceField, 0, wxEXPAND | wxALL, 5);

        // Setzen des Hauptlayouts für das Panel
        panel->SetSizer(mainSizer);

        // Verknüpfen des Button-Klick-Ereignisses mit der OnCalculate-Methode
        calculateButton->Bind(wxEVT_BUTTON, &CircleCalculatorFrame::OnCalculate, this);
    }

private:
    wxTextCtrl* inputField; // Eingabefeld für den Benutzer
    wxComboBox* comboBox; // Combobox zur Auswahl der Eingabeeinheit
    wxButton* calculateButton; // Button zum Auslösen der Berechnungen
    wxTextCtrl* radiusField; // Textfeld zur Anzeige des Radius
    wxTextCtrl* diameterField; // Textfeld zur Anzeige des Durchmessers
    wxTextCtrl* areaField; // Textfeld zur Anzeige des Flächeninhalts
    wxTextCtrl* circumferenceField; // Textfeld zur Anzeige des Umfangs

    // Methode, die aufgerufen wird, wenn der Button gedrückt wird
    void OnCalculate(wxCommandEvent& event)
    {
        double value;
        // Versuchen, den eingegebenen Wert in eine Gleitkommazahl umzuwandeln
        if (!inputField->GetValue().ToDouble(&value))
        {
            // Fehlermeldung anzeigen, wenn die Eingabe ungültig ist
            wxMessageBox(wxT("Bitte geben Sie eine gültige Zahl ein."), wxT("Fehler"), wxOK | wxICON_ERROR);
            return;
        }

        double radius, diameter, area, circumference;
        // Auslesen der Auswahl aus der Combobox
        wxString selection = comboBox->GetValue();

        // Berechnungen basierend auf der Auswahl der Combobox
        if (selection == wxT("Radius"))
        {
            radius = value;
            diameter = 2 * radius;
            area = M_PI * radius * radius;
            circumference = 2 * M_PI * radius;
        }
        else if (selection == wxT("Durchmesser"))
        {
            diameter = value;
            radius = diameter / 2;
            area = M_PI * radius * radius;
            circumference = 2 * M_PI * radius;
        }
        else if (selection == wxT("Flächeninhalt"))
        {
            area = value;
            radius = sqrt(area / M_PI);
            diameter = 2 * radius;
            circumference = 2 * M_PI * radius;
        }
        else if (selection == wxT("Umfang"))
        {
            circumference = value;
            radius = circumference / (2 * M_PI);
            diameter = 2 * radius;
            area = M_PI * radius * radius;
        }
        else
        {
            // Fehlermeldung anzeigen, wenn die Auswahl ungültig ist
            wxMessageBox(wxT("Ungültige Auswahl."), wxT("Fehler"), wxOK | wxICON_ERROR);
            return;
        }

        // Anzeigen der Ergebnisse in den Textfeldern
        radiusField->SetValue(wxString::Format(wxT("%.2f"), radius));
        diameterField->SetValue(wxString::Format(wxT("%.2f"), diameter));
        areaField->SetValue(wxString::Format(wxT("%.2f"), area));
        circumferenceField->SetValue(wxString::Format(wxT("%.2f"), circumference));
    }
};

// Definition der Anwendungsklasse
class CircleCalculatorApp : public wxApp
{
public:
    // Initialisierungsmethode der Anwendung
    virtual bool OnInit()
    {
        // Erstellen und Anzeigen des Hauptfensters
        CircleCalculatorFrame* frame = new CircleCalculatorFrame();
        frame->Show(true);
        return true;
    }
};

// Implementierung der Anwendung
wxIMPLEMENT_APP(CircleCalculatorApp);
