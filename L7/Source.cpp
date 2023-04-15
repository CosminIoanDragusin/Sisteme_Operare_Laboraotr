#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;


HANDLE th1, th2;
int globalCounter = 0;
DWORD th1Id, th2Id;
CRITICAL_SECTION criticalSection;



DWORD WINAPI Thread_1(LPVOID lpParam) {

	while (true) {
		Sleep(100);
		EnterCriticalSection(&criticalSection);

		for (auto i = 0; i < 10; i++)
		{
			Sleep(100);
			cout.width(10);
			cout << "thread1  ";
			cout.width(10);
			cout << globalCounter << endl;
			globalCounter++;


		}
		LeaveCriticalSection(&criticalSection);
		SwitchToThread();



	}
	return(0);

}



DWORD WINAPI Thread_2(LPVOID lpParam) {
	cout << endl;
	while (true) {
		Sleep(100);
		EnterCriticalSection(&criticalSection);

		for (auto i = 0; i < 10; i++)
		{
			Sleep(100);
			cout.width(10);
			cout << "thread 2  ";
			cout.width(10);
			cout << globalCounter << endl;
			globalCounter++;



		}
		LeaveCriticalSection(&criticalSection);
		SwitchToThread();


	}
	return(0);
}


void main() {

	InitializeCriticalSection(&criticalSection);

	th1 = CreateThread(NULL, 0, Thread_1, NULL, 0, &th1Id);
	th2 = CreateThread(NULL, 0, Thread_2, NULL, 0, &th2Id);
	getch();
}