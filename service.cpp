#include "service.h"
#include <algorithm>

int Service::add_pet_service(std::string name, std::string breed, int age, std::string photograph) {
    Pets pet(name, breed, age, photograph);
    int res = repo->add_pet_to_repository(pet);

    if (res == -1)
        return -1;

    // Create ActionAdd and add to undo stack
    Action* action = new ActionAdd(pet, *repo);
    undo_stack.push_back(action);

    // Clear the redo stack
    clear_redo_stack();

    return 0;
}

int Service::remove_pet_service(int index) {
    if (index < 0 || index >= repo->get_repo_length())
        return -1;

    Pets pet = repo->getPetsList()[index];
    int res = repo->remove_pet_from_repository(index);

    if (res == -1)
        return -1;

    // Create ActionRemove and add to undo stack
    Action* action = new ActionRemove(pet, *repo);
    undo_stack.push_back(action);

    // Clear the redo stack
    clear_redo_stack();

    return 0;
}

int Service::update_pet_service(int index, const Pets& new_pet) {
    if (index < 0 || index >= repo->get_repo_length())
        return -1;

    Pets old_pet = repo->getPetsList()[index];
    int res = repo->update_pet_from_repository(index, new_pet);

    if (res == -1)
        return -1;

    // Create ActionUpdate and add to undo stack
    Action* action = new ActionUpdate(old_pet, new_pet, *repo);
    undo_stack.push_back(action);

    // Clear the redo stack
    clear_redo_stack();

    return 0;
}

int Service::verify_if_it_exists(std::string name, std::string breed, int age, std::string photograph) {
    Pets pet(name, breed, age, photograph);
    int position = repo->search_for_a_pet(pet);
    return position == -1 ? -1 : 0;
}

void Service::initialize_repo() {
    add_pet_service("Scooby Doo", "Great Dane", 7, "https://ro.wikipedia.org/wiki/Scooby-Doo_%28personaj%29#/media/Fi%C8%99ier:Scooby-Doo_eats_live_sandwich.JPG");
    add_pet_service("Roach", "Horse", 10, "https://static0.gamerantimages.com/wordpress/wp-content/uploads/2022/07/the-witcher-3-roach-on-rooftop-gwent.jpg?q=50&fit=contain&w=1140&h=&dpr=1.5");
    add_pet_service("Lassie", "Rough Collie", 7, "https://en.wikipedia.org/wiki/Lassie#/media/File:Lassie_and_Tommy_Rettig_1956.JPG");
    add_pet_service("Max", "German Shepard", 4, "https://t1.gstatic.com/licensed-image?q=tbn:ANd9GcQnHykeJT7z-1d4NQBZBAIdr3QwHmCR1UBpo6JYVPy3M3mSsr4M60gX4nmC3iZ0p_6k");
    add_pet_service("Kuma", "Australian shepherd dog", 6, "https://m.media-amazon.com/images/M/MV5BMTY3Nzg0NDExNF5BMl5BanBnXkFtZTgwMDM4MTg1NDE@._V1_.jpg");
    add_pet_service("Cupcake", "Rottweiler", 4, "https://i.pinimg.com/564x/2b/a7/87/2ba7873c596ecd754179911a21097684.jpg");
    add_pet_service("ThunderLord the destroyer of worlds", "German Shepard", 4, "https://media1.tenor.com/m/wtsy01hLYckAAAAd/i-have-no-enemies-enemies.gif");
    add_pet_service("Doge", "Akita", 9, "https://www.researchgate.net/publication/359456368/figure/fig1/AS:11431281103138195@1669617009814/A-blank-doge-meme-template.png");
    add_pet_service("Max", "Siberian Husky", 2, "https://cdn.britannica.com/84/232784-050-1769B477/Siberian-Husky-dog.jpg");
    add_pet_service("Casper", "Great Pyrenees", 10, "https://people.com/thmb/alcuRy1218oBeyDtq31oXKLUxZk=/750x0/filters:no_upscale():max_bytes(150000):strip_icc():focal(749x0:751x2):format(webp)/decatur-sheepdog-casper-coyotes-attack-120922-1-654e1b73a57845a7b969f1e0d984c250.jpg");
}

std::vector<Pets> Service::get_pets_by_breed_and_age(std::string breed, int age) {
    std::vector<Pets> pet_list = get_all_pets();
    std::vector<Pets> pets_by_age_and_breed;

    auto satisfies_condition = [&](const Pets& pet) {
        return (breed == "" || pet.getBreed() == breed) && pet.getAge() <= age;
    };

    std::copy_if(pet_list.begin(), pet_list.end(), std::back_inserter(pets_by_age_and_breed), satisfies_condition);

    return pets_by_age_and_breed;
}

void Service::undo() {
    if (!undo_stack.empty()) {
        Action* action = undo_stack.back();
        action->execute_undo();
        undo_stack.pop_back();
        redo_stack.push_back(action);
    }
}

void Service::redo() {
    if (!redo_stack.empty()) {
        Action* action = redo_stack.back();
        action->execute_redo();
        redo_stack.pop_back();
        undo_stack.push_back(action);
    }
}
