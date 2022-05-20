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
			cell_size = 40;
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

	public:

	public:

	public:

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
			this->ClientSize = System::Drawing::Size(908, 680);
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

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				btns[i, j] = gcnew Button();
				btns[i, j]->CausesValidation = false;
				btns[i, j]->Location = System::Drawing::Point(initial_x + (i * cell_size), initial_y + (j * cell_size));
				btns[i, j]->Name = i.ToString() + j.ToString();
				btns[i, j]->Size = System::Drawing::Size(cell_size, cell_size);
				btns[i, j]->TabStop = false;
				btns[i, j]->TabIndex = (i * cols) + j;
				btns[i, j]->Text = i.ToString() + j.ToString();
				btns[i, j]->UseVisualStyleBackColor = true;
				btns[i, j]->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
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
	public: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string text;
		ClrStringToStdString(text, sender->ToString());
		int x = text[text.length() - 2] - '0';
		int y = text[text.length() - 1] - '0';
		label1->Text = x.ToString() + y.ToString();
		btns[x, y]->Visible = false;
	}
	};
}