#pragma once

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Records
	/// </summary>
	public ref class Records : public System::Windows::Forms::Form
	{
	public:
		Records(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Records()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Records::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::LightSteelBlue;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CausesValidation = false;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView1->Enabled = false;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 4;
			this->dataGridView1->ShowCellErrors = false;
			this->dataGridView1->ShowCellToolTips = false;
			this->dataGridView1->ShowEditingIcon = false;
			this->dataGridView1->ShowRowErrors = false;
			this->dataGridView1->Size = System::Drawing::Size(228, 256);
			this->dataGridView1->TabIndex = 101;
			this->dataGridView1->TabStop = false;
			// 
			// Records
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(252, 280);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Records";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Records";
			this->Load += gcnew System::EventHandler(this, &Records::Records_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Records_Load(System::Object^  sender, System::EventArgs^  e) {
		ReadScore(); //��� �������� ����� ������ ���������
	}
	private: System::Void ReadScore() {
		String^ str;
		array<wchar_t>^ separator = { L'|', L'\n' }; //��������� ����������� ������
		try {//��������� �� ����������
			IO::StreamReader^ rdr = gcnew IO::StreamReader(Application::UserAppDataPath + "\\result");
			str = rdr->ReadToEnd();
			rdr->Close();
		}
		catch (System::IO::FileNotFoundException^ rdr) { //���� ����� ���
			return;
		}
		array<String^>^ rplc = str->Split(separator);//����� ������ �� ������������
		Array::Resize(rplc, rplc->Length - 1); //������� ��������� ������ �������
		DataTable^ tabl = gcnew DataTable;//����� �������
		tabl->Columns->Add(L"���"); // ����� �������
		tabl->Columns->Add(L"����");
		for (int i = 0; i < rplc->Length; i += 2) {
			tabl->Rows->Add(rplc[i], rplc[i + 1]); //� ������ �� ��������� � �������
		}
		dataGridView1->DataSource = tabl; //���������� �������
	}
	};
}
