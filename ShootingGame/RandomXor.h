#pragma once

class RandomXor {
public:
	RandomXor()
	{
		x = 0x12345679, y = 0x11111111, z = 0x19991117, w = 0x20221106;
	}

	/// [0, UINT_MAX]‚Å—”¶¬
	unsigned int randUInt()
	{
		unsigned int t;
		t = (x ^ (x << 11)); x = y; y = z; z = w;
		return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}

	/// [0, term)‚Å—”¶¬
	int rand(int term) {
		return int(randUInt() & 0x7FFFFFFF) % term;
	}

	/// [min, term)‚Å—”¶¬
	int rand(int min, int term) {
		return min + rand(term - min);
	}

	/// [0, 1.0f)‚Å—”¶¬
	float randFloat() {
		return static_cast<float>(randUInt() % 0x7FFFFFFF) / static_cast<float>(0x7FFFFFFF);
	}

	float randFloat(float term) {
		return randFloat(0, term);
	}

	float randFloat(float min, float term) {
		return min + randFloat() * (term - min);
	}

private:
	unsigned int x, y, z, w;
};