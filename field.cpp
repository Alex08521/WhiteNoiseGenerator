#include "field.h"
#define _CRT_SECURE_NO_WARNINGS

template field<unsigned short>;
template field<unsigned int>;
template field<unsigned long>;
template field<long>;
template field<float>;
template field<short>;
template field<int>;
template field<double>;
template field<bool>;
template field<char>;
template field<wchar_t>;

//‘ункци€ дл€ перемещени€ по двумерному полю, действуют те же правила, что и у обычного двумерного массива
template<typename fieldvar>
void field<fieldvar>::moveTo(int x, int y)
{
	if (x > -1 && y > -1)
	{
		int segment = sideX * y + x;
		if (numOfElems > segment)
		{
			fieldArr = startArr;
			fieldArr += segment;
			X = x;
			Y = y;
		}
	}
}

//‘ункци€ дл€ записи пременной в выбранную €чейку пол€, €чейка выбераетс€ отдельно
template<typename fieldvar>
void field<fieldvar>::writeIn(fieldvar var)
{
	*fieldArr = var;
}

//¬озвращает значение X
template<typename fieldvar>
int field<fieldvar>::returnX()
{
	return X;
}

//¬озвращает значение Y
template<typename fieldvar>
int field<fieldvar>::returnY()
{
	return Y;
}

template<typename fieldvar>
void field<fieldvar>::destroy()
{
	this->~field();
}

template<typename fieldvar>
bool field<fieldvar>::resize(int x, int y)
{
	sideX = x;
	sideY = y;
	numOfElems = sideX * sideY;
	if (numOfElems > 6250000)
	{
		return false;
	}
	fieldArr = (fieldvar*)malloc((numOfElems + 1) * sizeof(fieldvar));
	startArr = fieldArr;
	for (int i = 0; i < sideY; i++)
	{
		for (int j = 0; j < sideX; j++)
		{
			moveTo(j, i);
			writeIn(0);
		}
	}
	X = 0;
	Y = 0;
	return true;
}

//‘ункци€ чтени€ из выбранной €чейки, €чейка выбираетс€ отдельно
template<typename fieldvar>
fieldvar& field<fieldvar>::readOn()
{
	return *fieldArr;
}

//‘ункци€ перегрузки оператора скобки() при записи переменных x и y уазатель смещаетс€ в соответствующую координатам €чейку
template<typename fieldvar>
fieldvar& field<fieldvar>::operator()(int x, int y)
{
	moveTo(x, y);
	return readOn();
}

//‘ункци€ перегрузки оператора присваивани€ =, значение переменной присваиваетс€ в выбранную €чейку
template<typename fieldvar>
void field<fieldvar>::operator=(fieldvar var)
{
	writeIn(var);
}

template<typename fieldvar>
void field<fieldvar>::operator++()
{
	writeIn(*fieldArr++);
}

//‘ункци€ перегрузки оператора присваивани€ =, значение выбранной €чейки присваиваетс€ переменной(в теории)
template<typename fieldvar>
field<fieldvar>::operator fieldvar()
{
	return readOn();
}

template<typename fieldvar>
field<fieldvar>::field()
{
	sideX = 1;
	sideY = 1;
	numOfElems = sideX * sideY;
	fieldArr = (fieldvar*)malloc((numOfElems + 1) * sizeof(fieldvar));
	startArr = fieldArr;
	for (int i = 0; i < sideY; i++)
	{
		for (int j = 0; j < sideX; j++)
		{
			moveTo(j, i);
			writeIn(0);
		}
	}
	X = 0;
	Y = 0;
}

