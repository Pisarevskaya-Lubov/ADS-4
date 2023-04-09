// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
       if ((arr[i] + arr[j]) == value) {
        count++;
       }
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
      else if (arr[i] + arr[j] > value) {
        break;
      }
    }
    continue;
  }
  return count;
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int begin = i, end = len;
    while (end - 1 > begin) {
      int mid = (begin + end) / 2;
      if (arr[i] + arr[mid] == value) {
        count++;
        int mid2 = mid + 1;
        while (arr[i] + arr[mid2] == value && mid2 < end) {
          count++;
          mid2++;
        }
        mid2 = mid - 1;
        while (arr[i] + arr[mid2] == value && mid2 > begin) {
          count++;
          mid2--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        end = mid;
      }
      else {
        begin = mid;
      }
    }
  }
  return count;
  
}
