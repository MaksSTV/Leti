#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3(void)
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
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ÓÚÍ˚Ú¸ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚ıÓ‰ToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÓÚÍ˚Ú¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Ù‡ÈÎToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(282, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ÓÚÍ˚Ú¸ToolStripMenuItem,
					this->ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem, this->‚˚ıÓ‰ToolStripMenuItem
			});
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// ÓÚÍ˚Ú¸ToolStripMenuItem
			// 
			this->ÓÚÍ˚Ú¸ToolStripMenuItem->Name = L"ÓÚÍ˚Ú¸ToolStripMenuItem";
			this->ÓÚÍ˚Ú¸ToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->ÓÚÍ˚Ú¸ToolStripMenuItem->Text = L"ŒÚÍ˚Ú¸";
			this->ÓÚÍ˚Ú¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm3::ÓÚÍ˚Ú¸ToolStripMenuItem_Click);
			// 
			// ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem
			// 
			this->ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem->Name = L"ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem";
			this->ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem->Text = L"—Óı‡ÌËÚ¸ Í‡Í";
			this->ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm3::ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem_Click);
			// 
			// ‚˚ıÓ‰ToolStripMenuItem
			// 
			this->‚˚ıÓ‰ToolStripMenuItem->Name = L"‚˚ıÓ‰ToolStripMenuItem";
			this->‚˚ıÓ‰ToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->‚˚ıÓ‰ToolStripMenuItem->Text = L"¬˚ıÓ‰";
			this->‚˚ıÓ‰ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm3::‚˚ıÓ‰ToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(12, 76);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(258, 145);
			this->textBox1->TabIndex = 1;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm3";
			this->Text = L"MyForm3";
			this->Load += gcnew System::EventHandler(this, &MyForm3::MyForm3_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm3_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "“ÂÍÒÚÓ‚˚È Â‰‡ÍÚÓ";
		openFileDialog1->FileName = "C:\\Users\\Maks\\Desktop\\Text2.txt";
		openFileDialog1->Filter = "“ÂÍÒÚÓ‚˚Â Ù‡ÈÎ˚ (*.txt)|*.txt|All files (*.*)|*.*";
		saveFileDialog1->Filter = "“ÂÍÒÚÓ‚˚Â Ù‡ÈÎ˚ (*.txt)|*.txt|All files (*.*)|*.*";
	}
	private: System::Void ÓÚÍ˚Ú¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^e) {
		openFileDialog1->ShowDialog();
		if (openFileDialog1->FileName == nullptr) return;
		try
		{
			auto MyReader = gcnew IO::StreamReader(openFileDialog1->FileName,
				System::Text::Encoding::GetEncoding(1251));
			textBox1->Text = MyReader->ReadToEnd();
			MyReader->Close();
		}
		catch (IO::FileNotFoundException^ —ËÚÛ‡ˆËˇ)
		{
			MessageBox::Show(—ËÚÛ‡ˆËˇ->Message + "\n‘‡ÈÎ ÌÂ Ì‡È‰ÂÌ", "Œ¯Ë·Í‡", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
		catch (Exception^ —ËÚÛ‡ˆËˇ)
		{
			MessageBox::Show(—ËÚÛ‡ˆËˇ->Message, "Œ¯Ë·Í‡", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
	}

	private: System::Void ÒÓı‡ÌËÚ¸ ‡ÍToolStripMenuItem_Click(System::Object^ sender,System::EventArgs^ e) {
		saveFileDialog1->FileName = openFileDialog1->FileName;
		if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) Save();
	}
		   void Save()
		   {
			   try
			   {
				   // —ÓÁ‰‡ÌËÂ ˝ÍÁÂÏÔÎˇ‡ StreamWriter ‰Îˇ Á‡ÔËÒË ‚ Ù‡ÈÎ:
				   auto MyWriter = gcnew IO::StreamWriter(saveFileDialog1->FileName, false,
					   System::Text::Encoding::GetEncoding(1251));
				   MyWriter->Write(textBox1->Text);
				   MyWriter->Close(); textBox1->Modified = false;
			   }
			   catch (Exception^ —ËÚÛ‡ˆËˇ)
			   {
				   MessageBox::Show(—ËÚÛ‡ˆËˇ->Message, "Œ¯Ë·Í‡", MessageBoxButtons::OK,
					   MessageBoxIcon::Exclamation);
			   }
		   }
	private: System::Void ‚˚ıÓ‰ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void MyForm3_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (textBox1->Modified == false) return;
		auto MeBox = MessageBox::Show("“ÂÍÒÚ ·˚Î ËÁÏÂÌ∏Ì. \n—Óı‡ÌËÚ¸ ËÁÏÂÌÂÌËˇ?",
			"œÓÒÚÓÈ Â‰‡ÍÚÓ", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Exclamation);
		if (MeBox == Windows::Forms::DialogResult::No) return;
		if (MeBox == Windows::Forms::DialogResult::Cancel) e->Cancel = true;
		if (MeBox == Windows::Forms::DialogResult::Yes)
		{
			if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				Save(); return;
			}
			else e->Cancel = true;
		}
	}
};
}
