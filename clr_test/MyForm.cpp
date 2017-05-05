#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
System::Void Main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew clr_test::MyForm());
}
