#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdio.h>

using namespace std;

// out -> write
// in -> read
// app -> append

void file_txt_write() {
	//ofstream fout("hakuna.txt", ios::out);
	ofstream fout("hakuna.txt", ios_base::app);

	if (!fout) {
		throw "File not found";
	}

	if (fout.is_open()) {
		fout << "Salam millet" << endl;
	}
	else {
		throw "File not open exception";
	}

	fout.close();
}

void file_txt_read() {
	ifstream fin("hakuna.txt", ios::in);

	if (fin.is_open()) {
		string value;
		//fin >> value;
		//getline(fin, value);

		while (!fin.eof())
		{
			getline(fin, value);
			cout << value << endl;
		}
	}

	fin.close();
}



void file_binary_write() {
	ofstream fout("arr.bin", ios::binary);
	int arr[5]{ 10,20,3,4,5 };

	if (fout.is_open()) {
		fout.write((char*)arr, sizeof(int) * 5);
	}
	fout.close();
}

void file_binary_read() {
	ifstream fin("arr.bin", ios::binary);

	int arr[5]{};

	if (fin.is_open()) {
		fin.read((char*)arr, sizeof(int) * 5);
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
}





class Contact {
public:
	string name;
	string surname;
	string number;

	Contact() = default;
	Contact(const string& name, const string& surname,
		const string& number)
	{
		this->name = name;
		this->surname = surname;
		this->number = number;
	}
};


void file_txt_write_object() {
	Contact contact("Tural", "Tural", "1234567");

	ofstream fout("contact.txt", ios::app);
	fout.setf(ios::left);

	if (fout.is_open()) {
		fout << setw(20) << contact.name << " "
			<< setw(20) << contact.surname << " "
			<< setw(20) << contact.number << endl;
	}

	fout.close();
}




void file_txt_read_object() {
	Contact contact;

	ifstream fin("contact.txt");

	if (fin.is_open()) {

		while (!fin.eof())
		{
			fin >> contact.name;
			fin >> contact.surname;
			fin >> contact.number;

			cout << contact.name << endl;
			cout << contact.surname << endl;
			cout << contact.number << endl;
		}

	}

	fin.close();
}





void find(const string& name) {
	Contact contact;

	ifstream fin("contact.txt");

	if (fin.is_open()) {
		bool isFind = false;
		while (!fin.eof())
		{
			fin >> contact.name;
			fin >> contact.surname;
			fin >> contact.number;

			if (contact.name == name) {
				cout << contact.name << endl;
				cout << contact.surname << endl;
				cout << contact.number << endl;
				isFind = true;
				break;
			}
		}

		if (!isFind) cout << "Not found" << endl;

	}

	fin.close();
}

void deleteContact(const string& name)
{
	Contact contact;

	ifstream fin("contact.txt");

	ofstream fout("tmp.txt", ofstream::app);


	if (fin.is_open()) {
		bool isFind = false;
		while (!fin.eof())
		{
			fin >> contact.name;
			fin >> contact.surname;
			fin >> contact.number;

			fout.setf(ios::left);
			if (contact.name == name) isFind = true;
			else {
				if (contact.name != "") fout << setw(20) << contact.name << " "
					<< setw(20) << contact.surname << " "
					<< setw(20) << contact.number << endl;
				contact.name = "";
			}
		}

		if (!isFind) cout << "Not found" << endl;

	}
	fin.close();
	fout.close();
	remove("contact.txt");
	{
		ofstream fout("contact.txt", ofstream::app);

		ifstream fin("tmp.txt");
		if (fin.is_open()) {
			bool isFind = false;
			while (!fin.eof())
			{
				fin >> contact.name;
				fin >> contact.surname;
				fin >> contact.number;

				fout.setf(ios::left);
				if (contact.name != "") fout << setw(20) << contact.name << " "
					<< setw(20) << contact.surname << " "
					<< setw(20) << contact.number << endl;
				contact.name = "";
			}
		}
		fin.close();
		remove("tmp.txt");
	}
}

int main() {
	//file_txt_write();
	//file_txt_read();

	//file_binary_write();
	//file_binary_read();


	//file_txt_write_object();
	//file_txt_read_object();

	//find("Nicat");

	deleteContact("Nicat");

	return 0;
}