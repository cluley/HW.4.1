#include <iostream>
#include <fstream>

class Adress {
public:
	void set(std::ifstream& input);
	void get(std::ofstream& output);
private:
	std::string city;
	std::string strt;
	int bldng;
	int aptmt;
};

void Adress::set(std::ifstream& input) { 
	input >> city >> strt >> bldng >> aptmt; 
}

void Adress::get(std::ofstream& output) {
	output << city << ", " << strt << ", " << bldng << ", " << aptmt << '\n';
}

int main(int argc, char** argv) {
	int total;
	std::ifstream input("in.txt");
	input >> total;

	Adress* adresses = new Adress[total];

	for (int i = 0; i < total; i++) {
		adresses[i].set(input);
	}

	std::ofstream output("out.txt");
	output << total << '\n'; 

	for (int i = (total - 1); i > -1; i--) {
		adresses[i].get(output);
	}

	delete[] ardesses;
	input.close();
	output.close();

	return 0;
}
