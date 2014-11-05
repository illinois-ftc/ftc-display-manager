#include "MyForm.h"


BOOL CALLBACK on_enumchildwindow_cb(HWND hwndWindow, LPARAM lParam) {
	TCHAR wsTitle[2048];
	LRESULT result;

	result = SendMessage(hwndWindow, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);

	if (_tcscmp(prev_item, L"Red Team 1") == 0){
		window.redTeam1 = hwndWindow;
	}
	if (_tcscmp(prev_item, L"Red Team 2") == 0){
		window.redTeam2 = hwndWindow;
	}
	if (_tcscmp(prev_item, L"Blue Team 1") == 0){
		window.blueTeam1 = hwndWindow;
	}
	if (_tcscmp(prev_item, L"Blue Team 2") == 0){
		window.blueTeam2 = hwndWindow;
	}
	if (_tcscmp(prev_item, L"Current Mode") == 0){
		window.currMode = hwndWindow;
	}
	if (_tcscmp(prev_item, L"Stop Match") == 0){
		window.timing = hwndWindow;
	}

	_tcscpy_s(prev_item, wsTitle);

	return true;
}

BOOL CALLBACK on_enumwindow_cb(HWND hwndWindow, LPARAM lParam) {
	TCHAR wsTitle[2048];
	LRESULT result;

	result = SendMessage(hwndWindow, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);

	if (_tcsstr(wsTitle, L"Samantha") != NULL){

		HANDLE                     hStdOut;
		COORD                      homeCoords = { 0, 0 };
		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

		/* Move the cursor home */
		SetConsoleCursorPosition(hStdOut, homeCoords);
		wprintf(L"%s\n", wsTitle);
		samo = hwndWindow;
		output.FCSConnected = true;

		EnumChildWindows(samo, (WNDENUMPROC)on_enumchildwindow_cb, 0);
		mode = PRE_AUTO;
		return false;
	}

	return true;
}

clock_t starttime = 0;
clock_t zerotime = 0;

