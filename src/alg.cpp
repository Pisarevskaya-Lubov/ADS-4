void Sort(int arr[], int size) {
    int klol = 0;
    int a = 0;
    for (int j = 1; j < size; j++) {
        klol = arr[j];
        a = j - 1;
        while (a >= 0 && arr[a] > klol) {
            arr[a + 1] = arr[a];
            a = a - 1;
            arr[a + 1] = klol;
        }
    }
}

int countPairs1(int* arr, int len, int value) {
    Sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len-1; j > i; --j) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            } else if (arr[i] + arr[j] < value) {
                break;
            }
        }
        continue;
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    Sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
        continue;
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    Sort(arr, len);
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int left = i, rig = len;
        while (1 < rig - left) {
            int center = (left + rig) / 2;
            if (arr[i] + arr[center] == value) {
                count++;
                int j = center + 1;
                while (arr[i] + arr[j] == value && j < rig) {
                    count++;
                    j++;
                }
                j = center - 1;
                while (arr[i] + arr[j] == value && j > left) {
                    count++;
                    j--;
                }
                break;
            }
            if (arr[i] + arr[center] > value) {
                rig = center;
            } else {
                left = center;
            }
        }
    }
    return count;
}
