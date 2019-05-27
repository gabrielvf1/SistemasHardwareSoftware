#include "mintest/macros.h"
#include <unistd.h>

int test1() {
    test_printf("Hello! %d %f\n", 3, 3.14);
    return 0;
}

int test2() {
    test_assert(1 == 0, "This always fails!");
    return 0;
}

int test3() {
    test_printf("<-- Name of the function before the printf!\n");
    test_assert(1 == 1, "This always succeeds");
    return 0;
}

int test4(){
	int *ponteiro_null = NULL;
	int a = *ponteiro_null*3;
    return 0;
}
int test5(){
	int a = 0;
	int b =13/a;
    return 0;
}

int test6(){
	int a = 100000/4;
	for (int i=0; i < a;i++){
		for(int j=0; j<a;j++){
			int b = 0;
		}
	}
	printf("test6 Demora mas nao cai no Time Out \n");
	return 1;
}

int test7(){
	int a = 100000/4;
	while(1){

	}
	return 0;
}

int test8(){
	 test_assert(1 == 1, "Test Pass Assert 1\n");
	 test_printf("[PASS] Passou Assert 1\n");
	 test_assert(1 == 0, "Falhou Assert 2\n");
	 //test_printf("test 8: Falhou Assert 2\n");
	 test_assert(1 == 1, "Passou Assert 3\n");
}

int test9(){
	int a = 2;
	for (int i = 0; i < a ; i++){
		test_printf("Print %d\n", i );
	}
	test_assert(1 == 1,"Passou");
}
int test10(){
	 test_assert(1 == 1, "Test Rapido 1\n");
	 test_printf("Rapido\n");
	 sleep(1);
	 test_assert(1 == 1, "Test Lento 1\n");	
	 test_printf("Lento\n");
	 //test_assert(1 == 1, "Test Rapido 1\n");

}



test_list = { TEST(test1), TEST(test2), TEST(test3), TEST(test4), TEST(test5), TEST(test6), TEST(test7), TEST(test8), TEST(test9), TEST(test10) };

#include "mintest/runner.h"
