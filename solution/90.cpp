#include <string>
#include <vector>

using namespace std;

struct CompressionResult {
    int zeros = 0;
    int ones = 0;
};

CompressionResult compress(const vector<vector<int>>& arr, int y, int x, int size) {
    CompressionResult result;
    
    if (size == 1) {
        arr[y][x] == 0 ? result.zeros++ : result.ones++;
        return result;
    }
    
    int firstValue = arr[y][x];
    bool canCompress = true;
    
    for (int i = y; i < y + size && canCompress; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[i][j] != firstValue) {
                canCompress = false;
                break;
            }
        }
    }
    
    if (canCompress) {
        firstValue == 0 ? result.zeros++ : result.ones++;
    } else {
        int halfSize = size / 2;
        CompressionResult parts[4];
        int offsets[4][2] = {{0, 0}, {0, halfSize}, {halfSize, 0}, {halfSize, halfSize}};

        for (int i = 0; i < 4; i++) {
            parts[i] = compress(arr, y + offsets[i][0], x + offsets[i][1], halfSize);
            result.zeros += parts[i].zeros;
            result.ones += parts[i].ones;
        }
    }
    
    return result;
}

vector<int> solution(vector<vector<int>> arr) {
    CompressionResult finalResult = compress(arr, 0, 0, arr.size());
    return {finalResult.zeros, finalResult.ones};
}
