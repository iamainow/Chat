#pragma once
//'function': signature of non-private member contains assembly private type 'private_type'
#pragma warning(disable:4677)
#include "iPerson.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
namespace Chat
{
	public ref class _person_add : public System::Windows::Forms::Form
	{
	public:
		iPerson^ Person;
	public:
		_person_add(void)
		{
			InitializeComponent();
			Person=nullptr;
		}
	protected:
		~_person_add()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::TextBox^  _person_ip;
		System::Windows::Forms::TextBox^  _person_name;
		System::Windows::Forms::Label^  __name;
		System::Windows::Forms::Label^  __ip;
		System::Windows::Forms::Button^  _accept;
		System::Windows::Forms::Button^  _cancel;
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->_person_ip = (gcnew System::Windows::Forms::TextBox());
			this->_person_name = (gcnew System::Windows::Forms::TextBox());
			this->__name = (gcnew System::Windows::Forms::Label());
			this->__ip = (gcnew System::Windows::Forms::Label());
			this->_accept = (gcnew System::Windows::Forms::Button());
			this->_cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// _person_ip
			// 
			this->_person_ip->Location = System::Drawing::Point(64, 35);
			this->_person_ip->MaxLength = 15;
			this->_person_ip->Name = L"_person_ip";
			this->_person_ip->Size = System::Drawing::Size(142, 20);
			this->_person_ip->TabIndex = 1;
			// 
			// _person_name
			// 
			this->_person_name->Location = System::Drawing::Point(64, 9);
			this->_person_name->MaxLength = 24;
			this->_person_name->Name = L"_person_name";
			this->_person_name->Size = System::Drawing::Size(142, 20);
			this->_person_name->TabIndex = 0;
			// 
			// __name
			// 
			this->__name->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->__name->Location = System::Drawing::Point(12, 9);
			this->__name->Name = L"__name";
			this->__name->Size = System::Drawing::Size(46, 20);
			this->__name->TabIndex = 2;
			this->__name->Text = L"Имя:";
			this->__name->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// __ip
			// 
			this->__ip->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->__ip->Location = System::Drawing::Point(12, 35);
			this->__ip->Name = L"__ip";
			this->__ip->Size = System::Drawing::Size(46, 20);
			this->__ip->TabIndex = 3;
			this->__ip->Text = L"IP:";
			this->__ip->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// _accept
			// 
			this->_accept->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_accept->Location = System::Drawing::Point(12, 61);
			this->_accept->Name = L"_accept";
			this->_accept->Size = System::Drawing::Size(94, 24);
			this->_accept->TabIndex = 4;
			this->_accept->Text = L"Принять";
			this->_accept->UseVisualStyleBackColor = true;
			this->_accept->Click += gcnew System::EventHandler(this, &_person_add::_accept_Click);
			// 
			// _cancel
			// 
			this->_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->_cancel->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->_cancel->Location = System::Drawing::Point(112, 61);
			this->_cancel->Name = L"_cancel";
			this->_cancel->Size = System::Drawing::Size(94, 24);
			this->_cancel->TabIndex = 5;
			this->_cancel->Text = L"Отменить";
			this->_cancel->UseVisualStyleBackColor = true;
			this->_cancel->Click += gcnew System::EventHandler(this, &_person_add::_cancel_Click);
			// 
			// _person_add
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(218, 96);
			this->ControlBox = false;
			this->Controls->Add(this->_cancel);
			this->Controls->Add(this->_accept);
			this->Controls->Add(this->__ip);
			this->Controls->Add(this->__name);
			this->Controls->Add(this->_person_name);
			this->Controls->Add(this->_person_ip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"_person_add";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавить контакт";
			this->Load += gcnew System::EventHandler(this, &_person_add::_person_add_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:
		System::Void _accept_Click(System::Object^  sender, System::EventArgs^  e) {
			if(_person_name->Text!=String::Empty && _person_ip->Text!=String::Empty)
			{
				Person=gcnew iPerson(_person_name->Text,_person_ip->Text);
			}
			else
			{
				Person=nullptr;
			}
			this->Close();
		}
		System::Void _cancel_Click(System::Object^  sender, System::EventArgs^  e) {
			Person=nullptr;
			this->Close();
		}
	private: System::Void _person_add_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}