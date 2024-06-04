class Action {
public:
    virtual void execute_undo() = 0;
    virtual void execute_redo() = 0;
};

class ActionAdd : public Action {
private:
    Pets addedPet;
    Repository& repository;

public:
    ActionAdd(const Pets& pet, Repository& repository1) : addedPet(pet), repository(repository1) {}

    void execute_undo() override {
        int position = this->repository.search_for_a_pet(this->addedPet);
        this->repository.remove_pet_from_repository(position);
    }

    void execute_redo() override {
        this->repository.add_pet_to_repository(this->addedPet);
    }
};

class ActionRemove : public Action {
private:
    Pets deletedPet;
    Repository& repository;

public:
    ActionRemove(const Pets& pet, Repository& repository1) : deletedPet(pet), repository(repository1) {}

    void execute_undo() override {
        this->repository.add_pet_to_repository(deletedPet);
    }

    void execute_redo() override {
        int position = this->repository.search_for_a_pet(deletedPet);
        this->repository.remove_pet_from_repository(position);
    }
};

class ActionUpdate : public Action {
private:
    Pets old_pet, new_pet;
    Repository& repository;

public:
    ActionUpdate(const Pets& old_pet, const Pets& new_pet, Repository& repository1)
            : old_pet(old_pet), new_pet(new_pet), repository(repository1) {}

    void execute_undo() override {
        int position = this->repository.search_for_a_pet(this->new_pet);
        this->repository.update_pet_from_repository(position, this->old_pet);
    }

    void execute_redo() override {
        int position = this->repository.search_for_a_pet(this->old_pet);
        this->repository.update_pet_from_repository(position, this->new_pet);
    }
};