//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "cspin.h"
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.WinXCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TLabel *Label1;
	TGroupBox *GroupBox1;
	TButton *Button5;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	TLabel *Label3;
	TComboBox *ComboBox;
	TLabel *Label4;
	TComboBox *ComboBox1;
	TLabel *Label5;
	TComboBox *ComboBox2;
	TLabel *Label6;
	TLabel *Label7;
	TComboBox *ComboBox3;
	TSpinEdit *SpinEdit2;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *Edit3;
	TLabel *Label10;
	TLabel *Label11;
	TEdit *Edit4;
	TRadioGroup *RadioGroup1;
	TButton *Button7;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall ComboBox3Change(TObject *Sender);
	void __fastcall SpinEdit2Change(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
    AnsiString FName;
	Byte * buffer;
	long lSize;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
