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
		MyForm(int mode)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			cells = nullptr;
			mine_locs = nullptr;
			if (mode == 0)
				initializeGame(9, 9, 52, 10);
			else if (mode == 1)
				initializeGame(16, 16, 40, 40);
			else if (mode == 2)
				initializeGame(30, 16, 30, 99);
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

	private: int Cols, Rows, cell_size, no_of_mines, total_unmined_cells, cells_exposed, flag_count, seconds_count;
	private: cli::array<Cell^, 2>^ cells;
	private: cli::array<int, 2>^ mine_locs;
	private: bool is_game_over;
	private: System::Windows::Forms::Label^ flag_count_lbl;
	private: System::Windows::Forms::Label^ timer_lbl;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Button^ React;
	private: System::Windows::Forms::PictureBox^ back_lbl;

	private: System::ComponentModel::IContainer^ components;


		   /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->flag_count_lbl = (gcnew System::Windows::Forms::Label());
			this->timer_lbl = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->React = (gcnew System::Windows::Forms::Button());
			this->back_lbl = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back_lbl))->BeginInit();
			this->SuspendLayout();
			// 
			// flag_count_lbl
			// 
			this->flag_count_lbl->AutoSize = true;
			this->flag_count_lbl->BackColor = System::Drawing::Color::Black;
			this->flag_count_lbl->Font = (gcnew System::Drawing::Font(L"hooge 05_53", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->flag_count_lbl->ForeColor = System::Drawing::Color::IndianRed;
			this->flag_count_lbl->Location = System::Drawing::Point(84, 12);
			this->flag_count_lbl->Name = L"flag_count_lbl";
			this->flag_count_lbl->Size = System::Drawing::Size(112, 50);
			this->flag_count_lbl->TabIndex = 1;
			this->flag_count_lbl->Text = L"000";
			// 
			// timer_lbl
			// 
			this->timer_lbl->AutoSize = true;
			this->timer_lbl->BackColor = System::Drawing::Color::Black;
			this->timer_lbl->Font = (gcnew System::Drawing::Font(L"hooge 05_53", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timer_lbl->ForeColor = System::Drawing::Color::IndianRed;
			this->timer_lbl->Location = System::Drawing::Point(387, 12);
			this->timer_lbl->Name = L"timer_lbl";
			this->timer_lbl->Size = System::Drawing::Size(112, 50);
			this->timer_lbl->TabIndex = 2;
			this->timer_lbl->Text = L"000";
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// React
			// 
			this->React->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"React.BackgroundImage")));
			this->React->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->React->Location = System::Drawing::Point(270, 12);
			this->React->Name = L"React";
			this->React->Size = System::Drawing::Size(50, 50);
			this->React->TabIndex = 0;
			this->React->TabStop = false;
			this->React->UseVisualStyleBackColor = true;
			this->React->Click += gcnew System::EventHandler(this, &MyForm::React_Click);
			this->React->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::React_MouseUp);
			// 
			// back_lbl
			// 
			this->back_lbl->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_lbl.Image")));
			this->back_lbl->Location = System::Drawing::Point(83, 65);
			this->back_lbl->Name = L"back_lbl";
			this->back_lbl->Size = System::Drawing::Size(416, 64);
			this->back_lbl->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->back_lbl->TabIndex = 3;
			this->back_lbl->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(182)), static_cast<System::Int32>(static_cast<System::Byte>(182)),
				static_cast<System::Int32>(static_cast<System::Byte>(182)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(928, 749);
			this->Controls->Add(this->back_lbl);
			this->Controls->Add(this->React);
			this->Controls->Add(this->timer_lbl);
			this->Controls->Add(this->flag_count_lbl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Minesweeper";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back_lbl))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: void initializeGame(int cols, int rows, int Cell_size, int Mines) {
		
		if (cells != nullptr) {
			for (int i = 0; i < Rows; i++)
				for (int j = 0; j < Cols; j++) {
					this->Controls->Remove(cells[i, j]->btn);
					this->Controls->Remove(cells[i, j]->exp_cel);
					delete cells[i, j];
				}
		}
		if (mine_locs != nullptr)
			for (int i = 0; i < no_of_mines; i++)
				mine_locs[i, 0] = -1, mine_locs[i, 1] = -1;

		Cols = cols;
		Rows = rows;
		cell_size = Cell_size;
		no_of_mines = Mines;
		flag_count = no_of_mines;
		total_unmined_cells = Cols * Rows - no_of_mines;
		cells_exposed = 0;
		seconds_count = 0;
		is_game_over = false;

		srand(time(0));

		back_lbl->SendToBack();
		flag_count_lbl->Text = flag_count.ToString(L"D3");
		timer_lbl->Text = seconds_count.ToString(L"D3");
		React->BackgroundImage = Image::FromFile("happy.png");

		cells = gcnew cli::array<Cell^, 2>(Rows, Cols);
		if(mine_locs == nullptr)
			mine_locs = gcnew cli::array<int, 2>(no_of_mines, 2);

		int x, y;
		//
		// Adding Mines
		//
		for (int i = 0; i < no_of_mines; i++) {
			do {
				x = rand() % Rows;
				y = rand() % Cols;
			} while (check_mine_loc(x, y, i - 1) == true);
			mine_locs[i, 0] = x;
			mine_locs[i, 1] = y;
			cells[x, y] = gcnew Mined_Cell(x, y, cell_size);
		}

		this->ClientSize = System::Drawing::Size((Cols + 2) * cell_size, (Rows + 3) * cell_size);
		this->timer_lbl->Font = (gcnew System::Drawing::Font(L"hooge 05_53", cell_size/2 + cell_size/11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->flag_count_lbl->Font = (gcnew System::Drawing::Font(L"hooge 05_53", cell_size / 2 + cell_size / 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->back_lbl->Location = System::Drawing::Point(cell_size, cell_size / 4);
		this->back_lbl->Size = System::Drawing::Size(Cols * cell_size, cell_size + cell_size/2);
		this->flag_count_lbl->Location = System::Drawing::Point(cell_size + cell_size / 2, cell_size / 2);
		this->timer_lbl->Location = System::Drawing::Point((Cols - 2) * cell_size + cell_size/2 - ((Cols / 16) * cell_size / 2), cell_size / 2);
		this->React->Location = System::Drawing::Point(float(Cols)/2.0 * cell_size + cell_size / 4, cell_size / 2 - cell_size / 8);
		this->React->Size = System::Drawing::Size(cell_size + cell_size / 4, cell_size + cell_size / 4);

		//
		// Adding Unmined Cells
		//
		for (int j = 0; j < Cols; j++)
			for (int i = 0; i < Rows; i++) {
				if (check_mine_loc(i, j, no_of_mines - 1) == false) {
					cells[i, j] = gcnew Unmined_Cell(i, j, cell_size);
				}

				this->Controls->Add(cells[i, j]->exp_cel);
				this->Controls->Add(cells[i, j]->btn);
				cells[i, j]->exp_cel->SendToBack();

				cells[i, j]->btn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &OOPProject::MyForm::OnMouseUp);
				cells[i, j]->btn->MouseEnter += gcnew System::EventHandler(this, &OOPProject::MyForm::OnMouseEnter);
				cells[i, j]->btn->MouseLeave += gcnew System::EventHandler(this, &OOPProject::MyForm::OnMouseLeave);
				cells[i, j]->btn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &OOPProject::MyForm::OnMouseDown);
			}
		//
		// Counting Adajecent Mines
		//
		for (int j = 0; j < Cols; j++)
			for (int i = 0; i < Rows; i++) {
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

	private: bool check_mine_loc(int x, int y, int mines_deployed){
		for (int i = 0; i <= mines_deployed; i++)
			if (mine_locs[i, 0] == x && mine_locs[i, 1] == y)
				return true;
		return false;
	}
	
	private: bool is_Valid(int x, int y) {
		if (x >= 0 && x < Rows)
			if (y >= 0 && y < Cols)
				return true;
		return false;
	}

	private: bool is_exposable(int x, int y) {
		if (is_Valid(x, y) == true)
			if (cells[x, y]->is_exposed == false)
				if (cells[x, y]->is_flagged == false)
					if (cells[x, y]->is_mined() == false) {
						cells_exposed++;
						return true;
					}
		return false;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}

	public: void ClrStringToStdString(std::string& outStr, String^ str) {
			   IntPtr ansiStr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
			   outStr = (const char*)ansiStr.ToPointer();
			   System::Runtime::InteropServices::Marshal::FreeHGlobal(ansiStr);
	}
	
	private: void expose_adj(int i, int j) {
			if (is_exposable(i - 1, j - 1) == true) if (cells[i - 1, j - 1]->expose() == 2) expose_adj(i - 1, j - 1);
			if (is_exposable(i, j - 1) == true) if (cells[i, j - 1]->expose() == 2) expose_adj(i, j - 1);
			if (is_exposable(i + 1, j - 1) == true) if (cells[i + 1, j - 1]->expose() == 2) expose_adj(i + 1, j - 1);

			if (is_exposable(i - 1, j) == true) if (cells[i - 1, j]->expose() == 2) expose_adj(i - 1, j);
			if (is_exposable(i, j) == true) if (cells[i, j]->expose() == 2) expose_adj(i, j);
			if (is_exposable(i + 1, j) == true) if (cells[i + 1, j]->expose() == 2) expose_adj(i + 1, j);

			if (is_exposable(i - 1, j + 1) == true) if (cells[i - 1, j + 1]->expose() == 2) expose_adj(i - 1, j + 1);
			if (is_exposable(i, j + 1) == true) if (cells[i, j + 1]->expose() == 2) expose_adj(i, j + 1);
			if (is_exposable(i + 1, j + 1) == true) if (cells[i + 1, j + 1]->expose() == 2) expose_adj(i + 1, j + 1);
		
	}
	
	private: void game_over(int x, int y) {
		is_game_over = true;
		timer->Enabled = false;
		cells[x, y]->exp_cel->Image = Image::FromFile("mine_red.jpeg");
		React->BackgroundImage = Image::FromFile("dead.png");
		for (int i = 0; i < no_of_mines; i++) {
			cells[mine_locs[i, 0], mine_locs[i, 1]]->btn->Visible = false;
			cells[mine_locs[i, 0], mine_locs[i, 1]]->is_exposed = true;
		}
	}

	public: System::Void OOPProject::MyForm::OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (is_game_over == false) {
			React->BackgroundImage = Image::FromFile("happy.png");

			if (timer->Enabled == false)
				timer->Enabled = true;

			std::string text;
			ClrStringToStdString(text, sender->ToString());
			int first_dash = text.find('-', 0);
			int second_dash = text.find('-', first_dash + 1);
			std::string text_x = text.substr(first_dash + 1, second_dash - first_dash - 1);
			std::string text_y = text.substr(second_dash + 1, text.length() - second_dash - 1);
			int x = std::stoi(text_x);
			int y = std::stoi(text_y);

			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				int what_to_do = cells[x, y]->expose();
				switch (what_to_do) {
				case 1: game_over(x, y); break;
				case 2: expose_adj(x, y); cells_exposed++; break;
				case 3: cells[x, y]->expose(); cells_exposed++; break;
				default: break;
				}
				if (cells_exposed == total_unmined_cells) {
					is_game_over = true;
					React->BackgroundImage = Image::FromFile("win.png");
					timer->Enabled = false;
				}
			}
			else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				if (cells[x, y]->flag() == true)
					flag_count--;
				else
					flag_count++;
				if(flag_count >= 0)
					flag_count_lbl->Text = flag_count.ToString(L"D3");
				else
					flag_count_lbl->Text = flag_count.ToString();
			}
		}
	}

	void OOPProject::MyForm::OnMouseEnter(System::Object^ sender, System::EventArgs^ e)
	{
		if (is_game_over == false) {
			std::string text;
			ClrStringToStdString(text, sender->ToString());
			int first_dash = text.find('-', 0);
			int second_dash = text.find('-', first_dash + 1);
			std::string text_x = text.substr(first_dash + 1, second_dash - first_dash - 1);
			std::string text_y = text.substr(second_dash + 1, text.length() - second_dash - 1);
			int x = std::stoi(text_x);
			int y = std::stoi(text_y);

			float popness = (float)10 / 100 * cell_size;

			cells[x, y]->btn->Size = System::Drawing::Size(cell_size + popness, cell_size + popness);
			cells[x, y]->btn->BringToFront();
		}
	}

	void OOPProject::MyForm::OnMouseLeave(System::Object^ sender, System::EventArgs^ e)
	{	
		if (is_game_over == false) {
			std::string text;
			ClrStringToStdString(text, sender->ToString());
			int first_dash = text.find('-', 0);
			int second_dash = text.find('-', first_dash + 1);
			std::string text_x = text.substr(first_dash + 1, second_dash - first_dash - 1);
			std::string text_y = text.substr(second_dash + 1, text.length() - second_dash - 1);
			int x = std::stoi(text_x);
			int y = std::stoi(text_y);

			float popness = (float)(10 / 100) * cell_size;

			cells[x, y]->btn->Size = System::Drawing::Size(cell_size - popness, cell_size - popness);

			cells[x, y]->btn->SendToBack();
			cells[x, y]->exp_cel->SendToBack();
		}
	}
	
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (timer->Enabled == true && seconds_count < 999)
			seconds_count++;
		timer_lbl->Text = seconds_count.ToString(L"D3");
	}
	
	private: void OOPProject::MyForm::OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if(is_game_over == false)
			React->BackgroundImage = Image::FromFile("scared.png");
	}
	
	private: System::Void React_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void React_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
			if (is_game_over == true)
				initializeGame(Cols, Rows, cell_size, no_of_mines);
	}
};
}








