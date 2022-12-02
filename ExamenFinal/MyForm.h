#pragma 
#include "controller.h"
#include <string>
#include <string.h>
namespace ExamenFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: 
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ bmpHero;
		Bitmap^ bmpEnemy;
		Bitmap^ bmpMap1;
		Bitmap^ bmpMap2;
		Bitmap^ bmpBomba; 
		
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

		Controller* objController;

	public:
		MyForm(void)
		{
			InitializeComponent();

			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			bmpHero = gcnew Bitmap("hero.png");
			bmpEnemy = gcnew Bitmap("Enemy.png");
			bmpBomba = gcnew Bitmap("boom.png");

			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpEnemy->MakeTransparent(bmpEnemy->GetPixel(0, 0));

			objController = new Controller();

			bmpMap1 = gcnew Bitmap("fondo.jpg");
			bmpMap2 = gcnew Bitmap("fondo2.jpg");
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(254, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(858, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(990, 15);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 71);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 29);
			this->label5->TabIndex = 4;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(254, 71);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(79, 29);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(12, 127);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(79, 29);
			this->label7->TabIndex = 6;
			this->label7->Text = L"label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(254, 127);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 29);
			this->label8->TabIndex = 7;
			this->label8->Text = L"label8";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1081, 686);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			objController->getHero()->mover(buffer->Graphics, char(75)); break;
		case Keys::Right:
			objController->getHero()->mover(buffer->Graphics, char(77)); break;
		case Keys::Up:
			objController->getHero()->mover(buffer->Graphics, char(72)); break;
		case Keys::Down:
			objController->getHero()->mover(buffer->Graphics, char(80)); break;
		case Keys::B: 
			objController->agregarBomba(); break; 
		
			
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		

		buffer->Graphics->DrawImage(bmpMap1, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);

		objController->moverTodo(buffer->Graphics);
		objController->mostrarTodo(buffer->Graphics,bmpBomba,bmpHero,bmpEnemy);
		objController->colision(); 



		label1->Text = "VIDA ENEMIGO 1: ";
		label5->Text = "VIDA ENEMIGO 2: ";
		label7->Text = "VIDA ENEMIGO 3: ";
		label3->Text = "PUNTOS: ";
		label4->Text = Convert::ToString(objController->getPuntos());
		label2->Text = Convert::ToString(objController->getEnemis()->at(0)->getvida());
		label6->Text = Convert::ToString(objController->getEnemis()->at(1)->getvida());
		label8->Text = Convert::ToString(objController->getEnemis()->at(2)->getvida());

		if (objController->getPuntos() == 120) {
			MessageBox::Show("ENEMIGOS ELIMINADOS"+ Convert::ToString(objController->getEnemigosEliminados()));
		}
		for (int  i = 0; i < objController->getEnemis()->size(); i++)
		{
			if (objController->getEnemis()->at(i)->getvida() == 0) {
				MessageBox::Show("SE TERMINO EL JUEGO"); 
				exit(0); 
			}
		}




		buffer->Render(g);
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
