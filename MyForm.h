#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
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
			no_of_mines = 10;
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
	private: int rows, cols, cell_size, no_of_mines;
	private: cli::array<Cell^, 2>^ cells;
	private: cli::array<int, 2>^ mine_locs;


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


	private: bool check_mine_loc(int x, int y, int mines_deployed){
		for (int i = 0; i < mines_deployed; i++)
			if (mine_locs[i, 0] == x && mine_locs[i, 1] == y)
				return true;
		return false;
	}
	
	private: bool is_Valid(int x, int y) {
		if (x >= 0 && x < cols)
			if (y >= 0 && y < rows)
				return true;
		return false;
	}

	private: bool is_exposable(int x, int y) {
		if (is_Valid(x, y) == true)
			if (cells[x, y]->is_exposed == false)
				if (cells[x, y]->is_flagged == false)
					if(cells[x, y]->is_mined() == false)
						return true;
		return false;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		srand(time(0));

		cells = gcnew cli::array<Cell^, 2>(rows, cols);
		mine_locs = gcnew cli::array<int, 2>(no_of_mines, 2);

		int x, y;
		//
		// Adding Mines
		//
		for (int i = 0; i < no_of_mines; i++) {
			do {
				x = rand() % cols;
				y = rand() % rows;
			} while (check_mine_loc(x, y, i - 1) == true);
			mine_locs[i, 0] = x;
			mine_locs[i, 1] = y;
			cells[x, y] = gcnew Mined_Cell(x, y, cell_size);
		}

		this->ClientSize = System::Drawing::Size((cols + 2) * cell_size, (rows + 3) * cell_size);

		//
		// Adding Unmined Cells
		//
		for (int j = 0; j < rows; j++)
			for (int i = 0; i < cols; i++) {
				if (check_mine_loc(i, j, no_of_mines) == false) {
					cells[i, j] = gcnew Unmined_Cell(i, j, cell_size);
				}

				this->Controls->Add(cells[i, j]->exp_cel);
				this->Controls->Add(cells[i, j]->btn);
				cells[i, j]->exp_cel->SendToBack();

				cells[i, j]->btn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &OOPProject::MyForm::OnMouseUp);
				cells[i, j]->btn->MouseEnter += gcnew System::EventHandler(this, &OOPProject::MyForm::OnMouseEnter);
				cells[i, j]->btn->MouseLeave += gcnew System::EventHandler(this, &OOPProject::MyForm::OnMouseLeave);
			}
		//
		// Counting Adajecent Mines
		//
		for (int j = 0; j < rows; j++)
			for (int i = 0; i < cols; i++) {
				int adj_mines = 0;
				if (cells[i, j]->is_mined() == false) {
					if (is_Valid(i - 1, j - 1) == true) if (cells[i - 1, j - 1]->is_mined() == true) adj_mines++;
					if (is_Valid(i, j - 1) == true) if (cells[i, j - 1]->is_mined() == true) adj_mines++;
					if (is_Valid(i + 1, j - 1) == true) if (cells[i + 1, j - 1]->is_mined() == true) adj_mines++;

					if (is_Valid(i - 1, j) == true) if (cells[i - 1, j]->is_mined() == true) adj_mines++;
					if (is_Valid(i, j) == true) if (cells[i, j]->is_mined() == true) adj_mines++;
					if (is_Valid(i + 1, j) == true) if (cells[i + 1, j]->is_mined() == true) adj_mines++;

					if (is_Valid(i - 1, j + 1) == true) if (cells[i - 1, j + 1]->is_mined() == true) adj_mines++;
					if (is_Valid(i, j + 1) == true) if (cells[i, j + 1]->is_mined() == true) adj_mines++;
					if (is_Valid(i + 1, j + 1) == true) if (cells[i + 1, j + 1]->is_mined() == true) adj_mines++;

					cells[i, j]->Set_adj_mines(adj_mines);
				}
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
			cells[x, y]->expose();
			break;
		case (System::Windows::Forms::MouseButtons::Right):
			cells[x, y]->flag();
			break;
		}
	}

	void OOPProject::MyForm::OnMouseEnter(System::Object^ sender, System::EventArgs^ e)
	{
		std::string text;
		ClrStringToStdString(text, sender->ToString());
		int first_dash = text.find('-', 0);
		int second_dash = text.find('-', first_dash + 1);
		std::string text_x = text.substr(first_dash + 1, second_dash - first_dash - 1);
		std::string text_y = text.substr(second_dash + 1, text.length() - second_dash - 1);
		int x = std::stoi(text_x);
		int y = std::stoi(text_y);
		label1->Text = x.ToString() + "-" + y.ToString();

		float popness = (float)10 / 100 * cell_size;

		cells[x, y]->btn->Size = System::Drawing::Size(cell_size + popness, cell_size + popness);
		cells[x, y]->btn->BringToFront();
	}

	void OOPProject::MyForm::OnMouseLeave(System::Object^ sender, System::EventArgs^ e)
	{
		std::string text;
		ClrStringToStdString(text, sender->ToString());
		int first_dash = text.find('-', 0);
		int second_dash = text.find('-', first_dash + 1);
		std::string text_x = text.substr(first_dash + 1, second_dash - first_dash - 1);
		std::string text_y = text.substr(second_dash + 1, text.length() - second_dash - 1);
		int x = std::stoi(text_x);
		int y = std::stoi(text_y);
		label1->Text = x.ToString() + "-" + y.ToString();

		float popness = (float)(10 / 100) * cell_size;

		cells[x, y]->btn->Size = System::Drawing::Size(cell_size - popness, cell_size - popness);

		cells[x, y]->btn->SendToBack();
		cells[x, y]->exp_cel->SendToBack();
	}
};
}





