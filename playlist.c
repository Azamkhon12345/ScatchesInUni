/*
 * first.c
 *
 *  Created on: 28 мар. 2020 г.
 *      Author: Azamkhon
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct song{
	char title[200];
	char artist[200];
	char genre[200];
	int year;
	int length;
	int playlist;

}song;

void add_song(song *a,int size){
	printf("Write titel:");
	scanf("%s",a[size].title);
	printf("\n");
	printf("Write artist:");
	scanf("%s",a[size].artist);
	printf("\n");
	printf("Write genre:");
	scanf("%s",a[size].genre);
	printf("\n");
	printf("Write year:");
	scanf("%d",&a[size].year);
	printf("\n");
	printf("Write length:");
	scanf("%d",&a[size].length);
	printf("\n");
	printf("Write playlist [1,9]:");
	scanf("%d",&a[size].playlist);
	if ((a[size].playlist) < 0 || a[size].playlist > 9){
		a[size].playlist=0;
	}
	printf("\n");
}

void add_song_in_playlist(song *a,int size){
	char title[200];
	int playlist,i;
	printf("Write a title of song: ");
	scanf("%s",title);
	printf("Write a playlist number to change: ");
	scanf("%d",&playlist);
	for(i=0;i<size;i++){
			if (0 == strcmp(a[i].title , title)){
				a[i].playlist = playlist;
			}
		}
	printf("succesefuly added ! ");
}

void print_song(song *a,int size){
	//find music and print all information about this song
	int i=0;
	char title[200];
	printf("What is title of song:");
	scanf("%s",title);
	printf("\n");
	for(i=0;i<size;i++){
		if (0 == strcmp(a[i].title , title)){
			printf("Artist: %s \n",a[i].artist);
			printf("Genre: %s \n",a[i].genre);
			printf("Year: %d \n",a[i].year);
			printf("Length: %d \n",a[i].length);
			printf("Playlist: %d \n",a[i].playlist);
		}
	}

}

void print_genre(song *a,int size){
	// should print all titles of song realted to givev genre
	//or return "no song of this genre"
	int i=0;
	int flag = 0;
	char genre[200];
	printf("What is genre of song:");
	scanf("%s",genre);
	printf("\n");
	for(i=0;i<size;i++){
		if (0 == strcmp(a[i].genre , genre)){
			printf("Title: %s \n",a[i].title);
			flag=1;
		}
	}
	if (flag==0){
		printf("no song of this genre. \n");
	}
}

float average_length(song *a,int size){
	//return the sum of length of all musics/count of musics
	int i;
	int sum=0;
	for(i=0;i<size;i++){
			sum += a[i].length;
		}
	return sum/size;
}

void top_playlist(song *a,int size){
	// print the album with maximum playlist
	int playlist[10]={0,0,0,0,0,0,0,0,0,0};
	int i;
	for(i=0;i<size;i++){
		playlist[a[i].playlist] += 1;
		}
	//find max in range 1 to 9
	int max=playlist[1];
	int album_id=1;
	for (i=1;i<10;i++){
		if(max < playlist[i]){
			max = playlist[i];
			album_id=i;
		}
	}
	if (max==0){
		printf("there is no playlist with musics\n");
	}else{
		printf("Here musics:\n");
		for(i=0;i<size;i++){
			if(album_id==a[i].playlist){
				printf("%s \n",a[i].title);
			}
		}
	}

}

// playlists index [1,9] each can have infinity musics

int main(void){
	int size = 0;
	song *songs = (song *)malloc(sizeof(song));
	char cmd[80];
	setvbuf(stdout,NULL,_IONBF,0);
	char command[80];
do{
	printf("Command: ");
	scanf("%s",cmd);
	strcpy(command,cmd);
	// CHECKING the function
	if(0 == strcmp(command,"add_song")){
		add_song(songs,size);
		printf("\n");
		size++;
		songs = (song *)realloc(songs,size*sizeof(song));
	}

	if(0 == strcmp(command,"print_song")){
		print_song(songs,size);
		printf("\n");
		size++;
		songs = (song *)realloc(songs,size*sizeof(song));
	}

	if(0 == strcmp(command,"print_genre")){
		print_genre(songs,size);
		printf("\n");
		size++;
		songs = (song *)realloc(songs,size*sizeof(song));
	}

	if(0 == strcmp(command,"average_length")){
		printf("%f",average_length(songs,size));
		printf("\n");
		size++;
		songs = (song *)realloc(songs,size*sizeof(song));
	}
	if(0 == strcmp(command,"top_playlist")){
		top_playlist(songs,size);
		printf("\n");
		size++;
		songs = (song *)realloc(songs,size*sizeof(song));

	}
	if(0 == strcmp(command,"add_song_in_playlist")){
		add_song_in_playlist(songs,size);
		printf("\n");
		size++;
		songs = (song *)realloc(songs,size*sizeof(song));
	}
	//exit
	 command[5] = '\0';

} while( 0 != strcmp(command,"exit") );
	return 0;
}
