#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <ncurses.h>
using namespace std;

void countdowntimer(int m){
	int s=0;
	cout << setfill('0') << setw(2) << m << ":" <<  setfill('0') << setw(2) << s << endl;
	m=0;
	s=60;
	for (int i=60 ; i>0 ; i--){
		sleep(1);
		if (s>0){
			s--;
		}
		if (m== 0 && s == 0)
			 break;
		cout << setfill('0') << setw(2) << m << ":" <<  setfill('0') << setw(2) << s << endl;
	}
	int beep();
}

int main(){
	int m=1;
	countdowntimer(m);
	return 0;
}
