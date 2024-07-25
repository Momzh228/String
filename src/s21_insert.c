#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || (str == S21_NULL && (int)start_index == 0)) {
    return S21_NULL;
  }
  int src_len = s21_strlen(src);
  int str_len = 0;
  if (str != S21_NULL) {
    str_len = s21_strlen(str);
  }
  int total_len = src_len + str_len;
  char *buff = (char *)malloc(sizeof(char) * (total_len) + 1);
  if ((int)start_index > src_len || (int)start_index < 0) {
    free(buff);
    return S21_NULL;
  }
  if (str == S21_NULL) {
    int i, k;
    for (i = 0, k = 0; i < (int)start_index; i++, k++) {
      buff[i] = src[i];
    }
    for (; i < total_len; i++, k++) {
      buff[i] = src[k];
    }
    buff[i] = '\0';
  }
  if (str != S21_NULL) {
    int i, j, k;
    for (i = 0, k = 0; i < (int)start_index; i++, k++) {
      buff[i] = src[i];
    }
    for (j = 0; i < (int)start_index + str_len; i++, j++) {
      buff[i] = str[j];
    }
    for (; i < total_len; i++, k++) {
      buff[i] = src[k];
    }
    buff[i] = '\0';
  }
  return buff;
}