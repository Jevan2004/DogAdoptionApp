//#include "tests.h"
//#include <iostream>
//
//void Tests::testPetsClass() {
//    // Test default constructor
//    Pets dog1;
//    assert(dog1.getName() == "");
//    assert(dog1.getBreed() == "");
//    assert(dog1.getAge() == 0);
//    assert(dog1.getPhotograph() == "");
//
//    // Test parameterized constructor
//    Pets dog2("Max", "Golden Retriever", 3, "https://example.com/max_photo.jpg");
//    assert(dog2.getName() == "Max");
//    assert(dog2.getBreed() == "Golden Retriever");
//    assert(dog2.getAge() == 3);
//    assert(dog2.getPhotograph() == "https://example.com/max_photo.jpg");
//
//    // Test copy constructor
//    Pets dog3 = dog2;
//    assert(dog3.getName() == "Max");
//    assert(dog3.getBreed() == "Golden Retriever");
//    assert(dog3.getAge() == 3);
//    assert(dog3.getPhotograph() == "https://example.com/max_photo.jpg");
//
//    assert(dog2 == dog3);
//    // Test assignment operator
//    Pets dog4;
//    dog4 = dog2;
//    assert(dog4.getName() == "Max");
//    assert(dog4.getBreed() == "Golden Retriever");
//    assert(dog4.getAge() == 3);
//    assert(dog4.getPhotograph() == "https://example.com/max_photo.jpg");
//    assert(dog4.getNumberOfInstances() == 3); // This line is covered only by this test
//
//    // Test destructor
//    {
//        Pets dog5("Buddy", "Labrador", 5, "https://example.com/buddy_photo.jpg");
//    }
//    assert(Pets::getNumberOfInstances() == 3); // Only 3 instances should exist after the scope ends
//
//    // Test toString() method
//    std::string expectedString = "Name:Max| Breed:Golden Retriever|Age:3|Photography:https://example.com/max_photo.jpg\n";
//    assert(dog4.toString() == expectedString);
//
//    // Test copy constructor
//    Pets dog5("Buddy", "Labrador", 5, "https://example.com/buddy_photo.jpg");
//    Pets dog6 = dog5;
//    assert(dog6.getName() == "Buddy");
//    assert(dog6.getBreed() == "Labrador");
//    assert(dog6.getAge() == 5);
//    assert(dog6.getPhotograph() == "https://example.com/buddy_photo.jpg");
//}
//
////void Tests::testDynamicVector() {
////    // Test default constructor
////    std::vector<int> vec;
////    assert(vec.size() == 0);
////
////    // Test adding elements
////    vec.push_back(10);
////    vec.push_back(20);
////    vec.push_back(30);
////    assert(vec.size() == 3);
////    assert(vec[0] == 10);
////    assert(vec[1] == 20);
////    assert(vec[2] == 30);
////    vec = vec;
////
////    // Test iterator
////    int sum = 0;
////    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
////        sum += *it;
////    }
////    assert(sum == 60); // Sum of elements should be 10 + 20 + 30 = 60
////
////    // Test copy constructor
////    std::vector<int> vecCopy(vec);
////    assert(vecCopy.size() == 3);
////    assert(vecCopy[0] == 10);
////    assert(vecCopy[1] == 20);
////    assert(vecCopy[2] == 30);
////
////    // Test assignment operator
////    std::vector<int> vecAssign;
////    vecAssign = vec;
////    assert(vecAssign.size() == 3);
////    assert(vecAssign[0] == 10);
////    assert(vecAssign[1] == 20);
////    assert(vecAssign[2] == 30);
////
////    // Test resizing
////    std::vector<int> vecResize(2);
////    vecResize.push_back(40);
////    vecResize.push_back(50);
////    vecResize.push_back(60); // This will trigger resizing
////    assert(vecResize.size() == 3);
////    assert(vecResize[0] == 40);
////    assert(vecResize[1] == 50);
////    assert(vecResize[2] == 60);
////
////    // Test removing elements
////    std::vector<int> vec1;
////    vec1.push_back(10);
////    vec1.push_back(20);
////    vec1.push_back(30);
////
////    vec1.erase(vec1.begin() , vec1.begin() + 2);
////    // Remove element at index 1 (value: 20)
////
////
////
////    assert(vec1.size() == 2);
////    assert(vec1[0] == 10);
////    assert(vec1[1] == 30);
////
////    // Test removing all elements
////    vec1.erase(vec1.begin()); // Remove element at index 0 (value: 10)
////    vec1.erase(vec1.begin()); // Remove element at index 0 (value: 30)
////
////    assert(vec1.size() == 0);
////
////    // Test removing from an empty vector
////    //assert(vec1.remove(0) == -1); // Attempt to remove from an empty vector, no effect expected
////    assert(vec1.size() == 0);
////}
//
//void Tests::testRepository() {
//    MemoryRepository repo;
//
//    assert(repo.get_repo_length() == 0);
//
//    Pets dog1("Max", "Golden Retriever", 3, "https://example.com/max_photo.jpg");
//
//    repo.add_pet_to_repository(dog1);
//    assert(repo.get_repo_length() == 1);
//
//    Pets dog2("Buddy", "Labrador", 5, "https://example.com/buddy_photo.jpg");
//
//    repo.add_pet_to_repository(dog2);
//
//    assert(repo.get_repo_length() == 2);
//
//    Pets dog3 = dog1;
//
//    assert(repo.add_pet_to_repository(dog3) == -1);
//    assert(repo.search_for_a_pet(dog2) == 1);
//
//    Pets dog4 = repo.get_pet_from_given_position(1);
//    assert(dog4 == dog2);
//
//    bool exceptionThrown = false;
//
//    try {
//        dog4 = repo.get_pet_from_given_position(5);
//    }
//    catch(std::out_of_range)
//    {
//        exceptionThrown = true;
//    }
//
//    assert(exceptionThrown);
//    assert(repo.get_repo_length() == 2);
//
//    assert(repo.remove_pet_from_repository(2) == -1);
//    assert(repo.remove_pet_from_repository(0) == 0);
//    assert(repo.get_repo_length() == 1);
//
//    dog4 = repo.get_pet_from_given_position(0);
//
//    assert(dog4.getName() == "Buddy");
//    assert(dog4.getBreed() == "Labrador");
//    assert(dog4.getAge() == 5);
//    assert(dog4.getPhotograph() == "https://example.com/buddy_photo.jpg");
//
//    assert(repo.remove_pet_from_repository(1) == -1);
//    assert(repo.remove_pet_from_repository(0) == 0);
//    assert(repo.get_repo_length() == 0);
//
//    exceptionThrown = false;
//
//    try {
//        dog4 = repo.get_pet_from_given_position(0);
//    }
//    catch(std::out_of_range)
//    {
//        exceptionThrown = true;
//    }
//    assert(exceptionThrown);
//
//    repo.add_pet_to_repository(dog1);
//    repo.add_pet_to_repository(dog2);
//    assert(repo.get_repo_length() == 2);
//
//    Pets dog5("Scooby Doo", "Great Dane", 7,
//              "https://ro.wikipedia.org/wiki/Scooby-Doo_%28personaj%29#/media/Fi%C8%99ier:Scooby-Doo_eats_live_sandwich.JPG");
//
//    assert(repo.update_pet_from_repository(2, dog5) == -1);
//    assert(repo.update_pet_from_repository(1, dog5) == 0);
//    assert(repo.get_repo_length() == 2);
//
//    Pets new_dog = repo.get_pet_from_given_position(1);
//
//    assert(new_dog.getName() == "Scooby Doo");
//    assert(new_dog.getBreed() == "Great Dane");
//    assert(new_dog.getAge() == 7);
//    assert(new_dog.getPhotograph() == "https://ro.wikipedia.org/wiki/Scooby-Doo_%28personaj%29#/media/Fi%C8%99ier:Scooby-Doo_eats_live_sandwich.JPG");
//
//    std::vector<Pets>& list_of_all_pets = repo.getPetsList();
//
//    assert(list_of_all_pets.size() == 2);
//    assert(list_of_all_pets[0] == dog1);
//    assert(list_of_all_pets[1] == new_dog);
//
//}
//
//void Tests::testService() {
//
//    MemoryRepository repo;
//    Service service(repo);
//
//    assert(service.add_pet_service("Buddy", "Labrador", 5, "https://example.com/buddy_photo.jpg") == 0);
//    assert(service.get_repo_length() == 1);
//
//    assert(service.add_pet_service("Buddy", "Labrador", 5, "https://example.com/buddy_photo.jpg") == -1);
//
//    assert(service.add_pet_service("Max", "Golden Retriever", 3, "https://example.com/max_photo.jpg") == 0);
//    assert(service.get_repo_length() == 2);
//
//    Pets dog5("Scooby Doo", "Great Dane", 7,
//              "https://ro.wikipedia.org/wiki/Scooby-Doo_%28personaj%29#/media/Fi%C8%99ier:Scooby-Doo_eats_live_sandwich.JPG");
//
//    assert(service.verify_if_it_exists("Scooby Doo", "Great Dane", 7,
//                                       "https://ro.wikipedia.org/wiki/Scooby-Doo_%28personaj%29#/media/Fi%C8%99ier:Scooby-Doo_eats_live_sandwich.JPG") == -1);
//    assert(service.update_pet_service(2, dog5) == -1);
//    assert(service.update_pet_service(0, dog5) == 0);
//
//    Pets new_dog;
//    new_dog = repo.get_pet_from_given_position(0);
//    assert(new_dog.getName() == "Scooby Doo");
//    assert(new_dog.getBreed() == "Great Dane");
//    assert(new_dog.getAge() == 7);
//    assert(new_dog.getPhotograph() == "https://ro.wikipedia.org/wiki/Scooby-Doo_%28personaj%29#/media/Fi%C8%99ier:Scooby-Doo_eats_live_sandwich.JPG");
//
//    assert(service.verify_if_it_exists("Buddy", "Labrador", 5, "https://example.com/buddy_photo.jpg") == -1);
//    assert(service.verify_if_it_exists("Scooby Doo", "Great Dane", 7,
//                                       "https://ro.wikipedia.org/wiki/Scooby-Doo_%28personaj%29#/media/Fi%C8%99ier:Scooby-Doo_eats_live_sandwich.JPG") == 0);
//
//
//    assert(service.remove_pet_service(2) == -1);
//    assert(service.remove_pet_service(0) == 0);
//
//    assert(service.get_repo_length() == 1);
//
//    Pets new_dog1 = repo.get_pet_from_given_position(0);
//    assert(new_dog1.getName() == "Max");
//    assert(new_dog1.getBreed() == "Golden Retriever");
//    assert(new_dog1.getAge() == 3);
//    assert(new_dog1.getPhotograph() == "https://example.com/max_photo.jpg");
//
//    bool exceptionThrown = false;
//    Pets dog4;
//    try {
//        dog4 = repo.get_pet_from_given_position(1);
//    }
//    catch(std::out_of_range)
//    {
//        exceptionThrown = true;
//    }
//    assert(exceptionThrown);
//
//    service.initialize_repo();
//    assert(service.get_repo_length() == 11);
//
//    assert(service.get_position_of_pet(new_dog1) != -1);
//
//    std::vector<Pets> pets = service.get_all_pets();
//    assert(pets.size() == 11);
//
//}
//
//void Tests::testAdoptionListRepo() {
//    AdoptionListRepo repo;
//
//    // Test adding pets to the adoption list
//    Pets pet1("Max", "Golden Retriever", 3, "https://example.com/max_photo.jpg");
//    Pets pet2("Buddy", "Labrador", 5, "https://example.com/buddy_photo.jpg");
//
//    repo.add_pet(pet1);
//    repo.add_pet(pet2);
//
//    std::vector<Pets> adoptionList = repo.get_adoption_list();
//
//    // Check if the adoption list contains the added pets
//    assert(adoptionList.size() == 2);
//    assert(adoptionList[0] == pet1);
//    assert(adoptionList[1] == pet2);
//}
//
//void Tests::testAdoptionListService() {
//    AdoptionListRepo repo;
//    AdoptionListService service(repo);
//
//    // Test adding pets to the adoption list via the service
//    Pets pet1("Max", "Golden Retriever", 3, "https://example.com/max_photo.jpg");
//    Pets pet2("Buddy", "Labrador", 5, "https://example.com/buddy_photo.jpg");
//
//    service.add_to_adoption_list(pet1);
//    service.add_to_adoption_list(pet2);
//
//    std::vector<Pets> adoptionList = service.get_adoption_list();
//
//    // Check if the adoption list contains the added pets
//    assert(adoptionList.size() == 2);
//    assert(adoptionList[0] == pet1);
//    assert(adoptionList[1] == pet2);
//}
//
//void Tests::testGetPetsByBreedAndAge() {
//    // Create a repository instance with some pets
//    MemoryRepository repo;
//    Service service(repo);
//
//    // Initialize the repository with some pets
//    service.initialize_repo();
//
//    // Test getting pets by breed and age
//    std::vector<Pets> pets = service.get_pets_by_breed_and_age("", 4); // Retrieve all pets aged 4 or less
//
//    assert(pets.size() == 4); // 4 pets should meet the criteria
//
//    pets = service.get_pets_by_breed_and_age("Great Dane", 7); // Retrieve Labradors aged 3 or less
//
//    assert(pets.size() == 1); // 1 Labrador should meet the criteria
//
//    pets = service.get_pets_by_breed_and_age("German Shepard", 2); // Retrieve German Shepherds aged 2 or less
//
//    assert(pets.size() == 0); // No German Shepherds aged 2 or less
//
//    pets = service.get_pets_by_breed_and_age("Rottweiler", 5); // Retrieve Rottweilers aged 5 or less
//
//    assert(pets.size() == 1); // 1 Rottweiler should meet the criteria
//
//    pets = service.get_pets_by_breed_and_age("Siberian Husky", 1); // Retrieve Siberian Huskies aged 1 or less
//
//    assert(pets.size() == 0); // No Siberian Huskies aged 1 or less
//}
//
//
//void Tests::testAll()
//{
//    testPetsClass();
////    testDynamicVector();
//    testRepository();
//    testService();
//    testAdoptionListRepo();
//    testAdoptionListService();
//    testGetPetsByBreedAndAge();
//}