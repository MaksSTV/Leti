#pragma once
#include <windows.h>
#include <math.h>
#include <string>
# define M_PI 3.14159265358979323846

namespace testfroms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum class FigureAnchores { Center, LeftBottomAngle, LeftTopAngle, RightTopAngle, RightBottomAngle };



	public ref class FigureForm : public System::Windows::Forms::Form
	{

	public:
		FigureForm(void)
		{
			InitializeComponent();
		}

	protected:
		~FigureForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox5;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TrackBar^ trackBar3;








	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(1, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(576, 566);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &FigureForm::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FigureForm::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(594, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Paralellogramm Parameters";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(594, 300);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(184, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Trajectory parameters";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(595, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Sides";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(595, 67);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Angle";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Maroon;
			this->label5->Location = System::Drawing::Point(595, 93);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"error_label";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(632, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(56, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &FigureForm::textBox1_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(690, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(25, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"and";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(718, 37);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(56, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &FigureForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(632, 63);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(56, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &FigureForm::textBox3_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(595, 119);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Figure anchor:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(784, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FigureForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Center", L"LeftBottomAngle", L"LeftTopAngle",
					L"RightTopAngle", L"RightBottomAngle"
			});
			this->comboBox1->Location = System::Drawing::Point(676, 116);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FigureForm::comboBox1_SelectedIndexChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(598, 148);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Change color";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FigureForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(598, 327);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(99, 23);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Change color";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FigureForm::button3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(703, 148);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(25, 23);
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(703, 327);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(25, 23);
			this->pictureBox3->TabIndex = 16;
			this->pictureBox3->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(598, 201);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 45);
			this->trackBar1->TabIndex = 17;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &FigureForm::trackBar1_Scroll);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(596, 185);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(38, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Width:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(601, 362);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(38, 13);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Width:";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(604, 378);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(104, 45);
			this->trackBar2->TabIndex = 19;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &FigureForm::trackBar2_Scroll);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(595, 249);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(59, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"Dash style:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(601, 419);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(59, 13);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Dash style:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Solid", L"Dash", L"DashDot", L"DashDotDot", L"Dot" });
			this->comboBox2->Location = System::Drawing::Point(594, 265);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 24;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &FigureForm::comboBox2_SelectedIndexChanged);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Solid", L"Dash", L"DashDot", L"DashDotDot", L"Dot" });
			this->comboBox3->Location = System::Drawing::Point(604, 435);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 25;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &FigureForm::comboBox3_SelectedIndexChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(868, 337);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(84, 13);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Full circle count:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(958, 334);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(47, 20);
			this->textBox4->TabIndex = 27;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(958, 361);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 28;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(856, 362);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(96, 13);
			this->label13->TabIndex = 29;
			this->label13->Text = L"Reverse trajectory:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(881, 388);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(71, 13);
			this->label14->TabIndex = 30;
			this->label14->Text = L"Radius scale:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(958, 385);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(47, 20);
			this->textBox5->TabIndex = 31;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(911, 419);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(41, 13);
			this->label15->TabIndex = 32;
			this->label15->Text = L"Speed:";
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(958, 411);
			this->trackBar3->Maximum = 100;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(104, 45);
			this->trackBar3->TabIndex = 33;
			// 
			// FigureForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1093, 594);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FigureForm";
			this->Text = L"FigureForm";
			this->Load += gcnew System::EventHandler(this, &FigureForm::FigureForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Pen^ figurepen;
		Pen^ trajectorypen;


	private: System::Void FigureForm_Load(System::Object^ sender, System::EventArgs^ e) {
		figurepen = gcnew Pen(Color::Red);
		trajectorypen = gcnew Pen(Color::Blue);

		comboBox1->Text = "Center";
		label5->Text = "";

		textBox1->Text = "20";
		textBox2->Text = "20";
		textBox3->Text = "30";

		pictureBox2->BackColor = Color::Red;
		pictureBox3->BackColor = Color::Blue;

		textBox4->Text = "1";
		comboBox2->Text = "Solid";
		comboBox3->Text = "Solid";

		textBox5->Text = "3";
		trackBar3->Value = 80;
	}

	private: void RecalculateParallelogram() {

		try {
			double side1 = Convert::ToDouble(textBox1->Text);
			double side2 = Convert::ToDouble(textBox2->Text);
			double angle = Convert::ToDouble(textBox3->Text);

			if (side1 <= 0 || side2 <= 0 || angle <= 0) {
				label5->Text = "Wrong params!";
			}
			else
			{
				label5->Text = "";
			}
		}
		catch (...) {
			label5->Text = "Wrong params!";
		}
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		RecalculateParallelogram();
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		RecalculateParallelogram();
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		RecalculateParallelogram();
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {



	}

	private: void Paint_Parallelogram(Point point)//, Pen pen
	{
		FigureAnchores anchore = FigureAnchores::Center;

		switch (comboBox1->SelectedIndex)
		{
		case -1:
			anchore = FigureAnchores::Center;
			break;
		case 0:
			anchore = FigureAnchores::Center;
			break;
		case 1:
			anchore = FigureAnchores::LeftBottomAngle;
			break;
		case 2:
			anchore = FigureAnchores::LeftTopAngle;
			break;
		case 3:
			anchore = FigureAnchores::RightTopAngle;
			break;
		case 4:
			anchore = FigureAnchores::RightBottomAngle;
			break;
		}

		double x = point.X;
		double y = point.Y;

		//x = x * cos(M_PI / 5) - y*sin(M_PI / 5);
		//y = x * sin(M_PI / 5) + y*sin(M_PI / 5);

		double side1 = Convert::ToDouble(textBox1->Text);
		double side2 = Convert::ToDouble(textBox2->Text);
		double angle = Convert::ToDouble(textBox3->Text);

		double diag1 = sqrt(side1 * side1 + side2 * side2 - 2 * side1 * side2 * cos(angle * M_PI / 180));
		double diag2 = sqrt(side1 * side1 + side2 * side2 - 2 * side1 * side2 * cos((180 - angle) * M_PI / 180));
		double h = side2 * sin(angle * M_PI / 180);
		double offset = 0;

		Graphics^ G = pictureBox1->CreateGraphics();
		array<Point>^ points = gcnew array<Point>(4);

		switch (anchore) {
		case FigureAnchores::Center:
			offset = sqrt(diag1 * diag1 / 4 - h * h / 4);
			points[0] = Point(int(x - side1 + offset), int(y + h / 2));
			points[1] = Point(int(x - offset), int(y - h / 2));
			points[2] = Point(int(x + side1 - offset), int(y - h / 2));
			points[3] = Point(int(x + offset), int(y + h / 2));
			break;
		case FigureAnchores::LeftBottomAngle:
			offset = sqrt(side2 * side2 / 4 - h * h / 4);
			points[0] = Point(x, y);
			points[1] = Point(int(x + offset), int(y - h));
			points[2] = Point(int(x + side1 + offset), int(y - h));
			points[3] = Point(int(x + side1), y);
			break;

		case FigureAnchores::LeftTopAngle:
			offset = sqrt(side2 * side2 / 4 - h * h / 4);
			points[0] = Point(int(x - offset), int(y + h));
			points[1] = Point(x, y);
			points[2] = Point(int(x + side1), y);
			points[3] = Point(int(x + side1 - offset), int(y + h));
			break;

		case FigureAnchores::RightTopAngle:
			offset = sqrt(side2 * side2 / 4 - h * h / 4);
			points[0] = Point(int(x - side1 - offset), int(y + h));
			points[1] = Point(int(x - side1), y);
			points[2] = Point(x, y);
			points[3] = Point(int(x - offset), int(y + h));
			break;

		case FigureAnchores::RightBottomAngle:
			offset = sqrt(side2 * side2 / 4 - h * h / 4);
			points[0] = Point(int(x - side1), y);
			points[1] = Point(int(x - side1 + offset), int(y - h));
			points[2] = Point(int(x + offset), int(y - h));
			points[3] = Point(x, y);
			break;
		}

		G->DrawLine(figurepen, points[0], points[1]);
		G->DrawLine(figurepen, points[1], points[2]);
		G->DrawLine(figurepen, points[2], points[3]);
		G->DrawLine(figurepen, points[3], points[0]);
	}

	private: void Paint_Graphic(array<Point>^ points, int count)
	{
		Graphics^ G = pictureBox1->CreateGraphics();
		G->Clear(BackColor);

		while (count != 0) {
			G->DrawLine(trajectorypen, points[count], points[count - 1]);
			count--;
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double circleCoef = Convert::ToDouble(textBox4->Text);
		double InitT = 0, LastT = 6.28 * circleCoef;
		double Step = 0.01, angle = InitT;
		double x, y;
		int cX = 300, cY = 300;
		int i = 0;
		double radiusMuliplier = Convert::ToDouble(textBox5->Text);
		int delay = trackBar3->Maximum - trackBar3->Value + 1;


		if (checkBox1->Checked) {
			Step = -abs(Step);
		}
		else {
			Step = abs(Step);
		}

		array<Point>^ points = gcnew array<Point>(LastT / abs(Step) + 1);

		Graphics^ G = pictureBox1->CreateGraphics();

		while (abs(angle) <= LastT)
		{
			double radius = radiusMuliplier * (30 + 15 * sin(60 * angle) * sin(2.5 * angle));

			x = radius * cos(angle);
			y = radius * sin(angle);

			points[i] = Point(cX + x, cY + y);

			G->Clear(BackColor);

			Paint_Graphic(points, i);
			Paint_Parallelogram(points[i]);
			Sleep(delay);

			angle += Step;
			i++;
		}


		i--;
		G->Clear(BackColor);
		Paint_Parallelogram(points[i]);
		while (i > 0) {
			G->DrawLine(trajectorypen, points[i], points[i - 1]);
			i--;
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			Color color = colorDialog1->Color;
			figurepen->Color = color;
			pictureBox2->BackColor = color;

		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			Color color = colorDialog1->Color;
			trajectorypen->Color = color;
			pictureBox3->BackColor = color;
		}
	}

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		figurepen->Width = trackBar1->Value * 1.0F;
	}

	private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
		trajectorypen->Width = trackBar1->Value * 1.0F;

	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		System::Drawing::Drawing2D::DashStyle style = System::Drawing::Drawing2D::DashStyle::Solid;

		switch (comboBox2->SelectedIndex)
		{
		case -1:
			style = System::Drawing::Drawing2D::DashStyle::Solid;
			break;
		case 0:
			style = System::Drawing::Drawing2D::DashStyle::Solid;
			break;
		case 1:
			style = System::Drawing::Drawing2D::DashStyle::Dash;
			break;
		case 2:
			style = System::Drawing::Drawing2D::DashStyle::DashDot;
			break;
		case 3:
			style = System::Drawing::Drawing2D::DashStyle::DashDotDot;
			break;
		case 4:
			style = System::Drawing::Drawing2D::DashStyle::Dot;
			break;
		}
		figurepen->DashStyle = style;
	}

	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		System::Drawing::Drawing2D::DashStyle style = System::Drawing::Drawing2D::DashStyle::Solid;

		switch (comboBox3->SelectedIndex)
		{
		case -1:
			style = System::Drawing::Drawing2D::DashStyle::Solid;
			break;
		case 0:
			style = System::Drawing::Drawing2D::DashStyle::Solid;
			break;
		case 1:
			style = System::Drawing::Drawing2D::DashStyle::Dash;
			break;
		case 2:
			style = System::Drawing::Drawing2D::DashStyle::DashDot;
			break;
		case 3:
			style = System::Drawing::Drawing2D::DashStyle::DashDotDot;
			break;
		case 4:
			style = System::Drawing::Drawing2D::DashStyle::Dot;
			break;
		}
		trajectorypen->DashStyle = style;
	}

	};
}