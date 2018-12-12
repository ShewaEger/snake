#pragma once

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Lose
	/// </summary>
	public ref class Lose : public System::Windows::Forms::Form
	{
	public:
		Lose(unsigned record, unsigned time)
		{
			InitializeComponent();
			this->record = record;
			label1->Text += L"\n ��� ����: " + (record).ToString() + L"\n";
			label1->Text += L"����� ����: " + (time / 60).ToString("D2") + L":" + (time % 60).ToString("D2");
			textBox1->Text = Environment::UserName;
		}
	private: unsigned record;
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Lose()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Lose::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 105);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(244, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button1->Location = System::Drawing::Point(262, 105);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 20);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lose::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(20, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(322, 26);
			this->label1->TabIndex = 2;
			this->label1->Text = L"�� ���������.\r\n��������, ��� ������ ����� �������.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Lose
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(362, 156);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(50, 50);
			this->MaximizeBox = false;
			this->Name = L"Lose";
			this->Text = L"You lose";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SaveScore(int sc) {
		String^ str;
		array<wchar_t>^ separator = { L'|', L'\n' }; //�����������
		array<String^>^ add = { textBox1->Text, Convert::ToString(sc) }; //������ ��� ����������
		try { //����� ����������
			IO::StreamReader^ rdr = gcnew IO::StreamReader(Application::UserAppDataPath + "\\result");
			str = rdr->ReadToEnd();
			rdr->Close();
		}
		catch (System::IO::FileNotFoundException^ rdr) { //���� ���� �� ������
			//�� ������ ������� ����� (��������� � ���������� �� ����� �, ���������� ������ ����� ��������� ������)
			IO::StreamWriter^ wrt = gcnew IO::StreamWriter(Application::UserAppDataPath + "\\result", false);
			wrt->Write(Environment::UserName + L"|" + Convert::ToString(sc) + L'|'); //����� ���������
			wrt->Close();
			return;
		}
		//int r = Convert::ToInt32(str);
		array<String^>^ rplc = str->Split(separator); //����� ������
		Array::Resize(rplc, rplc->Length - 1); //������� ������ �������
		int i;
		for (i = 1; i < rplc->Length; i += 2) { //���� ���� �������� ������
			if (Convert::ToInt32(rplc[i]) < sc) {
				break;
			}
		}
		if (i > rplc->Length && rplc->Length >= 20) return; //���� ���������� �������� - 10 � ������� ����� �� �����, �� �������
		if (i == rplc->Length) {//���� ������� � ����� �������
			Array::Resize(rplc, rplc->Length + 2); //������ ������ � ������
			rplc[rplc->Length - 2] = add[0];
			rplc[rplc->Length - 1] = add[1];
		}
		else { //����� � ��������
			if (rplc->Length < 20) Array::Resize(rplc, rplc->Length + 2); //���� ������ 10 ��-���, �� ��������� ���
			int j = rplc->Length - 1;//����� �������� ��� �������� ������� ������
			for (; j > i; j--)
				rplc[j] = rplc[j - 2];
			rplc[i - 1] = add[0];//� ��������� �� ������ �����
			rplc[i] = add[1];
		}
		//����� � ����
		IO::StreamWriter^ wrt = gcnew IO::StreamWriter(Application::UserAppDataPath + "\\result", false);
		for (i = 0; i < rplc->Length; i += 2) {
			wrt->Write(rplc[i] + L'|' + rplc[i + 1] + L'|');
		}
		wrt->Close();
		return;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox1->Text->IndexOf("|") >= 0) { //��������� ���� �� ������� ����������� ��������
			MessageBox::Show("���� �� ������ ��������� ������ \"|\"", "������ �����");
			return;
		}
		SaveScore(record);
		this->Close();
	}
	};
}
