#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept> // for runtime_error
#include <algorithm> //included this for std::reverse()
#include <vector>

using namespace std;

class BigInt
{
    string number;   // Stores the number as a string
    bool isNegative; // True if number is negative

    // Remove unnecessary leading zeros from the number
    void removeLeadingZeros()
    { // --omar--
        // TODO: Implement this function
        while (number[0] == '0' && number.size() > 1)
        { // check if the number isnt only a zero to avoid out of bound crash
            number.erase(number.begin());
        }
    }

    // Compare absolute values of two BigInts (ignore signs)
    // Returns: 1 if |this| > |other|, 0 if equal, -1 if |this| < |other|
    int compareMagnitude(const BigInt &other) const
    { // --omar--
        string s1 = number, s2 = other.number;
        if(s1[0] == '-'){
            s1.erase(s1.begin());
        }
        while (s1[0] == '0' && s1.size() > 1)
        {
            s1.erase(s1.begin());
        }

        if(s2[0] == '-'){
            s2.erase(s2.begin());
        }
        while (s2[0] == '0' && s2.size() > 1)
        {
            s2.erase(s2.begin());
        }

        if (s1.length() > s2.length())
        {
            return 1;
        }
        else if (s1.length() < s2.length())
        {
            return -1;
        }
        else
        {
            int i = 0;
            while (i < s1.length())
            {
                if (s1[i] > s2[i])
                {
                    return 1;
                }
                else if (s1[i] < s2[i])
                {
                    return -1;
                }
                i++;
            }
        }
        return 0;
    }

    string digit_to_string(long long x)
    {
        switch (x)
        {
        case 0:
            return "0";
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        default:
            return "invalid";
        }
    }

    long long Power(int x, int y)
    {
        return pow(x, y);
    }

    string add(const string &a, const string &b)
    {
        string res;
        string x = a, y = b;
        int carry = 0, i = 0, sum = 0;

        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());

