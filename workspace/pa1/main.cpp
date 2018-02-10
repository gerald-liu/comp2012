//do NOT submit this file
//while you may modify the main function to design your own test cases to test your program
//you should make sure your submitted code (i.e. the other cpp files) can be compiled with this main.cpp in its unmodified state

#include "mall.h"
#include <iostream>

using namespace std;

//print the info of a mall, used for testing the class code
void printMall(Mall* mall)
{
	if(mall == nullptr)
		cout << "printMall: No such mall." << endl;
	else
		cout << "Mall: " << mall->getName() << " @ " << mall->getAddress() << endl;
}

//print the list of shops of a mall, used for testing the class code
void printShopsInMall(Mall* mall)
{
	if(mall == nullptr)
		cout << "printShopsInMall: No such mall." << endl;
	cout << "Shops in " << mall->getName() << ": ";
	mall->printShopLinkedList();
}

//print the info of a shop, used for testing the class code
void printShop(Shop* shop)
{
	if(shop == nullptr)
		cout << "printShop: " <<  "No such shop." << endl;
	else
		cout << "Shop: " <<  "#" << shop->getShopNumber() << " " << shop->getName() << endl;
}

//print the array of products of a shop, used for testing the class code
void printProductsInShop(Shop* shop)
{
	if(shop == nullptr)
		cout << "printProductsInShop: No such shop." << endl;
	cout << "Products in " << shop->getName() << ": ";
	shop->printProductArray();
}

