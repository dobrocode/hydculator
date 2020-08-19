#include "MainForm.h"
#include "Windows.h"

using namespace System;
using namespace hydculator;

[STAThreadAttribute]

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	return 0;
}