#include "MyForm.h"
#include <stdlib.h>     
#include <time.h> 
using namespace System;
using namespace ExamenFinal;

void main() {
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ExamenFinal::MyForm);
}