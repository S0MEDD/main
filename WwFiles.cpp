#include "WwFiles.h"

void dataread(string ReadName) {
	std::stringstream output_beffer;
	string MyString;
	vector<Person>Group;
	std::stringstream open_f(ReadName);
	std::getline(open_f, MyString);
	while (open_f)
	{
		if (!open_f.eof())
		{
			std::getline(open_f, MyString);
			std::stringstream my_buffer(MyString);
			Person Temp;
			string Sentences;
			my_buffer >> Sentences;
			Temp.setName(Sentences);
			my_buffer >> Sentences;
			Temp.setSurname(Sentences);
			vector <int> TempV;
			int t;
			while (my_buffer >> t) {
				if (t >= 0 && t <= 10) TempV.push_back(t);
				else cout << "Points inpute error";
			}
			if (TempV.empty()) std::cerr << "semester points dont exist!!!";
			else {

				Temp.setExam(TempV.back());
				TempV.pop_back();
				Temp.setHW(TempV);
				Temp.setFinal(0.4 * (std::accumulate(TempV.begin(), TempV.end(), 0.0) /
					TempV.size()) + 0.6 * Temp.getExam());
				Group.push_back(Temp);
				cout << Temp;
			}
			TempV.clear();
			Temp.setHW(TempV);
			cout << Group.back();
		}
		else break;

	}
	//cout << Group[0]; 
	cout << "If You want rearange data by Names press - 1, Surnames - 2, final point -3:";
	int selection;
	cin.clear();
	cin >> selection;
	cout << selection;

	switch (selection) {
	case 1: sort(Group.begin(), Group.end(), lessName); break;
	case 2: sort(Group.begin(), Group.end(), lessSurname); break;
	default: sort(Group.begin(), Group.end());
	}
	for (auto& B : Group) cout << B;
	
	/*cout << output_beffer.str();
	*/
	
}

