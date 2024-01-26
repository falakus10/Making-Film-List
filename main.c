#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum filmGenre {
    drama = 1, horror, thriller
} Genre;

typedef struct cinemaFilm {
    char name[100];
    int productionYear;
    float imdbRating;
    Genre filmGenre;
} Film;

Film *createFilm(char *name, int productionYear, float imdbRating, Genre filmGenre);
void printGenre(Genre filmGenre);
void printFilms(Film *films, int count);

int main() {
    int count;

    printf("Enter the number of films: ");
    scanf("%d", &count);
    getchar(); // Consume the newline character in the buffer

    Film *filmArray = (Film *)malloc(count * sizeof(Film));

    for (int i = 0; i < count; i++) {
        Film newFilm;

        printf("Enter the Film Name: ");
        fgets(newFilm.name, sizeof(newFilm.name), stdin);

        printf("Enter the Production Year: ");
        scanf("%d", &newFilm.productionYear);

        printf("Enter the IMDB Rating: ");
        scanf("%f", &newFilm.imdbRating);

        printf("Enter the Film Genre (drama=1, horror=2, thriller=3): ");
        scanf("%d", &newFilm.filmGenre);
        getchar(); // Consume the newline character in the buffer

        Film *ptrFilm = createFilm(newFilm.name, newFilm.productionYear, newFilm.imdbRating, newFilm.filmGenre);
        filmArray[i] = *ptrFilm;
        free(ptrFilm);
    }

    printFilms(filmArray, count);

    free(filmArray);

    return 0;
}

Film *createFilm(char *name, int productionYear, float imdbRating, Genre filmGenre) {
    Film *ptrFilm = (Film *)malloc(sizeof(Film));
    strcpy(ptrFilm->name, name);
    ptrFilm->productionYear = productionYear;
    ptrFilm->imdbRating = imdbRating;
    ptrFilm->filmGenre = filmGenre;
    return ptrFilm;
}

void printGenre(Genre filmGenre) {
    switch (filmGenre) {
        case drama:
            printf("DRAM");
            break;
        case horror:
            printf("HORROR");
            break;
        case thriller:
            printf("THRILLER");
            break;
        default:
            printf("ERROR!");
    }
}

void printFilms(Film *films, int count) {
    for (int i = 0; i < count; i++) {
        printf("Film Name: %s", films[i].name);
        printf("Production Year: %d\n", films[i].productionYear);
        printf("IMDB Rating: %.1f\n", films[i].imdbRating);
        printf("Film Genre: ");
        printGenre(films[i].filmGenre);
        printf("\n-----------------\n");
    }
}
