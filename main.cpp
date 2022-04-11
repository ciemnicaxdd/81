#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class file {
    ifstream in;
    ifstream in2;
    ofstream out;

public:

    vector <vector <int>> numbers;
    vector <vector <int>> numbers2;
    file();
    ~file();

    void positive();
    void oneLine();
    void biggest();

};

file::file() {
    in.open("C:\\wspolrzedne.txt");
    in2.open("C:\\wspolrzedneTR.txt");


    int temp;
    for (int j = 0; j < 100; j++) {

        numbers.push_back(vector <int>());
        for (int i = 0; i < 6; i++) {
            in >> temp;
            numbers[j].push_back(temp);
        }

    }
    int temp2;
    for (int j = 0; j < 100; j++) {

        numbers2.push_back(vector <int>());
        for (int i = 0; i < 6; i++) {
            in2 >> temp2;
            numbers2[j].push_back(temp2);
        }

    }

}

file::~file() {
    in.close();
    out.close();
}

void file::positive() {
    int counter = 0;
    for (int i = 0; i < numbers.size(); i++) {
        
        if (numbers[i][0] > 0 && numbers[i][1] > 0 && numbers[i][2] > 0 && numbers[i][3] > 0 && numbers[i][4] > 0 && numbers[i][5] > 0 ) {
            counter++;
        }   
        
    }
    cout << counter << endl;
}

void file::oneLine() {
    int counter = 0;
    for (int i = 0; i < numbers.size(); i++) {
    
        if ((numbers[i][2] - numbers[i][0])*(numbers[i][5]- numbers[i][1]) == (numbers[i][3] - numbers[i][1])*(numbers[i][4] - numbers[i][0])){
            counter++;
        }

    }
    cout << counter<<endl;
}

void file::biggest() {
    double max = sqrt(pow(numbers2[0][0] - numbers2[0][2], 2) + pow(numbers2[0][1] - numbers2[0][3], 2)) + sqrt(pow(numbers2[0][2] - numbers2[0][4], 2) + pow(numbers2[0][3] - numbers2[0][5], 2)) + sqrt(pow(numbers2[0][0] - numbers2[0][4], 2) + pow(numbers2[0][1] - numbers2[0][5], 2));
    int maxxa = numbers2[0][0], maxya = numbers2[0][1], maxxb = numbers2[0][2], maxyb = numbers2[0][3], maxxc = numbers2[0][4], maxyc = numbers2[0][5];
    for (int i = 0; i < numbers2.size(); i++) {
        double ab = sqrt(pow(numbers2[i][0] - numbers2[i][2], 2) + pow(numbers2[i][1] - numbers2[i][3], 2));
        double bc = sqrt(pow(numbers2[i][2] - numbers2[i][4], 2) + pow(numbers2[i][3] - numbers2[i][5], 2));
        double ac = sqrt(pow(numbers2[i][0] - numbers2[i][4], 2) + pow(numbers2[i][1] - numbers2[i][5], 2));
        
        if ((ab + bc > ac) || (ab+ac > bc) || (ac + bc > ab)) {
            if (ab + bc + ac > max) {
                max = ab + bc + ac;
                maxxa = numbers2[i][0], maxya = numbers2[i][1], maxxb = numbers2[i][2], maxyb = numbers2[i][3], maxxc = numbers2[i][4], maxyc = numbers2[i][5];

            }
        }

        
    }
    cout << ceil(max*100)/100<<endl;
    cout << maxxa << "," << maxya << " " << maxxb << "," << maxyb << " " << maxxc << "," << maxyc << endl;
}

int main()
{
    file f;
    f.positive();
    f.oneLine();
    f.biggest();
}
