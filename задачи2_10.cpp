#include <vector>
#include <cmath>

class Polynomial {
private:
    vector<double> coefficients;

public:
    // Конструктор, принимающий вектор коэффициентов
    Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {}

    // Метод для вычисления значения полинома в точке x
    double calc(double x) const {
        double result = 0.0;
        double power = 1.0; // Степень x, начиная с x^0

        // Проходим по всем коэффициентам и складываем их, умноженные на соответствующую степень x
        for (double coef : coefficients) {
            result += coef * power;
            power *= x;
        }

        return result;
    }

    // Перегрузка оператора сложения для полиномов
    Polynomial operator+(const Polynomial& other) const {
        // Создаем новый полином, где коэффициенты будут суммой коэффициентов текущего и другого полинома
        vector<double> resultCoeffs(max(coefficients.size(), other.coefficients.size()), 0.0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            resultCoeffs[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            resultCoeffs[i] += other.coefficients[i];
        }
        return Polynomial(resultCoeffs);
    }

    // Перегрузка оператора умножения для полиномов
    Polynomial operator*(const Polynomial& other) const {
        // Создаем новый полином, где коэффициенты будут результатом перемножения коэффициентов текущего и другого полинома
        vector<double> resultCoeffs(coefficients.size() + other.coefficients.size() - 1, 0.0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(resultCoeffs);
    }
};
