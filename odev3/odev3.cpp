#include "pch.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;
long long int term[100];
//aşağıdaki satırları yoruma alarak kodunuzu farklı şekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

long long recursiveFunction(long long int numberOfStones)
{
	if (numberOfStones == 0) {// özel durum :yol haritası için gerekli başlangıç
		return 1;
	}
	else if (numberOfStones == 1) {//özel durum:yol haritası için gerekli başlangıç
		return 1;
	}
	else if (numberOfStones == 2) {//özel durum:yol haritası için gerekli başlangıç
		return 2;
	}
	else { //her taş sayısı için yol kendinden önceki 3taş ihtimalinin toplamını verir.
		long long int toplam;
		toplam = recursiveFunction(numberOfStones - 3) + recursiveFunction(numberOfStones - 2);

		return toplam + recursiveFunction(numberOfStones - 1);

	}

}
long long iterativeFunction(int numberOfStones)
{
	int dizi[72];//72 elemanlı bir dizi
	dizi[1] = 1;//başlangıç
	dizi[2] = 2;//başlangıç
	dizi[3] = 4;//başlangıç

	for (int i = 4; i <= numberOfStones; i++) { //başlangıç durumlarından sonraki sayılar için sona kadar döngü
		dizi[i] = dizi[i - 1] + dizi[i - 2] + dizi[i - 3];//önceki 3 durumun toplamı istenen ihtimali verir.
	}

	return dizi[numberOfStones];
}




int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i < MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}