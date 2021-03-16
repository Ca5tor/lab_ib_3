#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace labib3; // name project

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);

	return 0;
}
