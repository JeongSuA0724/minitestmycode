#include <stdio.h>
#include <string.h>

typedef struct{
    char productName[100];
    char productIntroduction[200];
    char productWeight[30];
    int productPrice;
    int productDeliveryWay;
}Product;

int selectMenu();
int createProduct(Product *p, int count); // 제품을 추가하는 함수
int readProduct(Product *p, int count); // 하나의 제품 출력 함수
void listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력
void searchProduct(Product *p, int count); // 제품 이름 검색
void searchProductPrice(Product *p, int count); // 제품 가격 검색
void searchProductDeliveryWay(Product *p, int count); // 제품 배송 방법 검색
int saveFile(Product *p, int count);

int selectMenu(){

    int select;

    printf("Run a fruit shopping mall management program.\n");
    printf("1. Add A Product\n");
    printf("2. Output A Single Product\n");
    printf("3. Print Out A Complete List Of Registered Products\n");
    printf("4. Search Product Name\n");
    printf("5. Search Product Price.\n");
    printf("6. Search Product Delivery Way.\n");
    printf("7. Save text  file.\n");
    printf("Please enter the desired item number. ");
    scanf("%d", &select);

    return select;
}

int createProduct(Product *p, int count){

    printf("\n\nWhat Is Product's Name? ");
    scanf("%s", p[count].productName);
    printf("Please Explain The Product You Entered. ");
    scanf("%s", p[count].productIntroduction);
    printf("Please Let Me Know The Weight Of The Product You Entered. ");
    scanf("%s", p[count].productWeight);
    printf("Please Let Me Know The Price Of The Product You Entered. ");
    scanf("%d", &p[count].productPrice);
    printf("Please Select The Shipping Method. (1: Early Morning Delivery / 2: Courier Delivery) ");
    scanf("%d", &p[count].productDeliveryWay);


    return 0;
}

int readProduct(Product *p, int count){

    int i=0;

    printf("Product's Name : %s\n", p[i].productName);
    printf("Product's Introduction : %s\n", p[i].productIntroduction);
        printf("Product's Weight : %s\n", p[i].productWeight);
    printf("Product's Price : %d\n", p[i].productPrice);
    printf("Product's Deliveryway : %d\n", p[i].productDeliveryWay);

    return 0;
}

void listProduct(Product *p, int count){

    for (int i=0; i<count; i++){
        printf("Product's Name : %s\n", p[i].productName);
        printf("Product's Introduction : %s\n", p[i].productIntroduction);
        printf("Product's Weight : %s\n", p[i].productWeight);
        printf("Product's Price : %d\n", p[i].productPrice);
        printf("Product's Deliveryway : %d\n", p[i].productDeliveryWay);
    }
}

int saveFile(Product *p, int index){
  char filename[20] = "product";
    FILE *fp = fopen("product.txt", "w");
  if (!fp) {
    return -1;
  }
  fputs("Name  introduction  weight  price  deliveryway\n", fp);

  for(int i = 0; i < index; i++){
    if(!strcmp(p[i].productName, "Deleted")){
    continue;
      }
    fprintf(fp, "%3s %3s %4s %4d %4d\n", p[i].productName, p[i].productIntroduction, p[i].productWeight, p[i].productPrice, p[i].productDeliveryWay);
  }

  fclose(fp);
}

void searchProduct(Product *p, int count){
    char name[30];
    int len;
        char *ptr=NULL;

    printf("What's the name you want to search? ");
    scanf("%s", name);

    for(int i=0; i<count; i++){
        ptr=strstr(p[i].productName, name);
        if(ptr==NULL){
            continue;
        }
        printf("Product's Name : %s\n", p[i].productName);
        printf("Product's Introduction : %s\n", p[i].productIntroduction);
        printf("Product's Weight : %s\n", p[i].productWeight);
        printf("Product's Price : %d\n", p[i].productPrice);
        printf("Product's Deliveryway : %d\n", p[i].productDeliveryWay);
    }
}

void searchProductPrice(Product *p, int count){
    int price[30];
        int len;
    char *ptr=NULL;

    printf("What's the price you want to search? ");
    scanf("%d", price);

    for(int i=0; i<count; i++){
        ptr=strstr(p[i].productPrice, price);
        if(ptr==NULL){
            continue;
        }
        printf("Product's Name : %s\n", p[i].productName);
        printf("Product's Introduction : %s\n", p[i].productIntroduction);
        printf("Product's Weight : %s\n", p[i].productWeight);
        printf("Product's Price : %d\n", p[i].productPrice);
        printf("Product's Deliveryway : %d\n", p[i].productDeliveryWay);
    }
}

void searchProductDeliveryWay(Product *p, int count){
       int DeliveryWay[30];
    int len;
    char *ptr=NULL;

    printf("What's the price you want to search? ");
    scanf("%d", DeliveryWay);

    for(int i=0; i<count; i++){
        ptr=strstr(p[i].productDeliveryWay, DeliveryWay);
        if(ptr==NULL){
            continue;
        }
        printf("Product's Name : %s\n", p[i].productName);
        printf("Product's Introduction : %s\n", p[i].productIntroduction);
        printf("Product's Weight : %s\n", p[i].productWeight);
        printf("Product's Price : %d\n", p[i].productPrice);
        printf("Product's Deliveryway : %d\n", p[i].productDeliveryWay);
    }
}

