#pragma once
#include <QAbstractTableModel>
#include "service.h"

class AdoptionListModel : public QAbstractTableModel {
Q_OBJECT

private:
    std::vector<Pets> adoptionList;

public:
    explicit AdoptionListModel(const std::vector<Pets>& pets, QObject* parent = nullptr)
            : QAbstractTableModel(parent), adoptionList(pets) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return static_cast<int>(adoptionList.size());
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return 4; // Name, Breed, Age, Photo
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || role != Qt::DisplayRole)
            return QVariant();

        const Pets& pet = adoptionList[index.row()];
        switch (index.column()) {
            case 0: return QString::fromStdString(pet.getName());
            case 1: return QString::fromStdString(pet.getBreed());
            case 2: return pet.getAge();
            case 3: return QString::fromStdString(pet.getPhotograph());
            default: return QVariant();
        }
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return QString("Name");
                case 1: return QString("Breed");
                case 2: return QString("Age");
                case 3: return QString("Photo");
                default: return QVariant();
            }
        }
        return QVariant();
    }

    void updateData(const std::vector<Pets>& newPets) {
        beginResetModel();
        adoptionList = newPets;
        endResetModel();
    }
};
