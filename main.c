#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock{

    int productCode;
    char productName[50];
    char productMaker[50];
    int productAmount;
    int productProfit;
    float productPrice;

};
struct Stock stock[1000];
char shopName[50];
int amountItens, maxItens;

int main(){

    int count, option, i, j;
    struct Stock aux;
    
    FILE *fileStock, *fileStockOut;
    
    fileStock = fopen("input.txt", "r");
    fileStockOut = fopen("output.txt", "w");
    
    fscanf(fileStock, "%s %d %d ", &shopName, &amountItens, &maxItens);
    
    for(count = 0; count<amountItens; count++){
        fscanf(fileStock, "%d %s %s %d %d %f ", &stock[count].productCode, &stock[count].productName, &stock[count].productMaker, &stock[count].productAmount, &stock[count].productProfit, &stock[count].productPrice);
    }
    
    for(i = 1; i < amountItens; i++){
        
        aux = stock[i];
        
        for(j = i; j > 0 && aux.productCode < stock[j-1].productCode; j--){
            
            stock[j] = stock[j-1];
        }
        stock[j] = aux;

    }
    
    option = 0;
    
    while(option != 9){
        
        option = menu();
        
        switch(option){
            
            case 1:
                insertProduct();
                break;
            case 2:
                excludeProduct();
                break;
            case 3:
                editProduct();
                break;
            case 4:
                searchProductMaker();
                break;
            case 5:
                searchProductCode();
                break;
            case 6:
                allProduct();
                break;
            case 7:
                productIn();
                break;
            case 8:
                productOut();
                break;
            case 9:
                
                printf("Closing...\n");
                
                fprintf(fileStockOut, "%s\n%d\n%d\n", shopName, amountItens, maxItens);
                for(count = 0; count<amountItens; count++){
                    fprintf(fileStockOut, "%6.d %s %s %d %d %.2f\n", stock[count].productCode, stock[count].productName, stock[count].productMaker, stock[count].productAmount, stock[count].productProfit, stock[count].productPrice);
                }
                
                break;
            default:
                printf("Invalid option.\n");
                break;
            
        }
    
    }
    return 0;
}

int menu(){
    
    int option;
    printf("------------ MENU ------------\n");
    printf("| 1 - Insert Product.        |\n");
    printf("| 2 - Remove Product.        |\n");
    printf("| 3 - Edit Product.          |\n");
    printf("| 4 - Search by brand.       |\n");
    printf("| 5 - Search by ID.          |\n");
    printf("| 6 - Overview.              |\n");
    printf("| 7 - Product In.            |\n");
    printf("| 8 - Product Out.           |\n");
    printf("| 9 - Exit.                  |\n");
    printf("------------------------------\n");
    
    printf("Choose the number of the desired option: ");
    scanf("%d", &option);
    
    while(option < 1 || option > 9){
        printf("Invalid option. Choose again: ");
        scanf("%d", &option);
    }
    
    return option;
    
}

int insertProduct(){
    int count;
    int aux;

    printf("Enter the product code.\n");
    scanf("%d", &stock[amountItens].productCode);
    
    for(count = amountItens; count > 0 && stock[count].productCode < stock[count-1].productCode; count--){
        aux = stock[count].productCode;
        stock[count] = stock[count-1];
        stock[count-1].productCode = aux;
    }
    
    printf("Enter the product name.\n");
    scanf("%s", &stock[count].productName);
    printf("Enter the manufacturer's name.\n");
    scanf("%s", &stock[count].productMaker);
    printf("Enter the amount of products.\n");
    scanf("%d", &stock[count].productAmount);
    printf("Insira a porcentagem de lucro.\n");
    scanf("%d", &stock[count].productProfit);
    printf("Enter the price of the product.\n");
    scanf("%f", &stock[count].productPrice);
    
    amountItens++;
    return 0;
}

int excludeProduct(){
    
    int code, count;
    
    printf("Enter the product code you want to delete.\n");
    scanf("%d", &code);
    
    for(count = 0; count < amountItens && code != stock[count].productCode; count++){}
    
    if(count == amountItens){
        printf("Product missing.\n");
    }else{
        while(count < amountItens){
            stock[count] = stock[count+1];
            count++;
        }
        amountItens--;
    }
    return 0;
}

