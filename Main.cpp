// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Main.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.NmXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.SmXhdpiPh.fmx", _PLAT_ANDROID)

TMainForm *MainForm;

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::MenuItem1Click(TObject *Sender)
{
    Close();
}
// ---------------------------------------------------------------------------

bool TMainForm::bisestile(int aa) {
    // calcolo bisestile, anno divisibile x 400, x 4 ma non x100

    if (aa % 400 == 0 || (aa % 4 == 0 && aa % 100 != 0))
        return true;
    else
        return false;
}

int TMainForm::giornimese(int aa, int mm) {
    switch (mm) {
    case 2:
        if (bisestile(aa) == true)
            return 29;
        else
            return 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

bool TMainForm::datavalida(int gg, int mm, int aa) {
    if (aa >= 1900 && aa < 2052 && mm > 0 && mm < 13 && gg > 0 &&
        gg <= giornimese(aa, mm))
        return true;
    else
        return false;
}

int TMainForm::calcolagiorni(int gg, int mm, int aa) {
    // calcola i giorni dal 01011900 fino al	ggmmaa
    int value = 0;
    // somma i giorni fino al 3112 dell'anno precedente
    for (int i = 1900; i <= aa - 1; i++) {
        if (bisestile(i))
            value += 366;
        else
            value += 365;
    }
    // somma i giorni fino all'ultimo giorno del mese precedente
    for (int i = 1; i <= mm - 1; i++) {
        value += giornimese(aa, i);
    }
    value += gg; // somma i giorni del mese corrente
    return value;
}

int TMainForm::abs(int gg) {
    if (gg < 0)
        return -gg;
    else
        return gg;
}

AnsiString TMainForm::giornoSettimana(int y, int m, int d) {
    AnsiString ret;
    const char *weekday[] = {"Domenica", "Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì", "Sabato"};
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return weekday[(y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7];
}

void __fastcall TMainForm::FormCreate(TObject *Sender) {
    lbGiornoNascita->Text += " (" + giornoSettimana(1932, 9, 25) + ")";
    lbGiornoMorte->Text += " (" + giornoSettimana(1982, 10, 4) + ")";
    lbGiorniVissuti->Text += " " + String(abs(calcolagiorni(25, 9, 1932) - calcolagiorni(4, 10, 1982))) + " giorni";
    Label3->Visible = false;
    // deOggi->Date=Now();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::btCalcClick(TObject *Sender) {
    AnsiString DataDa, DataA;
    Label3->Visible = true;
    DataDa = DateToStr(deCompleanno->Date);
    DataA = DateToStr(deOggi->Date);
    lbGiorni->Text = String(abs(calcolagiorni(StrToInt(DataA.SubString(0, 2)), StrToInt(DataA.SubString(3, 2)), StrToInt(DataA.SubString(6, 4))) - calcolagiorni(StrToInt(DataDa.SubString(0, 2)), StrToInt(DataDa.SubString(3, 2)), StrToInt(DataDa.SubString(5, 4))))) + " giorni";

}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::deOggiChange(TObject * Sender)
{
    Label3->Visible = false;
    lbGiorni->Text = "";
}
// ---------------------------------------------------------------------------
void __fastcall TMainForm::deCompleannoChange(TObject *Sender)
{
     Label3->Visible = false;
    lbGiorni->Text = "";
}
//---------------------------------------------------------------------------

