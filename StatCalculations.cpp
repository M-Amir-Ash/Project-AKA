#include <iostream>
using namespace std;

// Function to calculate stats recursively for a single level
void calculateStatsRecursive(int levels[], float baseHP, float baseATK, float baseDEF, float baseSpeed, float growthHP, float growthATK, float growthDEF, int& hp, int& atk, int& def ,int size, int& sizeFirst) {
    int level = levels[sizeFirst];
    if (level == 80) {
        hp = (int)(baseHP + (level - 1) * growthHP + 0.5);
        atk = (int)(baseATK + (level - 1) * growthATK + 0.5);
        def = (int)(baseDEF + (level - 1) * growthDEF + 0.5);
        cout << "Level: " << level << ", HP: " << hp << ", ATK: " << atk << ", DEF: " << def << endl;
    } else {
        hp = (int)(baseHP + (level - 1) * growthHP + 0.5);
        atk = (int)(baseATK + (level - 1) * growthATK + 0.5);
        def = (int)(baseDEF + (level - 1) * growthDEF + 0.5);
        cout << "Level: " << level << ", HP: " << hp << ", ATK: " << atk << ", DEF: " << def << endl;
        sizeFirst++;
        calculateStatsRecursive(levels, baseHP, baseATK, baseDEF, 0, growthHP, growthATK, growthDEF, hp, atk, def, size, sizeFirst);
    }
}

// Function to calculate stats iteratively for multiple levels
void calculateStatsIterative(float baseHP, float baseATK, float baseDEF, float baseSpeed, float growthHP, float growthATK, float growthDEF, int levels[], int size) {
    for (int i = 0; i < size; i++) {
        int level = levels[i];
        int hp = (int)(baseHP + (level - 1) * growthHP + 0.5);
        int atk = (int)(baseATK + (level - 1) * growthATK + 0.5);
        int def = (int)(baseDEF + (level - 1) * growthDEF + 0.5);
        cout << "Level: " << level << ", HP: " << hp << ", ATK: " << atk << ", DEF: " << def << endl;
    }
}

int main() {
    float baseHP = 110.0, baseATK = 71.0, baseDEF = 105.0;
    float growthHP = 8.91, growthATK = 5.72, growthDEF = 8.49;
    int levels[] = {1, 20, 30, 40, 50, 60, 70, 80};
    int size = 8;
    int sizeFirst = 0;
    cout << "Recursive Calculation:" << endl;
    int hp, atk, def;
    calculateStatsRecursive(levels, baseHP, baseATK, baseDEF, 0, growthHP, growthATK, growthDEF, hp, atk, def, size, sizeFirst);

    cout << "\nIterative Calculation:" << endl;
    calculateStatsIterative(baseHP, baseATK, baseDEF, 0, growthHP, growthATK, growthDEF, levels, size);
    return 0;
}
