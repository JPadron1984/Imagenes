//---------------------------------------------------------------------------

#ifndef Unit11H
#define Unit11H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
	TOpenPictureDialog *OpenPictureDialog1;
	TMainMenu *MainMenu1;
	TPaintBox *PaintBox1;
	TButton *Button1;
	TShape *Shape1;
	TShape *Shape2;
	TGroupBox *GroupBox1;
	TShape *Shape3;
	TShape *Shape4;
	TShape *Shape5;
	TShape *Shape6;
	TTrackBar *TrackBar1;
	TTrackBar *TrackBar2;
	TTrackBar *TrackBar3;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TColorDialog *ColorDialog1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TEdit *Edit4;
	TScrollBar *ScrollBar1;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);
	void __fastcall PaintBox1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall TrackBar3Change(TObject *Sender);
	void __fastcall PaintBox1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall ScrollBar1Change(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);

private:	// User declarations
public:		// User declarations

int H,W;

TJPEGImage*jpeg;

TColor clSelect;
TColor clColor;
TColor clNewColor;
TColor clPrueba;

TColor *ptr;
TColor *ptr2;

Graphics::TBitmap *pBitmap;// declaracion de matriz
Graphics::TBitmap *pBitmap2;//donde se guardara una copia del pBitmap a modo backup

TRect R1;

	__fastcall TForm11(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
