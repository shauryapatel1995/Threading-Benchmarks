#include <iostream>
#include <thread>
#include <chrono>
#include <unordered_map>
#include <stdlib.h>
#include <list>
#include <time.h>
typedef std::chrono::high_resolution_clock Clock;

using namespace std;

std::unordered_map<std::thread::id, double> thread_times;

void foo() {
	auto t1 = Clock::now();
	//cout << "Thread started executing : " << std::this_thread::get_id() << "\n";
	
	//cout << "Value of t1 is: " << t1 << "\n";
	int i;
	unsigned int out = 0;
	unsigned int a = static_cast<unsigned int>(time(NULL));
	//Just run a loop 1000 times 
	for(i = 0; i < 1000; i++){
		// something
		out += rand_r(&a);
	
	}
	printf("%d\n",out);
	auto t2 = Clock::now();
	//cout << "Thread finished executing : " << std::this_thread::get_id() << " " << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() << "\n";
	thread_times.insert(std::pair<std::thread::id, double>(std::this_thread::get_id(),std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()));
}

int main() {
	auto t1 = Clock::now();
	list<std::thread> threads;	
	//cout << "Starting thread\n";

	/*std::thread first(foo);
	cout << "ID of first is " << first.get_id() << "\n";
	std::thread second(foo);
	cout << "ID of second is " << second.get_id() << "\n";
	std::thread third(foo);
	cout << "ID of third is " << third.get_id() << "\n";
	std::thread fourth(foo);
	cout << "ID of fourth is " << fourth.get_id() << "\n";
	std::thread fifth(foo);	
	cout << "ID of fifth is " << fifth.get_id() << "\n"; */

	for(int i =0; i < 1000; i++){
		threads.push_back(std::thread(foo));
	}

	auto t2 = Clock::now();
	/*first.join();
	second.join();
	third.join();
	fourth.join();
	fifth.join(); */

	for(auto& trial_thread : threads) {
		trial_thread.join();
		//cout << "Thread is " << trial_thread;
	}
	
//	cout << "Duration of the thread execution is: " <<
//	       	std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()	
//		<< "\n";
//	printf("\nFinishing main\n");
	
	for(auto i : thread_times) {
		cout << i.second << "\n";
	}	
		

}


