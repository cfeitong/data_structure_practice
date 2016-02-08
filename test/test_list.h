#ifndef TEST_LIST_H_
#define TEST_LIST_H_


void test_list_cstr_convertion();
void test_list_insertion();
void test_list_get_element();
void test_list_deletion();

void DO_TEST(bool (*f)(const char *s) , const char *string);

bool double_convertion(const char *s);
bool insertion(const char *s);
bool deletion(const char *s);
bool get_element(const char *s);

#endif // TEST_LIST_H_
