#pragma once
#include<string>
class String
{
	public:
		//无参构造函数
		//String()
		//	:_str(new char[1])
		//{
		//	//*_str = '\0';
		//}
		////带参构造函数
		//String(const char* str)
		//	:_str(new char[strlen(str) + 1])
		//{
		//	strcpy(_str, str);
		//}

		////拷贝构造函数---------浅拷贝
		//String(const String& s)
		//	:_str(s._str)  //两指针指向同一块内存，释放出现问题
		//{}

		////拷贝构造函数---------深拷贝
		//String(const String& s)
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}
		////赋值运算符的重载----法一传统写法---------深拷贝
		//String& operator=(const String& s)
		//{
		//	if (this!=&s)//一定不能省略本句，否则将自己释放后，再取随机值
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}
//-------------------------------------------------------------------------------------------------

		////带参构造函数
		//String(const char* str)
		//	:_str(new char[strlen(str) + 1])
		//{
		//	strcpy(_str, str);
		//}

		//String(const String& s)
		//	:_str(NULL)//与下面屏蔽掉的_str = new char[1];有一样的效果，但这句更好
		//{
		//	//_str = new char[1];//防止this->_str随机，delete时不发生delete随机内存而崩溃
		//	String tmp(s._str);
		//	swap(_str, tmp._str);
		//}

		////赋值运算符的重载----法二现代写法---------深拷贝
		//String& operator=(const String& s)
		//{
		//	if (this != &s)//一定不能省略本句，否则将自己释放后，再取随机值
		//	{
		//		String tmp(s._str);
		//		swap(_str, tmp._str);
		//	}
		//	return *this;
		//}

//----------------------------------------------------------------------------------------------------
		//拷贝构造函数----法三现代写法改进---------深拷贝
		String(const String& s)
			:_str(NULL)//与下面屏蔽掉的_str = new char[1];有一样的效果，但这句更好
		{
			//_str = new char[1];//防止this->_str随机，delete时不发生delete随机内存而崩溃
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		//赋值运算符的重载----法三现代写法改进---------深拷贝
		String& operator=(String s)//参数不使用const和引用，函数内直接交换值，改变指向
		{
			swap(_str, s._str);
			return *this;
		}

		//析构函数
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = NULL;
			}
		}

		void Display()
		{
			cout << _str << endl;
		}
		
private:
	char* _str;
};

void Test()
{
	String s1("Hello World.");
	s1.Display();
	String s2(s1);
	s2.Display();
	String s3("Change World.");
	s1 = s3;
	s1.Display();
}