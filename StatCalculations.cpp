#include <iostream>
using namespace std;

// Function to calculate stats recursively for a single level
void calculateStatsRecursive(int level, float baseHP, float baseATK, float baseDEF, float baseSpeed, float growthHP, float growthATK, float growthDEF, int& hp, int& atk, int& def) {
    if (level == 1) {
        hp = (int)(baseHP + 0.5);
        atk = (int)(baseATK + 0.5);
        def = (int)(baseDEF + 0.5);
    } else {
        hp = (int)(baseHP + (level - 1) * growthHP + 0.5);
        atk = (int)(baseATK + (level - 1) * growthATK + 0.5);
        def = (int)(baseDEF + (level - 1) * growthDEF + 0.5);
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

    cout << "Recursive Calculation:" << endl;
    for (int i = 0; i < size; i++) {
        int hp, atk, def;
        calculateStatsRecursive(levels[i], baseHP, baseATK, baseDEF, 0, growthHP, growthATK, growthDEF, hp, atk, def);
        cout << "Level: " << levels[i] << ", HP: " << hp << ", ATK: " << atk << ", DEF: " << def << endl;
    }

    cout << "\nIterative Calculation:" << endl;
    calculateStatsIterative(baseHP, baseATK, baseDEF, 0, growthHP, growthATK, growthDEF, levels, size);
    return 0;
}
