#include<iostream>
#include<list>
using namespace std;

/*Дано: два манипулятора, которые описываются стартовыми центрами O1 и O2 и радиусом их действия R1 и R2 в декартовой системе координат.Радиус действия не изменяется в течении работы программы. Также дан массив точек, где лежат детали P1…Pn.
Выведете две строки: какие точки обойдет каждый манипулятор
Имейте в виду,что до детали должен дойти “оптимальный” манипулятор на текущей итерации процесса. P.S Оптимальность считаем по длине до точки. Радиус не учитываем.
Пример, есть массив точек:
{1, 3}, {2, 1.41}, {0.2, -7} ,{-5, -1} , {0, 9}
Манипуляторы на старте: M1 ( {0, 0} , 4 ) M2 ({2,1}, 3)
*/

class Distance
{
	double xp, yp;
	double xm, ym;

public:
	Distance();
	Distance(double, double, double, double);
	void SetP(double xp, double yp)
	{
		this->xp = xp;
		this->yp = yp;
	}
	void SetM(double xm, double ym)
	{
		this->xm = xm;
		this->ym = ym;
	}
	double LengthToPoint()
	{
		return (xm - xp) * (xm - xp) + (ym - yp) * (ym - yp);
	}

	double GetX() { return xp; }
	double GetY() { return yp; }
};

Distance::Distance()
{
	xp = yp = xm = ym = 0;
}

Distance::Distance(double xp, double yp, double xm, double ym)
{
	this->xp = xp;
	this->yp = yp;
	this->xm = xm;
	this->ym = ym;
}


int main()
{
	setlocale(LC_ALL, "rus");
	double xm_1, ym_1, xm_2, ym_2, xp, yp;


	cout << "введите начальное положение манипулятора 1:" << endl;
	cout << "x = ";
	cin >> xm_1;
	cout << "y = ";
	cin >> ym_1;

	cout << "введите начальное положение манипулятора 2:" << endl;
	cout << "x = ";
	cin >> xm_2;
	cout << "y = ";
	cin >> ym_2;

	Distance dst[10];
	list <Distance>manip_1;
	list < Distance> manip_2;
	for (int i = 0; i < 10; i += 2)
	{
		cout << "Введите координаты точки №" << i / 2 + 1 << ':' << endl << "x = ";
		cin >> xp;
		cout << "y = ";
		cin >> yp;
		dst[i].SetP(xp, yp);
		dst[i].SetM(xm_1, ym_1);
		dst[i + 1].SetP(xp, yp);
		dst[i + 1].SetM(xm_2, ym_2);
		/*поскольку в условии задачи не указано как реагировать, если расстояния от манипуляторов до точки окажутся
		равны, то буду полагать, что каждый раз они отличаются, а, значит, прописывать условие равенства не нужно*/
		if (dst[i].LengthToPoint() < dst[i + 1].LengthToPoint())
		{
			manip_1.push_back(dst[i]);
			xm_1 = xp;  ym_1 = yp;
		}
		else {
			manip_2.push_back(dst[i + 1]);
			xm_2 = xp;  ym_2 = yp;
		}
	}
	//Вывожу две строки: какие точки обойдет каждый манипулятор
	cout << "манипулятор №1:   ";
	for (auto i = manip_1.begin(); i != manip_1.end(); ++i) {
		auto temp = *i;
		{cout << '{' << temp.GetX() << ", " << temp.GetY() << "}   ";
		}
		cout << endl;
		cout << "манипулятор №2:   ";
		for (auto i = manip_2.begin(); i != manip_2.end(); ++i) {
			auto temp = *i;
			cout << '{' << temp.GetX() << ", " << temp.GetY() << '}' << "   ";
		}
		cout << endl;
	}
}