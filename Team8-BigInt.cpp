#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>  // for runtime_error

using namespace std;

class BigInt {
    string number;     // Stores the number as a string
    bool isNegative;   // True if number is negative

    // Remove unnecessary leading zeros from the number
    void removeLeadingZeros() { // --omar--
        // TODO: Implement this function
        while(number[0] == '0'){
            number.erase(number.begin());
        }
    }

    // Compare absolute values of two BigInts (ignore signs)
    // Returns: 1 if |this| > |other|, 0 if equal, -1 if |this| < |other|
    int compareMagnitude(const BigInt& other) const { // --omar--
        // TODO: Implement this function
        string s = other.number;
        if(s[0] == '-') s.erase(s.begin());
        if(number.length() > s.length()){
            return 1;
        }
        else if (number.length() < s.length()){
            return -1;
        }
        else{
            int i = 0;
            while(i < number.length()){
                if(number[i] > s[i]){
                    return 1;
                }
                else if(number[i] < s[i]){
                    return -1;
                }
                i++;
            }
        }
        return 0;
    }

    string digit_to_string(long long x){
        switch(x){
            case 0: return "0";
            case 1: return "1";
            case 2: return "2";
            case 3: return "3";
            case 4: return "4";
            case 5: return "5";
            case 6: return "6";
            case 7: return "7";
            case 8: return "8";
            case 9: return "9";
            default: return "invalid";
        }
    }

    long long Power(int x, int y){
        return pow(x, y);
    }

public:
    // Default constructor - initialize to zero
    BigInt() { // --omar--
        // TODO: Implement this constructor
        number = "0";
        isNegative = false;
    }

    // Constructor from 64-bit integer
    BigInt(long long value) { // --omar--
        // TODO: Implement this constructor
        isNegative = (value < 0 ? true : false);
        long long n;
        if(isNegative){
            number += "-";
            n = -value;
        }
        else
            n = value;
        long long m = n;
        int digit, Size = 0;
        while(m > 0){//12345
            Size++;
            m /= 10;
        }
        while(Size > 1){
            if(n >= pow(10, Size - 1) && n < pow(10, Size)){
                digit = (n - n % Power(10, Size - 1))/Power(10, Size - 1);
                number += digit_to_string(digit);
                n -= digit*Power(10, Size - 1);
            }
            else{
                number += "0";
            }
            Size--;
        }
        number += digit_to_string(n);
    }

    // Constructor from string representation
    BigInt(const string& str) { // --omar--
        // TODO: Implement this constructor
        number = str;
        isNegative = (str[0] == '-' ? true : false);
    }

    // Copy constructor
    BigInt(const BigInt& other) { // --omar--
        // TODO: Implement this constructor
        number = other.number;
        isNegative = other.isNegative;
    }

    // Destructor
    ~BigInt() {
        // TODO: Implement if needed
        /*number = "";
        isNegative = false;*/
    }

    // Assignment operator
    BigInt& operator=(const BigInt& other) { // --omar--
        // TODO: Implement this operator
        number = other.number;
        isNegative = other.isNegative;
        return *this;
    }

    // Unary negation operator (-x)
    BigInt operator-() const { // --george--
        BigInt result;
        // TODO: Implement negation logic
        return result;
    }

    // Unary plus operator (+x)
    BigInt operator+() const { // --george--
        BigInt result;
        // TODO: Implement this operator
        return result;
    }

    // Addition assignment operator (x += y)
    BigInt& operator+=(const BigInt& other) { // --salma--
        // TODO: Implement this operator
        return *this;
    }

    // Subtraction assignment operator (x -= y)
    BigInt& operator-=(const BigInt& other) { // --salma--
        // TODO: Implement this operator
        return *this;
    }

    // Multiplication assignment operator (x *= y)
    BigInt& operator*=(const BigInt& other) { // --marwan--
        // TODO: Implement this operator
        return *this;
    }

    // Division assignment operator (x /= y)
    BigInt& operator/=(const BigInt& other) { // --marwan--
        // TODO: Implement this operator
        return *this;
    }

    // Modulus assignment operator (x %= y)
    BigInt& operator%=(const BigInt& other) { // --marwan--
        // TODO: Implement this operator
        return *this;
    }

    // Pre-increment operator (++x)
    BigInt& operator++() { // --salma--
        // TODO: Implement this operator
        return *this;
    }

    // Post-increment operator (x++)
    BigInt operator++(int) { // --salma--
        BigInt temp;
        // TODO: Implement this operator
        return temp;
    }

    // Pre-decrement operator (--x)
    BigInt& operator--() { // --salma--
        // TODO: Implement this operator
        return *this;
    }

    // Post-decrement operator (x--)
    BigInt operator--(int) { // --salma--
        BigInt temp;
        // TODO: Implement this operator
        return temp;
    }

    // Convert BigInt to string representation
    string toString() const { // --omar--
        // TODO: Implement this function
        return number;
    }

    // Output stream operator (for printing)
    friend ostream& operator<<(ostream& os, const BigInt& num) { // --george--
        // TODO: Implement this operator
        return os;
    }

    // Input stream operator (for reading from input)
    friend istream& operator>>(istream& is, BigInt& num) { // --george--
        // TODO: Implement this operator
        return is;
    }

    // Friend declarations for comparison operators
    friend bool operator==(const BigInt& lhs, const BigInt& rhs);
    friend bool operator<(const BigInt& lhs, const BigInt& rhs);
};

