
#include "RepositoryManager.h"

using namespace std;

void RepositoryManager::print_options_repo_type() {
    cout << "What kind of repository do you want to use?\n";
    cout << "1. Memory Repository\n";
    cout << "2. Text File Repository\n";
    cout << "3. CSV File Repository\n";
    cout << "4. HTML File Repository \n";
}

int RepositoryManager::start_repo_type() {
    int option;

    while (true)
    {
        RepositoryManager::print_options_repo_type();
        cout << "Enter your option:\n>";
        cin >> option;
        cout<<"." << option <<".";
        if(option < 1 || option > 4)
            cout << " Invalid option!\n";
        else
        {
            return option;
        }
    }
}

void RepositoryManager::print_options_to_load() {
    cout << "How would you like your repository be?\n";
    cout << "1. Load the existing data from the file (or in the case of the memory repo"
            "start with an empty repository)\n";
    cout << "2. Don't load but start with 10 entries in the repository\n";
}

int RepositoryManager::start_options_to_load() {
    int option;

    while(true)
    {
        RepositoryManager::print_options_to_load();
        cout << "Enter your option::\n>";
        cin >> option;
        if(option != 1 && option != 2)
            cout << "Invalid option!\n";
        else
        {
            return option;
        }
    }
}
