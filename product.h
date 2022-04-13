typedef struct Product{
	char name[100];
	char des[100];
	char w[100];
	int price;
	int hd;
} Product;
int addP(Product *p);
void readP(Product p,int no);
int updateP(Product *p);
int deleteP(Product *p);
int selectmenu();
