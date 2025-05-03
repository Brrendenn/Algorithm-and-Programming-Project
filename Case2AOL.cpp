#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel_loc {
	char location[50];
    char city[50];
    int price;
    int rooms;
    int bathroom;
    int carpark;
    char type[50];
    char furnish[50];
};

hotel_loc data[10000];
int sum = 0;

void writeFile(char name[]){
	FILE *writeFile = fopen(name, "w");
	fprintf(writeFile, "Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");
	for (int i = 0; i < sum; i++) {
		fprintf(writeFile, "%s,%s,%d,%d,%d,%d,%s,%s\n", data[i].location, data[i].city, data[i].price, 
		data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
	}
	fclose(writeFile);
}


void readFile(){
	char file_loc[100];
	FILE *readFile = fopen("file.csv", "r");
	fscanf(readFile, "%[^\n]\n", file_loc);
	sum = 0;
	while (feof(readFile) == false) {
		fscanf(readFile, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", 
		data[sum].location, data[sum].city, &data[sum].price, 
		&data[sum].rooms, &data[sum].bathroom, &data[sum].carpark, 
		data[sum].type, data[sum].furnish);
		sum++;
	}
	fclose(readFile);
}
void find(char column[], int data_int, char data_string[]){
	bool found = false;
	if (strcmp(column, "Location") == 0) {
		for (int i = 0; i < sum; i++) {
			if (strcmpi(data[i].location, data_string) == 0) {
				found = true;
				break;
			}
		}
	} else if (strcmp(column, "City") == 0) {
		for (int i = 0; i < sum; i++) {
			if (strcmpi(data[i].city, data_string) == 0) {
				found = true;
				break;
			}
		}
	} else if (strcmp(column, "Price") == 0) {
		for (int i = 0; i < sum; i++) {
			if (data[i].price == data_int) {
				found = true;
				break;
			}
		}
	} else if (strcmp(column, "Rooms") == 0) {
		for (int i = 0; i < sum; i++) {
			if (data[i].rooms == data_int) {
				found = true;
				break;
			}
		}
	}else if (strcmp(column, "Bathroom") == 0 ){
		for (int i = 0; i < sum; i++) {
			if (data[i].bathroom == data_int) {
				found = true;
				break;
			}
		}
	}else if( strcmp(column, "Carpark") == 0) {
		for (int i = 0; i < sum; i++) {
			if (data[i].carpark == data_int) {
				found = true;
				break;
			}
		}
	}else if (strcmp(column, "Type") == 0) {
		for (int i = 0; i < sum; i++) {
			if (strcmp(data[i].type, data_string) == 0) {
				found = true;
				break;
			}
		}
	}else if (strcmp(column, "Furnish") == 0) {
		for (int i = 0; i < sum; i++) {
			if( strcmp(data[i].furnish, data_string) == 0) {
				found = true;
				break;
			}
		}
	}
	
	if (found == true) {
		puts("Data found. Detail of data: ");
			
		printf("Location                  City                 Price        Rooms   Bathroom    Carpark     Type          Furnish\n");
		if (strcmp(column, "Location") == 0) {
			for (int i = 0; i < sum; i++) {
				if (strcmp(data_string, data[i].location) == 0) {
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
			}
		} else if (strcmp(column, "City") == 0) {
			for (int i = 0; i < sum; i++) {
				if (strcmp(data_string, data[i].city) == 0) {
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
			}
		} else if (strcmp(column, "Price") == 0) {
			for (int i = 0; i < sum; i++) {
				if (data[i].price == data_int) {
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
			}
		} else if (strcmp(column, "Rooms") == 0) {
			for (int i = 0; i < sum; i++ ){
				if (data[i].rooms == data_int) {
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
			}
		} else if (strcmp(column, "Bathroom") == 0) { 
			for (int i = 0; i < sum; i++) {
				if (data[i].bathroom == data_int) {
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
			}
		} else if (strcmp(column, "Carpark") == 0) {
			for (int i = 0; i < sum; i++) {
				if (data[i].carpark == data_int){
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
			}
		} else if (strcmp(column, "Type") == 0) {
			for (int i = 0; i < sum; i++) {
				if (strcmp(data_string, data[i].type) == 0) {
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
			}
		} else if (strcmp(column, "Furnish") == 0) {
			for (int i = 0; i < sum; i++) {
				if (strcmp(data_string, data[i].furnish) == 0) {
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
			}
		}
	} else {
		puts("Data not found!");
	}
}

void ascending(char column[]){
	
	if (strcmp(column, "Location") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1-i; j++) {
				if (strcmp(data[j].location, data[j+1].location) > 0) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	} else if (strcmp(column, "City") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1-i; j++) {
				if (strcmp(data[j].city, data[j+1].city) > 0) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	} else if (strcmp(column, "Price") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1-i; j++) {
				if (data[j].price > data[j+1].price) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	} else if (strcmp(column, "Rooms") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1-i; j++) {
				if (data[j].rooms > data[j+1].rooms) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}else if (strcmp(column, "Bathroom") == 0 ){
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1-i; j++) {
				if (data[j].bathroom > data[j+1].bathroom) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}else if( strcmp(column, "Carpark") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1-i; j++) {
				if (data[j].carpark > data[j+1].carpark) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}else if (strcmp(column, "Type") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1-i; j++) {
				if (strcmp(data[j].type, data[j+1].type) > 0) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}else if (strcmp(column, "Furnish") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1-i; j++) {
				if (strcmp(data[j].furnish, data[j+1].furnish) > 0) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}
	printf("Location                  City                 Price        Rooms   Bathroom    Carpark     Type          Furnish\n");
	for (int i = 0; i < 5; i++) {
		printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
		data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
	}
}

void descending(char column[]){
	
	if (strcmp(column, "Location") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1; j++) {
				if (strcmp(data[j].location, data[j+1].location) < 0) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	} else if (strcmp(column, "City") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1; j++) {
				if (strcmp(data[j].city, data[j+1].city) < 0) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	} else if (strcmp(column, "Price") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1; j++) {
				if (data[j].price < data[j+1].price) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	} else if (strcmp(column, "Rooms") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1; j++) {
				if (data[j].rooms < data[j+1].rooms) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}else if (strcmp(column, "Bathroom") == 0 ){
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1; j++) {
				if (data[j].bathroom < data[j+1].bathroom) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}else if( strcmp(column, "Carpark") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1; j++) {
				if (data[j].carpark < data[j+1].carpark) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}else if (strcmp(column, "Type") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1; j++) {
				if (strcmp(data[j].type, data[j+1].type) < 0) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}else if (strcmp(column, "Furnish") == 0) {
		for (int i = 0; i < sum-1; i++) {
			for (int j = 0; j < sum-1; j++) {
				if (strcmp(data[j].furnish, data[j+1].furnish) < 0) {
					hotel_loc temp;
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}
	printf("Location                  City                 Price        Rooms   Bathroom    Carpark     Type          Furnish\n");
	for (int i = 0; i < 5; i++) {
		printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
		data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
	}
}

int main() {
	int menu;
	readFile();
	do{
		system("cls");
		printf("What do you want to do?\n");
		printf("1. Display data\n");
		printf("2. Search data\n");
		printf("3. Sort data\n");
		printf("4. Export data\n");
		printf("5. Exit\n");
		printf("Your choice: ");
		scanf("%d", &menu);getchar();
		switch(menu){
			case 1:
				int row;
				printf("Number of rows: ");
				scanf("%d", &row);getchar();
				if (row > sum){
					row = sum;
				}
				printf("Location                  City                 Price        Rooms   Bathroom    Carpark     Type          Furnish\n");
				for (int i = 0; i < row; i++) {
					printf("%-25s %-20s %-12d %-7d %-11d %-11d %-13s %-11s\n", data[i].location, data[i].city, data[i].price, 
					data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
				}
				printf("\n\nContinue... (press enter)");
				getchar();
				break;
			case 2:
				char column[100];
				char datastring[100];
				int dataint;
				printf("Choose column (case sensitive): ");
				scanf("%s", column);
				getchar();
				printf("What data do you want to find (case sensitive)? ");
				if (strcmp(column, "Price") == 0 || strcmp(column, "Rooms") == 0 || strcmp(column, "Bathroom") == 0 || strcmp(column, "Carpark") == 0) {
					scanf("%d", &dataint);
					getchar();
				} else {
					scanf("%s", datastring);
					getchar();
				}
				if (strcmp(column, "Location") != 0 && strcmp(column, "City") != 0 && strcmp(column, "Price") != 0 && strcmp(column, "Rooms") != 0
				&& strcmp(column, "Bathroom") != 0 && strcmp(column, "Carpark") != 0 && strcmp(column, "Type") != 0 && strcmp(column, "Furnish") != 0) {
					printf("Data not found!");
				} else {
					find(column, dataint, datastring);
				}
				printf("\n\nContinue... (press enter)");
				getchar();
				break;
			case 3:
				char column2[100];
				char sort[20];
				printf("Choose column (case sensitive): ");
				scanf("%s", column2);
				getchar();
				printf("Sort ascending or descending (case sensitive)? ");
				scanf("%s", sort);
				getchar();
				if(strcmp(sort, "ascending") == 0){
					ascending(column2);
				}else if(strcmp(sort, "descending") == 0){
					descending(column2);
				}
				printf("\n\nContinue... (press enter)");
				getchar();
				break;
			case 4:
				char name[100];
				printf("File name: ");
				scanf("%s", name);
				getchar();
				strcat(name, ".csv");
				writeFile(name);
				printf("Data successfully written to file %s!\n", name);
				printf("\n\nContinue... ");
				getchar();
				break;
		}
	}while(menu != 5);
	
	return 0;
}
