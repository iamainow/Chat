#pragma once
#include "iPerson.h"
#include "iUInt.h"
#include "iRSA.h"
#include "_person_add.h"
#include "_key_generate.h"
namespace Chat
{
	//Standart
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	//TCP/IP
	using namespace System::Net;
	using namespace System::Net::Sockets;
	//Кодировки
	using namespace System::Text;
	public ref class _main : public System::Windows::Forms::Form
	{
	public:
		static String^ HELPFILE="help.html";
		//прослушиваемый порт
	public:
		static const int PORT=14567;
		//мои ключи
	public:
		i::iRSA *MyKey;
		//ключи собеседника
	public: 
		i::iRSA *YourKey;
		//с каким контактом соединен
	public:
		System::String^ IP_CONNECTED;
		//безопасный вызов функции из другого потока
	public:
		delegate void SetTextCallback(String^ IP,String^ text,Color color);
	private:
		System::Windows::Forms::Button^  _send;
		System::Windows::Forms::TextBox^  _text_encode;
		System::Windows::Forms::Button^  _connect;
		System::Windows::Forms::Button^  _disconnect;
		System::ComponentModel::BackgroundWorker^  _server;
		System::Windows::Forms::ListBox^  _name;
		System::Windows::Forms::Button^  _name_add;
		System::Windows::Forms::Button^  _name_remove;
		System::Windows::Forms::Label^  _ip;
		System::Windows::Forms::ContextMenuStrip^  _menu_name;
		System::Windows::Forms::ToolStripMenuItem^  _menu_name_add;
		System::Windows::Forms::ToolStripMenuItem^  _menu_name_delete;
		System::Windows::Forms::ToolStripMenuItem^  _menu_name_save;
		System::Windows::Forms::CheckBox^  _name_autosave;
		System::Windows::Forms::GroupBox^  _address;
		System::Windows::Forms::Button^  _generate_key;
	private: System::Windows::Forms::Timer^  _show_ip_connected;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  _message;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::MenuStrip^  _menu;
	private: System::Windows::Forms::ToolStripMenuItem^  _menu_help;
	private: System::Windows::Forms::ToolStripMenuItem^  _menu_about;
			 System::ComponentModel::IContainer^  components;
	public:
		_main(void):IP_CONNECTED(gcnew String("")),MyKey(nullptr),YourKey(nullptr)
		{
			InitializeComponent();
		}
	protected:
		~_main()
		{
			if(components)
			{
				delete components;
			}
		}
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->_name = (gcnew System::Windows::Forms::ListBox());
			this->_menu_name = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->_menu_name_add = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_menu_name_delete = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_menu_name_save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_name_add = (gcnew System::Windows::Forms::Button());
			this->_name_remove = (gcnew System::Windows::Forms::Button());
			this->_ip = (gcnew System::Windows::Forms::Label());
			this->_name_autosave = (gcnew System::Windows::Forms::CheckBox());
			this->_address = (gcnew System::Windows::Forms::GroupBox());
			this->_generate_key = (gcnew System::Windows::Forms::Button());
			this->_send = (gcnew System::Windows::Forms::Button());
			this->_text_encode = (gcnew System::Windows::Forms::TextBox());
			this->_connect = (gcnew System::Windows::Forms::Button());
			this->_disconnect = (gcnew System::Windows::Forms::Button());
			this->_server = (gcnew System::ComponentModel::BackgroundWorker());
			this->_show_ip_connected = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->_message = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->_menu = (gcnew System::Windows::Forms::MenuStrip());
			this->_menu_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_menu_about = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->_menu_name->SuspendLayout();
			this->_address->SuspendLayout();
			this->_menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// _name
			// 
			this->_name->ContextMenuStrip = this->_menu_name;
			this->_name->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_name->ItemHeight = 16;
			this->_name->Location = System::Drawing::Point(6, 68);
			this->_name->Name = L"_name";
			this->_name->Size = System::Drawing::Size(159, 164);
			this->_name->Sorted = true;
			this->_name->TabIndex = 1;
			this->_name->SelectedIndexChanged += gcnew System::EventHandler(this, &_main::_name_SelectedIndexChanged);
			// 
			// _menu_name
			// 
			this->_menu_name->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->_menu_name_add, this->_menu_name_delete, 
				this->_menu_name_save});
			this->_menu_name->Name = L"_menu_name";
			this->_menu_name->Size = System::Drawing::Size(141, 70);
			// 
			// _menu_name_add
			// 
			this->_menu_name_add->Name = L"_menu_name_add";
			this->_menu_name_add->Size = System::Drawing::Size(140, 22);
			this->_menu_name_add->Text = L"Добавить";
			this->_menu_name_add->Click += gcnew System::EventHandler(this, &_main::_menu_name_add_Click);
			// 
			// _menu_name_delete
			// 
			this->_menu_name_delete->Name = L"_menu_name_delete";
			this->_menu_name_delete->Size = System::Drawing::Size(140, 22);
			this->_menu_name_delete->Text = L"Удалить";
			this->_menu_name_delete->Click += gcnew System::EventHandler(this, &_main::_menu_name_delete_Click);
			// 
			// _menu_name_save
			// 
			this->_menu_name_save->Name = L"_menu_name_save";
			this->_menu_name_save->Size = System::Drawing::Size(140, 22);
			this->_menu_name_save->Text = L"Сохранить";
			this->_menu_name_save->Click += gcnew System::EventHandler(this, &_main::_menu_name_save_Click);
			// 
			// _name_add
			// 
			this->_name_add->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_name_add->Location = System::Drawing::Point(6, 238);
			this->_name_add->Name = L"_name_add";
			this->_name_add->Size = System::Drawing::Size(76, 25);
			this->_name_add->TabIndex = 2;
			this->_name_add->Text = L"Добавить";
			this->_name_add->UseVisualStyleBackColor = true;
			this->_name_add->Click += gcnew System::EventHandler(this, &_main::_name_add_Click);
			// 
			// _name_remove
			// 
			this->_name_remove->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_name_remove->Location = System::Drawing::Point(89, 238);
			this->_name_remove->Name = L"_name_remove";
			this->_name_remove->Size = System::Drawing::Size(76, 25);
			this->_name_remove->TabIndex = 3;
			this->_name_remove->Text = L"Удалить";
			this->_name_remove->UseVisualStyleBackColor = true;
			this->_name_remove->Click += gcnew System::EventHandler(this, &_main::_name_remove_Click);
			// 
			// _ip
			// 
			this->_ip->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->_ip->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_ip->ForeColor = System::Drawing::Color::Blue;
			this->_ip->Location = System::Drawing::Point(6, 42);
			this->_ip->Name = L"_ip";
			this->_ip->Size = System::Drawing::Size(159, 23);
			this->_ip->TabIndex = 4;
			this->_ip->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// _name_autosave
			// 
			this->_name_autosave->Checked = true;
			this->_name_autosave->CheckState = System::Windows::Forms::CheckState::Checked;
			this->_name_autosave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_name_autosave->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_name_autosave->Location = System::Drawing::Point(6, 19);
			this->_name_autosave->Name = L"_name_autosave";
			this->_name_autosave->Size = System::Drawing::Size(159, 20);
			this->_name_autosave->TabIndex = 5;
			this->_name_autosave->Text = L"Автосохранение";
			this->_name_autosave->UseVisualStyleBackColor = true;
			// 
			// _address
			// 
			this->_address->Controls->Add(this->_name_autosave);
			this->_address->Controls->Add(this->_ip);
			this->_address->Controls->Add(this->_name);
			this->_address->Controls->Add(this->_name_remove);
			this->_address->Controls->Add(this->_name_add);
			this->_address->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->_address->Location = System::Drawing::Point(12, 27);
			this->_address->Name = L"_address";
			this->_address->Size = System::Drawing::Size(171, 269);
			this->_address->TabIndex = 6;
			this->_address->TabStop = false;
			this->_address->Text = L"Контакты";
			// 
			// _generate_key
			// 
			this->_generate_key->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_generate_key->Location = System::Drawing::Point(12, 364);
			this->_generate_key->Name = L"_generate_key";
			this->_generate_key->Size = System::Drawing::Size(171, 29);
			this->_generate_key->TabIndex = 7;
			this->_generate_key->Text = L"Подобрать ключ";
			this->_generate_key->UseVisualStyleBackColor = true;
			this->_generate_key->Click += gcnew System::EventHandler(this, &_main::_generate_key_Click);
			// 
			// _send
			// 
			this->_send->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_send->Location = System::Drawing::Point(189, 316);
			this->_send->Name = L"_send";
			this->_send->Size = System::Drawing::Size(180, 29);
			this->_send->TabIndex = 10;
			this->_send->Text = L"Отправить";
			this->_send->UseVisualStyleBackColor = true;
			this->_send->Click += gcnew System::EventHandler(this, &_main::_send_Click);
			// 
			// _text_encode
			// 
			this->_text_encode->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_text_encode->Location = System::Drawing::Point(189, 349);
			this->_text_encode->MaxLength = 16777216;
			this->_text_encode->Multiline = true;
			this->_text_encode->Name = L"_text_encode";
			this->_text_encode->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->_text_encode->Size = System::Drawing::Size(552, 134);
			this->_text_encode->TabIndex = 14;
			this->_text_encode->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &_main::_text_encode_KeyDown);
			// 
			// _connect
			// 
			this->_connect->Enabled = false;
			this->_connect->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_connect->ForeColor = System::Drawing::Color::Red;
			this->_connect->Location = System::Drawing::Point(12, 296);
			this->_connect->Name = L"_connect";
			this->_connect->Size = System::Drawing::Size(171, 29);
			this->_connect->TabIndex = 17;
			this->_connect->Text = L"Соединиться";
			this->_connect->UseVisualStyleBackColor = true;
			this->_connect->Click += gcnew System::EventHandler(this, &_main::_connect_Click);
			// 
			// _disconnect
			// 
			this->_disconnect->Enabled = false;
			this->_disconnect->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_disconnect->ForeColor = System::Drawing::Color::Red;
			this->_disconnect->Location = System::Drawing::Point(12, 329);
			this->_disconnect->Name = L"_disconnect";
			this->_disconnect->Size = System::Drawing::Size(171, 29);
			this->_disconnect->TabIndex = 18;
			this->_disconnect->Text = L"Разъединиться";
			this->_disconnect->UseVisualStyleBackColor = true;
			this->_disconnect->Click += gcnew System::EventHandler(this, &_main::_disconnect_Click);
			// 
			// _server
			// 
			this->_server->WorkerReportsProgress = true;
			this->_server->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &_main::_server_DoWork);
			// 
			// _show_ip_connected
			// 
			this->_show_ip_connected->Enabled = true;
			this->_show_ip_connected->Interval = 333;
			this->_show_ip_connected->Tick += gcnew System::EventHandler(this, &_main::_show_ip_connected_Tick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(375, 316);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(180, 29);
			this->button1->TabIndex = 19;
			this->button1->Tag = L"";
			this->button1->Text = L"Закодировать и отправить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &_main::button1_Click);
			// 
			// _message
			// 
			this->_message->Location = System::Drawing::Point(189, 27);
			this->_message->Name = L"_message";
			this->_message->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
			this->_message->Size = System::Drawing::Size(552, 283);
			this->_message->TabIndex = 20;
			this->_message->Text = L"";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(561, 316);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(180, 29);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Декодировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &_main::button2_Click);
			// 
			// _menu
			// 
			this->_menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->_menu_help, this->_menu_about});
			this->_menu->Location = System::Drawing::Point(0, 0);
			this->_menu->Name = L"_menu";
			this->_menu->Size = System::Drawing::Size(750, 24);
			this->_menu->TabIndex = 22;
			// 
			// _menu_help
			// 
			this->_menu_help->Name = L"_menu_help";
			this->_menu_help->ShortcutKeyDisplayString = L"";
			this->_menu_help->Size = System::Drawing::Size(82, 20);
			this->_menu_help->Text = L"Помощь (F1)";
			this->_menu_help->Click += gcnew System::EventHandler(this, &_main::_menu_help_Click);
			// 
			// _menu_about
			// 
			this->_menu_about->Name = L"_menu_about";
			this->_menu_about->Size = System::Drawing::Size(84, 20);
			this->_menu_about->Text = L"О Программе";
			this->_menu_about->Click += gcnew System::EventHandler(this, &_main::_menu_about_Click);
			// 
			// _main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(750, 493);
			this->Controls->Add(this->_menu);
			this->Controls->Add(this->_text_encode);
			this->Controls->Add(this->_disconnect);
			this->Controls->Add(this->_connect);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->_address);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->_send);
			this->Controls->Add(this->_message);
			this->Controls->Add(this->_generate_key);
			this->MainMenuStrip = this->_menu;
			this->MaximizeBox = false;
			this->Name = L"_main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Chat";
			this->Load += gcnew System::EventHandler(this, &_main::_main_Load);
			this->HelpRequested += gcnew System::Windows::Forms::HelpEventHandler(this, &_main::Form1_HelpR);
			this->_menu_name->ResumeLayout(false);
			this->_address->ResumeLayout(false);
			this->_menu->ResumeLayout(false);
			this->_menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//преобразуем IP в имена согласно контакт-листу
		//если IP=127.0.0.1 то Я
		//если такой IP есть в контакт-листе, возвращаем соответствующее имя
		//если такого IP нет, возвращяем Anonymous(IP)
	private:
		System::String^ ResolveIP(System::String^ IP)
		{
			if(IP=="127.0.0.1")
			{
				return "Я";
			}
			for(int i1=0;i1<_name->Items->Count;i1++)
			{
				if(dynamic_cast<iPerson^>(_name->Items[i1])->IP==IP)
				{
					return dynamic_cast<iPerson^>(_name->Items[i1])->NAME;
				}
			}
			return "Аnonymous ("+IP+")";
		}
		//отправить байты data по IP через порт PORT
		void SendBytes(System::String^ IP,array<Byte>^ data)
		{
			try
			{
				TcpClient^ client=gcnew TcpClient(IP,PORT);
				client->Client->Send(data);
				client->Close();
			}
			catch(System::Exception^ error) 
			{
				System::Windows::Forms::MessageBox::Show(error->Message,"ERROR of SendBytes(IP,data)");
				IP_CONNECTED="";
			}
		}
		//сохранить контакт-лист на HDD
		void SavePersons(String^ FileName)
		{
			array<String^>^ s1=gcnew array<String^>(_name->Items->Count*2);
			for(int i1=0;i1<_name->Items->Count;i1++)
			{
				s1[2*i1]=dynamic_cast<iPerson^>(_name->Items[i1])->NAME;
				s1[2*i1+1]=dynamic_cast<iPerson^>(_name->Items[i1])->IP;
			}
			try
			{
				IO::File::WriteAllLines(Application::StartupPath+"\\"+FileName,s1);
			}
			catch(System::Exception^ err)
			{
				MessageBox::Show(err->Message,"Ошибка записи в файл",MessageBoxButtons::OK,MessageBoxIcon::Warning);
				return;
			};
		}
		//загрузить сохраненный контакт-лист с HDD
		void LoadPersons(String^ FileName)
		{
			array<String^>^ s1;
			try
			{
				s1=IO::File::ReadAllLines(Application::StartupPath+"\\"+FileName);
			}
			catch(...)
			{
				return;
			};
			for(int i1=0;i1<s1->Length;i1+=2)
			{
				if(s1[i1]==String::Empty || s1[i1+1]==String::Empty)
				{
					break;
				}
				_name->Items->Add(gcnew iPerson(s1[i1],s1[i1+1]));
			}
		}
		//преобразовать строку в байтовый массив (Serialize)
		array<Byte>^ StringToByte(String^ str)
		{
			array<Byte>^ byte=gcnew array<Byte>(str->Length*2);
			for(int i1=0;i1<str->Length;++i1)
			{
				byte[2*i1]=str[i1]/256;
				byte[2*i1+1]=str[i1]%256;
			}
			return byte;
		}
		//преобразовать байтовый массив в строку (Deserialize)
		String^ ByteToString(array<Byte>^ byte)
		{
			String^ str="";
			for(int i1=0;i1<byte->Length;i1+=2)
			{
				str+=static_cast<wchar_t>(byte[i1]*256+byte[i1+1]);
			}
			return str;
		}
		//прослушивание порта PORT на этом компьютере
		//при приеме какой-либо информации обработать ее в функции Action
		void GetMessage()
		{
			TcpListener^ server=gcnew TcpListener(IPAddress::Any,PORT);
			server->Start();
			array<Byte>^bytes;
			while(true)
			{
				try
				{
					//ждать соединения
					TcpClient^ client = server->AcceptTcpClient();
					NetworkStream^ stream=client->GetStream();
					bytes=gcnew array<Byte>(65536);
					stream->Read(bytes,0,bytes->Length);
					Action(client->Client->RemoteEndPoint->ToString()->Substring(0,client->Client->RemoteEndPoint->ToString()->IndexOf(":")),bytes);
					client->Close();
				}
				catch(System::Exception^ error) 
				{
					System::Windows::Forms::MessageBox::Show(error->Message,"ERROR of GetMessage(void)");
				}
			}
		}
		//отправить компьютеру IP RSA ключи E и N=P*Q
		//формат:
		//6 - 1 байт (для идентификации типа приходящей информации)
		//длина открытой экспоненты E - 1 байт
		//открытая экспонента E - 1...255 байт
		//длина модуля N - 1 байт
		//модуль N - 1...255 байт
		void SendKeysEN(String^ IP)
		{
			//MessageBox::Show(MyKey->E.ToString(),"E");
			//MessageBox::Show(MyKey->N.ToString(),"N");
			array<Byte>^ data=gcnew array<Byte>(1+1+MyKey->E.N+1+MyKey->N.N);
			data[0]=6;
			//
			data[1]=MyKey->E.N;
			for(int i1=0;i1<MyKey->E.N;++i1)
			{
				data[1+1+i1]=MyKey->E.VALUE[i1];
			}
			//
			data[1+1+MyKey->E.N]=MyKey->N.N;
			for(int i1=0;i1<MyKey->N.N;++i1)
			{
				data[i1+1+1+MyKey->E.N+1]=MyKey->N.VALUE[i1];
			}
			SendBytes(IP,data);
		}
		//типы сообщений (первый байт):
		//0 - запрос на соединение
		//1 - разрыв соединения
		//2 - соединение установлено (в ответ на 0)
		//3 - соединение разорвано (в ответ на 0)
		//4 - сообщение
		//5 - закодированное сообщение
		//6 - RSA ключи E и N=P*Q
		void Action(String^ IP,array<Byte>^ data)
		{
			switch(data[0])
			{
			case 0:
				if(IP_CONNECTED=="")
				{
					if(MessageBox::Show("Разрешить соединение c "+ResolveIP(IP)+"?","",MessageBoxButtons::YesNo)==System::Windows::Forms::DialogResult::Yes)
					{
						SendBytes(IP,gcnew array<Byte>{2});
						IP_CONNECTED=IP;
						SendKeysEN(IP);
					}
					else
					{
						SendBytes(IP,gcnew array<Byte>{3});
					}
				}
				break;
			case 1:
				if(IP_CONNECTED!="")
				{
					MessageBox::Show("Разорвано соединение с "+ResolveIP(IP));
					IP_CONNECTED="";
				}
				break;
			case 2:
				if(IP_CONNECTED=="")
				{
					MessageBox::Show("Установлено соединение с "+ResolveIP(IP));
					IP_CONNECTED=IP;
					SendKeysEN(IP);
				}
				break;
			case 3:
				if(IP_CONNECTED=="")
				{
					MessageBox::Show("Отказано в запросе на соединение с "+ResolveIP(IP));
				}
				break;
			case 4:
				if(IP_CONNECTED==IP)
				{
					int length=((int)data[1])*256+data[2];
					String^ str=System::Text::Encoding::UTF8->GetString(data,3,length+3);
					//MessageBox::Show("Получано сообщение от "+ResolveIP(IP)+": "+str);
					AddMessage(IP,str,Color::DarkBlue);
				}
				break;
			case 5:
				if(IP_CONNECTED==IP)
				{
					int length=((int)data[1])*256+data[2];
					String^ str=System::Text::Encoding::UTF8->GetString(data,3,length+3);
					//String^ str2=MyKey->DecryptAllText(str);
					//MessageBox::Show("Получано зашифрованное сообщение от "+ResolveIP(IP)+": "+str2);
					AddMessage(IP,str,Color::DarkBlue);
				}
				break;
			case 6:
				if(IP_CONNECTED==IP)
				{
					//MessageBox::Show("Получены RSA ключи от "+ResolveIP(IP));
					delete YourKey;
					YourKey=new i::iRSA;
					YourKey->E.Create((int)data[1]);
					for(int i1=0;i1<YourKey->E.N;++i1)
					{
						YourKey->E.VALUE[i1]=data[1+1+i1];
					}
					YourKey->E.Verify();
					YourKey->N.Create((int)data[1+1+YourKey->E.N]);
					for(int i1=0;i1<YourKey->N.N;++i1)
					{
						YourKey->N.VALUE[i1]=data[1+1+YourKey->E.N+1+i1];
					}
					YourKey->N.Verify();
					//MessageBox::Show(YourKey->E.ToString(),"Get E");
					//MessageBox::Show(YourKey->N.ToString(),"Get N");
				}
				break;
			default:
				System::Windows::Forms::MessageBox::Show("ERROR"+__LINE__);
			}
		}
		//добавить сообщение на главное окно (окно чата)
		void AddMessage(System::String^ IP,String^ Message,Color color)
		{
			//потокобезопасный вызов функции (если необходимо)
			if(this->_message->InvokeRequired)
			{	
				SetTextCallback^ d = gcnew SetTextCallback(this,&_main::AddMessage);
				array<Object^>^ arr=gcnew array<Object^>{IP,Message,color};
				this->Invoke(d,arr);
			}
			else
			{
				//String^ str=ResolveIP(IP)+System::Environment::NewLine+Message+System::Environment::NewLine+System::Environment::NewLine;
				//_message->Text+=str;
				int i1=_message->Text->Length;
				_message->AppendText(ResolveIP(IP));
				_message->AppendText(System::Environment::NewLine);
				_message->AppendText(Message);
				_message->AppendText(System::Environment::NewLine);
				_message->AppendText(System::Environment::NewLine);
				//прокручивание в конец TextBox'а
				_message->SelectionStart=i1;
				_message->SelectionLength=_message->Text->Length;
				_message->SelectionColor=color;
				//MessageBox::Show(_message->SelectionStart.ToString());
				//MessageBox::Show(_message->SelectionLength.ToString());
				//_message->ScrollToCaret();
			}
		}
		//загрузка формы
		System::Void _main_Load(System::Object^  sender, System::EventArgs^  e) {
			LoadPersons("persons.txt");
			_server->RunWorkerAsync();
		}
		//добавление контакта в контакт-лист
		System::Void _name_add_Click(System::Object^  sender, System::EventArgs^  e) {
			_person_add ^Form=gcnew _person_add;
			Form->ShowDialog(this);
			if(Form->Person!=nullptr)
			{
				_name->Items->Add(Form->Person);
				if(_name_autosave->Checked)
				{
					SavePersons("persons.txt");
				}
			}
			delete Form;
		}
		//удаление контакта из контакт-листа
		System::Void _name_remove_Click(System::Object^  sender, System::EventArgs^  e) {
			if(_name->SelectedIndex>=0)
			{
				_name->Items->RemoveAt(_name->SelectedIndex);
			}
			_ip->Text=String::Empty;
			if(_name_autosave->Checked)
			{
				SavePersons("persons.txt");
			}
		}
		//выделение контакта в контакт-листе
		System::Void _name_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(_name->SelectedIndex>=0)
			{
				_ip->Text=dynamic_cast<iPerson^>(_name->Items[_name->SelectedIndex])->IP;
			}
		}
		//добавление контакта в контакт-лист (контекстная строка)
		System::Void _menu_name_add_Click(System::Object^  sender, System::EventArgs^  e) {
			_name_add_Click(nullptr,nullptr);
		}
		//удаление контакта из контакт-листа (контекстная строка)
		System::Void _menu_name_delete_Click(System::Object^  sender, System::EventArgs^  e) {
			_name_remove_Click(nullptr,nullptr);
		}
		//сохранение контакт-листа
		System::Void _menu_name_save_Click(System::Object^  sender, System::EventArgs^  e) {
			SavePersons("persons.txt");
		}
		//генерация ключей
		System::Void _generate_key_Click(System::Object^  sender, System::EventArgs^  e) {
			_key_generate^ Form=gcnew _key_generate;
			Form->ShowDialog(this);
			if(Form->RSAExternal!=nullptr)
			{
				MyKey=Form->RSAExternal;
				_generate_key->Enabled=false;
			}
			if(MyKey!=nullptr)
			{
				_connect->Enabled=true;
				_disconnect->Enabled=true;
			}
			delete Form;
		}
		//отправить сообщение
		System::Void _send_Click(System::Object^  sender, System::EventArgs^  e) {
			if(IP_CONNECTED!="")
			{
				array<Byte>^ data_enc=System::Text::Encoding::UTF8->GetBytes(_text_encode->Text);
				array<Byte>^ data=gcnew array<Byte>(1+2+data_enc->Length);
				data[0]=4;
				data[1]=data_enc->Length/256;
				data[2]=data_enc->Length%256;
				Array::Copy(data_enc,0,data,3,data_enc->Length);
				SendBytes(IP_CONNECTED,data);
				AddMessage("127.0.0.1",_text_encode->Text,Color::DarkRed);
				_text_encode->Text="";
			}
		}
		//соединиться
		System::Void _connect_Click(System::Object^  sender, System::EventArgs^  e) {
			if(_name->SelectedIndex>=0 && IP_CONNECTED=="")
			{
				SendBytes(dynamic_cast<iPerson^>(_name->Items[_name->SelectedIndex])->IP,gcnew array<Byte>{0});
			}
		}
		//разъединиться
		System::Void _disconnect_Click(System::Object^  sender, System::EventArgs^  e) {
			if(IP_CONNECTED!="")
			{
				SendBytes(IP_CONNECTED,gcnew array<Byte>{1});
				IP_CONNECTED="";
				_message->Text="";
			}
		}	 
		//второй поток (прослушивание порта PORT)
		System::Void _server_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			GetMessage();
		}
		//отображение состояния соединения в заголовке формы
		System::Void _show_ip_connected_Tick(System::Object^  sender, System::EventArgs^  e) {
			this->Text="Chat";
			if(IP_CONNECTED!="")
			{
				this->Text+=" - Connected: "+IP_CONNECTED;
			}
			if(_text_encode->Enabled==false)
			{
				_text_encode->Enabled=true;
				_text_encode->Text="";
				_text_encode->Focus();
			}
		}
		//нажатие кнопки закодировать и отправить
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ str;
			if(YourKey==nullptr || YourKey->E.Empty()||YourKey->N.Empty())
			{
				MessageBox::Show("Не получены ключи","ERROR",MessageBoxButtons::OK,MessageBoxIcon::Error);
				return;
			}
			else
			{
				str=YourKey->EncryptAllText(_text_encode->Text);
			}
			if(IP_CONNECTED!="")
			{
				array<Byte>^ data_enc=System::Text::Encoding::UTF8->GetBytes(str);
				array<Byte>^ data=gcnew array<Byte>(1+2+data_enc->Length);
				data[0]=5;
				data[1]=data_enc->Length/256;
				data[2]=data_enc->Length%256;
				Array::Copy(data_enc,0,data,3,data_enc->Length);
				SendBytes(IP_CONNECTED,data);
				AddMessage("127.0.0.1",str+" // "+_text_encode->Text+" //",Color::DarkRed);
				_text_encode->Text="";
			}
		}
		//отправка сообщений по нажатию клавиш Enter или Ctrl + Enter
		System::Void _text_encode_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if(e->KeyCode==Keys::Enter)
			{
				if(e->Control==true)
				{
					button1_Click(nullptr,nullptr);
					_text_encode->Enabled=false;
				}
				else
				{
					_send_Click(nullptr,nullptr);
					_text_encode->Enabled=false;
				}
			}
		}
		//расшифровка выделенного текста
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show(MyKey->DecryptAllText(_message->SelectedText),"Расшифрованный текст");
		}
		//открытие файла помощи
		System::Void Form1_HelpR(System::Object^  sender, System::Windows::Forms::HelpEventArgs^  hlpevent) {
			if(IO::File::Exists(Application::StartupPath+"\\"+HELPFILE))
			{
				System::Diagnostics::Process::Start(Application::StartupPath+"\\"+HELPFILE);
			}
		}
		//открытие файла помощи
		System::Void _menu_help_Click(System::Object^  sender, System::EventArgs^  e) {
			Form1_HelpR(nullptr,nullptr);
		}
		System::Void _menu_about_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::MessageBox::Show("Здесь могла бы быть ваша реклама ;)","О программе",MessageBoxButtons::OK,MessageBoxIcon::Information);
		}
	};
}