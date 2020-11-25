//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit11.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
	: TForm(Owner)
{
TrackBar1->Position=255;
TrackBar2->Position=255;
TrackBar3->Position=255;

Edit4->Text="Total de Pixels";

redindex=0.2126;
greenindex=0.7152;
blueindex=0.0722;



}
//---------------------------------------------------------------------------
void __fastcall TForm11::Button1Click(TObject *Sender)
{

pBitmap=new Graphics::TBitmap(); // Reserva de espacio de memoria para TBitmap
pBitmap2=new Graphics::TBitmap();

jpeg=new TJPEGImage;

OpenPictureDialog1->Filter="Archivos graficos|*.bmp;*.jpg;*.jpeg";

	if (OpenPictureDialog1->Execute()) {

		AnsiString ext=ExtractFileExt (OpenPictureDialog1->FileName);

			if (ext==".bmp") {
			pBitmap->LoadFromFile(OpenPictureDialog1->FileName);//ejecucion del cuadro de dialogo dentro de un if para evitar errores
			pBitmap2->LoadFromFile(OpenPictureDialog1->FileName);//ejecucion del cuadro de dialogo dentro de un if para evitar errores
			}
			else{jpeg->LoadFromFile (OpenPictureDialog1->FileName);
			pBitmap->Assign (jpeg);
			pBitmap2->Assign (jpeg);
			delete jpeg;
			}

	pBitmap->PixelFormat=pf32bit;
	pBitmap2->PixelFormat=pf32bit;
	}


//PaintBox1->Height=pBitmap->Height;
//PaintBox1->Width=pBitmap->Width;

R1=PaintBox1->BoundsRect;

PaintBox1->Invalidate();

ScrollBar1->Position=0;
}

//---------------------------------------------------------------------------


void __fastcall TForm11::PaintBox1Paint(TObject *Sender)
{
R1=PaintBox1->ClientRect;//Copia el tamaño posiion del paintbox al trect
PaintBox1->Canvas->Brush->Color=clGradientActiveCaption;
PaintBox1->Canvas->Rectangle(R1);
PaintBox1->Canvas->StretchDraw(R1,pBitmap);//grafica archivo -alternativa- PaintBox1->Canvas->Draw(R1.left,R1.top,pBitmap);
}
//---------------------------------------------------------------------------


void __fastcall TForm11::PaintBox1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
clColor=PaintBox1->Canvas->Pixels[X][Y];
Shape2->Brush->Color=clColor;

	int red=GetRValue (clColor);
	int green=GetGValue (clColor);
	int blue=GetBValue (clColor);

	Shape3->Brush->Color=RGB (red,0,0);
	TrackBar1->Position=int (red);
	Edit1->Text=TrackBar1->Position;

	Shape4->Brush->Color=RGB (0,green,0);
	TrackBar2->Position=int (green);
	Edit2->Text=TrackBar2->Position;

	Shape5->Brush->Color=RGB (0,0,blue);
	TrackBar3->Position=int (blue);
	Edit3->Text=TrackBar3->Position;


red=GetRValue (clColor);
green=GetGValue (clColor);
blue=GetBValue (clColor);
clColor=RGB(blue,green,red);

	H=pBitmap->Height;
	W=pBitmap->Width;
	int t=0;

	for (int y = 0; y < H; y++) {

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

		for (int x = 0; x < W; x++) {

			if (ptr[x]==clColor) {
			t=t+1;
			ptr[x]=clGreen;
		}
	}

}
Edit4->Text=t;
PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button2Click(TObject *Sender)
{
if (ColorDialog1->Execute()) {

	clSelect=ColorDialog1->Color;
	Shape6->Brush->Color=clSelect;

	int red=GetRValue (clSelect);
	int green=GetGValue (clSelect);
	int blue=GetBValue (clSelect);

	Shape3->Brush->Color=RGB (red,0,0);
	TrackBar1->Position=int (red);
	Edit1->Text=TrackBar1->Position;

	Shape4->Brush->Color=RGB (0,green,0);
	TrackBar2->Position=int (green);
	Edit2->Text=TrackBar2->Position;

	Shape5->Brush->Color=RGB (0,0,blue);
	TrackBar3->Position=int (blue);
	Edit3->Text=TrackBar3->Position;
}
}

