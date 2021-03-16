#include "MyForm.h"
#include <Windows.h>
#include <cmath>

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

String^ StringConcatenation(String^ pas, String^ s, CheckBox^ cb) {
	cb->Checked == true ? pas += s : pas = pas;
	return pas;
}

System::Void labib3::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e){
	
	double p = Convert::ToDouble(textBox1->Text);
	int v = Convert::ToInt32(textBox2->Text);
	int t = Convert::ToInt32(textBox3->Text);
	
	// �������� ������ � ���, �������� ��: ���-�� ���� � ��� = 7, ���-�� ����� � 1 ��� = 24 � ���-�� ��� � 1 ���� = 60 
	t *= 10080;

	String^ BigRu = "�����Ũ��������������������������";
	String^ SmallRu = "��������������������������������";
	String^ BigEng = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	String^ SmallEng = "abcdefghijklmnopqrstuvwxyz";
	String^ Symbols = "!@#$%^&*()-_=+:;�.,\"\'?<>\|\\\/";
	String^ Numbers = "123456789";
	String^ SymbolsToUse = ""; // ������ ��� ����� ���������� ������� ��� ��������� ������
	String^ Password = "";

	// ��������� � ����� ������ �� ������� ������� ������� ����� checkBox
	SymbolsToUse = StringConcatenation(SymbolsToUse, BigEng,   checkBox1);
	SymbolsToUse = StringConcatenation(SymbolsToUse, SmallEng, checkBox2);
	SymbolsToUse = StringConcatenation(SymbolsToUse, BigRu,    checkBox3);
	SymbolsToUse = StringConcatenation(SymbolsToUse, SmallRu,  checkBox4);
	SymbolsToUse = StringConcatenation(SymbolsToUse, Symbols,  checkBox5);
	SymbolsToUse = StringConcatenation(SymbolsToUse, Numbers,  checkBox6);

	double s = ceil(double(v * t) / p); // ������� s � ����������� �����
	label7->Text = s.ToString();

	int a = SymbolsToUse->Length; // ���������� ��������, ������� ����� ���� ������������ ��� ����������� ������
	label8->Text = a.ToString();

	// ��������� ���-�� log �������� �������� L(����� ������) � ����������� �� ���������� ������ �����
	int l = ceil(log(double(v * t) / p) / log(a));
	label9->Text = l.ToString();

	
	s <= pow(a, l) ? label12->Text = "True" : label12->Text = "False";

	for (int i = 0; i != l; i++) Password += SymbolsToUse[rand() % a];
	
	label10->Text = "������: " + Password->Replace("&", "&&");

	return System::Void();
}