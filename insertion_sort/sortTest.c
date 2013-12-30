#include "testUtils.h"
#include "sort.h"
#include <string.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int accountNumber;
	int balance;
} Account;

int compareAccountsByAccountNumber(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->accountNumber - secondAccount->accountNumber;
};

int compareAccountsByBalance(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->balance - secondAccount->balance;
};
int compareIntegers(void* first, void* second) {
	return *(int*)first-*(int*)second;
};	
void test_sort_with_integers(){
	int base[] ={4,3,2,5,1};
	int expected[] ={1,2,3,4,5}; 
	sort(base,5,sizeof(int),compareIntegers);
	ASSERT(0==memcmp(base,expected,5));
}

void test_sort_with_structures_element1() {
	Account accounts[] = {{100, 100}, {12, 10}, {33, 10000}, {40, 3}};
	Account expected[] = {{12, 10}, {33, 10000}, {40, 3}, {100, 100}};
	sort(accounts, 4, sizeof(Account), compareAccountsByAccountNumber);
	ASSERT(0==memcmp(accounts,expected,8));
}

void test_sort_with_structures_element2() {
	Account accounts[] = {{100, 100}, {12, 10}, {33, 10000}, {40, 3}};
	Account expected[] = { {40, 3},{12, 10}, {100, 100},{33, 10000}};
	sort(accounts, 4, sizeof(Account), compareAccountsByBalance);
	ASSERT(0==memcmp(accounts,expected,8));
}