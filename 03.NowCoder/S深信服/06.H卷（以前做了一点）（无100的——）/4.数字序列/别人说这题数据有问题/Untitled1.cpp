

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main() {
//    cout << endl;
    char buf[12];
    cin >> buf;
    int lines = atoi(buf);
    for(int i = 0; i < lines; i++) {
        cin >> buf;
        cin >> (buf + 1);
        cin >> (buf + 2);
        char cidx[12];
        cin >> cidx;
        int idx = atoi(cidx);
        char sss[12];
        sprintf(sss, "%s", buf);
        int bucket[1000] = {0};
        int start = 0;
        bool noRepeat = true;
        for (int i = 3; i < idx ;) {
            sprintf(sss, "%s%d", sss , (sss[(i - start -3)] + sss[(i - start-2)] + sss[(i - start-1)] - 3 * '0'));
            int tmp = (int)strlen(sss);
            start += (tmp - 3);
            i = start + 3;
            sprintf(sss, "%s", (sss + (tmp - 3)));
            if (noRepeat) {
                if (bucket[atoi(sss)] == 0) {
                    bucket[atoi(sss)] = i;
                } else {//这里有重复，所以后面会一直重复
                    int repeatLen = i - (bucket[atoi(sss)]);
                    int after = (idx - i) % repeatLen;
                    idx = 3 + after;
                    i = 3;
                    start = 0;
                    noRepeat = false;
                }
            } 
        }
        cout << sss[idx - start - 1] << endl;
    }
    return 0;
}
