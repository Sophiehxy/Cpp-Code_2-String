#pragma once
#include<string>
class String
{
	public:
		//�޲ι��캯��
		//String()
		//	:_str(new char[1])
		//{
		//	//*_str = '\0';
		//}
		////���ι��캯��
		//String(const char* str)
		//	:_str(new char[strlen(str) + 1])
		//{
		//	strcpy(_str, str);
		//}

		////�������캯��---------ǳ����
		//String(const String& s)
		//	:_str(s._str)  //��ָ��ָ��ͬһ���ڴ棬�ͷų�������
		//{}

		////�������캯��---------���
		//String(const String& s)
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}
		////��ֵ�����������----��һ��ͳд��---------���
		//String& operator=(const String& s)
		//{
		//	if (this!=&s)//һ������ʡ�Ա��䣬�����Լ��ͷź���ȡ���ֵ
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}
//-------------------------------------------------------------------------------------------------

		////���ι��캯��
		//String(const char* str)
		//	:_str(new char[strlen(str) + 1])
		//{
		//	strcpy(_str, str);
		//}

		//String(const String& s)
		//	:_str(NULL)//���������ε���_str = new char[1];��һ����Ч������������
		//{
		//	//_str = new char[1];//��ֹthis->_str�����deleteʱ������delete����ڴ������
		//	String tmp(s._str);
		//	swap(_str, tmp._str);
		//}

		////��ֵ�����������----�����ִ�д��---------���
		//String& operator=(const String& s)
		//{
		//	if (this != &s)//һ������ʡ�Ա��䣬�����Լ��ͷź���ȡ���ֵ
		//	{
		//		String tmp(s._str);
		//		swap(_str, tmp._str);
		//	}
		//	return *this;
		//}

//----------------------------------------------------------------------------------------------------
		//�������캯��----�����ִ�д���Ľ�---------���
		String(const String& s)
			:_str(NULL)//���������ε���_str = new char[1];��һ����Ч������������
		{
			//_str = new char[1];//��ֹthis->_str�����deleteʱ������delete����ڴ������
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		//��ֵ�����������----�����ִ�д���Ľ�---------���
		String& operator=(String s)//������ʹ��const�����ã�������ֱ�ӽ���ֵ���ı�ָ��
		{
			swap(_str, s._str);
			return *this;
		}

		//��������
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