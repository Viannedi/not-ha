#pragma once
#include <stdio.h>
#include <malloc.h>  
#include <stdlib.h>
#include <string.h>
FILE* file;


struct Film {
	char name[50];
	char genre[50];
	char director[50];
	char dateOfStreaming[100];
	int time;
	int countSoldTikets;
	int costs;


};
int n;
struct Film films[123];
char method[2];


void closeFile() { 
	if(file != NULL)
		fclose(file);


}

void printStruct() {
	for (int i = 0; i < n; i++) {
		printf("Name: %s\nGenre:%s\nDirector: %s\nDate: %s\nTime: %d\nSold Tickets: %d\nCosts: %d\n\n", films[i].name, films[i].genre, films[i].director,
			films[i].dateOfStreaming, films[i].time, films[i].countSoldTikets, films[i].costs);
	}
}
void readFile(char filename[50]) {
	file = fopen(filename, "rt");

	if (file == NULL) {
		printf("Error openning file.\n");
		return;
	}
	int i = 0;
	while (fscanf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d", &films[i].name, &films[i].genre, &films[i].director,
		&films[i].dateOfStreaming, &films[i].time, &films[i].countSoldTikets, &films[i].costs) != EOF) {
		i++;
	}
	n = i;
	fclose(file);
	printStruct();
}
void openFile(char filename[50]) {
	file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error openning file.\n");
		return;
	}
	readFile(filename);
}

void addRecord(char filename[50]) {
	file = fopen(filename, "a");

	struct Film film;

	printf("Name: ");
	scanf("%s", &film.name);

	printf("Genre: ");
	scanf("%s", &film.genre);

	printf("Director: ");
	scanf("%s", &film.director);

	printf("Date of streaming: ");
	scanf("%s", &film.dateOfStreaming);

	printf("Time: ");
	scanf("%d", &film.time);

	printf("SoldTickets: ");
	scanf("%d", &film.countSoldTikets);

	printf("Costs: ");
	scanf("%d", &film.costs);

	fprintf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n", film.name, film.genre, film.director,
		film.dateOfStreaming, film.time, film.countSoldTikets, film.costs);
	
	films[n] = film;
	n++;
	fclose(file);

}


void createFile(char filename[50]) {
	printf("Enter count of rows: ");
	scanf("%d", &n);

	file = fopen(filename, "wt");

	for (int i = 0; i < n; i++) {
		printf("Name: ");
		scanf("%s", &films[i].name);

		printf("Genre: ");
		scanf("%s", &films[i].genre);

		printf("Director: ");
		scanf("%s", &films[i].director);

		printf("Date of streaming: ");
		scanf("%s", &films[i].dateOfStreaming);

		printf("Time: ");
		scanf("%d", &films[i].time);

		printf("SoldTickets: ");
		scanf("%d", &films[i].countSoldTikets);

		printf("Costs: ");
		scanf("%d", &films[i].costs);
	}
	 
	for (int i = 0; i < n; i++) {
		fprintf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n", films[i].name, films[i].genre, films[i].director,
			films[i].dateOfStreaming, films[i].time, films[i].countSoldTikets, films[i].costs);
	}

	fclose(file);
}


void mostProfitableSessions(char filename[50]) {
	file = fopen(filename, "r");
	struct Film profitableFilms[123];
	int newLen = 0;
	int isNew = 1;

	int firstPrice;
	int secondPrice; 

	for (int i = 0; i < n; i++) {
		isNew = 1;
		for (int k = 0; k < newLen; k++) {
			if (strcmp(films[i].genre, profitableFilms[k].genre) == 0) {
				isNew = 0;
				firstPrice = films[i].countSoldTikets * films[i].costs;
				secondPrice = profitableFilms[k].countSoldTikets * profitableFilms[k].costs;
				if (firstPrice > secondPrice) {
					profitableFilms[k] = films[i];
				}
			}
		}
		if (isNew) {
			profitableFilms[newLen] = films[i];
			newLen++;
		}
	}

	for (int i = 0; i < newLen; i++) {
		printf("%s\n%s\n%s\n%s\n%d\n%d\n%d\n\n", profitableFilms[i].name, profitableFilms[i].genre, profitableFilms[i].director,
			profitableFilms[i].dateOfStreaming, profitableFilms[i].time, profitableFilms[i].countSoldTikets, profitableFilms[i].costs);
	}
	fclose(file);
}