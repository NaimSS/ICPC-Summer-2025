#include "testlib.h"
 
int main(int argc, char * argv[]) {
	registerTestlibCmd(argc, argv);
	
	int oufq = ouf.readInt();
	int ansq = ans.readInt();
    const int need = 6500;

	if (ansq < need)	
		quitf(_fail, "Poucos acertos");
 
	if (oufq < need)	
		quitf(_wa, "Poucos acertos");
 
	quitf(_ok, "Gahou %d", oufq);
}
