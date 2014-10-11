#include <string>
#include "tchar.h"
#include "Windows.h"
#include <ctime>
#using <System.dll>
using namespace System;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;
using namespace System::IO::Ports;
using namespace System::ComponentModel;

typedef enum {
	INIT,
	PRE_AUTO,
	AUTO,
	PRE_TELE,
	TELE
} modes;

typedef struct {
	HWND redTeam1;
	HWND redTeam2;
	HWND blueTeam1;
	HWND blueTeam2;
	HWND currMode;
	HWND timing;
} samoWindow;

typedef struct {
	TCHAR redDisp1[2048];
	TCHAR redDisp2[2048];
	TCHAR blueDisp1[2048];
	TCHAR blueDisp2[2048];
	int brightness;
	int rd1;
	int rd2;
	int bd1;
	int bd2;
	BOOL FCSConnected;
	BOOL enabled;
	BOOL dispEnabled;
} outputContent;

ref struct SerialPortData {
	static bool search = true;
	static ArrayList^ serialPorts = gcnew ArrayList;
	static String^ chosenPort = nullptr;
};

long autoTime = 30;
long teleTime = 120;

TCHAR prev_item[2048];
HWND samo = NULL;
modes mode = INIT;
outputContent output;
samoWindow window;

SRWLOCK dispLock;

SRWLOCK comLock;