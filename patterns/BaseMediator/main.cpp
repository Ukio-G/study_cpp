#include <iostream>
#include <DistrictAdministrativeCenter.h>

int main() {
    DistrictAdministrativeCenter administrativeCenter;
    administrativeCenter.dataStorage = new DataStorage;
    administrativeCenter.migrationService = new MigrationService(&administrativeCenter);
    administrativeCenter.funeralService = new FuneralService(&administrativeCenter);
    administrativeCenter.maternityService = new MaternityService(&administrativeCenter);

    Person person1;
    person1.address = {1, "street"};
    person1.name = "John";
    administrativeCenter.maternityService->registerBirth(person1);
    administrativeCenter.dataStorage->print();
    Person & person = administrativeCenter.dataStorage->population[0];

    std::cout << "============================== Evict ==============================\n";
    administrativeCenter.migrationService->Evict(person);
    administrativeCenter.dataStorage->print();

    std::cout << "============================== Settle ==============================\n";
    administrativeCenter.migrationService->Settle(person,{2,"another street"});
    administrativeCenter.dataStorage->print();

    std::cout << "============================== Bury ==============================\n";
    administrativeCenter.funeralService->bury(person);
    administrativeCenter.dataStorage->print();
    return 0;
}
