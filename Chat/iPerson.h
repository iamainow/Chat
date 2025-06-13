#pragma once
//класс записей в контакт-листе
ref class iPerson
{
public:
	System::String^ NAME;
	System::String^ IP;
	iPerson(){};
	iPerson(System::String^ Name,System::String^ Ip)
	{
		this->NAME=Name;
		this->IP=Ip;
	};
	virtual System::String^ ToString()override
	{
		return this->NAME;
	}
};