// Binary addition operator (x + y)
BigInt operator+(BigInt lhs, const BigInt& rhs) { // --salma--
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Binary subtraction operator (x - y)
BigInt operator-(BigInt lhs, const BigInt& rhs) { // --salma--
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Binary multiplication operator (x * y)
BigInt operator*(BigInt lhs, const BigInt& rhs) { // --marwan--
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Binary division operator (x / y)
BigInt operator/(BigInt lhs, const BigInt& rhs) { // --marwan--
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Binary modulus operator (x % y)
BigInt operator%(BigInt lhs, const BigInt& rhs) { // --marwan--
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Equality comparison operator (x == y)
bool operator==(const BigInt& lhs, const BigInt& rhs) { // --habiba--
    // TODO: Implement this operator
    return false;
}

// Inequality comparison operator (x != y)
bool operator!=(const BigInt& lhs, const BigInt& rhs) { // --habiba--
    // TODO: Implement this operator
    return false;
}

// Less-than comparison operator (x < y)
bool operator<(const BigInt& lhs, const BigInt& rhs) { // --habiba--
    // TODO: Implement this operator
    return false;
}

// Less-than-or-equal comparison operator (x <= y)
bool operator<=(const BigInt& lhs, const BigInt& rhs) { // --habiba--
    // TODO: Implement this operator
    return false;
}

// Greater-than comparison operator (x > y)
bool operator>(const BigInt& lhs, const BigInt& rhs) { // --habiba--
    // TODO: Implement this operator
    return false;
}

// Greater-than-or-equal comparison operator (x >= y)
bool operator>=(const BigInt& lhs, const BigInt& rhs) { // --habiba--
    // TODO: Implement this operator
    return false;
}

int main() {
    cout << "=== BigInt Class Test Program ===" << endl << endl;
    cout << "NOTE: All functions are currently empty." << endl;
    cout << "Your task is to implement ALL the functions above." << endl;
    cout << "The tests below will work once you implement them correctly." << endl << endl;

    // Test 1: Constructors and basic output
    cout << "1. Constructors and output:" << endl;
    BigInt a(12345);              // Should create BigInt from integer
    BigInt b("-67890");           // Should create BigInt from string
    BigInt c("0");                // Should handle zero correctly
    BigInt d = a;                 // Should use copy constructor
    cout << "a (from int): " << a.toString() << endl;        // Should print "12345"
    cout << "b (from string): " << b.toString() << endl;     // Should print "-67890"
    cout << "c (zero): " << c.toString() << endl;            // Should print "0"
    cout << "d (copy of a): " << d.toString() << endl << endl; // Should print "12345"
    /*
    // Test 2: Arithmetic operations
    cout << "2. Arithmetic operations:" << endl;
    cout << "a + b = " << a + b << endl;          // Should calculate 12345 + (-67890)
    cout << "a - b = " << a - b << endl;          // Should calculate 12345 - (-67890)
    cout << "a * b = " << a * b << endl;          // Should calculate 12345 * (-67890)
    cout << "b / a = " << b / a << endl;          // Should calculate (-67890) / 12345
    cout << "a % 100 = " << a % BigInt(100) << endl << endl; // Should calculate 12345 % 100

    // Test 3: Relational operators
    cout << "3. Relational operators:" << endl;
    cout << "a == d: " << (a == d) << endl;       // Should be true (12345 == 12345)
    cout << "a != b: " << (a != b) << endl;       // Should be true (12345 != -67890)
    cout << "a < b: " << (a < b) << endl;         // Should be false (12345 < -67890)
    cout << "a > b: " << (a > b) << endl;         // Should be true (12345 > -67890)
    cout << "c == 0: " << (c == BigInt(0)) << endl << endl; // Should be true (0 == 0)

    // Test 4: Unary operators and increments
    cout << "4. Unary operators and increments:" << endl;
    cout << "-a: " << -a << endl;                 // Should print "-12345"
    cout << "++a: " << ++a << endl;               // Should increment and print "12346"
    cout << "a--: " << a-- << endl;               // Should print "12346" then decrement
    cout << "a after decrement: " << a << endl << endl; // Should print "12345"

    // Test 5: Large number operations
    cout << "5. Large number operations:" << endl;
    BigInt num1("12345678901234567890");
    BigInt num2("98765432109876543210");
    cout << "Very large addition: " << num1 + num2 << endl;
    cout << "Very large multiplication: " << num1 * num2 << endl << endl;

    // Test 6: Edge cases and error handling
    cout << "6. Edge cases:" << endl;
    BigInt zero(0);
    BigInt one(1);
    try {
        BigInt result = one / zero;               // Should throw division by zero error
        cout << "Division by zero succeeded (unexpected)" << endl;
    } catch (const runtime_error& e) {
        cout << "Division by zero correctly threw error: " << e.what() << endl;
    }
    cout << "Multiplication by zero: " << one * zero << endl;        // Should be "0"
    cout << "Negative multiplication: " << BigInt(-5) * BigInt(3) << endl;  // Should be "-15"
    cout << "Negative division: " << BigInt(-10) / BigInt(3) << endl;       // Should be "-3"
    cout << "Negative modulus: " << BigInt(-10) % BigInt(3) << endl;        // Should be "-1"
    */

    return 0;
}
