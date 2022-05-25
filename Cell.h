#pragma once

ref class Cell abstract {
protected:
	bool is_flagged, is_exposed;
	System::Windows::Forms::Button^ btn;
	System::Windows::Forms::PictureBox^ exp_cel;
public:
	Cell(int i, int j, int cell_size) {
		//
		// Button Customization
		//
		btn = gcnew System::Windows::Forms::Button();
		btn->CausesValidation = false;
		btn->Location = System::Drawing::Point((j + 1) * cell_size, (i + 2) * cell_size);
		btn->Name = L"-" + i.ToString() + L"-" + j.ToString();
		btn->Size = System::Drawing::Size(cell_size, cell_size);
		btn->TabStop = false;
		btn->Text = L"-" + i.ToString() + L"-" + j.ToString();
		btn->UseVisualStyleBackColor = true;
		btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		btn->Cursor = System::Windows::Forms::Cursors::Hand;
		btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(184)), static_cast<System::Int32>(static_cast<System::Byte>(184)),
			static_cast<System::Int32>(static_cast<System::Byte>(184)));
		btn->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		btn->BackgroundImage = System::Drawing::Image::FromFile("Cell.png");
		//
		// Exposed Cells
		//
		exp_cel = gcnew System::Windows::Forms::PictureBox;
		exp_cel->Location = System::Drawing::Point((j + 1) * cell_size, (i + 2) * cell_size);
		exp_cel->Name = L"-" + i.ToString() + L"-" + j.ToString() + L"P";
		exp_cel->Size = System::Drawing::Size(cell_size, cell_size);
		exp_cel->TabStop = false;
		exp_cel->SizeMode = PictureBoxSizeMode::StretchImage;
	}

	bool is_mined() { return false; }

	void flag() {
		if (is_exposed == false) {
			if (is_flagged == false) {
				btn->BackgroundImage = System::Drawing::Image::FromFile("flag.png");
				is_flagged = true;
			}
			if (is_flagged == true) {
				btn->BackgroundImage = System::Drawing::Image::FromFile("Cell.png");
				is_flagged = false;
			}
		}
	}
};

