#include <stdio.h>

int main() {

    int T = 200;//this is the initial investment by Tom
    double J = 200;//this is the initial investment by Joan, represented as a double since it is i
    int i = 0;//this is the counter that will be used to count the amount of years taken

    while(J <= T){//a while loop is used since the looping condition is based on variables calculated within the loop and not on a predefined number of loops
        T = T + 30;//15% of 200 is 30 which is added to Tom's account annually
        J = J*1.1;//Joan's account balance is multiplied by 110% every year since it is based on compound interest
        i++;//the counter is incremented at the end since every pass of the loop represents a year passing
    }

    printf("Joan's invested sum overtook Tom's after %d years \n", i);//display for years taken for Joan's investment to overtake Tom's
    printf("Joan's sum after %d years: %.2lfe \n", i, J);//%.2lf identifier used for Joan's balance since it is not an integer value to round it to 2 d.p.
    printf("Tom's sum after %d years: %de \n", i, T);//Tom's balance at the time when Joan's exceeds his for the first time

    return 0;//program termination

}