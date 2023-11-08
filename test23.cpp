#include "Mylib1.h"
#include "WwFiles.h"

int main()
{
     cout << "Use automatic user generation (1),read from file(2) or turn on manual input of all data";
    int select1; cin >> select1;
    switch (select1) {
    case 1: {
        cout << "How many person belongs to the Group?";
        int PN; cin >> PN;
        vector<Person> Group(PN);

        cout << "If you want rearenge data by names press1, Surnames - 2, Fimalpoint -3";
        int selection;
        cin >> selection;
        switch (selection) {
    case 1: sort(Group.begin(), Group.end(), lessName); break;
    case 2: sort(Group.begin(), Group.end(), lessSurname); break;
    default: sort(Group.begin(), Group.end());
    }

 for (auto& B : Group) cout << B;
        break;
    }
    case 2: {
        
              string name;
              system("dir *.txt");
              std::cout << "Inpute file name:";
              cin >> name;
              dataread(name); break;
          }
        default: {
            vector<Person> Group;
            for (int j = 0; j < 3; j++) {
                Person temp;
                cin >> temp;
                Group.push_back(temp);
                temp.~Person();
                //temp cleatr();
            }

            cout << "If you want rearenge data by names press1, Surnames - 2, Fimalpoint -3 ";
            int selection;
            cin >> selection;
            switch (selection) {
            case 1: sort(Group.begin(), Group.end(), lessName); break;
            case 2: sort(Group.begin(), Group.end(), lessSurname); break;
            default: sort(Group.begin(), Group.end());
            }
            for (auto& B : Group) cout <<B;
        }
               }
    
    
        system("pause");
}
