#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

void displayVillagers(const map<string, tuple<int, string, string>>& villagerData) {
    cout << "Villager details:" << endl;
    for (const auto& pair : villagerData) {
        const auto& [friendship, species, catchphrase] = pair.second;
        cout << pair.first << " [" << friendship << ", " << species << ", " << catchphrase << "]" << endl;
    }
}

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;
    int choice;

    do {
        cout << "1. Add Villager\n"
                "2. Delete Villager\n"
                "3. Increase Friendship\n"
                "4. Decrease Friendship\n"
                "5. Search for Villager\n"
                "6. Exit\n"
                "Enter choices: ";
        cin >> choice;

        if(choice == 1) {
            string name, species, catchphrase;
            int friendship;
            cout << "Villager name: ";
            cin.ignore();
            getline(cin,name);
            cout << "Friendship level: ";
            cin >> friendship;
            cout << "Species: ";
            cin.ignore();
            getline(cin, species);
            cout << "Catchphrase: ";
            getline(cin, catchphrase);
            villagerData[name] = make_tuple(friendship, species, catchphrase);
            cout << name << " added." << endl;
        } else if (choice == 2) {
            string name;
            cout << "Villager name to delete: ";
            cin.ignore();
            getline(cin, name);
            auto it = villagerData.find(name);
            if (it != villagerData.end()) {
                villagerData.erase(it)); {
                    cout << name << "deleted. " << endl;
                }
            } else {
                cout << name "not found. " << endl;
            }
        }

    }

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}