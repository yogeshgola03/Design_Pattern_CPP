//Flyweight Pttern - used to optimize memory usage and performance when dealing with a large number of objects that share some common characteristics
//It achieves this by separating an object's intrinsic state (shared among multiple objects) from its extrinsic state (unique to each object)
//Storing the intrinsic state externally, typically within a Flyweight factory

//Example
//Consider a text editor where each character in the document is represented as an object
//If you have a large document, creating individual objects for each character can be memory-intensive
//However, most characters share common properties like the font and size, which can be optimized to reduce memory usage
#include <iostream>
#include <unordered_map>
using namespace std;

//Flyweight class
class Character {
    char intrinsic_;
    public:
    Character(const char c) : intrinsic_(c) {}
    void draw(int extrinsic) {
        cout << "Character : intrinsic - " << intrinsic_ << ", extrinsic - " << extrinsic << endl;
    }
};

//Flyweight Factory
class CharacterFactory {
    unordered_map<char, Character*> characterList;
    public:
    Character* getCharacter(char key) {
        if(characterList.find(key) == characterList.end()){
            characterList[key] = new Character(key);
        }
        return characterList[key];
    }
};

int main() {
    int extrinsic_data = 0;
    CharacterFactory characterFactory;
    characterFactory.getCharacter('A')->draw(extrinsic_data);
    extrinsic_data++;
    characterFactory.getCharacter('B')->draw(extrinsic_data);
    extrinsic_data++;
    characterFactory.getCharacter('A')->draw(extrinsic_data);
    extrinsic_data++;
    characterFactory.getCharacter('C')->draw(extrinsic_data);
    extrinsic_data++;
    characterFactory.getCharacter('B')->draw(extrinsic_data);
    return 0;
}