        while (i < x.size() || i < y.size() || carry)
        {
            int d1, d2;
            if (i < x.size())
            {
                d1 = x[i] - '0';
            }
            else
            {
                d1 = 0;
            }

            if (i < y.size())
            {
                d2 = y[i] - '0';
            }
            else
            {
                d2 = 0;
            }

            sum = d1 + d2 + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
            i++;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    string subtract(const string &a, const string &b)
    {
        string x = a, y = b;
        string res;
        int borrow = 0, i = 0, diff = 0;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());

        while (i < x.size())
        {
            int d1, d2;
            d1 = x[i] - '0' - borrow;
            if (i < y.size())
            {
                d2 = y[i] - '0';
            }
            else
            {
                d2 = 0;
            }

            if (d1 < d2)
            {
                d1 += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            diff = d1 - d2;
            res.push_back(diff + '0');
            i++;
        }

        reverse(res.begin(), res.end());

        while (res[0] == '0' && res.size() > 1)
        {
            res.erase(res.begin());
        }

        return res;
    }

public:
    // Default constructor - initialize to zero
    BigInt()
    { // --omar--
        // TODO: Implement this constructor
        number = "0";
        isNegative = false;
    }

    // Constructor from 64-bit integer
    BigInt(long long value)
    { // --omar--
        // TODO: Implement this constructor
        isNegative = (value < 0 ? true : false);
        long long n;
        if (isNegative)
        {
            n = -value;
        }
        else
            n = value;
        long long m = n;
        int digit, Size = 0;
        while (m > 0)
        { // 12345
            Size++;
            m /= 10;
        }
        while (Size > 1)
        {
            if (n >= pow(10, Size - 1) && n < pow(10, Size))
            {
                digit = (n - n % Power(10, Size - 1)) / Power(10, Size - 1);
                number += digit_to_string(digit);
                n -= digit * Power(10, Size - 1);
            }
            else
            {
                number += "0";
            }
            Size--;
        }
        number += digit_to_string(n);
    }

    // Constructor from string representation
    BigInt(const string &str)
    { // --omar--
        // TODO: Implement this constructor
        number = str;
        isNegative = (str[0] == '-' ? true : false);
        if (isNegative)
        {
            number.erase(number.begin());
        }
        this->removeLeadingZeros();
    }

    // Copy constructor
    BigInt(const BigInt &other)
    { // --omar--
        // TODO: Implement this constructor
        number = other.number;
        isNegative = other.isNegative;
    }

    // Destructor
    ~BigInt()
    {
        // TODO: Implement if needed
        /*number = "";
        isNegative = false;*/
    }

    // Assignment operator
    BigInt &operator=(const BigInt &other)
    { // --omar--
        // TODO: Implement this operator
        number = other.number;
        isNegative = other.isNegative;
        return *this;
    }

    // Unary negation operator (-x)
    BigInt operator-() const
    { // --george--
        BigInt result;
        // TODO: Implement negation logic
        return result;
    }

    // Unary plus operator (+x)
    BigInt operator+() const
    { // --george--
        BigInt result;
        // TODO: Implement this operator
        return result;
    }

    // Addition assignment operator (x += y)
    BigInt &operator+=(const BigInt &other)
    { // --salma--
        // TODO: Implement this operator
        *this = *this + other ;
        return *this  ;
    }

    // Subtraction assignment operator (x -= y)
    BigInt &operator-=(const BigInt &other)
    { // --salma--
        // TODO: Implement this operator
        *this = *this - other ;
        return *this ;
    }

    // Multiplication assignment operator (x *= y)
    BigInt &operator*=(BigInt other)
    { // --marwan--
        bool resultNegative = (isNegative != other.isNegative);

        string a = number;
        string b = other.number;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = a.length();
        int m = b.length();
        vector<int> k(n + m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                k[i + j] += (a[i] - '0') * (b[j] - '0');
            }
        }
        for (int i = 0; i < (int)k.size(); i++)
        {
            if (k[i] >= 10)
            {
                k[i + 1] += k[i] / 10;
                k[i] %= 10;
            }
        }
        while (k.size() > 1 && k.back() == 0)
            k.pop_back();
        number.clear();
        for (int i = k.size() - 1; i >= 0; i--)
        {
            number.push_back(k[i] + '0');
        }
        if (number != "0")
        {
            isNegative = resultNegative;
        }
        else
        {
            isNegative = false;
        }
        return *this;
    }

    // Division assignment operator (x /= y)
    BigInt &operator/=(const BigInt &other)
    { // --marwan--
        if (other.number == "0")
            throw runtime_error("Division by zero is undefined");
        if (number == "0")
            return *this;

        bool resultNegative = (isNegative != other.isNegative);

        string a = number;
        string b = other.number;

        BigInt dividend(a);
        dividend.isNegative = false;
        BigInt divisor(b);
        divisor.isNegative = false;

        if (dividend.compareMagnitude(divisor) < 0)
        {
            number = "0";
            isNegative = false;
            return *this;
        }
        else if (dividend.compareMagnitude(divisor) == 0)
        {
            number = "1";
            isNegative = resultNegative;
            return *this;
        }
        string result = "";
        BigInt current("0");
        // long division
        for (int i = 0; i < a.length(); i++)
        {
            current.number += a[i];

            while (current.number.size() > 1 && current.number[0] == '0')
            {
                current.number.erase(current.number.begin());
            }
            int count = 0;
            while (current.compareMagnitude(divisor) >= 0)
            {
                current -= divisor;
                count++;
            }

            result += to_string(count);
        }
        while (result.size() > 1 && result[0] == '0')
        {
            result.erase(result.begin());
        }
        number = result;
        if (number != "0")
        {
            isNegative = resultNegative;
        }
        else
        {
            isNegative = false;
        }
        return *this;
    }

