#include <iostream>
#include <unordered_set>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

struct Hashfunc {
    size_t operator() (const pair<int, int>& key) const {
        return hash<int>()(key.first) ^ hash<int>()(key.second);
    }
};
struct Equalfunc {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first == b.first && a.second == b.second;
    }
};

void init();
void setBlock(int left, int right, int up, int down, int val);
void initQueue(int left, int right, int up, int down, queue<pair<int, int>>& q);
void printBoard();

size_t const n = 21;
int board[n][n];
queue <pair<int, int>> q1;
queue <pair<int, int>> q2;
const vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };

int main(int argc, char const* argv[])
{
    int step1 = 0, step2 = 0;
    init();
    printBoard();
    bool finded = false;
    while (!finded && !q1.empty() && !q2.empty()) {
        int size1 = q1.size(), size2 = q2.size();
        step1++;
        for (int i = 0;i < size1;i++) {
            int row = q1.front().first;
            int col = q1.front().second;
            q1.pop();
            for (vector<int> dir : dirs) {
                if (row + dir[0] >= 0 && row + dir[0] < n &&
                    col + dir[1] >= 0 && col + dir[1] < n) {
                    if (board[row + dir[0]][col + dir[1]] == -2) {
                        board[row + dir[0]][col + dir[1]] = 2 * step1 - 1;
                        q1.push(pair<int, int>(row + dir[0], col + dir[1]));
                    }
                    // finded
                    else if (board[row + dir[0]][col + dir[1]] > 0 && board[row + dir[0]][col + dir[1]] % 2 == 0) {
                        cout << step1 + step2 << endl;
                        printBoard();
                        return 0;
                    }
                }
            }
        }

        step2++;
        for (int i = 0;i < size2;i++) {
            int row = q2.front().first;
            int col = q2.front().second;
            q2.pop();
            for (vector<int> dir : dirs) {
                if (row + dir[0] >= 0 && row + dir[0] < n &&
                    col + dir[1] >= 0 && col + dir[1] < n) {
                    if (board[row + dir[0]][col + dir[1]] == -2) {
                        board[row + dir[0]][col + dir[1]] = 2 * step2;
                        q2.push(pair<int, int>(row + dir[0], col + dir[1]));
                    }
                    // finded
                    else if (board[row + dir[0]][col + dir[1]] % 2 == 1) {
                        cout << step1 + step2 << endl;
                        printBoard();
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

void setBlock(int left, int right, int up, int down, int val) {
    for (int row = down;row <= up;row++) {
        for (int col = left;col <= right;col++)
            board[row][col] = val;
    }
}

void init() {
    for (int row = 0;row < n;row++) {
        for (int col = 0;col < n;col++)
            board[row][col] = -2;
    }
    setBlock(3, 5, 10, 5, -1);
    setBlock(5, 13, 14, 12, -1);

    setBlock(13, 13, 9, 5, 0);
    setBlock(12, 13, 6, 6, 0);
    setBlock(13, 15, 9, 9, 0);
    initQueue(13, 13, 9, 5, q1);
    initQueue(12, 13, 6, 6, q1);
    initQueue(13, 15, 9, 9, q1);

    setBlock(2, 6, 17, 17, 0);
    setBlock(3, 3, 19, 17, 0);
    setBlock(4, 4, 17, 15, 0);
    setBlock(4, 5, 15, 15, 0);
    initQueue(2, 6, 17, 17, q2);
    initQueue(3, 3, 19, 17, q2);
    initQueue(4, 4, 17, 15, q2);
    initQueue(4, 5, 15, 15, q2);

}
void initQueue(int left, int right, int up, int down, queue<pair<int, int>>& q) {
    for (int row = down;row <= up;row++) {
        for (int col = left;col <= right;col++)
            q.push(pair<int, int>(row, col));
    }
}

void printBoard() {
    for (int row = 0;row < n;row++) {
        for (int col = 0;col < n;col++) {
            if (board[row][col] == -2)
                cout << "    ";
            else
                printf("%4d", board[row][col]);
        }
        cout << endl;
    }
    cout << endl << endl;
}