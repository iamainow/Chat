#pragma once
//форма генерации ключей RSA
#include "iRSA.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
namespace Chat
{
	public ref class _key_generate : public System::Windows::Forms::Form
	{
	public:
		//внешний RSA
		i::iRSA *RSAExternal;
	private:
		//внутренний RSA
		i::iRSA *RSAInside;
	private:
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::NumericUpDown^  _round;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::NumericUpDown^  numericUpDown2;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::NumericUpDown^  _digit;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Button^  _generate;
		System::Windows::Forms::Label^  _p;
		System::Windows::Forms::Label^  _q;
		System::Windows::Forms::Label^  _modulus;
		System::Windows::Forms::Label^  __p;
		System::Windows::Forms::Label^  __q;
		System::Windows::Forms::Label^  __modulus;
		System::Windows::Forms::Label^  __exp_private;
		System::Windows::Forms::Label^  __exp_public;
		System::Windows::Forms::Label^  _exp_private;
		System::Windows::Forms::Label^  _exp_public;
		System::Windows::Forms::Button^  _accept;
		System::Windows::Forms::Button^  _cancel;
		System::Windows::Forms::Button^  _question;
	private: System::Windows::Forms::Label^  label5;
			 System::ComponentModel::IContainer^  components;
	public:
		_key_generate(void)
		{
			RSAExternal=nullptr;
			RSAInside=nullptr;
			InitializeComponent();
		}
	protected:
		~_key_generate()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->_generate = (gcnew System::Windows::Forms::Button());
			this->_p = (gcnew System::Windows::Forms::Label());
			this->_q = (gcnew System::Windows::Forms::Label());
			this->_modulus = (gcnew System::Windows::Forms::Label());
			this->__p = (gcnew System::Windows::Forms::Label());
			this->__q = (gcnew System::Windows::Forms::Label());
			this->__modulus = (gcnew System::Windows::Forms::Label());
			this->__exp_private = (gcnew System::Windows::Forms::Label());
			this->__exp_public = (gcnew System::Windows::Forms::Label());
			this->_exp_private = (gcnew System::Windows::Forms::Label());
			this->_exp_public = (gcnew System::Windows::Forms::Label());
			this->_accept = (gcnew System::Windows::Forms::Button());
			this->_cancel = (gcnew System::Windows::Forms::Button());
			this->_question = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->_round = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->_digit = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->_round))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->_digit))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(220, 21);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Количество цифр:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// _generate
			// 
			this->_generate->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_generate->Location = System::Drawing::Point(259, 343);
			this->_generate->Name = L"_generate";
			this->_generate->Size = System::Drawing::Size(123, 24);
			this->_generate->TabIndex = 0;
			this->_generate->Text = L"Подобрать";
			this->_generate->UseVisualStyleBackColor = true;
			this->_generate->Click += gcnew System::EventHandler(this, &_key_generate::_generate_Click);
			// 
			// _p
			// 
			this->_p->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->_p->Location = System::Drawing::Point(197, 87);
			this->_p->Name = L"_p";
			this->_p->Size = System::Drawing::Size(442, 40);
			this->_p->TabIndex = 4;
			// 
			// _q
			// 
			this->_q->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->_q->Location = System::Drawing::Point(197, 127);
			this->_q->Name = L"_q";
			this->_q->Size = System::Drawing::Size(442, 40);
			this->_q->TabIndex = 5;
			// 
			// _modulus
			// 
			this->_modulus->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->_modulus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_modulus->Location = System::Drawing::Point(197, 167);
			this->_modulus->Name = L"_modulus";
			this->_modulus->Size = System::Drawing::Size(442, 60);
			this->_modulus->TabIndex = 6;
			// 
			// __p
			// 
			this->__p->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->__p->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->__p->Location = System::Drawing::Point(10, 87);
			this->__p->Name = L"__p";
			this->__p->Size = System::Drawing::Size(181, 40);
			this->__p->TabIndex = 7;
			this->__p->Text = L"p=";
			this->__p->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// __q
			// 
			this->__q->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->__q->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->__q->Location = System::Drawing::Point(10, 127);
			this->__q->Name = L"__q";
			this->__q->Size = System::Drawing::Size(181, 40);
			this->__q->TabIndex = 8;
			this->__q->Text = L"q=";
			this->__q->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// __modulus
			// 
			this->__modulus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->__modulus->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->__modulus->Location = System::Drawing::Point(10, 167);
			this->__modulus->Name = L"__modulus";
			this->__modulus->Size = System::Drawing::Size(181, 53);
			this->__modulus->TabIndex = 9;
			this->__modulus->Text = L"Модуль (n)=";
			this->__modulus->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// __exp_private
			// 
			this->__exp_private->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->__exp_private->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->__exp_private->Location = System::Drawing::Point(10, 280);
			this->__exp_private->Name = L"__exp_private";
			this->__exp_private->Size = System::Drawing::Size(181, 60);
			this->__exp_private->TabIndex = 14;
			this->__exp_private->Text = L"Закрытая экспонента (d)=";
			this->__exp_private->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// __exp_public
			// 
			this->__exp_public->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->__exp_public->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->__exp_public->Location = System::Drawing::Point(10, 220);
			this->__exp_public->Name = L"__exp_public";
			this->__exp_public->Size = System::Drawing::Size(181, 60);
			this->__exp_public->TabIndex = 13;
			this->__exp_public->Text = L"Открытая экспонента (e)=";
			this->__exp_public->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// _exp_private
			// 
			this->_exp_private->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->_exp_private->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_exp_private->Location = System::Drawing::Point(197, 280);
			this->_exp_private->Name = L"_exp_private";
			this->_exp_private->Size = System::Drawing::Size(442, 60);
			this->_exp_private->TabIndex = 11;
			// 
			// _exp_public
			// 
			this->_exp_public->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->_exp_public->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_exp_public->Location = System::Drawing::Point(197, 220);
			this->_exp_public->Name = L"_exp_public";
			this->_exp_public->Size = System::Drawing::Size(442, 60);
			this->_exp_public->TabIndex = 10;
			// 
			// _accept
			// 
			this->_accept->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_accept->Location = System::Drawing::Point(388, 343);
			this->_accept->Name = L"_accept";
			this->_accept->Size = System::Drawing::Size(123, 24);
			this->_accept->TabIndex = 1;
			this->_accept->Text = L"Принять";
			this->_accept->UseVisualStyleBackColor = true;
			this->_accept->Click += gcnew System::EventHandler(this, &_key_generate::_accept_Click);
			// 
			// _cancel
			// 
			this->_cancel->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_cancel->Location = System::Drawing::Point(517, 343);
			this->_cancel->Name = L"_cancel";
			this->_cancel->Size = System::Drawing::Size(123, 24);
			this->_cancel->TabIndex = 2;
			this->_cancel->Text = L"Отмена";
			this->_cancel->UseVisualStyleBackColor = true;
			this->_cancel->Click += gcnew System::EventHandler(this, &_key_generate::_cancel_Click);
			// 
			// _question
			// 
			this->_question->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_question->Location = System::Drawing::Point(229, 343);
			this->_question->Name = L"_question";
			this->_question->Size = System::Drawing::Size(24, 24);
			this->_question->TabIndex = 6;
			this->_question->Text = L"\?";
			this->_question->UseVisualStyleBackColor = true;
			this->_question->Click += gcnew System::EventHandler(this, &_key_generate::_question_Click);
			// 
			// label2
			// 
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(220, 21);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Количество сведетелей простоты:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// _round
			// 
			this->_round->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_round->Location = System::Drawing::Point(238, 36);
			this->_round->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->_round->Name = L"_round";
			this->_round->Size = System::Drawing::Size(86, 21);
			this->_round->TabIndex = 4;
			this->_round->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->_round->ValueChanged += gcnew System::EventHandler(this, &_key_generate::_round_ValueChanged);
			// 
			// label3
			// 
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(220, 21);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Проверять на простоту до:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->numericUpDown2->Location = System::Drawing::Point(238, 63);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65536, 0, 0, 0});
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(86, 21);
			this->numericUpDown2->TabIndex = 5;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1024, 0, 0, 0});
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &_key_generate::numericUpDown2_ValueChanged);
			// 
			// label4
			// 
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(330, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(309, 35);
			this->label4->TabIndex = 22;
			// 
			// _digit
			// 
			this->_digit->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_digit->Location = System::Drawing::Point(238, 9);
			this->_digit->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {152, 0, 0, 0});
			this->_digit->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {7, 0, 0, 0});
			this->_digit->Name = L"_digit";
			this->_digit->Size = System::Drawing::Size(86, 21);
			this->_digit->TabIndex = 23;
			this->_digit->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {150, 0, 0, 0});
			// 
			// label5
			// 
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(330, 49);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(309, 35);
			this->label5->TabIndex = 24;
			// 
			// _key_generate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(651, 379);
			this->ControlBox = false;
			this->Controls->Add(this->label5);
			this->Controls->Add(this->_digit);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->_round);
			this->Controls->Add(this->_question);
			this->Controls->Add(this->_cancel);
			this->Controls->Add(this->__modulus);
			this->Controls->Add(this->__q);
			this->Controls->Add(this->__exp_private);
			this->Controls->Add(this->_exp_private);
			this->Controls->Add(this->__exp_public);
			this->Controls->Add(this->_accept);
			this->Controls->Add(this->_exp_public);
			this->Controls->Add(this->__p);
			this->Controls->Add(this->_modulus);
			this->Controls->Add(this->_q);
			this->Controls->Add(this->_p);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->_generate);
			this->Name = L"_key_generate";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Generate Key";
			this->Load += gcnew System::EventHandler(this, &_key_generate::_key_generate_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->_round))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->_digit))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		//загрузка формы
		System::Void _key_generate_Load(System::Object^  sender, System::EventArgs^  e) {
			_round_ValueChanged(nullptr,nullptr);
			numericUpDown2_ValueChanged(nullptr,nullptr);
		}
		//отмена
		System::Void _cancel_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}
		//нажата кнопка "?"
		System::Void _question_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show("пара чисел (n,e) образуют открытый ключ, а"+System::Environment::NewLine+"пара (n,d) - закрытый",String::Empty,MessageBoxButtons::OK,MessageBoxIcon::Information);
		}
		//генерация
	public:
		System::Void _generate_Click(System::Object^  sender, System::EventArgs^  e)
		{
			//очищаем поля
			_p->Text="";
			_q->Text="";
			_modulus->Text="";
			_exp_public->Text="";
			_exp_private->Text="";
			Application::DoEvents();
			//генерация
			i::iRSA RSA;
			RSA.GeneratePrimeNumbers(static_cast<int>(Math::Round(((double)_digit->Value*0.41524+0.29)/2)),(int)_round->Value,(int)numericUpDown2->Value);
			RSA.GenerateEDKey(gcnew Random());
			delete RSAInside;
			RSAInside=new i::iRSA;
			*RSAInside=RSA;
			//заполняем поля
			_p->Text=RSAInside->P.To10String();
			_q->Text=RSAInside->Q.To10String();
			_modulus->Text=RSAInside->N.To10String();
			_exp_public->Text=RSAInside->E.To10String();
			_exp_private->Text=RSAInside->D.To10String();
		}
		//примять
		System::Void _accept_Click(System::Object^  sender, System::EventArgs^  e) {
			RSAExternal=RSAInside;
			this->Close();
		}
		//изменено кол-во свидетелей простоты
		System::Void _round_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			label4->Text="P < "+Math::Pow(0.25,(double)_round->Value).ToString()+"\r\nВероятность что число составное";
		}
	private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 label5->Text="Число проверяется на делимость на числа\r\nот 2 до "+numericUpDown2->Value;
			 }
	};
}