int editProduct(){
    
    int option;
    int count, code;
    
    printf("Enter the code of the product you want to change.\n");
    scanf("%d", &code);
    
    for(count = 0; count < amountItens && code != stock[count].productCode; count++){}
    
    if(count == amountItens+1){
        printf("Product missing.\n");
    }else{
        
       option = 0;
    
        while(option != 6){
        
            option = editMenu();
        
            switch(option){
                case 1:
                    printf("Enter the new name of the product.\n");
                    scanf("%s", &stock[count].productName);
                    break;
                case 2:
                    printf("Enter the new producer manufacturer.\n");
                    scanf("%s", &stock[count].productMaker);
                    break;
                case 3:
                    printf("Enter the new amount of the product.\n");
                    scanf("%d", &stock[count].productAmount);
                    break;
                case 4:
                    printf("Enter the new profit product.\n");
                    scanf("%d", &stock[count].productProfit);
                    break;
                case 5:
                    printf("Enter the new price of the product.\n");
                    scanf("%f", &stock[count].productPrice);
                    break;
                case 6:
                    printf("Saving changes.\n");
                    break;
                default:
                    printf("Invalid option.\n");
                    break;
            }
            
        }
       
    }
    return 0;
}

int editMenu(){

    int option;
    
    printf("1 - Change name.\n");
    printf("2 - Change manufacturer.\n");
    printf("3 - Change amount.\n");
    printf("4 - Change Profit.\n");
    printf("5 - Change price.\n");
    printf("6 - Conclude.\n");
    
    printf("Choose the number of the desired option: ");
    scanf("%d", &option);
    
    while(option < 1 || option > 6){
        printf("Invalid option. Choose again: ");
        scanf("%d", &option);
    }
    
    return option;

}

int searchProductCode(){

    int code, count;
    
    printf("Enter the product code.\n");
    scanf("%d", &code);
    
    for(count = 0; count < amountItens && code != stock[count].productCode; count++){}
    
    if(count == amountItens+1){
        printf("Product missing.\n");
    }else{
        printf("%6.d %s %s %d %d %.2f\n", stock[count].productCode, stock[count].productName, stock[count].productMaker, stock[count].productAmount, stock[count].productProfit, stock[count].productPrice);
    }
    return 0;
}

int allProduct(){
    
    int count;
    
    printf("%s\nAmount of itens: %d\n", shopName, amountItens);
    
    for(count = 0; count < amountItens; count++){
        printf("%6.d %s %s %d %d %.2f\n", stock[count].productCode, stock[count].productName, stock[count].productMaker, stock[count].productAmount, stock[count].productProfit, stock[count].productPrice);
    }
    return 0;
}

int productIn(){
    
    int count, amount, code;
    
    printf("Enter the product code.\n");
    scanf("%d", &code);
    
    for(count = 0; count < amountItens && code != stock[count].productCode; count++){}
    
    if(count == amountItens+1){
        printf("Product missing.\n");
    }else{
        printf("Enter the quantity of the product you want to add.\n");
        scanf("%d", &amount);
        
        stock[count].productAmount = stock[count].productAmount + amount;
    }
    return 0;
}

int productOut(){
    
    int count, amount, code;
    
    printf("Enter the product code.\n");
    scanf("%d", &code);
    
    for(count = 0; count < amountItens && code != stock[count].productCode; count++){}
    
    if(count == amountItens+1){
        printf("Product missing.\n");
    }else{
        printf("Enter the amount of product you want to remove.\n");
        scanf("%d", &amount);
        
        stock[count].productAmount = stock[count].productAmount - amount;
    }
    return 0;
}

int searchProductMaker(){

    int count, i;
    char maker[50];
    i = 0;
    
    printf("Enter the product brand.\n");
    scanf("%s", &maker);
    
    for(count = 0; count < amountItens; count++){

        if(strcmp(maker, stock[count].productMaker) == 0){
            printf("%6.d %s %s %d %d %.2f\n", stock[count].productCode, stock[count].productName, stock[count].productMaker, stock[count].productAmount, stock[count].productProfit, stock[count].productPrice);
            i++;
        }
    
    }

    if(i == 0){
        printf("Product missing.\n");
    }
    return 0;
}
