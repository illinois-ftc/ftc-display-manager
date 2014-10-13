#pragma once
#include "Windows.h"
#include "FCSHeader.h"

namespace FCSDisplayController {

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
	private: System::Windows::Forms::Button^  ardConnButton;
	protected:


	private: System::Windows::Forms::TextBox^  red1Out;
	private: System::Windows::Forms::TextBox^  red2Out;
	private: System::Windows::Forms::TextBox^  blue1Out;
	private: System::Windows::Forms::TextBox^  blue2Out;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  red1Disp;
	private: System::Windows::Forms::ComboBox^  red2Disp;
	private: System::Windows::Forms::ComboBox^  blue2Disp;



	private: System::Windows::Forms::ComboBox^  blue1Disp;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TrackBar^  brightnessSlider;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  brightnessLabel;
	public: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  fcsStatus;
	private: System::Windows::Forms::Button^  dispConnBtn;
	private: System::Windows::Forms::ComboBox^  portSelector;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  dispStatus;

	private: System::Windows::Forms::CheckBox^  checkBox1;





	public:
	private:
	private: System::ComponentModel::IContainer^  components;
	public:

	protected:

	private:
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ardConnButton = (gcnew System::Windows::Forms::Button());
			this->red1Out = (gcnew System::Windows::Forms::TextBox());
			this->red2Out = (gcnew System::Windows::Forms::TextBox());
			this->blue1Out = (gcnew System::Windows::Forms::TextBox());
			this->blue2Out = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->red1Disp = (gcnew System::Windows::Forms::ComboBox());
			this->red2Disp = (gcnew System::Windows::Forms::ComboBox());
			this->blue2Disp = (gcnew System::Windows::Forms::ComboBox());
			this->blue1Disp = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->brightnessSlider = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->brightnessLabel = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->fcsStatus = (gcnew System::Windows::Forms::TextBox());
			this->dispConnBtn = (gcnew System::Windows::Forms::Button());
			this->portSelector = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dispStatus = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightnessSlider))->BeginInit();
			this->SuspendLayout();
			// 
			// ardConnButton
			// 
			this->ardConnButton->Location = System::Drawing::Point(260, 62);
			this->ardConnButton->Name = L"ardConnButton";
			this->ardConnButton->Size = System::Drawing::Size(155, 23);
			this->ardConnButton->TabIndex = 0;
			this->ardConnButton->Text = L"Connect to displays";
			this->ardConnButton->UseVisualStyleBackColor = true;
			this->ardConnButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// red1Out
			// 
			this->red1Out->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->red1Out->Location = System::Drawing::Point(3, 16);
			this->red1Out->Name = L"red1Out";
			this->red1Out->ReadOnly = true;
			this->red1Out->Size = System::Drawing::Size(45, 20);
			this->red1Out->TabIndex = 2;
			this->red1Out->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// red2Out
			// 
			this->red2Out->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->red2Out->Location = System::Drawing::Point(54, 16);
			this->red2Out->Name = L"red2Out";
			this->red2Out->ReadOnly = true;
			this->red2Out->Size = System::Drawing::Size(45, 20);
			this->red2Out->TabIndex = 3;
			this->red2Out->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// blue1Out
			// 
			this->blue1Out->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blue1Out->Location = System::Drawing::Point(125, 16);
			this->blue1Out->Name = L"blue1Out";
			this->blue1Out->ReadOnly = true;
			this->blue1Out->Size = System::Drawing::Size(45, 20);
			this->blue1Out->TabIndex = 4;
			this->blue1Out->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// blue2Out
			// 
			this->blue2Out->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blue2Out->Location = System::Drawing::Point(176, 16);
			this->blue2Out->Name = L"blue2Out";
			this->blue2Out->ReadOnly = true;
			this->blue2Out->Size = System::Drawing::Size(45, 20);
			this->blue2Out->TabIndex = 5;
			this->blue2Out->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Red 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(54, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Red 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(176, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Blue 2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(125, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Blue 1";
			// 
			// red1Disp
			// 
			this->red1Disp->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->red1Disp->FormattingEnabled = true;
			this->red1Disp->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"D1", L"D2", L"D3", L"D4" });
			this->red1Disp->Location = System::Drawing::Point(3, 42);
			this->red1Disp->Name = L"red1Disp";
			this->red1Disp->Size = System::Drawing::Size(45, 21);
			this->red1Disp->TabIndex = 10;
			// 
			// red2Disp
			// 
			this->red2Disp->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->red2Disp->FormattingEnabled = true;
			this->red2Disp->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"D1", L"D2", L"D3", L"D4" });
			this->red2Disp->Location = System::Drawing::Point(54, 42);
			this->red2Disp->Name = L"red2Disp";
			this->red2Disp->Size = System::Drawing::Size(45, 21);
			this->red2Disp->TabIndex = 11;
			// 
			// blue2Disp
			// 
			this->blue2Disp->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->blue2Disp->FormattingEnabled = true;
			this->blue2Disp->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"D1", L"D2", L"D3", L"D4" });
			this->blue2Disp->Location = System::Drawing::Point(176, 42);
			this->blue2Disp->Name = L"blue2Disp";
			this->blue2Disp->Size = System::Drawing::Size(45, 21);
			this->blue2Disp->TabIndex = 13;
			// 
			// blue1Disp
			// 
			this->blue1Disp->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->blue1Disp->FormattingEnabled = true;
			this->blue1Disp->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"D1", L"D2", L"D3", L"D4" });
			this->blue1Disp->Location = System::Drawing::Point(125, 42);
			this->blue1Disp->Name = L"blue1Disp";
			this->blue1Disp->Size = System::Drawing::Size(45, 21);
			this->blue1Disp->TabIndex = 12;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->blue2Disp, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->blue1Disp, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->label3, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->blue2Out, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->red2Disp, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->blue1Out, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->red1Disp, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->red1Out, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->red2Out, 1, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 35);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(224, 66);
			this->tableLayoutPanel1->TabIndex = 14;
			// 
			// brightnessSlider
			// 
			this->brightnessSlider->LargeChange = 4;
			this->brightnessSlider->Location = System::Drawing::Point(12, 109);
			this->brightnessSlider->Maximum = 15;
			this->brightnessSlider->Name = L"brightnessSlider";
			this->brightnessSlider->Size = System::Drawing::Size(226, 45);
			this->brightnessSlider->TabIndex = 16;
			this->brightnessSlider->Scroll += gcnew System::EventHandler(this, &MyForm::brightnessSlider_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(79, 141);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Brightness:";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// brightnessLabel
			// 
			this->brightnessLabel->AutoSize = true;
			this->brightnessLabel->Location = System::Drawing::Point(147, 141);
			this->brightnessLabel->MinimumSize = System::Drawing::Size(13, 13);
			this->brightnessLabel->Name = L"brightnessLabel";
			this->brightnessLabel->Size = System::Drawing::Size(21, 13);
			this->brightnessLabel->TabIndex = 18;
			this->brightnessLabel->Text = L"0%";
			this->brightnessLabel->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// fcsStatus
			// 
			this->fcsStatus->BackColor = System::Drawing::Color::DarkSalmon;
			this->fcsStatus->Location = System::Drawing::Point(260, 146);
			this->fcsStatus->Name = L"fcsStatus";
			this->fcsStatus->ReadOnly = true;
			this->fcsStatus->Size = System::Drawing::Size(155, 20);
			this->fcsStatus->TabIndex = 19;
			this->fcsStatus->Text = L"FCS Not Connected";
			this->fcsStatus->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// dispConnBtn
			// 
			this->dispConnBtn->Location = System::Drawing::Point(260, 117);
			this->dispConnBtn->Name = L"dispConnBtn";
			this->dispConnBtn->Size = System::Drawing::Size(155, 23);
			this->dispConnBtn->TabIndex = 20;
			this->dispConnBtn->Text = L"Connect to FCS";
			this->dispConnBtn->UseVisualStyleBackColor = true;
			this->dispConnBtn->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// portSelector
			// 
			this->portSelector->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->portSelector->FormattingEnabled = true;
			this->portSelector->Location = System::Drawing::Point(299, 35);
			this->portSelector->Name = L"portSelector";
			this->portSelector->Size = System::Drawing::Size(71, 21);
			this->portSelector->TabIndex = 21;
			this->portSelector->DropDown += gcnew System::EventHandler(this, &MyForm::comboBox1_DropDown);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(257, 16);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(146, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Dectected display controllers:";
			// 
			// dispStatus
			// 
			this->dispStatus->BackColor = System::Drawing::Color::DarkSalmon;
			this->dispStatus->Location = System::Drawing::Point(260, 91);
			this->dispStatus->Name = L"dispStatus";
			this->dispStatus->ReadOnly = true;
			this->dispStatus->Size = System::Drawing::Size(155, 20);
			this->dispStatus->TabIndex = 23;
			this->dispStatus->Text = L"Displays Not Connected";
			this->dispStatus->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(76, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(98, 17);
			this->checkBox1->TabIndex = 24;
			this->checkBox1->Text = L"Displays Active";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(423, 177);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->dispStatus);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->portSelector);
			this->Controls->Add(this->dispConnBtn);
			this->Controls->Add(this->fcsStatus);
			this->Controls->Add(this->brightnessLabel);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->brightnessSlider);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->ardConnButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"FCS Display Manager";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightnessSlider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->portSelector->SelectedIndex != -1){
			SerialPortData::search = !SerialPortData::search;
		}
		if (!SerialPortData::search){
			SerialPortData::chosenPort = (String^)(this->portSelector->SelectedItem);
			output.rd1 = ((String^)(this->red1Disp->SelectedItem))[1] - '0';
			output.rd2 = ((String^)(this->red2Disp->SelectedItem))[1] - '0';
			output.bd1 = ((String^)(this->blue1Disp->SelectedItem))[1] - '0';
			output.bd2 = ((String^)(this->blue2Disp->SelectedItem))[1] - '0';
			portSelector->Enabled = false;
			this->red1Disp->Enabled = false;
			this->red2Disp->Enabled = false;
			this->blue1Disp->Enabled = false;
			this->blue2Disp->Enabled = false;
			this->ardConnButton->Text = "Disconnect from displays";
		} else {
			this->portSelector->Enabled = true;
			this->red1Disp->Enabled = true;
			this->red2Disp->Enabled = true;
			this->blue1Disp->Enabled = true;
			this->blue2Disp->Enabled = true;
			this->ardConnButton->Text = "Connect to displays";
		}

	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void brightnessSlider_Scroll(System::Object^  sender, System::EventArgs^  e) {
		this->brightnessLabel->Text = String::Format("{0:P0}", ((float)this->brightnessSlider->Value / this->brightnessSlider->Maximum));
		AcquireSRWLockExclusive(&dispLock);
		output.brightness = this->brightnessSlider->Value;
		ReleaseSRWLockExclusive(&dispLock);
	}
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->red1Disp->SelectedIndex = 0;
		this->red2Disp->SelectedIndex = 1;
		this->blue1Disp->SelectedIndex = 2;
		this->blue2Disp->SelectedIndex = 3;
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		AcquireSRWLockShared(&dispLock);
		this->red1Out->Text = gcnew String(output.redDisp1);
		this->red2Out->Text = gcnew String(output.redDisp2);
		this->blue1Out->Text = gcnew String(output.blueDisp1);
		this->blue2Out->Text = gcnew String(output.blueDisp2);
		if (output.FCSConnected){
			this->fcsStatus->Text = "FCS Connected";
			this->fcsStatus->BackColor = Color::YellowGreen;
			this->dispConnBtn->Text = "Disconnect from FCS";
		} else {
			this->fcsStatus->Text = "FCS Not Connected";
			this->fcsStatus->BackColor = Color::DarkSalmon;
			this->dispConnBtn->Text = "Connect to FCS";
		}
		ReleaseSRWLockShared(&dispLock);
		if (!SerialPortData::search) {
			this->dispStatus->Text = "Displays Connected";
			this->dispStatus->BackColor = Color::YellowGreen;
			this->ardConnButton->Text = "Disconnect from displays";
			this->portSelector->Enabled = false;
		} else {
			this->portSelector->Enabled = true;
			this->ardConnButton->Text = "Connect to displays";
			this->dispStatus->Text = "Displays Not Connected";
			this->dispStatus->BackColor = Color::DarkSalmon;
		}

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		output.enabled = !output.enabled;
		if (output.enabled){
			this->dispConnBtn->Text = "Disconnect from FCS";
		} else {
			this->dispConnBtn->Text = "Connect to FCS";
		}
	}
	private: System::Void comboBox1_DropDown(System::Object^  sender, System::EventArgs^  e) {
		AcquireSRWLockShared(&comLock);
		portSelector->Items->Clear();
		for each (String^ portname in SerialPortData::serialPorts){
			if (portname != nullptr) {
				portSelector->Items->Add(portname);
			}
		}
		ReleaseSRWLockShared(&comLock);
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		AcquireSRWLockExclusive(&dispLock);
		output.dispEnabled = this->checkBox1->Checked;
		ReleaseSRWLockExclusive(&dispLock);
	}
};
}
