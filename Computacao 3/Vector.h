#include <iostream>
#include <vector>

class Vector
{
	public:
		Vector() { }
		Vector(int n) { for (int i=0; i<n; i++) vetor.push_back(0); }
		Vector(std::vector<int> novo) { vetor = novo; }

		int operator[] (int n)
		{
			if (n>=vetor.size())
				throw std::out_of_range("Quebra de limite do vetor");
			return vetor[n];
		}

		const int operator[] (int n) const
		{
			if (n>=vetor.size())
				throw std::out_of_range("Quebra de limite do vetor");
			return vetor[n];
		}
		void print (std::ostream& saida)
		{
			for( int i=0; i<vetor.size(); i++)
				saida << vetor[i] << ' ';
			saida << std::endl;
		}
	
	private:
		std::vector<int> vetor;
};
