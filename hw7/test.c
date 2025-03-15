#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "fileIO.h"



void running_test()
{
	HashTable table = {0};

	printf("\nTesting the add_customer function:\n");

	add_customer(&table,"mario@gmailcom","mario poper",12,"sushi");
	add_customer(&table,"julian@gmail.com","julian	segura",7,"pizza");
	add_customer(&table,"puppylover@gmailcom","dany mango",4,"mango	smoothie");
	add_customer(&table,"logan	@gmailcom","logan	stanley",9,"taco	ss");
	add_customer(&table,"hillary@gmailcom","margret",5,"tortas");

printf("\nNow we are going to lookup two specefic emails (puppylover@gmailcom) and (not_real_email)\n");

	Customer *customer1 = lookup_customer(&table,"puppylover@gmailcom");
	Customer *customer2= lookup_customer(&table,"not_real_email");



	if(customer1)
	{
		printf("Email was Succesfully Found!! ");
		printf("\nInformation found: %s, %s, %d, %s\n",customer1->email,customer1->name,customer1->shoe_size,customer1->favorite_food);


	}
	if(customer2)
	{
		printf("Email was not within Databse!!");
	}





	printf("\nTesting the delete_customer:\n");
	
	printf("\nFirst we will make sure they are in the database:\n");
	Customer *customer3 = lookup_customer(&table,"julian@gmail.com");
	Customer *customer4 = lookup_customer(&table,"hillary@gmailcom");
	
	
	if(customer3)
	{
		printf("\nEmail was Succesfully Found!! \n");
		printf("\nInformation found: %s, %s, %d, %s\n",customer3->email,customer3->name,customer3->shoe_size,customer3->favorite_food);
	}
	if(customer4)
	{
		printf("\nEmail was Succesfully Found!! \n");
		printf("\nInformation found: %s, %s, %d, %s\n",customer4->email,customer4->name,customer4->shoe_size,customer4->favorite_food);

	}

	printf("\nNow we  are going to delete julian@gmail.com hillary@gmailcom\n");	
	delete_customer(&table,"puppylover@gmailcom");
	delete_customer(&table,"hillary@gmailcom");
	printf("\nTo confirm the deletion let us look them up after calling delete_customer:\n");
	customer3 = lookup_customer(&table,"julian@gmail.com");
	customer4 =lookup_customer(&table,"hillary@gmailcom");

	

	if(!customer4 && !customer4)
	{
		printf("\njulian@gmail.com and hillary@gmailcom  have been deleted from database!");
	}



	
printf("\nTesting save_to_file and load_from_file:\n");
    save_to_file(&table, "test_customers.tsv");
    
    HashTable new_table = {0};
    load_from_file(&new_table, "test_customers.tsv");
    Customer *loaded_customer = lookup_customer(&new_table, "mario@gmailcom");
    if (loaded_customer) {
        printf("Successfully loaded Mario: %s - %s, Size: %d, Favorite food: %s\n", loaded_customer->email, loaded_customer->name, loaded_customer->shoe_size, loaded_customer->favorite_food);
    } else {
        printf("Loading failed for mario@gmailcom\n");
    }
    
    cleanup_table(&table);
    cleanup_table(&new_table);
    printf("\nAll tests completed.\n");
}
    int main()
    {
	    running_test();
	    return 0;
    }