DWORD WINAPI ReadFCS(LPVOID lpParam)
{
	output.enabled = false;
	while (true){
		if (samo == NULL) {
			output.FCSConnected = false;
			AcquireSRWLockExclusive(&dispLock);
			_tcscpy_s(output.redDisp1, L" r1 ");
			_tcscpy_s(output.redDisp2, L" r2 ");
			_tcscpy_s(output.blueDisp1, L" b1 ");
			_tcscpy_s(output.blueDisp2, L" b2 ");
			ReleaseSRWLockExclusive(&dispLock);
			if (output.enabled){
				EnumWindows((WNDENUMPROC)on_enumwindow_cb, 0);
			}
		} else {
			TCHAR wsTitle[2048];
			LRESULT result;

			result = SendMessage(window.currMode, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);

			if (mode != AUTO && _tcscmp(wsTitle, L"Autonomous") == 0){
				mode = AUTO;
			} else if (mode != PRE_TELE && _tcscmp(wsTitle, L"Waiting") == 0){
				if (mode == AUTO){
					zerotime = clock();
				}
				mode = PRE_TELE;
				starttime = 0;
			} else if (mode != TELE && _tcscmp(wsTitle, L"Teleop") == 0){
				mode = TELE;
			} else if (mode != PRE_AUTO && _tcscmp(wsTitle, L"Idle") == 0){
				if (mode == TELE){
					zerotime = clock();
				}
				mode = PRE_AUTO;
				starttime = 0;
			} else if (mode != PRE_AUTO && _tcscmp(wsTitle, L"Match Over") == 0){
				mode = PRE_AUTO;
				starttime = 0;
			}
			if (!IsWindow(samo) || !output.enabled){
				mode = INIT;
				samo = NULL;
			}
		}
		long currtime;
		TCHAR timedisp[6];
		TCHAR wsTitle[2048];
		LRESULT result;
		switch (mode){
		case INIT:
			AcquireSRWLockExclusive(&dispLock);
			_tcscpy_s(output.redDisp1, L" r1 ");
			_tcscpy_s(output.redDisp2, L" r2 ");
			_tcscpy_s(output.blueDisp1, L" b1 ");
			_tcscpy_s(output.blueDisp2, L" b2 ");
			ReleaseSRWLockExclusive(&dispLock);
			break;
		case PRE_AUTO:
			if ((clock() - zerotime) / CLOCKS_PER_SEC < 5) {
				_stprintf_s(timedisp, L"%02ld:%02ld", 0, 0);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.redDisp1, timedisp);
				_tcscpy_s(output.redDisp2, timedisp);
				_tcscpy_s(output.blueDisp1, timedisp);
				_tcscpy_s(output.blueDisp2, timedisp);
				ReleaseSRWLockExclusive(&dispLock);
			} else {
				result = SendMessage(window.redTeam1, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.redDisp1, wsTitle);
				ReleaseSRWLockExclusive(&dispLock);

				result = SendMessage(window.redTeam2, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.redDisp2, wsTitle);
				ReleaseSRWLockExclusive(&dispLock);

				result = SendMessage(window.blueTeam1, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.blueDisp1, wsTitle);
				ReleaseSRWLockExclusive(&dispLock);

				result = SendMessage(window.blueTeam2, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.blueDisp2, wsTitle);
				ReleaseSRWLockExclusive(&dispLock);
			}
			break;
		case AUTO:
			if (starttime == 0){
				result = SendMessage(window.timing, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				if (_tcsstr(wsTitle, L"Only") != NULL){
					TCHAR* endpos1ptr = _tcschr(wsTitle + 17, ':');
					int endpos1 = (int)(endpos1ptr - wsTitle + 1);
					TCHAR subbuff[50];
					_tcsncpy_s(subbuff, wsTitle + 17, endpos1 - 17);
					int min = _tstoi(subbuff);
					_tcscpy_s(subbuff, endpos1ptr + 1);
					int sec = _tstoi(subbuff);
					autoTime = sec + min * 60;
				} else {
					TCHAR* endpos1ptr = _tcschr(wsTitle + 12, ':');
					int endpos1 = (int)(endpos1ptr - wsTitle + 1);
					TCHAR subbuff[50];
					_tcsncpy_s(subbuff, wsTitle + 12, endpos1 - 12);
					int min = _tstoi(subbuff);
					_tcscpy_s(subbuff, endpos1ptr + 1);
					int sec = _tstoi(subbuff);
					autoTime = sec + min * 60;
				}
				starttime = clock();
			}
			currtime = (clock() - starttime) / CLOCKS_PER_SEC;
			_stprintf_s(timedisp, L"%02ld:%02ld", (autoTime - currtime) / 60, (autoTime - currtime) % 60);
			AcquireSRWLockExclusive(&dispLock);
			_tcscpy_s(output.redDisp1, timedisp);
			_tcscpy_s(output.redDisp2, timedisp);
			_tcscpy_s(output.blueDisp1, timedisp);
			_tcscpy_s(output.blueDisp2, timedisp);
			ReleaseSRWLockExclusive(&dispLock);
			break;
		case PRE_TELE:
			if ((clock() - zerotime) / CLOCKS_PER_SEC < 5) {
				_stprintf_s(timedisp, L"%02ld:%02ld", 0, 0);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.redDisp1, timedisp);
				_tcscpy_s(output.redDisp2, timedisp);
				_tcscpy_s(output.blueDisp1, timedisp);
				_tcscpy_s(output.blueDisp2, timedisp);
				ReleaseSRWLockExclusive(&dispLock);
			} else {
				result = SendMessage(window.redTeam1, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.redDisp1, wsTitle);
				ReleaseSRWLockExclusive(&dispLock);

				result = SendMessage(window.redTeam2, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.redDisp2, wsTitle);
				ReleaseSRWLockExclusive(&dispLock);

				result = SendMessage(window.blueTeam1, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.blueDisp1, wsTitle);
				ReleaseSRWLockExclusive(&dispLock);

				result = SendMessage(window.blueTeam2, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				AcquireSRWLockExclusive(&dispLock);
				_tcscpy_s(output.blueDisp2, wsTitle);
				ReleaseSRWLockExclusive(&dispLock);
			}
			break;
		case TELE:
			if (starttime == 0){
				result = SendMessage(window.timing, WM_GETTEXT, (WPARAM)2048, (LPARAM)wsTitle);
				if (_tcsstr(wsTitle, L"Only") != NULL){
					TCHAR* startpos1ptr = _tcsstr(wsTitle, L"Teleop");
					TCHAR* endpos1ptr = _tcsrchr(startpos1ptr + 13, ':');
					int endpos1 = (int)(endpos1ptr - startpos1ptr + 1);
					TCHAR subbuff[50];
					_tcsncpy_s(subbuff, startpos1ptr + 13, endpos1 - 13);
					int min = _tstoi(subbuff);
					_tcscpy_s(subbuff, endpos1ptr + 1);
					int sec = _tstoi(subbuff);
					teleTime = sec + min * 60;
				} else {
					TCHAR* startpos1ptr = _tcsstr(wsTitle, L"Teleop");
					TCHAR* endpos1ptr = _tcsrchr(startpos1ptr + 8, ':');
					int endpos1 = (int)(endpos1ptr - startpos1ptr + 1);
					TCHAR subbuff[50];
					_tcsncpy_s(subbuff, startpos1ptr + 8, endpos1 - 8);
					int min = _tstoi(subbuff);
					_tcscpy_s(subbuff, endpos1ptr + 1);
					int sec = _tstoi(subbuff);
					teleTime = sec + min * 60;
				}
				starttime = clock();
			}
			currtime = (clock() - starttime) / CLOCKS_PER_SEC;
			_stprintf_s(timedisp, L"%02ld:%02ld", (teleTime - currtime) / 60, (teleTime - currtime) % 60);
			AcquireSRWLockExclusive(&dispLock);
			_tcscpy_s(output.redDisp1, timedisp);
			_tcscpy_s(output.redDisp2, timedisp);
			_tcscpy_s(output.blueDisp1, timedisp);
			_tcscpy_s(output.blueDisp2, timedisp);
			ReleaseSRWLockExclusive(&dispLock);
			break;
		}


		HANDLE                     hStdOut;
		COORD                      homeCoords = { 0, 1 };
		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

		/* Move the cursor home */
		SetConsoleCursorPosition(hStdOut, homeCoords);
		wprintf(L"Red 1:  |%-4s|    \n", output.redDisp1);
		wprintf(L"Red 2:  |%-4s|    \n", output.redDisp2);
		wprintf(L"Blue 1: |%-4s|    \n", output.blueDisp1);
		wprintf(L"Blue 2: |%-4s|    \n", output.blueDisp2);
		Sleep(20);
	}
}

