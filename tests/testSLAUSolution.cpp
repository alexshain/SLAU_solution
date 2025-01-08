#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
//#include "../src/Quaternion.h"

void testSumQuaterAndQuater() {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    Quaternion result = quater1 + quater2;
    Quaternion assert_quater = Quaternion(2, 0, 0, 8);
    CU_ASSERT_EQUAL(result, assert_quater);
}

int main() {
    //Инициализация CUnit
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Создание тестового набора
    CU_pSuite pSuite = CU_add_suite("QuaternionOperationsTest", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Добавление тестов в набор
    if ((NULL == CU_add_test(pSuite, "testSumQuaterAndQuater()", testSumQuaterAndQuater)) ||
        (NULL == CU_add_test(pSuite, "testSumQuaterAndComplex()", testSumQuaterAndComplex))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Запуск тестов с использованием базового интерфейса
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    unsigned int num_failures = CU_get_number_of_failures();
    // Очистка
    CU_cleanup_registry();

    return (num_failures == 0) ? 0 : 1;
}