template<typename fieldvar>
field<fieldvar>::field(int numOfElements)
{
	sideX = 16;
	sideY = 9;
	int check = 2;
	while(true)
	{
		int d = sideX * sideY;
		if (numOfElements < d)
		{
			check -= 2;
			sideX = 16 * check;
			sideY = 9 * check;
			break;
		}
		else
		{
			sideX = 16 * check;
			sideY = 9 * check;
			check++;
		}
	} 
	numOfElems = sideX * sideY;
	fieldArr = (fieldvar*)malloc((numOfElems + 1) * sizeof(fieldvar));
	startArr = fieldArr;
	for (int i = 0; i < sideY; i++)
	{
		for (int j = 0; j < sideX; j++)
		{
			moveTo(j, i);
			writeIn(0);
		}
	}
	X = 0;
	Y = 0;

}

template<typename fieldvar>
field<fieldvar>::field(int x, int y)
{
	sideX = x;
	sideY = y;
	numOfElems = sideX * sideY;
	fieldArr = (fieldvar*)malloc((numOfElems + 1) * sizeof(fieldvar));
	startArr = fieldArr;
	for (int i = 0; i < sideY; i++)
	{
		for (int j = 0; j < sideX; j++)
		{
			moveTo(j, i);
			writeIn(0);
		}
	}
	X = 0;
	Y = 0;
}

template<typename fieldvar>
field<fieldvar>::~field()
{
	//for (int i = 0; i < numOfElems+1; i++)
	//{
	//	free(fieldArr[i]);
	//}
	moveTo(0, 0);
	free(fieldArr);
	fieldArr = nullptr;
	startArr = nullptr;
}

//ѕеремещает указатель условно на €чейку выше
template<typename fieldvar>
fieldvar& field<fieldvar>::move_up()
{
	if (Y < 1)
	{
		return readOn();
	}
	else
	{
		moveTo(X, Y - 1);
		return readOn();
	}
}

//ѕеремещает указатель условно на €чейку ниже
template<typename fieldvar>
fieldvar& field<fieldvar>::move_down()
{
	if (Y > (sideY-1))
	{
		return readOn();
	}
	else
	{
		moveTo(X, Y + 1);
		return readOn();
	}
}

//ѕеремещает указатель условно на €чейку левее
template<typename fieldvar>
fieldvar& field<fieldvar>::move_left()
{
	if (X < 1)
	{
		return readOn();
	}
	else
	{
		moveTo(X - 1, Y);
		return readOn();
	}
}

//ѕеремещает указатель условно на €чейку правее
template<typename fieldvar>
fieldvar& field<fieldvar>::move_right()
{
	if (X > (sideX - 1))
	{
		return readOn();
	}
	else
	{
		moveTo(X + 1, Y);
		return readOn();
	}
}

//ѕеремещает указатель условно на €чейку выше-левее по диагонали
template<typename fieldvar>
fieldvar& field<fieldvar>::move_upl()
{
	if (Y < 1 || X < 1)
	{
		return readOn();
	}
	else
	{
		moveTo(X - 1, Y - 1);
		return readOn();
	}
}

//ѕеремещает указатель условно на €чейку выше-правее по диагонали
template<typename fieldvar>
fieldvar& field<fieldvar>::move_upr()
{
	if (Y < 1 || X > sideX - 1)
	{
		return readOn();
	}
	else
	{
		moveTo(X + 1, Y - 1);
		return readOn();
	}
}

//ѕеремещает указатель условно на €чейку ниже-левее по диагонали
template<typename fieldvar>
fieldvar& field<fieldvar>::move_downl()
{
	if (Y > sideY - 1 || X < 1)
	{
		return readOn();
	}
	else
	{
		moveTo(X - 1, Y + 1);
		return readOn();
	}
}

//ѕеремещает указатель условно на €чейку ниже-правее по диагонали
template<typename fieldvar>
fieldvar& field<fieldvar>::move_downr()
{
	if (Y > sideY - 1 || X > sideX - 1)
	{
		return readOn();
	}
	else
	{
		moveTo(X + 1, Y + 1);
		return readOn();
	}
}

//ѕеремещает указатель условно на €чейку в центре пол€
template<typename fieldvar>
fieldvar& field<fieldvar>::moveToCentral()
{
	moveTo(sideX / 2, sideY / 2);
	return readOn();
}
