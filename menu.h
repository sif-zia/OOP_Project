#pragma once
#include "MyForm.h"


namespace OOPProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for menu
	/// </summary>
	public ref class menu : public System::Windows::Forms::Form
	{
	public:
		menu(void)
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
		~menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Button^ easy_btn;
	private: System::Windows::Forms::Button^ medm_btn;
	private: System::Windows::Forms::Button^ hard_btn;




	protected:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->title = (gcnew System::Windows::Forms::Label());
			this->easy_btn = (gcnew System::Windows::Forms::Button());
			this->medm_btn = (gcnew System::Windows::Forms::Button());
			this->hard_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// title
			// 
			this->title->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::SystemColors::Highlight;
			this->title->Location = System::Drawing::Point(66, 34);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(355, 75);
			this->title->TabIndex = 0;
			this->title->Text = L"Minesweeper";
			// 
			// easy_btn
			// 
			this->easy_btn->BackColor = System::Drawing::Color::Silver;
			this->easy_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->easy_btn->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->easy_btn->ForeColor = System::Drawing::Color::LawnGreen;
			this->easy_btn->Location = System::Drawing::Point(139, 136);
			this->easy_btn->Name = L"easy_btn";
			this->easy_btn->Size = System::Drawing::Size(170, 57);
			this->easy_btn->TabIndex = 1;
			this->easy_btn->Text = L"Easy";
			this->easy_btn->UseVisualStyleBackColor = false;
			this->easy_btn->Click += gcnew System::EventHandler(this, &menu::easy_btn_Click);
			// 
			// medm_btn
			// 
			this->medm_btn->BackColor = System::Drawing::Color::Silver;
			this->medm_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->medm_btn->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->medm_btn->ForeColor = System::Drawing::Color::Yellow;
			this->medm_btn->Location = System::Drawing::Point(139, 234);
			this->medm_btn->Name = L"medm_btn";
			this->medm_btn->Size = System::Drawing::Size(170, 57);
			this->medm_btn->TabIndex = 2;
			this->medm_btn->Text = L"Medium";
			this->medm_btn->UseVisualStyleBackColor = false;
			this->medm_btn->Click += gcnew System::EventHandler(this, &menu::medm_btn_Click);
			// 
			// hard_btn
			// 
			this->hard_btn->BackColor = System::Drawing::Color::Silver;
			this->hard_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->hard_btn->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hard_btn->ForeColor = System::Drawing::Color::Red;
			this->hard_btn->Location = System::Drawing::Point(139, 336);
			this->hard_btn->Name = L"hard_btn";
			this->hard_btn->Size = System::Drawing::Size(170, 57);
			this->hard_btn->TabIndex = 3;
			this->hard_btn->Text = L"Hard";
			this->hard_btn->UseVisualStyleBackColor = false;
			this->hard_btn->Click += gcnew System::EventHandler(this, &menu::hard_btn_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(453, 444);
			this->Controls->Add(this->hard_btn);
			this->Controls->Add(this->medm_btn);
			this->Controls->Add(this->easy_btn);
			this->Controls->Add(this->title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"menu";
			this->Text = L"Minesweeper";
			this->Load += gcnew System::EventHandler(this, &menu::menu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void menu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void easy_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm^ form = gcnew MyForm(0);
		form->ShowDialog();
		delete form;
		this->Show();
	}
	private: System::Void medm_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm^ form = gcnew MyForm(1);
		form->ShowDialog();
		delete form;
		this->Show();
	}
	private: System::Void hard_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm^ form = gcnew MyForm(2);
		form->ShowDialog();
		delete form;
		this->Show();
	}
};
}
