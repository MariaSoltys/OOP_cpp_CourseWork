#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;



class Person
{
protected:

	string name, surname, gen, fatherhood, bithdate;

public:
	
	Person() //конструктор
	{
		cout << "Людину створено!" << endl << "Введiть iм'я, прiзвище i по батьковi: ";
		cin >> name;
		cin >> surname;
		cin >> fatherhood;
		cout << endl << "Введiть дату народження: ";
		cin >> bithdate;
		cout << endl << "Введiть стать: ";
		cin >> gen;
	}

	Person(const Person& var) //конструктор копіювання
	{
		this->name = var.name;
		this->surname = var.surname;
		this->fatherhood = var.fatherhood;
		this->bithdate = var.bithdate;
		this->gen = var.gen;
	}

	void SetName(string var) 
	{
		name = var;
		cout << "Людина змiнила iм'я на " << name;
	}

	void SetSurame(string var)
	{
		surname = var;
		cout << "Людина змiнила прiзвище на " << surname;
	}

	string GetName()
	{
		return (name);
	}

	string GetSurname()
	{
		return (surname);
	}

	string GetDate()
	{
		return (bithdate);
	}

	string GetGender()
	{
		return (gen);
	}

	Person& operator = (Person &var) //перегрузка =
	{
		this->name = var.name;
		this->surname = var.surname;
	}

	Person& operator << (Person& var) //перегрузка <<
	{
		cout << "Name: " << var.name 
			<< endl << "Surname: " << var.surname 
			<< endl << "Fatherhood: " << var.fatherhood 
			<< endl << "Date of birth: " << var.bithdate 
			<< endl << "Gender: " << var.gen << endl;
		return var;
	}

	Person& operator >> (Person& var) //перегрузка >>
	{
		cout << "Змiнюємо iм`я i прiзвище: " << endl;
		cin >> var.name;
		cin >> var.surname;
		return var;
	}

	Person& operator () (Person& var) //перегрузка ()
	{
		this->name = var.name;
		this->surname = var.surname;
	}


	virtual void Reading() //віртуальна функція
	{
		cout << "Людину звуть " << surname << " " << name << endl;
	}

	~Person()  //деструктор
	{

	}

};

class Coworker: public Person //похідний клас
{
protected:
	int sum, tubnum, oklad, stage, w_hours, d_p_h;
public:
	Coworker() //конструктор
	{
		cout << name << " тепер спiвробiтник!" << endl;
		cout << endl << "Введiть номер: ";
		cin >> tubnum;
		cout << endl << "Введiть оклад: ";
		cin >> oklad;
		cout << endl << "Введiть стаж роботи: ";
		cin >> stage;
		cout << endl << "Введiть вiдпрацьованi години: ";
		cin >> w_hours;
		cout << endl << "Введiть оплату: ";
		cin >> d_p_h;
	}

	void print() //вивід інформації
	{
		cout << name << " має табельний номер " << tubnum
			<< ", оклад " << oklad << ", стаж роботи " << stage
			<< ", працює " << w_hours << " годин, i заробляє " << d_p_h << endl;
		sum = w_hours * d_p_h;
	}

	void SetWH (int var)
	{
		this->w_hours = var;
	}

	int GetWH() 
	{
		return w_hours;
	}

	void SetSum(int var)
	{
		this->sum = var;
	}

	int GetSum()
	{
		return sum;
	}

	void Reading() override //віртуальна функція
	{
		cout << "Людину звуть " << this->surname << " " << this->name 
			<< " i вона має табельний номер " << this->tubnum << endl;
	}

	~Coworker() {}
};

/*class Salary : public Coworker //обраховує зарплату
{
protected:
	int sum;
public:

	void SalaryCount() 
	{
		cout << "Спiвробітник " << name << " " << surname
			<< " прийшов по зарплату. " << endl;
		sum = w_hours * d_p_h;
		cout << "Вiн заробив " << sum << " доларiв" << endl;
	}

};*/

template <typename T>
class Iterator;

template<typename T>
class Salary {
protected:
	int sum;
public:
	typedef Iterator<T> iterator;
	Coworker* workArr;
	int length;
	
	Salary() //конструктор за замовчуванням
	{
		workArr = new Coworker[0];
		length = 0;
	}
	
	Salary(int n) //конструктор ініціалізації
	{
		length = n;
		workArr = new Coworker[length];
	}
	
	~Salary() //деструктор
	{
		delete[] workArr;
		length = 0;
	}
	
	Iterator<T> begin() //функція для повернення початкового елементу масиву
	{
		return Iterator<T>(workArr);
	}
	
	Iterator<T> end() //функція для повернення кінцевого елементу масиву
	{
		return Iterator<T>(workArr + length);
	}
	
	Coworker& operator [](int n) //перевантажений оператор повернення елемента масиву
	{
		return workArr[n];
	}
	
	void AddElement() //функція зчитування та заповнення полів даних об’єкта.
	{
		for (int i = 0; i < length; i++) {
			string name, surname;
			int w_hours, d_p_h;
			cout << "\n" << i + 1 << ") Вкажiть данi працiвника: \nIм'я та прiзвище: ";
			cin >> name;
			cin >> surname;
			cout << "Скiльки годин вiн працює: ";
			cin >> w_hours;
			cout << "Оклад: ";
			cin >> d_p_h;
			cout << "Оплата: ";
			sum = w_hours * d_p_h;
			cout << sum << endl;
			workArr[i].inputvalues(name, surname, w_hours, sum);
		}
	}

	friend ostream& operator<< (ostream& s, Coworker& n);

};


template<typename T>
class Iterator
{
private:
	T* current;
public:
	 
	Iterator(T* curr) //конструктор
	{ 
		current = curr;
	}
	
	Iterator& operator ++() //перевантажений оператор ++ (переходить до наступного елемента)
	{ 
		++current;
		return *this;
	}
	
	T& operator *() //оператор розіменування
	{ 
		return *current;
	}
	
	bool operator ==(const Iterator& other) //перевантажений оператор ==
	{
		return current == other.current;
	}
	
	bool operator !=(const Iterator& other) //перевантажений оператор !=
	{
		return !(*this == other);
	}
};

ostream& operator<< (ostream& s, Coworker& n) 
{
	s << "Iм'я:" << n.GetName() << endl;
	s << "Прізвище: " << n.GetSurname() << endl;
	s << "Робочі години: " << n.GetWH() << endl;
	s << "Оплата: " << n.GetSum() << endl;
	return s;
}

int main()
{
	setlocale(LC_ALL, "RU");
	
	int count;
	cout << "Що Ви хочете зробити?" << "\n1) Найняти робiтників" << "\t2) Видати зарплату" << endl;
	cin >> count;
	if (count == 1)
	{
		Coworker Human;
		Human.operator>>(Human);
		Coworker *b = &Human;
		Human.Reading();
		Human.operator<<(Human);
		Human.print();
		Coworker Human2;
	}
	else if (count == 2)
	{
		cout << endl << endl;
		int s;
		cout << "Скiльки робiтників отримують зарплату: ";
		cin >> s;
		Salary<Coworker> arr(s);//створення масиву об'єктів класу
		//arr.AddElement();
		cout << "Ви оплатили працю наступних працiвникiв:";
		for (Salary<Coworker>::iterator iter = arr.begin(); iter != arr.end(); ++iter) 
		{
			cout << *iter << endl << endl; //вивід по елементу масива через ітератор
		}

	}
	else 
	{
		cout << "Ви повиннi ввести 1 або 2 \nСпробуйте ще раз";
	}
}
