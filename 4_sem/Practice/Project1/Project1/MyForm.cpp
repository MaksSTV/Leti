#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include "MyForm5.h"
#include "MyForm6.h"
#include "MyForm7.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project1::MyForm form;
	Application::Run(% form);

	Project1::MyForm1 form1;
	Application::Run(% form1);

	Project1::MyForm2 form2;
	Application::Run(% form2);

	Project1::MyForm3 form3;
	Application::Run(% form3);

	Project1::MyForm4 form4;
	Application::Run(% form4);

	Project1::MyForm5 form5;
	Application::Run(% form5);

	Project1::MyForm6 form6;
	Application::Run(% form6);

	Project1::MyForm7 form7;
	Application::Run(% form7);

}