//the main function tests your code
//you should first make sure you can pass all the given test cases, and then design your own test cases to verify the correctness of your code
int main()
{
	{
		cout << "Test case 1:" << endl;
		Mall mallA("HKUST Mall", "Clear Water Bay");
		printMall(&mallA);
		printShopsInMall(&mallA);
		mallA.setName("HKUST Super Mall");
		mallA.setAddress("Clearer Water Bay");
		printMall(&mallA);
		mallA.addShop("Supermarket", 1);
		printShopsInMall(&mallA);
		printShop(mallA.getShop(1));
		printShop(mallA.getShop(11));
	}

	{
		cout << endl << "Test case 2:" << endl;
		Mall mallA("HKUST Mall", "Clear Water Bay");
		mallA.addShop("Supermarket A", 1);
		mallA.addShop("Supermarket B", 2);
		mallA.addShop("Supermarket C", 3);
		printShopsInMall(&mallA);
		Mall mallB(mallA);
		mallB.setName("HKUST Original Mall");
		cout << "Remove result: " << boolalpha << mallA.removeShop(1) << endl;
		printShopsInMall(&mallA);
		printShopsInMall(&mallB);
	}

	{
		cout << endl << "Test case 3:" << endl;
		Mall mallA("HKUST Mall", "Clear Water Bay");
		mallA.addShop("Supermarket A", 1);
		mallA.addShop("Supermarket B", 2);
		mallA.addShop("Supermarket C", 3);
		printShopsInMall(&mallA);
		cout << "Remove result: " << boolalpha << mallA.removeShop(2) << endl;
		printShopsInMall(&mallA);
	}

	{
		cout << endl << "Test case 4:" << endl;
		Mall mallA("HKUST Mall", "Clear Water Bay");
		mallA.addShop("Supermarket A", 1);
		mallA.addShop("Supermarket B", 2);
		mallA.addShop("Supermarket C", 3);
		printShopsInMall(&mallA);
		cout << "Remove result: " << boolalpha << mallA.removeShop(3) << endl;
		printShopsInMall(&mallA);
	}

	{
		cout << endl << "Test case 5:" << endl;
		Mall mallA("HKUST Mall", "Clear Water Bay");
		mallA.addShop("Supermarket A", 1);
		mallA.addShop("Supermarket B", 2);
		mallA.addShop("Supermarket C", 3);
		printShopsInMall(&mallA);
		cout << "Remove result: " << boolalpha << mallA.removeShop(4) << endl;
		printShopsInMall(&mallA);
	}

	{
		cout << endl << "Test case 6:" << endl;
		Mall mallA("HKUST Mall", "Clear Water Bay");
		cout << "Add result: " << boolalpha << mallA.addShop("Supermarket A", 1) << endl;
		cout << "Add result: " << boolalpha << mallA.addShop("Supermarket AAA", 1) << endl;
		printShopsInMall(&mallA);
	}

	{
		cout << endl << "Test case 7:" << endl;
		Shop* shopA = new Shop("Supermarket", 1);
		printProductsInShop(shopA);
		shopA->addProduct("XXBOX", TOYS, 2000, 10);
		printProductsInShop(shopA);
		shopA->addProduct("XXBOX", TOYS, 2000, 10);
		printProductsInShop(shopA);
		shopA->addProduct("XXBOX", shopA->findProduct("XXBOX")->getType(), shopA->findProduct("XXBOX")->getPrice(), 10);
		printProductsInShop(shopA);
		delete shopA;
	}

	{
		cout << endl << "Test case 8:" << endl;
		Shop shopA("Supermarket", 1);
		printProductsInShop(&shopA);
		shopA.addProduct("XXBOX", TOYS, 2000, 10);
		printProductsInShop(&shopA);
		shopA.addProduct("YBOX", TOYS, 3000, 40);
		printProductsInShop(&shopA);
		shopA.addProduct("ZZZBOX", TOYS, 1000, 20);
		printProductsInShop(&shopA);
		shopA.addProduct("Apple", FOOD, 5, 200);
		printProductsInShop(&shopA);
		shopA.addProduct("PreyStation", TOYS, 2500, 37);
		printProductsInShop(&shopA);
	}

	{
		cout << endl << "Test case 9:" << endl;
		Shop shopA("Supermarket", 1);
		shopA.addProduct("XXBOX", TOYS, 2000, 10);
		shopA.addProduct("YBOX", TOYS, 3000, 40);
		shopA.addProduct("ZZZBOX", TOYS, 1000, 20);
		shopA.addProduct("Apple", FOOD, 5, 200);
		shopA.addProduct("PreyStation", TOYS, 2500, 37);
		printProductsInShop(&shopA);
		cout << "Remove result: " << boolalpha <<  shopA.removeProduct("Banana", 100) << endl;
		printProductsInShop(&shopA);
		cout << "Remove result: " << boolalpha <<  shopA.removeProduct("Apple", 100) << endl;
		printProductsInShop(&shopA);
		cout << "Remove result: " << boolalpha <<  shopA.removeProduct("Apple", 200) << endl;
		printProductsInShop(&shopA);
		cout << "Remove result: " << boolalpha <<  shopA.removeProduct("Apple", 100) << endl;
		printProductsInShop(&shopA);
		cout << "Remove result: " << boolalpha <<  shopA.removeProduct("XXBOX", 10) << endl;
		printProductsInShop(&shopA);
		cout << "Remove result: " << boolalpha <<  shopA.removeProduct("YBOX", 40) << endl;
		printProductsInShop(&shopA);
	}

	{
		cout << endl << "Test case 10:" << endl;
		Shop shopA("Supermarket", 1);
		shopA.addProduct("XXBOX", TOYS, 2000, 10);
		shopA.addProduct("YBOX", TOYS, 3000, 40);
		shopA.addProduct("ZZZBOX", TOYS, 1000, 20);
		shopA.addProduct("Apple", FOOD, 5, 200);
		shopA.addProduct("PreyStation", TOYS, 2500, 37);
		printProductsInShop(&shopA);
		Shop shopB(shopA);
		shopB.setName("Supermarket Clone");
		shopB.setShopNumber(2);
		cout << "Update result: " << boolalpha <<  shopA.updatePrice("XXBOX", 9000) << endl;
		printProductsInShop(&shopA);
		printProductsInShop(&shopB);
	}

	return 0;
}
