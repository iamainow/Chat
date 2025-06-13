#pragma once
//nonstandard extension used: enum 'enum' used in qualified name
#pragma warning(disable:4482)
//'function' : not all control paths return a value
#pragma warning(disable:4715)
//
namespace i
{
	//результат сравнения
	enum Comparing:unsigned __int8
	{
		//==
		Equal=0,
		//>
		Great=1,
		//<
		Less=2
	};
	//
	namespace UInt
	{
		//unsigned integer
		class iUInt
		{
			//массив данных
		public:
			unsigned __int8 *VALUE;
			//размер массива VALUE
		public:
			signed __int32 SIZE;
			//размер используемых данных массива VALUE
			//после VALUE[N] идут не используемые данные (нули)
		public:
			signed __int32 N;
			//создать число 0
		public:
			void Create(void)
			{
				this->N=0;
			}
			//создать число с заданным N
		public:
			void Create(const signed __int32 &N)
			{
				this->N=N;
				this->Create_2(N);
			}
			//создать число с заданным N и присвоить всем элементам VALUE число Value
		public:
			void Create(const signed __int32 &N,const unsigned __int8 &Value)
			{
				this->N=N;
				this->Create_2(N,Value);
			}
			//создать число с заданным N
		public:
			void Create_2(const signed __int32 &N)
			{
				if(this->SIZE<N)
				{
					this->SIZE=N;
					delete []this->VALUE;
					this->VALUE=new unsigned __int8[this->SIZE];
				}
			}
		public:
			void Create_2(const signed __int32 &N,const unsigned __int8 &Value)
			{
				this->Create_2(N);
				for(signed __int32 i1=0;i1<N;++i1)
				{
					this->VALUE[i1]=Value;
				}
			}
			//изменить размер массива VALUE
		public:
			void Resize(const signed __int32 &N)
			{
				Resize_2(N);
				this->N=N;
			}
			//изменить размер массива VALUE и заменить освободившиеся позиции числом Value
		public:
			void Resize(const signed __int32 &N,const unsigned __int8 &Value)
			{
				Resize_2(N,Value);
				this->N=N;
			}
		public:
			void Resize_2(const signed __int32 &N)
			{
				if(this->SIZE<N)
				{
					unsigned __int8 *array_1=new unsigned __int8[N];
					for(signed __int32 i1=0;i1<this->N;++i1)
					{
						array_1[i1]=this->VALUE[i1];
					}
					delete []this->VALUE;
					this->VALUE=array_1;
					this->SIZE=N;
				}
			}
		public:
			void Resize_2(const signed __int32 &N,const unsigned __int8 &Value)
			{
				Resize_2(N);
				for(signed __int32 i1=this->N;i1<N;++i1)
				{
					this->VALUE[i1]=Value;
				}
			}
			//копирование
		public:
			void FromUInt(const iUInt &UInt)
			{
				if(this!=&UInt)
				{
					this->Create(UInt.N);
					for(signed __int32 i1=0;i1<this->N;++i1)
					{
						this->VALUE[i1]=UInt.VALUE[i1];
					}
				}
			}
			//удаление
		public:
			void Delete(void)
			{
				delete []this->VALUE;
				this->VALUE=nullptr;
				this->SIZE=0;
				this->N=0;
			}
		public:
			iUInt(void):VALUE(nullptr)
			{
				this->SIZE=0;
				this->Create();
			}
		public:
			iUInt(const iUInt &UInt):VALUE(nullptr)
			{
				this->SIZE=0;
				this->FromUInt(UInt);
			}
		public:
			~iUInt(void)
			{
				this->Delete();
			}
		public:
			void operator=(const iUInt &UInt)
			{
				this->FromUInt(UInt);
			}
			//упрощение this->N
		public:
			void Verify(void)
			{
				for(--this->N;this->N>=0;--this->N)
				{
					if(this->VALUE[this->N]!=0)
					{
						++this->N;
						return;
					}
				}
				this->N=0;
			}
			//упращение this->N, начальное значение N
		public:
			void Verify(const signed __int32 &N)
			{
				this->N=N;
				for(--this->N;this->N>=0;--this->N)
				{
					if(this->VALUE[this->N]!=0)
					{
						++this->N;
						return;
					}
				}
				this->N=0;
			}
			//
			//операторы преобразования типов
			//
			//from unsigned
		public:
			void FromUInt8(const unsigned __int8 &Value)
			{
				this->Create(1);
				this->VALUE[0]=Value;
				if(this->VALUE[0])
				{
					this->N=1;
				}
				else
				{
					this->N=0;
				}
			}
		public:
			void FromUInt16(const unsigned __int16 &Value)
			{
				this->Create(2);
				unsigned __int16 value(Value);
				if(value)
				{
					this->VALUE[0]=static_cast<unsigned __int8>(value);
					value>>=8;
					if(value)
					{
						this->VALUE[1]=static_cast<unsigned __int8>(value);
						this->N=2;
					}
					else
					{
						this->N=1;
					}
				}
				else
				{
					this->N=0;
				}
			}
		public:
			void FromUInt32(const unsigned __int32 &Value)
			{
				this->Create(4);
				unsigned __int32 value(Value);
				if(value)
				{
					this->VALUE[0]=value;
					value>>=8;
					if(value)
					{
						this->VALUE[1]=value;
						value>>=8;
						if(value)
						{
							this->VALUE[2]=value;
							value>>=8;
							if(value)
							{
								this->VALUE[3]=value;
								this->N=4;
							}
							else
							{
								this->N=3;
							}
						}
						else
						{
							this->N=2;
						}
					}
					else
					{
						this->N=1;
					}
				}
				else
				{
					this->N=0;
				}
			}
		public:
			void FromUInt64(const unsigned __int64 &Value)
			{
				this->Create(8);
				unsigned __int64 value(Value);
				if(value)
				{
					this->VALUE[0]=static_cast<unsigned __int8>(value);
					value>>=8;
					if(value)
					{
						this->VALUE[1]=static_cast<unsigned __int8>(value);
						value>>=8;
						if(value)
						{
							this->VALUE[2]=static_cast<unsigned __int8>(value);
							value>>=8;
							if(value)
							{
								this->VALUE[3]=static_cast<unsigned __int8>(value);
								value>>=8;
								if(value)
								{
									this->VALUE[4]=static_cast<unsigned __int8>(value);
									value>>=8;
									if(value)
									{
										this->VALUE[5]=static_cast<unsigned __int8>(value);
										value>>=8;
										if(value)
										{
											this->VALUE[6]=static_cast<unsigned __int8>(value);
											value>>=8;
											if(value)
											{
												this->VALUE[7]=static_cast<unsigned __int8>(value);
												this->N=8;
											}
											else
											{
												this->N=7;
											}
										}
										else
										{
											this->N=6;
										}
									}
									else
									{
										this->N=5;
									}
								}
								else
								{
									this->N=4;
								}
							}
							else
							{
								this->N=3;
							}
						}
						else
						{
							this->N=2;
						}
					}
					else
					{
						this->N=1;
					}
				}
				else
				{
					this->N=0;
				}
			}
			//from signed
		public:
			void FromSInt8(const signed __int8 &Value)
			{
				this->FromUInt8(static_cast<unsigned __int8>(Value));
			}
		public:
			void FromSInt16(const signed __int16 &Value)
			{
				this->FromUInt16(static_cast<unsigned __int16>(Value));
			}
		public:
			void FromSInt32(const signed __int32 &Value)
			{
				this->FromUInt32(static_cast<unsigned __int32>(Value));
			}
		public:
			void FromSInt64(const signed __int64 &Value)
			{
				this->FromUInt64(static_cast<unsigned __int64>(Value));
			}
			//from unsigned
		public:
			iUInt(const unsigned __int8 &Value):VALUE(nullptr)
			{
				SIZE=0;
				this->FromUInt8(Value);
			}
		public:
			iUInt(const unsigned __int16 &Value):VALUE(nullptr)
			{
				SIZE=0;
				this->FromUInt16(Value);
			}
		public:
			iUInt(const unsigned __int32 &Value):VALUE(nullptr)
			{
				SIZE=0;
				this->FromUInt32(Value);
			}
		public:
			iUInt(const unsigned __int64 &Value):VALUE(nullptr)
			{
				SIZE=0;
				this->FromUInt64(Value);
			}
			//from signed
		public:
			iUInt(const signed __int8 &Value):VALUE(nullptr)
			{
				SIZE=0;
				this->FromSInt8(Value);
			}
		public:
			iUInt(const signed __int16 &Value):VALUE(nullptr)
			{
				SIZE=0;
				this->FromSInt16(Value);
			}
		public:
			iUInt(const signed __int32 &Value):VALUE(nullptr)
			{
				SIZE=0;
				this->FromSInt32(Value);
			}
		public:
			iUInt(const signed __int64 &Value):VALUE(nullptr)
			{
				SIZE=0;
				this->FromSInt64(Value);
			}
			//to boolean
		public:
			bool Empty(void)const
			{
				return (this->N==0);
			}
			//to unsigned
		public:
			unsigned __int8 ToUInt8(void)const
			{
				if(this->N>=1)
				{
					return this->VALUE[0];
				}
				else
				{
					return 0;
				}
			}
		public:
			unsigned __int16 ToUInt16(void)const
			{
				if(this->N!=0)
				{
					unsigned __int16 value=this->VALUE[this->N-1];
					if(this->N==1)
					{
						return value;
					}
					else
					{
						for(signed __int32 i1=this->N-2;i1>=0;--i1)
						{
							value<<=8;
							value+=this->VALUE[i1];
						}
						return value;
					}
				}
				else
				{
					return 0;
				}
			}
		public:
			unsigned __int32 ToUInt32(void)const
			{
				if(this->N!=0)
				{
					unsigned __int32 value=this->VALUE[this->N-1];
					if(this->N==1)
					{
						return value;
					}
					else
					{
						for(signed __int32 i1=this->N-2;i1>=0;--i1)
						{
							value<<=8;
							value+=this->VALUE[i1];
						}
						return value;
					}
				}
				else
				{
					return 0;
				}
			}
		public:
			unsigned __int64 ToUInt64(void)const
			{
				if(this->N!=0)
				{
					unsigned __int64 value=this->VALUE[this->N-1];
					if(this->N==1)
					{
						return value;
					}
					else
					{
						for(signed __int32 i1=this->N-2;i1>=0;--i1)
						{
							value<<=8;
							value+=this->VALUE[i1];
						}
						return value;
					}
				}
				else
				{
					return 0;
				}
			}
			//to signed
		public:
			signed __int8 ToSInt8(void)const
			{
				return static_cast<signed __int8>(this->ToUInt8());
			}
		public:
			signed __int16 ToSInt16(void)const
			{
				return static_cast<signed __int16>(this->ToUInt16());
			}
		public:
			signed __int32 ToSInt32(void)const
			{
				return static_cast<signed __int32>(this->ToUInt32());
			}
		public:
			signed __int64 ToSInt64(void)const
			{
				return static_cast<signed __int64>(this->ToUInt64());
			}
			//
			//сравнение
			//
		public:
			static Comparing Compare(const iUInt &UInt1,const iUInt &UInt2)
			{
				if(UInt1.N>UInt2.N)
				{
					return Comparing::Great;
				}
				if(UInt1.N<UInt2.N)
				{
					return Comparing::Less;
				}
				for(signed __int32 i1=UInt1.N-1;i1>=0;--i1)
				{
					if(UInt1.VALUE[i1]>UInt2.VALUE[i1])
					{
						return Comparing::Great;
					}
					if(UInt1.VALUE[i1]<UInt2.VALUE[i1])
					{
						return Comparing::Less;
					}
				}
				return Comparing::Equal;
			}
		public:
			bool operator>(const iUInt &Long)const
			{
				switch(iUInt::Compare(*this,Long))
				{
				case Equal:
					return false;
					break;
				case Great:
					return true;
					break;
				case Less:
					return false;
					break;
				}
			}
		public:
			bool operator>=(const iUInt &Long)const
			{
				switch(iUInt::Compare(*this,Long))
				{
				case Equal:
					return true;
					break;
				case Great:
					return true;
					break;
				case Less:
					return false;
					break;
				}
			}
		public:
			bool operator<(const iUInt &Long)const
			{
				switch(iUInt::Compare(*this,Long))
				{
				case Equal:
					return false;
					break;
				case Great:
					return false;
					break;
				case Less:
					return true;
					break;
				}
			}
		public:
			bool operator<=(const iUInt &Long)const
			{
				switch(iUInt::Compare(*this,Long))
				{
				case Equal:
					return true;
					break;
				case Great:
					return false;
					break;
				case Less:
					return true;
					break;
				}
			}
		public:
			bool operator==(const iUInt &Long)const
			{
				switch(iUInt::Compare(*this,Long))
				{
				case Equal:
					return true;
					break;
				case Great:
					return false;
					break;
				case Less:
					return false;
					break;
				}
			}
		public:
			bool operator!=(const iUInt &Long)const
			{
				switch(iUInt::Compare(*this,Long))
				{
				case Equal:
					return false;
					break;
				case Great:
					return true;
					break;
				case Less:
					return true;
					break;
				}
			}
			//
			//
			//
			//в строку вида VALUE[N-1] - VALUE[N-2] - ... - VALUE[0]
		public:
			System::String ^ToString(void)const
			{
				System::String ^Text=this->N.ToString()+" : ";
				if(this->N)
				{
					for(signed __int32 i1=this->N-1;i1>=1;--i1)
					{
						Text+=this->VALUE[i1].ToString()+" - ";
					}
					Text+=this->VALUE[0].ToString();
				}
				else
				{
					Text+="0";
				}
				return Text;
			}
			//+
		public:
			void AddBigLittle(const iUInt &Big,const iUInt &Little)
			{
				this->Create_2(Big.N+1);
				bool increase=false;
				signed __int32 i1;
				for(i1=0;i1<Little.N;++i1)
				{
					this->VALUE[i1]=Big.VALUE[i1];
					this->VALUE[i1]+=Little.VALUE[i1];
					if(increase)
					{
						increase=(this->VALUE[i1]<Big.VALUE[i1]);
						++this->VALUE[i1];
						if(this->VALUE[i1]==0)
						{
							increase=true;
						}
					}
					else
					{
						increase=(this->VALUE[i1]<Big.VALUE[i1]);
					}
				}
				for(i1=Little.N;i1<Big.N;++i1)
				{
					this->VALUE[i1]=Big.VALUE[i1];
					if(increase)
					{
						++this->VALUE[i1];
						increase=(this->VALUE[i1]==0);
					}
				}
				this->N=Big.N;
				if(increase)
				{
					this->VALUE[Big.N]=1;
					++this->N;
				}
			}
			//+
		public:
			void Add(const iUInt &UInt1,const iUInt &UInt2)
			{
				if(UInt1.N>=UInt2.N)
				{
					this->AddBigLittle(UInt1,UInt2);
				}
				else
				{
					this->AddBigLittle(UInt2,UInt1);
				}
			}
			//+=
		public:
			void Add(const iUInt &UInt)
			{
				this->Resize_2(System::Math::Max(this->N,UInt.N)+1,0);
				this->N=System::Math::Max(this->N,UInt.N);
				bool increase=false;
				signed __int32 i1;
				for(i1=0;i1<UInt.N;++i1)
				{
					this->VALUE[i1]+=UInt.VALUE[i1];
					if(increase)
					{
						increase=(this->VALUE[i1]<UInt.VALUE[i1]);
						++this->VALUE[i1];
						if(this->VALUE[i1]==0)
						{
							increase=true;
						}
					}
					else
					{
						increase=(this->VALUE[i1]<UInt.VALUE[i1]);
					}
				}
				for(i1=UInt.N;i1<this->N;++i1)
				{
					if(increase)
					{
						++this->VALUE[i1];
						increase=(this->VALUE[i1]==0);
					}
					else
					{
						break;
					}
				}
				if(increase)
				{
					this->VALUE[this->N]=1;
					++this->N;
				}
			}
		public:
			iUInt operator+(const iUInt &UInt)const
			{
				iUInt uint1;
				uint1.Add(*this,UInt);
				return uint1;
			}
		public:
			iUInt &operator+=(const iUInt &UInt)
			{
				this->Add(UInt);
				return *this;
			}
		public:
			void operator++(void)
			{
				if(this->N==0)
				{
					this->Create(1);
					this->VALUE[0]=1;
					return;
				}
				for(signed __int32 i1=0;i1<this->N;++i1)
				{
					++this->VALUE[i1];
					if(this->VALUE[i1]!=0)
					{
						return;
					}
				}
				if(this->VALUE[this->N-1]==0)
				{
					this->Resize(this->N+1);
					this->VALUE[this->N]=1;
				}
			}
			//-
		public:
			void Subtract(const iUInt &Big,const iUInt &Little)
			{
				this->Create(Big.N);
				bool decrease=false;
				signed __int32 i1;
				for(i1=0;i1<Little.N;++i1)
				{
					this->VALUE[i1]=Big.VALUE[i1];
					this->VALUE[i1]-=Little.VALUE[i1];
					if(decrease)
					{
						decrease=(this->VALUE[i1]>Big.VALUE[i1]);
						if(this->VALUE[i1]==0)
						{
							decrease=true;
						}
						--this->VALUE[i1];
					}
					else
					{
						decrease=(this->VALUE[i1]>Big.VALUE[i1]);
					}
				}
				for(i1=Little.N;i1<Big.N;++i1)
				{
					this->VALUE[i1]=Big.VALUE[i1];
					if(decrease)
					{
						decrease=(this->VALUE[i1]==0);
						--this->VALUE[i1];
					}
				}
				this->Verify();
			}
			//-=
		public:
			void Subtract(const iUInt &Little)
			{
				bool decrease=false;
				signed __int32 i1;
				unsigned __int8 curr_value;
				for(i1=0;i1<Little.N;++i1)
				{
					curr_value=this->VALUE[i1];
					this->VALUE[i1]-=Little.VALUE[i1];
					if(decrease)
					{
						decrease=(this->VALUE[i1]>curr_value);
						if(this->VALUE[i1]==0)
						{
							decrease=true;
						}
						--this->VALUE[i1];
					}
					else
					{
						decrease=(this->VALUE[i1]>curr_value);
					}
				}
				for(i1=Little.N;i1<this->N;++i1)
				{
					if(decrease)
					{
						decrease=(this->VALUE[i1]==0);
						--this->VALUE[i1];
					}
					else
					{
						break;
					}
				}
				this->Verify();
			}
		public:
			iUInt operator-(const iUInt &Little)const
			{
				iUInt l1;
				l1.Subtract(*this,Little);
				return l1;
			}
		public:
			iUInt &operator-=(const iUInt &Little)
			{
				this->Subtract(Little);
				return *this;
			}
		public:
			void operator--(void)
			{
				if(this->N!=0)
				{
					for(signed __int32 i1=0;i1<this->N;++i1)
					{
						if(this->VALUE[i1]==0)
						{
							--this->VALUE[i1];
						}
						else
						{
							--this->VALUE[i1];
							return;
						}
					}
					if(this->VALUE[this->N-1]==0)
					{
						--this->N;
					}
				}
			}
			//*
		public:
			void Multiply(const iUInt &Long,const unsigned __int8 &Value)
			{
				if(Value==0)
				{
					this->Create();
					return;
				}
				if(Value==1)
				{
					this->FromUInt(Long);
					return;
				}
				this->Create_2(Long.N+1);
				unsigned __int16 value=static_cast<unsigned __int16>(Value);
				unsigned __int8 increase=0;
				unsigned __int16 num1;
				signed __int32 i1;
				for(i1=0;i1<Long.N;++i1)
				{
					num1=value*static_cast<unsigned __int16>(Long.VALUE[i1]);
					this->VALUE[i1]=static_cast<unsigned __int8>(num1);
					if(increase!=0)
					{
						this->VALUE[i1]+=increase;
						increase=(this->VALUE[i1]<increase);
					}
					increase+=(num1>>8);
				}
				this->N=Long.N;
				if(increase)
				{
					this->VALUE[this->N]=increase;
					++this->N;
				}
			}
		public:
			iUInt operator*(const unsigned __int8 &Value)const
			{
				iUInt l1;
				l1.Multiply(*this,Value);
				return l1;
			}
		public:
			iUInt &operator*=(const unsigned __int8 &Value)
			{
				iUInt l1;
				l1.Multiply(*this,Value);
				*this=l1;
				return *this;
			}
			//*
		public:
			void Multiply(const iUInt &UInt1,const iUInt &UInt2)
			{
				if(UInt1.N==0 && UInt2.N==0)
				{
					this->N=0;
					return;
				}
				unsigned __int16 num1;
				unsigned __int8 increase;
				signed __int32 i1,i2,i3;
				this->Create(UInt1.N+UInt2.N,0);
				for(i1=0;i1<UInt2.N;++i1)
				{
					increase=0;
					for(i2=0,i3=i1;i2<UInt1.N;++i2,++i3)
					{
						num1=UInt1.VALUE[i2]*UInt2.VALUE[i1];
						num1+=static_cast<unsigned __int16>(increase);
						VALUE[i3]+=static_cast<unsigned __int8>(num1);
						if(VALUE[i3]<static_cast<unsigned __int8>(num1))
						{
							increase=1;
						}
						else
						{
							increase=0;
						}
						num1>>=8;
						increase+=static_cast<unsigned __int8>(num1);
					}
					if(increase)
					{
						VALUE[i1+UInt1.N]+=increase;
					}
				}
				if(VALUE[UInt1.N+UInt2.N-1]==0)
				{
					--this->N;
				}
			}
		public:
			iUInt operator*(const iUInt &UInt)const
			{
				iUInt l1;
				l1.Multiply(*this,UInt);
				return l1;
			}
		public:
			iUInt &operator*=(const iUInt &UInt)
			{
				iUInt l1;
				l1.Multiply(*this,UInt);
				*this=l1;
				return *this;
			}
			//^2
		public:
			void Sqr(const iUInt &UInt)
			{
				if(UInt.N==0)
				{
					this->N=0;
					return;
				}
				unsigned __int16 num1;
				unsigned __int8 increase;
				signed __int32 i1,i2;
				signed __int32 n2=UInt.N;
				n2<<=1;
				this->Create(n2,0);
				for(i1=0;i1<UInt.N;++i1)
				{
					increase=0;
					for(i2=0;i2<UInt.N;++i2)
					{
						num1=static_cast<unsigned __int16>(UInt.VALUE[i2])*static_cast<unsigned __int16>(UInt.VALUE[i1]);
						num1+=static_cast<unsigned __int16>(increase);
						VALUE[i1+i2]+=static_cast<unsigned __int8>(num1);
						if(VALUE[i1+i2]<static_cast<unsigned __int8>(num1))
						{
							increase=1;
						}
						else
						{
							increase=0;
						}
						num1>>=8;
						increase+=static_cast<unsigned __int8>(num1);
					}
					if(increase)
					{
						VALUE[i1+UInt.N]+=increase;
					}
				}
				if(VALUE[n2-1]==0)
				{
					--this->N;
				}
			}
			//<<8*Value
		public:
			void IncreaseByte(const iUInt &UInt,const signed __int32 &Value)
			{
				this->Create(UInt.N+Value);
				signed __int32 i1;
				for(i1=0;i1<Value;++i1)
				{
					this->VALUE[i1]=0;
				}
				for(i1=Value;i1<this->N;++i1)
				{
					this->VALUE[i1]=UInt.VALUE[i1-Value];
				}
			}
			//<<=8*Value
		public:
			void IncreaseByte(const signed __int32 &Value)
			{
				this->Resize(this->N+Value);
				signed __int32 i1;
				for(i1=this->N-1;i1>=Value;--i1)
				{
					this->VALUE[i1]=this->VALUE[i1-Value];
				}
				for(i1=0;i1<Value;++i1)
				{
					this->VALUE[i1]=0;
				}
			}
			//>>8*Value
		public:
			void DecreaseByte(const iUInt &UInt,const signed __int32 &Value)
			{
				if(UInt.N>Value)
				{
					this->Create(UInt.N-Value);
					signed __int32 i1;
					for(i1=0;i1<this->N;++i1)
					{
						this->VALUE[i1]=UInt.VALUE[i1+Value];
					}
				}
				else
				{
					this->N=0;
				}
			}
			//>>=8*Value
		public:
			void DecreaseByte(const signed __int32 &Value)
			{
				if(this->N>Value)
				{
					this->N-=Value;
					signed __int32 i1;
					for(i1=0;i1<this->N;++i1)
					{
						this->VALUE[i1]=this->VALUE[i1+Value];
					}
				}
				else
				{
					this->N=0;
				}
			}
			//<<Value
		public:
			void IncreaseBit(const iUInt &UInt,const signed __int32 &Value)
			{
				if(UInt.N==0)
				{
					this->N=0;
					return;
				}
				const signed __int32 AntiValue=8-Value;
				if(UInt.VALUE[UInt.N-1]>>AntiValue)
				{
					this->Create(UInt.N+1);
					this->VALUE[0]=UInt.VALUE[0]<<Value;
					for(signed __int32 i1=1;i1<UInt.N;++i1)
					{
						this->VALUE[i1]=(UInt.VALUE[i1-1]>>AntiValue)+(UInt.VALUE[i1]<<Value);
					}
					this->VALUE[UInt.N]=UInt.VALUE[UInt.N-1]>>AntiValue;
				}
				else
				{
					this->Create(UInt.N);
					this->VALUE[0]=UInt.VALUE[0]<<Value;
					for(signed __int32 i1=1;i1<UInt.N;++i1)
					{
						this->VALUE[i1]=(UInt.VALUE[i1-1]>>AntiValue)+(UInt.VALUE[i1]<<Value);
					}
				}
			}
			//
		public:
			void IncreaseBit(const signed __int32 &Value)
			{
				iUInt long_1=*this;
				this->IncreaseBit(long_1,Value);
			}
			//>>Value
		public:
			void DecreaseBit(const iUInt &UInt,const signed __int32 &Value)
			{
				if(UInt.N==0)
				{
					this->N=0;
					return;
				}
				const signed __int32 AntiValue=8-Value;
				if(UInt.VALUE[UInt.N-1]>>Value)
				{
					this->Create(UInt.N);
					for(signed __int32 i1=0;i1<UInt.N-1;++i1)
					{
						this->VALUE[i1]=(UInt.VALUE[i1+1]<<AntiValue)+(UInt.VALUE[i1]>>Value);
					}
					this->VALUE[UInt.N-1]=(UInt.VALUE[UInt.N-1]>>Value);
				}
				else
				{
					this->Create(UInt.N-1);
					for(signed __int32 i1=0;i1<UInt.N-1;++i1)
					{
						this->VALUE[i1]=(UInt.VALUE[i1+1]<<AntiValue)+(UInt.VALUE[i1]>>Value);
					}
				}
			}
			//
		public:
			void DecreaseBit(const signed __int32 &Value)
			{
				iUInt long_1=*this;
				this->DecreaseBit(long_1,Value);
			}
		public:
			void IncreaseBits(const iUInt &UInt,const signed __int32 &Value)
			{
				this->IncreaseBit(UInt,Value%8);
				this->IncreaseByte(Value/8);
			}
		public:
			void DecreaseBits(const iUInt &UInt,const signed __int32 &Value)
			{
				this->DecreaseBit(UInt,Value%8);
				this->DecreaseByte(Value/8);
			}
		public:
			iUInt operator<<(const unsigned __int32 &Value)const
			{
				if(Value)
				{
					iUInt long_1;
					long_1.IncreaseBits(*this,Value);
					return long_1;
				}
				else
				{
					return *this;
				}
			}
		public:
			iUInt &operator<<=(const unsigned __int32 &Value)
			{
				if(Value)
				{
					iUInt long_1;
					long_1.IncreaseBits(*this,Value);
					*this=long_1;
				}
				return *this;
			}
		public:
			iUInt operator>>(const unsigned __int32 &Value)const
			{
				if(Value)
				{
					iUInt long_1;
					long_1.DecreaseBits(*this,Value);
					return long_1;
				}
				else
				{
					return *this;
				}
			}
		public:
			iUInt &operator>>=(const unsigned __int32 &Value)
			{
				if(Value)
				{
					iUInt long_1;
					long_1.DecreaseBits(*this,Value);
					*this=long_1;
				}
				return *this;
			}
			//
		public:
			static unsigned __int8 ProbablyDivide(const iUInt &Long1,const iUInt &Long2)
			{
				if(Long1.N>=Long2.N+2)
				{
					return 255;
				}
				if(Long1.N<Long2.N || Long1.N==0)
				{
					return 0;
				}
				else
				{
					unsigned __int32 int1=0,int2=0;
					unsigned __int8 int3;
					if(Long1.N>=1)
					{
						int1+=static_cast<unsigned __int32>(Long1.VALUE[Long1.N-1])<<16;
						if(Long1.N>=2)
						{
							int1+=static_cast<unsigned __int32>(Long1.VALUE[Long1.N-2])<<8;
							if(Long1.N>=3)
							{
								int1+=static_cast<unsigned __int32>(Long1.VALUE[Long1.N-3]);
							}
						}
					}
					if(Long1.N==Long2.N)
					{
						if(Long2.N>=1)
						{
							int2+=static_cast<unsigned __int32>(Long2.VALUE[Long2.N-1])<<16;
							if(Long2.N>=2)
							{
								int2+=static_cast<unsigned __int32>(Long2.VALUE[Long2.N-2])<<8;
								if(Long2.N>=3)
								{
									int2+=static_cast<unsigned __int32>(Long2.VALUE[Long2.N-3]);
								}
							}
						}
					}
					else
					{
						//int2=0;
						if(Long2.N>=1)
						{
							int2+=static_cast<unsigned __int32>(Long2.VALUE[Long2.N-1])<<8;
							if(Long2.N>=2)
							{
								int2+=static_cast<unsigned __int32>(Long2.VALUE[Long2.N-2]);
							}
						}
					}
					++int2;
					int3=int1/int2;
					return int3;
				}
			}
			//деление Long1 на Long2, результат -Result, остаток - Ostatok
		public:
			static void Divide(const iUInt &Long1,const iUInt &Long2,iUInt &Result,iUInt &Ostatok)
			{
				//если делим на 0 - ошибка
				if(Long2.N==0)
				{
					throw __LINE__;
					Result.Create();
					Ostatok.Create();
					return;
				}
				Comparing compare=iUInt::Compare(Long1,Long2);
				if(compare==Comparing::Less)
				{
					Result.Create();
					Ostatok.FromUInt(Long1);
					return;
				}
				if(compare==Comparing::Equal)
				{
					Result.Create(1);
					Result.VALUE[0]=1;
					Ostatok.Create();
					return;
				}
				iUInt long_4;
				long_4.Create(Long2.N+1);
				Result.Create(Long1.N-Long2.N+1,0);
				Ostatok.DecreaseByte(Long1,Long1.N-Long2.N);
				unsigned __int8 int1;
				for(signed __int32 i1=Result.N-1;i1>=0;--i1)
				{
					while(Ostatok>=Long2)
					{
						int1=iUInt::ProbablyDivide(Ostatok,Long2);
						if(int1)
						{
							Result.VALUE[i1]+=int1;
							long_4.Multiply(Long2,int1);
							Ostatok-=long_4;
						}
						else
						{
							++Result.VALUE[i1];
							Ostatok-=Long2;
						}
					}
					if(i1!=0)
					{
						//сдвиг на 1 позицию
						Ostatok<<=8;
						//копирование в конец числа цифры из Long1
						Ostatok.VALUE[0]=Long1.VALUE[i1-1];
						Ostatok.Verify();
					}
				}
				Result.Verify();
				Ostatok.Verify();
			}
		public:
			iUInt operator/(const iUInt &UInt)const
			{
				iUInt uint1,uint2;
				iUInt::Divide(*this,UInt,uint1,uint2);
				return uint1;
			}
		public:
			iUInt operator%(const iUInt &UInt)const
			{
				iUInt uint1,uint2;
				iUInt::Divide(*this,UInt,uint1,uint2);
				return uint2;
			}
		public:
			iUInt &operator/=(const iUInt &UInt)
			{
				iUInt uint1,uint2;
				iUInt::Divide(*this,UInt,uint1,uint2);
				*this=uint1;
				return *this;
			}
		public:
			iUInt &operator%=(const iUInt &UInt)
			{
				iUInt uint1,uint2;
				iUInt::Divide(*this,UInt,uint1,uint2);
				*this=uint2;
				return *this;
			}
		public:
			void Pow(const iUInt &Value,const iUInt &Degree)
			{
				this->FromUInt8(1);
				if(Degree.Empty())
				{
					return;
				}
				if(Value.Empty())
				{
					this->N=0;
					return;
				}
				if(Value.N==1 && Value.VALUE[0]==1)
				{
					return;
				}
				if(Degree.N==1 && Degree.VALUE[0]==1)
				{
					this->FromUInt(Value);
					return;
				}
				iUInt a(Value);
				iUInt degree(Degree);
				iUInt uint1;
				while (degree.N!=0)
				{
					if(degree.VALUE[0]%2==0)
					{
						degree.DecreaseBit(1);
						uint1=a;
						a.Sqr(uint1);
					}
					else
					{
						--degree;
						uint1=*this;
						this->Multiply(uint1,a);
					}
				}
			}
		public:
			void Pow(const iUInt &Value,const iUInt &Degree,const iUInt &Modul)
			{
				this->FromUInt8(1);
				if(Degree.N==0)
				{
					return;
				}
				if(Degree==1)
				{
					iUInt::Divide(Value,Modul,iUInt(),*this);
					return;
				}
				if(Value.N==0)
				{
					this->N=0;
					return;
				}
				if(Value==1)
				{
					return;
				}
				iUInt a(Value);
				iUInt degree(Degree);
				iUInt res,ost;
				while(degree.N!=0)
				{
					if(degree.VALUE[0]%2==0)
					{
						degree.DecreaseBit(1);
						//res.Sqr(a);
						a*=a;
						//a=res;
						iUInt::Divide(a,Modul,res,ost);
						a=ost;
					}
					else
					{
						--degree;
						//res.Multiply(a,*this);
						//*this=res;
						*this=a**this;
						iUInt::Divide(*this,Modul,res,ost);
						*this=ost;
					}
				}
			}
			//НОД
		public:
			void NOD(const iUInt &Long1,const iUInt &Long2)
			{
				iUInt long_1;
				iUInt a,b,c;
				a=Long1;
				b=Long2;
				while(b.N!=0)
				{
					iUInt::Divide(a,b,long_1,c);
					a=b;
					b=c;        
				}
				*this=a;
			}
			//конвертирование из 10-значной строки
		public:
			void From10String(System::String^ Number)
			{
				iUInt result;
				iUInt degree;
				degree.FromUInt8(1);
				iUInt long_1;
				iUInt __10;
				__10.FromUInt8(10);
				if(Number->Length==0)
				{
					this->Create();
					return;
				}
				for(signed __int32 i1=Number->Length-1;i1>=0;--i1)
				{
					long_1.FromUInt16(static_cast<unsigned __int16>(System::Convert::ToChar(Number[i1])-48));
					result+=long_1*degree;
					degree=degree*__10;
				}
				*this=result;
			}
			//в строку
		public:
			System::String^ To10String(void)
			{
				if(this->N==0)
				{
					return "";
				}
				System::String^ result="";
				iUInt __10;
				__10.FromUInt8(10);
				//
				iUInt long_1,long_2,long_3;
				long_1=*this;
				while(long_1.N!=0)
				{
					iUInt::Divide(long_1,__10,long_2,long_3);
					if(long_3.N!=0)
					{
						result=long_3.VALUE[0].ToString()+result;
					}
					else
					{
						result="0"+result;
					}
					long_1=long_2;
				}
				return result;
			}
		public:
			int Log2(void)const
			{
				unsigned __int8 i1=this->VALUE[this->N-1];
				int i2=(this->N-1)<<3;
				while(i1)
				{
					i1>>=1;
					++i2;
				}
				return i2;
			}
		};
	}
}