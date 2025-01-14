/* sched: a simple scheduler written in C.
 * Copyright (C) 2015 Cyphar
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be included in
 *    all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "async.h"
#include "sched.h"

struct sched_t scheduler;

/* ====================== */
/* NOTE: ARDUINO EMULATOR */
/* ====================== */



void setup(void) {
	sched_init(&scheduler);

	struct tone_t *tone440 = malloc(sizeof(struct tone_t));
	tone_clear(tone440);
	tone440->pin = 13;
	tone440->amplitude = 0.5;
	tone440->frequency = 440;
	tone440->start = 0;
	tone440->end = 3000;
	async_tone(&scheduler, tone440);

	struct tone_t *tone880 = malloc(sizeof(struct tone_t));
	tone_clear(tone880);
	tone880->pin = 13;
	tone880->amplitude = 0.6;
	tone880->frequency = 880;
	tone880->start = 1000;
	tone880->end = 2000;
	async_tone(&scheduler, tone880);
}

void loop(void) {
	sched_tick(&scheduler);
}

int main(void) {
	setup();

	while(true)
		loop();

	return 0;
}
