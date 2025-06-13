#pragma once
#include "iUInt.h"
namespace i
{
	class iRSA
	{
		//простые числа
	public:
		UInt::iUInt P;
	public:
		UInt::iUInt Q;
		//открытая экспонента
	public:
		UInt::iUInt E;
		//закрытая экспонента
	public:
		UInt::iUInt D;
		//P*Q
	public:
		UInt::iUInt N;
		//(P-1)*(Q-1)
	public:
		UInt::iUInt F;
	public:
		iRSA(void)
		{
		}
	public:
		~iRSA(void)
		{
		}
		//является ли случайное число свидетелем простоты числа m
	public:
		static bool IsSvidetel(const UInt::iUInt &m,System::Random^ random,const UInt::iUInt &t,const int &s,UInt::iUInt &a,const UInt::iUInt &m_1)
		{
			//генерация a (a<m && a>1)
			a.Create(m.N);
			do
			{
				a.N=m.N;
				for(int i1=0;i1<a.N;++i1)
				{
					a.VALUE[i1]=random->Next();
				}
				a.Verify();
			}
			while(a>=m || a.N==0 || (a.N==1 && a.VALUE[0]==1));
			UInt::iUInt l1,l2;
			//l1.Create(t.N);
			UInt::iUInt::Divide(m,a,l1,l2);
			if(l1.N!=0)
			{
				l1.Pow(a,t,m);
				if(l1==1 || l1==m_1)
				{
					return true;
				}
				l1=t;
				for(int k=0;k<s;++k,l1.IncreaseBit(1))
				{
					l2.Pow(a,l1,m);
					if(l2==m_1)
					{
						return true;
					}
				}
				return false;
			}
			else
			{
				return false;
			}
			return false;
		}
		//генерация одного простого числа и проверка его на простоту
	public:
		static void ProbablyGeneratePrimeNumber(const int &Byte,const int &Round,System::Random^ random,UInt::iUInt &L,const UInt::iUInt &Border)
		{
			L.Create(Byte);
			UInt::iUInt t;
			int s;
			int i1;
			//генерация случайного L: L%2!=0, L>1, L<256^Byte
			do
			{
				for(i1=1;i1<Byte-1;++i1)
				{
					L.VALUE[i1]=random->Next();
				}
				do
				{
					L.VALUE[0]=random->Next();
				}
				while(L.VALUE[0]%2==0);
				do
				{
					L.VALUE[Byte-1]=random->Next();
				}
				while(L.VALUE[Byte-1]==0);
			}
			while(L.N==0 || (L.N==1 && L.VALUE[0]==1));
			//проверка на тривиальные делители
			UInt::iUInt uint1,uint2,uint3;
			for(uint3=3;uint3<Border;uint3+=2)
			{
				UInt::iUInt::Divide(L,uint3,uint1,uint2);
				if(uint2.N==0)
				{
					L.Create();
					return;
				}
			}
			//
			uint2=L;
			--uint2;
			for(s=0;;++s)
			{
				t.DecreaseBits(uint2,s);
				uint3.IncreaseBits(t,s);
				uint1.Subtract(uint2,uint3);
				//
				if(uint1.N==0 && t.N!=0 && t.VALUE[0]%2==1)
				{
					break;
				}
			}
			for(int r=0;r<Round;++r)
			{
				if(!IsSvidetel(L,random,t,s,uint1,uint2))
				{
					L.Create();
					return;
				}
			}
			return;
		}
		//генерация простого числа
	public:
		static void GeneratePrimeNumber(const int &Byte,const int &Round,System::Random^ random,UInt::iUInt &L,const UInt::iUInt &Border)
		{
			while(true)
			{
				ProbablyGeneratePrimeNumber(Byte,Round,random,L,Border);
				if(L.N!=0)
				{
					return;
				}
			}
		}
		//генерация P и Q
	public:
		void GeneratePrimeNumbers(const int &Byte,const int &Round,const UInt::iUInt &Border)
		{
			System::Random^ random=gcnew System::Random;
			GeneratePrimeNumber(Byte,Round,random,P,Border);
			GeneratePrimeNumber(Byte,Round,random,Q,Border);
		}
		//генерация E и D
	public:
		void GenerateEDKey(System::Random^ random)
		{
			UInt::iUInt uint1,uint2;
			uint1.FromUInt8(1);
			N=P*Q;
			F=(P-uint1)*(Q-uint1);
			E.Create(F.N-1,0);
			do
			{
				for(int i1=0;i1<E.N;i1++)
				{
					E.VALUE[i1]=random->Next();
				}
				E.Verify();
				uint2.NOD(E,F);
			}
			while(E<=uint1 || E>=F || uint2!=uint1);
			UInt::iUInt x,y;
			NODADV(UInt::iUInt(F),UInt::iUInt(E),x,y);
			D=y;
			if((E*D)%F!=uint1)
			{
				GenerateEDKey(random);
			}
		}
		//signed вычитание
		static void subtract(const UInt::iUInt &a,const UInt::iUInt &b,const bool &sign_a,const bool &sign_b,UInt::iUInt &result,bool &sign_res)
		{
			if(sign_a)
			{
				if(sign_b)
				{
					if(a<b)
					{
						result=b-a;
						sign_res=false;
					}
					else
					{
						result=a-b;
						sign_res=true;
					}
				}
				else
				{
					result=b+a;
					sign_res=true;
				}
			}
			else
			{
				if(sign_b)
				{
					result=b+a;
					sign_res=false;
				}
				else
				{
					if(a<b)
					{
						result=b-a;
						sign_res=true;
					}
					else
					{
						result=a-b;
						sign_res=false;
					}
				}
			}
		}
		//расширенный алгоритм евклида
		static void NODADV(UInt::iUInt &a,UInt::iUInt &b,UInt::iUInt &x,UInt::iUInt &y)
		{
			UInt::iUInt q,r,x1,x2,x3,x4;
			x1.FromUInt8(1);
			x2.FromUInt8(0);
			x3.FromUInt8(0);
			x4.FromUInt8(1);
			bool plus1=true,plus2=true,plus3=true,plus4=true;
			while(true)
			{
				UInt::iUInt::Divide(a,b,q,r);
				if(r.N==0)
				{
					x=x2;
					y=x4;
					return;
				}
				UInt::iUInt y1,y2,y3,y4;
				bool plus11=plus1,plus22=plus2,plus33=plus3,plus44=plus4;
				//
				y1=x1;
				y2=x2;
				y3=x3;
				y4=x4;
				//
				plus1=plus22;
				x1=y2;
				//
				subtract(y1,y2*q,plus11,plus22,x2,plus2);
				//
				plus3=plus44;
				x3=y4;
				//
				subtract(y3,y4*q,plus33,plus44,x4,plus4);
				//
				a=b;
				b=r;
			}
		}
		//зашифровать число
		UInt::iUInt EncryptValue(const UInt::iUInt &Value)
		{
			//N=P*Q;
			UInt::iUInt i1;
			i1.Pow(Value,this->E,this->N);
			return i1;
		}
		//расшифровать число
		UInt::iUInt DecryptValue(const UInt::iUInt &Value)
		{
			//N=P*Q;
			UInt::iUInt i1;
			i1.Pow(Value,this->D,this->N);
			return i1;
		}
		//зашифровать неограниченный по длине текст
		System::String^ EncryptAllText(System::String^ Text)
		{
			System::String^ text2="";
			int len=(N.N-1)/2;
			for(int i1=0;i1<Text->Length;i1+=len)
			{
				if(i1+len<=Text->Length)
				{
					text2+=this->EncryptText(Text->Substring(i1,len));
				}
				else
				{
					text2+=this->EncryptText(Text->Substring(i1));
				}
			}
			return text2;
		}
		//зашифровать короткий текст
		System::String^ EncryptText(System::String^ Text)
		{
			System::String^ text2="";
			for(int i1=0;i1<Text->Length;i1++)
			{
				text2+=static_cast<wchar_t>(Text[i1]+256);
			}
			UInt::iUInt L1;
			L1.Create(text2->Length*2);
			for(int i1=0;i1<text2->Length;i1++)
			{
				L1.VALUE[i1*2]=text2[i1]%256;
				L1.VALUE[i1*2+1]=text2[i1]/256;
			}
			L1.Verify();
			UInt::iUInt L2=this->EncryptValue(L1);
			UInt::iUInt L3=L2;
			L3.Resize(N.N,0);
			System::String^ text3="";
			for(int i1=0;i1<L3.N;i1++)
			{
				text3=text3+static_cast<wchar_t>(static_cast<int>(L3.VALUE[i1])+256);
			}
			return text3;
		}
		//расшифровать неограниченный по длине текст
		System::String^ DecryptAllText(System::String^ Text)
		{
			System::String^ text2="";
			for(int i1=0;i1<Text->Length;i1+=N.N)
			{
				if(i1+N.N<=Text->Length)
				{
					text2+=this->DecryptText(Text->Substring(i1,N.N));
				}
			}
			return text2;
		}
		//расшифровать короткий текст
		System::String^ DecryptText(System::String^ Text)
		{
			UInt::iUInt L1;
			L1.Create(N.N);
			for(int i1=0;i1<Text->Length;i1++)
			{
				L1.VALUE[i1]=Text[i1]-256;
			}
			UInt::iUInt L2=L1;
			L2.Verify();
			UInt::iUInt L3=this->DecryptValue(L2);
			L3.Verify();
			System::String^ text2="";
			for(int i1=0;i1<L3.N;i1+=2)
			{
				text2+=static_cast<wchar_t>(static_cast<int>(L3.VALUE[i1+1])*256+static_cast<int>(L3.VALUE[i1]));
			}
			System::String^ text3="";
			for(int i1=0;i1<text2->Length;i1++)
			{
				text3=text3+static_cast<wchar_t>(text2[i1]-256);
			}
			return text3;
		}
	};
}