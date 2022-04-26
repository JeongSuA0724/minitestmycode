#include <stdio.h>
#include <string.h>
#include "product.h"

#ifdef DEBUG


#endif
int main(void){
    Product p[20];
    int index = 0;
    int count = 0, menu;

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
          createProduct(p, index);
          printf("\n=> Complete Adding!\n\n");
          index++;
        }
        else if (menu == 2){
          readProduct(p, index);
        }
        else if (menu == 3){
          listProduct(p, index);
        }
        else if (menu == 4){
          searchProduct(p, index);
        }
        else if (menu == 5){
          searchProductPrice(p, index);
        }
        else if (menu == 6){
          searchProductDeliveryWay(p, index);
        }
        else if (menu == 7){
          saveFile(p, index);
        }
    }
 printf("End!\n");
    return 0;
}

