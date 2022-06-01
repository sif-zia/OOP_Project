#pragma once
#include <string>
#include <fstream>

namespace OOPProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for leaderboard
	/// </summary>
	public ref class leaderboard : public System::Windows::Forms::Form
	{
	public:
		leaderboard(int mode, int score)
		{	
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			game_mode = mode;

			if (mode == 0)
				filename = gcnew String("easy.dat"), mode_name_lbl->Text = L"Easy Mode:";
			else if (mode == 1)
				filename = gcnew String("medium.dat"), mode_name_lbl->Text = L"Medium Mode:";
			else if (mode == 2)
				filename = gcnew String("hard.dat"), mode_name_lbl->Text = L"Hard Mode:";

			std::string file;
			ClrStringToStdString(file, filename);
			std::ifstream fin;
			fin.open(file.c_str());

			std::string tempStr;
			std::getline(fin, tempStr);
			posNums = std::stoi(tempStr);

			posNames = gcnew cli::array<String^>(5);
			posScores = gcnew cli::array<int>(5);

			for (int i = 0; i < posNums; i++) {
				std::getline(fin, tempStr);
				posNames[i] = gcnew String(tempStr.c_str());
				std::getline(fin, tempStr);
				posScores[i] = std::stoi(tempStr);
			}

			fin.close();

			for (int i = 0; i < posNums; i++)
				show_pos(posScores[i], posNames[i], i + 1);

			should_add = false;
			curPos = -1;
			curScore = score;

			for (int i = 0; i < posNums && should_add == false; i++) {
				if (score < posScores[i])
					curPos = i, should_add = true;
			}

			if (should_add == true && posNums < 5)
				posNums++;


			if (should_add == false && posNums < 5) {
				curPos = posNums, posNums++, should_add = true;
			}

			newName->Enabled = true;
			submit_btn->Enabled = true;

			if (should_add == true)
				Msg_lbl->Text = L"Congrats! You got " + (curPos+1).ToString() + L" position.";
			else
				Msg_lbl->Text = L"Better Luck Next Time!";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~leaderboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ mode_name_lbl;
	protected:
	private: System::Windows::Forms::Label^ posNum1_lbl;
	private: System::Windows::Forms::Label^ posNum2_lbl;
	private: System::Windows::Forms::Label^ posNum3_lbl;
	private: System::Windows::Forms::Label^ posNum4_lbl;
	private: System::Windows::Forms::Label^ posNum5_lbl;
	private: System::Windows::Forms::Label^ posName5_lbl;
	private: System::Windows::Forms::Label^ posName4_lbl;
	private: System::Windows::Forms::Label^ posName3_lbl;
	private: System::Windows::Forms::Label^ posName2_lbl;
	private: System::Windows::Forms::Label^ posName1_lbl;
	private: System::Windows::Forms::Label^ posScore5_lbl;
	private: System::Windows::Forms::Label^ posScore4_lbl;
	private: System::Windows::Forms::Label^ posScore3_lbl;
	private: System::Windows::Forms::Label^ posScore2_lbl;
	private: System::Windows::Forms::Label^ posScore1_lbl;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ PosName;
	private: System::Windows::Forms::Label^ PosNum;
	private: System::Windows::Forms::TextBox^ newName;
	private: System::Windows::Forms::Label^ Msg_lbl;
	private: System::Windows::Forms::Button^ submit_btn;

	private: String^ filename;
	private: cli::array<String^>^ posNames;
	private: cli::array<int>^ posScores;
	private: int posNums, curPos, curScore, game_mode;
	private: bool should_add, submitted;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(leaderboard::typeid));
			this->mode_name_lbl = (gcnew System::Windows::Forms::Label());
			this->posNum1_lbl = (gcnew System::Windows::Forms::Label());
			this->posNum2_lbl = (gcnew System::Windows::Forms::Label());
			this->posNum3_lbl = (gcnew System::Windows::Forms::Label());
			this->posNum4_lbl = (gcnew System::Windows::Forms::Label());
			this->posNum5_lbl = (gcnew System::Windows::Forms::Label());
			this->posName5_lbl = (gcnew System::Windows::Forms::Label());
			this->posName4_lbl = (gcnew System::Windows::Forms::Label());
			this->posName3_lbl = (gcnew System::Windows::Forms::Label());
			this->posName2_lbl = (gcnew System::Windows::Forms::Label());
			this->posName1_lbl = (gcnew System::Windows::Forms::Label());
			this->posScore5_lbl = (gcnew System::Windows::Forms::Label());
			this->posScore4_lbl = (gcnew System::Windows::Forms::Label());
			this->posScore3_lbl = (gcnew System::Windows::Forms::Label());
			this->posScore2_lbl = (gcnew System::Windows::Forms::Label());
			this->posScore1_lbl = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PosName = (gcnew System::Windows::Forms::Label());
			this->PosNum = (gcnew System::Windows::Forms::Label());
			this->newName = (gcnew System::Windows::Forms::TextBox());
			this->Msg_lbl = (gcnew System::Windows::Forms::Label());
			this->submit_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// mode_name_lbl
			// 
			this->mode_name_lbl->AutoSize = true;
			this->mode_name_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mode_name_lbl->Location = System::Drawing::Point(19, 9);
			this->mode_name_lbl->Name = L"mode_name_lbl";
			this->mode_name_lbl->Size = System::Drawing::Size(103, 45);
			this->mode_name_lbl->TabIndex = 0;
			this->mode_name_lbl->Text = L"Mode";
			// 
			// posNum1_lbl
			// 
			this->posNum1_lbl->AutoSize = true;
			this->posNum1_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posNum1_lbl->Location = System::Drawing::Point(20, 120);
			this->posNum1_lbl->Name = L"posNum1_lbl";
			this->posNum1_lbl->Size = System::Drawing::Size(40, 39);
			this->posNum1_lbl->TabIndex = 1;
			this->posNum1_lbl->Text = L"1)";
			// 
			// posNum2_lbl
			// 
			this->posNum2_lbl->AutoSize = true;
			this->posNum2_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posNum2_lbl->Location = System::Drawing::Point(20, 182);
			this->posNum2_lbl->Name = L"posNum2_lbl";
			this->posNum2_lbl->Size = System::Drawing::Size(44, 39);
			this->posNum2_lbl->TabIndex = 2;
			this->posNum2_lbl->Text = L"2)";
			// 
			// posNum3_lbl
			// 
			this->posNum3_lbl->AutoSize = true;
			this->posNum3_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posNum3_lbl->Location = System::Drawing::Point(20, 245);
			this->posNum3_lbl->Name = L"posNum3_lbl";
			this->posNum3_lbl->Size = System::Drawing::Size(44, 39);
			this->posNum3_lbl->TabIndex = 3;
			this->posNum3_lbl->Text = L"3)";
			// 
			// posNum4_lbl
			// 
			this->posNum4_lbl->AutoSize = true;
			this->posNum4_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posNum4_lbl->Location = System::Drawing::Point(20, 305);
			this->posNum4_lbl->Name = L"posNum4_lbl";
			this->posNum4_lbl->Size = System::Drawing::Size(44, 39);
			this->posNum4_lbl->TabIndex = 4;
			this->posNum4_lbl->Text = L"4)";
			// 
			// posNum5_lbl
			// 
			this->posNum5_lbl->AutoSize = true;
			this->posNum5_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posNum5_lbl->Location = System::Drawing::Point(20, 370);
			this->posNum5_lbl->Name = L"posNum5_lbl";
			this->posNum5_lbl->Size = System::Drawing::Size(44, 39);
			this->posNum5_lbl->TabIndex = 5;
			this->posNum5_lbl->Text = L"5)";
			// 
			// posName5_lbl
			// 
			this->posName5_lbl->AutoSize = true;
			this->posName5_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posName5_lbl->Location = System::Drawing::Point(112, 370);
			this->posName5_lbl->Name = L"posName5_lbl";
			this->posName5_lbl->Size = System::Drawing::Size(167, 39);
			this->posName5_lbl->TabIndex = 10;
			this->posName5_lbl->Text = L"Pos Name 5";
			this->posName5_lbl->Visible = false;
			// 
			// posName4_lbl
			// 
			this->posName4_lbl->AutoSize = true;
			this->posName4_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posName4_lbl->Location = System::Drawing::Point(112, 305);
			this->posName4_lbl->Name = L"posName4_lbl";
			this->posName4_lbl->Size = System::Drawing::Size(167, 39);
			this->posName4_lbl->TabIndex = 9;
			this->posName4_lbl->Text = L"Pos Name 4";
			this->posName4_lbl->Visible = false;
			// 
			// posName3_lbl
			// 
			this->posName3_lbl->AutoSize = true;
			this->posName3_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posName3_lbl->Location = System::Drawing::Point(112, 245);
			this->posName3_lbl->Name = L"posName3_lbl";
			this->posName3_lbl->Size = System::Drawing::Size(167, 39);
			this->posName3_lbl->TabIndex = 8;
			this->posName3_lbl->Text = L"Pos Name 3";
			this->posName3_lbl->Visible = false;
			// 
			// posName2_lbl
			// 
			this->posName2_lbl->AutoSize = true;
			this->posName2_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posName2_lbl->Location = System::Drawing::Point(112, 182);
			this->posName2_lbl->Name = L"posName2_lbl";
			this->posName2_lbl->Size = System::Drawing::Size(167, 39);
			this->posName2_lbl->TabIndex = 7;
			this->posName2_lbl->Text = L"Pos Name 2";
			this->posName2_lbl->Visible = false;
			// 
			// posName1_lbl
			// 
			this->posName1_lbl->AutoSize = true;
			this->posName1_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posName1_lbl->Location = System::Drawing::Point(112, 120);
			this->posName1_lbl->Name = L"posName1_lbl";
			this->posName1_lbl->Size = System::Drawing::Size(163, 39);
			this->posName1_lbl->TabIndex = 6;
			this->posName1_lbl->Text = L"Pos Name 1";
			this->posName1_lbl->Visible = false;
			// 
			// posScore5_lbl
			// 
			this->posScore5_lbl->AutoSize = true;
			this->posScore5_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posScore5_lbl->Location = System::Drawing::Point(378, 370);
			this->posScore5_lbl->Name = L"posScore5_lbl";
			this->posScore5_lbl->Size = System::Drawing::Size(68, 39);
			this->posScore5_lbl->TabIndex = 15;
			this->posScore5_lbl->Text = L"000";
			this->posScore5_lbl->Visible = false;
			// 
			// posScore4_lbl
			// 
			this->posScore4_lbl->AutoSize = true;
			this->posScore4_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posScore4_lbl->Location = System::Drawing::Point(378, 305);
			this->posScore4_lbl->Name = L"posScore4_lbl";
			this->posScore4_lbl->Size = System::Drawing::Size(68, 39);
			this->posScore4_lbl->TabIndex = 14;
			this->posScore4_lbl->Text = L"000";
			this->posScore4_lbl->Visible = false;
			// 
			// posScore3_lbl
			// 
			this->posScore3_lbl->AutoSize = true;
			this->posScore3_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posScore3_lbl->Location = System::Drawing::Point(378, 245);
			this->posScore3_lbl->Name = L"posScore3_lbl";
			this->posScore3_lbl->Size = System::Drawing::Size(68, 39);
			this->posScore3_lbl->TabIndex = 13;
			this->posScore3_lbl->Text = L"000";
			this->posScore3_lbl->Visible = false;
			// 
			// posScore2_lbl
			// 
			this->posScore2_lbl->AutoSize = true;
			this->posScore2_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posScore2_lbl->Location = System::Drawing::Point(378, 182);
			this->posScore2_lbl->Name = L"posScore2_lbl";
			this->posScore2_lbl->Size = System::Drawing::Size(68, 39);
			this->posScore2_lbl->TabIndex = 12;
			this->posScore2_lbl->Text = L"000";
			this->posScore2_lbl->Visible = false;
			// 
			// posScore1_lbl
			// 
			this->posScore1_lbl->AutoSize = true;
			this->posScore1_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->posScore1_lbl->Location = System::Drawing::Point(378, 120);
			this->posScore1_lbl->Name = L"posScore1_lbl";
			this->posScore1_lbl->Size = System::Drawing::Size(68, 39);
			this->posScore1_lbl->TabIndex = 11;
			this->posScore1_lbl->Text = L"000";
			this->posScore1_lbl->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(367, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 39);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Score";
			// 
			// PosName
			// 
			this->PosName->AutoSize = true;
			this->PosName->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PosName->Location = System::Drawing::Point(146, 67);
			this->PosName->Name = L"PosName";
			this->PosName->Size = System::Drawing::Size(94, 39);
			this->PosName->TabIndex = 17;
			this->PosName->Text = L"Name";
			// 
			// PosNum
			// 
			this->PosNum->AutoSize = true;
			this->PosNum->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PosNum->Location = System::Drawing::Point(6, 67);
			this->PosNum->Name = L"PosNum";
			this->PosNum->Size = System::Drawing::Size(120, 39);
			this->PosNum->TabIndex = 16;
			this->PosNum->Text = L"Position";
			// 
			// newName
			// 
			this->newName->Enabled = false;
			this->newName->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->newName->Location = System::Drawing::Point(27, 496);
			this->newName->Name = L"newName";
			this->newName->Size = System::Drawing::Size(275, 40);
			this->newName->TabIndex = 19;
			this->newName->Text = L"Anonymous";
			// 
			// Msg_lbl
			// 
			this->Msg_lbl->AutoSize = true;
			this->Msg_lbl->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Msg_lbl->Location = System::Drawing::Point(20, 429);
			this->Msg_lbl->Name = L"Msg_lbl";
			this->Msg_lbl->Size = System::Drawing::Size(128, 39);
			this->Msg_lbl->TabIndex = 20;
			this->Msg_lbl->Text = L"Message";
			// 
			// submit_btn
			// 
			this->submit_btn->Enabled = false;
			this->submit_btn->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->submit_btn->Location = System::Drawing::Point(355, 496);
			this->submit_btn->Name = L"submit_btn";
			this->submit_btn->Size = System::Drawing::Size(117, 40);
			this->submit_btn->TabIndex = 21;
			this->submit_btn->Text = L"Submit";
			this->submit_btn->UseVisualStyleBackColor = true;
			this->submit_btn->Click += gcnew System::EventHandler(this, &leaderboard::submit_btn_Click);
			// 
			// leaderboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(531, 571);
			this->Controls->Add(this->submit_btn);
			this->Controls->Add(this->Msg_lbl);
			this->Controls->Add(this->newName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PosName);
			this->Controls->Add(this->PosNum);
			this->Controls->Add(this->posScore5_lbl);
			this->Controls->Add(this->posScore4_lbl);
			this->Controls->Add(this->posScore3_lbl);
			this->Controls->Add(this->posScore2_lbl);
			this->Controls->Add(this->posScore1_lbl);
			this->Controls->Add(this->posName5_lbl);
			this->Controls->Add(this->posName4_lbl);
			this->Controls->Add(this->posName3_lbl);
			this->Controls->Add(this->posName2_lbl);
			this->Controls->Add(this->posName1_lbl);
			this->Controls->Add(this->posNum5_lbl);
			this->Controls->Add(this->posNum4_lbl);
			this->Controls->Add(this->posNum3_lbl);
			this->Controls->Add(this->posNum2_lbl);
			this->Controls->Add(this->posNum1_lbl);
			this->Controls->Add(this->mode_name_lbl);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"leaderboard";
			this->Text = L"Leaderboard";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &leaderboard::leaderboard_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: void change_visibility(int i) {
			if (i == 1)
				if (posName1_lbl->Visible == false)
					posName1_lbl->Visible = true, posScore1_lbl->Visible = true;
				else
					posName1_lbl->Visible = false, posScore1_lbl->Visible = false;
			else if(i == 2)
				if (posName2_lbl->Visible == false)
					posName2_lbl->Visible = true, posScore2_lbl->Visible = true;
				else
					posName2_lbl->Visible = false, posScore2_lbl->Visible = false;
			else if (i == 3)
				if (posName3_lbl->Visible == false)
					posName3_lbl->Visible = true, posScore3_lbl->Visible = true;
				else
					posName3_lbl->Visible = false, posScore3_lbl->Visible = false;
			else if (i == 4)
				if (posName4_lbl->Visible == false)
					posName4_lbl->Visible = true, posScore4_lbl->Visible = true;
				else
					posName4_lbl->Visible = false, posScore4_lbl->Visible = false;
			else if (i == 5)
				if (posName5_lbl->Visible == false)
					posName5_lbl->Visible = true, posScore5_lbl->Visible = true;
				else
					posName5_lbl->Visible = false, posScore5_lbl->Visible = false;
		}

		private: void show_pos(int score, String^ name, int pos) {
			if (pos == 1) {
				posName1_lbl->Visible = true, posScore1_lbl->Visible = true;
				posName1_lbl->Text = name, posScore1_lbl->Text = score.ToString(L"D3");
			}
			else if (pos == 2) {
				posName2_lbl->Visible = true, posScore2_lbl->Visible = true;
				posName2_lbl->Text = name, posScore2_lbl->Text = score.ToString(L"D3");
			}
			else if (pos == 3) {
				posName3_lbl->Visible = true, posScore3_lbl->Visible = true;
				posName3_lbl->Text = name, posScore3_lbl->Text = score.ToString(L"D3");
			}
			else if (pos == 4) {
				posName4_lbl->Visible = true, posScore4_lbl->Visible = true;
				posName4_lbl->Text = name, posScore4_lbl->Text = score.ToString(L"D3");
			}
			else if (pos == 5) {
				posName5_lbl->Visible = true, posScore5_lbl->Visible = true;
				posName5_lbl->Text = name, posScore5_lbl->Text = score.ToString(L"D3");
			}
		}

		private: void shiftRight(int p) {
			for (int i = p; p < posNums - 1; p++)
				posNames[i + 1] = posNames[i], posScores[i + 1] = posScores[i];
		}

		public: void ClrStringToStdString(std::string& outStr, String^ str) {
			IntPtr ansiStr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
			outStr = (const char*)ansiStr.ToPointer();
			System::Runtime::InteropServices::Marshal::FreeHGlobal(ansiStr);
		}

	private: System::Void submit_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		if (should_add == true) {
			shiftRight(curPos);
			posScores[curPos] = curScore;
			String^ tempSystemString = gcnew String(newName->Text);
			posNames[curPos] = tempSystemString;
			submitted = true;
		}

		for (int i = 0; i < posNums; i++)
			show_pos(posScores[i], posNames[i], i + 1);

		submit_btn->Enabled = false;
		newName->Enabled = false;
	}
private: System::Void leaderboard_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (submitted == false && should_add == true) {
		shiftRight(curPos);
		posScores[curPos] = curScore;
		String^ tempSystemString = gcnew String(newName->Text);
		posNames[curPos] = tempSystemString;
		submitted = true;
	}

	if (game_mode == 0)
		filename = gcnew String("easy.dat"), mode_name_lbl->Text = L"Easy Mode:";
	else if (game_mode == 1)
		filename = gcnew String("medium.dat"), mode_name_lbl->Text = L"Medium Mode:";
	else if (game_mode == 2)
		filename = gcnew String("hard.dat"), mode_name_lbl->Text = L"Hard Mode:";

	std::string file;
	ClrStringToStdString(file, filename);
	std::ofstream fout;
	fout.open(file.c_str());

	std::string tempStr;

	fout << posNums << std::endl;
	for (int i = 0; i < posNums; i++) {
		ClrStringToStdString(tempStr, posNames[i]);
		fout << tempStr << std::endl;
		fout << posScores[i] << std::endl;
	}

	fout.close();
}
};
}
