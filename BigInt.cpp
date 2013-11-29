#include"BigInt.h"
#include<vector>
#include<string.h>

BigInt BigInt::ZERO = BigInt(0);
BigInt BigInt::ONE  = BigInt(1);
BigInt BigInt::TEN  = BigInt(10);

BigInt::BigInt(){
    vec.clear();
    sign_ = true;
}

BigInt::BigInt(int i_val){
    vec.clear();
    if (i_val >= 0)
        sign_ = true;
    else{
        sign_ = false;
        i_val = -i_val;
    }
    if (i_val == 0){
        vec.push_back(0);
    }
    while (i_val > 0){
        vec.push_back(i_val % 10);
        i_val /= 10;
    }
}

BigInt::BigInt(const char* i_val){
    vec.clear();
    sign_ = true;
    int tmp = 0;
    if (i_val[0] == '-'){
        sign_ = false;
        tmp = 1;
    }
    int len = strlen(i_val);
    //std::cout << len << std::endl;
    for (int i = len - 1; i > 0 + tmp; --i){
        vec.push_back(i_val[i] - '0');
    }
    vec.push_back(i_val[0 + tmp] - '0');
}

BigInt::BigInt(const std::string& i_val){
    vec.clear();
    sign_ = true;
    int tmp = 0;
    if (i_val[0] == '-'){
        sign_ = false;
        tmp = 1;
    }
    for (std::string::size_type i = i_val.size() - 1; i > 0 + tmp; --i){
        vec.push_back(i_val[i] - '0');
    }
    vec.push_back(i_val[0 + tmp] - '0');
}

BigInt BigInt::operator=(const BigInt& i_val) {
    vec.clear();
    sign_ = i_val.sign_;
    for (std::vector<int>::size_type i = 0; i < i_val.vec.size(); ++i) {
        vec.push_back(i_val.vec[i]);
    }
    return *this;
}

BigInt BigInt::operator=(const std::string& i_val){
    vec.clear();
    sign_ = true;
    int tmp = 0;
    if (i_val[0] == '-'){
        sign_ = false;
        tmp = 1;
    }
    for (std::string::size_type i = i_val.size() - 1; i > 0 + tmp; --i) {
        vec.push_back(i_val[i] - '0');
    }
    vec.push_back(i_val[0 + tmp] - '0');
    return *this;
}

inline BigInt operator+(const BigInt& lhs, const BigInt& rhs){
    BigInt ret(lhs);
    ret += rhs;
    return ret;
}

inline BigInt operator-(const BigInt& lhs, const BigInt& rhs){
    BigInt ret(lhs);
    ret -= rhs;
    return ret;
}

inline BigInt operator*(const BigInt& lhs, const BigInt& rhs){
    BigInt ret(lhs);
    ret *= rhs;
    return ret;
}

inline BigInt operator/(const BigInt& lhs, const BigInt& rhs){
    BigInt ret(lhs);
    ret /= rhs;
    return ret;
}

//TODO
BigInt& BigInt::operator+=(const BigInt& i_val){
    if (sign_ == i_val.sign_) {
        std::vector<int>::size_type lena = vec.size(), lenb = i_val.vec.size(), i;
        while (lena <= lenb){
            vec.push_back(0);
            ++lena;
        }
        int carry = 0;
        for (i = 0; i < i_val.vec.size(); ++i){
            vec.at(i) += carry + i_val.vec.at(i);
            carry = vec.at(i) % 10;
            vec.at(i) /= 10;
        }
        for ( ; i < vec.size(); ++i){
            vec.at(i) += carry + 0;
            carry = vec.at(i) % 10;
            vec.at(i) /= 10;
        }
    }else{

    }
    trim();
    return *this;
}

//TODO
BigInt& BigInt::operator-=(const BigInt& i_val){

}

//TODO
BigInt& BigInt::operator*=(const BigInt& i_val){

}

//TODO
BigInt& BigInt::operator/=(const BigInt& i_val){

}

BigInt& BigInt::operator++() {
    *this += BigInt::ONE;
    return *this;
}//前置++

BigInt& BigInt::operator--() {
    *this -= BigInt::ONE;
    return *this;
}

const BigInt BigInt::operator++(int) {
    BigInt temp = *this;
    ++(*this);
    return BigInt(temp);
}

const BigInt BigInt::operator--(int) {
    BigInt temp = *this;
    --(*this);
    return BigInt(temp);
}

BigInt& BigInt::operator+() {
    return *this;
}

BigInt& BigInt::operator-() {
    this->sign_ = !(this->sign_);
    return *this;
}

bool operator>(const BigInt& lhs, const BigInt& rhs) {
    return (lhs != rhs) && (rhs < lhs);
}

bool operator>=(const BigInt& lhs, const BigInt& rhs) {
    return !(lhs < rhs);
}

bool operator<(const BigInt& lhs, const BigInt& rhs) {
    if (lhs.sign_ == false && rhs.sign_ == true)
        return true;
    if (lhs.sign_ == true && rhs.sign_ == false)
        return false;
    if (lhs.sign_){
        if (lhs.vec.size() < rhs.vec.size())
            return true;
        else if (lhs.vec.size() > rhs.vec.size())
            return false;
    }else{
        if (lhs.vec.size() < rhs.vec.size())
            return false;
        else if (lhs.vec.size() > rhs.vec.size())
            return true;
    }
    for (std::vector<int>::size_type i = lhs.vec.size() - 1; i > 0; --i) {
        if (lhs.vec.at(i) < rhs.vec.at(i)){
            if (lhs.sign_)
                return true;
            else
                return false;
        }
    }
    if (lhs.vec.at(0) < rhs.vec.at(0)){
        if (lhs.sign_)
            return true;
        else
            return false;
    }
    return false;
}

bool operator<=(const BigInt& lhs, const BigInt& rhs) {
    return !(lhs > rhs);
}

bool operator==(const BigInt& lhs, const BigInt& rhs) {
    if (lhs.sign_ != rhs.sign_
        || lhs.vec.size() != rhs.vec.size())
        return false;
    for (std::vector<int>::size_type i = 0; i < lhs.vec.size(); i++){
        if (lhs.vec.at(i) != rhs.vec.at(i))
            return false;
    }
    return true;
}

bool operator!=(const BigInt& lhs, const BigInt& rhs) {
    return !(lhs == rhs);
}


std::istream& operator>>(std::istream& in, BigInt& o_val) {
    std::string tmp;
    in >> tmp;
    o_val = tmp;
    return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& i_val) {
    if (i_val.vec.size() == 0){
        out << "0";
    }else{
        for (std::vector<int>::size_type i = i_val.vec.size() - 1; i > 0; --i) {
            out << i_val.vec[i];
        }
        out << i_val.vec[0];
    }
    return out;
}

void BigInt::trim() {
    while (vec.size() > 1 && vec[vec.size() - 1] == 0)
        vec.pop_back();
}

