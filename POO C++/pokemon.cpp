#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>

// Re-declarations
class Pokemon;
std::list<Pokemon> PokemonList;
void setNextForms(int forms_quant);
//

class Pokemon {
    public:
        std::string name;
        std::string new_form_name;
        std::list<std::string> next_forms;
    
    Pokemon create(std::string name, int forms_quant) {
        Pokemon p;
        p.name = name;
        p.new_form_name = new_form_name;
        p.next_forms = next_forms;
        setNextForms(p.name, forms_quant);
        std::cout << "\nPokemon " << p.name << " was successfully created!" << std::endl;
        return p;
    }

    void info() {
        std::cout << std::endl << "Evolutions:" << std::endl;

        if (next_forms.front() == next_forms.back()) {
            std::cout << next_forms.front() << std::endl;
        } else {
            std::cout << next_forms.front() << std::endl << next_forms.back() << std::endl;
        }
    }
    void setNextForms(std::string name, int forms_quant) {
        for (int i=0; i<forms_quant; i++) {
            if (forms_quant <= 0) break;
            std::cout << name << " next forms name " << (i+1) << ": ";
            std::cin >> new_form_name;
            next_forms.push_back(new_form_name);
        }
    }
    void deletePokemonFront() {
        PokemonList.pop_front();
    }
    void deletePokemonBack() {
        PokemonList.pop_back();
    }
    void evolve() {
        std::string old_name;
        old_name = name;
        if (next_forms.empty()) {
            std::cout << "This Pokemon is in the final form!" << std::endl;
        } else {
            name = next_forms.front();
            std::cout << old_name << " get evolved into " << name << "!" << std::endl;
            next_forms.pop_front();
        }
    }
};

int main() {
    Pokemon pokemon = Pokemon();
    pokemon.create("Charmander", 2);
    PokemonList.push_front(pokemon);
    pokemon.info();
    pokemon.evolve();
    pokemon.info();

    return 0;
}