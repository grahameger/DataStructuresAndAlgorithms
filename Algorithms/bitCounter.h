/*
	 bit_counter.h
  	 bit_counter
Copyright 2018 Graham Eger

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in 
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


#ifndef GRAHAMEGER_BITCOUNTER
#define GRAHAMEGER_BITCOUNTER

class bit_counter_static {
public:
	// initialize the lookup table
	bit_counter_static() {
		// fill out the lookup table
		for (size_t i = 0; i < 256; ++i)
		{
			uint8_t count = 0;
			// shifty business
			for (; i; i >>=1) {
				++count;
			}
			lookup[i] = count;
		}
	}
	static uint8_t arr[256];
};

// given an array of bytes length len, return the number of set bits
// works on arrays of size 32 bit integers or greater, multiples
// obviously can be edited to adjust that fact
class bit_counter {
public:
	size_t count(uint32_t * arr, size_t len) {
		size_t count = 0;
		// no shifting stuff here
		unsigned char * data = nullptr;
		for (size_t i = 0; i < len; ++i) {
			// we'll do 4 per loop 
			data = (unsigned char *)&arr[i];
			// this works for 32 bit and 64 bit ints
			// change number of lookups for byte in the size of your int
			// pretty sure we can change this with templating
			count += lookup.arr[data[0]];
			count += lookup.arr[data[1]];
			count += lookup.arr[data[2]];
			count += lookup.arr[data[3]];
		}
		return count;
	}
private:
	bit_counter_static lookup;
};


#endif /* GRAHAMEGER_BITCOUNTER */
