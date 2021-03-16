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

// Проверка что поле не пустое
bool InputValidation(TextBox^ Tx, String^ s, double& d) {
	if (Tx->Text->Length == 0) {
		MessageBox::Show(s, "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		Tx->Focus();
		return false;
	}
	d = Convert::ToDouble(Tx->Text);

	return true;
}

System::Void labib3::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e){
	
	double P = 0., V = 0., T = 0.;

	if (!InputValidation(textBox1, "Введите значение P", P)) return;
	if (!InputValidation(textBox2, "Введите значение V", V)) return;
	if (!InputValidation(textBox3, "Введите значение T", T)) return;



	return System::Void();
}

