#pragma once

#include <pthread.h>

typedef struct countdownlatch {
	int counter;
	pthread_mutex_t lock;
	pthread_cond_t waiters;
} countdownlatch_t;

void countdownlatch_init(countdownlatch_t * cdl, int initial_count);
void countdownlatch_cleanup(countdownlatch_t * cdl);

void countdownlatch_countdown(countdownlatch_t * cdl);
void countdownlatch_await(countdownlatch_t * cdl);