    // Modulus assignment operator (x %= y)
    BigInt &operator%=(const BigInt &other)
    { // --marwan--
        if (other.number == "0")
            throw runtime_error("Modulo by zero is undefined");
        if (number == "0")
            return *this;
        // modulo formula is a%b=a-(a/b*b)
        bool originalSign = isNegative;
        BigInt a(*this);
        BigInt b(other);
        *this -= (a / b) * b;
        if (number != "0")
        {
            isNegative = originalSign;
        }
        else
        {
            isNegative = false;
        }
        return *this;
    }

    // Pre-increment operator (++x)
    BigInt &operator++()
    { // --salma--
        // TODO: Implement this operator
        *this += BigInt(1);
        return *this;
    }

    // Post-increment operator (x++)
    BigInt operator++(int)
    { // --salma--
        BigInt temp(*this);
        // TODO: Implement this operator
        *this += BigInt(1);
        return temp;
    }

    // Pre-decrement operator (--x)
    BigInt &operator--()
    { // --salma--
        // TODO: Implement this operator
        *this -= BigInt(1);
        return *this;
    }

    // Post-decrement operator (x--)
    BigInt operator--(int)
    { // --salma--
        BigInt temp(*this);
        // TODO: Implement this operator
        *this -= BigInt(1);
        return temp;
    }

    // Convert BigInt to string representation
    string toString() const
    { // --omar--
        if (isNegative)
        {
            return "-" + number;
        }
        else
        {
            return number;
        }
    }

    // Output stream operator (for printing)
    friend ostream &operator<<(ostream &os, const BigInt &num)
    { // --george--
        if (num.isNegative)
        {
            os << "-" + num.number;
        }
        else
        {
            os << num.number;
        }
        return os;
    }

    // Input stream operator (for reading from input)
    friend istream &operator>>(istream &is, BigInt &num)
    { // --george--
        // TODO: Implement this operator
        return is;
    }

    // Friend declarations for comparison operators
    friend bool operator==(const BigInt &lhs, const BigInt &rhs);
    friend bool operator<(const BigInt &lhs, const BigInt &rhs);
    friend BigInt operator+(BigInt lhs, const BigInt &rhs);
    friend BigInt operator-(BigInt lhs, const BigInt &rhs);
    friend BigInt operator*(BigInt lhs, const BigInt &rhs);
    friend BigInt operator/(BigInt lhs, const BigInt &rhs);
    friend BigInt operator%(BigInt lhs, const BigInt &rhs);
};

// Binary addition operator (x + y)
BigInt operator+(BigInt lhs, const BigInt &rhs)
{ // --salma--
    BigInt result;
    if (lhs.isNegative == rhs.isNegative)
    {
        result.number = lhs.add(lhs.number, rhs.number);
        result.isNegative = lhs.isNegative;
    }
    else
    {

        if (lhs.compareMagnitude(rhs) >= 0)
        {
            result.number = lhs.subtract(lhs.number, rhs.number);
            result.isNegative = lhs.isNegative;
        }
        else
        {
            result.number = lhs.subtract(rhs.number, lhs.number);
            result.isNegative = rhs.isNegative;
        }
    }
    result.removeLeadingZeros();
    if (result.number == "0")
        result.isNegative = false;
    return result;
}

// Binary subtraction operator (x - y)
BigInt operator-(BigInt lhs, const BigInt &rhs)
{ // --salma--
    BigInt result = rhs;
    result.isNegative = !rhs.isNegative;
    return lhs + result;
}

// Binary multiplication operator (x * y)
BigInt operator*(BigInt lhs, const BigInt &rhs)
{ // --marwan--
    BigInt result = lhs;
    result *= rhs;
    return result;
}

// Binary division operator (x / y)
BigInt operator/(BigInt lhs, const BigInt &rhs)
{ // --marwan--
    BigInt result = lhs;
    result /= rhs;
    return result;
}

