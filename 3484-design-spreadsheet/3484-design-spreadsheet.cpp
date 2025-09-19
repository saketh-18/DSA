#include <bits/stdc++.h>
struct PairHash {
    size_t operator()(const std::pair<char, int>& p) const {
        // combine the two hashes
        return std::hash<char>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};
class Spreadsheet {
public:
    unordered_map<pair<char, int>, int, PairHash> sheet;
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        char col = cell[0];
        int row = 0;
        for (int i = 1; i < cell.size(); i++) {
            row = row * 10 + (cell[i] - '0');
        }
        sheet[{col, row}] = value;
    }

    void resetCell(string cell) {
        char col = cell[0];
        int row = 0;
        for (int i = 1; i < cell.size(); i++) {
            row = row * 10 + (cell[i] - '0');
        }
        sheet[{col, row}] = 0;
    }

    int getValue(string formula) {
        string left = "";
        string right = "";
        int i = 1;
        while (formula[i] != '+') {
            left += formula[i];
            i++;
        }
        i++;
        while (i < formula.size()) {
            right += formula[i];
            i++;
        }

        bool leftval = all_of(left.begin(), left.end(),
                              [](unsigned char c) { return isdigit(c); });
        bool rightval = all_of(right.begin(), right.end(),
                               [](unsigned char c) { return isdigit(c); });

        if (leftval == false && rightval == false) {
            char lcol = left[0];
            int lrow = 0;
            for (int i = 1; i < left.size(); i++) {
                lrow = (lrow * 10) + left[i] - '0';
            }
            char rcol = right[0];
            int rrow = 0;
            for (int i = 1; i < right.size(); i++) {
                rrow = (rrow * 10) + right[i] - '0';
            }

            return sheet[{lcol, lrow}] + sheet[{rcol, rrow}];
        }

        if (leftval && rightval) {
            return stoi(left) + stoi(right);
        }

        if (leftval) {
            char rcol = right[0];
            int rrow = 0;
            for (int i = 1; i < right.size(); i++) {
                rrow = (rrow * 10) + right[i] - '0';
            }

            return stoi(left) + sheet[{rcol, rrow}];
        }

        char lcol = left[0];
        int lrow = 0;
        for (int i = 1; i < left.size(); i++) {
            lrow = (lrow * 10) + left[i] - '0';
        }

        return sheet[{lcol, lrow}] + stoi(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */