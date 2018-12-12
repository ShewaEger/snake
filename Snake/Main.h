#pragma once
#include "Cell.cpp"
#include "Records.h"
#include "About.h"
#include "Rules.h"
#include "Lose.h"
namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
		int px = 10, py = 0;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Timer^  time;





	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	public:
		Main(void)
		{
			//Resources::ResourceManager^ rm = gcnew Resources::ResourceManager;
			InitializeComponent();
			// ������������� ����������
			g = pictureBox1->CreateGraphics(); // ��� ��������
			p = gcnew SolidBrush(Color::DarkOliveGreen); // ���� ������
			pb1 = gcnew SolidBrush(pictureBox1->BackColor); // ���� ����
			pa = gcnew SolidBrush(Color::Red); // ���� ������
			label1->Text = L"Score: 0";
			resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid)); // ���������� ����� ��� �� �������� �� ��������� ������
			//����������� ������ �� exe�����
			snd = gcnew Media::SoundPlayer(cli::safe_cast<System::IO::Stream^>(resources->GetObject(L"sound")));
			snd->PlayLooping(); //�������� � �����
			pictureBox2->Image = cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sndOn"));
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::Timer^  gameLoop;


	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>




#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameLoop = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->time = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Honeydew;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Location = System::Drawing::Point(12, 63);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(240, 300);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Main::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Harrington", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Teal;
			this->label1->Location = System::Drawing::Point(12, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Score:";
			this->label1->Click += gcnew System::EventHandler(this, &Main::label1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::SteelBlue;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->����ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(264, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->���������ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->�������ToolStripMenuItem, this->aboutToolStripMenuItem, this->toolStripSeparator1, this->�����ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::����ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->���������ToolStripMenuItem->Text = L"����� ����";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::�������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::�������ToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::aboutToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(128, 6);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::�����ToolStripMenuItem_Click);
			// 
			// gameLoop
			// 
			this->gameLoop->Enabled = true;
			this->gameLoop->Tick += gcnew System::EventHandler(this, &Main::gameLoop_Tick);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->pictureBox2->Location = System::Drawing::Point(228, 31);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(24, 24);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Main::pictureBox2_Click);
			// 
			// time
			// 
			this->time->Interval = 1000;
			this->time->Tick += gcnew System::EventHandler(this, &Main::time_Tick);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(264, 373);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Main";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Snake [00:00]";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Main::Main_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void contextMenuStrip1_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

	private: bool Self(List &a) { // �������� �� ������������ � ����� �����
		Iter it(a);  // �������� ��� ���������
		it.First(); 
		it.Next(); //������������ �� ������ �������
		for (; it.isNext(); it.Next()) {
			if (a.start->p.isIntersection(it.CurrItem())) break; // ���� �����������, �� ������ �� �����
		}
		return &it.CurrItem() != &(a.end->p); // � ��������� ��������� ���������
	}
	private: Graphics^ g; //������ ��� ����� ��� �������� �������� ��� ������� �����������
	private: SolidBrush^ p;//������ ��� �����������
	private: SolidBrush^ pb1;
	private: SolidBrush^ pa;
	private: bool fTurn = false, fNewGame = true, fPaint = false; // �������� ������� ���� �� ����
	private: unsigned GameTime; 
	private: Media::SoundPlayer^ snd; //������, ��������������� ������
			 System::ComponentModel::ComponentResourceManager^  resources; // ������, ������� ����� � ��������
			 void Paint(List &a, Cell &b) { // ���������� �������� ��� �����������
				 Iter it(a);
				 if (a.isEmpty()) return; //���� ��������� �� ������
				 for (it.First(); it.isNext(); it.Next()) {
					 it.CurrItem().Draw(g, p); // ���������� ������ � ������
				 }
				 b.Draw(g, pa);
			 }
	private: System::Void gameLoop_Tick(System::Object^  sender, System::EventArgs^  e) {
		static List snake;
		static Iter it(snake);
		static Cell apple, *tmp = NULL; //�� ��������� ������ ������ ������ ��� ��� ����� ��������
		static bool isApple;
		static unsigned score = 0;
		Random^ rnd = gcnew Random;
		if (fPaint) {
			fPaint = false; //���� ��������� ���������� �����������
			Paint(snake, apple);
		}
		if (fNewGame) { //���� ����� ����
			time->Enabled = true; //��������� �����
			GameTime = 0; //������������� ����� � 0
			fNewGame = false; //�������, ��� ��� �� ����� ����
			it.Clear();							//���� ���������
			g->Clear(pictureBox1->BackColor);	//���� ����
			isApple = false;					//������, ��� ������ ��� ���
			score = 0;							// ������� ����
			label1->Text = L"Score: " + Convert::ToString(score);
			this->Text = "Snake [00:00]";
			px = 10; //������������ ���������� �� x
			py = 0; //�� �
		}
		if (snake.isEmpty()) {			//������ �������������
			tmp = new Cell(0, 0);		//�������� ������ �������
			snake.push_front(*tmp);		//������ � ����
			delete tmp;					//������ ��������� �������
			tmp = new Cell(px, 0);		// ����������
			snake.push_front(*tmp);
			it.First().Draw(g, p);		//����� ��
			it.Next().Draw(g, p);
			isApple = false;			// ������, ��� ������� �� ����������
		}
		if (!isApple) { //���� ������ �� ����������
			while (1) {
				apple.Setsize(8); //������ ������
				apple.Setx((rnd->Next() % ((pictureBox1->Size.Width)) / 10) * 10); //������������� ����� ����������
				apple.Sety((rnd->Next() % ((pictureBox1->Size.Height)) / 10) * 10);

				for (it.First(); it.isNext(); it.Next()) { // ��������� �� ������ �� �� �� ������
					if (it.CurrItem().isIntersection(apple)) break;
				}
				if (&it.CurrItem() == &(snake.end->p)) break; //���� ���� ���� ������� �� �����, �� ��� ����
			}
			apple.Draw(g, pa); // ����� ������
			isApple = true; //�������, ��� ������ �� ����
		}
		tmp = new Cell(it[0].Getx() + px, it[0].Gety() + py); //������� ����� ������� ������
		snake.push_front(*tmp);//��������� ��� � ���������
		delete tmp;
		//����� ��������� �������� �� ������������
		if (Self(snake) || it[0].Getx() + 10 > pictureBox1->Size.Width || it[0].Gety() + 10 > pictureBox1->Size.Height || it[0].Gety() < 0 || it[0].Getx() < 0) {
			gameLoop->Enabled = false; //��������� ������� ����
			time->Enabled = false; //��������� ���� �������
			Lose^ lose =gcnew Lose(score, GameTime); // ������� ���� � ������������ ������ ��� ������������
			lose->ShowDialog();
			//������� ������� ��������
			pictureBox1->BackgroundImage = cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GameOver"));
			
			//������ ���������
			it.Clear();
			return;
		}
		if (!it[0].isIntersection(apple)) { // ���� �� ������ �� ������
			it.Last().Draw(g, pb1); // ��������� ������� ������� 
			it.Prev(); // � �������
			snake.pop_back();
		}
		else {
			apple.Draw(g, pb1);//����� ������� � ���� ������
			it[0].Draw(g, p);//���������� ������� �������
			isApple = false;//�������, ��� ������ �� ����������
			score += 10; //��������� ���������
			label1->Text = L"Score: " + Convert::ToString(score);
		}

		it.First().Draw(g, p); // ������ ������ �������
		fTurn = true;
	}
	private: System::Void Main_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (!fTurn) return;//���� ������ ��� �� �����������, �� ����� �� �������
		switch (e->KeyCode) { 
		case Keys::Up: //��������� ��������� ����������
			if (py == 10) return;
			py = -10;
			px = 0;
			break;
		case Keys::Down:
			if (py == -10) return;
			py = 10;
			px = 0;
			break;
		case Keys::Right:
			if (px == -10) return;
			py = 0;
			px = 10;
			break;
		case Keys::Left:
			if (px == 10) return;
			py = 0;
			px = -10;
			break;
		case Keys::Space: // �� ������� ���������, ��� �������� ������� ����
			gameLoop->Enabled = !(gameLoop->Enabled);
			return;
		}
		fTurn = false; //��������� ���������� ��������� ���������� ���� ��� ��� �� ���������� � ������
					   
	}
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		gameLoop->Enabled = true; //���� ����� ����, �� �������� ������� ����
		fNewGame = true; //� ������� ����� ��������� ������� ����, ��� ����� ������ ����� ����
	}
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		fPaint = true; //���� ��������� �����������
	}
	private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Records^ rcrd = gcnew Records(); //�������� ���� � ���������
		rcrd->ShowDialog();
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		About^ abt = gcnew About; //�������� ���� �� ������
		abt->ShowDialog();
	}
	private: bool fPlaySnd = true; //�������� ������, ��� ���
	private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (fPlaySnd) { //���� ��, �� ���������
			snd->Stop();
			//� ������ ��������
			pictureBox2->Image = cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sndOff"));
		}
		else {//����� �������� � ������ ��������
			snd->PlayLooping();
			pictureBox2->Image = cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sndOn"));
		}
		fPlaySnd = !fPlaySnd;
	}
	private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Rules^ rl = gcnew Rules; //���������� ���� � ���������
		rl->ShowDialog();
	}
	
	private: System::Void time_Tick(System::Object^  sender, System::EventArgs^  e) {
		GameTime++; // ������� ������� � ����
		this->Text = L"Snake [" + (GameTime/60).ToString("D2") + ":" + (GameTime % 60).ToString("D2") + L"]";
	}
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
