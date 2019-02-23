#include <clocale>
#include <iostream>
using namespace std;

class Triangle
{
public:
	double a, b, c;

	Triangle(); // Конструктор по умолчанию
	Triangle(const Triangle &t); // Конструктор копирования
	Triangle(double _a, double _b, double _c);// Конструктор инициализации
	
	int Exist(const Triangle& cmp);
	int Type(const Triangle& cmp);
	double P(const Triangle& cmp);
	double S(const Triangle& cmp);
};

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int j, h;
	double a0, b0, c0, S0, P0;
	Triangle c1, E, T, S, P;
	Triangle Sdf(2, 5, 6);
	cout << "Введите сторону а: ";
	cin >> a0;
	c1.a = a0;
	cout << "Введите сторону b: ";
	cin >> b0;
	c1.b = b0;
	cout << "Введите сторону c: ";
	cin >> c0;
	c1.c = c0;
	j = E.Exist(c1);
	if (j!=0) cout << "Треугольник существует"<<"\n";
	else cout << "Треугольник не существует"<<"\n";
	h = T.Type(c1);
	if (j == 0) cout << "-"<<"\n";
	else
	{
	if (h == 1) cout << "Треугольник остроугольный" <<"\n";
	else if (h == 2) cout << "Треугольник тупоугольный"<<"\n";
	else if (h == 3) cout << "Треугольник прямоугольный"<<"\n";
	}
	P0 = P.P(c1);
	if (j == 0) cout << "Периметр треугольника -"<<"\n";
	else
	cout << "Периметр треугольника = " << P0<<"\n";
	S0 = S.S(c1);
	if (j == 0) cout << "Площадь треугольника -"<<"\n";
	else
	cout << "Площадь треугольника = " << S0<<"\n";
	getchar();
	getchar();
}

Triangle::Triangle()
{
	a = 0.0; b = 0.0; c = 0.0;
}

int Triangle::Exist(const Triangle & cmp)
{
	int res;
	if ((cmp.a + cmp.b > cmp.c) && (cmp.a + cmp.c > cmp.b) && (cmp.b + cmp.c > cmp.a)) res = 1;
	else res = 0;
	return res;
}
int Triangle::Type(const Triangle & cmp)
{
	int res;
	if ((cmp.a*cmp.a + cmp.b*cmp.b > cmp.c*cmp.c) && (cmp.a*cmp.a + cmp.c*cmp.c > cmp.b*cmp.b) && (cmp.b*cmp.b + cmp.c*cmp.c > cmp.a*cmp.a)) res = 1;
	else if ((cmp.a*cmp.a + cmp.b * cmp.b < cmp.c * cmp.c) || (cmp.a*cmp.a + cmp.c * cmp.c < cmp.b * cmp.b) || (cmp.b*cmp.b + cmp.c * cmp.c < cmp.a * cmp.a)) res = 2;
	else res = 3;
	return res;
}

double Triangle::P(const Triangle & cmp)
{
	double res;
	res = cmp.a + cmp.b + cmp.c;
	return res;
}
double Triangle::S(const Triangle & cmp)
{
	double res, p;
	p = (cmp.a + cmp.b + cmp.c) / 2;
	res = sqrt(p*(p - cmp.a)*(p - cmp.b)*(p - cmp.c));
	return res;
}
Triangle::Triangle(const Triangle &t)
{
	a = t.a;
	b = t.b;
	c = t.c;
}
Triangle::Triangle(double _a, double _b, double _c)
{
	a = _a;
	b = _b;
	c = _c;
}