// Binary modulus operator (x % y)
BigInt operator%(BigInt lhs, const BigInt &rhs)
{ // --marwan--
    BigInt result = lhs;
    result %= rhs;
    return result;
}

// Equality comparison operator (x == y)
bool operator==(const BigInt &lhs, const BigInt &rhs)
{ // --habiba--
    return (lhs.isNegative == rhs.isNegative && lhs.number == rhs.number);
}
// Inequality comparison operator (x != y)
bool operator!=(const BigInt &lhs, const BigInt &rhs)
{ // --habiba--
    return !(lhs == rhs);
}
// Less-than comparison operator (x < y)
bool operator<(const BigInt &lhs, const BigInt &rhs)
{ // --habiba--
    if (lhs.isNegative != rhs.isNegative)
        return lhs.isNegative;
    if (!lhs.isNegative)
    {
        if (lhs.number.size() != rhs.number.size())
            return lhs.number.size() < rhs.number.size();
        return lhs.number < rhs.number;
    }
    else
    {
        if (lhs.number.size() != rhs.number.size())
            return lhs.number.size() > rhs.number.size();
        return lhs.number > rhs.number;
    }
}
// Less-than-or-equal comparison operator (x <= y)
bool operator<=(const BigInt &lhs, const BigInt &rhs)
{ // --habiba--
    return (lhs < rhs || lhs == rhs);
}
// Greater-than comparison operator (x > y)
bool operator>(const BigInt &lhs, const BigInt &rhs)
{ // --habiba--
    return !(lhs <= rhs);
}
// Greater-than-or-equal comparison operator (x >= y)
bool operator>=(const BigInt &lhs, const BigInt &rhs)
{ // --habiba--
    return !(lhs < rhs);
}
int main()
{
    cout << "=== BigInt Class Test Program ===" << endl
         << endl;
    cout << "NOTE: All functions are currently empty." << endl;
    cout << "Your task is to implement ALL the functions above." << endl;
    cout << "The tests below will work once you implement them correctly." << endl
         << endl;

    // Test 1: Constructors and basic output
    cout << "1. Constructors and output:" << endl;
    BigInt a(12345);                          // Should create BigInt from integer
    BigInt b("-000000067890");                       // Should create BigInt from string
    BigInt c("0");                            // Should handle zero correctly
    BigInt d = a;                             // Should use copy constructor
    cout << "a (from int): " << a << endl;    // Should print "12345"
    cout << "b (from string): " << b << endl; // Should print "-67890"
    cout << "c (zero): " << c << endl;        // Should print "0"
    cout << "d (copy of a): " << d << endl
         << endl; // Should print "12345"


    // Test 2: Arithmetic operations
    cout << "2. Arithmetic operations:" << endl;
    cout << "a + b = " << a + b << endl;          // Should calculate 12345 + (-67890)
    cout << "a - b = " << a - b << endl;          // Should calculate 12345 - (-67890)
    cout << "a * b = " << a * b << endl; // Should calculate 12345 * (-67890)
    cout << "b / a = " << b / a << endl; // Should calculate (-67890) / 12345
    cout << "a % 100 = " << a % BigInt(100) << endl
         << endl; // Should calculate 12345 % 100

         

    // Test 3: Relational operators
    cout << "3. Relational operators:" << endl;
    cout << "a == d: " << (a == d) << endl;       // Should be true (12345 == 12345)
    cout << "a != b: " << (a != b) << endl;       // Should be true (12345 != -67890)
    cout << "a < b: " << (a < b) << endl;         // Should be false (12345 < -67890)
    cout << "a > b: " << (a > b) << endl;         // Should be true (12345 > -67890)
    cout << "c == 0: " << (c == BigInt(0)) << endl << endl; // Should be true (0 == 0)

    // Test 4: Unary operators and increments
    cout << "4. Unary operators and increments:" << endl;
   // cout << "-a: " << -a << endl;                 // Should print "-12345"
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
    

    return 0;
}
