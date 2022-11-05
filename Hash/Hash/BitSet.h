#pragma once
#include <vector>

namespace atm
{
	template<size_t N>
	class BitSet
	{
	public:
		BitSet()
		{
			_bits.resize(N / 32+1,0);
		}

		//½«xÓ³ÉäÎª1
		void Set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_bits[i] |= (1 << j);
		}

		void Reset(size_t)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_bit[i] &=( ~(1 << j));
		}

		bool Test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			return _bits[i] & (1 << j);

		}


	private:
		vector<int> _bits;
	};


	//void TestBitSet()
	//{
	//	BitSet<-1> bs;
	//}
}
