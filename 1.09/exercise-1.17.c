// Exercise 1.17
// Write a program to print all input lines that are longer than 80 characters.

#include <stdio.h>

#define VISIBLE_MIN_LENGTH 80
#define TWEET_MAX_LENGTH 280

int get_tweet(char[TWEET_MAX_LENGTH]);

int main(void)
{
	int len;
	char tweet[TWEET_MAX_LENGTH];

	while((len = get_tweet(tweet)) > 0) {
		if(len >= VISIBLE_MIN_LENGTH) {
			printf("%s\n", tweet);
		}
	}
}

int get_tweet(char tweet[])
{
	int c, i;

	for (i =0; i < TWEET_MAX_LENGTH - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		tweet[i] = c;
	}

	if (c == '\n') {
		tweet[i] = c;
	}

	tweet[i] = '\0';

	return i;
}
