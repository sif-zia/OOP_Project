#pragma once
#include <string>
#include "Cell.h"


namespace OOPProject {

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
			rows = 10;
			cols = 10;
			cell_size = 52;
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
	public: System::Windows::Forms::Label^ label1;
	private: int rows, cols, cell_size;
	public: cli::array<Button^, 2>^ btns;
	private: cli::array<PictureBox^, 2>^ exp_cels;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(182)), static_cast<System::Int32>(static_cast<System::Byte>(182)),
				static_cast<System::Int32>(static_cast<System::Byte>(182)));
			this->ClientSize = System::Drawing::Size(928, 749);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		btns = gcnew cli::array<Button^, 2>(rows, cols);
		exp_cels = gcnew cli::array<PictureBox^, 2>(rows, cols);

		this->ClientSize = System::Drawing::Size((cols + 2) * cell_size, (rows + 3) * cell_size);

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				btns[i, j] = gcnew Button();
				btns[i, j]->CausesValidation = false;
				btns[i, j]->Location = System::Drawing::Point((j + 1) * cell_size, (i + 2) * cell_size);
				btns[i, j]->Name = L"-" + i.ToString() + L"-" + j.ToString();
				btns[i, j]->Size = System::Drawing::Size(cell_size, cell_size);
				btns[i, j]->TabStop = false;
				btns[i, j]->Text = L"-" + i.ToString() + L"-" + j.ToString();
				btns[i, j]->UseVisualStyleBackColor = true;
				btns[i, j]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				btns[i, j]->Cursor = System::Windows::Forms::Cursors::Hand;
				btns[i, j]->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(184)),
					static_cast<System::Int32>(static_cast<System::Byte>(184)));
				btns[i, j]->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				btns[i, j]->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				btns[i, j]->BackgroundImage = Image::FromFile("Cell.png");
				btns[i, j]->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &OOPProject::MyForm::OnMouseUp);

				exp_cels[i, j] = gcnew PictureBox;
				exp_cels[i, j]->Location = System::Drawing::Point((j + 1) * cell_size, (i + 2) * cell_size);
				exp_cels[i, j]->Name = L"-" + i.ToString() + L"-" + j.ToString() + L"P";
				exp_cels[i, j]->Size = System::Drawing::Size(cell_size, cell_size);
				exp_cels[i, j]->TabStop = false;
				exp_cels[i, j]->SizeMode = PictureBoxSizeMode::StretchImage;
				exp_cels[i, j]->Image = Image::FromFile("mine_red.jpeg");
			}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				Controls->Add(exp_cels[i, j]);
				Controls->Add(btns[i, j]);
				exp_cels[i, j]->SendToBack();
			}
	}


	public: void ClrStringToStdString(std::string& outStr, String^ str) {
			   IntPtr ansiStr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
			   outStr = (const char*)ansiStr.ToPointer();
			   System::Runtime::InteropServices::Marshal::FreeHGlobal(ansiStr);
	}
	public: System::Void OOPProject::MyForm::OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		std::string text;
		ClrStringToStdString(text, sender->ToString());
		int first_dash = text.find('-', 0);
		int second_dash = text.find('-', first_dash+1);
		std::string text_x = text.substr(first_dash + 1, second_dash - first_dash - 1);
		std::string text_y = text.substr(second_dash + 1, text.length() - second_dash - 1);
		int x = std::stoi(text_x);
		int y = std::stoi(text_y);
		label1->Text = x.ToString() + "-" + y.ToString();
		
		switch (e->Button) {
		case (System::Windows::Forms::MouseButtons::Left):
			btns[x, y]->Visible = false;
			break;
		case (System::Windows::Forms::MouseButtons::Right):
			btns[x, y]->BackgroundImage = Image::FromFile("flag.png");
			break;
		}
	}
};
}
