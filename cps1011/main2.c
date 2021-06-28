#include <stdio.h>

int main() {

    FILE *fp;//points to the file where the receipt is to be saved
    int a, o, c, tempa, tempo, tempc, totalWeight, exit;//declaration of variables to be used
    a = 0;//kilos of artichokes
    o = 0;//kilos of onions
    c = 0;//kilos of carrots
    totalWeight = 0;//total weight in kilos
    exit = 0;//exit condition for while loop, set to 1 when user wishes to checkout and therefore exit the loop
    char response, checkout;//stores user's response from main menu
    double grossPrice, netPrice;//stores the total price of the user's order
    int scanValid = 0;//used to check if input from scanf is valid;

    while(exit == 0){
        printf("What would you like to do? (Insert a, b, c or q)\n");
        printf("a) Order artichokes \n");
        printf("b) Order onions \n");
        printf("c) Order carrots \n");
        printf("q) Check out \n");
        fflush(stdin);//flush the input buffer before taking user input to clear the input stream of unwanted content
        scanf("%c", &response);//takes user's choice for the main menu
        if(response == 'a'){
            printf("How many kilos would you like to add to your order? \n");
            fflush(stdin);
            scanValid = scanf("%d", &tempa);
            if(tempa < 0 || scanValid!=1){
                printf("Invalid input, please insert a positive integer value \n");
                tempa = 0;
            }
            a += tempa;//adds the user's input to the total amount of artichokes to be ordered
        }else if(response == 'b'){
            printf("How many kilos would you like to add to your order? \n");
            fflush(stdin);
            scanValid = scanf("%d", &tempo);
            if(tempo < 0 || scanValid!=1){
                printf("Invalid input, please insert a positive integer value \n");
                tempo = 0;
            }
            o += tempo;//adds the user's input to the total amount of onions to be ordered
        }else if(response == 'c'){
            printf("How many kilos would you like to add to your order? \n");
            fflush(stdin);
            scanValid = scanf("%d", &tempc);
            if(tempc < 0 || scanValid!=1){
                printf("Invalid input, please insert a positive integer value \n");
                tempc = 0;
            }
            c += tempc;//adds the user's input to the total amount of carrots to be ordered
        }else if(response == 'q'){//exits menu loop and proceeds to checkout
            printf("Are you sure you want to check out? (Type Y to check out, type anything else to return to main menu)\n");
            fflush(stdin);
            scanf("%c", &checkout);//checkout confirmation
            if(checkout == 'Y'){
                exit = 1;
            }else{
                printf("Returning to main menu\n");
            }
        }else{//user input doesn't match one of the menu options
            printf("Invalid input, please try again. \n");
        }
    }

    totalWeight = a + o + c;//adds up the total amount of kilos, in the order, used to calculate shipping cost
    if(totalWeight > 0){//no checkout if nothing is ordered
        double tap = a*2.05;//calculating total price of artichokes
        double top = o*1.15;//calculating total price of onions
        double tcp = c*1.19;//calculating total price of carrots
        grossPrice = tap + top + tcp;//calculating total price before discount and shipping
        double bulkDiscount = 0;
        double shippingCost = 0;
        netPrice = grossPrice;//initializing net price with value of gross price before deducting discount/adding shipping

        if(grossPrice >= 100){//calculating bulk discount if total price before shipping exceeds 100 euro
            bulkDiscount = grossPrice*0.05;
            netPrice -= bulkDiscount;
        }
        if(totalWeight <= 5){//calculation of shipping costs
            shippingCost = 6.5;
            netPrice += shippingCost;
        }else if(totalWeight > 5 & totalWeight < 20){
            shippingCost = 14;
            netPrice += shippingCost;
        }else if(totalWeight >= 20) {
            shippingCost = 14 + 0.5 * totalWeight - 20;
            netPrice += shippingCost;
        }

        printf("Final Bill \n");//outputting the bill to the user
        printf("Artichokes: %d kilos, %.2lfe \n", a, tap);
        printf("Onions: %d kilos, %.2lfe \n", o, top);
        printf("Carrots: %d kilos, %.2lfe \n", c, tcp);
        printf("Gross Price: %d kilos, %.2lfe \n", totalWeight, grossPrice);
        printf("Shipping Cost: %.2lfe \n", shippingCost);
        if(bulkDiscount != 0)
            printf("Bulk Discount: -%.2lfe \n", bulkDiscount);
        printf("Net Price: %.2lfe \n", netPrice);

        fp=fopen("bill.txt", "w");//opening or creating the file where the bill is to be saved
        fprintf(fp, "Final Bill \n");//printing the bill to a text file
        fprintf(fp, "Artichokes: %d kilos, %.2lfe \n", a, tap);
        fprintf(fp, "Onions: %d kilos, %.2lfe \n", o, top);
        fprintf(fp, "Carrots: %d kilos, %.2lfe \n", c, tcp);
        fprintf(fp, "Gross Price: %d kilos, %.2lfe \n", totalWeight, grossPrice);
        fprintf(fp, "Shipping Cost: %.2lfe \n", shippingCost);
        if(bulkDiscount != 0)
            fprintf(fp, "Bulk Discount: -%.2lfe\n", bulkDiscount);
        fprintf(fp, "Net Price: %.2lfe \n", netPrice);
    }

    return 0;//program termination

}