BOOL sendcommand(String^ msg, SerialPort^ out){
	String^ resp = gcnew String("");
	try{
		out->Write(msg);
		//resp = out->ReadTo(";");
	}
	catch (TimeoutException^ ex)
	{
		Debug::WriteLine(ex->Message);
	}
	if (resp->Equals("r")){
		return true;
	} else {
		return false;
	}
}

DWORD WINAPI SendSerial(LPVOID lpParam)
{
	array<String^>^ serialPorts = nullptr;
	while (true){
		if (SerialPortData::search){
			try
			{
				// Get a list of serial port names.
				serialPorts = SerialPort::GetPortNames();
			}
			catch (Win32Exception^ ex)
			{
				Console::WriteLine(ex->Message);
			}

			// Display each port name to the console. 
			for (int i = 0; i < serialPorts->Length; i++)
			{
				String^ port = serialPorts[i];
				SerialPort^ pingPort = gcnew SerialPort(port);
				pingPort->BaudRate = 9600;
				pingPort->ReadTimeout = 1000;
				String^ pingResp = gcnew String("");
				try {
					pingPort->Open();
					pingPort->Write("p;");
					pingResp = pingPort->ReadTo(";");
				}
				catch (TimeoutException^ ex)
				{
					Debug::WriteLine(ex->Message);
				}
				catch (UnauthorizedAccessException^ ex)
				{
					Debug::WriteLine(ex->Message);
				}
				catch (System::IO::IOException^ ex)
				{
					Debug::WriteLine(ex->Message);
				}
				try{
					pingPort->Close();
				}
				catch (TimeoutException^ ex)
				{
					Debug::WriteLine(ex->Message);
				}
				catch (System::IO::IOException^ ex)
				{
					Debug::WriteLine(ex->Message);
				}
				if (!pingResp->Equals("ardFCSv1")){
					serialPorts[i] = nullptr;
				}
			}
			AcquireSRWLockExclusive(&comLock);
			SerialPortData::serialPorts->Clear();
			for each (String^ portname in serialPorts){
				if (SerialPortData::chosenPort != nullptr && SerialPortData::chosenPort->Equals(portname)){
					SerialPortData::search = false;
				} else if (portname != nullptr) {
					SerialPortData::serialPorts->Add(portname);
				} 
			}
			ReleaseSRWLockExclusive(&comLock);
			Sleep(50);
		} else {
			SerialPort^ dispPort = gcnew SerialPort(SerialPortData::chosenPort);
			dispPort->BaudRate = 9600;
			dispPort->ReadTimeout = 1000;
			while (!SerialPortData::search){
				try {
					dispPort->Open();
					sendcommand(output.dispEnabled ? "e;" : "d;", dispPort);
					sendcommand(String::Format("b{0};", output.brightness), dispPort);
					if (_tcscmp(output.blueDisp1, output.redDisp2) == 0 && _tcscmp(output.blueDisp1, output.blueDisp2) == 0 && _tcscmp(output.redDisp1, output.redDisp2) == 0) {
						_TCHAR out[7];
						_tcscpy_s(out, output.blueDisp1);
						if (out[2] == ':'){
							sendcommand("ca1;",dispPort);
							out[2] = out[3];
							out[3] = out[4];
							out[4] = out[5];
						} else {
							sendcommand("ca0;", dispPort);
						}
						sendcommand(String::Format("wa{0,4};", gcnew String(out)), dispPort);
					} else {
						sendcommand("ca0;", dispPort);
						sendcommand(String::Format("wo{1},{0,4};", gcnew String(output.redDisp1), output.rd1), dispPort);
						sendcommand(String::Format("wo{1},{0,4};", gcnew String(output.redDisp2), output.rd2), dispPort);
						sendcommand(String::Format("wo{1},{0,4};", gcnew String(output.blueDisp1), output.bd1), dispPort);
						sendcommand(String::Format("wo{1},{0,4};", gcnew String(output.blueDisp2), output.bd2), dispPort);
					}
				}
				catch (UnauthorizedAccessException^ ex)
				{
					Debug::WriteLine(ex->Message);
				}
				catch (System::IO::IOException^ ex)
				{
					Debug::WriteLine(ex->Message);
					SerialPortData::search = true;
				}
				try{
					dispPort->Close();
				}
				catch (System::IO::IOException^ ex)
				{
					Debug::WriteLine(ex->Message);
					SerialPortData::search = true;
				}
				Sleep(50);
			}
		}
	}
}

[STAThread]
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	output.dispEnabled = true;
	output.brightness = 15;

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	InitializeSRWLock(&dispLock);

	CreateThread(
		NULL,                   // default security attributes
		0,                      // use default stack size  
		ReadFCS,       // thread function name
		NULL,          // argument to thread function 
		0,                      // use default creation flags 
		NULL);

	CreateThread(
		NULL,                   // default security attributes
		0,                      // use default stack size  
		SendSerial,       // thread function name
		NULL,          // argument to thread function 
		0,                      // use default creation flags 
		NULL);

	FCSDisplayController::MyForm form;
	Application::Run(%form);
}