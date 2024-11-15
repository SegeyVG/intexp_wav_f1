//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <cstdio.h>
#include <fstream>
#include <string.h>
#include <memory.h>
#include <math.h>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

struct WavHead {
//		char RIFF[4]; //The RIFF in the first part
//		int size0;//The size of all subsequent files is stored
//		char WAVE[4];
		char FMT[4];
		int size1;//The size saved by fmt, after containing this, the first few data, a total of 16
		unsigned short fmttag;
		unsigned short channel;
		unsigned int sampleRate; // samples per second
		unsigned int bytepersec;
		unsigned short blockalign;
		unsigned short bitpersamples;
		char DATA[4];
		int size2;//The remaining file size
};

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 if (OpenDialog1->Execute()) {
		String FileNameS= OpenDialog1->FileName;
		AnsiString file = AnsiString(FileNameS);

		FILE * pFile;
		//long lSize;
		size_t result;

		pFile = fopen(file.c_str(), "rb");
		if (pFile==NULL) { ShowMessage("File error"); return; }

		// obtain file size:
		fseek (pFile , 0 , SEEK_END);
		lSize = ftell (pFile);
		rewind (pFile);

		// allocate memory to contain the whole file:
		delete [] buffer;
		buffer = new Byte[lSize];
		if (buffer == NULL) { ShowMessage("Memory error"); return; }

		// copy the file into the buffer:
		result = fread (buffer,1,lSize,pFile);
		if (result != lSize) { ShowMessage("Reading error"); return; }

		FName = file;
		Edit2->Text = AnsiString() + FileNameS.c_str();
		// terminate
		fclose (pFile);
		Button5->Enabled = true;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	 if (SaveDialog1->Execute()) {
		String FileNameS= SaveDialog1->FileName;
		AnsiString file = AnsiString(FileNameS);
		FILE * pFile;
		size_t result;
		pFile = fopen (file.c_str(), "wb");
		result = fwrite (buffer , sizeof(Byte), lSize, pFile);
		if (result!=lSize) {
			ShowMessage("Ошибка записи файла");
		}
		fclose (pFile);
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete [] buffer;
}
//---------------------------------------------------------------------------

int MakeWaveData2(int freq, float amp, int time_ms, unsigned char* p, int sampleRate, int channels, int BitsPerSample)
{
	 int ret = 0;
	 int SAMPLE_NUM = sampleRate * time_ms / 1000; //Total samples collected
	 int AUDIO_CYCLE = sampleRate / freq; //Number of samples collected by a sine wave
	 int ACCURACY = (BitsPerSample == 16)? INT16_MAX: INT8_MAX; //Precision

	 if(amp > 1.0){
		amp = 1.0;
	 } else if (amp <= 0.01){
		amp = 0.01;
	 }

	 for (int i = 0; i <SAMPLE_NUM; i++){ //In fact, as long as AUDIO_CYCLE points are collected, a complete sine wave can be obtained
			int16_t v = (int16_t)( amp * ACCURACY * sin( 2 * M_PI * (i% AUDIO_CYCLE * 1.0)/AUDIO_CYCLE )); // sine function y = k sin x
		 if (BitsPerSample == 16) {//16bit
			 if (channels == 1){//16-bit single channel
				 p[i*2] = (v & 0xFF); //The low byte is quantized in the first 16 bits, the low byte is 8 bits
				 p[1+i*2] = ((v >>8) & 0xFF); //High byte is in the back, high byte is 8 bits
				 ret +=2;
			 }else{//16-bit dual channel
				 p[i*4] = (v & 0xFF); //The low byte is quantized in the first 16 bits, the low byte is 8 bits
				 p[1+i*4] = ((v >>8) & 0xFF); //High byte is in the back, high byte is 8 bits
				 p[2+i*4] = (v & 0xFF); //The low byte is quantized in the first 16 bits, the low byte is 8 bits
				 p[3+i*4] = ((v >>8) & 0xFF); //High byte follows, high byte 8 bits
				 ret +=4;
			}

		}else{
			 if (channels == 1){//8-bit single channel
				p[i] = (v & 0xFF);
				ret ++;
			 }else{//8-bit dual channel
				p[i*2] = (v & 0xFF);
				p[1+i*2] = (v & 0xFF);
				ret +=2;
			}
		}
	}

	return ret;
}



void __fastcall TForm1::Button5Click(TObject *Sender)
{
	WavHead WH;

	bool stop = false;
	 size_t posFmt = 0;
	 char ch;
	 while (!stop) {
		Byte *bd = buffer + posFmt;
		memcpy(&ch, bd, sizeof(Byte));
		if (ch=='f') {
			char d[4];
			memcpy(&d, bd, sizeof(Byte)*4);
			if (d[1]=='m' && d[2]=='t') {
			   stop = true;
			   continue;
			}
		}
		posFmt++;
	 }

	memcpy(&WH, buffer + posFmt, sizeof(WH));
	//AnsiString Print = AnsiString(WH.sampleRate) + " _ " + WH.channel + " _ " + WH.bitpersamples + " _ " + WH.size2;
	//ShowMessage(Print);
	//AnsiString Print1 = AnsiString() + "_" + WH.size1;

	 stop = false;
	 size_t posD = 0;
	 while (!stop) {
		Byte *bd = buffer + posD;
		memcpy(&ch, bd, sizeof(Byte));
		if (ch=='d') {
			char d[4];
			memcpy(&d, bd, sizeof(Byte)*4);
			if (d[1]=='a' && d[2]=='t' && d[3]=='a') {
			   stop = true;
			   continue;
			}
		}
		posD++;
	 }

	 int ld;
	 Byte *bd1 = buffer + posD + 4;
	 memcpy(&ld, bd1, sizeof(int));
	 //ShowMessage(ld);

	 //int freq = 3000;
	 int freq = AnsiString(SpinEdit2->Value).ToInt();
	 float amp = 0.8;
	 int durations = AnsiString(Edit1->Text).ToInt();
	 int t1 = WH.sampleRate * 2 * WH.bitpersamples / 8;
	 int t2 = durations /1000;
	 int t3 = t1*t2;
	 int totalLen = t3;

	 unsigned char * audiodata = new unsigned char[totalLen];
	 int cb = MakeWaveData2(freq, amp, durations, audiodata, WH.sampleRate, WH.channel, WH.bitpersamples);
	 //ShowMessage(cb);
	 int new_size2 = WH.size2 + cb;
	 WH.size2 = new_size2;
	 ld +=cb;
	 memcpy(bd1, &ld, sizeof(int));
	 Byte *tbuff = new Byte[lSize + cb];
	 memcpy(tbuff, buffer, lSize);
	 Byte *tbuff_end = tbuff + lSize;
	 memcpy(tbuff_end, audiodata, cb);
	 delete [] buffer;
	 buffer = tbuff;
	 lSize +=cb;
	 ShowMessage("Сигнал сформирован и добавлен к блоку данных для файла.\nЧтобы увидеть изменения осуществите сохранение файла");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
    Edit2->Text = FName;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox3Change(TObject *Sender)
{
	SpinEdit2->Increment = AnsiString(ComboBox3->Text).ToInt();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpinEdit2Change(TObject *Sender)
{
	int max = AnsiString(SpinEdit2->MaxValue).ToInt();
	int min = AnsiString(SpinEdit2->MinValue).ToInt();
	int v = AnsiString(SpinEdit2->Value).ToInt();
	if (v<min || v>max) {
		AnsiString msg = AnsiString("Недопустимо! Значение должно быть в диапазоне 100 - 16000Гц.\n");
		msg += "Будет установлено усредненное значение 5000Гц";
		ShowMessage(msg);
		SpinEdit2->Value = 5000;
	}
}
//---------------------------------------------------------------------------



enum type_signal
{
	tsNone = -1,
	tsTone,
	tsTImp
};

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	type_signal ts;
	ts = (type_signal) AnsiString(RadioGroup1->ItemIndex).ToInt();
    if(ts!=-1) Button7->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	type_signal ts;
	ts = (type_signal) AnsiString(RadioGroup1->ItemIndex).ToInt();
	if ((ComboBox->Text)=="")  { ShowMessage("Задайте частоту дискретизации");  return;  }
	if ((ComboBox1->Text)=="")  { ShowMessage("Задайте тип звука (стерео/моно)");  return;  }
	if ((ComboBox2->Text)=="")  { ShowMessage("Задайте глубину звучания");  return;  }

	if ((ts==tsTImp)&&(Edit3->Text)=="")  { ShowMessage("Для тонально-импульсного сигнала задайте период следования");  return;  }
	if ((ts==tsTImp)&&(Edit4->Text)=="")  { ShowMessage("Для тонально-импульсного сигнала задайте длину импульса");  return;  }

	int sampleRate = AnsiString(ComboBox->Text).ToInt();
	int BitsPerSample = AnsiString(ComboBox2->Text).ToInt();
	int channels = (ComboBox1->Text == "Моно")? 1:2;
	int durations = AnsiString(Edit1->Text).ToInt();
	int freq = AnsiString(SpinEdit2->Value).ToInt();
	float amp = 0.8;
	int t1 = sampleRate * channels * BitsPerSample/8;
	int t2 = durations /1000;
	int t3 = t1*t2;
	int dataLen = t3;
	unsigned char * audiodata = new unsigned char[dataLen];
	int cb = 0;
	if (ts==tsTone)
		cb = MakeWaveData2(freq, amp, durations, audiodata, sampleRate, channels, BitsPerSample);
	else if(ts==tsTImp) {
		int period = AnsiString(Edit3->Text).ToInt();
		int len_imp = AnsiString(Edit4->Text).ToInt();
		int Count = durations / period;
		if (period<len_imp) { ShowMessage("Задайте корректную длину импульса.\n Она не может быть больше периода следования");  return; 	}
		//if (Count<1) {  ShowMessage("Задайте корректный периода следования.\n Он не должен быть больше общей длительности");  return; 	}

		for(int i=0; i<Count; i++)  {
			int c1 = MakeWaveData2(freq, amp, len_imp, audiodata+cb, sampleRate, channels, BitsPerSample);
			cb +=c1;
			int c2 = MakeWaveData2(freq, 0, period-len_imp, audiodata+cb, sampleRate, channels, BitsPerSample);
			cb +=c2;
		}
		int len_tail = durations - period*Count;
		int len_tail_imp = (len_tail>=len_imp) ? len_imp : len_tail;
		int len_tail_null = (len_tail>len_imp) ? len_tail-len_imp : 0;

		if(len_tail!=0) {
			int ct1 = MakeWaveData2(freq, amp, len_tail_imp, audiodata+cb, sampleRate, channels, BitsPerSample);
			cb +=ct1;
			if(len_tail_null!=0) {
				int ct2 = MakeWaveData2(freq, 0, len_tail_null, audiodata+cb, sampleRate, channels, BitsPerSample);
				cb +=ct2;
			}

		}
	}
	else  return;

	Byte *tbuff = new Byte[44 + cb];
	char RIFF[4] = {'R','I','F','F'};
	memcpy(tbuff, &RIFF, 4);
	int size0 = cb + 36;
	memcpy(tbuff+4, &size0, 4);
	char WAVE[4] = {'W','A','V','E'};
	memcpy(tbuff+8, &WAVE, 4);
	char FMT[4] = {'f','m','t',' '};
	memcpy(tbuff+12, &FMT, 4);
	int size1 = 16;
	memcpy(tbuff+16, &size1, 4);
	unsigned short fmttag = 1;
	memcpy(tbuff+20, &fmttag, 2);
	unsigned short channel = (unsigned short)channels;
	memcpy(tbuff+22, &channel, 2);
	memcpy(tbuff+24, &sampleRate, 4);
	unsigned int bytepersec = channels*sampleRate*BitsPerSample/8;
	memcpy(tbuff+28, &bytepersec, 4);
	short blockalign = (short)channels*BitsPerSample/8;
	memcpy(tbuff+32, &blockalign, 2);
	unsigned short bitpersamples = (unsigned short)BitsPerSample;
	memcpy(tbuff+34, &bitpersamples, 2);
	char Data[4] = {'d','a','t','a'};
	memcpy(tbuff+36, &Data, 4);
	int sizeData = cb;
	memcpy(tbuff+40, &sizeData, 4);
	memcpy(tbuff+44, audiodata, cb);

	if (SaveDialog1->Execute()) {
		String FileNameS= SaveDialog1->FileName;
		AnsiString file = AnsiString(FileNameS);
		FILE * pFile;
		size_t result;
		pFile = fopen (file.c_str(), "wb");
		result = fwrite (tbuff , sizeof(Byte), 44 + cb, pFile);
		if (result!=(44 + cb)) {
			ShowMessage("Ошибка записи файла");
		}
		fclose (pFile);
		delete [] tbuff;
	}
}
//---------------------------------------------------------------------------


