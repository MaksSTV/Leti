#pragma once

#include <windows.h>
#include <cmath>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm7
	/// </summary>
	public ref class MyForm7 : public System::Windows::Forms::Form
	{
	public:
		MyForm7(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm7()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(54, 48);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(355, 337);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm7::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(54, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// MyForm7
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(475, 397);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm7";
			this->Text = L"MyForm7";
			this->Load += gcnew System::EventHandler(this, &MyForm7::MyForm7_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm7_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Окружность";
		label1->Text = "Рисовашки";
	}
	private: void Paint_Circle(int cX, int cY, int centX, int centY, int radius, int x, int y)
	{
		Graphics^ Графика = pictureBox1->CreateGraphics();
		Графика->DrawEllipse(Pens::Black, centX + cX - radius, cY - radius - centY, radius * 2, radius * 2);
		Графика->DrawLine(Pens::Black, centX + cX, cY - centY, cX + x, cY + y);
		// прорисовка радиуса большей окружности
	}
	private: void Paint_Graphic(int cX, int cY, int r2, int x, int y, array<Point>^ p)
	{
		Graphics^ Графика = pictureBox1->CreateGraphics();
		Графика->Clear(BackColor);
		Paint_Circle(cX, cY, 0, 0, r2, x, y);
		Графика->DrawLines(Pens::Red, p); // траектория
	}
		   
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		double InitT = 0, LastT = 6.3; // оборот в 360 градусов (6,28 радиан)
		double Step = 0.1, angle = InitT;
		double x, y, x1, y1;
		int cX = 120, cY = 120; // центр большой окружности
		int R2 = 90; // радиус большой окружности
		int k = 20; // число областей на траектории
		int R1 = int(R2 / k); // радиус меньшей (движущейся) окружности
		int i = 0; // количество точек прорисовки
		cli::array<Point>^ p;
		p = gcnew array<Point>(64); // точки для прорисовки (LastT/Step)
		while (angle <= LastT)
		{
			x = R1 * (k - 1) * (cos(angle) + cos((k - 1) * angle) / (k - 1));
			y = R1 * (k - 1) * (sin(angle) - sin((k - 1) * angle) / (k - 1));
			p[i] = Drawing::Point(cX + int(x), cY + int(y)); // расчет очередной точки траектории
			Paint_Graphic(cX, cY, R2, x, y, p);
			x1 = (R2 - R1) * sin(angle + 1.57);
			y1 = (R2 - R1) * cos(angle + 1.57);
			Paint_Circle(cX, cY, int(x1), int(y1), R1, x, y);
			angle += Step;
			::Sleep(40); //время приостановки прорисовки
			i++;
		}
	}
};
}
