#pragma once
#include <string>

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
			initial_x = 50;
			initial_y = 50;
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
	private: int rows, cols, cell_size, initial_x, initial_y;
	public: cli::array<Button^, 2>^ btns;

	private: ImageList^ Img;
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
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(928, 749);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		btns = gcnew cli::array<Button^, 2>(rows, cols);

		Img = gcnew ImageList;
		Img->ImageSize = System::Drawing::Size(cell_size+1, cell_size+1);
		Img->Images->Add(Image::FromFile("Cell.png"));
		Img->Images->Add(Image::FromFile("flag.png"));

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				btns[i, j] = gcnew Button();
				btns[i, j]->CausesValidation = false;
				btns[i, j]->Location = System::Drawing::Point(initial_x + (j * cell_size), initial_y + (i * cell_size));
				btns[i, j]->Name = L"-" + i.ToString() + L"-" + j.ToString();
				btns[i, j]->Size = System::Drawing::Size(cell_size, cell_size);
				btns[i, j]->TabStop = false;
				btns[i, j]->TabIndex = (i * cols) + j;
				btns[i, j]->Text = L"-" + i.ToString() + L"-" + j.ToString();
				btns[i, j]->UseVisualStyleBackColor = true;
				btns[i, j]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				btns[i, j]->Cursor = System::Windows::Forms::Cursors::Hand;
				btns[i, j]->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(184)),
					static_cast<System::Int32>(static_cast<System::Byte>(184)));
				btns[i, j]->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				btns[i, j]->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
				btns[i, j]->BackgroundImage = Img->Images[0];
				btns[i, j]->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &OOPProject::MyForm::OnMouseUp);
			}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				Controls->Add(btns[i, j]);
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
			btns[x, y]->BackgroundImage = Img->Images[1];
			break;
		}
	}
};
}
