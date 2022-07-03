#pragma once

#include <Windows.h>
#include <cmath>


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;






	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;

	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Splitter^ splitter1;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::ComboBox^ comboBox6;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ textBox9;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(12, 72);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(481, 598);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(202, 22);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 44);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(948, 251);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 35);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Изменить цвет";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(1118, 251);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(39, 35);
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->Location = System::Drawing::Point(661, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(121, 57);
			this->pictureBox3->TabIndex = 11;
			this->pictureBox3->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(941, 92);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(113, 56);
			this->trackBar1->TabIndex = 12;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Solid", L"Dash", L"DashDot", L"DashDotDot", L"Dot" });
			this->comboBox1->Location = System::Drawing::Point(1036, 185);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 13;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1033, 166);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"контур";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(928, 53);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 16);
			this->label6->TabIndex = 15;
			this->label6->Text = L"толщина";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(948, 433);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(164, 36);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Изменить цвет";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(1118, 433);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(39, 36);
			this->pictureBox4->TabIndex = 17;
			this->pictureBox4->TabStop = false;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Solid", L"Dash", L"DashDot", L"DashDotDot", L"Dot" });
			this->comboBox2->Location = System::Drawing::Point(784, 440);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 19;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(550, 486);
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(142, 56);
			this->trackBar3->TabIndex = 20;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(547, 389);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(147, 16);
			this->label7->TabIndex = 21;
			this->label7->Text = L"скорость прорисовки";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(781, 408);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(53, 16);
			this->label8->TabIndex = 22;
			this->label8->Text = L"контур";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(547, 467);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(63, 16);
			this->label9->TabIndex = 23;
			this->label9->Text = L"толщина";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(546, 354);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(79, 22);
			this->label10->TabIndex = 24;
			this->label10->Text = L"График";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(544, 26);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(77, 22);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Фигура";
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 682);
			this->splitter1->TabIndex = 26;
			this->splitter1->TabStop = false;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Равносторонний ", L"Как на картинке" });
			this->comboBox3->Location = System::Drawing::Point(568, 135);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(177, 24);
			this->comboBox3->TabIndex = 27;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(565, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 16);
			this->label2->TabIndex = 28;
			this->label2->Text = L"вариант пятиугольника";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(566, 172);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(133, 16);
			this->label3->TabIndex = 29;
			this->label3->Text = L"координата острия";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(566, 216);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(230, 16);
			this->label4->TabIndex = 30;
			this->label4->Text = L"координата верхнего левого угла";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(565, 261);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(225, 16);
			this->label12->TabIndex = 31;
			this->label12->Text = L"координата нижнего левого угла";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(781, 172);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(180, 16);
			this->label13->TabIndex = 32;
			this->label13->Text = L"сторона равностороннего";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(568, 191);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(53, 22);
			this->textBox1->TabIndex = 33;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(635, 191);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(54, 22);
			this->textBox2->TabIndex = 34;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(569, 236);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(56, 22);
			this->textBox3->TabIndex = 35;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(635, 235);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(57, 22);
			this->textBox4->TabIndex = 36;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(568, 290);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(57, 22);
			this->textBox5->TabIndex = 37;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(635, 289);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(54, 22);
			this->textBox6->TabIndex = 38;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(784, 191);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 22);
			this->textBox7->TabIndex = 39;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Да", L"Нет" });
			this->comboBox4->Location = System::Drawing::Point(1078, 41);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(121, 24);
			this->comboBox4->TabIndex = 40;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox4_SelectedIndexChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(1078, 19);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(78, 16);
			this->label14->TabIndex = 41;
			this->label14->Text = L"Пульсация";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(550, 420);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 22);
			this->textBox8->TabIndex = 42;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox8_TextChanged);
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Нет", L"Против часовой", L"По часовой" });
			this->comboBox5->Location = System::Drawing::Point(1078, 92);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(121, 24);
			this->comboBox5->TabIndex = 43;
			this->comboBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox5_SelectedIndexChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(1078, 72);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(73, 16);
			this->label15->TabIndex = 44;
			this->label15->Text = L"Вращение";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Да", L"Нет" });
			this->comboBox6->Location = System::Drawing::Point(1078, 142);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(121, 24);
			this->comboBox6->TabIndex = 45;
			this->comboBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox6_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(1078, 123);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(71, 16);
			this->label16->TabIndex = 46;
			this->label16->Text = L"Инверсия";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(802, 26);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(104, 16);
			this->label17->TabIndex = 47;
			this->label17->Text = L"угол вращения";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(805, 53);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 22);
			this->textBox9->TabIndex = 48;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox9_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1309, 682);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		Pen^ figurepen;
		Pen^ trajectorypen;
		int sleep = 180;
		int pulse = 0;
		int rotate = 0;
		int inversion = 0;
		int angle = 10;
		int side = 25;

		int xCordAngle = 20;
		int yCordAngle = 0;
		int xCordUpLeft = -10;
		int yCordUpLeft = -10;
		int xCordDownLeft = -10;
		int yCordDownLeft = 10;
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		figurepen = gcnew Pen(Color::Black);
		trajectorypen = gcnew Pen(Color::Blue);

		this->Text = "Рисуем";
		button1->Text = "Нарисовать";
		label1->Text = "y = |x * x - 4|";

		comboBox1->Text = "Solid";
		comboBox3->Text = "Нет";
		comboBox2->Text = "Solid";
		comboBox4->Text = "Нет";
		comboBox5->Text = "Нет";
		comboBox6->Text = "Нет";


		textBox1->Text = "20";
		textBox2->Text = "0";
		textBox3->Text = "-10";
		textBox4->Text = "-10";
		textBox5->Text = "-10";
		textBox6->Text = "10";
		textBox7->Text = "25";
		textBox8->Text = "100";
		textBox9->Text = "10";

		pictureBox2->BackColor = Color::Black;
		pictureBox4->BackColor = Color::Black;

	}


	private: void Paint_Graphic(array<Point>^ p, int i)
	{
		Graphics^ Графика = pictureBox1->CreateGraphics();
		Графика->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		Графика->Clear(BackColor);
		while (i != 0) {
			Графика->DrawLine(trajectorypen, p[i], p[i-1]); // траектория
			i--;
		}
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		


	}
		
	private: void Paint_Pentagram(Point point, int angle, int k)//, Pen pen
	{

		double x = point.X;
		double y = point.Y;

		Graphics^ G = pictureBox1->CreateGraphics();
		Brush^ zalivka = gcnew SolidBrush(pictureBox2->BackColor);
	

		switch (comboBox3->SelectedIndex)
		{
		case 0:
			cli::array<Point> ^ points;
			points = gcnew array<Point>(5);

			for (int i = 0; i < 5; i++)
			{
				points[i] = Point(
					(int)(x + side * k * cos((angle + (2 * 3.14 * i) / 5))),
					(int)(y + side * k * sin(angle + (2 * 3.14 * i) / 5)));
			}
			G->DrawLine(figurepen, points[0], points[1]);
			G->DrawLine(figurepen, points[1], points[2]);
			G->DrawLine(figurepen, points[2], points[3]);
			G->DrawLine(figurepen, points[3], points[4]);
			G->DrawLine(figurepen, points[4], points[0]);

			
			G->FillPolygon(zalivka, points);
			break;
		case 1:

			cli::array<Point>^ curvePoints;
			curvePoints = gcnew array<Point>(5);

			if (rotate != 0) {
				curvePoints[0] = Point(
					((xCordUpLeft * k) * cos(angle) - (xCordUpLeft * k) * sin(angle) + x),
					((yCordUpLeft * k) * sin(angle) + (yCordUpLeft * k) * cos(angle) + y));
				curvePoints[1] = Point(
					((abs(xCordUpLeft) * k) * cos(angle) - (yCordUpLeft * k) * sin(angle) + x),
					((yCordUpLeft * k) * sin(angle) + (abs(xCordUpLeft) * k) * cos(angle) + y));
				curvePoints[2] = Point(
					((xCordAngle * k) * cos(angle) - yCordAngle * sin(angle) + x),
					(yCordAngle * sin(angle) + (xCordAngle * k) * cos(angle) + y));
				curvePoints[3] = Point(
					((abs(xCordDownLeft) * k) * cos(angle) - (yCordDownLeft * k) * sin(angle) + x),
					((yCordDownLeft * k) * sin(angle) + (abs(xCordDownLeft) * k) * cos(angle) + y));
				curvePoints[4] = Point(
					(xCordDownLeft * cos(angle) - yCordDownLeft * sin(angle) + x),
					(yCordDownLeft * sin(angle) + (xCordDownLeft)*cos(angle) + y));
			}
			if (rotate == 0) {
				curvePoints[0] = Point(
					(xCordUpLeft + x),
					(yCordUpLeft + y));
				curvePoints[1] = Point(
					(abs(xCordUpLeft) + x),
					(yCordUpLeft + y));
				curvePoints[2] = Point(
					(xCordAngle + x),
					(yCordAngle + y));
				curvePoints[3] = Point(
					(abs(xCordDownLeft) + x),
					(yCordDownLeft + y));
				curvePoints[4] = Point(
					(xCordDownLeft + x),
					(yCordDownLeft + y));
			}

			G->DrawPolygon(figurepen, curvePoints);
			G->FillPolygon(zalivka, curvePoints);

			break;
		}
		
	}
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Refresh();
		double x, y;
		int cX = 120, cY = 400; // центр большой окружности
		int i = 0; // количество точек прорисовки
		cli::array<Point>^ p;
		p = gcnew array<Point>(39); // точки для прорисовки (LastT/Step)

		Graphics^ G = pictureBox1->CreateGraphics();
		x = -19.0;
		if(inversion == 0){ y = -abs(x * x - 40); }
		else { y = abs(x * x - 40); cY = 50; }
		p[i] = Drawing::Point(cX + int(x) * 3.5, cY + int(y)); // расчет очередной точки траектории
		
		int angleZero = 0;
		int k = 1;
		for (i = 1; i < 39; i++) {
			x = x + 1;
			if (inversion == 0) { y = -abs(x * x - 40); }
			else { y = abs(x * x - 40); cY = 50; }


			G->Clear(BackColor);
			p[i] = Drawing::Point(cX + int(x) * 3.5, cY + int(y)); // расчет очередной точки траектории
			Paint_Graphic(p, i);
			Paint_Pentagram(p[i], angleZero, k);
			if (rotate == 1) {
				angleZero = angleZero + angle;
			}
			else if (rotate == 2) {
				angleZero = angleZero - angle;
			}
			else if (rotate == 0) {
				angleZero = angleZero;
			}

			if (pulse == 1) {
				if (i % 5 == 0) {
					k = 0.5;
				}
				else if (i % 5 == 1) {
					k = 1.2;
				}
				else if (i % 5 == 2) {
					k = 1.7;
				}
				else if (i % 5 == 3) {
					k = 2.1;
				}
				else if (i % 5 == 4) {
					k = 1;
				}
			}
			::Sleep(sleep); //время приостановки прорисовки
		}

		i--;
		G->Clear(BackColor);
		Paint_Pentagram(p[i], angleZero,k);
		while (i > 0) {
			G->DrawLine(trajectorypen, p[i], p[i - 1]);
			i--;
		}

	}
	
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		System::Drawing::Drawing2D::DashStyle style = System::Drawing::Drawing2D::DashStyle::Solid;

		switch (comboBox1->SelectedIndex)
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
		trajectorypen->DashStyle = style;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			   Color color = colorDialog1->Color;
			   //figurepen->Color = color;
			   pictureBox2->BackColor = color;
	    }
    }

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			Color color = colorDialog1->Color;
			trajectorypen->Color = color;
			pictureBox4->BackColor = color;
		}
	}

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		figurepen->Width = trackBar1->Value * 1.0F;
	}

	private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
		trajectorypen->Width = trackBar3->Value * 1.0F;

	}

	private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		sleep = Convert::ToInt64(textBox8->Text);
	}

	private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (comboBox4->SelectedIndex)
		{
		case 0:
			pulse = 1;
			break;
		case 1:
			pulse = 0;
			break;
		}
	
	}

	private: System::Void comboBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (comboBox5->SelectedIndex)
		{
		case 0:
			rotate = 0;
			break;
		case 1:
			rotate = 1;
			break;
		case 2:
			rotate = 2;
			break;
		}
	
	}

	private: System::Void comboBox6_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (comboBox6->SelectedIndex)
		{
		case 0:
			inversion = 1;
			break;
		case 1:
			inversion = 0;
			break;
		}
	
	}
	private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		angle = Convert::ToInt64(textBox9->Text);
	}
	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		side = Convert::ToInt64(textBox7->Text);
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		xCordAngle = Convert::ToInt64(textBox1->Text);
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		yCordAngle = Convert::ToInt64(textBox2->Text);
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		xCordUpLeft = Convert::ToInt64(textBox3->Text);
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		yCordUpLeft = Convert::ToInt64(textBox4->Text);
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		xCordDownLeft = Convert::ToInt64(textBox5->Text);
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		yCordDownLeft = Convert::ToInt64(textBox6->Text);
	}
};
}