//---------------------------------------------------------------------------

void __fastcall TForm11::TrackBar1Change(TObject *Sender)
{
Edit1->Text=TrackBar1->Position;
Shape3->Brush->Color=RGB (TrackBar1->Position,0,0);
Shape6->Brush->Color=RGB (TrackBar1->Position,TrackBar2->Position,TrackBar3->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm11::TrackBar2Change(TObject *Sender)
{
Edit2->Text=TrackBar2->Position;
Shape4->Brush->Color=RGB (0,TrackBar2->Position,0);
Shape6->Brush->Color=RGB (TrackBar1->Position,TrackBar2->Position,TrackBar3->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm11::TrackBar3Change(TObject *Sender)
{
Edit3->Text=TrackBar3->Position;
Shape5->Brush->Color=RGB (0,0,TrackBar3->Position);
Shape6->Brush->Color=RGB (TrackBar1->Position,TrackBar2->Position,TrackBar3->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm11::PaintBox1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
clColor=PaintBox1->Canvas->Pixels[X][Y];
Shape1->Brush->Color=clColor;
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button3Click(TObject *Sender)
{
//INVERTIR EN EJE X//

H=pBitmap->Height;
W=pBitmap->Width;

for (int y = 0; y < H; y++) {

	ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa
	ptr2=(TColor*) pBitmap2->ScanLine[y];//Cargo en la lista ptr2 la fila completa

	for (int x = 0; x < W; x++) {
		ptr[x]=ptr2[W-x];// el primer pixel de PBitmap es igual al ultimo pixel de PBitmap2
	}

}
PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button4Click(TObject *Sender)
{
//INVERTIR EN EJE Y//

H=pBitmap->Height;
W=pBitmap->Width;

for (int y = 0; y < H; y++) {

	ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa
	ptr2=(TColor*) pBitmap2->ScanLine[H-1-y];//Cargo en la lista ptr2 la ultima fila completa

	for (int x = 0; x < W; x++) {
		ptr[x]=ptr2[x];// Ptr2 posee la ultima fila del pbitmap
	}

}
PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm11::ScrollBar1Change(TObject *Sender)
{
//CAMBIO DE COLOR POR UMBRAL//

int umbral;
int umbral2;
int t;

ScrollBar1->Max=100;
ScrollBar1->Min=0;

umbral=ScrollBar1->Position;
clNewColor=Shape2->Brush->Color;
umbral2=(clNewColor*umbral)/100;

H=pBitmap->Height;
W=pBitmap->Width;

int red=GetRValue (clNewColor);
int green=GetGValue (clNewColor);
int blue=GetBValue (clNewColor);
clNewColor=RGB(blue,green,red);

for (int y = 0; y < H; y++) {

	ptr=(TColor*) pBitmap->ScanLine[y];

	for (int x = 0; x < W; x++) {
		clPrueba=ptr[x];

		if ((clPrueba<=(clNewColor+umbral2))&&(clPrueba>=(clNewColor-umbral2))) {

		ptr[x]=clGreen;
		t=t+1;

		}

}

}
PaintBox1->Invalidate();
Edit4->Text=t;

}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button5Click(TObject *Sender)
{
//CUADRADO NEGRO//

H=pBitmap->Height;
W=pBitmap->Width;


	for (int y = (H/2)-100; y < (H/2)+100; y++) { //Alto del cuadrado

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

			for (int x = (W/2)-100; x < (W/2)+100; x++) { //Ancho del cuadrado

				ptr[x]=clBlack;// Ptr2 posee la ultima fila del pbitmap

	}

}
PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button6Click(TObject *Sender)
{
//BANDERA//

H=pBitmap->Height;
W=pBitmap->Width;


	for (int y = (H/3); y < 2*(H/3); y++) {

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

			for (int x = 0 ; x < W; x++) {

				ptr[x]=clRed;// Ptr2 posee la ultima fila del pbitmap

			}

	}

	for (int y = (H/3)+(H/9); y < (H/3)+2*(H/9); y++) {

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

			for (int x = 0 ; x < W; x++) {

				ptr[x]=clWhite;// Ptr2 posee la ultima fila del pbitmap
			}

	}



PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button7Click(TObject *Sender)
{
//RECUADRO VERDE//

H=pBitmap->Height;
W=pBitmap->Width;


	for (int y = 0; y < H; y++) {

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

			for (int x = 0 ; x < W; x++) {

				if ((y<10)||(y>H-10)) {

					ptr[x]=clGreen;
				}
				if ((x<10)||(x>W-10)) {

					ptr[x]=clGreen;
				}
			}
	}
PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button10Click(TObject *Sender)
{
//NEGATIVO//

H=pBitmap->Height;
W=pBitmap->Width;

	for (int y = 0; y < H; y++) {

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

			for (int x = 0; x < W; x++) {

				int red=GetRValue (ptr[x]);
				int green=GetGValue (ptr[x]);
				int blue=GetBValue (ptr[x]);

				ptr[x]=RGB(255-red,255-green,255-blue);
	}

}
PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button8Click(TObject *Sender)
{
//ESCALA DE GRISES//

H=pBitmap->Height;
W=pBitmap->Width;

	for (int y = 0; y < H; y++) {

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

			for (int x = 0; x < W; x++) {

				int red=GetRValue (ptr[x]);
				int green=GetGValue (ptr[x]);
				int blue=GetBValue (ptr[x]);

				int gray=(red*redindex)+(green*greenindex)+(blue*blueindex);

				ptr[x]=RGB(gray,gray,gray);

	}

}
PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button9Click(TObject *Sender)
{
//BLANCO Y NEGRO//

H=pBitmap->Height;
W=pBitmap->Width;

	for (int y = 0; y < H; y++) {

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

			for (int x = 0; x < W; x++) {

				int red=GetRValue (ptr[x]);
				int green=GetGValue (ptr[x]);
				int blue=GetBValue (ptr[x]);

				int gray=(red*redindex)+(green*greenindex)+(blue*blueindex);


				if (gray>127.5) {gray=0;}
				else{gray=255;}

				ptr[x]=RGB(gray,gray,gray);

			}


}
PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button11Click(TObject *Sender)
{
//ESTRELLA//

H=pBitmap->Height; //alto bitmap
W=pBitmap->Width;  //ancho bitmap
float n=0;//define el ancho
float m=70; //define alto



	for (int y = 4*(H/9)-m; y < 4*(H/9)+m; y++) {   //define posicion en eje vertical

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila de pixeles de la imagen
		ptr2=(TColor*) pBitmap->ScanLine[H-y];//Cargo en la lista ptr la fila completa

			for (int x = (W/2)-n; x < (W/2)+n; x++) {         //define posicion en el eje horizontal

				ptr[x]=clBlack;//triangulo negro
				ptr2[x]=clBlack;//triangulo invertido rojo

				}
		n=n+0.7;
}

PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------


void __fastcall TForm11::Button12Click(TObject *Sender)
{
//TRIANGULO CON EXTERIOR NEGATIVO//

H=pBitmap->Height; //alto bitmap
W=pBitmap->Width;  //ancho bitmap
float n=0;//define el ancho
float m=70; //define alto

	for (int y = 0; y < H; y++) {

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila completa

			for (int x = 0; x < W; x++) {

				int red=GetRValue (ptr[x]);
				int green=GetGValue (ptr[x]);
				int blue=GetBValue (ptr[x]);

				ptr[x]=RGB(255-red,255-green,255-blue);
				}
   }

	 for (int y = 4*(H/9)-m; y < 4*(H/9)+m; y++) {   //define posicion en eje vertical

		ptr=(TColor*) pBitmap->ScanLine[y];//Cargo en la lista ptr la fila de pixeles de la imagen


				for (int x = (W/2)-n; x < (W/2)+n; x++) {         //define posicion en el eje horizontal

				int red=GetRValue (ptr[x]);
				int green=GetGValue (ptr[x]);
				int blue=GetBValue (ptr[x]);

				ptr[x]=RGB(255-red,255-green,255-blue);


				}
				n=n+0.7;
				}


PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------


