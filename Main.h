//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Menus.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
//#include <FireDAC.Phys.MSSQL.hpp>
//#include <FireDAC.Phys.MSSQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Layouts.hpp>
#include <System.Rtti.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <System.Bindings.Outputs.hpp>
#include <FMX.DateTimeCtrls.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *panelBottom;
    TMenuBar *MenuBar1;
    TPanel *Panel1;
    TButton *btCalc;
    TMenuItem *MenuItem1;
    TDateEdit *deCompleanno;
    TLabel *Label2;
    TDateEdit *deOggi;
    TLabel *Label1;
    TLabel *lbGiornoNascita;
    TLabel *lbGiornoMorte;
    TLabel *lbGiorniVissuti;
    TPanel *PanelGould;
    TStyleBook *StyleBook1;
    TPanel *Panel2;
    TLabel *Label3;
    TLabel *lbGiorni;
    void __fastcall MenuItem1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btCalcClick(TObject *Sender);
    void __fastcall deOggiChange(TObject *Sender);
    void __fastcall deCompleannoChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
    bool bisestile(int aa) ;
    int giornimese(int aa, int mm) ;
    bool datavalida(int gg, int mm, int aa);
    int calcolagiorni(int gg, int mm, int aa) ;
    int abs(int gg) ;
    AnsiString giornoSettimana(int y, int m, int d) ;

};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
