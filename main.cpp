#include <iostream>
#include <math.h>

using namespace std;


double f(const double &x) {
  double f = pow(x, 2) * exp(sin(x));
  return f;
}

double fm(const double &x) {
  double f = pow(x, 2)* exp(sin(x))* (sin(5 * x));
  return f;
}

void table(std::string type, int N[19][10]) {
  int i = 0, j = 0;
  std::cout << "+-------+------------+------------+------------+------------+-------"
               "-----+------------+------------+-----------"
               "-+------------+------------+\n";
  std::cout << "|  q/P  |    0.9     |    0.91    |    0.92    |    0.93    |    "
               "0.94    |    0.95    |    0.96    | "
               "   0.97    |    0.98    |    0.91    |\n";
  std::cout << "+-------+------------+------------+------------+------------+-------"
               "-----+------------+------------+-----------"
               "-+------------+------------+\n";
  double min = 9;
  for (i = 0; i < 19; i++) {
    std::cout << "| ";
    std::cout.width(6);
    std::cout << (i + 1) * 0.005 << "| ";
    for (j = 0; j < 14; j++) { 
      min = 9;
      for (int t = 0; t < N[i][j]; t++) {
        double x = ((double)rand() / RAND_MAX) * 3 + 7;
        if (type == "унимодальная") {
          if (f(x) < f(min))
            min = x;
        } else {
          if (fm(x) < fm(min))
            min = x;
        }
      }
      std::cout.width(11);
      if (type == "унимодальная") {
        std::cout << f(min) << "| ";
      } else {
        std::cout << fm(min) << "| ";
      }
    }
    std::cout << '\n';
  }
  std::cout << "+-------+------------+------------+------------+------------+-------"
               "-----+------------+------------+-----------"
               "-+------------+------------+\n\n";
}

int main() {
  setlocale(LC_ALL, "Russian");
  int N[19][10];
  std::cout.setf(std::ios::left);
  std::cout << "+-------+------+------+------+------+------+------+------+-----"
               "-+------+------+\n";
  std::cout << "|  q/P  | 0.9  | 0.91 | 0.92 | 0.93 | 0.94 | 0.95 | 0.96 | "
               "0.97 | 0.98 | 0.99 |\n";
  std::cout << "+-------+------+------+------+------+------+------+------+-----"
               "-+------+------+\n";
  int i = 0, j = 0;
  for (double q = 0.005; q <= 0.1; q += 0.005) {
    std::cout << "| ";
    std::cout.width(6);
    std::cout << q << "| ";
    j = 0;
    for (double P = 0.9; P < 1; P += 0.01) {
      N[i][j] = int((log(1 - P)) / (log(1 - q)));
      std::cout.width(5);
      std::cout << N[i][j] << "| ";
      j++;
    }
    std::cout << '\n';
    i++;
  }
  std::cout << "+-------+------+------+------+------+------+------+------+-----"
               "-+------+------+\n\n";

  table("унимодальная", N);
  table("модальная", N);
}
