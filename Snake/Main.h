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
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
		int px = 10, py = 0;
	private: System::Windows::Forms::ToolStripMenuItem^  рекордыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  правилаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Timer^  time;





	private: System::Windows::Forms::ToolStripMenuItem^  новаяИграToolStripMenuItem;
	public:
		Main(void)
		{
			//Resources::ResourceManager^ rm = gcnew Resources::ResourceManager;
			InitializeComponent();
			// Инициализация переменных
			g = pictureBox1->CreateGraphics(); // Где рисовать
			p = gcnew SolidBrush(Color::DarkOliveGreen); // цвет змейки
			pb1 = gcnew SolidBrush(pictureBox1->BackColor); // цвет поля
			pa = gcnew SolidBrush(Color::Red); // цвет яблока
			label1->Text = L"Score: 0";
			resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid)); // Переменная нужна что бы вытянуть из екзешника ресурс
			//Выковыриваю ресурс из exeШника
			snd = gcnew Media::SoundPlayer(cli::safe_cast<System::IO::Stream^>(resources->GetObject(L"sound")));
			snd->PlayLooping(); //Запускаю в цикле
			pictureBox2->Image = cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sndOn"));
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::Timer^  gameLoop;


	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->новаяИграToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правилаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->рекордыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->файлToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(264, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->новаяИграToolStripMenuItem,
					this->правилаToolStripMenuItem, this->рекордыToolStripMenuItem, this->aboutToolStripMenuItem, this->toolStripSeparator1, this->выходToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			this->файлToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::файлToolStripMenuItem_Click);
			// 
			// новаяИграToolStripMenuItem
			// 
			this->новаяИграToolStripMenuItem->Name = L"новаяИграToolStripMenuItem";
			this->новаяИграToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->новаяИграToolStripMenuItem->Text = L"Новая игра";
			this->новаяИграToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::новаяИграToolStripMenuItem_Click);
			// 
			// правилаToolStripMenuItem
			// 
			this->правилаToolStripMenuItem->Name = L"правилаToolStripMenuItem";
			this->правилаToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->правилаToolStripMenuItem->Text = L"Правила";
			this->правилаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::правилаToolStripMenuItem_Click);
			// 
			// рекордыToolStripMenuItem
			// 
			this->рекордыToolStripMenuItem->Name = L"рекордыToolStripMenuItem";
			this->рекордыToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->рекордыToolStripMenuItem->Text = L"Рекорды";
			this->рекордыToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::рекордыToolStripMenuItem_Click);
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
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::выходToolStripMenuItem_Click);
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
	private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

	private: bool Self(List &a) { // Проверяю на столкновения с самим собой
		Iter it(a);  // итератор для структуры
		it.First(); 
		it.Next(); //устанавливаю на второй элемент
		for (; it.isNext(); it.Next()) {
			if (a.start->p.isIntersection(it.CurrItem())) break; // Если пересеклось, то выхожу из цикла
		}
		return &it.CurrItem() != &(a.end->p); // И возвращаю результат сравнения
	}
	private: Graphics^ g; //Выношу вне цикла все создания объектов для большей оптимизации
	private: SolidBrush^ p;//Вверху уже обсуждалось
	private: SolidBrush^ pb1;
	private: SolidBrush^ pa;
	private: bool fTurn = false, fNewGame = true, fPaint = false; // названия говорят сами за себя
	private: unsigned GameTime; 
	private: Media::SoundPlayer^ snd; //Объект, воспроизводящий музыку
			 System::ComponentModel::ComponentResourceManager^  resources; // объект, который знает о ресурсах
			 void Paint(List &a, Cell &b) { // Вызывается косвенно при перерисовке
				 Iter it(a);
				 if (a.isEmpty()) return; //Если структура не пустая
				 for (it.First(); it.isNext(); it.Next()) {
					 it.CurrItem().Draw(g, p); // отборажаем змейку и яблоко
				 }
				 b.Draw(g, pa);
			 }
	private: System::Void gameLoop_Tick(System::Object^  sender, System::EventArgs^  e) {
		static List snake;
		static Iter it(snake);
		static Cell apple, *tmp = NULL; //Во избежание утечек памяти подбил все вот таким костылем
		static bool isApple;
		static unsigned score = 0;
		Random^ rnd = gcnew Random;
		if (fPaint) {
			fPaint = false; //Если случилась глобальная перерисовка
			Paint(snake, apple);
		}
		if (fNewGame) { //Если новая игра
			time->Enabled = true; //запускаем время
			GameTime = 0; //Устанавливаем время в 0
			fNewGame = false; //говорим, что тут не новая игра
			it.Clear();							//Чищу структуру
			g->Clear(pictureBox1->BackColor);	//чищу поле
			isApple = false;					//Говорю, что яблока еще нет
			score = 0;							// обнуляю счет
			label1->Text = L"Score: " + Convert::ToString(score);
			this->Text = "Snake [00:00]";
			px = 10; //устанавливаю приращение по x
			py = 0; //по у
		}
		if (snake.isEmpty()) {			//Первая инициализация
			tmp = new Cell(0, 0);		//Добавляю первый элемент
			snake.push_front(*tmp);		//Заношу в лист
			delete tmp;					//удаляю временный элемент
			tmp = new Cell(px, 0);		// аналогично
			snake.push_front(*tmp);
			it.First().Draw(g, p);		//Рисую их
			it.Next().Draw(g, p);
			isApple = false;			// говорю, что яблочка не существует
		}
		if (!isApple) { //Если яблока не существует
			while (1) {
				apple.Setsize(8); //Задаем размер
				apple.Setx((rnd->Next() % ((pictureBox1->Size.Width)) / 10) * 10); //Устанавливаем новые координаты
				apple.Sety((rnd->Next() % ((pictureBox1->Size.Height)) / 10) * 10);

				for (it.First(); it.isNext(); it.Next()) { // Проверяем не попали ли мы на змейку
					if (it.CurrItem().isIntersection(apple)) break;
				}
				if (&it.CurrItem() == &(snake.end->p)) break; //Если весь цикл пройден до конца, то все норм
			}
			apple.Draw(g, pa); // Рисую яблоко
			isApple = true; //Говорим, что яблоко на поле
		}
		tmp = new Cell(it[0].Getx() + px, it[0].Gety() + py); //Создаем новый сегмент змейки
		snake.push_front(*tmp);//добавляем его в структуру
		delete tmp;
		//Далее различные проверки на столкновения
		if (Self(snake) || it[0].Getx() + 10 > pictureBox1->Size.Width || it[0].Gety() + 10 > pictureBox1->Size.Height || it[0].Gety() < 0 || it[0].Getx() < 0) {
			gameLoop->Enabled = false; //Выключаем игровой цикл
			time->Enabled = false; //Выключаем счет времени
			Lose^ lose =gcnew Lose(score, GameTime); // Выводим окно с приглашением ввести имя пользователя
			lose->ShowDialog();
			//Выводим смешную картинку
			pictureBox1->BackgroundImage = cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GameOver"));
			
			//чистим структуру
			it.Clear();
			return;
		}
		if (!it[0].isIntersection(apple)) { // Если не попали на яблоко
			it.Last().Draw(g, pb1); // последнюю вершину стираем 
			it.Prev(); // и удаляем
			snake.pop_back();
		}
		else {
			apple.Draw(g, pb1);//иначе убираем с поля яблоко
			it[0].Draw(g, p);//отрисовуем обратно вершину
			isApple = false;//говорим, что яблока не существует
			score += 10; //обновляем результат
			label1->Text = L"Score: " + Convert::ToString(score);
		}

		it.First().Draw(g, p); // Рисуем первую вершину
		fTurn = true;
	}
	private: System::Void Main_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (!fTurn) return;//Если змейка еще не повернулась, то выход из функции
		switch (e->KeyCode) { 
		case Keys::Up: //формируем различные приращения
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
		case Keys::Space: // По пробелу выключаем, или включаем игровой цикл
			gameLoop->Enabled = !(gameLoop->Enabled);
			return;
		}
		fTurn = false; //запрещаем дальнейшее изменение приращений пока это все не применится в змейке
					   
	}
	private: System::Void новаяИграToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		gameLoop->Enabled = true; //Если новая игра, то включаем игровой цикл
		fNewGame = true; //С помощью флага оповещаем игровой цикл, что нужно начать новую игру
	}
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		fPaint = true; //Если произошла перерисовка
	}
	private: System::Void рекордыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Records^ rcrd = gcnew Records(); //Показать окно с рекордами
		rcrd->ShowDialog();
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		About^ abt = gcnew About; //показать окно об авторе
		abt->ShowDialog();
	}
	private: bool fPlaySnd = true; //Запущена музыка, или нет
	private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (fPlaySnd) { //если да, то выключаем
			snd->Stop();
			//И меняем картинку
			pictureBox2->Image = cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sndOff"));
		}
		else {//Иначе включаем и меняем картинку
			snd->PlayLooping();
			pictureBox2->Image = cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sndOn"));
		}
		fPlaySnd = !fPlaySnd;
	}
	private: System::Void правилаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Rules^ rl = gcnew Rules; //отображает окно с правилами
		rl->ShowDialog();
	}
	
	private: System::Void time_Tick(System::Object^  sender, System::EventArgs^  e) {
		GameTime++; // Счетчик времени в игре
		this->Text = L"Snake [" + (GameTime/60).ToString("D2") + ":" + (GameTime % 60).ToString("D2") + L"]";
	}
private: System::Void файлToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
