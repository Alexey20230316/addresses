#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>

class address {

private:
	std::string city;
	std::string street;
	int house;
	int flat;

public:
	// геттеры
	std::string get_city()const {
		return city;
	}	
	std::string get_street()const {
		return street;
	}	
	int get_house()const {
		return house;
	}	
	int get_flat()const {
		return flat;
	}

	//сеттеры
	void set_city(std::string citi) {
		this->city = citi;
	}	
	void set_street(std::string street) {
    	this->street = street;
	}	
	void set_house(int house) {
		this->house = house;
	}	
	void set_flat(int flat) {
		this->flat = flat;
	}
	
	//конструктор по умолчанию
	address() {
		city = "No name ";
    	street = "No name ";
	    house = 0;
		flat = 0;
	}

};


int main() {

	setlocale(LC_ALL, "Russian");

	//address t;
	//t.print();


	std::string path_in = "in.txt";  // имя файла присваиваем переменной типа стринг
	std::ifstream fin;              //  создаем обьект fin на чтение
	fin.open(path_in);             //  вызов метода  open для открытия файла in.txt.

	std::string path_out = "out.txt";   // имя файла присваиваем переменной типа стринг
	std::ofstream fout;                //  создаем обьект fout на запись
	fout.open(path_out);              //  вызов метода  open для открытия файла out.txt.

	

	if (!(fin.is_open() || fout.is_open()))      //  is_open  возвращает  true или false
	{        
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
	else
	{
		int n = 0;
		fin >> n;
		fout << n << "\n";
		
		address* arr = new address[n];

		for (int i = 0; i < n; i++)
		{
			std::string b;
			fin >> b;
			arr[i].set_city(b);
			fin >> b;
			arr[i].set_street(b);
			int c = 0;
			fin >> c;
			arr[i].set_house(c);
			fin >> c;
			arr[i].set_flat(c);
		}

		for (int i = 0; i < n; i++)
		{
			fout << arr[n - (1 + i)].get_city() << ", ";
			fout << arr[n - (1 + i)].get_street() << ", ";
			fout << arr[n - (1 + i)].get_house() << ", ";
			fout << arr[n - (1 + i)].get_flat() << "\n";	
		}
		delete[]arr;
	}

	fin.close();
	fout.close();

}