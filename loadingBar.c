#include <stdio.h>
#include <unistd.h>

int main(){

    int index = 0;
    int percentDone = 0;
    char loadingBar[51] = {};
    memset(&loadingBar, '-', 50);
    for(;;){
        printf("\rLoading: %s %d%c", loadingBar, percentDone, '%');
        loadingBar[index] = '>';
        if ((index - 1) >= 0) loadingBar[index - 1] = '=';
        //Check for loading completion
        if (index == 50){
            return 0;
        }

        index += 1;
        percentDone = 100 - (2 * (50 - index));
        sleep(1);
    }

}